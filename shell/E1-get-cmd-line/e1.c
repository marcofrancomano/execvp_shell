#include "e1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void get_cmd_line(char* argv[MAX_TOKENS]) {
    char* temp = (char*) malloc(sizeof(char) * MAX_LINE);
    fgets(temp, MAX_LINE, stdin);
    char* token = strtok(temp, " \t\n");
    int i = 0;
    for(i; i < MAX_TOKENS && token != NULL; i++) {
        argv[i] = (char*) malloc(strlen(token) + 1);
        strcpy(argv[i], token);
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
}
	
