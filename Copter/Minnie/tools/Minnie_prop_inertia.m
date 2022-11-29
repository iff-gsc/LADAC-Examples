
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

%% linear mass distribution
I = 0;
m_total = 0;
N = 100;
l = 0.01;
h0 = 0.077;
h = h0/N;
rho = 1.22e3;
for i=1:N
    
    b = 0.0025 - 0.0021*i/N;
    V = l*b*h;
    m = rho*V;
    m_total = m_total + m;
    hx = h0*i/N;
    I = I + m*hx^2;
    
end

I = I*3
m_total = m_total*3

%% hyperbolic mass distribution (like Kegel)
R = 0.0037;
h = 0.078;
m = 0.0041;
I = m/20*(3*R^2+2*h^2)

%% constant mass distribution
m = 0.0041;
l = 2*0.077;
I = 1/12*m*l^2

