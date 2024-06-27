% Funray parameter initialization for C++ code generation for ArduPlane

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2024 Yannic Beyer
%   Copyright (C) 2024 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% Clear workspace and console
addPathFunray();
clc_clear;

%% Init airplane parameters
airplane = conventionalAirplaneLoadParams( 'airplane_params_Funray' );

%% Compute LindiPlane parameters
[lindi,lindi_notune] = lindiPlaneAutoCreate( airplane, 'SensFilt', [50,1], 'AgilityAtti', 1.2, 'AgilityPos', 1.0, 'ServoBoost', 0.6 );
lindi.ceb.scale = 1.2;
lindi = structDouble2Single(lindi);
lindi_notune = structDouble2Single(lindi_notune);

%% Init ArduPlane custom controller interface buses
clearAllBuses();
ardupilotCreateInputBuses();

%% Open model
open_model('ArduPlane_LindiPlane');
