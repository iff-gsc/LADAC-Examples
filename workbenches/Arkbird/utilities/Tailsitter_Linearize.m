
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% trim (get op objects)

Tailsitter_Trim_Horizontal_Transition;

%% Start linearization loop

n_trimpoints = length(op_map);

mdl = 'TailsitterSimModel_Trim';
sys = linearize(mdl,op_map(1));
sys_array = repmat({sys},n_trimpoints,1);
for i = 1:n_trimpoints
    sys_array{i} = linearize(mdl,op_map(i));
end

%% Reduce order

A = sys_array{1}.A;
B = sys_array{1}.B;
C = sys_array{1}.C;
D = sys_array{1}.D;

% specify the indices of the pseudo-control output within the output vector
% (pseudo-control outputs must be defined as outputs in the Simulink model)
idx_ny = [13:15,18];

idx_act_red = [18,19];
elim = false(19,1);
elim(idx_act_red) = true;
[ A_red, B_red, C_red, D_red, condA_elim ] = modredEmb2( ...
    A, B, C, D, elim );

% specify the indices of the actuator states within the state vector
idx_mot = [14:17];

% get control effectiveness matrices (indiCntrlEffectiveness is currently
% only available in multicopter/functions)
[ ny_du_red, ny_du_dt ] = indiCntrlEffectiveness( ...
    A_red, B_red, C_red(idx_ny,:), D_red(idx_ny,:), idx_mot );

% compensate tilt in hover
ny_du_red = ny_du_red([3,2,1,4],:).*[1;1;-1;1];
ny_du_dt = ny_du_dt([3,2,1,4],:).*[1;1;-1;1];

% transform to reduced attitude
ny_du_red(1:2,:) = ny_du_red([2,1],:).*[-1;1];
ny_du_dt(1:2,:) = ny_du_dt([2,1],:).*[-1;1];

% PWM to 0-1
ny_du_red(:,[1,2]) = ny_du_red(:,[1,2])*800;
ny_du_red(:,[3,4]) = ny_du_red(:,[3,4])*1000;
ny_du_dt(:,[1,2]) = ny_du_dt(:,[1,2])*800;
ny_du_dt(:,[3,4]) = ny_du_dt(:,[3,4])*1000;