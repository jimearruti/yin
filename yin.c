#include <stdio.h>
#include "yin.h"


//Definitions of parameters
double inputSampleRate;
double frameSize=0.03*inputSampleRate; /*????*/
double thresh;
double hop=0.010*inputSampleRate; /*????*/
int signalLength;

/*Signal read from file*/
double input[50];

/*Final output from the program, the detected frequencies for every instant*/
double freq[50];


//for every instant
for (int time=0;t<=signalLength-frameSize;t++);{
	
	//difference function must be calculated for every instant. Variable with Tau.
	double difference[frameSize] = calcDifference(time,frameSize,&input);

	//For the cummulative difference, the mean of the difference vector must be calculated
	double cumulativeDifference[frameSize];

	cumulativeDifference[0]=1;
	
	for (int tau=1;tau<=frameSize-1;tau++){
		
		int meanFrame=0;
	
		for (int i=1;i<=tau;i++)//chequear límites
		
			meanFrame=meanFrame+difference[tau]/tau;
			
	
		cummulativeDifference[tau]=difference[tau]/meanFrame;

		
	}
			
	
	//Must find tau so that cummulativeDifference(tau) is minimum and smaller than th 
	//-if this is impossible the global minimum of cummulativeDifference is calculated




}



double calcDifference(int time, int frameSize,double* input){

	for (int tau=0;tau<=frameSize-1;tau++){

		difference[tau]=0;

		for (int i=time;i<=time+frameSize-1;i++){

			difference[tau]=difference[tau]+input[i]-input[i+tau];

		}
	}


}


//Adaptar para buscar mínimo de cummulativeDifference
int minDistance(ITEM* dist, int* T, int n){

   	// Initialize min value
   	int min = 2147483647;
	int min_index;
  
   	for (int v = 0; v < n; v++)
     		if (T[v] == 0 && dist[v].value < min){
         		min = dist[v].value;
			min_index = v;
  		}
   	return min_index;
}

