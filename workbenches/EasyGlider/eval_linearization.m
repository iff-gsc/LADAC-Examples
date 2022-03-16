
% Disclamer:
%   SPDX-License-Identifier: GPL-2.0-only
% 
%   Copyright (C) 2020-2022 Yannic Beyer
%   Copyright (C) 2022 TU Braunschweig, Institute of Flight Guidance
% *************************************************************************

[eig_vec_mat,eig_val_mat] = eig(linsys1.A);

X = categorical({'mot. speed','u','v','w','q1','q2','q3','q4','p','q','r','pos'});
X = reordercats(X,{'mot. speed','u','v','w','q1','q2','q3','q4','p','q','r','pos'});

index = 3;

figure(1)
bar(X,real(eig_vec_mat(:,index)))

eig_value = eig_val_mat(index,index);

 omega_0 = abs(eig_value);
 f0 = omega_0 / (2*pi);
 D = real(-eig_value) / omega_0;
 tau = 1 / abs(eig_value);

if D < 0.99
    title(['Frequenz f= ',num2str(f0),' Hz; D=',num2str(D),])
else
    title(['Zeitkonstante tau = ',num2str(tau),' s'])    
end

%%

Ix = 0.0712;
rho = 1.225;
b = 1.815;
s = b/2;
S = 1.815*0.185;
Lambda = b^2/S;
V0 = 14;


%clp = 1/4*pi*Lambda/(sqrt((pi*Lambda/(2*pi))^2+4)+2);
clp = -1/4 * (pi*Lambda) / (sqrt((Lambda^2 / 4) + 4) + 2)
T_R = Ix / (rho/2 * V0 * S * (b/2)^2 * clp)
