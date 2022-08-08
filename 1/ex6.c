#include <stdio.h>
#include <math.h>

double trajectory(double t);

int main(){
	printf("Time (in seconds)      Height (in metres)\n");
	printf("*****************************************\n");
	double t=0.0;
	while(1){
		double height=trajectory(t);
		printf("%f 		%f\n", t, height);

		if(t>=100) break;
		if(height<=0.) break;
		if(height<50) t=t+0.05;
		else t=t+2.;


	}
	return 0;
}

double trajectory(double t){
	return 60+2.13*t*t-0.0013*t*t*t*t+0.000034*pow(t, 4.751);
}
