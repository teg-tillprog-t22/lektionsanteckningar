#include<cstdio>
#include<unistd.h>

const int numbers[] = {1975, 2, 28};
const int number_count = 3;

void setup() {
    printf("Startar");
}

void loop() {
    // Det här är loopen vi ville ta bort:
    // for(int current_index=0; current_index<number_count; current_index++)
    static int current_index = 0;

    if (current_index>number_count)
        current_index = 0;

    printf("%d", numbers[current_index]);

    current_index++;
}

void main() {
    setup();
    while(true) {
        loop();
    }
}
