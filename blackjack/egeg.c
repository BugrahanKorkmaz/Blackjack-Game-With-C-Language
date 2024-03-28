#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deger(int *kartdegeri, char kart) {
    if (kart == 'T' || kart == 'J' || kart == 'Q' || kart == 'K') {
        *kartdegeri = 10;
    } else if (kart == 'A') {
        *kartdegeri = 11; 
    } else {
        *kartdegeri = kart - '0';
    }
}

char masa1() {
    char mkart[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'J', 'A'};
    int x = rand() % 13;
    char masanininel1 = mkart[x];
    return masanininel1;
}

char *oyuncu(char *oyunucununel, int kartSayisi) {
    char okart[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'J', 'A'};
    int x = rand() % 13;

    oyunucununel[kartSayisi] = okart[x];
    oyunucununel[kartSayisi + 1] = '\0';

    return oyunucununel;
}

char *masa2(char *masaninel2, int masakartsayisi, char masanininel1) {
    char mkart[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'J', 'A'};
    int x = rand() % 13;

    masaninel2[masakartsayisi] = masanininel1; 
    masaninel2[masakartsayisi + 1] = mkart[x];
    masaninel2[masakartsayisi + 2] = '\0';

    return masaninel2;
}

int main() {
    char masanininel1, oyuncununel[20], masaninel2[20]; 
    int oyuncutoplam = 0, masatoplam = 0, kartsayisi = 0, masakartsayisi = 0;
    srand(time(NULL));

    printf("Welcome to Blackjack game, please enter if you want to play.\n");
    getchar();

    masanininel1 = masa1();
    printf("Table hand= %c \n", masanininel1);

    char devam;
    do {
        printf("Press enter to want a card\n");
        getchar();
        oyuncu(oyuncununel, kartsayisi);
        kartsayisi++;
        printf("Table hand= %c \nYour hand= %s \n", masanininel1, oyuncununel);
        printf("\n'E' key pull card, if you dont want to card press 'H'\n\n");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');

    for (int j = 0; j < kartsayisi; j++) {
        if (oyuncununel[j] != '\0') {
            int kartdegeri;
            deger(&kartdegeri, oyuncununel[j]);
            oyuncutoplam += kartdegeri;
        } else {
            if (oyuncutoplam > 21) { 
                oyuncutoplam -= 10; 
            }
        }
    }

    do {
        masa2(masaninel2, masakartsayisi, masanininel1);
        if (masaninel2[masakartsayisi] != 'A') {
            int kartdegeri;
            deger(&kartdegeri, masaninel2[masakartsayisi]);
            masatoplam += kartdegeri;
        } else {
            if (masatoplam > 21) {
                masatoplam -= 10;
            }
        }
        masakartsayisi++;
    } while (masatoplam <= 16);

    printf("Value of table: %d \n", masatoplam);
    printf("Value of player: %d \n\n", oyuncutoplam);

    if (oyuncutoplam > 21) {
        printf("<><><><> YOU LOSE <><><><>\n");
    } else if (masatoplam > 21 && oyuncutoplam <= 21) {
        printf("<><><><> YOU WIN <><><><>\n");
    } else if (masatoplam > oyuncutoplam) {
        printf("<><><><> YOU LOSE <><><><>\n");
    } else if (oyuncutoplam > masatoplam) {
        printf("<><><><> YOU WIN <><><><>\n");
    } else {
        printf("<><><><> DRAW <><><><>\n");
    }

    return 0;
}
