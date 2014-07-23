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
    FILE * arq = fopen("2.txt","rb");
    REGISTRO r;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        printf("IDADE:   %i \n",r.idade);
        printf("NRO USP: %i \n",r.NroUSP);
        printf("VALIDO:  %i \n",r.valido);
        printf("\n");
    }
}

bool inverte(){
    FILE *arq = fopen("1.txt","rb");
    FILE *rec = fopen("2.txt","wb");
    REGISTRO r[10];
    int cont=0;
    while(1==fread(&r[cont],sizeof(REGISTRO),1,arq)){
        cont++;
    }
    fseek(arq,sizeof(REGISTRO),SEEK_SET);
    cont--;
    while(cont>=0){
        fwrite(&r[cont],sizeof(REGISTRO),1,rec);
        cont--;
    }
    fclose(arq);
    fclose(rec);
}

int main(){
    inverte();
}
