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

	person p[3]={{"홍길동","011-1111-1111","서울시 구로구 고척동"},
	{"조명호","017-3245-3278,","서울시 강남구 도곡동"},{"최윤호","011-2222-2456","경기도 안양시 비산동"}};

	for(i=0; i<3; i++){
		fwrite(&p[i],sizeof(char),3,)
	}
	


}