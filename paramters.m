T=0.01;
m1 = 0.18;
n1 = 0.078;
l1 = 0.19;
Jn1 = 2.8e-5;
I1 = 0.0089;
c1 = 0.0001;
m2 = 0.1;
n2 = 0.05;
l2 = 0.115;
Jn2 = 2e-6;
I2 = 0.0018;
c2 = 0.002;
g = 9.8;
L = 0.38;

I_theta = I1 +m1*(l1^2)+m2*(L^2)+n2*(L^2)+Jn1;
M1 = m2*l2*L;
M2 = m1*l1+m2*L+n2*L;
I_phi = I2+m2*(l2*l2)+Jn2;
M3=m2*l2;

A2 = [0 1 0 0
     M2*g/I_theta -((c1+c2)/I_theta) 0 0
     0 0 0 1
     0 0 0 0];
 B2 = [0;-M2/I_theta;0;1];
 
 [P ,~,~] = care(A2+1*eye(4),B2,eye(4));
 
%  
%  S2 = (B2')*P;
%  
%  
%  
%  a21 = -(I_phi*M2*g)/(M1^2 - I_phi*I_theta);
% 
% 
% a22 =(I_phi*(c1 + c2))/(M1^2 - I_phi*I_theta) + (M1*c2)/(M1^2 - I_phi*I_theta);
% 
% 
% a23 =(M1*M3*g)/(M1^2 - I_phi*I_theta);
% a24 = - (I_phi*c2)/(M1^2 - I_phi*I_theta) - (M1*c2)/(M1^2 - I_phi*I_theta);
% 
% 
% a41 = (M1*M2*g)/(M1^2 - I_phi*I_theta);
% 
% a42 = - (M1*(c1 + c2))/(M1^2 - I_phi*I_theta) - (I_theta*c2)/(M1^2 - I_phi*I_theta);
% 
% 
% 
% a43 = -(I_theta*M3*g)/(M1^2 - I_phi*I_theta);
% 
% a44 = (I_theta*c2)/(M1^2 - I_phi*I_theta) + (M1*c2)/(M1^2 - I_phi*I_theta);
% 
% 
% b2 = M1*M3-M2*I_phi;
% b2 = b2/a_den;
% 
% b4 = M1*M2-M3*I_theta;
% b4 = b4/a_den;

A3 =[                                          0,                                                                                        1,                                            0,                                                  0, 0, 0
 -(I_phi*M2*g)/(M1^2 - I_phi*I_theta),     (I_phi*(c1 + c2))/(M1^2 - I_phi*I_theta) + (M1*c2)/(M1^2 - I_phi*I_theta),       (M1*M3*g)/(M1^2 - I_phi*I_theta), - (I_phi*c2)/(M1^2 - I_phi*I_theta) - (M1*c2)/(M1^2 - I_phi*I_theta), 0, 0
                                          0,                                                                                        0,                                            0,                                                                              1, 0, 0
     (M1*M2*g)/(M1^2 - I_phi*I_theta), - (M1*(c1 + c2))/(M1^2 - I_phi*I_theta) - (I_theta*c2)/(M1^2 - I_phi*I_theta), -(I_theta*M3*g)/(M1^2 - I_phi*I_theta), (I_theta*c2)/(M1^2 - I_phi*I_theta) + (M1*c2)/(M1^2 - I_phi*I_theta), 0, 0
                                          0,                                                                                        0,                                            0,                                                                              0, 0, 1
                                          0,                                                                                        0,                                            0,                                                                              0, 0, 0];
 
%  B3 = [0;b2;0;b4;0;1];
 
 
  B3 =[                                                          0
     (I_phi*M2 - M1*M3)/(M1^2 - I_phi*I_theta) - (I_phi*(I_phi*M2 - M1*M3))/(M1^2 - I_phi*I_theta)^2 + (M1*(I_theta*M3 - M1*M2))/(M1^2 - I_phi*I_theta)^2
                                                                                                                                                                               0
 (I_theta*M3 - M1*M2)/(M1^2 - I_phi*I_theta) - (I_theta*(I_theta*M3 - M1*M2))/(M1^2 - I_phi*I_theta)^2 + (M1*(I_phi*M2 - M1*M3))/(M1^2 - I_phi*I_theta)^2
                                                                                                                                                                               0
                                                                                                                                                                               1];
 
 
 
 