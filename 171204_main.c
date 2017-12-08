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

/*		if (sdata.IRSensor[1] > 0 && sdata.IRSensor[2] > 0) {
			Go(-300, -300);
			Steering(3);
			delay(2000);
			Go(0, 0);
		}*/

		Go(400, 400);

		if (sdata.IRSensor[0] > 100 || sdata.IRSensor[1] > 200 || sdata.IRSensor[2]> 100)
		{
//			Go(-100, -100);
//			delay(1000);

			if (sdata.IRSensor[3] > 20) curve(sdata, 1);
			if (sdata.IRSensor[4] > 20) curve(sdata, -1);
		}

		// if (종착점)
		//	break;

	}

	Close();

	return 0;
}

void curve(SensorData data, int n)
{
	// 후진
	Go(-300, -300);
	delay(1000);
	Go(0, 0);

	if (n == 1)
		Steering(1);
	else if (n == -1)
		Steering(3);

	// 커브돌기
	Go(400, 400);
	delay(1000);
	Go(0, 0);
	Steering(2);
}

/*
커브함수

// 우회전
if (sdata.IRSensor[4] > 100) {
	Go(-300, -300);

	delay(2300);

	Go(0, 0);

	Steering(3);

	Go(400, 400);

	delay(2700);

	Go(0, 0);
}

// 좌회전
if (sdata.IRSensor[3] > 50) {
	Go(-300, -300);

		delay(2300);

		Go(0, 0);

		Steering(1);

		Go(400, 400);

		delay(2700);

		Go(0, 0);
}
*/