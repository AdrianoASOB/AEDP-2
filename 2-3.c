#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

typedef struct s {
    int NroUSP; // chave prim�ria
    int idade;
    bool valido; // para exclus�o l�gica
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
            printf("%i %i \n",tabela[i].end,tabela[i].id);
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
void elimina(PT a, int numUsp){
    FILE *arq = fopen("2.txt","rb+");
    int end = buscarEnd(a,numUsp);
    fseek(arq,end*sizeof(REGISTRO),SEEK_SET);
    REGISTRO vazio;
    vazio.valido=false;
    fwrite(&vazio,sizeof(REGISTRO),1,arq);
}

void tabela(PT a){
    FILE * arq = fopen("2.txt","rb+");
    int prox=0;
    REGISTRO r;
    int num=0;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        if(r.idade==10)num=r.NroUSP;
        //printf("%i \n",r.NroUSP);
        inserirIndice(a,r.NroUSP,prox);
        prox++;
    }
    if(num==0){
        printf("VAGOYNAS");
        return;
    }
    elimina(a,10);
    printaLista(a);
}


int main(){
    TABELA* a = (TABELA*)malloc(sizeof(TABELA)*4);
    tabela(a);
}
