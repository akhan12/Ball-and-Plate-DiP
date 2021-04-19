function [mod_sec_edit,reset_fall]  = fcn(mod_sec,math_co,bounce_co,bounce_co_world,bounce_co_vel,x_vec,y_vec)
%mod_sec if 0 output is bounce_co
%if anything else math_co
%this requires bounce_co and math_co for vrml model, note doesn't require
%the negative
z_vec = cross(x_vec,y_vec);
math_co_world = [x_vec,y_vec,z_vec]*math_co;
plate_dim_x = 35;
plate_dim_y = 35;
global gravity;
global gravity_fall;
global initial_velocity_fall;
global initial_position_fall;
         initial_velocity_fall = bounce_co_vel';
         initial_position_fall = bounce_co_world;
reset_fall = 0;
if mod_sec == 1
    nates = bounce_co;
       mod_sec_edit = 1;
    if nates(2)<5&&(abs(nates(1)))>plate_dim_y||(abs(nates(3)))>plate_dim_y
        mod_sec_edit = 3;
        gravity = 0;
        
        gravity_fall = -9.8;
         initial_velocity_fall = bounce_co_vel';
         initial_position_fall = bounce_co_world;
         reset_fall = 1;
        
    end
elseif mod_sec == 0
    nates = math_co;
     mod_sec_edit = 0;
    if (abs(nates(1))) > plate_dim_x || (abs(nates(3))) > plate_dim_y
        mod_sec_edit = 3; 
        gravity = 0;
        reset_fall = 1;
        gravity_fall = -9.8;
        initial_velocity_fall = [0;0;0];
        initial_position_fall = math_co_world;
    end
end