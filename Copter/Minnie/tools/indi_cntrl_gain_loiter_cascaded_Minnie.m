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
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% set the "maximum allowable deviations" ([1], p. 406f) of the...
% ...states
e_max = [];
e_max(1) = 1.8; % x_max
e_max(2) = 1.8; % y_max
e_max(3) = 2.8; % x_dt_max
e_max(4) = 2.8; % y_dt_max
e_max(5) = 8; % x_dt2_max
e_max(6) = 8; % y_dt2_max
e_max(7) = 40; % x_dt3_max
e_max(8) = 40; % y_dt3_max
% ...inputs
Delta_nu_max = [];
Delta_nu_max(1) = 10; % nu_x_dt2_max
Delta_nu_max(2) = 10; % nu_y_dt2_max

% define attitude second order reference model parameters
Phi_omega   = 9.5;
Phi_D       = 1;
Theta_omega = 9.5;
Theta_D     = 1;

% create weighting matrices from the "maximum allowable deviations"
Q = diag( 1./(e_max.^2) );
R = diag( 1./(Delta_nu_max.^2) );

% compute control gain
K = indiCntrlGainLoiterCascaded( Q, R, Theta_omega, Theta_D, Phi_omega, Phi_D );
