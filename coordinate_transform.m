function [local,world] = coordinate_transform(x_vec,y_vec,x,y,z)
%y_p is y prime which is vector of y coordinate axis after rotation beta
%about the x axis
%x_p is rotation alpha about arbitary axis y_p
world = [x;y;z];
z_vec=cross(x_vec,y_vec);
local=[x_vec,y_vec,z_vec]\[x;y;z];

