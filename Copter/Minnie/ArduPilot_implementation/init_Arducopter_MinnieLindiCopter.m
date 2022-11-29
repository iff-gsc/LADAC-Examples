% init Arducopter Interface for quadcopter Minnie with autopilot Dragonfly
% 
% ATTENTION:
%   THE FLIGHT TEST WITH THIS VERSION WAS NOT A SUCCESS!
%   The copter simply flew straight up for reasons as yet unexplained, even
%   when Custom Guided Mode was deactivated.

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
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
lindiCopter_params = lindiCopterAutoCreate( copter );

%% initialize the Ardupilot Interface
ardupilotCreateInputBuses();

%% change the main struct from double to float
lindiCopter_params = structDouble2Single(lindiCopter_params);
lindiCopter_params.ts = double(lindiCopter_params.ts);

%% open Simulink model
open ArduCopter_MinnieLindiCopter.slx
