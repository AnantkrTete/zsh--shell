#include <stdio.h>
#include "my_shell.h"

//shell loop
//input parsing

//echo,cd , pwd, env, setenv, unsetev, which, exit
int shell_builts(char** args, char** env, char* initial_directory){
    // printf("Args: %s",args[0]);
    // printf("\n"); 
    if(my_strcmp(args[0],"cd") == 0){
        // return command_cd(args,initial_directory);
    }else if(my_strcmp(args[0],"pwd") == 0){
        // return command_pwd();
    }
    else if(my_strcmp(args[0],"echo") == 0){
        // return command_echo(args,env);
    }
    else if(my_strcmp(args[0],"env") == 0){
        // return command_env(env);
    }
    else if(my_strcmp(args[0],"which") == 0){
        // return command_which(args,env);
    }
    else if(my_strcmp(args[0],"exit") == 0 || my_strcmp(args[0],"quit")== 0){
        printf("I am exiting");
        exit(EXIT_SUCCESS); 
    }
    else{
        //not a builtin command 
    }
      
}

void shell_loop(char** env){
    char* input = NULL;
    size_t input_size =0;

    char** args;

    char* initial_directory = getcwd(NULL,0);

    while(1)
    {   
        printf("[my_shell]>");
        if(getline(&input, &input_size, stdin) == -1)
        { // end of file,ctrl+D
            perror("getline");
            break;
        }    
        // printf("input:%s", input);
        
        args = parse_input(input);

        for (size_t i = 0; args[i]; i++)
        {
            printf("Args: %s",args[i]);  
            printf("\n");  
        }
        
        if(args[0] != NULL){
            shell_builts(args, env, initial_directory);
        }
        free_tokens(args);
    } 
}


int main(int argc, char** argv, char** env){
    (void)argc;
    (void)argv;

    shell_loop(env);

    return 0;
}