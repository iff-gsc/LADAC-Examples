% init quadcopter Minnie with autopilot LindiCopter

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
addPathMinnie();
clc_clear;

%% waypoints
% a = V^2/r = 14^2/10 = 2*g
waypoints = [ 0 0 0 1; 1 0 -1 1; 0 0 -2 1; -1 0 -1 1 ]'.*[14;14;14;14*1.0] + [20;0;-15;0];
% waypoints = [ 0 0 0 1; 1 1 0 1; 0 2 0 1; -1 1 0 1]'.*[14;14;14;14] + [0;0;-5;0];

%% load physical copter parameters
copter = copterLoadParams( 'copter_params_Minnie' );

%% environment parameters
envir = envirLoadParams('params_envir','envir',0);

%% autopilot parameters
lindi = lindiCopterAutoCreate( copter, ...
                              'caWls_params', 'caWls_params_Minnie', ...
                              'MtcScaling', 1.2 );
lindi.atc.rm.leanmax = pi;

lindi_notune = loadParams( 'lindiCopter_params_notune_default' );

%% joystick
joystick = joystickLoadParams( 'joystick_params_Xbox_360', 2, 0 );

%% initial conditions (IC)
% load initial conditions
IC = loadInitialConditionsParams( 'params_initial_conditions_hover' );

% initial motor angular velocity, in rad/s
IC.omega_mot = [ 1; 1; 1; 1 ] * 843;

%% load ground parameters (grnd)
grnd = groundLoadParams( 'params_ground_default' );

%% reference position lat, lon, alt
% initial latitude, in deg
pos_ref.lat = 37.6117;
% initial longitude, in deg
pos_ref.lon = -122.37822;
% initial altitude, in m
pos_ref.alt = 10;

%% Flight Gear settings for UDP connection
% Flight Gear URL
fg.remoteURL = '127.0.0.1';
% fdm receive port of Flight Gear
fg.remotePort = 5502;

%% Open Simulink model
open_model('QuadcopterSimModel_LindiCopter')