%  ** init EasyGlider with manual joystick input **

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Fabian Guecker
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% set path
addPathEasyGlider();
clc_clear;

% init airplane parameters
airplane = conventionalAirplaneLoadParams( ...
	'params_conventional_airplane_EasyGlider' );

% environment parameters
envir = envirLoadParams( 'envir_params_default', 'envir', 0 );

% should a joystick be used?
cntrl.enable_remote_control = true;

jystck = joystickLoadParams('joystick_params_Taranis_X9D',4,0);

% open simulink model
open_model('AirplaneSimModel')
