function [] = addPathEasyGlider()

% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% *************************************************************************

this_file_path = fileparts(mfilename('fullpath'));
cd(this_file_path);
addpath(genpath(this_file_path));
cd ..
addPathPlane();
cd(this_file_path);

end