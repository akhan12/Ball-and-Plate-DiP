function [A,B,C,BP_ss,rnk ] = BP_linear( m,r )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
g = -9.8;
J=2*m*r*r/5;
coeff_alpha= -m*(g)/((J/r*r)+m);

A = [0 1;0 0];
B = [0;coeff_alpha];
C = [1 0];
D = 0;
BP_ss = ss(A,B,C,D);
rnk = rank(ctrb(BP_ss));

end

