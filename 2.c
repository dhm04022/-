#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	FILE *fp1;
	FILE *fp2;
	
	int num1, num2;
	char c;

	fp1=fopen(argv[1],"r");
	fscanf(fp1,"%d%c%d",&num1, &c, &num2);

	fp2 = fopen(argv[2], "w");

	switch(c){
		case '+': fprintf(fp2,"%d\n",num1+num2);
			     printf("%d\n",num1+num2);
				 break;
		case '*': fprintf(fp2,"%d\n",num1*num2);
				printf("%d\n",num1*num2);
				break;
		case '-': fprintf(fp2,"%d\n",num1-num2);
				printf("%d\n",num1-num2);
				break;
		case '/' :  fprintf(fp2,"%.1f\n",(float)num1/num2);\
				printf("%.1f\n",(float)num1/num2);
			break;
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}


	
