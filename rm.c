
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void rm(char** line)
{
	pid_t child_pid;
	char *input;
    int stat_loc;
	int ret;

	child_pid = fork();

        if(child_pid == 0)
        {
            ret = execl("/bin/rm", "rm",line[1], (char *)0);
        }
        else
        {
            waitpid(child_pid,0,WUNTRACED);
        }
   //  return 0;
 }

