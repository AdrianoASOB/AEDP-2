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
bool compara(REGISTRO a,REGISTRO b){
    if(a.idade==b.idade){
        if(a.NroUSP==b.NroUSP){
            if(a.valido==b.valido)return true;
        }
    }
    return false;
}


bool insereSemDuplicata(REGISTRO a){
    REGISTRO r;
    FILE *arq = fopen("2.txt","rb+");
    bool aIgual=false;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        if(aIgual==false)aIgual=compara(a,r);
    }
    //fclose(arq);
    if(aIgual==true){
        printf("GOTCHA LITTLE SHIT");
        return;
    }
    fseek(arq,0,SEEK_END);
    fwrite(&a,sizeof(REGISTRO),1,arq);
}

int main(){
    REGISTRO *a = (REGISTRO*)malloc(sizeof(REGISTRO));
    REGISTRO *b = (REGISTRO*)malloc(sizeof(REGISTRO));
    a->idade=25;
    b->idade=20;
    a->NroUSP=634;
    b->NroUSP=888;
    a->valido=true;
    b->valido=false;
    insereSemDuplicata(*b);
    insereSemDuplicata(*a);
}
