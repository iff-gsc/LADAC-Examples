% Change to this folder
this_file_path = fileparts(mfilename('fullpath'));
cd(this_file_path);

% Run all tests in workbenches
tic;
cd Copter
addPathCopter();
rt = table(runtests([pwd,'/Copter'],'IncludeSubfolders',true))
cd Plane
addPathPlane();
rt = table(runtests([pwd,'/Plane'],'IncludeSubfolders',true))
cd VTOL
addPathVtol();
rt = table(runtests([pwd,'/VTOL'],'IncludeSubfolders',true))
toc;