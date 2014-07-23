#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;


typedef struct {
    int NroUSP; // chave primária
    int idade;
    bool valido; // para exclusão lógica, apaga sua cabeca
} REGISTRO;

REGISTRO numUSP(int num){
    FILE *arq = fopen("2.txt","rb");
    REGISTRO r;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        if(r.NroUSP==num)break;
    }
    return r;
}

int main(){
    REGISTRO r = numUSP(911);
    printf("%i \n",r.NroUSP);
    printf("%i",r.idade);
}
