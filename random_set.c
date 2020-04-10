#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int p,a,i,j,k;
	FILE *fptr;
	fptr=fopen("Input.txt","w");
	for(a=1;a<51;a++)
	{
		fputs("\nProcess   Bursttime   Priority\n",fptr);
		for(p=1;p<=5;p++)
		{
			i=p;
			j=rand()%10;
			k=rand()%10;
			fprintf(fptr,"  %d",i);
			fprintf(fptr,"\t\t%d",j);
			fprintf(fptr,"\t%d",k);
			fprintf(fptr,"\n");
		}
	}
	fclose(fptr);
	return 0;
}
