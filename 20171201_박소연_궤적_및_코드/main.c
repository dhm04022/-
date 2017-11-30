#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"
#define MAX 10000
int forward_speed=300;
int backward_speed=-350;
void Autonomous(int ir1, int ir2, int ir3);

int main()
{
    SensorData sdata;
    double saveData[3][MAX];     //���� �󸶳� ���� �޾ƾ� ���� ��..
    int i, n = 0;

    Open(szPort);

    while(1){                   //���� �� �� �����͸� �޾ƾ� �ϴϱ� ���� ���� �� ������ �־�� ��
        sdata = Sensor(1);      //���� �ϴ� ���� �����͸� ��� �ޱ�
        saveData[0][n] = sdata.MSensor[0];
        saveData[1][n] = sdata.MSensor[1];
        saveData[2][n] = sdata.MSensor[2];
        n++;
        if(n != 0){
            if(saveData[0][n] == saveData[0][0] && saveData[1][n] == saveData[0][0] && saveData[2][n] && saveData[2][0])
                break;          //ó�� ���� ���� ���� ���� ���� ���߱�
        }
    }

    Close();

    return 0;
}

void Autonomous(int ir1, int ir2, int ir3){
    if(ir1>15 && ir2>15 && ir3>15){         //�տ� 3�� �������� ��� 15���� ũ��
        Go(backward_speed, backward_speed); //�������� �����ϱ�
        Steering(1);
    }
    else if(ir1>15 && ir2>15){              //���� ���ʰ� �߾� ������ 15���� ũ��
        Go(backward_speed, backward_speed);
        Steering(1);                        //�������� �����ϱ�
    }
    else if(ir1>15){                        //���� ���� ������ 15���� ũ��
        Go(backward_speed, backward_speed);
        Steering(1);                        //�������� �����ϱ�
    }
    else if(ir2>15 && ir3>15){              //�߾Ӱ� ���� ������ ������ 15���� ũ��
        Go(backward_speed, backward_speed);
        Steering(3);                        //���������� �����ϱ�
    }
    else if(ir3>15){                        //���� ������ ������ 15���� ũ��
        Go(backward_speed, backward_speed); //���������� ����
        Steering(3);
    }
    else{                                   //��� �͵� �ƴ� �� ����
        Go(forward_speed, forward_speed);   //�Ƹ��� ���ʿ� ���� ������ ������ ���� �ϴ� ��?
        Steering(2);
    }
}
