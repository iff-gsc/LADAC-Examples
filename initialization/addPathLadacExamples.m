function [] = addPathLadacExamples()

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% go to correct directory
init_scripts_path = fileparts(mfilename('fullpath'));
cd(init_scripts_path);
cd ..

% add folders to path
addpath(genpath('common_functions'));
addpath(genpath('initialization'));
addpath(genpath('libraries'));
addpath(genpath('models'));

end