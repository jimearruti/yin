#include "funciones.h"

void autocorrelation(float* buffer, float* autocorr, int windowSize){
	
	int j, tau;

	for (tau=0; tau<windowSize; tau++){
		autocorr[tau]=0;
	
		for (j=0; j+tau<windowSize ;j++){
			autocorr[tau]=autocorr[tau]+buffer[j]*buffer[j+tau];
		}
	}

}


int findMaximum(float* buffer,int windowSize){

	int tau=0;
	int maxTau=0;
	int maxVal=0;

	//tau inicial se debe ajustar para no caer en que el máximo es en 0. Si es demasiado grande puedo elegir pico de mayor orden
	for (tau=63;tau<windowSize;tau++){

		if (buffer[tau]> maxVal){
	
			maxVal=buffer[tau];
			maxTau=tau;
		}

	}

return maxTau;

}
