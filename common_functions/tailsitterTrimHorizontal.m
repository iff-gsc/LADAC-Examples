function [x,u,op] = tailsitterTrimHorizontal( groundspeed )
% Search for a specified operating point for the model TailsitterSimModel_Trim.

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% Specify the model name
model = 'TailsitterSimModel_Trim';

%% Create the operating point specification object.
opspec = operspec(model);

%% Set the constraints on the states in the model.
% - The defaults for all states are Known = false, SteadyState = true,
%   Min = -Inf, Max = Inf, dxMin = -Inf, and dxMax = Inf.

% State (1) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/State equations (Quaternions)/V__Kb
% - Default model initial conditions are used to initialize optimization.

% State (2) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/State equations (Quaternions)/q_bg
opspec.States(2).x = [0.73169;0;0.68164;0];

% State (3) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/State equations (Quaternions)/rates
% - Default model initial conditions are used to initialize optimization.
opspec.States(3).Known = [true;true;true];

% State (4) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/State equations (Quaternions)/s__g
opspec.States(4).x = [0;0;-15];
opspec.States(4).Known = [false;false;true];
opspec.States(4).SteadyState = [false;false;true];

% State (5) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/servo dynamics/Integrator
opspec.States(5).x = [1240;1240];

% State (6) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/servo dynamics/Nonlinear Second-Order Actuator/A
% - Default model initial conditions are used to initialize optimization.
opspec.States(6).Min = [-0.43633;-0.43633];
opspec.States(6).Max = [0.43633;0.43633];

% State (7) - TailsitterSimModel_Trim/Tailsitter Flight Dynamics/servo dynamics/Nonlinear Second-Order Actuator/dot_A
% - Default model initial conditions are used to initialize optimization.
opspec.States(7).Known = [true;true];
opspec.States(7).Min = [-6.9813;-6.9813];
opspec.States(7).Max = [6.9813;6.9813];

%% Set the constraints on the inputs in the model.
% - The defaults for all inputs are Known = false, Min = -Inf, and
% Max = Inf.

% Input (1) - TailsitterSimModel_Trim/cmd_eta
opspec.Inputs(1).u = [1500;1500];
opspec.Inputs(1).Min = [1000;1000];
opspec.Inputs(1).Max = [2000;2000];

% Input (2) - TailsitterSimModel_Trim/cmd_motors
opspec.Inputs(2).u = [1500;1500];
opspec.Inputs(2).Min = [1000;1000];
opspec.Inputs(2).Max = [2000;2000];

%% Set the constraints on the outputs in the model.
% - The defaults for all outputs are Known = false, Min = -Inf, and
% Max = Inf.

% Output (1) - TailsitterSimModel_Trim/Rates
% - Default model initial conditions are used to initialize optimization.

% Output (2) - TailsitterSimModel_Trim/EulerAngles
opspec.Outputs(2).y = [0;0.5;0];

% Output (3) - TailsitterSimModel_Trim/velocity
opspec.Outputs(3).y = [groundspeed;0;0];
opspec.Outputs(3).Known = [true;true;false];

% Output (4) - TailsitterSimModel_Trim/s_Kg
% - Default model initial conditions are used to initialize optimization.


%% Create the options
opt = findopOptions('OptimizerType','lsqnonlin',...
    'DisplayReport','iter');
opt.OptimizationOptions.MaxFunEvals = 6000;
opt.OptimizationOptions.MaxIter = 1200;

%% Perform the operating point search.
try
    [op,opreport] = findop(model,opspec,opt);
    
    x.velocity = op.States(1).x;
    x.quaternion = op.States(2).x;
    x.rates = op.States(3).x;
    x.position = op.States(4).x;
    x.motor_speed = op.States(5).x;
    x.elevon_deflection = op.States(6).x;
    x.elevon_deflection_rate = op.States(7).x;
    u.cmd_eta = op.Inputs(1).u;
    u.cmd_motors = op.Inputs(2).u;
    
catch
    
    x.velocity = zeros(3,1);
    x.quaternion = zeros(3,1);
    x.rates = zeros(3,1);
    x.position = zeros(3,1);
    x.motor_speed = zeros(2,1);
    x.elevon_deflection = zeros(2,1);
    x.elevon_deflection_rate = zeros(2,1);
    u.cmd_eta = zeros(2,1);
    u.cmd_motors = zeros(2,1);

end
    

end
