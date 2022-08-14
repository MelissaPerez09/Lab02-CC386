/*
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACION
* CC3086 - Programacion de microprocesadores
* ------------------------------------------------------------
* Laboratorio 02 - Parte 4
* Descripción: Creacion de hilos posix y el calculo de recorrido
* -------------------------------------------------------------
*/

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//declaracion de variables
void *sumS1(void *ptr);                             //funcion de subtotal1
void *sumS2(void *ptr);                             //funcion de subtotal2
char *info;                                         //informacion temporal
int sub1, sub2;                                     //variables subtotales
int numbers[] = {40, 35, 30, 25, 20, 15, 10, 5};    //numeros
int sizeNumbers = sizeof numbers/sizeof numbers[0]; //tamanio 
int divNumbers = sizeNumbers/2;                     //division para threads
pthread_t thread1, thread2;                         //threads
char const *m1 = "Thread 1";                        //mensaje para threads
char const *m2 = "Thread 2";                        //mensaje para threads

int main(){
    //creacion de los threads
     pthread_create(&thread1, NULL, sumS1, (void*) m1);
     pthread_create(&thread2, NULL, sumS2, (void*) m2);
    //termina los threads dependiendo de la espera
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 
     exit(0);
}

//THREAD 1: imprime valores del array y los suma
void *sumS1(void *ptr){
    info = (char *) ptr;
    printf("%s \n",info);
    int arr[divNumbers];

    //recorrer array e impresion
    for (int i = 0; i < divNumbers; i++){
        arr[i] = numbers[i];
        printf("Numbers in array (1): %d\n", arr[i]);
        sub1 = sub1 + arr[i];
    }
    printf("Sum total of the numbers in array (1): %d\n\n", sub1);
    return 0;
}

//THREAD 2: imprime valores del array y los suma
void *sumS2(void *ptr){
    info = (char *) ptr;
    printf("%s \n",info);
    int arr2[divNumbers];
    int contador = 0;
    //Ciclo para recorrer el array y realizar la impresion de cada dato
    for (int i = divNumbers; i < sizeNumbers; i++){
        arr2[contador] = numbers[i];
        printf("Numbers in array (2): %d\n", arr2[contador]);
        sub2 = sub2 + arr2[contador];
        contador++;
    }
    printf("Sum total of the numbers in array (2): %d\n\n", sub2);
    return 0;
}