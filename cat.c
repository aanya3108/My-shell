#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h> 

void cat(char** line)
 {
 	int ret;
        pid_t child_pid = fork();

        if(child_pid == 0)
        {
            ret = execl("/bin/cat", "cat", line[1], (char *)0);
        }
        else
        {
            waitpid(child_pid,0,WUNTRACED);
        }
  }