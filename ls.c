#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

void ls(char** line)
{
		int ret;
        pid_t child_pid;
         int stat_loc;
		
		if(strcmp(line[1],"-l")==0)
		{
		    child_pid = fork();
		    
			if (child_pid == 0) 
			{
	           ret = execl ("/bin/ls", "ls", "-1", (char *)0);
	        }
	        else
	        {
	            waitpid(child_pid, &stat_loc, WUNTRACED);
	        }	
		}
		else
		{
			child_pid = fork();

			if (child_pid == 0) 
			{
	           ret = execl ("/bin/ls", "ls", 0, (char *)0);
	        }
	        else
	        {
	            waitpid(child_pid, &stat_loc, WUNTRACED);
	        }	
		}

}