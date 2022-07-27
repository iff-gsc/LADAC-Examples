% Init for ArduPlane Custom mode including the sysID and Waypoint feature

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Fabian Guecker
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************


%% Clear workspace and console
addPathEasyGlider();
clc_clear;

g = 9.81;



load EX_V-12_T-10_22-03-24_16-16
Maneuver = Experiments.ShortPeriod_Sweep_lin; range = [1000, 3002];
%Maneuver = Experiments.ShortPeriod_Sweep_log; range = [1000, 3002];
%Maneuver = Experiments.ShortPeriod_DutchRoll_Multisine; range = [1000, 3002];
%Maneuver = Experiments.Phugoid_Spiral_Multisine; range = [1000, 3002];
%Maneuver = Experiments.Roll_Doublettes_pos;  range = [1000, 1176];
%Maneuver = Experiments.Phugoid_Pulse_pos; range = [1000, 1005];

signals(:,1) = single(Maneuver.Aileron(range(1):range(2)));
signals(:,2) = single(Maneuver.Elevator(range(1):range(2)));
signals(:,3) = single(Maneuver.Rudder(range(1):range(2)));
signals_size = length(signals);


%traj_Parms = trajLoadParams('traj_params_default');
waypoints = [1 -1 0.2; 2 0 -0.5; 1 1 0; -1 -1 0; -2 0 -0.5; -1 1 0.2]'*15;
cycle = true;

%% Generate empty trajectory struct and bus definition for simulink 

degree = 5;

% Create emptry trajectory with a maximum space for 10 waypoints
traj_size = size(waypoints,2);
[traj_empty] = trajInit(traj_size, degree);

% Create simulink bus definition
trajectoryBus = struct2bus_(traj_empty);
traj_parms = trajLoadParams( 'traj_params_default');
traj_parms = structDouble2Single(traj_parms);
%set_param(gcs, 'DataTypeOverride', 'Single','DataTypeOverrideAppliesTo','Floating-point')
%set_param(gcs, 'DefaultUnderspecifiedDataType', 'single')

K_roll  = ndiFeedbackGainPlace(-0.5*ones(2,1), 0);
K_pitch = ndiFeedbackGainPlace(-0.5*ones(2,1), 0);
K_yaw   = ndiFeedbackGainPlace(-0.5*ones(2,1), 0);

K_thurst  = ndiFeedbackGainPlace(-0.5*ones(2,1), 0);


trim_speed = 14;

initInterfaceBuses;

open('EasyGlider_ManualMode_with_waypoints_and_sysID.slx')