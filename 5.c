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

void deleta(){
    FILE *arq = fopen("1.txt","rb+");
    REGISTRO r[10];
    REGISTRO temp;
    int cont=0;
    while(1==fread(&temp,sizeof(REGISTRO),1,arq)){
        if(temp.valido==0){
            r[cont]=temp;
            cont++;
        }
    }
    fclose(arq);
    arq = fopen("2.txt","wb+");
    int limite=cont;
    cont=0;
    while(cont<limite){
        fwrite(&r[cont],sizeof(REGISTRO),1,arq);
        cont++;
    }

}

int main(){
    deleta();
}
