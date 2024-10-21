/*
Code created in 2014.
The purpose of this code was to learn more about threads and forks in a fun way.
This code only runs in Unix-based systems, as far as I remember.
Don't be evil. Use it for the good.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

void *bunno();
void *dunno();


void *dunno(){
	for(;;){
		pthread_t tt;
		pthread_create(&tt,NULL,bunno,NULL);
		pthread_join(tt,NULL);
	}
}

void *bunno(){

	for(;;){
			pid_t pid;
			pid =fork();
			dunno();
			wait(0);
		}
}

int main(){
	pid_t pid;
	pid =fork();
	if(pid > 0){
		bunno();
	}
	if(pid == 0){
		dunno();
	}
	return 0;

}
