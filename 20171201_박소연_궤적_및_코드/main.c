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
    double saveData[3][MAX];     //값을 얼마나 자주 받아야 할지 모름..
    int i, n = 0;

    Open(szPort);

    while(1){                   //주행 할 때 데이터를 받아야 하니까 주행 시작 후 조건을 넣어야 함
        sdata = Sensor(1);      //주행 하는 동안 데이터를 계속 받기
        saveData[0][n] = sdata.MSensor[0];
        saveData[1][n] = sdata.MSensor[1];
        saveData[2][n] = sdata.MSensor[2];
        n++;
        if(n != 0){
            if(saveData[0][n] == saveData[0][0] && saveData[1][n] == saveData[0][0] && saveData[2][n] && saveData[2][0])
                break;          //처음 센서 값과 같은 곳에 오면 멈추기
        }
    }

    Close();

    return 0;
}

void Autonomous(int ir1, int ir2, int ir3){
    if(ir1>15 && ir2>15 && ir3>15){         //앞에 3개 센서값이 모두 15보다 크면
        Go(backward_speed, backward_speed); //왼쪽으로 후진하기
        Steering(1);
    }
    else if(ir1>15 && ir2>15){              //앞의 왼쪽과 중앙 센서가 15보다 크면
        Go(backward_speed, backward_speed);
        Steering(1);                        //왼쪽으로 후진하기
    }
    else if(ir1>15){                        //앞의 왼쪽 센서가 15보다 크면
        Go(backward_speed, backward_speed);
        Steering(1);                        //왼쪽으로 후진하기
    }
    else if(ir2>15 && ir3>15){              //중앙과 앞의 오른쪽 센서가 15보다 크면
        Go(backward_speed, backward_speed);
        Steering(3);                        //오른쪽으로 후진하기
    }
    else if(ir3>15){                        //앞의 오른쪽 센서가 15보다 크면
        Go(backward_speed, backward_speed); //오른쪽으로 후진
        Steering(3);
    }
    else{                                   //어느 것도 아닐 때 직진
        Go(forward_speed, forward_speed);   //아마도 양쪽에 벽이 세워져 있으면 직진 하는 듯?
        Steering(2);
    }
}
