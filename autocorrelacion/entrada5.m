close all
clear all
clc

%Programa para crear se�al de entrada al yin

SR=44100;
tf=10*0.0232;
t=[0:1/SR:tf];
%t=[0:1/SR:0.0232]+t(length(t));

frec=10;
%quiero frecuencia instantanea 400+100*sin(2*pi*frec*t), derivada de la fase /2pi
fase=10*sin(2*pi*frec.*t); %no aliasing

sinusoide=cos(2*pi*fase);

%frecTeorica2=sin(2*pi*50.*t)./50; %aliasing
%sinusoide2=cos(2*pi*frecTeorica2.*t);



%grafica la entrada generada
figure (1)
plot (t,sinusoide,"linewidth",2)
%hold on
%plot (t2,sinusoide2,"linewidth",2)

%plot (t,fase,"linewidth",2,'r')
%hold on
%%plot ([t(length(t)),t(length(t))],[200,800],'k--',"linewidth",2)

h2=xlabel ("tiempo (s)");
set (h2, "fontsize", 30);
h3=ylabel ("cos(wt)");
set (h3, "fontsize", 30);
h=get(gcf, "currentaxes");
set(h, "fontsize", 30, "linewidth", 1);
grid minor

%figure (2)
%plot (tiempos,frecuencias)
%xlabel ("t");
%ylabel ("f(t)");


%escribe archivo txt con entrada
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

%
%fclose(fid);
save datos.mat frec tf