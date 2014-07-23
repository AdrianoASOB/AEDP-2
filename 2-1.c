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

void inserir(PT a, REGISTRO kawaii){
    FILE * arq = fopen("2.txt","rb+");
    int prox=0;
    REGISTRO r;
    while(1==fread(&r,sizeof(REGISTRO),1,arq)){
        //printf("%i \n",r.NroUSP);
        inserirIndice(a,r.NroUSP,prox);
        prox++;
    }
    //printaLista(a);
    int end = buscarEnd(a,kawaii.NroUSP);
    printf("%i %i",end,kawaii.NroUSP);
    if(end==-1){
        //printf("AEW FERA CURTE QUANDO NAO COMPILA A PORRA DO PROGRAMA? EU TBM MUITO TOP");
        fseek(arq,0,SEEK_END);
        fwrite(&kawaii,sizeof(REGISTRO),1,arq);
    }
    else printf("AEW PARÇA NEM TEM COMO MALZ");
}


int main(){
    TABELA* a = (TABELA*)malloc(sizeof(TABELA)*4);
    REGISTRO* r =(REGISTRO*)malloc(sizeof(REGISTRO));
    r->idade=69; //HAHEUAHUAHEUHAUEHEUAHEUHEUAHEUHUEHAUEHUAHEUEHUAHEUHEUAHEUEHUUAEHUEHUAHEUEHUEHUAHEUHEUAHEUHEUAHEUHEAUHEUAHEUAHEU
    r->NroUSP=6969;//KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
    r->valido=1;
    inserir(a,*r);
}
