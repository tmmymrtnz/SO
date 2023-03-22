//en man de fork me dice que tengo que incluir el header:
#include <unistd.h>
//en man de waitpid veo que necesito estos headers:
#include <sys/types.h>
#include <sys/wait.h>
//para printf necesito:
#include <stdio.h>

void type_prompt(){
  printf("$ ");
    printf("l");
    sleep(1);
    printf("s");    
    sleep(1);
    printf("\n");
    sleep(1);
}

//command: ls

int main(){
    //while (1)
        int status;
        setvbuf(stdout, NULL, _IONBF, 0 );

        type_prompt();
        
        printf("Antes del fork \n");
        sleep(5);
    
        //TODO: check -1
    if (fork() != 0){
        //parent
            printf("despues del fork (padre)\n");
             waitpid(-1, &status, 0);
            printf("despues del waitpid\n");
    }
    else{
      //child
            printf("despues del fork (hijo)\n");
            //execve(cmd, params, 0);
            //params es arreglo de strings que termina con NULL
            char *const parmList[] = {"/bin/ls", NULL};
            execve("/bin/ls", parmList, 0);
            printf("despues del execve\n"); //esto nunca se ejecuta!!!!!!
    }
        return 0;
}