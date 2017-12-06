#include "Altino.h"

void curve(SensorData, int);

int main(void)
{
	SensorData sdata;
	int i;

	Open(szPort);

	while (1) {
		sdata = Sensor(10);
	
		printf("IR1 : %d, IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
		printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
		printf("IR5 : %d, IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);

		Go(400, 400);

		if (sdata.IRSensor[0] > 100 || sdata.IRSensor[1] > 200 || sdata.IRSensor[2] > 100){

			if (sdata.IRSensor[3] > 70) {
				curve(sdata, 1);
				if (sdata.IRSensor[0] < sdata.IRSensor[2]) {
					curve(sdata, 1);
				}
				else if (sdata.IRSensor[0] > sdata.IRSensor[2]) {
					curve(sdata, -1);
				}
			}
			
			if (sdata.IRSensor[4] > 70) {
				curve(sdata, -1);

				if (sdata.IRSensor[0] < sdata.IRSensor[2]) {
					curve(sdata, 1);
				}
				else if (sdata.IRSensor[0] > sdata.IRSensor[2]) {
					curve(sdata, -1);
				}
			}
		}
		
		else if (sdata.IRSensor[3] < 70 || sdata.IRSensor[4] < 70) {

			if (sdata.IRSensor[0] > 20 || sdata.IRSensor[1] > 100) {
				curve(sdata, -1);
				if (sdata.IRSensor[0] < sdata.IRSensor[2]) {
					curve(sdata, 1);
				}
				else if (sdata.IRSensor[0] > sdata.IRSensor[2]) {
					curve(sdata, -1);
				}
			}

			else if (sdata.IRSensor[1] > 100 || sdata.IRSensor[2] > 20) {
				curve(sdata, 1);
				if (sdata.IRSensor[0] < sdata.IRSensor[2]) {
					curve(sdata, 1);
				}
				else if (sdata.IRSensor[0] > sdata.IRSensor[2]) {
					curve(sdata, -1);
				}
			}
		}


	}

	Close();

	return 0;
}

void curve(SensorData data, int n)
{

	Go(-300, -300);
	delay(500);
	Go(0, 0);

	if (n == 1) {
		Steering(1);
		Go(-300, -300);
		delay(800);
		Go(0, 0);

		if (data.IRSensor[3] > 300) {
			Steering(2);
		
		}

	}
	else if (n == -1) {
		Steering(3);
		Go(-300, -300);
		delay(800);
		Go(0, 0);

		if (data.IRSensor[4] > 300) {
			Steering(2);
	
		}
	}
	Go(400, 400);
	delay(1500);
	Go(0, 0);

}

