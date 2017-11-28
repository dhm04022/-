#include <stdio.h>
#include <string.h>

#define p 5

typedef struct exam{
	int i;
	char num[20];
	char name[20];
	int mid;
	int final;
	int hw1;
	int hw2;
	int a;
	float sum;
	char s[10];
}exam;

int main(){
	char fexam1[]="input.txt";
	char fexam2[]="output.txt";

	FILE *f1;
	FILE *f2;

	exam e[5];

	int i;

	f1= fopen(fexam1,"r");

	for(i=0; i<p; i++){
		fscanf(f1, "  %d %s %s %d %d %d %d %d\n",&e[i].i, e[i].num, e[i].name, 
			&e[i].mid, &e[i].final, &e[i].hw1, &e[i].hw2, &e[i].a);
	}

	f2= fopen(fexam2,"w");

	for(i=0; i<p; i++){

		fprintf(f2, "%d %s %s %d %d %d %d %d\n",e[i].i, e[i].num, e[i].name, 
			e[i].mid, e[i].final, e[i].hw1, e[i].hw2,e[i].a);
		fprintf(f2, "              %.1f, %.1f, %.1f, %.1f %d",(0.3 * e[i].mid), 
			(0.4 * e[i].final), (0.1 * e[i].hw1), (0.1* e[i].hw2), e[i].a);
		e[i].sum = (0.3 * e[i].mid) + (0.4 * e[i].final) + (0.1 * e[i].hw1) + (0.1 * e[i].hw2) + e[i].a;
		
		fprintf(f2, "  %.1f", e[i].sum);

		if(95 <= e[i].sum && e[i].sum <= 100){
			strcpy(e[i].s,"A+\n");
			fprintf(f2, " %s",e[i].s);
		}else if(90 <= e[i].sum && e[i].sum < 95){
			strcpy(e[i].s,"A0\n");
			fprintf(f2, " %s",e[i].s);
		}else if(85 <= e[i].sum && e[i].sum < 90){
			strcpy(e[i].s,"B+\n");
			fprintf(f2, " %s",e[i].s);
		}else if(80 <= e[i].sum && e[i].sum < 85){
			strcpy(e[i].s,"B0\n");
			fprintf(f2, " %s",e[i].s);
		}else if(75 <= e[i].sum && e[i].sum < 80){
			strcpy(e[i].s,"C+\n");
			fprintf(f2, " %s",e[i].s);
		}else if(70 <= e[i].sum && e[i].sum < 75){
			strcpy(e[i].s,"C0\n");
			fprintf(f2, " %s",e[i].s);
		}else if(65 <= e[i].sum && e[i].sum < 70){
			strcpy(e[i].s,"D+\n");
			fprintf(f2, " %s",e[i].s);
		}else if(60 <= e[i].sum && e[i].sum < 65){
			strcpy(e[i].s,"D0\n");
			fprintf(f2, " %s",e[i].s);
		}else if(e[i].sum < 60){
			strcpy(e[i].s,"F\n");
			fprintf(f2, " %s",e[i].s);
		}
	}

	for(i=0; i<p; i++){
		printf("%d %s %s   %d    %d   %d  %d   %d\n",e[i].i, e[i].num, e[i].name, 
			e[i].mid, e[i].final, e[i].hw1, e[i].hw2,e[i].a);
		printf("                  %.1f  %.1f  %.1f  %.1f  %d  %.1f     %s\n",(0.3 * e[i].mid), 
			(0.4 * e[i].final), (0.1 * e[i].hw1), (0.1* e[i].hw2), e[i].a, e[i].sum, e[i].s);
	}
	fclose(f1);
	fclose(f2);

	return 0;
}