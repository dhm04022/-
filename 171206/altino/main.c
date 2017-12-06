#include "Altino.h"
#include <stdio.h>
#define SPEED 400
int main(){    int i=1;    int i0, i1, i2, i3, i4;    SensorData dat;
    Open(szPort);
    while(1)    {
        dat = Sensor(10);
        i0 = dat.IRSensor[0]; 
        i1 = dat.IRSensor[1];     
        i2 = dat.IRSensor[2];
		i3 = dat.IRSensor[3];
		i4 = dat.IRSensor[4];

        printf("%d %d %d\n", i0, i1, i2);   
        Steering(2);      
        Go(SPEED,SPEED);    
        Sleep(100);
		if(i3<20){
			Steering(1);
			Go(-SPEED, -SPEED);
			Sleep(1000);
			Steering(3);
			Go(SPEED, SPEED);
			Sleep(500);
		}
		else if(i0>200){
			Steering(1);
			Go(SPEED, SPEED);
		}
		else if(i2>400){
			Steering(1);
			Go(-SPEED, -SPEED);
			Sleep(500);
		}
		else if(i3>400){
			Steering(1);
			Go(SPEED, SPEED);
			Sleep(500);
		}
    Close();
	}
}