#include <stdio.h>
#include "Altino.h"
const int s = 300;

void curve(SensorData, int);

int main(void)
{
	SensorData sdata;
	int i;

	Open(szPort);

	while (1) {
		sdata = Sensor(10);

		printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
		printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
		printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);

/*		if( (sdata.IRSensor[0] > 100 || sdata.IRSensor[1] > 100) && sdata.IRSensor[2] > 300){
            Steering(3);
            Go(-s, -s);
            delay(1000);
            Steering(2);
            Go(s,s);
            delay(700);
            Go(0,0);
		}

		if (sdata.IRSensor[0] < 30 && sdata.IRSensor[1] < 30 && sdata.IRSensor[2] < 30 && sdata.IRSensor[3] < 30 && sdata.IRSensor[4] < 30 && sdata.IRSensor[5] < 30) {
			Steering(3);
			Go(s, s);
			delay(700);
		}

		if (sdata.IRSensor[0] < 30 && sdata.IRSensor[1] < 30 && sdata.IRSensor[2] < 50) {
                if(sdata.IRSensor[3] < 500 && sdata.IRSensor[3] > 0){
                    Steering(2);
                    Go(-s, -s);
                    delay(1000);
                    Steering(3);
                    Go(s, s);
                    delay(1000);
                    Go(0,0);
                }
		}//�տ� ���� ���� �����ʿ� ���� ���� �� , ������ Ŀ��

		if (sdata.IRSensor[0] < 20 && sdata.IRSensor[1] > 20 && sdata.IRSensor[1] < 200 && sdata.IRSensor[2] > 150 && sdata.IRSensor[2] < 1000 && sdata.IRSensor[3] < 1000 && sdata.IRSensor[3] > 300) {
			curve(sdata, 1);
		}


		Go(400, 400);

		if(sdata.IRSensor[2] > 100 || sdata.IRSensor[3] > 200){
                if(sdata.IRSensor[3] > 400 && sdata.IRSensor[2] > 200)
                    curve(sdata, 1);
                else {
                    Steering(3);
                    Go(s, s);
                    delay(1000);
                    Go(0,0);
                }
		}

		/*if (sdata.IRSensor[0] > 100 || sdata.IRSensor[1] > 200 || sdata.IRSensor[2]> 100)
		{

			if (sdata.IRSensor[3] > 20) curve(sdata, 1);
			if (sdata.IRSensor[4] > 20) curve(sdata, -1);
		}*/


		if(sdata.IRSensor[0] < 10 && sdata.IRSensor[1] < 10 && sdata.IRSensor[2] < 10 && sdata.IRSensor[3] < 10 && sdata.IRSensor[4] < 10 && sdata.IRSensor[5] < 10){
            Steering(3);
            Go(s, s);
            delay(1000);
            Go(0,0);
		} //�ֺ��� �ƹ��͵� ���� ��

		if(sdata.IRSensor[1] > 100 || sdata.IRSensor[2] > 100 || sdata.IRSensor[3] > 100){
            if(sdata.IRSensor[2] > 400 && sdata.IRSensor[3] > 400){
                curve(sdata, 1);
            }
            if((sdata.IRSensor[0] > 400 || sdata.IRSensor[1] > 400 || sdata.IRSensor[2] > 400) && sdata.IRSensor[3] > 200){
                if(sdata.IRSensor[3] > 400){
                    Steering(3);
                    Go(-s, -s);
                    delay(1000);
                    Steering(2);
                    Go(s, s);
                    delay(700);
                }
                else{
                    curve(sdata,1);
                }
            }

            if(sdata.IRSensor[0] < 10 && sdata.IRSensor[1] < 10 && sdata.IRSensor[2] < 500 && sdata.IRSensor[2] > 10 && sdata.IRSensor[3] > 100){
                    Steering(3);
                    Go(s,s);
                    delay(700);
                    Go(0,0);
            }
            if(sdata.IRSensor[2] < 100 && sdata.IRSensor[3] < 200){
                Steering(3);
                Go(s, s);
                delay(700);
                Go(0,0);
            }
            if(sdata.IRSensor[1] > 400 || sdata.IRSensor[2] > 400){ //�����̳� �ä��� �椾�⼾���� ���� ���� ��
                    if(sdata.IRSensor[1] > 400 && sdata.IRSensor[2] > 400){
                        Steering(1);
                        Go(-s, -s);
                        delay(700);
                        Go(0,0);
                    }
                    if(sdata.IRSensor[2] > 100 && sdata.IRSensor[3] > 400){
                        Steering(1);
                        Go(-s, -s);
                        delay(700);
                        Go(0,0);
                    }
            }
		}

		Go(400, 400);

		// if (������)
		//	break;

	}

	Close();

	return 0;
}

void curve(SensorData data, int n)
{
	// ����
	Steering(2);
	Go(-300, -300);
	delay(1000);
	Go(0, 0);

	if (n == 1)
		Steering2(-70, -70);
	else if (n == -1)
		Steering2(70, 70);

	// Ŀ�굹��
	Go(400, 400);
	delay(1000);
	Go(0, 0);
	Steering(2);
}

