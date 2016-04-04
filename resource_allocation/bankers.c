#include<stdio.h>
#define SIZE 15
int main(void)
{
	int allocated[SIZE][SIZE];
	int max[SIZE][SIZE];
	int need[SIZE][SIZE];
	int avail[SIZE];
	int tres[SIZE]; 
	int work[SIZE]; 
	int flag[SIZE];
	int sequence[SIZE];
	int pno, rno, i, j, proc, count, total;
	count = 0;
	printf("Enter the number of Process: ");
	scanf("%d",&pno);
	printf("Enter the number of Resources: ");
	scanf("%d",&rno);
	for(i=1; i<=pno; i++)
		flag[i] = 0;
	printf("Enter total number of each resources: ");
	for(i=1; i<=rno; i++)
		scanf("%d",&tres[i]);
	printf("Enter the max resources for each Process: \n");
	for(i=1; i<=pno; i++)
	{
		printf("Process %d: ",i);
		for(j=1; j<=rno; j++)
			scanf("%d",&max[i][j]);
	}
	printf("Enter Allocated resources for each process: \n");
	for(i=1; i<=pno; i++)
	{
		printf("Process %d: ",i);
		for(j=1; j<=rno; j++)
			scanf("%d",&allocated[i][j]);
	}
	printf("Available resources: ");
	for(j=1; j<=rno; j++)
	{
		avail[j] = 0;
		total = 0;
		for(i=1; i<=pno; i++)
			total += allocated[i][j];
		avail[j] = tres[j]-total;
		work[j] = avail[j];
		printf("%d  ",work[j]);
	}
	do
	{
		for(i=1; i<=pno; i++)
			for(j=1; j<=rno; j++)
				need[i][j] = max[i][j] - allocated[i][j];
		printf("\nAllocated Matrix       Max            Need");
		for(i=1; i<=pno; i++)
		{
			putchar(10);
			for(j=1; j<=rno; j++)
				printf("%4d",allocated[i][j]);
			printf("    |");
			for(j=1; j<=rno; j++)
				printf("%4d",max[i][j]);
			printf("    |");
			for(j=1; j<=rno; j++)
				printf("%4d",need[i][j]);
		}
		proc = 0;
		for(i=1; i<=pno; i++)
		{
			if(flag[i] == 0)
			{
				proc = i;
				for(j=1; j<=rno; j++)
					if(work[j]<need[i][j])
					{
						proc = 0;
						break;
					}
			}
			if(proc!=0)
				break;
		}
		if(proc!=0)
		{
			printf("\nProcess %d completed!",proc);
			sequence[count++] = proc;
			printf("\nAvailable matrix: ");
			for(j=1; j<=rno; j++)
			{
				work[j] += allocated[proc][j];
				allocated[proc][j] = 0;
				max[i][j] = 0;
				flag[proc] = 1;
				printf("%d  ",work[j]);
			}
		}
		sleep(1);
	}while(count!=pno && proc!=0);
	for(i=1; i<=pno; i++)
		for(j=1; j<=rno; j++)
			need[i][j] = max[i][j] - allocated[i][j];
	printf("\nLast state fo the Matrix\n");
	printf("\nAllocated Matrix       Max            Need");
	for(i=1; i<=pno; i++)
	{
		putchar(10);
		for(j=1; j<=rno; j++)
			printf("%4d",allocated[i][j]);
		printf("    |");
		for(j=1; j<=rno; j++)
			printf("%4d",max[i][j]);
		printf("    |");
		for(j=1; j<=rno; j++)
			printf("%4d",need[i][j]);
	}
	if(count == pno)
	{
		printf("\nSystem is safe, No deadlock!\n");
		for(i=0; i<count; i++)
		{
			printf("%d",sequence[i]);
			if(i<count-1)
				printf("->");
		}
		putchar(10);
	}
	else
		printf("\nSystem is unsafe, Deadlock occured!\n");
	return 0;
}
