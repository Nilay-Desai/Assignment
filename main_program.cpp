#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

FILE *Outputfile()
{
    return fopen("output.txt","a");
}
struct Process {
   int pid;
   int bt;
   int priority;
};

bool compare(Process a, Process b) {
   return (a.priority > b.priority);
}
void waitingtime(Process pro[], int n, int wt[]) {
   wt[0] = 0;
   for (int i = 1; i < n ; i++ )
      wt[i] = pro[i-1].bt + wt[i-1] ;
}
void turnarround( Process pro[], int n, int wt[], int tat[]) {
   for (int i = 0; i < n ; i++)
      tat[i] = pro[i].bt + wt[i];
}
void avgtime(Process pro[], int n) {
   FILE *fp=Outputfile();
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   waitingtime(pro, n, wt);
   turnarround(pro, n, wt, tat);
   char a[]= "Processes   Burst time   Waiting time   Turn around time";
   fputs(a,fp);
   fprintf(fp,"\n");
   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      fprintf(fp," %d",pro[i].pid);
      fprintf(fp,"\t\t%d",pro[i].bt);
      fprintf(fp,"\t\t%d",wt[i]);
      fprintf(fp,"\t\t%d",tat[i]);
      fprintf(fp,"\n");
   }
   fprintf(fp,"\n");
   char b[]="Average waiting time = ";
   fputs(b,fp);
   fprintf(fp,"  %f",(float)total_wt / (float)n);
   fprintf(fp,"\n");
   char ch[]="Average turn around time = ";
   fputs(ch,fp);
   fprintf(fp,"  %f",(float)total_tat / (float)n);
}
void scheduling(Process pro[], int n) {
   FILE *fp=Outputfile();
   sort(pro, pro + n, compare);
   fprintf(fp,"\n");
   fprintf(fp,"\n");
   char m[]="Order in which processes gets executed ";
   fputs(m,fp);
   fprintf(fp,"\n");
   for (int i = 0 ; i < n; i++)
   {
       fprintf(fp,"%d ",pro[i].pid);
   }
   fprintf(fp,"\n");
   avgtime(pro, n);
}
int main() {
    char ch;
	const char *fileName="Input.txt";
	ifstream file;
	file.open(fileName,ios::in);
	if(!file)
	{
		cout<<"Error in opening file!!!"<<endl;
		return -1;
	}
	int z=0;
	while (!file.eof())
    {
        if(z==50)
        {
            break;
        }
        z++;
        for(int i=1;i<=24;i++)
        {
           file >> ch;
        }
            file >> ch;
            int a=ch-'0';
             file >> ch;
            int b=ch-'0';
             file >> ch;
            int c=ch-'0';
             file >> ch;
            int d=ch-'0';
             file >> ch;
            int e=ch-'0';
             file >> ch;
            int f=ch-'0';
             file >> ch;
            int g=ch-'0';
             file >> ch;
            int h=ch-'0';
             file >> ch;
            int i=ch-'0';
             file >> ch;
            int j=ch-'0';
             file >> ch;
            int k=ch-'0';
             file >> ch;
            int l=ch-'0';
             file >> ch;
             int m=ch-'0';
             file >> ch;
            int ni=ch-'0';
             file >> ch;
            int o=ch-'0';
            Process pro[] = {{a,b,c},{d,e,f},{g,h,i},{j,k,l},{m,ni,o}};
            int n = sizeof pro / sizeof pro[0];
            scheduling(pro, n);
     }
	file.close();
	return 0;
}
