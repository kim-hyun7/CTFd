#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

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

int main(){
       
    char userid[11];
    char userpassword[11];
    char inputAdmin[14];
    char inputAdminId[14];
    char inputAdminPass[5];
    char AdminPassword[5] = "1234";

    char registered;
    
    init();
    printf("you registered? [y/n] : ");
    scanf("%c", &registered);
    getchar();
    if (!(registered == 'y' || registered == 'n'))
    {
       printf("wrong.\n");
       exit(0);
    }
    
    if(registered == 'y'){
        sleep(1);
        printf("Plz register..!!\n");
        sleep(1);
        printf("Enter your new id (Id must be no more than 10 characters) : "); 
        fgets(userid , sizeof(userid), stdin);
        printf("Enter your new password (Password must be no more than 10 characters) : ");
        scanf("%s", userpassword);
        getchar();
       
        sleep(1);
        printf("THANK YOU!!\n");

        sleep(1);
        printf("Hello %s\n", userid);
        sleep(1);
        printf("password address : %p\n", userpassword);        
    }
    
    if (registered == 'n') printf("Hello!\n");
    
    sleep(1);
    printf("Hoxy... Are you admin?\n");
    sleep(1);

    printf("Enter admin's Id : ");
    fgets(inputAdminId ,sizeof(inputAdminId), stdin);
    char AdminId[14] = "kimhyunisking";
    if (strcmp(inputAdminId, AdminId) == 0)
    {
        sleep(1);
        printf("First Step Clear!!\n");
        
    }
    else {
        sleep(1);
        printf("Who are you??... Get out.\n");
        exit(0);
    }

    printf("Enter admin's password : ");
    getchar();
    fgets(inputAdminPass, sizeof(inputAdminPass), stdin);
    if (strcmp(inputAdminPass, AdminPassword) == 0 && strcmp(inputAdmin,AdminId) == 0)
    {
        printf("Right Admin's password!!\n");
        sleep(2);
        printf("Authentication Success!\n");
        system("/bin/sh");
    }
    else if (strcmp(inputAdminPass, AdminPassword) == 0)
    {
        sleep(1);
        printf("Right Admin's password!!\n");
        sleep(1);
        printf("What? wait...\n");
        sleep(2);
        printf("Authentication Failed... Bye Bye\n");
    }
    else {
        printf("Wrong!!!! Get out.\n");
        exit(0);
    }
    

}
