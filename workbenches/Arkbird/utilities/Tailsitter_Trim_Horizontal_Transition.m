% With this script you can compute multiple trim points for the tailsitter
% for horizontal steady flight depending on given groundspeeds.

% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% set input parameters
% init tailsitter parameters
init_Arkbird_INDI_simple;
% define ground speed vector (for each element a trim point will be
% computed)
groundspeed_vector = [0];

%% start trimming computation

[x,u,op] = tailsitterTrimHorizontal(0);

len_gs = length(groundspeed_vector);
x_map = repmat(x,len_gs,1);
u_map = repmat(u,len_gs,1);
op_map = repmat(op,len_gs,1);
y.EulerAngles = zeros(3,1);
for i = 1:len_gs
    [x_map(i),u_map(i),op_map(i)] = tailsitterTrimHorizontal(groundspeed_vector(i));
end

% TailsitterSimModel_Trim([], [], [], 'term')

%% compute outputs

trim_map.V_Kb = [x_map.velocity];
trim_map.quaternion = [x_map.quaternion];
trim_map.EulerAngles = zeros(size(trim_map.V_Kb));
trim_map.V_Kg = zeros(size(trim_map.V_Kb));
for i = 1:size(trim_map.V_Kb,2)
    trim_map.EulerAngles(:,i) = quat2Euler(trim_map.quaternion(:,i));
    trim_map.V_Kg(:,i) = quat2Dcm(trim_map.quaternion(:,i))'*trim_map.V_Kb(:,i);
end
trim_map.groundspeed = vecnorm(trim_map.V_Kg(1:2,:),2,1);
trim_map.u_eta = [u_map.cmd_eta];
trim_map.u_omega = [u_map.cmd_motors];
trim_map.elevon_deflection = [x_map.elevon_deflection];


%% plot results

n = 2;
m = 2;
subplot(m,n,1)
plot(trim_map.groundspeed,rad2deg(trim_map.EulerAngles(2,:)),'-x')
xlabel('groundspeed, m/s')
ylabel('pitch, °')
grid on
title('Pitch')

subplot(m,n,2)
plot(trim_map.groundspeed,rad2deg(trim_map.elevon_deflection),'-x')
xlabel('groundspeed, m/s')
ylabel('elevon deflection, °')
grid on
title('Elevons')

subplot(m,n,3)
plot(trim_map.groundspeed,trim_map.u_omega,'-x')
xlabel('groundspeed, m/s')
ylabel('motor PWM')
grid on
title('Motors')
