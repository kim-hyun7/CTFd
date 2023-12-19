#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler() {
    puts("TIME OUT");
    exit(-1);
}

void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    signal(SIGALRM, alarm_handler);
    alarm(10);
}


void get_flag(){
    system("/bin/bash");  
}

int main(int argc, char *argv[])
{
    char buf[0x30];

    init();


    printf("you can do it!\n");
    scanf("%s", buf);
    printf("%s\n", buf);
    return 0;
}
