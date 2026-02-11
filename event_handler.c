#include <stdio.h>

typedef void (*event_handler)(int event_code);

void handle_connect(int event_code){
        printf("connect event %d\n", event_code);
}

void handle_disconnect(int event_code){
        printf("disconnect event %d\n", event_code);
}

struct entry {
        int event_code;
        event_handler handler;
};

void dispatch_event(struct entry *table, size_t count, int event_code){
        for(size_t i = 0; i < count; i++){
                if (table[i].event_code == event_code){
                        table[i].handler(event_code);
                        return;
                }
        }
        printf("no handler for event %d\n", event_code);
}

int main(void){
        struct entry handlers[] = {
                {1, handle_connect},
                {2, handle_disconnect}
        };
        dispatch_event(handlers, 2, 1);
        dispatch_event(handlers, 2, 2);
        dispatch_event(handlers, 2, 3);
        return 0;
}
