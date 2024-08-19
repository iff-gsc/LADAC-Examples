function wing_wet = getWetWing( tailsitter )

% Disclaimer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

wing_dry = tailsitter.aero.wing;

wing_wet = wing_dry;

config = tailsitter.config;

y_motor = config.propPos_c(2,:);

c_in = wing_dry.geometry.c/((1+wing_dry.geometry.z)/2);
chord_motor = c_in * ( 1- y_motor(2)/(wing_dry.geometry.b/2)*(1-wing_dry.geometry.z) );

prop_name_split = strsplit(tailsitter.prop.name,'x');
prop_diameter = 0.0254 * str2double(prop_name_split{1});

% Calculate diameter of slipstream behind propeller based on v_i_gain
v_i_gain = tailsitter.aero.v_i_gain;
slipstream_diameter = prop_diameter * sqrt( 1/v_i_gain );

wing_wet.geometry.S = 2 * slipstream_diameter * chord_motor;
wing_wet.flap.eta_0 = slipstream_diameter / (wing_dry.geometry.b/2);
% wing_wet.flap.x = wing_dry.flap.x * 1.1;

wing_wet = simpleWingSetFlapEffectiveness( wing_wet );

wing_wet.xyz_cntrl_pt_wing(2,:) = y_motor;
wing_wet.xyz_cntrl_pt_wing(1,:) = - y_motor(2)*sin(wing_dry.geometry.phi) - chord_motor/2;

wing_wet.xyz_wing_np(2,:) = y_motor;


end