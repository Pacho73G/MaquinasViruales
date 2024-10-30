/****************************************************************************
Pontificia Universidad Javeriana
Autor: Francisco Javier Guzman Villegas
Fecha: 29/10/2024
Materia: Sistemas Operativos
Topico: Hilos
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

static void *funcion(void *argumentos){
  size_t job= *(size_t *)argumentos;
  printf("\n\t Job %zu \n", job);
  return NULL;
}

int main(int argc, char *argv[]){
  int N=(int)atoi(argv[1]);
  size_t jobs[N];    //vector de trabajos
  pthread_t hilos[N];  //vector de hilos
  for(int i=0;i<N;i++){
    jobs[i]=i;
    
    //Creacion de hilos y envio a la funcion
    pthread_create(&hilos[i],NULL,funcion,jobs+i);
  }
  for(int i=0;i<N;i++)
    pthread_join(hilos[i],NULL);
  
  return 0;
}