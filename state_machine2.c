#include <stdio.h>
#include <stdlib.h>


enum states {
        START,
        LOOP,
        END,
} state;

enum events {
        START_LOOPING,
        PRINT_HELLO,
        STOP_LOOPING,
};


typedef enum states (*event_handler)(enum states, enum events);

enum states start_looping(enum states state, enum events event){
        return LOOP;
}

enum states print_hello(enum states state, enum events event){
        printf("Hello World! \n");
        return LOOP;
}
enum states stop_looping(enum states state, enum events event){
        return END;
}

event_handler transitions[STOP_LOOPING+1][END+1] = {
        [START] = { [START_LOOPING] = start_looping, },
        [LOOP] = { [PRINT_HELLO] = print_hello,
                    [STOP_LOOPING] = stop_looping, },
};

void step_state(enum events event){
        event_handler handler = transitions[state][event];
        if(!handler)
                exit(1);
        state = handler(state, event);
}
int main(void){
        step_state(START_LOOPING);
        step_state(PRINT_HELLO);
        step_state(PRINT_HELLO);
        step_state(STOP_LOOPING);
        return 0;
}

