#define NUM_READ 5
#define NUM_WRIT 5
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t mutex;
sem_t db;
int reader_count = 0;
int reader_name[NUM_READ];
int writer_name[NUM_WRIT];
void * reader(void *);
void * writer(void *);
int main(void)
{
	int i;
	pthread_t readers[NUM_READ];
	pthread_t writers[NUM_WRIT];
	for(i=0; i<NUM_READ; i++)
		reader_name[i]=i+1;
        for(i=0; i<NUM_WRIT; i++)
                writer_name[i]=i+1;
	if((sem_init(&mutex,0,1))<0)
		perror("ERROR");
	if((sem_init(&db,0,1))<0)
                perror("ERROR");
	for(i=0; i<NUM_READ; i++)
		if((pthread_create(&readers[i],NULL,reader,&reader_name[i]))!=0)
			perror("ERROR");
        for(i=0; i<NUM_WRIT; i++)
                if((pthread_create(&writers[i],NULL,writer,&writer_name[i]))!=0)
                        perror("ERROR");
        for(i=0; i<NUM_READ; i++)
                if((pthread_join(readers[i],NULL))!=0)
                        perror("ERROR");
        for(i=0; i<NUM_WRIT; i++)
                if((pthread_join(writers[i],NULL))!=0)
                        perror("ERROR");
	sem_destroy(&mutex);
	sem_destroy(&db);
	return 0;
}
void * reader(void *n)
{
	int i = (*(int *)n);
	if((sem_wait(&mutex))<0)
		 perror("ERROR");
	reader_count++;
	if(reader_count == 1)
		if((sem_wait(&db))<0)
			perror("ERROR");
	if((sem_post(&mutex))<0)
		perror("ERROR");
	printf("Reader %d is reading\n",i);
	sleep(3);
        if((sem_wait(&mutex))<0)
                perror("ERROR");
	reader_count--;
	if((sem_post(&mutex))<0)
                perror("ERROR");
	if(reader_count == 0)
		if((sem_post(&db))<0)
                	perror("ERROR");
}
void * writer(void *n)
{
	int i = (*(int *)n);
	printf("Writer %d is waiting\n",i);
        if((sem_wait(&db))<0)
                 perror("ERROR");
	printf("Writer %d is writing\n",i);
	sleep(2);
	if((sem_post(&db))<0)
                 perror("ERROR");
}
