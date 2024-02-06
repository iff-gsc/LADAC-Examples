% init Arducopter Interface for quadcopter Minnie with autopilot
% LindiCopter

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
% 	Copyright (C) 2022 Yannic Beyer
% 	Copyright (C) 2022 Fabian Guecker
% 	Copyright (C) 2022 Eike Bremers
% 	Copyright (C) 2024 Jonas Withelm
%   Copyright (C) 2024 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
cd ..
addPathMinnie();
clc_clear;

%% copter parameters
copter = copterLoadParams( 'copter_params_Minnie' );

%% autopilot parameters
lindi = lindiCopterAutoCreate( copter );
lindi_notune = loadParams( 'lindiCopter_params_notune_default' );

%% initialize the Ardupilot Interface
ardupilotCreateInputBuses();

%% change the autopilot structs from double to single
lindi = structDouble2Single(lindi);
lindi_notune = structDouble2Single(lindi_notune);
lindi_notune.ts = double(lindi_notune.ts);

%% open Simulink model
open ArduCopter_MinnieLindiCopter.slx
