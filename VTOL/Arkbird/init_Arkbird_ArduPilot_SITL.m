
% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% add folders to path
addPathArkbird();
clc_clear;

%% load Arkbird parameters
tailsitter = tailsitterLoadParams( 'tailsitter_params_Arkbird' );

%% environment parameters
envir = envirLoadParams('envir_params_default','envirBus',0);

%% SITL parameters
% sample time (1/300s used in Arkbird config)
SITL.sample_time = 1/300;

%% open simulink file
% open slx
open_model('TailsitterSimModel_ArduPilot_SITL');
