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

void altera(int nani){
    FILE *arq = fopen("2.txt","rb+");
    REGISTRO r;
    bool achou=false;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        if(r.NroUSP==nani){
            achou=true;
            printf("achou");
            break;
        }
    }
    if(achou==false){
        fclose(arq);
        printf("não achou");
        return;
    }
    r.idade=2;
    fseek(arq,-sizeof(REGISTRO),SEEK_CUR);
    fwrite(&r,sizeof(REGISTRO),1,arq);
    fclose(arq);
}

int main(){
    altera(911);
}
