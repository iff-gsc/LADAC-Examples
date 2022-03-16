
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% battery
xyz_cg_dist(1,:)    = [ 0.0065, 0, -0.0195 ];
m(1)                = 0.201;
xyz_dim(1,:)        = [ 0.081, 0.035, 0.038 ];

% motor front left
xyz_cg_dist(2,:)    = [ 0.0795, -0.099, 0.019 ];
m(2)                = 0.018;
xyz_dim(2,:)        = [ 0.022, 0.022, 0.01 ];

% motor front right
xyz_cg_dist(3,:)    = [ 0.0795, 0.099, 0.019 ];
m(3)                = 0.018;
xyz_dim(3,:)        = [ 0.022, 0.022, 0.01 ];

% motor back right
xyz_cg_dist(4,:)    = [ -0.0795, 0.099, 0.019 ];
m(4)                = 0.018;
xyz_dim(4,:)        = [ 0.022, 0.022, 0.01 ];

% motor back left
xyz_cg_dist(5,:)    = [ -0.0795, -0.099, 0.019 ];
m(5)                = 0.018;
xyz_dim(5,:)        = [ 0.022, 0.022, 0.01 ];

% frame top plate
xyz_cg_dist(6,:)    = [ -0.0125, 0, 0.001 ];
m(6)                = 0.007+0.001;
xyz_dim(6,:)        = [ 0.115, 0.026, 0.002 ];

% frame bottom plate back
xyz_cg_dist(7,:)    = [ -0.024, 0, 0.023 ];
m(7)                = 0.006+0.001;
xyz_dim(7,:)        = [ 0.09, 0.027, 0.002 ];

% frame bottom plate front
xyz_cg_dist(8,:)    = [ 0.0125, 0, 0.029 ];
m(8)                = 0.0056+0.001;
xyz_dim(8,:)        =  [ 0.07, 0.28, 0.002 ];

% arm front left
xyz_cg_dist(9,:)    = [ 0.0398, -0.0495, 0.026 ];
m(9)                = 0.012;
xyz_dim(9,:)        = [ 0.09, 0.12, 0.004 ];

% arm front right
xyz_cg_dist(10,:)    = [ 0.0398, 0.0495, 0.026 ];
m(10)                = 0.012;
xyz_dim(10,:)        = [ 0.09, 0.12, 0.004 ];

% arm back right
xyz_cg_dist(11,:)    = [ -0.0398, 0.0495, 0.026 ];
m(11)                = 0.012;
xyz_dim(11,:)        = [ 0.09, 0.12, 0.004 ];

% arm back left
xyz_cg_dist(12,:)    = [ -0.0398, -0.0495, 0.026 ];
m(12)                = 0.012;
xyz_dim(12,:)        = [ 0.09, 0.12, 0.004 ];

% Pixhawk Mini
xyz_cg_dist(13,:)    = [ -0.0055, 0, 0.0085 ];
m(13)                = 0.010+0.002;
xyz_dim(13,:)        = [ 0.041, 0.036, 0.005 ];

% ESC
xyz_cg_dist(14,:)    = [ -0.0055, 0, 0.0165 ];
m(14)                = 0.011+0.002;
xyz_dim(14,:)        = [ 0.041, 0.036, 0.005 ];

% telemetry
xyz_cg_dist(15,:)   = [ -0.0775, 0, -0.0125 ];
m(15)               = 0.012;
xyz_dim(15,:)       = [ 0.075, 0.01, 0.01 ];

% GPS
xyz_cg_dist(16,:)   = [ -0.01, 0, -0.037 ];
m(16)               = 0.011;
xyz_dim(16,:)       = [ 0.025, 0.025, 0.006 ];

% Receiver + Capacitor
xyz_cg_dist(17,:)   = [ -0.05, 0, 0.015 ];
m(17)               = 0.004;
xyz_dim(17,:)       = [ 0.015, 0.01, 0.01 ];

% BEC
xyz_cg_dist(18,:)   = [ -0.0, 0.007, 0.003 ];
m(18)               = 0.001;
xyz_dim(18,:)       = [ 0.01, 0.01, 0.003 ];



%  compute the cg
xyz_cg = centerOfGravity(xyz_cg_dist,m)

% compute the moment of inertia
I = momentOfInertia(xyz_cg_dist,m,xyz_dim)

% total mass
sum(m)
