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
void popula(){
    REGISTRO *a = (REGISTRO*)malloc(sizeof(REGISTRO));
    REGISTRO *b = (REGISTRO*)malloc(sizeof(REGISTRO));
    REGISTRO *c = (REGISTRO*)malloc(sizeof(REGISTRO));
    REGISTRO *d = (REGISTRO*)malloc(sizeof(REGISTRO));
    a->idade=10;
    b->idade=20;
    c->idade=30;
    a->NroUSP=999;
    b->NroUSP=888;
    c->NroUSP=911;
    a->valido=true;
    b->valido=false;
    c->valido=true;
    d->idade=32;
    d->NroUSP=234;
    d->valido=true;
    REGISTRO dois[4];
    dois[0]=*a;
    dois[1]=*b;
    dois[2]=*c;
    dois[3]=*d;
    FILE *arq = fopen("2.txt","wb");
    fwrite(&dois[0],sizeof(REGISTRO),1,arq);
    fwrite(&dois[1],sizeof(REGISTRO),1,arq);
    fwrite(&dois[2],sizeof(REGISTRO),1,arq);
    fwrite(&dois[3],sizeof(REGISTRO),1,arq);
    fclose(arq);
}

int main(){
    //popula();
    leTuto();
}
