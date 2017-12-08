#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"
#define SPEED 300

void backgoright();

int main()
{
    SensorData sdata;

//    int i;

    Open(szPort);


    while(1){
        sdata = Sensor(10);
        printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
		printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
		printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);

		if(sdata.IRSensor[1] > 100 || sdata.IRSensor[2] > 100 || sdata.IRSensor[3] > 100){
            if(sdata.IRSensor[1] < 200 && sdata.IRSensor[2] > 50 && sdata.IRSensor[2] < 200 && sdata.IRSensor[3] > 100 && sdata.IRSensor[3] < 300){ //살짝 굽은 곡선일 때
                printf("살짝 굽은 곡선일 떄:\n");
                Steering(3);
                Go(-SPEED, -SPEED);
                delay(700);
                Steering(2);
                Go(SPEED, SPEED);
                delay(1000);
               // Go(0,0);
                continue;
            }
            else if(sdata.IRSensor[0] < 100 && sdata.IRSensor[1] < 100 && sdata.IRSensor[2] < 200 && sdata.IRSensor[3] > 100){  //앞에 아무것도 없고 직진할 때
                printf("앞에 아무것도 없고 직진할 떄\n");
                Steering(2);
                Go(SPEED, SPEED);
                delay(1000);
                continue;
            }
            else if(sdata.IRSensor[0] < 200 &&sdata.IRSensor[1] < 200 && sdata.IRSensor[2] < 100 && sdata.IRSensor[3] > 200){   //오른족에 길이 없을 때
                printf("오른쪽에 가다가 길이 없어질 때\n");
                Steering(3);
                Go(SPEED,SPEED);
                delay(1000);
                continue;
            }
            else if(sdata.IRSensor[3] < 300 && sdata.IRSensor[3] > 100 && sdata.IRSensor[1] > 300 && sdata.IRSensor[1] < 400 && sdata.IRSensor[2] > 300 && sdata.IRSensor[2] < 500){     //왼쪽 오른쪽 90도로 막혀잇을 때
                printf("왼쪽 오른쪽 90도로 막혀 있을 떄\n");
                backgoright();
                continue;
            }
            if(sdata.IRSensor[1] > 500 || sdata.IRSensor[3] > 500 || sdata.IRSensor [2] > 500){
                if(sdata.IRSensor[2] > 500 && sdata.IRSensor[3] > 400){ //오른쪽에 박았을 때
                    printf("2,3이 구석에 박았을 때\n");
                    backgoright();
                    continue;
                }
                else if(sdata.IRSensor[1] > 200 && sdata.IRSensor[2] > 500){ //구석에 박혔을 때
                    printf("1, 2가 구석에 박았을 댸:\n");
                    backgoright();
                    continue;
                }
                else if(sdata.IRSensor[2] > 700 || sdata.IRSensor[3] > 700){
                    printf("완전 짱박혔을 때");
                    backgoright();
                    continue;
                }
                else if(sdata.IRSensor[2] > 200 && sdata.IRSensor[2] > 400 && sdata.IRSensor[3] < 100){
                    printf("애매한 구석");
                    backgoright();
                    continue;
                }
            }

		else if(sdata.IRSensor[0] < 30 && sdata.IRSensor[1] < 30 &&sdata.IRSensor[2] < 30 && sdata.IRSensor[3] < 30){
            printf("아무것도 없을 때: \n");
            Steering(3);
            Go(SPEED, SPEED);
            delay(1000);
            continue;
		}

		}
        else{
            printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
            printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
            printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);
            printf("바보다\n");
            Steering(1);
            while(1){
                if(sdata.IRSensor[3] < 400){
                    sdata = Sensor(10);
                    printf("IR1 : %d IR2 : %d ", sdata.IRSensor[0], sdata.IRSensor[1]);
                    printf("IR3 : %d\nIR4 : %d ", sdata.IRSensor[2], sdata.IRSensor[3]);
                    printf("IR5 : %d IR6 : %d\n\n", sdata.IRSensor[4], sdata.IRSensor[5]);
                    printf("GOGO\n");
                    Go(-SPEED, -SPEED);
                    delay(1000);
                    continue;
                }
                else
                    break;
            }
            /*Go(400, 400);
            delay(500);*/
            //continue;
        }
    }
}

void backgoright(){
    Steering(2);
    Go(-SPEED, -SPEED);
    delay(700);
    Steering(1);
    Go(SPEED, SPEED);
    delay(1000);
}
