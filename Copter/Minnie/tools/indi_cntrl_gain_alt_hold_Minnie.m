% ** Design an altitude hold feedback gains for (I)NDI with LQR **

% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% set the "maximum allowable deviations" ([1], p. 406f) of the...
% ...states
e_max = [];
e_max(1) = 0.1; % max h1, dimensionless
e_max(2) = 0.1; % max h2, dimensionless
e_max(3) = 0.1; % max psi, in rad
e_max(4) = 0.1; % max z, in m
e_max(5) = 0.7; % max h1_dt
e_max(6) = 0.7; % max h2_dt
e_max(7) = 0.5; % max psi_dt
e_max(8) = 0.2; % max z_dt
e_max(9) = 40; % max h1_dt2
e_max(10) = 40; % max h2_dt2
e_max(11) = 20; % max psi_dt2
e_max(12) = 40; % max z_dt2
% ...inputs
Delta_nu_max = [];
Delta_nu_max(1) = 20; % max nu_h1_dt2
Delta_nu_max(2) = 20; % max nu_h2_dt2
Delta_nu_max(3) = 5; % max nu_psi_dt2
Delta_nu_max(4) = 5; % max nu_z_dt2

% define neglected actuator dynamics
% time constant
T = 0.032;

% create weighting matrices from the "maximum allowable deviations"
Q = diag( 1./(e_max.^2) );
R = diag( 1./(Delta_nu_max.^2) );

% compute control gain (in matrix form)
K = zeros( length(Delta_nu_max), length(e_max) );
for i = 1:length(Delta_nu_max)
    K(i,i:4:end) = ndiFeedbackGainLqr( e_max(i:4:end), Delta_nu_max(i), T );
end

K_atti = K(1:3,[1:3,5:7,9:11]);
K_alt = K(4,[4,8,12]);
