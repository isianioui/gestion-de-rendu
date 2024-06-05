#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    float value;
    int dispo;
} monnaie;

monnaie tab[9] = {
    {"Billet 200 DH", 200.0, 0},
    {"Billet 100 DH", 100.0, 0},
    {"Billet 50 DH", 50.0, 0},
    {"Billet 20 DH", 20.0, 0},
    {"Piece 10 DH", 10.0, 5},
    {"Piece 5 DH", 5.0, 3},
    {"Piece 2 DH", 2.0, 2},
    {"Piece 1 DH", 1.0, 6},
    {"Piece 0.5 DH", 0.5, 3}
};

void afficherDispo() {

    for (int i = 0; i < 9; i++) {
        printf("%s: %d\n", tab[i].name, tab[i].dispo);
    }
}

// int  testerDisponibilite() {
//     for (int i = 0; i < 9; i++) {
//         if (tab[i].dispo <= 0) {
//             return 0;
//         }
//     }
//      return 1;
// }




//  void redemarerDispo(float paiment, float rendu) {

//      for (int i = 0; i < 9; i++) {
//          if (paiment >= tab[i].value) {
//              paiment -= tab[i].value;
//              ++tab[i].dispo;
//              if (rendu != tab[i+1]){
//                  ++tab[i+1].dispo;
//              }
            
//          } else if (rendu == tab[i].value) {
//             ++tab[i].dispo; 
//              printf("Ajout de %.2f DH à la caisse.\n", tab[i].value);
//              break; 
//          }
//      }
//  }



void redemarerDispo(float paiment, float rendu) {
    for (int i = 0; i < 9; i++) {
        if (paiment >= tab[i].value) {
            paiment -= tab[i].value;
            tab[i].dispo++;
        }

        if (rendu == tab[i].value && tab[i].dispo > 0) {
            tab[i].dispo++;
            printf("Ajout de %.2f DH à la caisse.\n", tab[i].value);
            break;
        }
    }
}




//  void ajouterCaisse(float prix_client){
//     printf("%.2f dh est ajouter a la caisse" , prix_client);
//  }



int monnaieRendu(float rendu, monnaie temp[9]) {
    int nbr_billets = 0, nbr_coins = 0;
    printf("Rendu de la monnaie :\n");
    for (int i = 0; i < 9; i++) {
        while (rendu >= temp[i].value && temp[i].dispo > 0) {
            rendu -= temp[i].value;
            temp[i].dispo--;
            printf("1 x %s\n", temp[i].name);
            if (temp[i].value >= 20.0)
                nbr_billets++;
            else
                nbr_coins++;
        }
    }

    if (rendu > 0.0) {
        printf("Erreur: Pas assez de monnaie disponible  la monnaie restante est  :  %.2f DH.\n", rendu);
        return 0; 
    }

    printf("nombre total de billets : %d\n", nbr_billets);
    printf("nombre total de pieces : %d\n", nbr_coins);
    return 1;
}

int main() {

    float prix_achat, prix_client;
     
    printf("Entrer le prix a payer : ");
    scanf("%f", &prix_achat);
    printf("Entrer le montant donne par le client : ");
    scanf("%f", &prix_client);

    if (prix_client < prix_achat) {
        printf("Le montant donne par le client est insuffisant.\n");
    } else {
       float rendu = prix_client - prix_achat;
        printf("Montant a rendre : %.2f DH\n", rendu);
        printf("\nAvant transaction:\n");
        afficherDispo();
        
       
        monnaie temp[9];
        memcpy(temp, tab, sizeof(tab));
        
      
        
        if (monnaieRendu(rendu, temp)) {
         
            memcpy(tab, temp, sizeof(tab));
              redemarerDispo(prix_client , rendu);
            printf("\n apres  transaction:\n");
            afficherDispo();
          
        } else {
            printf("Transaction echouee .\n");

        }
    }

    // ajouterCaisse(prix_client);
    

    return 0;
}
