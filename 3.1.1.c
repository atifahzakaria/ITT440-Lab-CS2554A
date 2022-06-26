#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void){
   void sigint_handler(int sig);
   void sigtstp_handler(int tt);
   void sigq_handler(int q);
   char s[200];

   if(signal(SIGINT, sigint_handler) == SIG_ERR){
        perror("signal");
        exit(1);}
   if(signal(SIGTSTP, sigtstp_handler) == SIG_ERR){
	perror("signal");
	exit(1);}
   if(signal(SIGQUIT, sigq_handler) == SIG_ERR){
	perror("signal");
	exit(1);} 

   printf("Enter a string:\n");

   if(fgets(s, 200, stdin) == NULL)
        perror("gets");
   else
        printf("You entered: %s\n", s);

   return 0;
}

void sigint_handler(int sig){
   printf("This is a special signal handler for <SIGINT>");}

void sigtstp_handler(int tt){
   printf("This is a special signal handler for <SIGTSTP>)");}

void sigq_handler(int q){
   printf("This is a special signal handler for <SIGQUIT>");}
