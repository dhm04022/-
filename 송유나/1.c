#include "Altino.h"

int main() {

	SensorData data1;
	Open(szPort);

	while (1)
	{
		data1 = Sensor(1);


		if (data1.IRSensor[0]<100 && data1.IRSensor[0]>0 && data1.IRSensor[1]<100 && data1.IRSensor[1]>0 && data1.IRSensor[2]<100 && data1.IRSensor[2]>0)
		{
			Go(0, 0);
			Steering2(3);
		}
		else if (data1.IRSensor[0]<200 && data1.IRSensor[1]<200 && data1.IRSensor[0]>0 && data1.IRSensor[1]>0)
		{
			Go(400, 400);
			Steering2(1);
		}

		else if (data1.IRSensor[1]<200 && data1.IRSensor[2]<200 && data1.IRSensor[1]>0 && data1.IRSensor[2]>0)
		{
			Go(400, 400);
			Steering2(3);
		}
		else if (data1.IRSensor[0]<100 && data1.IRSensor[0]>0)
		{
			Go(0, 0);
			Steering2(1);
		}
		else if (data1.IRSensor[1]<100 && data1.IRSensor[1]>0)
		{
			Go(0, 0);
			Steering2(1);
		}
		else if (data1.IRSensor[2]<100 && data1.IRSensor[2]>0)
		{
			Go(0, 0);
			Steering2(3);
		}
		else if (data1.IRSensor[5]>0 && data1.IRSensor[5] < 100) {
			Go(0, 0);
			Steering2(2);
		}
		else if (data1.IRSensor[3]<150 && data1.IRSensor[3]>0) {
			Go(500, 500);
			Steering2(3);
		}
		else if (data1.IRSensor[4]<150 && data1.IRSensor[4]>0) {
			Go(500, 500);
			Steering2(1);
		}
		else if (data1.IRSensor[4]<100 && data1.IRSensor[4]>0 && data1.IRSensor[1]<100 && data1.IRSensor[1]>0) {
			Go(-400, -400);
			Steering2(2);
			delay(1000);
		}
		else {
			Go(500, 500);
			Steering2(2);
		}
	}




	//Go(0,0);
	//    sleep();
	Close();

	return 0;
}