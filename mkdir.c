 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void mkdir(char** line)
{
        int ret;
        pid_t child_pid = fork();
         int stat_loc;
        

        if(child_pid == 0)
        {
            ret = execl("/bin/mkdir", "mkdir", line[1], (char *)0);
        }
        else
        {
            waitpid(child_pid,0,WUNTRACED);
        }

}