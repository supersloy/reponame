#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *PrintHello(int i) {
	sleep(1); 		//Proof that threads is made subsequently
	printf("Hello from thread %d - I was created in iteration %d !\n",
		(int) pthread_self(), i);
	pthread_exit(NULL);
}

int main(int argc, char * argv[]) {

	int N;
	printf("Write amount of threads (N): ");
	scanf("%d", &N);
	pthread_t thread_id[N];

	int rc, i;
	for (i = 0; i < N; i++) {
		rc = pthread_create(&thread_id[i], NULL, PrintHello, i);
		if (rc) {
			printf("\nERROR: return code from pthread_create is %d \n", rc);
			exit(1);
		}
		printf("\nI am thread %d. Created new thread (%d) in iteration %d ...\n",
			(int) pthread_self(), (int) thread_id[i], i);
		pthread_join(thread_id[i], NULL);
	}

	printf("\nP.S. Thread ids are the same because program wait till the thread is terminated before making new one. Therefore new thread id may be the same.\n");
	pthread_exit(NULL);
}
