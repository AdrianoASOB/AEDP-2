#include <malloc.h>
#include <stdio.h>

int main(){
    FILE *arq = fopen("teste.txt","r");
    FILE *fag = fopen("newteste.txt","w+");
    char c;
    while(c=fgetc(arq)!= feof(arq)){
        putc(c,fag);
    }
}
