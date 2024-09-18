#include <cstdio>

// Kommentar som går till slutet av raden

/* Kommentar över flera rader, eller til
    exempel för bortkommentering av kod.
*/

int heltal = 9;
float decimaltal = 3.14;
char tecken = 'a';
bool flagga = true;

// Array-typer (ungefär listor)
char text[] = "Hello, world!";

// Vi behöver hålla reda på längden på en 
// array om vi ska kunna loopa över den
// eller skicka med den till en funktion
int led_pins[] = { 23, 24, 25 };
int num_led_pins = 3;

// Vi kan inte ta emot en array i en funktion,
// utan vi får en PEKARE till var i minnet det
// första elementet ligger. För att veta hur lång
// listan är, måste vi själva skicka med längden.
float turn_on(int *leds, int num_leds)
{
    for (int i=0; i<num_leds; i++) 
    {
        printf("Tänder led nummer %d\n");
    }
}

// I vanliga program skrivna i C/C++ för datorer så
// börjar alltså koden köras med main()-funktionen.
// Till skillnad från Python så kan vi inte ha någon
// kod som ligger utanför funktioner.

// Variabler däremot fungerar - de blir då globala
// och tillgängliga överallt i filen. Precis som i Python.
int main()
{

    // Villkorssatser (if-satser)
    if (heltal == 10)
    {
        // Vi använder block med {} för det som ska hända
        // när ett villkor är uppfyllt
    }
    // Vi skriver ut else if istället för elif som i Python
    else if (heltal < 10)
    {
        printf("Det var ett litet tal!");
    }
    else
    {
        printf("Talet är större än 10!");
    }

    // Loopar #1
    // En for-loop består av tre stycken uttryck inom
    // parenteser, åtskilda med semikolon
    // 1. Initialisering sker före loopen körs, här kan
    //    t ex en räknare deklareras med datatyp och startvärde
    // 2. En jämförelse sker FÖRE varje varv i loopen. Loopen
    //    avslutas om villkoret är falskt
    // 3. Efter ett varv i loopen körs det sista uttrycket. Det
    //    innehåller oftast en ökning av räknare med något värde.
    for (int i=1; i<=10; i++) 
    {
        printf("%d\n", i);
        // i++ samma som i += 1 samma som i = i + 1
    }

    // Loopar #2
    // En while-loop har friare former än for-loopen. Det
    // enda obligatoriska uttrycket är ett villkor för om
    // loopen skall köras eller inte. Hur koden fungerar i
    // övrigt för att styra programflödet avgör utvecklaren
    // själv.
    int i=1;
    while (i<=10) 
    {
        printf("%d\n", i);
        if (i%3==0) {
            i++;
        }
        i++;
    }

    // Loopar #3
    // Precis som i Python kan vi istället göra oändliga loopar.
    // För att avsluta dem får vi använda break.
    i = 0;
    while (true) {
        if (i>10) {
            break;
        }
        printf("%d\n", i);
        i++;
    }

}


