function   pen_2d(x_theta)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

time = x_theta.time;
x = x_theta.data(:,1);
theta = x_theta.data(:,2);
phi = x_theta.data(:,3);
r = 2;
%         h = animatedline;
line1x = [x,r*sin(theta)+x];
line1y = [zeros(length(time),1),r*cos(theta)];
line2x = [line1x(:,2),r*sin(phi)+line1x(:,2)];
line2y = [line1y(:,2),r*cos(phi)+line1y(:,2)];
 axis([min(x)-4 max(x)+4 -4.5 4.5]);
         for i=1:length(time)
             
            plot(line1x(i,:),line1y(i,:),line2x(i,:),line2y(i,:));
             axis([min(x)-4 max(x)+4 -4.5 4.5]);

%             pause(0.0001);
            drawnow
%              addpoints(h,xy.data(i,2),xy.data(i,1));
%              drawnow
         end



%         for i=1:length(time)
%              
%              theta_t = theta(i);
%              phi_t = phi(i);
%             line1x = [x(i), r*sin(theta_t)+x(i)];
%             line1y = [0,r*cos(theta_t)];
%             line2x = [line1x(2),r*sin(phi_t)+line1x(2)];
%             line2y = [line1y(2),r*cos(phi_t)+line1y(2)];
%             plot(line1x,line1y,'.',line2x,line2y,'.');
%             axis([min(x)-4 max(x)+4 -4.5 4.5]);
% %             pause(0.0001);
%             drawnow
% %              addpoints(h,xy.data(i,2),xy.data(i,1));
% %              drawnow
%          end

end

