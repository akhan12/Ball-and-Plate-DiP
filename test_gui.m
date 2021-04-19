function varargout = test_gui(varargin)

% TEST_GUI MATLAB code for test_gui.fig
%      TEST_GUI, by itself, creates a new TEST_GUI or raises the existing
%      singleton*.
%
%      H = TEST_GUI returns the handle to a new TEST_GUI or the handle to
%      the existing singleton*.
%
%      TEST_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TEST_GUI.M with the given input arguments.
%
%      TEST_GUI('Property','Value',...) creates a new TEST_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before test_gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to test_gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help test_gui

% Last Modified by GUIDE v2.5 16-Jul-2016 00:20:10

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @test_gui_OpeningFcn, ...
                   'gui_OutputFcn',  @test_gui_OutputFcn, ...
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


% --- Executes just before test_gui is made visible.
function test_gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to test_gui (see VARARGIN)
assignin('base','xy_output',[]);
% Choose default command line output for test_gui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
% axes(handles.axes2);
% plot(1:10,1:10);
set(handles.axes5,'Visible','off');
assignin('base','T',0.01);
set(handles.falling,'Visible','off');
handles.w=vrworld('bandplate_move_correctordinates');
%%ADDing on teensy
load teensy_config.mat;
handles.teensy1 = teensy;
open(handles.w);
handles.fullscr = 0;
% c1 = vr.canvas(w,'Parent',gcf,'Units','normalized','Position',[0.477 0.302 0.51 0.653]);
handles.c1 = vr.canvas(handles.w,'Parent',gcf,'Units','normalized','Position',[0.295 0.302 0.51 0.653]);
guidata(hObject,handles);
% cl=vrfigure(w);
load_system('ballonplate_correctordinates');
load variants
assignin('base','Backsteppingx',Backsteppingx);
assignin('base','Fuzzy',Fuzzy);
assignin('base','PID',PID);
set_param('ballonplate_correctordinates','StopTime','10');
set(handles.fuzzy,'Checked','off');
set(handles.backstep,'Checked','off');
set(handles.pid,'Checked','on');

% set(handles.step,'Checked','on');
% set(handles.sine,'Checked','off');
% contents = get(handles.popupmenu1,'Value');
%removed for so that default values assigned regardless of popupmenu1 value
% if contents ==1
        set_param('ballonplate_correctordinates/switch_x','sw','1');
        set_param('ballonplate_correctordinates/switch_y','sw','1');
        set_param('ballonplate_correctordinates/step_x','after','0.1');
        set_param('ballonplate_correctordinates/step_y','after','0.1');
% else
%         set_param('ballonplate_correctordinates/switch_x','sw','0');
%         set_param('ballonplate_correctordinates/switch_y','sw','0');
        set_param('ballonplate_correctordinates/sine_x','Amplitude','0.1','Frequency','0.5');
        set_param('ballonplate_correctordinates/sine_y','Amplitude','0.1','Frequency','0.5');
  %set this for sine or step
        set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/sine_step','Value','1');
        set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/Amplitude','Value','0.1');
        set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/step_size','Value','0.1');
        set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/angular_freq','Value','0.5');

        set_param('ballonplate_correctordinates/Controllery/Backsteppingx/sine_step','Value','1');
        set_param('ballonplate_correctordinates/Controllery/Backsteppingx/Amplitude','Value','0.1');
        set_param('ballonplate_correctordinates/Controllery/Backsteppingx/step_size','Value','0.1');
        set_param('ballonplate_correctordinates/Controllery/Backsteppingx/angular_freq','Value','0.5');
% end
% open_system('ballonplate_correctordinates/Scope1')
% open_system('ballonplate_correctordinates/Scope2')
% initializing default parameters
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/mass','Value','0.263');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/Radius','Value','0.2');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/m_s','Value','0');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/mass','Value','0.263');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/Radius','Value','0.2');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/m_s','Value','0');
set_param('ballonplate_correctordinates/plate_dimension','Value','35');
set_param('ballonplate_correctordinates/fall_sw','sw','0');
assignin('base','ctrlbp',2);
%Causes instability when on with other controllers
 set_param('ballonplate_correctordinates/Controllerx/Backsteppingx','Commented','on');
  set_param('ballonplate_correctordinates/Controllery/Backsteppingx','Commented','on');



% UIWAIT makes test_gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = test_gui_OutputFcn(hObject, eventdata, handles) 
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
%         mass = get_param('ballonplate_correctordinates/Subsystem3/Subsystem1/mass','Value');
%         radius = get_param('ballonplate_correctordinates/Subsystem3/Subsystem1/Radius','Value');
%         friction = get_param('ballonplate_correctordinates/Subsystem3/Subsystem1/m_s','Value');
%         plate = get_param('ballonplate_correctordinates/plate_dimension','Value');
%         defaultans = {mass,radius,friction,plate};
% 
% 
% sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
% mass = sys_parameters{1};
% radius = sys_parameters{2};
% friction = sys_parameters{3};
% plate = sys_parameters{4};
% set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/mass','Value',mass);
% set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/Radius','Value',radius);
% set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/m_s','Value',friction);
% set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/mass','Value',mass);
% set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/Radius','Value',radius);
% set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/m_s','Value',friction);
% set_param('ballonplate_correctordinates/plate_dimension','Value',plate);




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
y = get(handles.cb_parametric,'Value');
if y==1
set_param('ballonplate_correctordinates/XY Graph','commented','off')
else
    set_param('ballonplate_correctordinates/XY Graph','commented','on')

end

time = get(handles.simtime,'String');
rec_time = get(handles.recordtime,'String');
rec = get(handles.record,'Value');
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
set_param('ballonplate_correctordinates','StopTime',time);


try
    set_param('ballonplate_correctordinates','SimulationCommand','start')
catch
    errordlg('Simulation Prematurely Stopped','Error');
end




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
set_param('ballonplate_correctordinates','SimulationCommand','stop')


% --------------------------------------------------------------------
function Default_Callback(hObject, eventdata, handles)
% hObject    handle to Default (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/mass','Value','0.263');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/Radius','Value','0.2');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/m_s','Value','0');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/mass','Value','0.263');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/Radius','Value','0.2');
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/m_s','Value','0');
set_param('ballonplate_correctordinates/plate_dimension','Value','35');

% --------------------------------------------------------------------
function User_Callback(hObject, eventdata, handles)
% hObject    handle to User (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'Mass(kg)','Radius(m)','Rolling Friction Coefficient','Plate Dimensions (cm)'};
dlg_title = 'System Parameters';
num_lines = 1;
 
        mass = get_param('ballonplate_correctordinates/Subsystem3/Subsystem1/mass','Value');
        radius = get_param('ballonplate_correctordinates/Subsystem3/Subsystem1/Radius','Value');
        friction = get_param('ballonplate_correctordinates/Subsystem3/Subsystem1/m_s','Value');
        plate = get_param('ballonplate_correctordinates/plate_dimension','Value');
        defaultans = {mass,radius,friction,plate};


try
sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
mass = sys_parameters{1};
radius = sys_parameters{2};
friction = sys_parameters{3};
plate = sys_parameters{4};
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/mass','Value',mass);
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/Radius','Value',radius);
set_param('ballonplate_correctordinates/Subsystem3/Subsystem1/m_s','Value',friction);
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/mass','Value',mass);
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/Radius','Value',radius);
set_param('ballonplate_correctordinates/Subsystem3/Subsystem2/m_s','Value',friction);
set_param('ballonplate_correctordinates/plate_dimension','Value',plate);
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
 
 x1 = get_param('ballonplate_correctordinates/x1_init','InitialValue');
 x1_d = get_param('ballonplate_correctordinates/x1_d_init','InitialValue');
 x2 = get_param('ballonplate_correctordinates/x2_init','InitialValue');
 x2_d =  get_param('ballonplate_correctordinates/x2_d_init','InitialValue');
        defaultans = {x1,x1_d,x2,x2_d};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
try
x1 = sys_parameters{1};
x1_d = sys_parameters{2};
x2 = sys_parameters{3};
x2_d = sys_parameters{4};
set_param('ballonplate_correctordinates/x1_init','InitialValue',x1);
set_param('ballonplate_correctordinates/x1_d_init','InitialValue',x1_d);
set_param('ballonplate_correctordinates/x2_init','InitialValue',x2);
set_param('ballonplate_correctordinates/x2_d_init','InitialValue',x2_d);
catch
end

% --------------------------------------------------------------------
function falling_Callback(hObject, eventdata, handles)
% hObject    handle to falling (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'Initial Position','Initial Velocity'};
dlg_title = 'Falling ICs';
num_lines = 1;
 
 velocity= get_param('ballonplate_correctordinates/initial_velocity','InitialValue');
 position=get_param('ballonplate_correctordinates/initial_position','InitialValue');
        defaultans = {position,velocity};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
position = sys_parameters{1};
velocity = sys_parameters{2};

set_param('ballonplate_correctordinates/initial_position','InitialValue',position);
set_param('ballonplate_correctordinates/initial_velocity','InitialValue',velocity);


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
try fclose(handles.teensy1);
catch
 
end
close_system('ballonplate_correctordinates',0);
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
    open_system('ballonplate_correctordinates/Scope2');
else
    try  close_system('ballonplate_correctordinates/Scope2')
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
    open_system('ballonplate_correctordinates/angles');
else
    try  close_system('ballonplate_correctordinates/angles')
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
             canc = get(handles.realtime,'Value');
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
        set_param('ballonplate_correctordinates/fall_sw','sw','0');
        set_param('ballonplate_correctordinates/x1_init','InitialValue','0');
        set_param('ballonplate_correctordinates/x1_d_init','InitialValue','0');
        set_param('ballonplate_correctordinates/x2_init','InitialValue','0');
        set_param('ballonplate_correctordinates/x2_d_init','InitialValue','0');
    case 'Fall'
        set(handles.falling,'Visible','on');
        set(handles.BP_IC,'Visible','off');
        set_param('ballonplate_correctordinates/fall_sw','sw','1');
        set_param('ballonplate_correctordinates/initial_velocity','InitialValue','[0;5;0]');
        set_param('ballonplate_correctordinates/initial_position','InitialValue','[5;25;3]');
        set_param('ballonplate_correctordinates/gravity','InitialValue','-4');

end


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
contents = get(hObject,'Value');
if contents ==1
        set_param('ballonplate_correctordinates/switch_x','sw','1');
        set_param('ballonplate_correctordinates/switch_y','sw','1');
        set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/sine_step','Value','1');
        set_param('ballonplate_correctordinates/Controllery/Backsteppingx/sine_step','Value','1');

%         set_param('ballonplate_correctordinates/step_x','after','0.1');
%         set_param('ballonplate_correctordinates/step_y','after','0.1');
else
        set_param('ballonplate_correctordinates/switch_x','sw','0');
        set_param('ballonplate_correctordinates/switch_y','sw','0');
        set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/sine_step','Value','2');
        set_param('ballonplate_correctordinates/Controllery/Backsteppingx/sine_step','Value','3');
%         set_param('ballonplate_correctordinates/sine_x','Amplitude','0.1','Frequency','0.5');
%         set_param('ballonplate_correctordinates/sine_y','Amplitude','0.1','Frequency','0.5');
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
 
amplitude = get_param('ballonplate_correctordinates/sine_x','Amplitude');
frequency = get_param('ballonplate_correctordinates/sine_x','Frequency');

        defaultans = {amplitude,frequency};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
try
amplitude = sys_parameters{1};
frequency = sys_parameters{2};
catch
end

 set_param('ballonplate_correctordinates/sine_x','Amplitude',amplitude,'Frequency',frequency);
 set_param('ballonplate_correctordinates/sine_y','Amplitude',amplitude,'Frequency',frequency);
  
 set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/Amplitude','Value',amplitude);
      
 set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/angular_freq','Value',frequency);

        
  set_param('ballonplate_correctordinates/Controllery/Backsteppingx/Amplitude','Value',amplitude);
  set_param('ballonplate_correctordinates/Controllery/Backsteppingx/angular_freq','Value',frequency);

% --------------------------------------------------------------------
function step_Callback(hObject, eventdata, handles)
% hObject    handle to step (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
prompt = {'Step Size x','Step Size y'};
dlg_title = 'Step Properties';
num_lines = 1;
 
step_x = get_param('ballonplate_correctordinates/step_x','after');
step_y = get_param('ballonplate_correctordinates/step_y','after');


        defaultans = {step_x,step_y};


sys_parameters = inputdlg(prompt,dlg_title,num_lines,defaultans);
try
step_x = sys_parameters{1};
step_y = sys_parameters{2};

catch
end

 set_param('ballonplate_correctordinates/step_x','after',step_x);
 set_param('ballonplate_correctordinates/step_y','after',step_y);
   
 set_param('ballonplate_correctordinates/Controllerx/Backsteppingx/step_size','Value',step_x);
 set_param('ballonplate_correctordinates/Controllery/Backsteppingx/step_size','Value',step_y);


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


% --- Executes on button press in realtime.
function realtime_Callback(hObject, eventdata, handles)
% hObject    handle to realtime (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
w=handles.w;
% try 
try fopen(handles.teensy1);
catch
end
% catch
%     errordlg('Teensy not connected!','Communication Error');
% end

if strcmp(handles.teensy1.status,'open')
        i=1;
% h=animatedline;
% figure;
% axis([0 500 0 4000]);
while(true)
    if(handles.teensy1.BytesAvailable>0)
    a=fscanf(handles.teensy1,'%f');
    x(i)=a(1);
    y(i)=a(2);
%     addpoints(h,i,y(i));
%     drawnow
%     i_back =0;
%     if i>500
%     i_back = i-500;
%     end
%     axis([i_back i 0 4000]);
    stop = get(handles.stop_real,'value');
    if stop==1
        break;
    end
    x_test=(70*(x(i)-2048)/4096);
    y_test = (70*(y(i)-2048)/4096);
    w.ball_trans.translation = [x_test 5 y_test];
    i=i+1;
    pause(0.001);
    end
end
end
% Hint: get(hObject,'Value') returns toggle state of realtime


% --- Executes on button press in record.
function record_Callback(hObject, eventdata, handles)
% hObject    handle to record (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of record
value = get(hObject,'Value');


if value ==1
    set(handles.record,'ForegroundColor',[1 0 0]);
    set(handles.record,'FontWeight','bold');
else set(handles.record,'ForegroundColor',[0.07 0.169 0.549]);
    set(handles.record,'FontWeight','normal');
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


% --------------------------------------------------------------------
function startstop_Callback(hObject, eventdata, handles)
% hObject    handle to startstop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function startmenu_Callback(hObject, eventdata, handles)
% hObject    handle to startmenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
y = get(handles.cb_parametric,'Value');
if y==1
set_param('ballonplate_correctordinates/XY Graph','commented','off')
else
    set_param('ballonplate_correctordinates/XY Graph','commented','on')

end

time = get(handles.simtime,'String');
rec_time = get(handles.recordtime,'String');
rec = get(handles.record,'Value');
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
set_param('ballonplate_correctordinates','StopTime',time);


set_param('ballonplate_correctordinates','SimulationCommand','start')

% --------------------------------------------------------------------
function stopmenu_Callback(hObject, eventdata, handles)
% hObject    handle to stopmenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('ballonplate_correctordinates','SimulationCommand','stop')


% --------------------------------------------------------------------
function pid_Callback(hObject, eventdata, handles)
% hObject    handle to pid (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)c
assignin('base','ctrlbp',2);
set(handles.fuzzy,'Checked','off');
set(handles.backstep,'Checked','off');
set(hObject,'Checked','on');
set_param('ballonplate_correctordinates/Controllerx/Backsteppingx','Commented','on');
  set_param('ballonplate_correctordinates/Controllery/Backsteppingx','Commented','on');


% --------------------------------------------------------------------
function fuzzy_Callback(hObject, eventdata, handles)
% hObject    handle to fuzzy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
assignin('base','ctrlbp',1);
set(hObject,'Checked','on');
set(handles.pid,'Checked','off');
set(handles.backstep,'Checked','off');
set_param('ballonplate_correctordinates/Controllerx/Backsteppingx','Commented','on');
  set_param('ballonplate_correctordinates/Controllery/Backsteppingx','Commented','on');



% --------------------------------------------------------------------
function backstep_Callback(hObject, eventdata, handles)
% hObject    handle to backstep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
assignin('base','ctrlbp',0);
set(hObject,'Checked','on');
set(handles.pid,'Checked','off');
set(handles.fuzzy,'Checked','off');
set_param('ballonplate_correctordinates/Controllerx/Backsteppingx','Commented','off');
  set_param('ballonplate_correctordinates/Controllery/Backsteppingx','Commented','off');


% --- Executes on button press in stop_real.
function stop_real_Callback(hObject, eventdata, handles)
% hObject    handle to stop_real (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of stop_real
