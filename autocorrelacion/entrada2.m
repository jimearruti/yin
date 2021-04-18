close all
clear all
clc

%Programa para crear se�al de entrada al yin

SR=44100;
t=[0:1/SR:10*0.0232];
frecTeorica=20+500*t;
sinusoide=cos(2*pi*frecTeorica.*t);



%grafica la entrada generada
%figure (1)
%plot (t,sinusoide)
%xlabel ("t");
%ylabel ("sin (wt)");

figure (2)
plot (t,frecTeorica)
xlabel ("t");
ylabel ("f(t)");

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

fclose(fid);