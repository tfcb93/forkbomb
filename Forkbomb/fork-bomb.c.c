/*This code was created in 2014
with the propose to learn about threads in a fun way
This code just run in Unix-based systems
created by Thiago Borges
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