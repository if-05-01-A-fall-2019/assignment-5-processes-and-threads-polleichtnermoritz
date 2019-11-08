#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1000

char **convert_command(char *);

int main() {
    int status;
    char input[MAX_INPUT_LENGTH];
    char* sepChar;
    char **cmd;
    char* delimiter = "&";
       
    printf("Enter command: ");

    scanf("%s", input);

    //parts the string
    sepChar = strtok(input, delimiter);

    while(sepChar != 0) {
        cmd = convert_command(sepChar);

        if (fork() != 0) 
        {
            //waits for the process to change (-1 = waits for any child process)
            waitpid(-1, &status, 0);
        } else 
        {
            //executes the given command
            execvp(cmd[0], cmd);
        }    

        sepChar = strtok(0, delimiter);
        free(cmd);
    }

    free(cmd);
    
    return 0;
}

char **convert_command(char *input) {
    int i = 0;
    char **cmd = malloc(10 * sizeof(char *));
    char *parsed;
    char* sepChar = " ";

    parsed = strtok(input, sepChar);

    while (parsed != 0) {
        cmd[i] = parsed;
        parsed = strtok(0, sepChar);
        i++;
    }

    cmd[i] = 0;
    return cmd;
}
