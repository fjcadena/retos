#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *before;
    struct Nodo *next;
};

struct Nodo* insertar_nodo(struct Nodo *actual, struct Nodo *priner_nodo, int valor, size_t size_nodo);
struct Nodo* find_nodo(struct Nodo* primer_elemento, int buscar);

void delete_nodo(void);


struct Nodo* insertar_nodo(struct Nodo *actual, struct Nodo *primer_nodo, int valor, size_t size_nodo){
    //posicion
    if (primer_nodo == NULL){
        primer_nodo = (struct Nodo*)malloc(size_nodo);
        primer_nodo->before = NULL;
        primer_nodo->next = NULL;
        primer_nodo->dato = valor;
        actual = primer_nodo;
    }
    else {
        struct Nodo *prt_nodo = (struct Nodo *) malloc(size_nodo);

        prt_nodo = (struct Nodo *) malloc(size_nodo);
        prt_nodo->next = actual->next;
        actual->next = prt_nodo;
        prt_nodo->before = actual;
        prt_nodo->dato = valor;
        actual = prt_nodo;
    }
    return primer_nodo;
}


struct Nodo* find_nodo(struct Nodo* primer_elemento, int buscar){
    struct Nodo* ptr_nodo = primer_elemento;
    // aqui tenemos dos opciones o mirar hasta que el valor de next sea NULL y luego añadir un if al final
    // para verificar si el ultimo registro es correcto mirar si ptr es NULL y asi eliminamos esa verificación

    while (ptr_nodo != NULL){
        if (ptr_nodo->dato == buscar){
            return ptr_nodo;
        }
        ptr_nodo = ptr_nodo->next;
    }
    return NULL;
}



int main() {
    size_t size_struct = sizeof(struct Nodo);
    struct Nodo *primero = NULL;
    struct Nodo *actual = NULL;
    int dato;

    primero = insertar_nodo(actual, primero, dato, size_struct);

    printf("Hello, World!\n");
    return 0;
}
