instrhwinfo('Bluetooth');
bb=Bluetooth('PARTNERZ',1);
bb.OutputBufferSize=11;
bb.inputBufferSize=15;
fopen(bb);
flushinput(bb);
d = 0.1; % Distance between axes
phiRef = -pi/2; % Reference position
q = 0; % Initial state
e = phiRef - q;
start="start"
pause(1);
 while 1
 e = phiRef - q; %Position end orientation error


 % Controller
 v = 0;
 w = 4*e;

 %VR and VL
 VL=((2*v)-(w*d))/2;
 VR=((2*v)+(w*d))/2;
 
 % Physical constraints
 if abs(VL)>0.8914, VL = 0.8914*sign(VL); end
 if abs(VR)>0.8914, VR = 0.8914*sign(VR); end
 
 % ADC
 L_pwm=string(int32((VL)/0.0022))
 R_pwm=string(int32((VR)/0.0022))
 
 %Bluetooth
    fwrite(bb,"0"+" "+L_pwm+" "+R_pwm+" ");
    cmd=char(fread(bb));
    cmd=convertCharsToStrings(cmd);
    dist=str2double(extractBetween(cmd,",",";"));
    q=dist(1)
    
 end