function [xTrim,uTrim,op] = trimSteady( model, EulerAngles, EulerAngles_known, V_Kg, V_Kg_known )
% Search for a specified operating point for the model QuadcopterSimModel.

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% Specify the model name
% model = 'QuadcopterSimModel';

%% Create the operating point specification object.
opspec = operspec(model);

k_else = [];

for k = 1:length(opspec.States)
    if strcmp(opspec.States(k).StateName,'velocity')
        k_velocity = k;
    elseif strcmp(opspec.States(k).StateName,'quaternion')
        k_quaternion = k;
    elseif strcmp(opspec.States(k).StateName,'rates')
        k_rates = k;
    elseif strcmp(opspec.States(k).StateName,'position')
        k_position = k;
    elseif strcmp(opspec.States(k).StateName,'motor_speed')
        k_motor_speed = k;
    else
        k_else = [k_else,k];
    end
end
    

%% Set the constraints on the states in the model.
% - The defaults for all states are Known = false, SteadyState = true,
%   Min = -Inf, Max = Inf, dxMin = -Inf, and dxMax = Inf.

% State (1) - QuadcopterSimModel/Quadcopter/Integrator
opspec.States(k_motor_speed).x = [100;100;100;100];
opspec.States(k_motor_speed).Known = [false;false;false;false];
opspec.States(k_motor_speed).SteadyState = [true;true;true;true];
opspec.States(k_motor_speed).Min = [-Inf;-Inf;-Inf;-Inf];
opspec.States(k_motor_speed).Max = [Inf;Inf;Inf;Inf];
opspec.States(k_motor_speed).dxMin = [-Inf;-Inf;-Inf;-Inf];
opspec.States(k_motor_speed).dxMax = [Inf;Inf;Inf;Inf];

% State (2) - QuadcopterSimModel/Quadcopter/State equations (Quaternions)/V__Kb
opspec.States(k_velocity).x = [0;0;0];
opspec.States(k_velocity).Known = [false;false;false];
opspec.States(k_velocity).SteadyState = [true;true;true];
opspec.States(k_velocity).Min = [-Inf;-Inf;-Inf];
opspec.States(k_velocity).Max = [Inf;Inf;Inf];
opspec.States(k_velocity).dxMin = [-Inf;-Inf;-Inf];
opspec.States(k_velocity).dxMax = [Inf;Inf;Inf];

% State (3) - QuadcopterSimModel/Quadcopter/State equations (Quaternions)/q_bg
opspec.States(k_quaternion).x = [1;0;0;0];
opspec.States(k_quaternion).Known = [false;false;false;false];
opspec.States(k_quaternion).SteadyState = [true;true;true;true];
opspec.States(k_quaternion).Min = [-Inf;-Inf;-Inf;-Inf];
opspec.States(k_quaternion).Max = [Inf;Inf;Inf;Inf];
opspec.States(k_quaternion).dxMin = [-Inf;-Inf;-Inf;-Inf];
opspec.States(k_quaternion).dxMax = [Inf;Inf;Inf;Inf];

% State (4) - QuadcopterSimModel/Quadcopter/State equations (Quaternions)/rates
opspec.States(k_rates).x = [0;0;0];
opspec.States(k_rates).Known = [true;true;true];
opspec.States(k_rates).SteadyState = [true;true;true];
opspec.States(k_rates).Min = [-Inf;-Inf;-Inf];
opspec.States(k_rates).Max = [Inf;Inf;Inf];
opspec.States(k_rates).dxMin = [-Inf;-Inf;-Inf];
opspec.States(k_rates).dxMax = [Inf;Inf;Inf];

% State (5) - QuadcopterSimModel/Quadcopter/State equations (Quaternions)/s__g
opspec.States(k_position).x = [0;0;-15];
opspec.States(k_position).Known = [true;true;true];
opspec.States(k_position).SteadyState = [false;false;false];

% State (6) - QuadcopterSimModel/Environment/From FlightGear/Receive net_ctrl Packet from FlightGear/UDP Receive
for i = 1:length(k_else)
    opspec.States(k_else(i)).x(:) = 0;
    opspec.States(k_else(i)).Known(:) = true;
    opspec.States(k_else(i)).SteadyState(:) = true;
end

%% Set the constraints on the inputs in the model.
% - The defaults for all inputs are Known = false, Min = -Inf, and
% Max = Inf.

% Input (1) - QuadcopterSimModel/Input
opspec.Inputs(1).u = [0.5;0.5;0.5;0.5];
opspec.Inputs(1).Min = [0;0;0;0];
opspec.Inputs(1).Max = [1;1;1;1];

%% Set the constraints on the outputs in the model.
% - The defaults for all outputs are Known = false, Min = -Inf, and
% Max = Inf.

% Output (1) - QuadcopterSimModel/omega_Kb
% - Default model initial conditions are used to initialize optimization.

% Output (2) - QuadcopterSimModel/EulerAngles
opspec.Outputs(2).y = EulerAngles;
opspec.Outputs(2).Known = EulerAngles_known;

% Output (3) - QuadcopterSimModel/V_Kg
% - Default model initial conditions are used to initialize optimization.
opspec.Outputs(3).y = V_Kg;
opspec.Outputs(3).Known = V_Kg_known;


%% Create the options
opt = findopOptions('OptimizerType','graddescent',...
    'DisplayReport','iter');
opt.OptimizationOptions.Algorithm = 'interior-point';

%% Perform the operating point search.
[op,~] = findop(model,opspec,opt);

%% output
% define the struct of the input vector (uTrim) as well as the struct of the
% initial integrator conditins (IC) from the determined trim point
uTrim.cmd = op.Inputs(1).u;

xTrim.q_bg = op.States(k_quaternion).x;
xTrim.V_Kb = op.States(k_velocity).x;
xTrim.omega_Kb = op.States(k_rates).x;
xTrim.s_Kg = op.States(k_position).x;
xTrim.motor_speed = op.States(k_motor_speed).x;


end
