function varargout = DIP_gui(varargin)

% DIP_gui MATLAB code for DIP_gui.fig
%      DIP_gui, by itself, creates a new DIP_gui or raises the existing
%      singleton*.
%
%      H = DIP_gui returns the handle to a new DIP_gui or the handle to
%      the existing singleton*.
%
%      DIP_gui('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DIP_gui.M with the given input arguments.
%
%      DIP_gui('Property','Value',...) creates a new DIP_gui or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DIP_gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DIP_gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DIP_gui

% Last Modified by GUIDE v2.5 26-Jun-2016 19:17:05

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DIP_gui_OpeningFcn, ...
                   'gui_OutputFcn',  @DIP_gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before z_dd is made visible.
function DIP_gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DIP_gui (see VARARGIN)
assignin('base','xy_output',[]);
% Choose default command line output for DIP_gui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
% axes(handles.axes2);
% plot(1:10,1:10);
set(handles.axes5,'Visible','off');
assignin('base','T',0.01);
assignin('base','m1', 0.18);
assignin('base','n1',0.078);
assignin('base','l1',0.19);
assignin('base','Jn1', 2.8e-5);
assignin('base','I1' ,0.0089);
assignin('base','c1',  0.0001);
assignin('base','m2', 0.1);
assignin('base','n2',0.05);
assignin('base','l2',0.115);
assignin('base','Jn2' , 2e-6);
assignin('base','I2', 0.0018);
assignin('base','c2', 0.002);
assignin('base','g', 9.8);
assignin('base','L', 0.38);

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

assignin('base','I_theta',I_theta);
assignin('base','M1',M1);
assignin('base','M2',M2);
assignin('base','I_phi',I_phi);
assignin('base','M3',M3);
handles.w=vrworld('Double_Inverted_Pendullum_updated3');
open(handles.w);
handles.fullscr = 0;
% c1 = vr.canvas(w,'Parent',gcf,'Units','normalized','Position',[0.477 0.302 0.51 0.653]);
handles.c1 = vr.canvas(handles.w,'Parent',gcf,'Units','normalized','Position',[0.295 0.302 0.51 0.653]);
guidata(hObject,handles);
% cl=vrfigure(w);
load_system('pendulumgui');
load variants;
assignin('base','FF',FF);
assignin('base','energy_method',energy_method);
%initial conditions for simulink model
%This is for feedforward controller
set_param('pendulumgui','StopTime','10');
set_param('pendulumgui/Manual Switch','sw','0');
assignin('base','ctrl',0);
set_param('pendulumgui/DIP/theta','InitialCondition','-pi');
set_param('pendulumgui/DIP/phi','InitialCondition','-pi');

% open_system('pendulumgui/Scope1')
% open_system('pendulumgui/Scope2')
% initializing default parameters
% set_param('pendulumgui/Subsystem3/Subsystem1/mass','Value','0.263');
% set_param('pendulumgui/Subsystem3/Subsystem1/Radius','Value','0.2');
% set_param('pendulumgui/Subsystem3/Subsystem1/m_s','Value','0');
% set_param('pendulumgui/Subsystem3/Subsystem2/mass','Value','0.263');
% set_param('pendulumgui/Subsystem3/Subsystem2/Radius','Value','0.2');
% set_param('pendulumgui/Subsystem3/Subsystem2/m_s','Value','0');
% set_param('pendulumgui/plate_dimension','Value','35');
% set_param('pendulumgui/fall_sw','sw','0');



% UIWAIT makes DIP_gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = DIP_gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --------------------------------------------------------------------
function sys_param_Callback(hObject, eventdata, handles)
% hObject    handle to sys_param (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% prompt = {'Mass(kg)','Radius(m)','Rolling Friction Coefficient','Plate Dimensions (m)'};
% dlg_title = 'System Parameters';
% num_lines = 1;
%  
%         mass = get_param('pendulumgui/Subsystem3/Subsystem1/mass','Value');
%         radius = get_param('pendulumgui/Subsystem3/Subsystem1/Radius','Value');
%         friction = get_param('pendulumgui/Subsystem3/Subsystem1/m_s','Value');
%         plate = get_param('pendulumgui/plate_dimension','Value');
%         defaultans = {mass,radius,friction,plate};
% 
% 
% sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
% mass = sys_parameters{1};
% radius = sys_parameters{2};
% friction = sys_parameters{3};
% plate = sys_parameters{4};
% set_param('pendulumgui/Subsystem3/Subsystem1/mass','Value',mass);
% set_param('pendulumgui/Subsystem3/Subsystem1/Radius','Value',radius);
% set_param('pendulumgui/Subsystem3/Subsystem1/m_s','Value',friction);
% set_param('pendulumgui/Subsystem3/Subsystem2/mass','Value',mass);
% set_param('pendulumgui/Subsystem3/Subsystem2/Radius','Value',radius);
% set_param('pendulumgui/Subsystem3/Subsystem2/m_s','Value',friction);
% set_param('pendulumgui/plate_dimension','Value',plate);




% --------------------------------------------------------------------
function controller_Callback(hObject, eventdata, handles)
% hObject    handle to controller (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function initial_conditions_Callback(hObject, eventdata, handles)
% hObject    handle to initial_conditions (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes when figure1 is resized.
function figure1_SizeChangedFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in checkbox1.
function checkbox1_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox1


% --- Executes on button press in togglebutton1.
function togglebutton1_Callback(hObject, eventdata, handles)
% hObject    handle to togglebutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of togglebutton1


% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes1


% --- Executes on button press in start_pb.
function start_pb_Callback(hObject, eventdata, handles)
% hObject    handle to start_pb (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% if y==1
% set_param('pendulumgui/XY Graph','commented','off')
% else
%     set_param('pendulumgui/XY Graph','commented','on')
% 
% end
outputvar =get(handles.cb_outputvar,'Value');
controlvar = get(handles.cb_controlvar,'Value');
if outputvar==1
    open_system('pendulumgui/scope_output');
else try
        close_system('pendulumgui/scope_output');
    catch
    end

end
if controlvar==1
   open_system('pendulumgui/scope_position'); 
else try close_system('pendulumgui/scope_position'); 
    catch
    end
end
time = get(handles.simtime,'String');
rec_time = get(handles.recordtime,'String');
rec = get(handles.Record,'Value');
if rec==1
    set(handles.w,'RecordMode','scheduled');
     set(handles.w,'Record3D','on');
%       handles.f=get(handles.w,'Figures');
%       set(handles.f,'Record2D','on');
%       set(handles.f,'NavPanel','halfbar');
    if str2double(rec_time)>str2double(time)
        rec_time = time;
    end
    set(handles.w,'RecordInterval',[0 str2double(rec_time)]);
else set(handles.w,'Record3D','off');
end
guidata(hObject,handles);
set_param('pendulumgui','StopTime',time);
set_param('pendulumgui','SimulationCommand','start');




% --------------------------------------------------------------------
function input_signals_Callback(hObject, eventdata, handles)
% hObject    handle to input_signals (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in stop.
function stop_Callback(hObject, eventdata, handles)
% hObject    handle to stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui','SimulationCommand','stop')


% --------------------------------------------------------------------
function Default_Callback(hObject, eventdata, handles)
% hObject    handle to Default (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
assignin('base','T',0.01);
assignin('base','m1', 0.18);
assignin('base','n1',0.078);
assignin('base','l1',0.19);
assignin('base','Jn1', 2.8e-5);
assignin('base','I1' ,0.0089);
assignin('base','c1',  0.0001);
assignin('base','m2', 0.1);
assignin('base','n2',0.05);
assignin('base','l2',0.115);
assignin('base','Jn2' , 2e-6);
assignin('base','I2', 0.0018);
assignin('base','c2', 0.002);
assignin('base','g', 9.8);
assignin('base','L', 0.38);

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

assignin('base','I_theta',I_theta);
assignin('base','M1',M1);
assignin('base','M2',M2);
assignin('base','I_phi',I_phi);
assignin('base','M3',M3);

% --------------------------------------------------------------------
function User_Callback(hObject, eventdata, handles)
% hObject    handle to User (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


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


% I_theta = I1 +m1*(l1^2)+m2*(L^2)+n2*(L^2)+Jn1;
% M1 = m2*l2*L;
% M2 = m1*l1+m2*L+n2*L;
% I_phi = I2+m2*(l2*l2)+Jn2;
% M3=m2*l2;



prompt = {'m1(kg)','n1','l1','Jn1','I1','c1','m2','n2','l2','Jn2','I2','c2','g','L'};

dlg_title = 'System Parameters';
num_lines = 1;

defaultans = {m1,n1,l1,Jn1,I1,c1,m2,n2,l2,Jn2,I2,c2,g,L};
for i=1:14
    defaultans{i} = num2str(defaultans{i});
end

try
sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
m1 = str2double(sys_parameters{1});
n1 = str2double(sys_parameters{2});
l1 = str2double(sys_parameters{3});
Jn1 = str2double(sys_parameters{4});
I1 = str2double(sys_parameters{5});
c1 = str2double(sys_parameters{6});
m2 = str2double(sys_parameters{7});
n2 = str2double(sys_parameters{8});
l2 = str2double(sys_parameters{9});
Jn2 = str2double(sys_parameters{10});
I2 = str2double(sys_parameters{11});
c2 =str2double(sys_parameters{12});
g = str2double(sys_parameters{13});
L = str2double(sys_parameters{14});

assignin('base','m1', m1);
assignin('base','n1',n1);
assignin('base','l1',l1);
assignin('base','Jn1', Jn1);
assignin('base','I1' ,I1);
assignin('base','c1',  c1);
assignin('base','m2', m2);
assignin('base','n2',n2);
assignin('base','l2',l2);
assignin('base','Jn2' , Jn2);
assignin('base','I2', I2);
assignin('base','c2', c2);
assignin('base','g', g);
assignin('base','L', L);

I_theta = I1 +m1*(l1^2)+m2*(L^2)+n2*(L^2)+Jn1;
M1 = m2*l2*L;
M2 = m1*l1+m2*L+n2*L;
I_phi = I2+m2*(l2*l2)+Jn2;
M3=m2*l2;

assignin('base','I_theta',I_theta);
assignin('base','M1',M1);
assignin('base','M2',M2);
assignin('base','I_phi',I_phi);
assignin('base','M3',M3);
catch
end

% --------------------------------------------------------------------
function BP_IC_Callback(hObject, eventdata, handles)
% hObject    handle to BP_IC (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'x','dx/dt','y','dy/dt'};
dlg_title = 'Ball and Plate ICs';
num_lines = 1;
 
 x1 = get_param('pendulumgui/x1_init','InitialValue');
 x1_d = get_param('pendulumgui/x1_d_init','InitialValue');
 x2 = get_param('pendulumgui/x2_init','InitialValue');
 x2_d =  get_param('pendulumgui/x2_d_init','InitialValue');
        defaultans = {x1,x1_d,x2,x2_d};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
x1 = sys_parameters{1};
x1_d = sys_parameters{2};
x2 = sys_parameters{3};
x2_d = sys_parameters{4};
set_param('pendulumgui/x1_init','InitialValue',x1);
set_param('pendulumgui/x1_d_init','InitialValue',x1_d);
set_param('pendulumgui/x2_init','InitialValue',x2);
set_param('pendulumgui/x2_d_init','InitialValue',x2_d);

% --------------------------------------------------------------------
function falling_Callback(hObject, eventdata, handles)
% hObject    handle to falling (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'Initial Position','Initial Velocity'};
dlg_title = 'Falling ICs';
num_lines = 1;
 
 velocity= get_param('pendulumgui/initial_velocity','InitialValue');
 position=get_param('pendulumgui/initial_position','InitialValue');
        defaultans = {position,velocity};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
position = sys_parameters{1};
velocity = sys_parameters{2};

set_param('pendulumgui/initial_position','InitialValue',position);
set_param('pendulumgui/initial_velocity','InitialValue',velocity);


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
close_system('pendulumgui',0);
Main_Gui;
delete(hObject);


% --- Executes on button press in nofall_radio.
function nofall_radio_Callback(hObject, eventdata, handles)
% hObject    handle to nofall_radio (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of nofall_radio


% --- Executes on button press in cb_outputvar.
function cb_outputvar_Callback(hObject, eventdata, handles)
% hObject    handle to cb_outputvar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cb_outputvar
y = get(hObject,'Value');
if y==1
    open_system('pendulumgui/scope_output');
else
    try  close_system('pendulumgui/scope_output')
    catch
    end   
end

% --- Executes on button press in cb_controlvar.
function cb_controlvar_Callback(hObject, eventdata, handles)
% hObject    handle to cb_controlvar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
y = get(hObject,'Value');
if y==1
    open_system('pendulumgui/scope_position');
else
    try  close_system('pendulumgui/scope_position')
    catch
    end   
end
% Hint: get(hObject,'Value') returns toggle state of cb_controlvar


% --- Executes on button press in cb_parametric.
function cb_parametric_Callback(hObject, eventdata, handles)
% hObject    handle to cb_parametric (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cb_parametric


% --- Executes on button press in replay.
function replay_Callback(hObject, eventdata, handles)
% hObject    handle to replay (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

    xy = evalin('base','xy_output');
    if isempty(xy)
        errordlg('Run Simulation First','No Data');
    else
    delete(handles.c1);
%     handles.c1 = vr.canvas(handles.w,'Parent',gcf,'Units','normalized','Position',[0.5+0.02 0.355 0.504 0.622]);
    handles.fullscr = 1;
    guidata(hObject,handles);
         set(handles.axes5,'Visible','on');
         cla
         axes(handles.axes5);
         h = animatedline;
         balltranslation = evalin('base','balltranslation');
         shaftxtranslation = evalin('base','shaftxtranslation');
         shaftytranslation = evalin('base','shaftytranslation');
         platexrotation = evalin('base','platexrotation');
         plateyrotation = evalin('base','plateyrotation');
         for i=1:length(xy.time)
             addpoints(h,xy.data(i,2),xy.data(i,1));
             drawnow
%              vrml_animate(i,balltranslation,0.00001,handles.w,shaftxtranslation,shaftytranslation,plateyrotation,platexrotation);
             canc = get(handles.replaycancel,'Value');
             if canc==1
                 break;
             end;
         end
%         plot(xy.time,xy.data(:,1),'--',xy.time,xy.data(:,2),'--');
    end

    

% --- Executes when selected object is changed in uibuttongroup2.
function uibuttongroup2_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uibuttongroup2 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

h = get(handles.uibuttongroup2,'SelectedObject');
select = get(h,'string');
switch select
    case 'No Fall'
        set(handles.falling,'Visible','off');
        set(handles.BP_IC,'Visible','on');
        set_param('pendulumgui/fall_sw','sw','0');
        set_param('pendulumgui/x1_init','InitialValue','0');
        set_param('pendulumgui/x1_d_init','InitialValue','0');
        set_param('pendulumgui/x2_init','InitialValue','0');
        set_param('pendulumgui/x2_d_init','InitialValue','0');
    case 'Fall'
        set(handles.falling,'Visible','on');
        set(handles.BP_IC,'Visible','off');
        set_param('pendulumgui/fall_sw','sw','1');
        set_param('pendulumgui/initial_velocity','InitialValue','[0;5;0]');
        set_param('pendulumgui/initial_position','InitialValue','[5;25;3]');
        set_param('pendulumgui/gravity','InitialValue','-4');

end



% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --------------------------------------------------------------------
function sine_Callback(hObject, eventdata, handles)
% hObject    handle to sine (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'Amplitude','Frquency'};
dlg_title = 'Circular Trajectory Properties';
num_lines = 1;
 
amplitude = get_param('pendulumgui/sine_x','Amplitude');
frequency = get_param('pendulumgui/sine_x','Frequency');

        defaultans = {amplitude,frequency};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
amplitude = sys_parameters{1};
frequency = sys_parameters{2};

 set_param('pendulumgui/sine_x','Amplitude',amplitude,'Frequency',frequency);
 set_param('pendulumgui/sine_y','Amplitude',amplitude,'Frequency',frequency);

% --------------------------------------------------------------------
function step_Callback(hObject, eventdata, handles)
% hObject    handle to step (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'Step Size x','Step Size y'};
dlg_title = 'Step Properties';
num_lines = 1;
 
step_x = get_param('pendulumgui/step_x','after');
step_y = get_param('pendulumgui/step_y','after');


        defaultans = {step_x,step_y};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
step_x = sys_parameters{1};
step_y = sys_parameters{2};

 set_param('pendulumgui/step_x','after',step_x);
 set_param('pendulumgui/step_y','after',step_y);


% --- Executes on button press in checkbox5.
function checkbox5_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox5


% --------------------------------------------------------------------
function screen_Callback(hObject, eventdata, handles)
% hObject    handle to screen (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --------------------------------------------------------------------
function mini_Callback(hObject, eventdata, handles)
% hObject    handle to mini (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    delete(handles.c1);
    set(handles.axes5,'Visible','off');
    axes(handles.axes5);
    cla
    handles.c1 = vr.canvas(handles.w,'Parent',gcf,'Units','normalized','Position',[0.295 0.302 0.51 0.653]);
if handles.fullscr==1
    handles.fullscr = 0;
    guidata(hObject,handles);
end

% --------------------------------------------------------------------
function fullscr_Callback(hObject, eventdata, handles)
% hObject    handle to fullscr (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    delete(handles.c1);
    set(handles.axes5,'Visible','off');
    axes(handles.axes5);
    cla;
    handles.c1 = vr.canvas(handles.w,'Parent',gcf,'Units','normalized','Position',[0 0 1 1]);
if handles.fullscr ==0

    handles.fullscr=1;
    guidata(hObject,handles);
end


% --- Executes when uibuttongroup2 is resized.
function uibuttongroup2_SizeChangedFcn(hObject, eventdata, handles)
% hObject    handle to uibuttongroup2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in replaycancel.
function replaycancel_Callback(hObject, eventdata, handles)
% hObject    handle to replaycancel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of replaycancel


% --------------------------------------------------------------------
function menustartstop_Callback(hObject, eventdata, handles)
% hObject    handle to menustartstop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function dipic_Callback(hObject, eventdata, handles)
% hObject    handle to dipic (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Record.
function Record_Callback(hObject, eventdata, handles)
% hObject    handle to Record (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Record


% --------------------------------------------------------------------
function startmenu_Callback(hObject, eventdata, handles)
% hObject    handle to startmenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui','SimulationCommand','start')


% --------------------------------------------------------------------
function stopmenu_Callback(hObject, eventdata, handles)
% hObject    handle to stopmenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui','SimulationCommand','stop')


% --------------------------------------------------------------------
function swing_Callback(hObject, eventdata, handles)
% hObject    handle to swing (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function stabcontrol_Callback(hObject, eventdata, handles)
% hObject    handle to stabcontrol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function smc_controller_Callback(hObject, eventdata, handles)
% hObject    handle to smc_controller (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui/select_energy','Value','0');
set_param('pendulumgui/FF/select_FF','Value','0');

% --------------------------------------------------------------------
function lqr_Callback(hObject, eventdata, handles)
% hObject    handle to lqr (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui/select_energy','Value','1');
set_param('pendulumgui/FF/select_FF','Value','1');

% --------------------------------------------------------------------
function feedforward_Callback(hObject, eventdata, handles)
% hObject    handle to feedforward (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui/Manual Switch','sw','0');
assignin('base','ctrl',0);
set_param('pendulumgui/DIP/theta','InitialCondition','-pi');
set_param('pendulumgui/DIP/phi','InitialCondition','-pi');

% --------------------------------------------------------------------
function energy_Callback(hObject, eventdata, handles)
% hObject    handle to energy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('pendulumgui/Manual Switch','sw','1');
assignin('base','ctrl',1);
set_param('pendulumgui/DIP/theta','InitialCondition','-pi+(pi/100)');
set_param('pendulumgui/DIP/phi','InitialCondition','-pi');


% --- Executes during object deletion, before destroying properties.
function figure1_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function simtime_Callback(hObject, eventdata, handles)
% hObject    handle to simtime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of simtime as text
%        str2double(get(hObject,'String')) returns contents of simtime as a double


% --- Executes during object creation, after setting all properties.
function simtime_CreateFcn(hObject, eventdata, handles)
% hObject    handle to simtime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function recordtime_Callback(hObject, eventdata, handles)
% hObject    handle to recordtime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of recordtime as text
%        str2double(get(hObject,'String')) returns contents of recordtime as a double


% --- Executes during object creation, after setting all properties.
function recordtime_CreateFcn(hObject, eventdata, handles)
% hObject    handle to recordtime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
