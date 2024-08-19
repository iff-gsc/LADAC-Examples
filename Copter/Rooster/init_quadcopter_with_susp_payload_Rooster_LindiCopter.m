% init quadcopter Rooster with suspended payload for ArduPilot SITL

% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2023 Jonas Withelm
%   Copyright (C) 2023 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
addPathRooster();
clc_clear;

%% load physical copter parameters
copter = copterLoadParams( 'copter_params_Rooster',...
                           'Battery', 'bat_4S1P_1550_Tattu_V2');
%% waypoints
waypoints = [ 0 0 0 1; 1 0 -1 1; 0 0 -2 1; -1 0 -1 1 ]'.*[10;10;10;14*1.0] + [20;0;-15;0];

%% autopilot parameters
lindi = lindiCopterAutoCreate( copter, ...
                              'caWls_params', 'caWls_params_Minnie', ...
                              'MtcScaling', 1.2 );

lindi_notune = loadParams( 'lindiCopter_params_notune_default' );

%% joystick
joystick = joystickLoadParams( 'joystick_params_Xbox_360', 2, 0 );

%% environment parameters
envir = envirLoadParams('params_envir','envir',0);

%% initial conditions (IC)
% load initial conditions
IC = loadInitialConditionsParams( 'params_initial_conditions_hover' );

% initial motor angular velocity, in rad/s
IC.omega_mot = [ 0; 0; 0; 0 ];

%% load suspended payload parameters
[susp_payload, IC_susp_payload] = suspPayloadLoadParams('susp_payload_params_Rooster.m', copter, IC, envir);

%% load ground parameters (grnd)
grnd = groundLoadParams( 'params_ground_default' );

%% reference position lat, lon, alt
pos_ref     = posRefLoadParams( 'reference_position_params_default' );
pos_ref.alt = 5.85;

%% Flight Gear settings for UDP connection
% Flight Gear URL
fg.remoteURL = '127.0.0.1';
% fdm receive port of Flight Gear
fg.remotePort = 5502;

%% Open Simulink model
open_model('QuadcopterWithSuspPayloadSimModel_LindiCopter');
