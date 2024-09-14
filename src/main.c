#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_WORD   100
#define NUM_WORDS  1

int main(){
    char answer[50];
    char yesno[5];

    FILE *fp = fopen("/usr/local/bin/8ball.txt", "r");

    if (fp == NULL) {
        perror("unable to locate answers");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD];
    long wc = 0;
    while (fgets(word, sizeof word, fp) != NULL) {
        ++wc;
    }

    char randwords[NUM_WORDS][MAX_WORD];
    srand((unsigned) time(NULL));
    for (size_t i = 0; i < NUM_WORDS; i++) {
        rewind(fp);
        int sel = rand() % wc + 1;
        for (int j = 0; j < sel; j++) {
            if (fgets(word, sizeof word, fp) == NULL) {
                perror("Error in fgets()");
            }
        }
        strcpy(randwords[i], word);
    }

    if (fclose(fp) != 0) {
        perror("unable to close file");
    }

    printf("what would you like answered today?:\n");
    scanf("%[^\n]%*c", answer);
    printf("you asked: '%s', correct? (yes/no):\n", answer);
    scanf("%s", yesno);

    if(!strcmp(yesno, "yes")) {
        printf("thinking...\n");
        sleep(3);
        printf("the 8 ball has decided!\n");
        sleep(1);
        for (size_t i = 0; i < NUM_WORDS; i++) {
        printf(">> %s", randwords[i]);} 
    }

    if(!strcmp(yesno, "no")) {
        printf("understood, exiting.\n");
        sleep(1);
        printf("have a good day!\n");
        return 0;
    }
}
