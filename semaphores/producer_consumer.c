#include<pthread.h>
#include<stdio.h>
#define BSIZE 4
#define NUMITEMS 30
#define NUM_THREADS 2
typedef struct{
	char buf[BSIZE];
	int occupied;
	int nextin, nextout;
	pthread_mutex_t mutex;
	pthread_cond_t more;
	pthread_cond_t less;
}buffer_t;
buffer_t buffer;
void * producer(void *);
void * consumer(void *);
pthread_t tid[NUM_THREADS];
int main(void)
{
	int i;
	pthread_cond_init(&(buffer.more),NULL);
	pthread_cond_init(&(buffer.less),NULL);
	pthread_create(&tid[i],NULL,consumer,NULL);
	pthread_create(&tid[i],NULL,producer,NULL);
	for(i=0; i<NUM_THREADS; i++)
	{
		pthread_join(tid[i], NULL);
		printf("\nmain() reporting that all threads of %d have terminated\n",i);
	}
	return 0;
}
void * producer(void *parm)
{
	char item[NUMITEMS] = "Its a small world";
	int i;
	printf("Producer started\n");
	for(i=0; i<NUMITEMS; i++)
	{
		if(item[i] == '\0')
			break;
		if(buffer.occupied >= BSIZE)
			printf("Producer waiting\n");
		while(buffer.occupied >= BSIZE)
			pthread_cond_wait(&(buffer.less),&(buffer.mutex));
		printf("Producer executing\n");
		sleep(1);
		buffer.buf[buffer.nextin++] = item[i];
		buffer.nextin %= BSIZE;
		buffer.occupied++;
		pthread_cond_signal(&(buffer.more));
		pthread_mutex_unlock(&(buffer.mutex));
	}
	printf("Producer exiting\n");	
	pthread_exit(0);
}
void * consumer(void *parm)
{
	char item;
	int i;
	printf("Consumer started\n");
        printf("Producer started\n");
        for(i=0; i<NUMITEMS; i++)
        {
		pthread_mutex_lock(&(buffer.mutex));
                if(buffer.occupied <= 0)
                        printf("Consumer waiting\n");
                while(buffer.occupied <= 0)
                        pthread_cond_wait(&(buffer.more),&(buffer.mutex));
                printf("Consumer executing\n");
		sleep(1);
                item = buffer.buf[buffer.nextout++];
		printf("%c\n",item);
                buffer.nextout %= BSIZE;
                buffer.occupied--;
                pthread_cond_signal(&(buffer.less));
                pthread_mutex_unlock(&(buffer.mutex));
        }
        printf("Consumer exiting\n");
        pthread_exit(0);
}
