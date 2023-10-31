#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <stdlib.h>

#define N			7
#define Repetitions		20
#define LEFT			((i + N - 1) % N)
#define RIGHT			(i % N)
#define THINKING		0
#define EATING			3

static int			state[N];
static pthread_mutex_t		mutex;
static pthread_cond_t		cond;

static void 		take_forks(int);
static void 		put_forks(int);
static void 		testPhilosopher(int); 
static void 		eat(int);
static void 		think(int);
static void 		*philosopher(void*);

static void eat(int i) {
	int status;
	//printf("hello from Eat subroutine\n");
	int newi;
	newi = i + 1;
	printf("Philosopher %d is eating............\n", newi);	
	/*create a bash command to run*/
	char command[50];
	sprintf(command, "echo 'Philosopher #%d is eating\n' >> output.txt", newi);

	/*run the command*/
	status = system(command);
	//sleep(2);
}

static void think(int i) {
	int status;
	int newi;
	newi = i + 1;
	//printf("thinking subroutine\n");
	printf("Philosopher %d is thinking...\n", newi);	
	//sleep(2);
	
	/*create a bash command to run*/
	char command[50];
	sprintf(command, "echo 'philosopher #%d is thinking\n' >> output.txt", newi);

	/*run the command*/
	status = system(command);
}

static void *philosopher(void* arg) {
	int j;                                     
	//printf("hello from philosper sub\n");
    	for(j = 0; j < Repetitions; j++)
    	{                                                     
        	//printf("hello from for loop\n");
        	think((int)arg);
		take_forks((int)arg);
		eat((int)arg);
		put_forks((int)arg);
	}
	
	}

static void take_forks(int i) {
	//printf("hello from take forks\n");
	pthread_mutex_lock(&mutex);
	//printf("before testPhilosopher %d.....\n", i);
	testPhilosopher(i);
	//printf("after testPhilosopher %d.....\n", i);
	pthread_mutex_unlock(&mutex);
}

static void put_forks(int i) {
	int status;
	int newi;
	newi=i+1;
	pthread_mutex_lock(&mutex);
	state[LEFT] = THINKING;
	state[RIGHT] = THINKING;
	pthread_cond_signal(&cond);
	printf("Philosopher %d, put forks down....\n", i+1);
	
	/*create a bash command to run*/
	char command[75];
	sprintf(command, "echo 'Philosoper %d, has put forks down....\n' >> output.txt", i+1);

	/*run the command*/
	status = system(command);
	
	pthread_mutex_unlock(&mutex);
}

static void testPhilosopher(int i) {
		int status;
		
		while (state[LEFT] == EATING || state[RIGHT] == EATING) {
		printf("Philosopher %d, is hungry and is trying to pick up forks...., left = %d, right = %d\n", i+1, LEFT+1, RIGHT+1);
		/*create a bash command to run*/
    		char command[100];
		sprintf(command, "echo 'Philosopher %d, is hungry and is trying to pick up forks...., left = %d, right = %d\n' >> output.txt", i+1, LEFT+1, RIGHT+1);

		/*run the command*/
		status = system(command);
		
		pthread_cond_wait(&cond, &mutex);
		
	state[LEFT] = EATING;
	state[RIGHT] = EATING;
}
	
int main() {
	int res;
	pthread_t a_thread[N];
	void *thread_result;
	//printf("hello1\n");
	res = pthread_mutex_init(&mutex, NULL);
	if (res != 0) {
		perror("Mutex initialization failed.");
		exit(-1);
	}
	//printf("hello2\n");
	res = pthread_cond_init(&cond, NULL);
	if (res != 0) {
		perror("Condition initialization failed.");
		exit(-1);
	}
	//printf("hello3\n");
	for (int i = 0; i < N; i++)
		res = pthread_create(&a_thread[i], NULL, philosopher, (void*)i);	

	if (res != 0) {
		perror("Thread creation failed.");
		exit(-1);
	}

	//printf("hello4\n");
	for (int i = 0; i < N; i++)
		res = pthread_join(a_thread[i], &thread_result);

	if (res != 0) {
		perror("Thread join failed.");
		exit(-1);
	}

	printf("Done with Repetitions\n");
}
