close all
clear all
clc

%Programa para crear se�al de entrada al yin

frecTeorica=43.47;
SR=44100;
t=[0:1/SR:0.0232];
sinusoide=cos(2*pi*frecTeorica*t);


%frecTeorica2=700;
%t2=[0.3:1/SR:0.6];
%sinusoide2=cos(2*pi*frecTeorica2*t2);
%
%frecTeorica3=100;
%t3=[0.6:1/SR:1];
%sinusoide3=cos(2*pi*frecTeorica3*t3);

%grafica la entrada generada
%figure (1)
%plot (t,sinusoide)
%hold on
%plot (t2,sinusoide2)
%hold on
%plot (t3,sinusoide3)

%
%%escribe archivo txt con entrada
%formato:
%SR cantidad de muestras
%e(0) e(1) e(2) ....

fid=fopen('entrada3.txt','w');
fprintf(fid,'%d %d\n',SR,size(t,2));

for i=1:size(t,2)
fprintf(fid,'%f ',sinusoide(i));
end
%for i=1:size(t2,2)
%fprintf(fid,'%f ',sinusoide2(i));
%end
%for i=1:size(t3,2)
%fprintf(fid,'%f ',sinusoide3(i));
%end
fclose(fid);