
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
addPathMinnie();
clc_clear;

%% load physical copter parameters
copter = copterLoadParams( 'copter_params_Minnie' );

%% environment parameters
envir = envirLoadParams('params_envir','envir',0);

%% initial conditions (IC)
% load initial conditions
IC = loadInitialConditionsParams( 'params_initial_conditions_hover' );

% initial motor angular velocity, in rad/s
IC.omega_mot = [ 0; 0; 0; 0 ];

%% load ground parameters (grnd)
grnd = groundLoadParams( 'params_ground_default' );

%% reference position lat, lon, alt
pos_ref = posRefLoadParams( 'reference_position_params_default' );
% initial altitude, in m
pos_ref.alt = 10;

%% Flight Gear settings for UDP connection
% Flight Gear URL
fg.remoteURL = '127.0.0.1';
% fdm receive port of Flight Gear
fg.remotePort = 5502;

%% ArduPilot SITL parameters
SITL.sample_time = 1/400;

%% Open Simulink model
open_model('QuadcopterSimModel_ArduCopter_SITL')
