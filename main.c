// Created by javiercadena on 29/10/24.
//
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *before;
    struct Nodo *next;
};

struct Nodo* insertar(struct Nodo *actual, struct Nodo *primer_nodo, int dato, size_t size_nodo);
struct Nodo* buscar(struct Nodo *primer_nodo, int buscar);
void borrar(struct Nodo *ptr_nodo, struct Nodo *primer_nodo);

struct Nodo* insertar(struct Nodo *actual, struct Nodo *primer_nodo, int dato, size_t size_nodo){
    if (primer_nodo == NULL) {
        primer_nodo = (struct Nodo*) malloc(size_nodo);
        primer_nodo->before = NULL;
        primer_nodo->next = NULL;
        primer_nodo->valor = dato;
        actual = primer_nodo;
    }
    else{
        struct Nodo *ptr_new = malloc(size_nodo);
        ptr_new->next = actual->next;
        if (actual->next != NULL){  //si no es el ultimo el siguiente apunta al nuevo
            actual->next->before = ptr_new;
        }
        actual->next = ptr_new;
        ptr_new->before = actual;
        ptr_new->valor = dato;
        actual=ptr_new;
    }
    return primer_nodo;
}

struct Nodo* buscar(struct Nodo *primer_nodo, int buscar){
    struct Nodo* ptr_nodo = primer_nodo;
    while (ptr_nodo != NULL){
        if (ptr_nodo->valor == buscar){
            return ptr_nodo;
        }
        ptr_nodo = ptr_nodo->next;
    }
    return NULL;
}

void borrar(struct Nodo *ptr_nodo, struct Nodo *primer_nodo){
    if (ptr_nodo == primer_nodo)
        primer_nodo = ptr_nodo->next;
    if (ptr_nodo->before != NULL)
        ptr_nodo->before->next = ptr_nodo->next;
    if (ptr_nodo->next != NULL)
        ptr_nodo->next->before = ptr_nodo->before;

    free(ptr_nodo);
    ptr_nodo = NULL;
}

int main(void){
    size_t size_nodo = sizeof(struct Nodo);

    //declaramos variables a estructura
    //struct Nodo *posicion_actual = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo *actual = malloc(size_nodo);
    struct Nodo *primer_nodo = NULL;
    int valor = 5;
    //insertar(posicion_actual,primer_nodo,valor,size_nodo);

    printf("hola mundo");
    return 0;
}
