#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#define MAX 50

typedef struct process
{
	int pid,AT,BT;
	int CT,TAT,WT;
	int RT,type;
}process;
/*						----- Terminology -----
	pid  --> processId(in program calculated by order on entry by user)
	AT   --> Arrival Time(i/p)
	BT   --> Burst(time required to execute process) Time(i/p)
	CT   --> Complition Time
	TAT  --> Turn Around Time, Calculated as TAT = CT - AT
	WT   --> Waiting Time, Calculated as WT = TAT - BT
	RT   --> Remaining Time(time remaining to complete execution)
			 intialized equal to BT
	type --> type of process(i/p),one of following three:-
			 1. System Processes     --  Scheduled with SRTN
			 2. Interactive Proceses --  Scheduled with RR
			 3. Batch Processes      --  Scheduled with FCFS
*/

//display for cmd,just for testing:-
void display(process p[],int n)
{
	int i;
	printf("Pid AT BT CT TAT WT type\n");
	for(i=0;i<n;i++)
	{
		printf("%3d %2d %2d %2d %3d %2d %d\n",p[i].pid,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].type);
	}
	printf("\n");
}
void readOutput(process p[],int *n,float *avg_tat,float *avg_wt)
{
	FILE *fp;
	char fileName[34],opFiles[30][34];
	int len,k=0,choice;
	DIR *d;
	struct dirent *pd;
	
	d = opendir("./");
	printf("Select a file:-\n");
	if(d != NULL)
	{
		while((pd = readdir(d))!=NULL)
		{
			len = strlen(pd->d_name);
			if(strcmp(pd->d_name+len-4,".txt")==0)
			{
				printf("%d. %s\n",k+1,pd->d_name);
				strcpy(opFiles[k],pd->d_name);
				k++;
			}
		}
	}
	(void) closedir(d);
	scanf("%d",&choice);
	strcpy(fileName,opFiles[choice-1]);
	fp = fopen(fileName,"r");
	if(fp == NULL)
	{
		printf("cannot open file\n");
		exit(4);
	}	
	fscanf(fp,"%d\n",n);
	for(int i=0;i<*n;i++)
	{	
		fscanf(fp,"%d%d%d",&p[i].pid,&p[i].AT,&p[i].BT); 
		fscanf(fp,"%d%d%d ",&p[i].CT,&p[i].TAT,&p[i].WT);
		fscanf(fp,"%d",&p[i].type);
	}
	fscanf(fp,"%f%f",avg_tat,avg_wt);
	fclose(fp);
}
void main()
{
	int n;
	float avg_tat,avg_wt;
	process p[MAX];
	readOutput(p,&n,&avg_tat,&avg_wt);
	
	//just for checking:-
	display(p,n);
	printf("average TAT = %.2f ms\n",avg_tat);
	printf("average WT= %.2f ms\n",avg_wt);
	
}