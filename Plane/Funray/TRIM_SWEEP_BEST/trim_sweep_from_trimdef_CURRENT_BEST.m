% ============================================================
% trim_sweep_from_trimdef.m
%
% Purpose:
%   Automate TrimMod runs using saved trim definition files.
%
% Important:
%   The trim formulation is NOT changed in this script.
%   Active trim variables and trim requirements come directly
%   from the selected TrimDef file.
%
% Modes:
%   trimMode = 'nominal'
%       Uses nominal trim definition file.
%       Sweeps speed only.
%
%   trimMode = 'jammed'
%       Uses jammed-elevator trim definition file.
%       Sweeps speed and prescribed elevator jam angle.
% ============================================================

addPathFunray();
clc_clear;

%% Model and trim file settings

modelName = 'AirplaneSimModel_Trim';

trimMode = 'nominal';   % 'nominal' or 'jammed'

switch trimMode

    case 'nominal'
        trimDefFile = 'AirplaneSimModel_Trim_NOMINAL_BEST_start.mat';

        V_list = 12:-0.5:5; %5:0.5:40;

        % No elevator jam sweep in nominal mode
        el_jam_list_deg = NaN;
        el_jam_list     = NaN;

    case 'jammed'
        trimDefFile = 'AirplaneSimModel_Trim_JAM_BEST_start.mat';

        V_list = 6:0.5:40;

        % Elevator jam sweep in degrees.
        % Range can be adjusted depending on the investigated region.
        el_jam_list_deg = -21:1:21;
        el_jam_list     = deg2rad(el_jam_list_deg);

    otherwise
        error('Unknown trimMode: %s', trimMode);

end

%% Load aircraft and environment parameters

airplane = conventionalAirplaneLoadParams('airplane_params_Funray');
envir    = envirLoadParams('envir_params_default', 'envir', 0);

airplane.posRef.alt = airplane.posRef.alt + 30;

airplane.ic.q_bg     = euler2Quat([0; 0; -1.4]);
airplane.ic.V_Kb     = [15; 0; 0];
airplane.ic.s_Kg     = [10; 0; 0];
airplane.ic.omega_Kb = [0; 0; 0];

%% Acceptance settings

costTol = 1e-6;

thMin = 0;
thMax = 1;

surfaceCommandLimit = 1;   % normalized aileron surface command limit

%% Stall angles from main wing polar

alphaPolar_rad = airplane.aero.wingMain.polar.alpha;
CLPolar        = airplane.aero.wingMain.polar.C_L;

% NOTE:
% The original approach used global min/max of the nonlinear wing polar,
% which produced a nonphysical negative stall angle near -40 deg due to
% secondary post-stall extrema. For trim feasibility analysis, the stall
% boundary is instead defined symmetrically using +/- alpha_max.
alphaStallPositive_deg = airplane.aero.wingMain.polar.params.alpha_max;
alphaStallNegative_deg = -alphaStallPositive_deg;

% Stall rejection margin.
% A point is rejected if it is within 0.5 deg of the stall boundary.
% This avoids accepting trim points too close to the nonlinear stall region.
stallMargin_deg = 0.5;

fprintf('Positive stall angle from polar: %.3f deg\n', alphaStallPositive_deg);
fprintf('Negative stall angle from polar: %.3f deg\n', alphaStallNegative_deg);

wingIncidence_deg = rad2deg(airplane.aero.config.wingMainIncidence);

%% Actuator limits

elMin_rad = airplane.act.elevator.deflectionMin;
elMax_rad = airplane.act.elevator.deflectionMax;

elMin_deg = rad2deg(elMin_rad);
elMax_deg = rad2deg(elMax_rad);

% Elevator command is dimensionless:
% physical elevator angle = command * elevator maximum deflection
elCmdMin = elMin_rad / elMax_rad;
elCmdMax = elMax_rad / elMax_rad;

aiMin_rad = airplane.act.ailerons.deflectionMin;
aiMax_rad = airplane.act.ailerons.deflectionMax;

aiMin_deg = rad2deg(aiMin_rad);
aiMax_deg = rad2deg(aiMax_rad);

aiDeflectionMax_rad = airplane.act.ailerons.deflectionMax;
aiDeflectionMax_deg = rad2deg(aiDeflectionMax_rad);

%% Trimming simplification

airplane.act.ailerons.delay = 0;
airplane.act.elevator.delay = 0;
airplane.act.rudder.delay   = 0;

%% Open and prepare model

open_model(modelName);

set_param(modelName, ...
    'LoadExternalInput', 'off', ...
    'LoadInitialState',  'off');

%% Load saved trim definition

S = load(trimDefFile);
save_struct = S.save_struct;

sys = save_struct.model_name;

if ~strcmp(sys, modelName)
    error('Trim file model "%s" does not match opened model "%s".', sys, modelName);
end

[u_nam, u0, i_u, del_u_max, del_u_lin, u_min, u_max] = extractTrimData(save_struct.input_data);
[x_nam, x0, i_x, del_x_max, del_x_lin, x_min, x_max] = extractTrimData(save_struct.state_data);
[d_nam, d0, i_d] = extractRequirementData(save_struct.derivative_data);
[y_nam, y0, i_y] = extractRequirementData(save_struct.output_data);

options = save_struct.parameters;

options.n_iter_max = 42;
options.cost_tbg = costTol;
options.EnableMessages = 0;
options.CompileFlag = 0;   % do NOT compile/term inside jj_trim

%% Match TrimMod default handling

del_x_max(del_x_max == 0) = 1e42;
del_u_max(del_u_max == 0) = 1e42;

idxZeroXLin = (del_x_lin == 0);
idxZeroULin = (del_u_lin == 0);

del_x_lin(idxZeroXLin) = 1e-6 * (1 + abs(x0(idxZeroXLin)));
del_u_lin(idxZeroULin) = 1e-6 * (1 + abs(u0(idxZeroULin)));

x_min(x_min == 0) = -inf;
u_min(u_min == 0) = -inf;
x_max(x_max == 0) = inf;
u_max(u_max == 0) = inf;

%% Print active trim definition

fprintf('\n========================================\n');
fprintf('Loaded trim definition file:\n%s\n', trimDefFile);
fprintf('Trim mode: %s\n', trimMode);
fprintf('========================================\n');

fprintf('\nActive input trim variables:\n');
disp(u_nam(i_u))

fprintf('\nActive state trim variables:\n');
disp(x_nam(i_x))

fprintf('\nActive derivative trim requirements:\n');
disp(d_nam(i_d))

fprintf('\nActive output trim requirements:\n');
disp(y_nam(i_y))

%% Find useful indices

idx_el = findSingleIndex(u_nam, 'el', 'input');

idx_ai = findSingleIndex(u_nam, 'ai', 'input');

idx_ai_coll = findSingleIndex(u_nam, 'ai_coll', 'input');

idx_th = findSingleIndex(u_nam, 'th', 'input');

idx_ru = findSingleIndex(u_nam, 'ru', 'input');

idxAilState1 = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/Actuators/Nonlinear Second-Order Actuator (ailerons)/A___1', ...
    'state');

idxAilState2 = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/Actuators/Nonlinear Second-Order Actuator (ailerons)/A___2', ...
    'state');

idxAilState3 = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/Actuators/Nonlinear Second-Order Actuator (ailerons)/A___3', ...
    'state');

idxAilState4 = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/Actuators/Nonlinear Second-Order Actuator (ailerons)/A___4', ...
    'state');

% Horizontal no-wind flight assumption:
% V_Kg_1 is used as the trim speed requirement.
idx_speed_output = findSingleIndex(y_nam, 'V_Kg___1', 'output');

idx_VKb1 = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/State equations (Quaternions)/V__Kb___1', ...
    'state');

idx_VKb3 = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/State equations (Quaternions)/V__Kb___3', ...
    'state');

idxElevatorState = findSingleIndex(x_nam, ...
    'Conventional Airplane, single engine/Actuators/Nonlinear Second-Order Actuator (elevons)/A', ...
    'state');

%% Reference elevator

el_reference_rad = x0(idxElevatorState);
el_reference_deg = rad2deg(el_reference_rad);

fprintf('\nReference elevator from trim definition:\n');
fprintf('el_reference = %.6f rad = %.3f deg\n', ...
    el_reference_rad, el_reference_deg);

fprintf('elevator limits = [%.3f, %.3f] deg\n', elMin_deg, elMax_deg);
fprintf('aileron limits  = [%.3f, %.3f] deg\n', aiMin_deg, aiMax_deg);

%% Check trim problem size

nTrimVariables    = numel(i_x) + numel(i_u);
nTrimRequirements = numel(i_d) + numel(i_y);

fprintf('\nNumber of trim variables    = %d\n', nTrimVariables);
fprintf('Number of trim requirements = %d\n', nTrimRequirements);

if nTrimVariables ~= nTrimRequirements
    error('Unbalanced trim problem: variables (%d) ~= requirements (%d). Check TrimDef file.', ...
        nTrimVariables, nTrimRequirements);
end

%% Preallocate results

nV   = numel(V_list);
nJam = numel(el_jam_list);
nCases = nV * nJam;

trim_results = repmat(makeEmptyResult(), nCases, 1);

%% Run sweep

feval(modelName, [], [], [], 'compile');
caseCounter = 0;

for iJam = 1:nJam

    if strcmp(trimMode, 'jammed')
        el_case_rad = el_jam_list(iJam);          % physical jam angle [rad]
        el_case_deg = el_jam_list_deg(iJam);      % physical jam angle [deg]
        el_case_cmd = el_case_rad / elMax_rad;    % dimensionless command
    else
        el_case_rad = el_reference_rad;
        el_case_deg = el_reference_deg;
        el_case_cmd = u0(idx_el);
    end

    fprintf('\n########################################\n');

    if strcmp(trimMode, 'jammed')
        fprintf('Elevator jam case %d / %d\n', iJam, nJam);
        fprintf('el_jam = %.6f rad = %.3f deg\n', el_case_rad, el_case_deg);
    else
        fprintf('Nominal trim sweep\n');
    end

    fprintf('########################################\n');

    for iV = 1:nV

        caseCounter = caseCounter + 1;

        V_target = V_list(iV);

        fprintf('\nTrim case %d / %d\n', caseCounter, nCases);
        fprintf('V target = %.3f m/s | el = %.3f deg\n', V_target, el_case_deg);

        % Initial guess for this trim point.
        %
        % Jammed case:
        %   Use a fresh start from the saved TrimDef for every point.
        %
        % Nominal case:
        %   Use continuation from the previous successful trim point.
        %   This improves convergence along the smooth nominal trim curve.
        if strcmp(trimMode, 'nominal') && iV > 1 && trim_results(caseCounter-1).isTrimmodConverged
        
            x_guess = trim_results(caseCounter-1).x_tr;
            u_guess = trim_results(caseCounter-1).u_tr;
        
        else
        
            x_guess = x0;
            u_guess = u0;
        
        end
        
        d_target = d0;
        y_target = y0;
                
        % Change only the numerical values for this case.
        % The TrimDef file decides what is active/free/constrained.
        
        % Improved initial guess for body-axis forward velocity.
        % This does NOT constrain V_Kb_1; it only helps TrimMod start closer
        % to the expected trimmed speed. V_Kb_3 is left at the TrimDef value,
        % because forcing it to zero reduced convergence robustness in tests.
        
        % Speed target requirement
        y_target(idx_speed_output) = V_target;
        
        %% Initial guess fallback loop for V_Kb_1
        
        % Candidate initial guesses for body-axis forward velocity.
        % The loop stops as soon as TrimMod converges successfully.
        
        VKb1_guess_list = [V_target, V_target - 1, V_target + 1];
        
        trimSucceeded = false;
        
        for iGuess = 1:numel(VKb1_guess_list)
        
            x_guess_try = x_guess;
            u_guess_try = u_guess;
        
            x_guess_try(idx_VKb1) = VKb1_guess_list(iGuess);
        
            % Elevator jam value, only in jammed case.
            % In the jammed TrimDef file, el should already be inactive.
            if strcmp(trimMode, 'jammed')
                u_guess_try(idx_el) = el_case_cmd;
            end
        
            x_min_try = x_min;
            x_max_try = x_max;
            
            VKb3_min = ...
                sind(alphaStallNegative_deg - wingIncidence_deg) ...
                * V_target * 0.95;
            
            x_min_try(idx_VKb3) = VKb3_min;
            
            [x_tr, u_tr, d_tr, y_tr, errflg, infostruct] = jj_trim( ...
                sys, ...
                x_guess_try, u_guess_try, d_target, y_target, ...
                i_x, i_u, i_d, i_y, ...
                x_nam, u_nam, d_nam, y_nam, ...
                del_x_max, del_u_max, del_x_lin, del_u_lin, ...
                options, ...
                x_min_try, x_max_try, u_min, u_max);
        
            finalCost = getFinalCost(infostruct);
            exitCode  = getExitCode(infostruct);
        
            trimSucceeded = ...
                (errflg == 0) && ...
                (exitCode == 0) && ...
                (finalCost < costTol);
        
            if trimSucceeded
                fprintf('Trim converged using V_Kb_1 initial guess = %.3f m/s\n', ...
                    VKb1_guess_list(iGuess));
                break
            else
                fprintf('Trim failed using V_Kb_1 initial guess = %.3f m/s\n', ...
                    VKb1_guess_list(iGuess));
            end
        
        end

        el_cmd = u_tr(idx_el);                 % dimensionless elevator command
        el_state_rad = x_tr(idxElevatorState); % actual elevator deflection [rad]
        el_state_deg = rad2deg(el_state_rad);  % actual elevator deflection [deg]
        
        % Actual aileron actuator states
        aileronStates_rad = x_tr([ ...
            idxAilState1 ...
            idxAilState2 ...
            idxAilState3 ...
            idxAilState4]);
        aileronStates_deg = rad2deg(aileronStates_rad);
        
        AileronCollectiveState_deg = mean(aileronStates_deg);

        AileronState1_deg = aileronStates_deg(1);
        AileronState2_deg = aileronStates_deg(2);
        AileronState3_deg = aileronStates_deg(3);
        AileronState4_deg = aileronStates_deg(4);

        ai      = u_tr(idx_ai);
        ai_coll = u_tr(idx_ai_coll);
        th      = u_tr(idx_th);
        ru      = u_tr(idx_ru);

        leftAiSurface  = ai + ai_coll;
        rightAiSurface = -ai + ai_coll;
        maxSurface     = max(abs([leftAiSurface, rightAiSurface]));
        maxSurfacePercent = 100 * maxSurface / surfaceCommandLimit;

        leftAiSurface_deg  = leftAiSurface  * aiDeflectionMax_deg;
        rightAiSurface_deg = rightAiSurface * aiDeflectionMax_deg;
        ai_coll_deg        = ai_coll        * aiDeflectionMax_deg;

        V_Kb_1 = x_tr(idx_VKb1);
        V_Kb_3 = x_tr(idx_VKb3);

        speedBodyApprox = sqrt(V_Kb_1^2 + V_Kb_3^2);

        alphaBody_rad = atan2(V_Kb_3, V_Kb_1);
        alphaBody_deg = rad2deg(alphaBody_rad);
        alphaWing_deg = alphaBody_deg + wingIncidence_deg;

        isPositiveStall = alphaWing_deg >= alphaStallPositive_deg;
        isNegativeStall = alphaWing_deg <= alphaStallNegative_deg;

        isNearPositiveStall = alphaWing_deg >= (alphaStallPositive_deg - stallMargin_deg);
        isNearNegativeStall = alphaWing_deg <= (alphaStallNegative_deg + stallMargin_deg);
        isNearStall = isNearPositiveStall || isNearNegativeStall;

        isTrimmodConverged = ...
            (errflg == 0) && ...
            (exitCode == 0) && ...
            (finalCost < costTol);

        isThrottleValid = ...
            (th >= thMin) && ...
            (th <= thMax);

        isSurfaceValid = ...
            (abs(leftAiSurface) <= surfaceCommandLimit) && ...
            (abs(rightAiSurface) <= surfaceCommandLimit);

        isElevatorValid = ...
            (el_state_rad >= elMin_rad) && ...
            (el_state_rad <= elMax_rad);

        % A trim point is considered usable only if:
        % - TrimMod converged,
        % - throttle limits are satisfied,
        % - aileron surface limits are satisfied,
        % - elevator limits are satisfied,
        % - and the point is outside the stall rejection margin.
        isUsableTrim = ...
            isTrimmodConverged && ...
            isThrottleValid && ...
            isSurfaceValid && ...
            isElevatorValid && ...
            ~isNearStall;

        invalidReason = getInvalidReason( ...
            isTrimmodConverged, isThrottleValid, isSurfaceValid, isElevatorValid, isNearStall);

        trim_results(caseCounter).V_target = V_target;
        trim_results(caseCounter).V_trim = V_target;
        trim_results(caseCounter).V_Kb_1 = V_Kb_1;
        trim_results(caseCounter).V_Kb_3 = V_Kb_3;
        trim_results(caseCounter).SpeedBodyApprox = speedBodyApprox;

        trim_results(caseCounter).ElevatorCommand = el_cmd;
        trim_results(caseCounter).ElevatorCommand_degEquivalent = el_cmd * elMax_deg;
        
        trim_results(caseCounter).Elevator_rad = el_state_rad;
        trim_results(caseCounter).Elevator_deg = el_state_deg;
        trim_results(caseCounter).ElevatorOffsetFromReference_deg = el_state_deg - el_reference_deg;

        trim_results(caseCounter).x_tr = x_tr;
        trim_results(caseCounter).u_tr = u_tr;
        trim_results(caseCounter).d_tr = d_tr;
        trim_results(caseCounter).y_tr = y_tr;

        trim_results(caseCounter).errflg    = errflg;
        trim_results(caseCounter).ExitCode  = exitCode;
        trim_results(caseCounter).FinalCost = finalCost;

        trim_results(caseCounter).ai      = ai;
        trim_results(caseCounter).ai_coll = ai_coll;
        trim_results(caseCounter).th      = th;
        trim_results(caseCounter).ru      = ru;

        trim_results(caseCounter).LeftAiSurface      = leftAiSurface;
        trim_results(caseCounter).RightAiSurface     = rightAiSurface;
        trim_results(caseCounter).MaxSurface         = maxSurface;
        trim_results(caseCounter).MaxSurfacePercent  = maxSurfacePercent;

        trim_results(caseCounter).LeftAiSurface_deg  = leftAiSurface_deg;
        trim_results(caseCounter).RightAiSurface_deg = rightAiSurface_deg;
        trim_results(caseCounter).ai_coll_deg        = ai_coll_deg;

        trim_results(caseCounter).AileronCollectiveState_deg = AileronCollectiveState_deg;
        trim_results(caseCounter).AileronState1_deg = AileronState1_deg;
        trim_results(caseCounter).AileronState2_deg = AileronState2_deg;
        trim_results(caseCounter).AileronState3_deg = AileronState3_deg;
        trim_results(caseCounter).AileronState4_deg = AileronState4_deg;

        trim_results(caseCounter).AlphaBody_deg     = alphaBody_deg;
        trim_results(caseCounter).WingIncidence_deg = wingIncidence_deg;
        trim_results(caseCounter).AlphaWing_deg     = alphaWing_deg;

        trim_results(caseCounter).isPositiveStall = isPositiveStall;
        trim_results(caseCounter).isNegativeStall = isNegativeStall;

        trim_results(caseCounter).isTrimmodConverged = isTrimmodConverged;
        trim_results(caseCounter).isThrottleValid    = isThrottleValid;
        trim_results(caseCounter).isSurfaceValid     = isSurfaceValid;
        trim_results(caseCounter).isElevatorValid    = isElevatorValid;
        trim_results(caseCounter).isNearStall        = isNearStall;
        trim_results(caseCounter).isUsableTrim       = isUsableTrim;
        trim_results(caseCounter).InvalidReason      = invalidReason;

        fprintf('errflg = %d | ExitCode = %g | FinalCost = %.3e | usable = %d | reason = %s\n', ...
            errflg, exitCode, finalCost, isUsableTrim, invalidReason);

        fprintf('el = %.3f deg | ai = %.6f | ai_coll = %.6f = %.3f deg | th = %.6f\n', ...
            el_state_deg, ai, ai_coll, ai_coll_deg, th);

        fprintf('Left surf = %.3f deg | Right surf = %.3f deg | MaxSurf = %.1f %%\n', ...
            leftAiSurface_deg, rightAiSurface_deg, maxSurfacePercent);

        fprintf('V_Kb_1 = %.3f | V_Kb_3 = %.3f | |V_Kb| approx = %.3f\n', ...
            V_Kb_1, V_Kb_3, speedBodyApprox);

        fprintf('alpha_body = %.3f deg | alpha_wing = %.3f deg | near stall = %d\n', ...
            alphaBody_deg, alphaWing_deg, isNearStall);

        if ~isUsableTrim
            warning('Trim not usable for V = %.3f m/s, el = %.3f deg. Reason: %s', ...
                V_target, el_case_deg, invalidReason);
        end
    end
end

feval(modelName, [], [], [], 'term');

%% Build summary table

results_table = buildResultsTable(trim_results);

disp(' ');
disp('===== Trim sweep summary =====');
disp(results_table);

%% Save results

V_tag   = makeTag('V', min(V_list), max(V_list));
run_tag = datestr(now, 'yyyymmdd_HHMMSS');

if strcmp(trimMode, 'jammed')
    el_tag = makeTag('elDeg', min(el_jam_list_deg), max(el_jam_list_deg));
else
    el_tag = makeTag('elDeg', el_reference_deg, el_reference_deg);
end

case_tag = [trimMode '_' el_tag '_' V_tag '_' run_tag];

output_folder = fullfile('TrimResults', case_tag);

if ~exist(output_folder, 'dir')
    mkdir(output_folder);
end

results_filename = fullfile(output_folder, ...
    [trimMode '_trim_results_' case_tag '.mat']);

save(results_filename, ...
    'trim_results', ...
    'results_table', ...
    'x_nam', 'u_nam', 'd_nam', 'y_nam', ...
    'i_x', 'i_u', 'i_d', 'i_y', ...
    'V_list', ...
    'el_jam_list', 'el_jam_list_deg', ...
    'el_reference_rad', 'el_reference_deg', ...
    'elMin_rad', 'elMax_rad', 'elMin_deg', 'elMax_deg', ...
    'aiMin_rad', 'aiMax_rad', 'aiMin_deg', 'aiMax_deg', ...
    'aiDeflectionMax_rad', 'aiDeflectionMax_deg', ...
    'trimMode', ...
    'trimDefFile', ...
    'costTol', ...
    'surfaceCommandLimit', ...
    'thMin', 'thMax', ...
    'alphaPolar_rad', ...
    'CLPolar', ...
    'alphaStallPositive_deg', ...
    'alphaStallNegative_deg', ...
    'stallMargin_deg', ...
    'wingIncidence_deg');

fprintf('\nSaved trim results to:\n%s\n', results_filename);

%% Local helper functions

function [names, values, activeIdx, maxStep, linStep, minVal, maxVal] = extractTrimData(data)
    names     = cellstr(data(:,1));
    values    = cell2mat(data(:,2));
    activeIdx = find(cell2mat(data(:,3)) ~= 0);

    maxStep = cell2mat(data(:,4));
    linStep = cell2mat(data(:,5));
    minVal  = cell2mat(data(:,6));
    maxVal  = cell2mat(data(:,7));
end

function [names, values, activeIdx] = extractRequirementData(data)
    names     = cellstr(data(:,1));
    values    = cell2mat(data(:,2));
    activeIdx = find(cell2mat(data(:,3)) ~= 0);
end

function idx = findSingleIndex(names, targetName, signalType)
    idx = find(strcmp(names, targetName));

    if isempty(idx)
        error('Required %s "%s" not found.', signalType, targetName);
    end

    if numel(idx) > 1
        error('Required %s "%s" found more than once.', signalType, targetName);
    end
end

function finalCost = getFinalCost(infostruct)
    if isfield(infostruct, 'cost') && ~isempty(infostruct.cost)
        finalCost = infostruct.cost(end);
    else
        finalCost = NaN;
    end
end

function exitCode = getExitCode(infostruct)
    if isfield(infostruct, 'ExitCode')
        exitCode = infostruct.ExitCode;
    else
        exitCode = NaN;
    end
end

function invalidReason = getInvalidReason( ...
    isTrimmodConverged, isThrottleValid, isSurfaceValid, isElevatorValid, isNearStall)

    if ~isTrimmodConverged
        invalidReason = "TrimMod failed";
    elseif ~isThrottleValid
        invalidReason = "Throttle limit";
    elseif ~isSurfaceValid
        invalidReason = "Aileron surface limit";
    elseif ~isElevatorValid
        invalidReason = "Elevator limit";
    elseif isNearStall
        invalidReason = "Stall";
    else
        invalidReason = "Usable";
    end
end

function result = makeEmptyResult()
    result = struct( ...
        'V_target', [], ...
        'V_trim', [], ...
        'V_Kb_1', [], ...
        'V_Kb_3', [], ...
        'SpeedBodyApprox', [], ...
        'Elevator_rad', [], ...
        'Elevator_deg', [], ...
        'ElevatorCommand', [], ...
        'ElevatorCommand_degEquivalent', [], ...
        'ElevatorOffsetFromReference_deg', [], ...
        'x_tr', [], ...
        'u_tr', [], ...
        'd_tr', [], ...
        'y_tr', [], ...
        'errflg', [], ...
        'ExitCode', [], ...
        'FinalCost', [], ...
        'ai', [], ...
        'ai_coll', [], ...
        'th', [], ...
        'ru', [], ...
        'LeftAiSurface', [], ...
        'RightAiSurface', [], ...
        'MaxSurface', [], ...
        'MaxSurfacePercent', [], ...
        'LeftAiSurface_deg', [], ...
        'RightAiSurface_deg', [], ...
        'ai_coll_deg', [], ...
        'AileronCollectiveState_deg', [], ...
        'AileronState1_deg', [], ...
        'AileronState2_deg', [], ...
        'AileronState3_deg', [], ...
        'AileronState4_deg', [], ...
        'AlphaBody_deg', [], ...
        'WingIncidence_deg', [], ...
        'AlphaWing_deg', [], ...
        'isPositiveStall', [], ...
        'isNegativeStall', [], ...
        'isTrimmodConverged', [], ...
        'isThrottleValid', [], ...
        'isSurfaceValid', [], ...
        'isElevatorValid', [], ...
        'isNearStall', [], ...
        'isUsableTrim', [], ...
        'InvalidReason', "");
end

function results_table = buildResultsTable(trim_results)

    results_table = table( ...
        [trim_results.V_target]', ...
        [trim_results.V_trim]', ...
        [trim_results.V_Kb_1]', ...
        [trim_results.V_Kb_3]', ...
        [trim_results.SpeedBodyApprox]', ...
        [trim_results.Elevator_rad]', ...
        [trim_results.ElevatorCommand]', ...
        [trim_results.ElevatorCommand_degEquivalent]', ...
        [trim_results.Elevator_deg]', ...
        [trim_results.ElevatorOffsetFromReference_deg]', ...
        [trim_results.errflg]', ...
        [trim_results.ExitCode]', ...
        [trim_results.FinalCost]', ...
        [trim_results.ai]', ...
        [trim_results.ai_coll]', ...
        [trim_results.th]', ...
        [trim_results.ru]', ...
        [trim_results.LeftAiSurface]', ...
        [trim_results.RightAiSurface]', ...
        [trim_results.MaxSurface]', ...
        [trim_results.MaxSurfacePercent]', ...
        [trim_results.LeftAiSurface_deg]', ...
        [trim_results.RightAiSurface_deg]', ...
        [trim_results.ai_coll_deg]', ...
        [trim_results.AileronCollectiveState_deg]', ...
        [trim_results.AileronState1_deg]', ...
        [trim_results.AileronState2_deg]', ...
        [trim_results.AileronState3_deg]', ...
        [trim_results.AileronState4_deg]', ...
        [trim_results.AlphaBody_deg]', ...
        [trim_results.WingIncidence_deg]', ...
        [trim_results.AlphaWing_deg]', ...
        [trim_results.isPositiveStall]', ...
        [trim_results.isNegativeStall]', ...
        [trim_results.isTrimmodConverged]', ...
        [trim_results.isThrottleValid]', ...
        [trim_results.isSurfaceValid]', ...
        [trim_results.isElevatorValid]', ...
        [trim_results.isNearStall]', ...
        [trim_results.isUsableTrim]', ...
        [trim_results.InvalidReason]', ...
        'VariableNames', { ...
        'V_target', ...
        'V_trim', ...
        'V_Kb_1', ...
        'V_Kb_3', ...
        'SpeedBodyApprox', ...
        'Elevator_rad', ...
        'ElevatorCommand', ...
        'ElevatorCommand_degEquivalent', ...
        'Elevator_deg', ...
        'ElevatorOffsetFromReference_deg', ...
        'errflg', ...
        'ExitCode', ...
        'FinalCost', ...
        'ai', ...
        'ai_coll', ...
        'th', ...
        'ru', ...
        'LeftAiSurface', ...
        'RightAiSurface', ...
        'MaxSurface', ...
        'MaxSurfacePercent', ...
        'LeftAiSurface_deg', ...
        'RightAiSurface_deg', ...
        'ai_coll_deg', ...
        'AileronCollectiveState_deg', ...
        'AileronState1_deg', ...
        'AileronState2_deg', ...
        'AileronState3_deg', ...
        'AileronState4_deg', ...
        'AlphaBody_deg', ...
        'WingIncidence_deg', ...
        'AlphaWing_deg', ...
        'isPositiveStall', ...
        'isNegativeStall', ...
        'isTrimmodConverged', ...
        'isThrottleValid', ...
        'isSurfaceValid', ...
        'isElevatorValid', ...
        'isNearStall', ...
        'isUsableTrim', ...
        'InvalidReason'});

end

function tag = makeTag(prefix, valMin, valMax)
    tag = sprintf('%s_%.3f_to_%.3f', prefix, valMin, valMax);
    tag = strrep(tag, '.', 'p');
    tag = strrep(tag, '-', 'minus');
end