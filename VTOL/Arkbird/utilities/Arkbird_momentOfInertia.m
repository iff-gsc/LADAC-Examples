
% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% battery
xyz_cg_dist(1,:)    = [ - 0.05, 0, 0 ];
m(1)                = 0.44;
xyz_dim(1,:)        = [ 0.145, 0.05, 0.03 ];

% motor left (m_motor = 32g + m_prop)
xyz_cg_dist(2,:)    = [ 0.1, -0.165, 0 ];
m(2)                = 0.035;
xyz_dim(2,:)        = [ 0.02, 0.03, 0.03 ];

% motor right
xyz_cg_dist(3,:)    = [ 0.1, 0.165, 0 ];
m(3)                = 0.035;
xyz_dim(3,:)        = [ 0.02, 0.03, 0.03 ];

% pylon left
xyz_cg_dist(4,:)    = [ 0.05, -0.165, 0 ];
m(4)                = 0.035;
xyz_dim(4,:)        = [ 0.08, 0.04, 0.04 ];

% pylon right
xyz_cg_dist(5,:)    = [ 0.05, 0.165, 0 ];
m(5)                = 0.035;
xyz_dim(5,:)        = [ 0.08, 0.04, 0.04 ];

% fuselage main
xyz_cg_dist(6,:)    = [ 0, 0, 0.01 ];
m(6)                = 0.29;
xyz_dim(6,:)        = [ 0.45, 0.08, 0.05 ];

% fuselage front
xyz_cg_dist(7,:)    = [ 0.16, 0, 0.02 ];
m(7)                = 0.03;
xyz_dim(7,:)        = [ 0.1, 0.05, 0.02 ];

% wing left
xyz_cg_dist(8,:)    = [ -0.09, -0.215, 0 ];
m(8)                = 0.05;
xyz_dim(8,:)        =  [ 0.24, 0.43, 0.02 ];

% wing right
xyz_cg_dist(9,:)    = [ -0.09, 0.215, 0 ];
m(9)                = 0.05;
xyz_dim(9,:)        = [ 0.24, 0.43, 0.02 ];

% winglet left
xyz_cg_dist(10,:)    = [ -0.17, -0.43, 0 ];
m(10)                = 0.015;
xyz_dim(10,:)        = [ 0.2, 0.01, 0.15 ];

% winglet right
xyz_cg_dist(11,:)   = [ -0.17, 0.43, 0 ];
m(11)               = 0.015;
xyz_dim(11,:)       = [ 0.2, 0.01, 0.15 ];

% cables / servos left
xyz_cg_dist(12,:)   = [ -0.05, -0.15, 0 ];
m(12)               = 0.04;
xyz_dim(12,:)       = [ 0.15, 0.1, 0.03 ];

% cables / servos right
xyz_cg_dist(13,:)   = [ -0.05, 0.15, 0 ];
m(13)               = 0.04;
xyz_dim(13,:)       = [ 0.15, 0.1, 0.03 ];



%  compute the cg
xyz_cg = centerOfGravity(xyz_cg_dist,m)

% compute the moment of inertia
I = momentOfInertia(xyz_cg_dist,m,xyz_dim)

% total mass
sum(m)
