function I = momentOfInertia( xyz_cg_dist, m, xyz_dim ) %#codegen
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
%   I                   moment of inertia (3x3) matrix of the body in body
%                       frame, in kg.m^2
% 

% Disclamer:
%   SPDX-License-Identifier: GPL-3.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

I = zeros( 3, 3);
for i = 1:length(xyz_cg_dist(:,1))
    a = [ 0, -xyz_cg_dist(i,3), xyz_cg_dist(i,2);
            xyz_cg_dist(i,3), 0 , -xyz_cg_dist(i,1)
            -xyz_cg_dist(i,2), xyz_cg_dist(i,1), 0 ];
    I = I + ...
        1/12 * m(i) * diag( xyz_dim(i,[2,3,1]).^2 + xyz_dim(i,[3,1,2]).^2 ) + ...
        m(i)*a'*a;
%         m(i) * ( xyz_cg_dist(i,:)*xyz_cg_dist(i,:)'*eye(3) - xyz_cg_dist(i,:)'.*xyz_cg_dist(i,:) );
%             m(i) * xyz_cg_dist(i,:)'*xyz_cg_dist(i,:);
end