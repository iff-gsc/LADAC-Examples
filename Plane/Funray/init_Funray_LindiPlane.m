% Initialize airplane Funray with autopilot LindiPlane

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2024 Yannic Beyer
%   Copyright (C) 2024 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% Clear workspace and console
addPathFunray();
clc_clear;

%% Init simulation parameters
% Airplane parameters
airplane = conventionalAirplaneLoadParams( 'airplane_params_Funray' );

% Environment parameters
envir = envirLoadParams( 'envir_params_default', 'envir', 0 );

% Joystick parameters
jystck = joystickLoadParams('joystick_params_Xbox_360',2,-1);

% Initial altitude
airplane.posRef.alt = 50;

% Initial location (San Francisco)
airplane.posRef.lat = 37.6117;
airplane.posRef.lon = -122.37822;

% Inital conditons of rigid-body motion
airplane.ic.q_bg = euler2Quat([0;0;-1.4]);
airplane.ic.V_Kb = [15;0;0];
airplane.ic.s_Kg = [10; 0; 0];
airplane.ic.omega_Kb = [0; 0; 0];

%% Define waypoints
waypoints = [ 0 0 0; 0 -1 0; 1 -1 0; 1 0 0 ]'*250 + [0;-100;0];

%% Compute LindiPlane parameters
[lindi,lindi_notune] = lindiPlaneAutoCreate( airplane, 'SensFilt', [50,1], 'AgilityAtti', 1.3, 'AgilityPos', 1.3, 'ServoBoost', 0.6 );

%% Open model
open_model('AirplaneSimModel_LindiPlane');
