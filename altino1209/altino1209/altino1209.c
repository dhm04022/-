#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"
#define SPEED 300
#define MAX 100

void backgoright();

int main()
{
	SensorData sdata;

	double gyro[4][100];
	int i = 0;

	Open(szPort);


	while (1) {
		sdata = Sensor(10);
		printf("\n\nIR값: \n");
		printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
		printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
		printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);
		i++;
		printf("i 의 값은? %d\n", i);

/*		gyro[0][i] = sdata.GySensor[0];
		gyro[1][i] = sdata.GySensor[1];
		gyro[2][i] = sdata.GySensor[2];
		i++;
		if (i == 100)
			break;*/

		if (sdata.IRSensor[1] > 70 || sdata.IRSensor[2] > 70 || sdata.IRSensor[3] > 70) {
			if (sdata.IRSensor[1] < 200 && sdata.IRSensor[2] > 50 && sdata.IRSensor[2] < 200 && sdata.IRSensor[3] > 100 && sdata.IRSensor[3] < 300) { //살짝 굽은 곡선일 때
																																					  //              printf("살짝 굽은 곡선일 때:\n");
				printf("살짝 굽은 곡선일 때:\n");
				sdata = Sensor(10);
				Steering(3);
				Go(-SPEED, -SPEED);
				delay(700);
				Steering(2);
				Go(SPEED, SPEED);
				delay(1000);
				// Go(0,0);


				i = 0;
				printf("i 리셋 %d\n", i);
				continue;
			}
			else if (sdata.IRSensor[0] < 100 && sdata.IRSensor[1] < 100 && sdata.IRSensor[2] < 200 && sdata.IRSensor[3] > 300 && sdata.IRSensor[3] < 400) {  //앞에 아무것도 없고 직진할 때
				printf("앞에 아무것도 없고 직진 할 때\n");
				sdata = Sensor(10);
				Steering(2);
				Go(SPEED, SPEED);
				delay(1000);

				i = 0;
				printf("i 리셋 %d\n", i);
				continue;
			}
			else if (sdata.IRSensor[0] < 100 && sdata.IRSensor[1] < 100 && sdata.IRSensor[2] < 100 && sdata.IRSensor[3] > 150 && sdata.IRSensor[3] < 300) {   //오른족에 길이 없을 때
																																   //               printf("오른쪽에 가다가 길이 없어질 때\n");
				printf("가다가 오른쪽에 길이 없을 때\n");
				sdata = Sensor(10);
				Steering(3);
				Go(SPEED, SPEED);
				delay(1000);

				i = 0;
				continue;
			}
			else if (sdata.IRSensor[3] < 300 && sdata.IRSensor[3] > 100 && sdata.IRSensor[1] > 300 && sdata.IRSensor[1] < 400 && sdata.IRSensor[2] > 300 && sdata.IRSensor[2] < 500) {     //왼쪽 오른쪽 90도로 막혀잇을 때
																																														   //                printf("왼쪽 오른쪽 90도로 막혀 있을 때\n");
				printf("왼쪽 오른쪽 90도로 막혀 있을 때\n");
				sdata = Sensor(10);
				backgoright();

				i = 0;
				printf("i 리셋 %d\n", i);
				continue;
			}
			if (sdata.IRSensor[1] > 500 || sdata.IRSensor[3] > 500 || sdata.IRSensor[2] > 500) {
				if (sdata.IRSensor[2] > 500 && sdata.IRSensor[3] > 400) { //오른쪽에 박았을 때
																		  //                    printf("2,3이 구석에 박았을 때\n");
					printf("2,3이 구석에 박았을 때\n");
					sdata = Sensor(10);
					backgoright();

					i = 0;
					printf("i 리셋 %d\n", i);
					continue;
				}
				else if (sdata.IRSensor[1] > 200 && sdata.IRSensor[2] > 500) { //구석에 박혔을 때
																			   //                   printf("1, 2가 구석에 박았을 때:\n");
					printf("1, 2가 구석에 박았을 때:\n");
					sdata = Sensor(10);
					backgoright();

					i = 0;
					printf("i 리셋 %d\n", i);
					continue;
				}
				else if (sdata.IRSensor[2] > 600 || sdata.IRSensor[3] > 600) {
					//                    printf("완전 짱박혔을 때");
					printf("완전 짱박혔을 때\n");
					sdata = Sensor(10);
					backgoright();

					i = 0;
					printf("i 리셋 %d\n", i);
					continue;
				}
				else if ((sdata.IRSensor[2] > 200 && sdata.IRSensor[2] < 400 && sdata.IRSensor[3] < 200 && sdata.IRSensor[3] > 100)) {
					//                    printf("애매한 구석");
					printf("오른쪽 앞이 가까운 애매한 구석\n");
					sdata = Sensor(10);
					backgoright();

					i = 0;
					printf("i 리셋 %d\n", i);
					continue;
				}
				else if ( sdata.IRSensor[3] < 550 && sdata.IRSensor[3] > 250 && sdata.IRSensor[2] > 100 && sdata.IRSensor[2] < 200) {
					printf("오른쪽이 애매한 구석 2\n");
					sdata = Sensor(10);
					backgoright();

					i = 0; 				printf("i 리셋 %d\n", i);
					continue;
				}
			}

			else if (sdata.IRSensor[0] < 30 && sdata.IRSensor[1] < 30 && sdata.IRSensor[2] < 30 && sdata.IRSensor[3] < 30 && sdata.IRSensor[4] < 30) {
				//            printf("아무것도 없을 때: \n");
				printf("아무것도 없을 때:\n");
				sdata = Sensor(10);
				Steering(3);
				Go(SPEED, SPEED);
				delay(1000);

				i = 0; 				printf("i 리셋 %d\n", i);
				continue;
			}
			/*else if (sdata.IRSensor[2] > 50 && sdata.IRSensor[2] < 100 && sdata.IRSensor[3] > 50 && sdata.IRSensor[3] < 100) {
				printf()
				Steering(2);
				Go(SPEED, SPEED);
				delay(700);

				i = 0;
				continue;
			}*/

		}
		else if (sdata.IRSensor[5] > 600) {
			printf("뒤에 박았을 때\n");
			sdata = Sensor(10);
			Steering(2);
			Go(SPEED, SPEED);
			delay(1000);

			i = 0; 				printf("i 리셋 %d\n", i);
			continue;
		}
		else {
			sdata = Sensor(10);
			printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
			printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
			printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);
			printf("바보다\n");
			Steering(1);
			while (1) {
				if (sdata.IRSensor[3] < 250 && sdata.IRSensor[5] < 300) {
					sdata = Sensor(10);
					if (sdata.IRSensor[2] > 400 || sdata.IRSensor[3] > 400 || sdata.IRSensor[1] > 400)
						i = 0; 				printf("i 리셋 %d\n", i);
					break;
					printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
					printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
					printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);
					printf("GOGO\n");
					Go(-SPEED, -SPEED);
					delay(1000);

					i = 0; 				printf("i 리셋 %d\n", i);
					continue;
				}
				else if (sdata.IRSensor[5] > 300) {
					sdata = Sensor(10);

					i = 0; 				printf("i 리셋 %d\n", i);
					break;
				}
				else
					i = 0; 				printf("i 리셋 %d\n", i);
					break;
			}
			/*Go(400, 400);
			delay(500);*/
			continue;
		}
		if (i >= 20) {
			printf("애매하면 그냥 뒤로 보낸다 \n");
			Steering(1);
			Go(-500, -500);
			delay(500);
			Steering(2);
			Go(500, 500);
			delay(1000);
			i = 0; 				printf("i 리셋 %d\n", i);
			continue;
		}
	}

/*	for (i = 0; i < MAX; i++) {
		printf("gyroX: %d\n", gyro[0][i]);
		printf("gyroY: %d\n", gyro[1][i]);
		printf("gyroZ: %d\n", gyro[2][i]);
	}*/
}

void backgoright() {
	Steering(2);
	Go(-SPEED, -SPEED);
	delay(700);
	Steering(1);
	Go(SPEED, SPEED);
	delay(1000);
}
