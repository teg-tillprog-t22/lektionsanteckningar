// I förra veckan skissade jag på hur vi kan undvika
// anrop till delay()-funktionen i loop() och därmed
// göra exekveringen av funktionen ännu effektivare.
//
// Den fullständiga lösnignen ser ni nedan
// (för att det skall vara en viss utmaning för er
// att överföra koden till Wokwi är den skriven i 
// "vanlig C++")

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

// Vi behöver spara tillfället då vi senast utförde en handling
// för att veta när vi skall göra något nästa gång
unsigned long last_time_we_did_something = 0;

// (Loop-variabeln är densamma som tidigare, den använde vi för
// att bli av med for-satsen)
int current_index = 0;

void loop() {
    // current_time kommer att innehålla tiden i millisekunder (ms) sedan
    // vi startade om vår mikrokontroller
    unsigned long current_time = millis();
    
    // Vi kollar om tiden är större än vårt senaste tillfälle PLUS
    // det intervall vi vill vänta (vår tidigare delay).
    // ENBART när detta är uppfyllt gör vi något
    if (current_time > last_time_we_did_something + 1000)
    {
        if (current_index>=number_count)
            current_index = 0;

        printf("%d\n", numbers[current_index]);

        current_index++;

        // När vi gjort vår uppdatering ställer vi om
        // tiden för vår senaste uppdatering till aktuell tid
        last_time_we_did_something = current_time;
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
