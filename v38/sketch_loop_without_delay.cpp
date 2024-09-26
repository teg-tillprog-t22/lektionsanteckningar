#include<stdio.h>
#include<unistd.h>
#include<time.h>

const int numbers[] = {1975, 2, 28};
const int number_count = 3;

// I vanliga C++ finns det ingen millis()-funktion,
// men vi kan göra en egen med hjälp av funktionen clock
unsigned long millis() {
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}

void setup() {
    printf("Startar");
}

void loop() {
    // En "static" variabel kan fungera istället för en
    // global om värdet enbart behövs inne i funktionen
    static int current_index = 0;

    unsigned long current_time = millis();
    
    // Vi vill uppnå något i stil med:
    // if ( det har gått 10000ms sen senast vi gjorde något ) så
    {
        if (current_index>number_count)
            current_index = 0;

        printf("%d\n", numbers[current_index]);

        current_index++;
    }
}

// Den här funktionen gör att ett vanligt C++-program fungerar
// ungefär som i Ardunio-ramverket. Först körs setup() en gång,
// därefter körs loop() i all evighet.
int main() {
    setup();
    while(true) {
        loop();
    }
}
