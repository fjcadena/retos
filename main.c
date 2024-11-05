// Created by javiercadena on 29/10/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

struct Nodo {
    int valor;
    struct Nodo *before;
    struct Nodo *next;
};
void insertar(struct Nodo **actual, struct Nodo **primer_nodo, int dato, size_t size_nodo);
struct Nodo* buscar(struct Nodo *primer_nodo, int buscar);
void borrar(struct Nodo *ptr_nodo);

void insertar(struct Nodo **actual, struct Nodo **primer_nodo, int dato, size_t size_nodo){
    struct Nodo *ptr_new = malloc(size_nodo);
    ptr_new->valor = dato;
    if ((*primer_nodo) == NULL) {
        *primer_nodo = ptr_new;
        //*primer_nodo = (struct Nodo*) malloc(size_nodo);
        (*primer_nodo)->before = NULL;
        (*primer_nodo)->next = NULL;
        //(*primer_nodo)->valor = dato;
        printf("Primer_NODO: %p\n",(void *)primer_nodo);
        *actual = *primer_nodo;
        printf("Actual: %p\n",(void *)actual);

    }
    else{
        //struct Nodo *ptr_new = malloc(size_nodo);
        ptr_new->next = (*actual)->next;
        if ((*actual)->next != NULL){  //si no es el ultimo el siguiente apunta al nuevo
            (*actual)->next->before = ptr_new;
        }
        (*actual)->next = ptr_new;
        ptr_new->before = *actual;
        //ptr_new->valor = dato;
        *actual=ptr_new;
    }
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

void borrar(struct Nodo *ptr_nodo){

    if (ptr_nodo->before != NULL)
        ptr_nodo->before->next = ptr_nodo->next;
    if (ptr_nodo->next != NULL)
        ptr_nodo->next->before = ptr_nodo->before;

    free(ptr_nodo);
    ptr_nodo = NULL;
}

int main(void){
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(65001);
    size_t size_nodo = sizeof(struct Nodo);
    int accion=0, valor=0;
    //declaramos variables a estructura
    //struct Nodo *posicion_actual = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo *actual = malloc(size_nodo);
    actual = NULL;
    struct Nodo *primer_nodo = NULL;

    while(1){
        printf("Que desea hacer:\n1- Insertar\n2- buscar\n3- borrar");
        printf("\nIngresa una opción\n");
        scanf("%d", &accion);
        if (accion == 1) {
            printf("Introduce el dato a insertar: ");
            scanf("%d", &valor);
            insertar(&actual, &primer_nodo, valor, size_nodo);
            printf("valor de primer nodo %p, su valor %i\n", (void *)primer_nodo, primer_nodo->valor);
            printf("valor del nodo actual %p, su valor %i\n", (void *)actual, actual->valor );
        }
        if (accion == 2){
            printf("Introduce el dato a buscar: ");
            scanf("%d", &valor);
            actual = buscar(primer_nodo, valor);
            printf("nodo a buscar %p, su valor %i", actual, actual->valor);
        }
        if (accion == 3){
            borrar(actual);
        }
        if (accion == 4){
            exit(0); //break;
        }
    }
}