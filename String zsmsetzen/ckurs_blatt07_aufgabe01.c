#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char wochentag[] = "Freitag";
    int tag = 13;
    char monat[] = "Mai";
    int jahr = 1927;
    const size_t kapazitaet = 100 * sizeof(char); // Maximale Laenge des Datumstrings!
    char *string = (char*)malloc(kapazitaet); // Hier soll das Datum hineingeschrieben werden!

    // Hier implementieren und dynamisch Speicher reservieren
    snprintf(string, kapazitaet, "%s, der %d. %s %d", wochentag, tag, monat, jahr);


    printf("%s\n", string);
    // Speicher freigeben
    free(string);
    return 0;
}
