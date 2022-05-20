% init Arducopter Interface for quadcopter Minnie with autopilot Dragonfly

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
% 	Copyright (C) 2022 Yannic Beyer
% 	Copyright (C) 2022 Fabian Guecker
% 	Copyright (C) 2022 Eiker Bremers
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
cd ..
addPathMinnie();
clc_clear;

%% autopilot parameters
ap_dragonfly = apCopterDragonflyLoadParams( 'apCopterDragonfly_params_Minnie' );

%% initialize the Ardupilot Interface
initInterfaceBuses

%% change the main struct from double to float
sample_time = ap_dragonfly.sample_time;
ap_dragonfly = structDouble2Single(ap_dragonfly);
ap_dragonfly.sample_time = double(sample_time);
clear sample_time;

%% open Simulink model
open ArduCopter_MinnieDragonflyController.slx