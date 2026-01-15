#include <stdio.h>
#include "my_shell.h"
//shell loop
//input parsing

//echo,cd , pwd, env, setenv, unsetev, which, exit
int shell_builts(char** args, char** env, char* initial_directory){
    if(strcmp(args[0],"cd")){
        return command_cd(args,initial_directory);
    }else if(strcmp(args[0],"pwd")){
        return command_pwd();
    }
    else if(strcmp(args[0],"echo")){
        return command_echo(args,env);
    }
    else if(strcmp(args[0],"env")){
        return command_env(env);
    }
    else if(strcmp(args[0],"which")){
        return command_which(args,env);
    }
    else if(strcmp(args[0],"exit") || strcmp(args[0],"quit")){
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

        // for (size_t i = 0; args[i]; i++)
        // {
        //     printf("Args: %s",args[i]);  
        //     printf("\n");  /* code */
        // }
        
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