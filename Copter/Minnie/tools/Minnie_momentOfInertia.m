
% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

xyz_cg_dist = [];
m = [];
xyz_dim = [];

% battery (203g including cables)
xyz_cg_dist(1,:)    = [ 0.0065, 0, -0.0195 ];
m(1)                = 0.195;
xyz_dim(1,:)        = [ 0.081, 0.035, 0.038 ];

% battery cables
xyz_cg_dist(end+1,:)    = [ -0.047, 0, -0.02 ];
m(end+1)                = 0.008;
xyz_dim(end+1,:)        = [ 0.035, 0.02, 0.035 ];

% battery strap
xyz_cg_dist(end+1,:)    = [ 0, 0, -0.019 ];
m(end+1)                = 0.0031;
xyz_dim(end+1,:)        = [ 0.01, 0.035, 0.04 ];

% motor (12.5g) + prop (3g) + 4x screws (0.5g): 16g; cardboard: 2.7g
% motor front left (motor + prop-center + screws)
xyz_cg_dist(end+1,:)    = [ 0.0795, -0.099, 0.019 ];
m(end+1)                = 0.0145;
xyz_dim(end+1,:)        = [ 0.022, 0.022, 0.01 ];

% cardboard front left
xyz_cg_dist(end+1,:)    = [ 0.0795, -0.099, 0.053 ];
m(end+1)                = 0.001;
xyz_dim(end+1,:)        = [ 0.05, 0.05, 0.025 ];

% prop blade front left
xyz_cg_dist(end+1,:)    = [ 0.0795, -0.099, 0.014 ];
m(end+1)                = 0.0015;
xyz_dim(end+1,:)        = [ 0.08, 0.08, 0.0005 ];

% motor front right
xyz_cg_dist(end+1,:)    = [ 0.0795, 0.099, 0.019 ];
m(end+1)                = 0.0145;
xyz_dim(end+1,:)        = [ 0.022, 0.022, 0.01 ];

% cardboard front right
xyz_cg_dist(end+1,:)    = [ 0.0795, 0.099, 0.053 ];
m(end+1)                = 0.001;
xyz_dim(end+1,:)        = [ 0.05, 0.05, 0.025 ];

% prop blade front right
xyz_cg_dist(end+1,:)    = [ 0.0795, 0.099, 0.014 ];
m(end+1)                = 0.0015;
xyz_dim(end+1,:)        = [ 0.08, 0.08, 0.0005 ];

% motor back right
xyz_cg_dist(end+1,:)    = [ -0.0795, 0.099, 0.019 ];
m(end+1)                = 0.0145;
xyz_dim(end+1,:)        = [ 0.022, 0.022, 0.01 ];

% cardboard back right
xyz_cg_dist(end+1,:)    = [ -0.0795, 0.099, 0.053 ];
m(end+1)                = 0.001;
xyz_dim(end+1,:)        = [ 0.05, 0.05, 0.025 ];

% prop blade back right
xyz_cg_dist(end+1,:)    = [ -0.0795, 0.099, 0.014 ];
m(end+1)                = 0.0015;
xyz_dim(end+1,:)        = [ 0.08, 0.08, 0.0005 ];

% motor back left
xyz_cg_dist(end+1,:)    = [ -0.0795, -0.099, 0.019 ];
m(end+1)                = 0.0145;
xyz_dim(end+1,:)        = [ 0.022, 0.022, 0.01 ];

% cardboard back left
xyz_cg_dist(end+1,:)    = [ -0.0795, -0.099, 0.053 ];
m(end+1)                = 0.001;
xyz_dim(end+1,:)        = [ 0.05, 0.05, 0.025 ];

% prop blade back left
xyz_cg_dist(end+1,:)    = [ -0.0795, -0.099, 0.014 ];
m(end+1)                = 0.0015;
xyz_dim(end+1,:)        = [ 0.08, 0.08, 0.0005 ];

% frame top plate
xyz_cg_dist(end+1,:)    = [ -0.0125, 0, 0.001 ];
m(end+1)                = 0.008 + 0.002;
xyz_dim(end+1,:)        = [ 0.115, 0.026, 0.002 ];

% frame bottom plate back
xyz_cg_dist(end+1,:)    = [ -0.024, 0, 0.023 ];
m(end+1)                = 0.007;
xyz_dim(end+1,:)        = [ 0.09, 0.027, 0.002 ];

% frame bottom plate front
xyz_cg_dist(end+1,:)    = [ 0.0125, 0, 0.029 ];
m(end+1)                = 0.0057 + 0.002;
xyz_dim(end+1,:)        =  [ 0.07, 0.28, 0.002 ];

% arm front left
xyz_cg_dist(end+1,:)    = [ 0.0398, -0.0495, 0.026 ];
m(end+1)                = 0.012 + 0.002;
xyz_dim(end+1,:)        = [ 0.09, 0.12, 0.004 ];

% arm front right
xyz_cg_dist(end+1,:)    = [ 0.0398, 0.0495, 0.026 ];
m(end+1)                = 0.012 + 0.002;
xyz_dim(end+1,:)        = [ 0.09, 0.12, 0.004 ];

% arm back right
xyz_cg_dist(11,:)    = [ -0.0398, 0.0495, 0.026 ];
m(11)                = 0.012 + 0.002;
xyz_dim(11,:)        = [ 0.09, 0.12, 0.004 ];

% arm back left
xyz_cg_dist(end+1,:)    = [ -0.0398, -0.0495, 0.026 ];
m(end+1)                = 0.012 + 0.002;
xyz_dim(end+1,:)        = [ 0.09, 0.12, 0.004 ];

% Matek H743 Slim
xyz_cg_dist(end+1,:)    = [ -0.0055, 0, 0.0085 ];
m(end+1)                = 0.012;
xyz_dim(end+1,:)        = [ 0.041, 0.036, 0.005 ];

% ESC
xyz_cg_dist(end+1,:)    = [ -0.0055, 0, 0.0165 ];
m(end+1)                = 0.013;
xyz_dim(end+1,:)        = [ 0.041, 0.036, 0.005 ];

% telemetry
xyz_cg_dist(end+1,:)   = [ -0.0775, 0, -0.0125 ];
m(end+1)               = 0.012;
xyz_dim(end+1,:)       = [ 0.09, 0.01, 0.01 ];

% GPS
xyz_cg_dist(end+1,:)   = [ -0.01, 0, -0.037 ];
m(end+1)               = 0.0114;
xyz_dim(end+1,:)       = [ 0.025, 0.025, 0.006 ];

% Receiver + Capacitor
xyz_cg_dist(end+1,:)   = [ -0.05, 0, 0.015 ];
m(end+1)               = 0.004;
xyz_dim(end+1,:)       = [ 0.015, 0.01, 0.01 ];




%  compute the cg
xyz_cg = centerOfGravity(xyz_cg_dist,m)

% compute the moment of inertia
I = momentOfInertia(xyz_cg_dist,m,xyz_dim)

% total mass
sum(m)
