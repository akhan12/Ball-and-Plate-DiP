function  vrml_animate( i,balltrans,T,w,shaftx,shafty,y_rot,x_rot)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    w.ball_trans.translation = balltrans.data(i,:);
    w.shaft_x.translation = shaftx.data(i,:);
    w.shaft_y.translation = shafty.data(i,:);
    w.plate_test_y.rotation = y_rot.data(i,:);
    w.plate_test_x.rotation = x_rot.data(i,:);
    pause(T);

% vrml_animate(balltranslation,0.005,w,shaftxtranslation,shaftytranslation,plateyrotation,platexrotation);
end

