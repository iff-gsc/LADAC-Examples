function xyz_cg = centerOfGravity( xyz_cg_dist, m ) %#codegen
% momentOfInertia computes the moment of inertia matrix of a body depending
%   on discretized elements of the body.
% 
% Inputs:
%   xyz_cg_dist         distance of element cg of the body cg in body frame
%                       (nx3) matrix, in m
%   m                   mass of the element (nx1) vector, in kg
%   xyz_dim             dimension of the element in body frame (nx3)
%                       matrix, in m
% 
% Outputs:
%   xyz_cg              center of gravity (3x1) vector, in m
% 

% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

m_total = sum( m );

xyz_cg = sum( m'.*xyz_cg_dist/m_total, 1 )';

end