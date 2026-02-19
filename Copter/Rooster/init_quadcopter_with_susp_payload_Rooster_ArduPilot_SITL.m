% init quadcopter Rooster with suspended payload for ArduPilot SITL

% Disclaimer:
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
pos_ref = loadParams( 'flightgearRefPos_params_default' );

%% Flight Gear settings for UDP connection
% Flight Gear URL
fg.remoteURL = '127.0.0.1';
% fdm receive port of Flight Gear
fg.remotePort = 5502;

%% ArduPilot parameters
ap.sample_time   = 1/1000;
ap.prop_channels = [2;3;4;1];

%% Open Simulink model
open_model('QuadcopterWithSuspPayloadSimModel_ArduCopter_SITL');

%% Debug coupling:
%suspPayloadGetFrequencies(copter, susp_payload);
