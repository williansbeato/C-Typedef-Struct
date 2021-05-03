#ifndef _PARKIF_
#define _PARKIF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char marca[50];
    char modelo[50];
    char cor[20];
    char placa[10];

} veiculo;


veiculo *db;
int pos = 0;
char placa[10];

void init() {
    db = malloc(1 * sizeof(veiculo));
}

void add(veiculo v) {
    printf("\n[OK]\n");
    db[pos] = v;
    pos++;
    db = realloc(db, pos+1*sizeof(veiculo));
}

int rem(char *placa) {
    veiculo *dbAux;
    dbAux = malloc(pos * sizeof(veiculo));
    int i, j, aux=0;
    
    for(i=0,j=0; i<pos; i++){ 
        if (strcmp(placa, db[i].placa)==0){  
            aux++;
        }else{
            dbAux[j]=db[i];
            j++;
        }
    }

    db = realloc(NULL, j+1*sizeof(veiculo));
    for(i=0,j=0; i<pos; i++){ 
        db[i]=dbAux[i];
    }

    if (aux!=0){
        pos--;
        printf("\n[OK]\n");
    }else{
        printf("\n[ERRO]: Placa nao encontrada!\n");
    }

    return -1;
}

void view() {

    printf("\n[VISUALIZACAO DE VEICULO]\n", pos);
    for(int i=0; i<pos; i++){   
        printf("\n%i | %s / %s / %s / %s\n", i+1, db[i].marca, db[i].modelo, db[i].cor, db[i].placa);
    }
}

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

#endif