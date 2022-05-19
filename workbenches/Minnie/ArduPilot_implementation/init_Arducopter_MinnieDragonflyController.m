% Init Arducopter Interface for quadcopter Minnie with autopilot Dragonfly

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add to path
cd ..
addPathMinnie();
clc_clear;

%% waypoints
waypoints = [ 0 0 0 1; 1 0 -1 1; 0 0 -2 1; -1 0 -1 1 ]'.*[10;10;10;14] + [0;0;-15;0];

%% autopilot parameters
ap_dragonfly = apCopterDragonflyLoadParams( 'apCopterDragonfly_params_Minnie' );

%% initialize the Ardupilot Interface
initInterfaceBuses

%% Change the main struct from double to float
Sample_Time = ap_dragonfly.sample_time;
ap_dragonfly = structDouble2Single(ap_dragonfly);
ap_dragonfly.sample_time = double(Sample_Time);
clear Sample_Time;

open ArduCopter_MinnieDragonflyController.slx