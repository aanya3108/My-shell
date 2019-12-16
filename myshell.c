#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include "date.c"
#include "cat.c"
//#include "mkdir.c"
#include "rm.c"
#include "ls.c"


#define MEM 1024
	char* history[100];
		int a=0;


char* read_line()
{
	int b = MEM;
	
	char* line2;
	line2 = (char*)malloc(b);
	scanf("%s",line2);
	return line2;
}
int geti(int i)
{
	return i;
}

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

int execute(char** line,int i)
{

	pid_t child_pid;
	char *input;
    int stat_loc;
	int ret;

	if(strcmp(line[0],"pwd")==0)
	{
		char abc[100];
		child_pid = fork();

		if (child_pid == 0) 
		{
	        char* path=getcwd(abc,sizeof(abc));
			if(path!=NULL)
			{
				printf("%s\n",abc);
			}
        }

        else 
        {
            waitpid(child_pid, 0, WUNTRACED);
        }
      //  history
		
		return 0;
	}


    else if(strcmp(line[0],"cat")==0)
    {
    	cat(line);
        return 0;
    }

	else if(strcmp(line[0],"ls")==0)
	{
		ls(line);
		return 0;

	}

	else if(strcmp(line[0],"date")==0)
	{
        imp_date(line);	       
        return 0;
	}

	else if(strcmp(line[0],"rm") == 0)
    {

        rm(line);
        return 0;
    }
	
	else if(strcmp(line[0],"mkdir")==0)
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
        
        return 0;
    }

    else if(strcmp(line[0],"history") == 0)
    {
        int i = 0;

        while(history[i] != NULL)
        {
        	//printf("%d\n",i );
            printf("%s\n", history[i]);
            i++;   
        }
    }

    else if(strcmp(line[0],"cd")==0)
    {
			char abc[100];
	        char* path=getcwd(abc,sizeof(abc));
			if(path!=NULL)
			{
				printf("%s\n",abc);
			}
			chdir(line[1]);

	        path=getcwd(abc,sizeof(abc));

			if(path!=NULL)
			{
				printf("%s\n",abc);
			}

    
    	 return 0;
    }

    else if(strcmp(line[0],"echo")==0)
	{
		char abc[100];
		child_pid = fork();

		if (child_pid == 0) 
		{
	       if(strcmp(line[1],"-E")==0)
			{
				for (int j = 2; j < i; ++j) 
			        printf("%s", line[j]);
			   	printf("\n");
			}

			else
			{				
				for (int j = 1; j < i; ++j) 
			        printf("%s ", line[j]);
			    printf("\n");
			}
        }

        else
        {
            waitpid(child_pid, 0, WUNTRACED);
        }
        return 0;

	}

	else if(strcmp(line[0],"exit")==0)
	{
		return 1;
	}


}
int main()
{
	printf("SIMPLE SHELL: Type 'exit' or send EOF to exit.\n");
	
	//load configuration files
	//run command loop
	//shutdown/cleanup
	//terminate
	char* line;
	int i=0;
	line = (char*)malloc(1024);
	int status=0;
	char buf[1024];

	while(status==0)
	{

		printf("> ");
		scanf("%[^\n]%*c", buf);
		
	//	printf("in" );
	//	char pos = buf;
		history[a] = buf;
		a++;

	//	printf("%s\n",buf);
	    int i = 0;
	    char *p = strtok (buf, " ");
	    char *array[100];

	    while (p != NULL)
	    {
	        array[i] = p;
	        p = strtok (NULL, " ");
	        i++;
	    }

	//    geti(i);
		status=execute(array,i);
	}

}

//execl("/bin/date","date",0,(char*)0 );

/*void loop(void)
{
	char* line;
	line = (char*)malloc(1024);
	char **args;
	args=(char**)malloc(1024);
	int status=1;

	do
	{
				line = read_line();
		
		args = splitline();
		status = execute(args);
		free(line);
		free(args);

	}while(status);

}*/

