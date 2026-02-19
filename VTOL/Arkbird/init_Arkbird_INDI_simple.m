
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

tailsitter.posRef.alt = tailsitter.posRef.alt + 1;

%% environment parameters
envir = envirLoadParams('envir_params_default','envirBus',0);

%% controller parameters
fm_atti = loadParams( 'fm_copter_atti_indi_params_Arkbird' );

%% joystick
jystck = joystickLoadParams( 'joystick_params_Xbox_360', 2, -1 );

%% open simulink file
% open slx
open_model('TailsitterSimModel_INDI_simple');
