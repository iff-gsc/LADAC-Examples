% Change to this folder
this_file_path = fileparts(mfilename('fullpath'));
cd(this_file_path);

% Add subfolders to path
addpath(genpath(this_file_path));

% Change current folder to workbenches 
cd('workbenches')

% Run all tests in workbenches
tic;
rt = table(runtests([pwd],'IncludeSubfolders',true))
toc;