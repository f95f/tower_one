#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "entities.h"

void main(){
    srand((unsigned) time(NULL));
    setlocale(LC_ALL, "");

    int ataque;
    int cura;
    int opc;
    int rodada = 1;

    PLAYER jogador1;
    jogador1.att = 10;
    jogador1.hp = 500;
    jogador1.mp = 4;

    ENEMY inimigo1;
    inimigo1.att = 10;
    inimigo1.hp = 999;

    do{
        printf("\n > Rodada %d\n\n", rodada);
         printf(" > Seu HP: %d", jogador1.hp);
         printf(" > --- Sua magia: %d\n", jogador1.mp);
         printf(" > Inimigo1 - HP: %d\n", inimigo1.hp);
         printf(" --------------------------------\n\n");

        do{
            opc = 0;
            printf(" Escolha uma opção:\n\n");
            printf("     [1] Atacar\n");
            printf("     [2] Curar \n\n");

            printf(" > ");
            scanf("%d", &opc);

            if(opc != 1 && opc != 2){
                printf(" [!] Opção inválida!\n\n");
                system("pause");
            }
            if(opc == 2 && jogador1.mp == 0){
                    printf(" [!] Você não tem poder o suficiente!\n\n");
                    opc = 0;
                    system("pause");
            }

        }
        while(opc != 1 && opc != 2);

        switch(opc){
            case 1:
                ataque = jogador1.att * (rand() % 20 ) + rand()/10000;
                 inimigo1.hp -= ataque;
                 if(ataque == 0){
                        printf(" > Inimigo1 esquivou do seu ataque!\n\n");
                 }
                 else{
                        printf(" > Você atacou Inimigo1 com %d de dano!\n\n", ataque);
                 }
                if(ataque >= 180){
                    printf(" > Dano crítico!\n");
                    printf(" > Sua magia aumentou.\n\n");
                    jogador1.mp++;

                }
                break;
            case 2:
                cura = rand() % 100 + 50;
                jogador1.hp += cura;
                jogador1.mp--;
                printf(" > Você recuperou %d de HP.", cura);

                break;
        }

         system("pause");

        system("cls");
        printf("\n > Rodada %d\n\n", rodada);
        printf(" > Seu HP: %d\n", jogador1.hp);
        printf(" > Inimigo1 - HP: %d\n", inimigo1.hp);
        printf(" --------------------------------!\n\n");

         if(inimigo1.hp > 0){
            ataque = inimigo1.att * (rand() % 20 ) + rand()/10000;
            jogador1.hp -= ataque;
            if(ataque == 0){
                    printf(" > Inimigo1 errou o ataque!\n\n");
            }
            else{
                    printf(" > Inimigo1 te atacou com %d de dano.\n\n", ataque);
            }

            rodada++;
         }
         else{ printf(" > Você venceu!\n\n");}
         if(jogador1.hp <= 0){ printf(" > Você foi derrotado!\n\n");}
         system("pause");
         system("cls");
    }
    while(inimigo1.hp > 0 && jogador1.hp > 0);

    printf(" > Fim de jogo.");

}
