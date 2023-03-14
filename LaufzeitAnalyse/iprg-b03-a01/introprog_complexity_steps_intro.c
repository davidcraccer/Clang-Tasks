#include <stdio.h>
#include "introprog_complexity_steps_input.h"

long for_linear(int n, int *befehle)
{
    // TODO: Die Befehle müssen richtig gezählt werden

    long sum = 0;
    (*befehle)++; // initialize for sum
    (*befehle)++; // initialize for i
    for (int i = 1; i <= n; ++i)
    {
        // Zähle die folgende Zeile als genau ein Befehl!
        (*befehle)++; // initialize for i, when true
        (*befehle)++; // initialize for Erhöhung

        sum += get_value_one();
        (*befehle)++; // sum += get_value_one()
    }
    (*befehle)++; // Abbruch
    (*befehle)++; // sum
    return sum;
}

long for_quadratisch(int n, int *befehle)
{
    // TODO: Die Befehle müssen richtig gezählt werden

    long sum = 0;
    (*befehle)++; // initialize for sum
    (*befehle)++; // initialize for i
    for (int i = 1; i <= n; ++i)
    {
        (*befehle)++; // initialize for i, when true
        (*befehle)++; // initialize for Erhöhung
        (*befehle)++; // initialize for j
        for (int j = 1; j <= n; ++j)
        {
            // Zähle die folgende Zeile als genau ein Befehl!
            (*befehle)++; // initialize for j, when true
            (*befehle)++; // initialize for Erhöhung
            sum += get_value_one();
            (*befehle)++; // sum += get_value_one()
        }
        (*befehle)++; // Abbruch j
    }
    (*befehle)++; // Abbruch i
    (*befehle)++; // sum
    return sum;
}

long for_kubisch(int n, int *befehle)
{
    // TODO: Die Befehle müssen richtig gezählt werden

    long sum = 0;
    (*befehle)++; // initialize for sum
    (*befehle)++; // initialize for i
    for (int i = 1; i <= n; ++i)
    {
        (*befehle)++; // initialize for i, when true
        (*befehle)++; // initialize for Erhöhung
        (*befehle)++; // initialize for j
        for (int j = 1; j <= n; ++j)
        {
            (*befehle)++; // initialize for j, when true
            (*befehle)++; // initialize for Erhöhung
            (*befehle)++; // initialize for k
            for (int k = 1; k <= n; ++k)
            {
                // Zähle die folgende Zeile als genau ein
                // Befehl!
                (*befehle)++; // initialize for k, when true
                (*befehle)++; // initialize for Erhöhung
                sum += get_value_one();
                (*befehle)++; // get_value_one()
            }
            (*befehle)++; // Abbruch k
        }
        (*befehle)++; // Abbruch j
    }
    (*befehle)++; // Abbruch i
    (*befehle)++; // Sum
    return sum;
}

int main(int argc, char *argv[])
{
    const int WERTE[] = {5, 6, 7, 8, 9, 10};
    const int LEN_WERTE = 6;
    const int LEN_ALGORITHMEN = 3;

    long befehle_array[LEN_ALGORITHMEN][LEN_WERTE];
    long werte_array[LEN_ALGORITHMEN][LEN_WERTE];
    double laufzeit_array[LEN_ALGORITHMEN][LEN_WERTE];

    for (int j = 0; j < LEN_WERTE; ++j)
    {
        int n = WERTE[j];
        for (int i = 0; i < LEN_ALGORITHMEN; ++i)
        {
            printf("Starte Algorithmus %d mit Wert %d\n",
                   (i + 1), n);
            int anzahl_befehle = 0;
            int wert = 0;

            // Starte den Timer
            start_timer();

            // Aufruf der entsprechenden Funktion
            if (i == 0)
            {
                wert = for_linear(n, &anzahl_befehle);
            }
            else if (i == 1)
            {
                wert = for_quadratisch(n, &anzahl_befehle);
            }
            else if (i == 2)
            {
                wert = for_kubisch(n, &anzahl_befehle);
            }

            // Speichere Laufzeit, Rückgabewert und Anzahl
            // ausgeführter Befehle ab
            laufzeit_array[i][j] = end_timer();
            werte_array[i][j] = wert;
            befehle_array[i][j] = anzahl_befehle;
        }
        printf("\n");
    }

    // Ausgabe der Rückgabewerte, Anzahl ausgeführter Befehle
    // sowie der gemessenen Laufzeiten (in Millisekunden)
    printf("%3s \t%-28s \t%-28s \t%-28s\n", "", "linear", "quadratisch", "kubisch");
    printf("%3s \t %5s %10s %10s\t %5s %10s %10s\t %5s %10s %10s\n", "n", "Wert", "Befehle", "Laufzeit", "Wert", "Befehle", "Laufzeit", "Wert", "Befehle", "Laufzeit");

    for (int j = 0; j < LEN_WERTE; ++j)
    {
        printf("%3d \t ", WERTE[j]);
        for (int i = 0; i < LEN_ALGORITHMEN; ++i)
        {
            printf("%5ld %10ld %10.4f \t ", werte_array[i][j], befehle_array[i][j], laufzeit_array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
