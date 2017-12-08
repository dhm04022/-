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
            if(sdata.IRSensor[1] < 200 && sdata.IRSensor[2] > 50 && sdata.IRSensor[2] < 200 && sdata.IRSensor[3] > 100 && sdata.IRSensor[3] < 300){ //��¦ ���� ��� ��
                printf("��¦ ���� ��� ��:\n");
                Steering(3);
                Go(-SPEED, -SPEED);
                delay(700);
                Steering(2);
                Go(SPEED, SPEED);
                delay(1000);
               // Go(0,0);
                continue;
            }
            else if(sdata.IRSensor[0] < 100 && sdata.IRSensor[1] < 100 && sdata.IRSensor[2] < 200 && sdata.IRSensor[3] > 100){  //�տ� �ƹ��͵� ���� ������ ��
                printf("�տ� �ƹ��͵� ���� ������ ��\n");
                Steering(2);
                Go(SPEED, SPEED);
                delay(1000);
                continue;
            }
            else if(sdata.IRSensor[0] < 200 &&sdata.IRSensor[1] < 200 && sdata.IRSensor[2] < 100 && sdata.IRSensor[3] > 200){   //�������� ���� ���� ��
                printf("�����ʿ� ���ٰ� ���� ������ ��\n");
                Steering(3);
                Go(SPEED,SPEED);
                delay(1000);
                continue;
            }
            else if(sdata.IRSensor[3] < 300 && sdata.IRSensor[3] > 100 && sdata.IRSensor[1] > 300 && sdata.IRSensor[1] < 400 && sdata.IRSensor[2] > 300 && sdata.IRSensor[2] < 500){     //���� ������ 90���� �������� ��
                printf("���� ������ 90���� ���� ���� ��\n");
                backgoright();
                continue;
            }
            if(sdata.IRSensor[1] > 500 || sdata.IRSensor[3] > 500 || sdata.IRSensor [2] > 500){
                if(sdata.IRSensor[2] > 500 && sdata.IRSensor[3] > 400){ //�����ʿ� �ھ��� ��
                    printf("2,3�� ������ �ھ��� ��\n");
                    backgoright();
                    continue;
                }
                else if(sdata.IRSensor[1] > 200 && sdata.IRSensor[2] > 500){ //������ ������ ��
                    printf("1, 2�� ������ �ھ��� ��:\n");
                    backgoright();
                    continue;
                }
                else if(sdata.IRSensor[2] > 700 || sdata.IRSensor[3] > 700){
                    printf("���� ¯������ ��");
                    backgoright();
                    continue;
                }
                else if(sdata.IRSensor[2] > 200 && sdata.IRSensor[2] > 400 && sdata.IRSensor[3] < 100){
                    printf("�ָ��� ����");
                    backgoright();
                    continue;
                }
            }

		else if(sdata.IRSensor[0] < 30 && sdata.IRSensor[1] < 30 &&sdata.IRSensor[2] < 30 && sdata.IRSensor[3] < 30){
            printf("�ƹ��͵� ���� ��: \n");
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
            printf("�ٺ���\n");
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
