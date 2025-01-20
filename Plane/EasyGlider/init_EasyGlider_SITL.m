%  ** init EasyGlider with ArduPlane SITL **

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
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

channel_idx = 1:5;

% environment parameters
envir = envirLoadParams( 'envir_params_default', 'envir',0 );

% open simulink model
open_model('AirplaneSimModel_SITL')
