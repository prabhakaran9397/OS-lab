#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
	int pid,st,ft,prior;
	int wt,tat,at,bt;
	int flag;
}pr;

int n,avail[10],s=0;
pr p[10];
void accept(int);
void fcfs();
void disp_gantt_();
void disp_gantt();
void sjf_sort();
void priority_sort();
void round_robin(int);
void fcfs_sort();

int main(int args,char *argv[])
{
	printf("\n\t\t**Scheduling Algorithms**");
	int ch,tq;
	do
	{
		printf("\n->(1) FCFS\n->(2) SJF\n->(3) Priority Based\n->(4) Round Robin\n->(5) Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: accept(ch);
				fcfs();
				break;
			case 2:
				accept(ch);
				sjf_sort();
				fcfs();
				break;
			case 3:
				accept(ch);
				priority_sort();
				fcfs();
				break;
			case 4: printf("\nEnter the Time Quantum: ");
				scanf("%d",&tq);
				accept(ch);
				fcfs_sort();
				round_robin(tq);
				break;
			case 5:
				break;
		}
		printf("\n\n\n");
	}while(ch!=5);
}

void accept(int ch)
{
	int i;
	printf("\nHow many processes: ");
	scanf("%d",&n);
	printf("\nEnter the values");
	if(ch==1 || ch==2)
	{
		printf("\nArrival Time and Burst Time\n");
		for(i=0;i<n;i++)
		{
			printf("Enter for Process %d: ",i);
			scanf("%d%d",&p[i].at,&p[i].bt);
			p[i].pid=i;
		}
	}
	else if(ch==3)
	{
		printf("\nArrival Time, Burst Time and Priority\n");
		for(i=0;i<n;i++)
		{
			printf("Enter for Process %d: ",i);
			scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].prior);
			p[i].pid=i;
			p[i].at=0;
		}
	}
	else if(ch==4)
	{
		printf("\nArrival Time and Burst Time\n");
		for(i=0;i<n;i++)
		{
			printf("Enter for Process %d: ",i);
			scanf("%d%d",&p[i].at,&p[i].bt);
			p[i].pid=i;
		}
	}
}

void fcfs_sort()
{
	int i,j;
	pr temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;

			}
		}
	}
}

void fcfs()
{
	int i;
	float avgtat=0,avgwt=0;
	fcfs_sort();
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			p[i].st=p[i].at;
			p[i].wt=p[i].st-p[i].at;
			p[i].tat=p[i].wt+p[i].bt;
			p[i].ft=p[i].st+p[i].bt;
		}
		else
		{
			if(p[i-1].ft>=p[i].at)
			{
				p[i].st=p[i-1].ft;
			}
			else
			{
				p[i].st=p[i].at;
			}
			p[i].wt=p[i].st-p[i].at;
			p[i].tat=p[i].wt+p[i].bt;
			p[i].ft=p[i].st+p[i].bt;
		}
		avgtat=avgtat+p[i].tat;
		avgwt=avgwt+p[i].wt;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	disp_gantt(n);
	printf("\n Average Turn Around Time: %0.4f",avgtat);
	printf("\n Average waiting time: %0.4f",avgwt);
}
void disp_gantt_()
{
	int i;
	printf("\n\tGANTT CHART");
	for(i=0;i<n;i++)
	{
		printf("\t P%d",p[i].pid);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\t %d",p[i].st);
	}
	printf("\t %d",p[i-1].ft);
	printf("\n");
}
void disp_gantt()
{
	int i,t=0;
	printf("\n\tGANTT CHART");
	for(i=0;i<n;i++)
	{
		printf("\nP%d from ",p[i].pid);
		printf("%d to %d",p[i].st,p[i].ft);
	}
	printf("\n");
}
void sjf_sort()
{
	int i,j;
	pr temp;
	for(i=0;i<n;i++)
	{
		p[i].at=0;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i-1;j++)
		{
			if(p[j].bt>p[j+1].bt)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;

			}
		}
	}
}
void priority_sort()
{
	int i,j;
	pr temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].prior>p[j+1].prior)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;

			}
		}
	}
}

void round_robin(int tq)
{
	int allterminate=0,cnt=0,i;
	int gt[30],ps[30],temp=0,pcnt=0;
	float avgtat=0;
	printf("\n\tGANTT CHART\n\n");
	while(allterminate<n)
	{
		for(i=0;i<n;i++)
		{
			if(p[i].flag==0) //process incomplete
			{
				p[i].st=temp;
				cnt++;
				if(p[i].bt>=tq)//burst time > time slice
				{

					p[i].bt=p[i].bt-tq;
					temp=temp+tq;
					gt[cnt]=temp;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}
				else
				{ //burst time < time slice
					temp=temp+p[i].bt;
					gt[cnt]=temp;
					p[i].bt=0;
					ps[pcnt]=p[i].pid;
					pcnt++;
				}

				if(p[i].bt==0)
				{
					allterminate++;
					p[i].flag=1;
					p[i].ft=temp;
				}

				if(p[i].flag==1)
				{
					p[i].tat=p[i].ft;
					avgtat=avgtat+p[i].tat;
				}
			}//if

		}//for

	}//while
	for(i=0;i<pcnt;i++)
	{
		printf("\t  P%d",ps[i]);
	}
	printf("\n\t0\t");
	for(i=1;i<=cnt;i++)
	{
		printf("%d\t",gt[i]);
	}
	avgtat=avgtat/n;
	printf("\n\t** Average Turn Around Time:%f **",avgtat);
}
