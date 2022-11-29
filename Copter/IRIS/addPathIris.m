function [] = addPathIris()

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% *************************************************************************

this_file_path = fileparts(mfilename('fullpath'));
cd(this_file_path);
addpath(genpath(this_file_path));
cd ..
addPathCopter();
cd(this_file_path);

end