
//!!! I did not include sleep commands between each step in the code because it only make execution longer while provide the same result.
//(Errors will be in any case whether code contain additional sleep comands or not.) 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1
#define false 0
#define BUFFER_SIZE 100

int itemCount = 0;
int producerAsleep = false;
int consumerAsleep = false;

//Most part of producer and consumer code from https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem.
void *producer() 
{
    while (true) 
    {
    	if(!producerAsleep)
        {
        	if (itemCount == BUFFER_SIZE) 
        	{
        		printf("Amount of items reach the buffer size(%d). Producer start sleeping.\n", BUFFER_SIZE);
        	    producerAsleep = true;
        	}

        	itemCount = itemCount + 1;
        	printf("Item produced. Current amount of items is: %d\n", itemCount);

        	if (itemCount == 1) 
        	{
        		printf("Amount of items is enough to start consume them(1). Consumer is awaken.\n");
        	    consumerAsleep = false;
        	}
    	}
    }
}

void *consumer() 
{
    while (true) 
    {
    	if(!consumerAsleep)
    	{
        	if (itemCount == 0) 
        	{
        		printf("All items are currently consumed. Consumer start sleeping.\n");
        	    consumerAsleep = true;
        	}

        	itemCount = itemCount - 1;
        	printf("Item consumed. Current amount of items is: %d\n", itemCount);


        	if (itemCount == BUFFER_SIZE - 1) 
        	{
        		printf("There is space for items in the buffer (amount of items = %d). Producer is awaken.\n", BUFFER_SIZE-1);
        		producerAsleep = false;
        	}
        }
    }
}

int main(int argc, char * argv[]) {
	pthread_t thread_id[2];
	printf("Producer start produce items.\n");
	pthread_create(&thread_id[0], NULL, producer, NULL);
	printf("Consumer start consume items.\n");
	pthread_create(&thread_id[1], NULL, consumer, NULL);	
	
	printf("\nP.S. I did not include sleep commands between each step in the code because it only make execution longer while provide the same result.");
	printf("\n(Errors will be in any case whether code contain additional sleep comands or not.) \n");
	pthread_exit(NULL);
}
