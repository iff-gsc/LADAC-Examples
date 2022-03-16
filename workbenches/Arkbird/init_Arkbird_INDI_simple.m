
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
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

%% controller parameters
fm_atti = fmCopterAttiIndiLoadParams( 'fm_copter_atti_indi_params_Arkbird' );

%% joystick
jystck = joystickLoadParams( 'joystick_params_Xbox_360', 2, -1 );

%% open simulink file
% set simulation pace to real time
pace = 1;
% open slx
open_model('TailsitterSimModel_INDI_simple');
