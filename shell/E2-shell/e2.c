#include "e2.h"
#include "../E1-get-cmd-line/e1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int do_shell(const char* prompt){
	char** cmds=malloc(MAX_TOKENS*sizeof(char*));
	pid_t pid;
	int status;
	while(1){
		printf("%s:",prompt);
		get_cmd_line(cmds);
		if(cmds[0]==NULL) continue;
		if(!strcmp(cmds[0],"quit")) break;
		pid=fork();
		if(pid==-1) {
			perror("fork failed");
			return EXIT_FAILURE;
		}
		if(pid==0){
			int i=execvp(cmds[0],cmds);
			if(i==-1) {
				printf("error command: %s\n",cmds[0]);
				return EXIT_FAILURE;
			}
			
		}
		int res=wait(&status);
		if(res==-1) {
			perror("wait failed");
			return EXIT_FAILURE;
		}
		//codice di esecuzione
		
	}

}
