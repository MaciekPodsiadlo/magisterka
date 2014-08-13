function [] = using_mlib(x, y, z)
mlibini;
mlib('SelectBoard','DS1005');
% mlib('LoadVarFile' , 'C:\Documents and Settings\k12_p800a\Moje dokumenty\praca_magisterska');
par_names = {
%         'Data Stores/ObliczoneX'
    'Model Root/tryby/rozpoznawanie obrazu/wlacz/Value';
    'Model Root/tryby/rozpoznawanie obrazu/obliczoneX/Value';
    'Model Root/tryby/rozpoznawanie obrazu/obliczoneY/Value';
    'Model Root/tryby/rozpoznawanie obrazu/obliczoneZ/Value';
    };
param = mlib('GetTrcVar' , par_names);
kk = mlib('Read', param);

% mlib('Set','Trigger','ON',...
%    'TriggerLevel',1,...        
%    'TriggerEdge','rising',...  % default, can be omitted
%    'TriggerVariable',trig,...
%    'TraceVars',param,...
%    'NumSamples',500,...
%    'Delay',0);

% mlib('StartCapture');   % start capture on the DS1006, defult service number 1
% while mlib('TriggerState') ~= 1, end   % wait until trigger is armed; in pre-trigger mode
%                                        % trigger is armed after the delay time is run down!

kk{1} = 1;
kk{2} = x;
kk{3} = y;
kk{4} = z;
% kk = x;
                                       
% set the amplitude to 0.5 - the trigger event occurs 
mlib('Write',param,'Data',kk);
% while mlib('CaptureState')~=0, end     % wait until data acquisition finished

% out_data = mlib('FetchData')

end