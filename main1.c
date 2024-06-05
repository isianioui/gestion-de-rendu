#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int value;
} monnaie;


monnaie tab[9] = {
    {"Billet 200 DH", 200},
    {"Billet 100 DH", 100},
    {"Billet 50 DH", 50},
    {"Billet 20 DH", 20},
    {"Piece 10 DH", 10},
    {"Piece 5 DH", 5},
    {"Piece 2 DH", 2},
    {"Piece 1 DH", 1},
    {"Piece 0.5 DH", 0.5}
};

void monnaieRendu(float rendu) {
    int nbr_billets = 0, numCoins = 0;
    printf("Rendu de la monnaie :\n");
    for (int i = 0; i < 9; i++) {
        int count = (int)(rendu / tab[i].value);
        if (count > 0) {
            printf("%d x %s\n", count, tab[i].name);
            rendu -= count * tab[i].value;
            if (tab[i].value >= 20)
                nbr_billets += count;
            else
                numCoins += count;
        }
    }
    printf("Nombre total de billets : %d\n", nbr_billets);
    printf("Nombre total de pieces : %d\n", numCoins);
}

int main() {
    float achat , payment;
    printf("Entrer le prix a payer : ");
    scanf("%f", &achat );
    printf("Entrer le montant donne par le client : ");
    scanf("%f", &payment);

    if (payment < achat ) {
        printf("Le montant donne par le client est insuffisant.\n");
    } else {
        float rendu = payment -achat;
        int rest = (int)rendu;
        
        printf("Montant a rendre : %d  DH\n", rest);
        monnaieRendu(rendu);
    }

    return 0;
}
