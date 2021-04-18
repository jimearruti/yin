close all
clear all
clc
%programa para leer la salida del yin

fid=fopen('salida3.txt','r');
valores=fscanf(fid,'%f');
fclose(fid);

SR=valores(1);
numMuestras=valores(2);
windowSize=valores(3);
hop=valores(4);
senal=valores(5:end);

n=[1:1:windowSize];

[maximo i]=max (senal(63:length(senal)));
i=i+63;
fobt=SR/i

%figure (2)
%plot (n,senal,'.')
%hold on
%plot ([63,63],[-1000,1000],'r--',"linewidth",3)
%hold on
%plot ([i,i],[-1000,1000],'g--',"linewidth",3)


%h2=xlabel ("numero de muestra");
%set (h2, "fontsize", 30);
%h3=ylabel ("Autocorrelacion");
%set (h3, "fontsize", 30);
%h=get(gcf, "currentaxes");
%set(h, "fontsize", 30, "linewidth", 2);
%grid minor