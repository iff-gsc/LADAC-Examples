function K = indiCntrlGainLoiterCascaded( Q, R, omega_pitch, damp_pitch, omega_roll, damp_roll )
%   indiCntrlGainLoiterCascaded returns an optimal output feedback gain for
%   a multicopter with feedback linearization (or NDI/INDI) regarding the
%   position in the plane parallel to flat earth (x,y). The output of this
%   controller are accelerations in the same frame (nu_x_dt2, nu_y_dt2).
%   These accelerations must be transformed into a desired attitude by the
%   (I)NDI and then given as desired values to an attitude controller.
%   We consider second-order attitude dynamics. Thus, the state
%   vector contains the second and third derivative of the position. As it
%   is not obvious how to control the third derivative of the position, an
%   output feedback gain is computed instead of a full state feedback gain.
%   Any actuator dynamics are neglected.
%   Therefore, the following state vector, output vector and pseudo-control
%   input vector are considered:
% 
%   state vector:
%   x, y, x_dt, y_dt, x_dt2, y_dt2, x_dt3, y_dt3
% 
%   output vector:
%   x, y, x_dt, y_dt, x_dt2, y_dt2
% 
%   pseudo-control input vector:
%   nu_x_dt2, nu_y_dt2
% 
%   For the (iterative) design or the optimal state feedback gain, you may
%   want to adjust the weightings of the LQR cost function. Therefore, you
%   should adjust the values x_max(i) and u_max(i) similar to [1], p. 406f.
% 
% Inputs:
%   Q               LQR weighting matrix for the outputs (6x6 matrix)
%   R               LQR weighting matrix for the inputs (2x2 matrix)
%   omega_pitch     angular frequency of the second order pitch dynamics
%                   (scalar), in rad/s
%   damp_pitch      damping ratio of the second order pitch dynamics
%                   (scalar), dimensionless
%   omega_roll      angular frequency of the second order roll dynamics
%                   (scalar), in rad/s
%   damp_roll       damping ratio of the second order roll dynamics
%                   (scalar), dimensionless
% 
% Outputs:
%   K               optimal output feedback gain matrix (2x6 matrix)
% 
% Literature:
%   [1] Stevens, B. L. et al. (2016): Aircraft Control and Simulation.
%       Dynamics, Control Design, and Autonomous Systems. 3rd ed. Wiley.
% 

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% create perfectly transformed state space model with PT2 reference model
% of the attitude control loop
A = [ ...
    0, 0, 1, 0, 0, 0, 0, 0; ...
    0, 0, 0, 1, 0, 0, 0, 0; ...
    0, 0, 0, 0, 1, 0, 0, 0; ...
    0, 0, 0, 0, 0, 1, 0, 0; ...
    0, 0, 0, 0, 0, 0, 1, 0; ...
    0, 0, 0, 0, 0, 0, 0, 1; ...
    zeros(2,4), diag( -[ omega_pitch, omega_roll ].^2 ), -2*diag( [ damp_pitch * omega_pitch, damp_roll * omega_roll ] ) ...
    ];
B = [ ...
    0, 0; ...
    0, 0; ...
    0, 0; ...
    0, 0; ...
    0, 0; ...
    0, 0; ...
    omega_pitch.^2, 0; ...
    0, omega_roll.^2 ...
    ];
C = [ ...
    1, 0, 0, 0, 0, 0, 0, 0; ...
    0, 1, 0, 0, 0, 0, 0, 0; ...
    0, 0, 1, 0, 0, 0, 0, 0; ...
    0, 0, 0, 1, 0, 0, 0, 0; ...
    0, 0, 0, 0, 1, 0, 0, 0; ...
    0, 0, 0, 0, 0, 1, 0, 0 ...
    ];

% compute LQR output feedback
K = lqrY(A,B,C,Q,R,0);

% plot eigenvalues
figure
set(0,'DefaultLegendAutoUpdate','off')
plot(complex(eig(A)),'rx')
hold on
plot(complex(eig(A-B*K*C)),'bx')
legend('open loop','closed loop')
axis equal
sgrid
xlabel('Re')
ylabel('Im')

% plot step response
Bp = sum(B,2);
Cp = [ eye(2), zeros(2,6) ];
D = zeros(2,1);
sys = ss(A-B*K*C,Bp,Cp,D);
sys.OutputName = {'x','y'};
figure
step(sys)

end
