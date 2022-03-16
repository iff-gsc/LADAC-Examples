
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
addPathIris();
clc_clear;

%% load physical copter parameters
copter = copterLoadParams( 'params_copter_IRIS' );

%% environment parameters
envir = envirLoadParams('params_envir','envir',0);

%% initial conditions (IC)
% load initial conditions
IC = loadInitialConditionsParams( 'params_initial_conditions_hover' );

% initial motor angular velocity, in rad/s
IC.omega_mot = [ 1; 1; 1; 1 ] * 497.6862;
% trim command
u_Trim = ones(4,1) * 0.6254;

%% reference position lat, lon, alt
% initial latitude, in deg
pos_ref.lat = 37.6117;
% initial longitude, in deg
pos_ref.lon = -122.37822;
% initial altitude, in m
pos_ref.alt = 7;

%% load ground parameters (grnd)
grnd = groundLoadParams( 'params_ground_default' );

%% Flight Gear settings for UDP connection
% Flight Gear URL
fg.remoteURL = '127.0.0.1';
% fdm receive port of Flight Gear
fg.remotePort = 5502;

%% ArduPilot SITL parameters
SITL.sample_time = 1/400;

%% Set pacer parameters
pacer.pace = 1;
pacer.sample_time = 1/100;

%% Open Simulink model
open_model('QuadcopterSimModel_ArduCopter_SITL')
