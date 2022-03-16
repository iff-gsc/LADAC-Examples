% High Dynamic Trajectory Following Example for Aircraft

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Fabian Guecker
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% Clear workspace and console
addPathEasyGlider();
clc_clear;

%% Create waypoints
% Acht
waypoints = [1 -1 0.2; 2 0 -0.5; 1 1 0; -1 -1 0; -2 0 -0.5; -1 1 0.2]'*15;
cycle = true;

%% Generate empty trajectory struct and bus definition for simulink 

degree = 5;

% Create emptry trajectory with a maximum space for 10 waypoints
traj_size = size(waypoints,2);
[traj_empty] = trajInit(traj_size, degree);

% Create simulink bus definition
trajectoryBus = struct2bus_(traj_empty);

%% compute cubic-spline trajectory

traj = trajInit(traj_size, degree);
traj = trajFromWaypoints(traj, waypoints, degree, cycle);

%% compute hobby-spline trajectory
num_waypoints = size(waypoints,2);
points = cell(num_waypoints,1);
for k = 1:num_waypoints
    points(k) = {waypoints(:,k)'};
end

%% Calculate inital values for smooth simulation

% inital velocity (norm)
inital_velo  = 15;
g = 9.81;

% inital positon
inital_point = waypoints(:,1);

% inital velocity vector and acceleration
%[active_section, Error, t] = trajGetMatch(traj, inital_point);
[active_section, Error, t] = trajGetMatchEnhanced(traj, inital_point);

traj_section = trajGetSection(traj,active_section);
[T, B, N] = trajSectionGetFrenetSerretWithGravity(traj_section,inital_velo, g, t);
inital_vel_vec = inital_velo * T;

% Calculate inital attitude
initalSerretFrame = [T, B, -N];
inital_quaternion = rotm2quat(initalSerretFrame);

%% Plot trajectory with expected acceleration for constant given velocity

figure(1);
% new_waypoints = trajPlot(traj, inital_velo, g);
trajPlot(traj, inital_velo, g);
view([-1 -1.2 0.5])
axis equal

%% init airplane parameters
% init airplane parameters
airplane = conventionalAirplaneLoadParams( ...
	'params_conventional_airplane_EasyGlider' );

% environment parameters
envir = envirLoadParams( 'envir_params_default', 'envir', 0 );

% should a joystick be used?
cntrl.enable_remote_control = true;

jystck = joystickLoadParams('joystick_params_Taranis_X9D',4,0);

% Updated inital parameters
airplane.posRef.alt = 50;

% Iceland
%airplane.posRef.lat = 63.985024;
%airplane.posRef.lon = -22.597652;

% Honolulu
airplane.posRef.lat = 21.325229677012764;
airplane.posRef.lon = -157.93891162805602;

% Update inital conditons to active trajectory
airplane.ic.q_bg = inital_quaternion';
airplane.ic.V_Kb = [norm(inital_vel_vec);0;0];
airplane.ic.s_Kg = inital_point + [0; 0; 0];
airplane.ic.omega_Kb = [0; 0; 0];

% Control effectiveness at 14 m/s for EasyGlider model
B_aileron_p_14ms = 97.75*(inital_velo/14);
B_elevator_q_14ms = 58.11*(inital_velo/14);
B_rudder_r_14ms = 17.59*(inital_velo/14);

% INDI Attitude Controller
K_atti = ndiFeedbackGainPlace( -10*ones(3,1), 2/80 + 2/100 );

% Position Controller Vertical-Channel
K_vertical = ndiFeedbackGainPlace(-2*ones(3,1), 0);

% Position Controller Lateral-Channel
K_lateral = ndiFeedbackGainPlace( -1*ones(3,1), 0);

%% open model

open_model('AirplaneSimModel_AutomaticTrajectory');
