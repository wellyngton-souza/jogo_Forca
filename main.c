#include <stdio.h>
#include <string.h>

void chute(char chutes[26] ,int* tentativas){
    // * recebe um valor e & envia um valor
    // a respeito de um endereço
    char chute;
    scanf(" %c", &chute);
    
    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int main()
{
    char palavra[20];
    
    sprintf(palavra, "cavalo");
    
    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;
    
    printf("*****************\n");
    printf("**Jogo da Forca**\n");
    printf("*****************\n\n");
    
    do{
        // printa a palavra inteira
        for(int i = 0; i < strlen(palavra); i++){
            
            int achou = 0;
            // verifica se acertou            
            for(int j = 0; j < tentativas; j++){
                if(chutes[j] == palavra[i]){
                    achou = 1;
                    break;
                }
            }
            
            // se o caractere foi encontrada printa ele, senão printa _
            if(achou){
                printf("%c " , palavra[i]);
            } else{
                printf("_ ");
            }
        }
        
        printf("\n");
        
        // faz uma tentativa
        chute(chutes, &tentativas);
        
    } while(!acertou && !enforcou);
    
    return 0;
}