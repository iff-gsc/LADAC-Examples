%temprorary init for bebob2
clear all;

ap_dragonfly = fmCopterLoiterIndiLoadParams( 'fmCopterLoiterIndi_params_bebop2' );

ap_dragonfly.traj = trajLoadParams('traj_params_default');

waypoints = [ 0 0 0 1; 1 0 -1 1; 0 0 -2 1; -1 0 -1 1 ]'.*[10;10;10;14] + [0;0;-15;0];
ap_dragonfly.atc.rm.leanmax = 2*pi;


sample_time = ap_dragonfly.sample_time;
ap_dragonfly = structDouble2Single(ap_dragonfly);
ap_dragonfly.sample_time = double(sample_time);
clear sample_time;

initInterfaceBuses;