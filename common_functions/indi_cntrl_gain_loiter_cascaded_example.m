% ** Design a cascaded position controller for (I)NDI with LQR **
% 
%   With this script you can compute an optimal output feedback gain for a
%   multicopter with feedback linearization (or NDI/INDI) regarding the
%   Position in the plane parallel to flat earth (x,y).
%   This script is an example for how to call the indiCntrlGainLoiterCascaded
%   function.
%   Please have a look at the function documentation for additional
%   information.
% 
% Literature:
%   [1] Stevens, B. L. et al. (2016): Aircraft Control and Simulation.
%       Dynamics, Control Design, and Autonomous Systems. 3rd ed. Wiley.
% 

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% set the "maximum allowable deviations" ([1], p. 406f) of the...
% ...states
x_max = [];
x_max(1) = 3; % x_max
x_max(2) = 3; % y_max
x_max(3) = 2.5; % x_dt_max
x_max(4) = 2.5; % y_dt_max
x_max(5) = 10; % x_dt2_max
x_max(6) = 10; % y_dt2_max
x_max(7) = 20; % x_dt3_max
x_max(8) = 20; % y_dt3_max
% ...inputs
u_max = [];
u_max(1) = 20; % nu_x_dt2_max
u_max(2) = 20; % nu_y_dt2_max

% define attitude second order reference model parameters
Phi_omega   = 9;
Phi_D       = 1;
Theta_omega = 9;
Theta_D     = 1;

% create weighting matrices from the "maximum allowable deviations"
Q = diag( 1./(x_max.^2) );
R = diag( 1./(u_max.^2) );

% compute control gain
K = indiCntrlGainLoiterCascaded( Q, R, Theta_omega, Theta_D, Phi_omega, Phi_D );

