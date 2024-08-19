function cntrl_effect = indiCopterCntrlEffect( filename )
% indiCopterCntrlEffect computes the control effectiveness matrices for a 
%   specified quadcopter for hover. 
%   With this function you can compute two control effectiveness matrices
%   for a multicopter including actuator dynamics.
%   The first control effectiveness matrix is based on a reduced-order
%   model where the actuator dynamics are negled.
%   The second control effectiveness matrix is with respect to the time
%   derivative of the control input.
%   The necessity of both matrices is pointed out in [1].
% 
% Inputs:
%   filename            name of a quadcopter parameters file (e.g. 
%                       'copter_params_default')
% 
% Outputs:
%   cntrl_effect        struct containing the two control effectiveness
%                       matrices and the trim values of the motor commands
% 
% Literature:
%   [1] Smeur, E.J., Qiping, C., and de Croon, G.C. (2016). Adaptive
%       Incremental Nonlinear Dynamic Inversion for Attitude Control of
%       Micro Air Vehicles. Journal of Guidance, Control, and Dynamics,
%       39(3), 450-461.
%   [2] Sun, S., Baert, M., Van Schijndel, B. S., & De Visser, C. (2020). 
%       Upset Recovery Control for Quadrotors Subjected to a Complete Rotor
%       Failure from Large Initial Disturbances. In 2020 IEEE International
%       Conference on Robotics and Automation (ICRA) (pp. 4273-4279). IEEE.
% 

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

% load quadcopter struct
copter = copterLoadParams(filename);

% get operating point op
[x_trim,u_trim,op] = trimSteady( 'QuadcopterSimModel_Trim', ...
    [0;0;0], [true;true;true], [0;0;0],[false;false;true] );

% get linear state-space model at operating point op
sys = linearize( 'QuadcopterSimModel_Trim',op );

% specify the indices of the pseudo-control output within the output vector
% (pseudo-control outputs must be defined as outputs in the Simulink model)
idx_ny = [10:12,15];

% specify the indices of the actuator states within the state vector
idx_mot = 1:4;

% get control effectiveness matrices 
[ ny_du_red, ny_du_dt ] = indiCntrlEffectiveness( ...
    sys.A, sys.B, sys.C(idx_ny,:),sys.D(idx_ny,:), idx_mot );

% transform to reduced attitude as used in [2]
ny_du_red(1:2,:) = ny_du_red([2,1],:).*[-1;1];

% assign results to struct
cntrl_effect.ny_du_red = ny_du_red;
cntrl_effect.ny_du_dt = ny_du_dt;
cntrl_effect.u_trim = u_trim.cmd;

end
