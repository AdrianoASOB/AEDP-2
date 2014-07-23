#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

typedef struct {
    int NroUSP; // chave primária
    int idade;
    bool valido; // para exclusão lógica
} REGISTRO;

void leTuto(){
    FILE * deflango = fopen("2.txt","rb");
    REGISTRO r;
    while(1==fread(&r,sizeof(REGISTRO),1,deflango)){
        printf("IDADE:   %i \n",r.idade);
        printf("NRO USP: %i \n",r.NroUSP);
        printf("VALIDO:  %i \n",r.valido);
        printf("\n");
    }
}

bool criaSohValido(){
    FILE * arq1= fopen("1.txt","rb");
    FILE * arq2= fopen("2.txt","wb");
    REGISTRO r;
    while(1==fread(&r,sizeof(REGISTRO),1,arq1)){
        if(r.valido==true)fwrite(&r,sizeof(REGISTRO),1,arq2);
    }
    leTuto();
}

int main(){
    leTuto();
    //criaSohValido();
}
