#include <stdio.h>

void log_message(const char *text){
        printf("log: %s\n", text);
}

int main(void){
        void (*logger)(const char*) = NULL; // means no function for this slot

        if(logger) {
                logger("Startup");
        }
        // should do nothing for the above case

        logger = log_message;// pointer assigned

        if(logger) {
                logger("running");
        }
        return 0;
}
