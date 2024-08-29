#include <cstdio>

// Kommentar som går till slutet av raden

/* Kommentar över flera rader, eller til
    exempel för bortkommentering av kod.
*/

int heltal = 9;
float decimaltal = 3.14;
char tecken = 'a';
bool flagga = true;

// Array-typer
char text[] = "Hello, world!";
int led_pins[] = {23, 24, 25};

int main()
{
    // Villkorssatser (if-satser)
    if (heltal == 10)
    {
    }
    else if (heltal < 10)
    {
        printf("Det var ett litet tal!");
    }
    else
    {
        printf("Talet är större än 10!");
    }

    // Loopar #1
    for (int i=1; i<=10; i++) 
    {
        printf("%d\n", i);
        // i++ samma som i += 1 samma som i = i + 1
    }

    // Loopar #2
    int i=1;
    while (i<=10) 
    {
        printf("%d\n", i);
        if (i%3==0) {
            i++;
        }
        i++;
    }

    i = 0;
    while (true) {
        if (i>10) {
            break;
        }
        printf("%d\n", i);
        i++;
    }


}


