/*
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACION
* CC3086 - Programacion de microprocesadores
* ------------------------------------------------------------
* Laboratorio 02 - Parte 5
* Descripción: Creacion de hilos para ejecutar tareas
* -------------------------------------------------------------
*/

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

//declaracion de variables
void *task1(void *ptr);                     //funcion para tarea1
void *task2(void *ptr);                     //funcion para tarea2
void *task3(void *ptr);                     //funcion para tarea3
pthread_t thread1, thread2, thread3;        //threads
char const *t1 = "Thread 1";                //mensaje para threads
char const *t2 = "Thread 2";                //mensaje para threads
char const *t3 = "Thread 3";                //mensaje para threads
int velocidad;
int segundos[] = {25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}; 
int sizeS = sizeof segundos/sizeof segundos[0]; //tamanio 
int divS = sizeS/2; 

int main(){
    cout << "Ingrese una velocidad en m/s: ";
    cin >> velocidad;
    //creacion de los threads
     pthread_create(&thread1, NULL, task1, (void*) t1);
     pthread_create(&thread2, NULL, task2, (void*) t2);
     pthread_create(&thread3, NULL, task3, (void*) t3);
    //termina los threads dependiendo de la espera
     pthread_join(thread1, NULL);
     pthread_join(thread2, NULL); 
     pthread_join(thread3, NULL); 
     exit(0);
}

//THREAD 1: imprime valor de un contador con un sleep
void *task1(void *ptr){
    int contador = 0;
    int array[divS];
    //Ciclo para recorrer el array y realizar la impresion de cada dato
    for (int i = divS; i < sizeS; i++){
        array[contador] = segundos[i];
        sleep(segundos[i]);
        printf("El valor del hilo 1 es: %d\n", array[contador]);
        contador++;
    }
    return 0;
}

//THREAD 2: toma la velocidad y calcula segun la formula
void *task2(void *ptr){
    int velocidad = velocidad;
    int tiempo = *task1(*)(task1*);
    int distancia = velocidad/tiempo;
    printf("En _ segundos la distancia recorrida es: %d\n", distancia);
    return 0;
}

//THREAD 3: revisa la distancia cada 5 metros
void *task3(void *ptr){
    
    return 0;
}
