function [ ny_du_red, ny_du_dt ] = indiCntrlEffectiveness( A, B, C, D, idx_mot )
% indiCntrlEffectiveness computes two control effectiveness matrices for a
% system including actuator dynamics.
%   The first control effectiveness matrix is based on a reduced-order 
%   model where the actuator dynamics are negled.
%   The second control effectiveness matrix is with respect to the time
%   derivative of the control input.
%   The necessity of both matrices is pointed out in [1].
% 
% Inputs:
%   A           system matrix including actuator dynamics (nxn)
%   B           input matrix (nxm)
%   C           output matrix (pxn) where the pseudo-control signal is 
%               defined as the output 
%   D           feedthrough matrix (pxm)
%   idx_mot     index of the motor states inside the state vector (1xN
%               vector for N motor states)
% 
% Outputs:
%   ny_du_red   control effectiveness with respect to the control input
%               assuming the reduced-order model without actuator dynamics
%               (partial derivative @ny/@u)
%   ny_du_dt    control effectiveness with respect to the time derivative
%               of the control input (partial derivative @ny/@(@u/@t))
% 
% Literature:
%   [1] Smeur, E.J., Qiping, C., and de Croon, G.C. (2016). Adaptive
%       Incremental Nonlinear Dynamic Inversion for Attitude Control of
%       Micro Air Vehicles. Journal of Guidance, Control, and Dynamics,
%       39(3), 450-461.
% 

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% Nomenclature:
%   omega_mot 	angular velocity of motors
%   u           motor command (0~1)
%   t           time
%   @           denotes a partial derivative (cursive d, del)

% compute reduced-order state-space model by neglecting the actuator states
% D = zeros(size(C,1),size(B,2));
elim = false(size(A,1),1);
elim(idx_mot) = true;
[ ~, ~, ~, D_red, ~ ] = modredEmb2(  A, B, C, D, elim );

% partial derivative @(omega_mot/@t)/@omega_mot (-1/T_mot; motor time
% constant)
omega_mot_dt_domega = A(idx_mot,idx_mot);

% control effectiveness of reduced model (without actuator dynamics)
CB_red = D_red;
% control effectiveness including actuator dynamics (there can be a direct
% relation between control input and pseudo-control output, else this is
% zeros)
% CB = C*B;
CB = D;

% This is T_s*G_2 in [1] with a small difference:
% In [1] the angular velocity of the rotors is used as the control input.
% Here, the motor command (0~1) is used as control input instead.
% Partial derivative @ny/@(@u/@t)
% = @ny/@u * @omega_mot/@(@omega_mot/@t)
ny_du_dt = CB * -pinv(omega_mot_dt_domega);
% This is G_1 in [1] with a small difference:
% In [1] the angular velocity of the rotors is used as the control input.
% Here, the motor command (0~1) is used as control input instead.
% Partial derivative @ny/@u (for a reduced (red) order system - actuator
% dynamics removed)
ny_du_red = CB_red;

end