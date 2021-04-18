#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


float* signal;
float* autocorr;
float* frec;

int main(){
	
	int inputSampleRate; //viene en entrada
	int signalLength; //viene en entrada
	int i;
	int hop; //definir
	int windowSize; //definir
	int maxTau;
	int numFrame;

	
	FILE*fp=fopen("entrada3.txt","r");
	

	//leo frecuencia de muestreo y largo de la señal
	fscanf(fp,"%d %d",&inputSampleRate,&signalLength);

	//defino windowSize en función de otros parámetros
	windowSize=1024;

	//defino hop en función de otros parámetros
	hop=windowSize;

	//calculo numero de frames
	numFrame=(int)(((float) signalLength-(float) windowSize)/(float) hop)+1;

	//reservo memoria para almacenar la señal
	signal=malloc(sizeof(float)*signalLength);
	autocorr=malloc(sizeof(float)*windowSize);
	frec=malloc(sizeof(float)*numFrame);

	//guardo en el vector cada muestra
	for (i=0; i<signalLength; i++){
		fscanf(fp,"%f",signal+i);
	}
	
//---------------------------------------------------------------------	
	//escribo la salida

	FILE*fp2=fopen("salida3.txt","w+");

	//escribo frecuencia de muestreo y largo de la señal
	fprintf(fp2,"%d %d %d %d\n",inputSampleRate,numFrame,windowSize,hop);



	//Para cada frame, calculo la autocorrelación y busco el máximo. Con ese máximo obtengo la frecuencia
	

	for (i=0;i<numFrame;i++){

		autocorrelation(&signal[i*hop],autocorr,windowSize);
		
		maxTau=findMaximum(autocorr,windowSize);
	
		frec[i]=(float)inputSampleRate/(float)maxTau;

			// muestro la autocorrelación del frame 149			
			if (i==0){
				
				for (int j=0; j<windowSize;j++){
					fprintf(fp2,"%f ",autocorr[j]);
				}
			}	
	

	}
//---------------------------------------------------------------------	
/*	//escribo la salida*/

/*	FILE*fp2=fopen("salida3.txt","w+");*/

/*	//escribo frecuencia de muestreo y largo de la señal*/
/*	fprintf(fp2,"%d %d %d %d\n",inputSampleRate,numFrame,windowSize,hop);*/
	
	//escribo la señal

/*	for (i=0; i<numFrame;i++){*/
/*		fprintf(fp2,"%f ",frec[i]);*/
/*	}	*/
	

	fclose(fp);
	fclose(fp2);
	free(autocorr);
	free(signal);
	free(frec);

return 0;
}	
