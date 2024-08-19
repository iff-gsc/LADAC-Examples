function [] = addPathLadacExamples()

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% *************************************************************************

% go to correct directory
init_scripts_path = fileparts(mfilename('fullpath'));
cd(init_scripts_path);
cd ..

% add folders to path
addpath(genpath('common_functions'));
addpath(genpath('modules'));

end