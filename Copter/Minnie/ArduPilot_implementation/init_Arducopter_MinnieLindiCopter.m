% init Arducopter Interface for quadcopter Minnie with autopilot
% LindiCopter

% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
% 	Copyright (C) 2022 Yannic Beyer
% 	Copyright (C) 2022 Fabian Guecker
% 	Copyright (C) 2022 Eike Bremers
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
cd ..
addPathMinnie();
clc_clear;

%% autopilot parameters
copter = copterLoadParams( 'copter_params_Minnie' );
lindi = lindiCopterAutoCreate( copter );

%% initialize the Ardupilot Interface
ardupilotCreateInputBuses();

%% change the main struct from double to float
lindi = structDouble2Single(lindi);
lindi.ts = double(lindi.ts);

%% open Simulink model
open ArduCopter_MinnieLindiCopter.slx
