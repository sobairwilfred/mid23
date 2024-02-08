#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int wert;
} item;

typedef struct sp {
    char * text;
    struct sp *v, *z, *l, *r;
    item * gegenstand[5];
    item * zugangMit[5];
    char * frage;
    int richtigeAntwort;
} storypoint;

void textAusgabe(char * text) {
    printf("\n");
    for(int i = 0; i < strlen(text); i++) {
        printf("%c",text[i]);
        Sleep(10);
    }
    printf("\n");
}

void ausgabeInventar(item * inventar[], int anzahl) {
    printf("Inventar: ");
    for(int i = 0; i < anzahl; i++) {
        printf("%s (%i) ",inventar[i]->name,inventar[i]->wert);
    }
    printf("\n");
}

void introJingle() {
    Beep(1000,500);
    Beep(2000,500);
    Beep(1000,500);
    Beep(800,250);
    Beep(1000,500);
    Beep(2000,500);
    Beep(1000,500);
}

int main() {
    srand(42);
    //introJingle();
    
    char cmd[10];
    int quit = 0;

    storypoint lichtung;
    lichtung.text = "Du stehst auf einer Lichtung. Es ist dunkel. In der ferne siehst du ein Licht.";

    storypoint teich;
    teich.text = "Ein Teich liegt vor dir. Der Mond scheint. Am Ufer liegt etwas.";

    storypoint haus;
    haus.text = "Du stehst vor einem Haus. Die Lichter sind aus.";

    storypoint flur;
    flur.text = "Du bist im Haus. Hoffentlich hat niemand geh�rt, dass du die T�r aufgeschlossen hast. Du h�rst ein Ger�usch von oben.";

    item schluessel;
    schluessel.name = "Gelber Schl�ssel";
    schluessel.wert = 100;

    item schluessel2;
    schluessel2.name = "Blauer Schl�ssel";
    schluessel2.wert = 100;

    lichtung.v = &haus;
    lichtung.l = &teich;
    lichtung.r = NULL;
    lichtung.z = NULL;
    lichtung.gegenstand[0] = NULL;
    lichtung.zugangMit[0] = NULL;
    lichtung.frage = NULL;

    teich.v = NULL;
    teich.z = NULL;
    teich.r = &lichtung;
    teich.l = NULL;
    teich.gegenstand[0] = &schluessel;
    teich.gegenstand[1] = NULL;
    teich.zugangMit[0] = NULL;
    teich.frage = "Wie viel ist 3*4. [1] 10 [2] 12 [3] 20?";
    teich.richtigeAntwort = 2;

    haus.v = &flur;
    haus.z = &lichtung;
    haus.l = NULL;
    haus.r = NULL;
    haus.gegenstand[0] = &schluessel2;
    haus.gegenstand[1] = NULL;
    haus.zugangMit[0] = NULL;
    haus.frage = NULL;

    flur.v = NULL;
    flur.z = &haus;
    flur.l = NULL;
    flur.r = NULL;
    flur.gegenstand[0] = NULL;
    flur.zugangMit[0] = &schluessel;
    flur.zugangMit[1] = &schluessel2;
    flur.frage = NULL;

    //            Flur
    //              |
    //            Haus
    //              |
    //  Teich <- Lichtung

    //Spielzustand
    storypoint * current = &lichtung;
    storypoint * finish = &flur;
    item * inventar[10];
    int anzahlItemsInBesitz = 0;

    printf("Willkommen im Spiel!\n\n");
    
    while(1) {
        //Gegenst�nde einsammeln
        for(int x = 0; x < 5; x++) {
            if(current->gegenstand[x] != NULL) {
                inventar[anzahlItemsInBesitz++] = current->gegenstand[x];
                current->gegenstand[x] = NULL;
            } else {
                break;
            }
        }
        ausgabeInventar(inventar,anzahlItemsInBesitz);
        textAusgabe(current->text);

        if(strcmp(current->text,finish->text) == 0) {
            printf("Herzlichen Glückwunsch\n");
            return 0;
        } else {
            printf("Es geht weiter..\n");
        }

        printf("> ");
        scanf("%s",&cmd);
        storypoint * next = current;
        if(strcmp(cmd,"quit") == 0) {
            break;
        } else if(strcmp(cmd,"v") == 0) {
            if(current->v != NULL) {
                next = current->v;
            } else {
                textAusgabe("Hier geht es nicht vorwaerts.\n");
            }
        } else if(strcmp(cmd,"z") == 0) {
            if(current->z != NULL) {
                next = current->z;
            } else {
                textAusgabe("Hier geht es nicht zurueck.\n");
            }
        } else if(strcmp(cmd,"l") == 0) {
            if(current->l != NULL) {
                next = current->l;
            } else {
                textAusgabe("Hier geht es nicht nach links.\n");
            }
        } else if(strcmp(cmd,"r") == 0) {
            if(current->r != NULL) {
                next = current->r;
            } else {
                textAusgabe("Hier geht es nicht nach rechts.\n");
            }
        }
        //check ob zugang m�glich
        bool alleVoraussetzungenErf�llt = TRUE;
        for(int r = 0; r < 5; r++) { //max 5 n�tige Gegenst�nde
            if(next->zugangMit[r] != NULL) {
                bool gefunden = FALSE;
                for(int i = 0; i < anzahlItemsInBesitz; i++) {
                    if(strcmp(inventar[i]->name,next->zugangMit[0]->name) == 0) {
                        current = next;
                        gefunden = TRUE;
                        break;
                    }
                }
                if(!gefunden) alleVoraussetzungenErf�llt = FALSE;
            } else {
                break;
            }
        }
        if(next->frage != NULL) {
            textAusgabe(next->frage);
            int antwort;
            scanf("%i",&antwort);
            if(antwort != next->richtigeAntwort) {
                alleVoraussetzungenErf�llt = FALSE;
                textAusgabe("Das war leider falsch!\n");
            }
        }
        if(!alleVoraussetzungenErf�llt) {
            textAusgabe("So kommst du hier nicht weiter.\n");
        }
        if(alleVoraussetzungenErf�llt) {
            current = next;
        }
    }
}