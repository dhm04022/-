#include <stdio.h>

typedef struct person{
	char name[20];
	char tell[20];
	char address[80];
}person;

int main(){
	char name[] = "data.bin";
	FILE *f;
	int i;

	f = fopen(name,"wb");

	person p[3]={{"ȫ�浿","011-1111-1111","����� ���α� ��ô��"},
	{"����ȣ","017-3245-3278,","����� ������ ���"},{"����ȣ","011-2222-2456","��⵵ �Ⱦ�� ��굿"}};

	for(i=0; i<3; i++){
		fwrite(&p[i],sizeof(char),3,)
	}
	


}