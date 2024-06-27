
% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

addPathFunray();


xyz_c_dist = [];
m = [];
xyz_dim = [];

% Battery (including cables)
xyz_c_dist(1,:)    = [ -0.235, -0.01, 0.01 ];
m(1)                = 0.350;
xyz_dim(1,:)        = [ 0.16, 0.04, 0.03 ];

% ESC
xyz_c_dist(end+1,:)    = [ -0.245, 0.025, 0 ];
m(end+1)                = 0.063;
xyz_dim(end+1,:)        = [ 0.13, 0.01, 0.05 ];

% Motor
xyz_c_dist(end+1,:)    = [ -0.074, 0, 0 ];
m(end+1)                = 0.200;
xyz_dim(end+1,:)        = [ 0.05, 0.03, 0.03 ];

% Spinner + screws
xyz_c_dist(end+1,:)    = [ -0.03, 0, 0 ];
m(end+1)                = 0.060;
xyz_dim(end+1,:)        = [ 0.05, 0.03, 0.03 ];

% Prop
xyz_c_dist(end+1,:)    = [ -0.03, 0, 0 ];
m(end+1)                = 0.010;
xyz_dim(end+1,:)        = [ 0.01, 0.20, 0.20 ];

% Fuselage spar
xyz_c_dist(end+1,:)    = [ -0.6, 0, 0.029+0.005 ];
m(end+1)                = 0.059;
xyz_dim(end+1,:)        = [ 1.08, 0.01, 0.01 ];

% Fuselage foam
xyz_c_dist(end+1,:)    = [ -0.55, 0, 0 ];
m(end+1)                = 0.210;
xyz_dim(end+1,:)        = [ 1.1, 0.07, 0.08 ];

% Fuselage cockpit window
xyz_c_dist(end+1,:)    = [ -0.21, 0, -0.05 ];
m(end+1)                = 0.041;
xyz_dim(end+1,:)        = [ 0.25, 0.085, 0.06 ];

% Center wing
xyz_c_dist(end+1,:)    = [ -0.46, 0, 0.029-0.05 ];
m(end+1)                = 0.07;
xyz_dim(end+1,:)        = [ 0.1, 0.05, 0.05 ];

% Wing spar left
xyz_c_dist(end+1,:)    = [ -0.445, -0.34, -0.04 ];
m(end+1)                = 0.081;
xyz_dim(end+1,:)        = [ 0.01, 0.82, 0.01 ];

% Wing spar right
xyz_c_dist(end+1,:)    = [ -0.445, 0.34, 0.029-0.07 ];
m(end+1)                = 0.081;
xyz_dim(end+1,:)        = [ 0.01, 0.82, 0.01 ];

% Wing foam left (with LE) (includes a bit of cables)
xyz_c_dist(end+1,:)    = [ -0.46, -0.45, 0.029-0.07 ];
m(end+1)                = 0.185 + 0.010;
xyz_dim(end+1,:)        = [ 0.17, 0.9, 0.02 ];

% Wing foam right (with LE) (includes a bit of cables)
xyz_c_dist(end+1,:)    = [ -0.46, 0.45, 0.029-0.07 ];
m(end+1)                = 0.185 + 0.010;
xyz_dim(end+1,:)        = [ 0.17, 0.9, 0.02 ];

servo_dim               = [ 0.024, 0.028, 0.012 ];
servo_m                 = 0.020 + 0.002; % includes flap attachment weight
% Servo 1
xyz_c_dist(end+1,:)    = [ -0.445-0.041, -0.74, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 2
xyz_c_dist(end+1,:)    = [ -0.445-0.04, -0.58, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 3
xyz_c_dist(end+1,:)    = [ -0.445-0.055, -0.412, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 4
xyz_c_dist(end+1,:)    = [ -0.445-0.065, -0.255, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 5
xyz_c_dist(end+1,:)    = [ -0.445-0.065, 0.255, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 6
xyz_c_dist(end+1,:)    = [ -0.445-0.055, 0.412, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 7
xyz_c_dist(end+1,:)    = [ -0.445-0.04, 0.58, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Servo 8
xyz_c_dist(end+1,:)    = [ -0.445-0.041, 0.74, 0.029-0.07 ];
m(end+1)                = servo_m;
xyz_dim(end+1,:)        = servo_dim;

% Tail servos
xyz_c_dist(end+1,:)    = [ -1.105, 0, -0.03 ];
m(end+1)                = 0.06;
xyz_dim(end+1,:)        = [ 0.04, 0.04, 0.05 ];

% Horizontal tailplane
xyz_c_dist(end+1,:)    = [ -1.12, 0, -0.05 ];
m(end+1)                = 0.065;
xyz_dim(end+1,:)        = [ 0.1, 0.4, 0.01 ];

% Vertical tailplane
xyz_c_dist(end+1,:)    = [ -1.12, 0 -0.12 ];
m(end+1)                = 0.03;
xyz_dim(end+1,:)        = [ 0.15, 0.01, 0.25 ];

% Matek H743 Wing plus cables
xyz_c_dist(end+1,:)    = [ -0.39, 0, 0.01 ];
m(end+1)                = 0.080;
xyz_dim(end+1,:)        = [ 0.06, 0.04, 0.04 ];

% Telemetry
xyz_c_dist(end+1,:)   = [ -0.48, 0, 0.02 ];
m(end+1)               = 0.012;
xyz_dim(end+1,:)       = [ 0.09, 0.01, 0.01 ];

% GPS
xyz_c_dist(end+1,:)   = [ -0.38, 0, -0.08 ];
m(end+1)               = 0.011;
xyz_dim(end+1,:)       = [ 0.025, 0.025, 0.006 ];

% Airspeed sensor
xyz_c_dist(end+1,:)    = [ -0.39, 0.39, -0.06 ];
m(end+1)                = 0.020;
xyz_dim(end+1,:)        = [ 0.08, 0.03, 0.03 ];

% Cam
xyz_c_dist(end+1,:)    = [ -1.08, 0, -0.185 ];
m(end+1)                = 0.008;
xyz_dim(end+1,:)        = [ 0.02, 0.015, 0.02 ];

% Cam VTX
xyz_c_dist(end+1,:)    = [ -0.80, -0.02, 0.01 ];
m(end+1)                = 0.028;
xyz_dim(end+1,:)        = [ 0.03, 0.015, 0.03 ];

% Trim mass
xyz_c_dist(end+1,:)    = [ -0.155, 0, 0.01 ];
m(end+1)                = 0.014;
xyz_dim(end+1,:)        = [ 0.015, 0.015, 0.015 ];


%  Compute the cg
xyz_cg = centerOfGravity(xyz_c_dist,m)

% Compute the moment of inertia
I = momentOfInertia(xyz_c_dist-xyz_cg',m,xyz_dim)

% Total mass
sum(m)

momentOfInertiaPlot(xyz_c_dist,xyz_dim,m,'Alpha','Density')
