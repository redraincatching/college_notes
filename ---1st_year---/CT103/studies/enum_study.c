#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_status();
void wait(int delay);

enum status {idle, busy, asleep, maintenance};

void main() {
    while(1){
        switch (get_status()){
        case idle:
            puts("system idle - can accept input");
            break;
        case busy:
            puts("system busy, please wait");
            break;
        case asleep:
            puts("system asleep, initiating startup");
            break;
        case maintenance:
            puts("system undergoing maintenance, please wait");
            break;
        }
        wait(10);
    }
}

int get_status(){
    srand(time(NULL));
    return rand() % 4;
}

void wait(int delay) {
    long t = time(NULL);
    long tplus = t + delay;
    long tplusone = t + 1;

    while (t<tplus) {
        if (t == tplusone) {    // print a dot every second
            printf(".");
            tplusone = t +  1;
        }
        t = time(NULL);
    }
}
