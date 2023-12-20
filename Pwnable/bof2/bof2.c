#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char buf[0x30];

    printf("Address of buf : %p\n", buf);

   


    read(0, buf, 100);
    printf("%s", buf);

    return 0;
}
