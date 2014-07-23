#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

typedef struct s {
    int NroUSP; // chave primária
    int idade;
    bool valido; // para exclusão lógica
}REGISTRO;

typedef struct{
    int id;
    int end;
}TABELA, *PT;

void printaLista(PT tabela){
    int i =0;
    for(i=0;i<4;i++){
        printf("%i  %i \n",tabela[i].id,tabela[i].end);
    }
}

void bubbleSort(PT numbers, int array_size){
    int i,j;
    TABELA temp;
    for (i =(array_size - 1);i>0;i--)  {
        for (j=1;j<=i;j++){
        if (numbers[j-1].id>numbers[j].id){
            temp = numbers[j-1];
            numbers[j-1]= numbers[j];
            numbers[j]=temp;
        }
        }
    }
    //printaLista(numbers);
}

int buscarEnd(PT tabela,int aid){
    int i;
    for(i=0;i<4;i++){
        if(tabela[i].id==aid){
            //printf("%i %i \n",tabela[i].end,tabela[i].id);
            return tabela[i].end;
        }
    }
    return -1;
}

void inserirIndice(PT tabela,int ID,int endereco){
    tabela[endereco].end=endereco;
    tabela[endereco].id =ID;
    if(endereco == 3)bubbleSort(tabela,4);
}

REGISTRO busca(PT a,int num){
    FILE *arq = fopen("2.txt","rb");
    int end = buscarEnd(a,num);
    if(end==-1)return;
    REGISTRO r;
    fseek(arq,end*sizeof(REGISTRO),SEEK_SET);
    fread(&r,sizeof(REGISTRO),1,arq);
    return r;
}

void inserir(PT a){
    FILE * arq = fopen("2.txt","rb+");
    int prox=0;
    REGISTRO r;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        //printf("%i \n",r.NroUSP);
        inserirIndice(a,r.NroUSP,prox);
        prox++;
    }
    //printaLista(a);
}


int main(){
    printf("A RESPOSTA DESSE EX É 0 \n");
    TABELA* a = (TABELA*)malloc(sizeof(TABELA)*4);
    inserir(a);
    REGISTRO arr;
    arr=busca(a,888);
    printf("%i %i",arr.NroUSP,arr.idade);
}
