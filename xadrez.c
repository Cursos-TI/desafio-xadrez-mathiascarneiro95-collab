#include <stdio.h>

//########## FUNÇÕES DAS PEÇAS ##########

void linha(){ // Função para pular linha
    printf("\n");
}

void mover_torre(int casa){ // Função para mover a torre
    if (casa > 0){
        printf("\033[7mDireita\033[m\n");
        linha();
        mover_torre(casa - 1);
    }
}


void mover_rainha(int casa){ // Função para mover a rainha
    if (casa > 0){
        printf("\033[7mEsquerda\033[m\n");
        linha();
        mover_rainha(casa - 1);
    }
}


void mover_vertical(int v){ // Função para movimento na vertical do bispo
    if (v > 0){
        printf("\033[7mCima\033[m\n");
        mover_vertical(v - v); // Recursividade
    }
}


void mover_bispo(int casa){
    for (int v = 0; v < casa; v++){
        mover_vertical(casa); // Recursividade do movimento vertical
        printf("\033[7mDireita\033[m\n");
        linha();
    }
}


void mover_cavalo(int casa){
    // Loops Aninhados
    while (casa > 0){
        for (int h = 0; h <= 0; h++){
            printf("\033[7mDireita\033[m\n");
            mover_vertical(casa); // Função Recursiva
            casa--;
            linha();
        }
    }
}


// ########## PROGRAMA PRINCIPAL ##########

int main(){

    printf("\033[4;41m########## MOVIMENTO DE PEÇAS DE XADREZ ##########\033[m\n");
    linha();

    // Movimento da torre 5 casas para a direita
    printf("\033[1;42m>>> Movimento da Torre 5 Casas <<<\033[m\n");
    linha();

    mover_torre(5); // Imprime a direção do movimento    

    // Movimento do Bispo 5 casas na diagonal 
    linha();
    printf("\033[1;43m>>> Movimento do Bispo 5 Casas <<<\033[m\n");
    linha();

    mover_bispo(5);


    // Movimento da Rainha 8 casas à esquerda

    linha();
    printf("\033[1;44m>>> Movimento da Rainha 8 Casas <<<\033[m\n");
    linha();
    
    mover_rainha(8);
    linha();
        
    // Movimento do cavalo em L
    linha();
    printf("\033[1;45m>>> Movimento do Cavalo 2x <<<\033[m\n");
    linha();
    
    mover_cavalo(2);


    linha();
    printf("\033[1;41mFim...\033[m\n"); // Fim do programa

    return 0;
}
