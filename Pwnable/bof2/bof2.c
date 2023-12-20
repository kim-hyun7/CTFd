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


int main(int argc, char *argv[])
{
    char buf[0x30];
    init();
    printf("Address of buf : %p\n", buf);

   


    read(0, buf, 100);
    printf("%s", buf);

    return 0;
}
