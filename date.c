#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include<fcntl.h>
//#define MEM0 1024

void imp_date(char** line)
{
    if(line[1] != NULL)
    {
        if(strcmp(line[1],"-u") == 0)
        {
           int ret;
            pid_t child_pid = fork();
            if(child_pid == 0)
            {
                ret = execl("/bin/date", "date", "-u", (char *)NULL);
            }
            else
            {
                waitpid(child_pid,0,WUNTRACED);
            } 
        }
        else
        {
            int ret;
            pid_t child_pid = fork();
            if(child_pid == 0)
            {
                ret = execl("/bin/date", "date", 0, (char *)NULL);
            }
            else
            {
                waitpid(child_pid,0,WUNTRACED);
            } 
        }
        
    }
    
}
