% ============================================================
% trim_analysis_plots.m
%
% Works for both:
%   - nominal trim sweep
%   - jammed elevator trim sweep
%
% Shows:
%   - usable trim points
%   - stall points
%   - optional diagnostic invalid points
%
% Colour grading:
%   nominal:
%       wing angle of attack
%
%   jammed:
%       selectable using colorMode:
%           - collective aileron deflection
%           - wing angle of attack
%
% Plot styles:
%   plotStyle = "analysis"
%       Clean plot:
%       usable points + stall points
%
%   plotStyle = "diagnostic"
%       Debugging plot:
%       usable points + all invalid categories
% ============================================================

clear; clc; close all;

%% Load trim result files from selected folder

path = uigetdir(pwd, 'Select folder containing trim result .mat files');

if isequal(path, 0)
    error('No folder selected.');
end

filesStruct = dir(fullfile(path, '*.mat'));

if isempty(filesStruct)
    error('No .mat files found in selected folder.');
end

files = {filesStruct.name};

T_all = table();

loadedTrimMode = "";

for iFile = 1:numel(files)

    thisFile = fullfile(path, files{iFile});
    S = load(thisFile);

    if iFile == 1
        if isfield(S, 'elMax_deg'); elMax_deg = S.elMax_deg; end
        if isfield(S, 'elMin_deg'); elMin_deg = S.elMin_deg; end

        if isfield(S, 'aiMax_rad')
            aiMax_rad = S.aiMax_rad;
        elseif isfield(S, 'aiMax_deg')
            aiMax_rad = deg2rad(S.aiMax_deg);
        end

        if isfield(S, 'alphaStallPositive_deg')
            alphaStallPositive_deg = S.alphaStallPositive_deg;
        end

        if isfield(S, 'alphaStallNegative_deg')
            alphaStallNegative_deg = S.alphaStallNegative_deg;
        end

        if isfield(S, 'stallMargin_deg')
            stallMargin_deg = S.stallMargin_deg;
        end
    end

    if ~isfield(S, 'results_table')
        warning('Skipping file because it does not contain results_table: %s', files{iFile});
        continue;
    end

    T_all = [T_all; S.results_table];

    if isfield(S, 'trimMode')
        loadedTrimMode = string(S.trimMode);
    end

end

if isempty(T_all)
    error('No valid results_table found in selected files.');
end

T = T_all;

%% Detect required columns

requiredColumns = {'V_trim', 'Elevator_deg', 'isUsableTrim', ...
    'InvalidReason', 'AlphaWing_deg'};

for iCol = 1:numel(requiredColumns)
    if ~ismember(requiredColumns{iCol}, T.Properties.VariableNames)
        error('results_table must contain %s.', requiredColumns{iCol});
    end
end

%% Choose elevator plotting/grid variable

if loadedTrimMode == "jammed" && ismember('ElevatorJamTarget_deg', T.Properties.VariableNames)
    elevatorGridDeg = T.ElevatorJamTarget_deg;
else
    elevatorGridDeg = T.Elevator_deg;
end

%% Remove duplicate trim cases

T.ElevatorGrid_deg = elevatorGridDeg;

T = sortrows(T, {'ElevatorGrid_deg', 'V_trim'});

[~, uniqueIdx] = unique([T.V_trim, T.ElevatorGrid_deg], 'rows', 'last');
T = T(uniqueIdx, :);

T = sortrows(T, {'ElevatorGrid_deg', 'V_trim'});

%% Determine whether this is nominal or jammed-style plotting

elevatorUnique = unique(round(T.Elevator_deg, 8));

isNominalLike = numel(elevatorUnique) == 1 || loadedTrimMode == "nominal";

fprintf('Loaded %d file(s).\n', numel(files));
fprintf('Total unique trim cases: %d\n', height(T));

if isNominalLike
    fprintf('Detected nominal-style result.\n');
else
    fprintf('Detected jammed-envelope-style result.\n');
end

if ~isNominalLike && ismember('ElevatorJamTarget_deg', T.Properties.VariableNames)
    requiredColumns{end+1} = 'ElevatorJamTarget_deg';
end

%% Basic masks

usable = T.InvalidReason == "Usable";

trimFailed    = T.InvalidReason == "TrimMod failed";
elevatorLimit = T.InvalidReason == "Elevator limit";
throttleLimit = T.InvalidReason == "Throttle limit";
surfaceLimit  = T.InvalidReason == "Aileron surface limit";
stall          = T.InvalidReason == "Stall";

%% Set physical aileron scale

if ~isNominalLike

    if ~ismember('ai_coll', T.Properties.VariableNames)
        error('Jammed plot requires ai_coll in results_table.');
    end

    if ~exist('aiMax_rad', 'var')
        % Fallback from aircraft model value:
        % airplane.act.ailerons.deflectionMax = 0.4887 rad
        aiMax_rad = 0.4887;
        warning('aiMax_rad not found in result file. Using fallback aiMax_rad = 0.4887 rad.');
    end

    aiScale_deg = rad2deg(aiMax_rad);

    % Physical collective aileron deflection:
    % ai_coll is normalized, so +/-1 corresponds to +/- aiMax_rad.
    aiColl_deg = T.ai_coll * aiScale_deg;

    % Solver garbage / nonphysical trim values.
    % These should not influence plotting or color scaling.
    badAiColl = abs(T.ai_coll) > 1.05;

    if any(badAiColl)
        fprintf('\nWarning: %d cases have nonphysical ai_coll values abs(ai_coll) > 1.05.\n', ...
            sum(badAiColl));
        fprintf('These values are excluded from colour scaling and treated as invalid.\n');
    end

else
    badAiColl = false(height(T), 1);
end

%% Stall classification

positiveStall = ...
    stall & T.AlphaWing_deg >= 0;

negativeStall = ...
    stall & T.AlphaWing_deg < 0;

%% Treat nonphysical aileron values as invalid for plotting

if ~isNominalLike
    trimFailed = trimFailed | badAiColl;
end

otherInvalid = ...
    ~usable & ...
    ~stall & ...
    ~trimFailed & ...
    ~elevatorLimit & ...
    ~throttleLimit & ...
    ~surfaceLimit;

%% Print diagnostic summary

fprintf('\n===== Classification summary =====\n');
fprintf('Usable trim cases:        %d\n', sum(usable));
fprintf('Positive stall cases:     %d\n', sum(positiveStall));
fprintf('Negative stall cases:     %d\n', sum(negativeStall));
fprintf('TrimMod failed/bad cases: %d\n', sum(trimFailed));
fprintf('Elevator limit cases:     %d\n', sum(elevatorLimit));
fprintf('Throttle limit cases:     %d\n', sum(throttleLimit));
fprintf('Aileron surface limit:    %d\n', sum(surfaceLimit));
fprintf('Other invalid cases:      %d\n', sum(otherInvalid));

if ~isNominalLike
    fprintf('\nInvalid cases by reason:\n');
    disp(groupsummary(T(~usable,:), 'InvalidReason'));
end

%% Plot settings

plotStyle = "diagnostic";
% Options:
%   "analysis"   -> usable + stall points
%   "diagnostic" -> show all invalid categories

colorMode = "throttle";
% Options:
%   "ai_coll"
%   "alpha_wing"
%   "throttle"

showInvalidPoints = plotStyle == "diagnostic";
saveFigure        = true;

figureFolder = fullfile(path, 'Figures');

if isNominalLike
    plotTitle = 'Nominal trim result classification';
else
    plotTitle = 'Trim feasibility envelope under elevator jam';
end

%% Plot elevator values

% For diagnostic jammed-envelope plots, failed trims should be plotted at
% the requested sweep grid location, not at the returned failed solver state.
elPlot = T.Elevator_deg;

if ~isNominalLike && ismember('ElevatorCommand_degEquivalent', T.Properties.VariableNames)
    elPlot(trimFailed) = T.ElevatorCommand_degEquivalent(trimFailed);
end

%% Main figure

fig = figure('Color', 'w');
set(fig, 'Units', 'centimeters');
set(fig, 'Position', [2 2 24 14]);
hold on; grid on; box on;

V = T.V_trim;
elDeg = elPlot;

%% Colour quantity

if isNominalLike

    colorValue = T.AlphaWing_deg;
    colorLabel = 'Wing angle of attack [deg]';
    colorTag   = 'alphaDeg';
    colorLimits = [min(T.AlphaWing_deg) max(T.AlphaWing_deg)];

else

    switch colorMode

        case "ai_coll"
            colorValue = T.AileronCollectiveState_deg;
            colorLabel = 'Collective aileron deflection [deg]';
            colorTag   = 'aiCollDeg';
            colorLimits = [-aiScale_deg aiScale_deg];

        case "alpha_wing"
            colorValue = T.AlphaWing_deg;
            colorLabel = 'Wing angle of attack [deg]';
            colorTag   = 'alphaDeg';
            colorLimits = [-14 14];

        case "throttle"
            colorValue = T.th;
            colorLabel = 'Throttle command [-]';
            colorTag   = 'throttle';
            colorLimits = [0 1];

        otherwise
            error('Unknown colorMode: %s', colorMode);
    end

    % Do not allow failed/nonphysical cases to stretch colorbar.
    colorValue(trimFailed) = NaN;

end
%% Scatter points

legendHandles = gobjects(0);
legendNames   = {};

% Usable trims
if any(usable)
    h = scatter(V(usable), elDeg(usable), ...
        32, colorValue(usable), ...
        'o', ...
        'filled', ...
        'MarkerEdgeColor', 'k', ...
        'LineWidth', 0.5);

    legendHandles(end+1) = h;
    legendNames{end+1} = 'Usable trim';
end

% Positive stall
if any(positiveStall)
    h = scatter(V(positiveStall), elDeg(positiveStall), ...
        35, colorValue(positiveStall), ...
        'x', ...
        'LineWidth', 1);

    legendHandles(end+1) = h;
    legendNames{end+1} = 'Positive stall';
end

% Negative stall
if any(negativeStall)
    h = scatter(V(negativeStall), elDeg(negativeStall), ...
        35, colorValue(negativeStall), ...
        'v', ...
        'LineWidth', 1);

    legendHandles(end+1) = h;
    legendNames{end+1} = 'Negative stall';
end

if showInvalidPoints

    if any(trimFailed)
        h = scatter(V(trimFailed), elDeg(trimFailed), ...
            28, [0.75 0.75 0.75], ...
            '+', ...
            'LineWidth', 0.8);

        legendHandles(end+1) = h;
        legendNames{end+1} = 'TrimMod failed';
    end

    if any(elevatorLimit)
        h = scatter(V(elevatorLimit), elDeg(elevatorLimit), ...
            28, [0.65 0.00 0.85], ...
            's', ...
            'LineWidth', 0.8);

        legendHandles(end+1) = h;
        legendNames{end+1} = 'Elevator saturation';
    end

    if any(throttleLimit)
        h = scatter(V(throttleLimit), elDeg(throttleLimit), ...
            28, [0.00 0.55 0.00], ...
            'd', ...
            'LineWidth', 0.8);

        legendHandles(end+1) = h;
        legendNames{end+1} = 'Throttle limit';
    end

    if any(surfaceLimit)
        h = scatter(V(surfaceLimit), elDeg(surfaceLimit), ...
            28, [0.00 0.60 0.85], ...
            '^', ...
            'LineWidth', 0.8);

        legendHandles(end+1) = h;
        legendNames{end+1} = 'Aileron surface limit';
    end

    if any(otherInvalid)
        h = scatter(V(otherInvalid), elDeg(otherInvalid), ...
            35, [0.75 0.00 0.75], ...
            '.');

        legendHandles(end+1) = h;
        legendNames{end+1} = 'Other invalid';
    end

end
%% Elevator actuator limits

if exist('elMax_deg', 'var')

    hElevLimit = yline(elMax_deg, '--', ...
        'Color', [0.4 0.4 0.4], ...
        'LineWidth', 1.0);

    legendHandles(end+1) = hElevLimit;
    legendNames{end+1} = 'Elevator limits';

end

if exist('elMin_deg', 'var')
    yline(elMin_deg, '--', ...
        'Color', [0.4 0.4 0.4], ...
        'LineWidth', 1.0, ...
        'HandleVisibility', 'off');
end

%% Colour bar

cb = colorbar;
cb.Label.String = colorLabel;
cb.Label.Interpreter = 'latex';

clim(colorLimits)

%% Labels and title

xlabel('Airspeed $V$ [m/s]', 'Interpreter', 'latex');

if isNominalLike
    ylabel('Elevator deflection $\delta_e$ [deg]', 'Interpreter', 'latex');
else
    ylabel('Elevator jam angle $\delta_{e,\mathrm{jam}}$ [deg]', ...
        'Interpreter', 'latex');
end

title(plotTitle, 'Interpreter', 'latex');

%% Axes formatting

ax = gca;
ax.TickLabelInterpreter = 'latex';
ax.FontSize = 12;
ax.GridAlpha = 0.10;
ax.LineWidth = 1.0;

xlim([min(V), max(V)]);

validY = elDeg(~isnan(elDeg));

if ~isempty(validY)
    yPadding = 0.05 * range(validY);
    if yPadding == 0
        yPadding = 1;
    end

    ylim([min(validY) - yPadding, max(validY) + yPadding]);
end

legend(legendHandles, legendNames, ...
    'Interpreter', 'latex', ...
    'Location', 'southeast');
%% Save figure

if saveFigure
    if ~exist(figureFolder, 'dir')
        mkdir(figureFolder);
    end

    if isNominalLike
        outputName = fullfile(figureFolder, ...
            sprintf('nominal_trim_classification_%s.png', plotStyle));
    else
        outputName = fullfile(figureFolder, ...
            sprintf('jammed_trim_feasibility_envelope_%s_%s.png', colorTag, plotStyle));
    end

    print(fig, outputName, '-dpng', '-r500');

    fprintf('\nSaved figure to:\n%s\n', outputName);
end