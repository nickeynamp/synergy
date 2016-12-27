#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* fighting(void *ptr){
  char *parts = (char*) ptr;
  size_t newWeight= strlen(goods);
  for(size_t i =0; i<newWeight;i++){
    parts[i] = parts[i]+1;
  }
  return NULL;
}

int main(int argc, char *argv[]){
  if(argc!=3){
    perror("Incorrect number of arguments (3)");
    puts("Remember to include -pthread flag during compilation");
    exit(1);
  }
  printf("Hi Nick! This is a multi-threaded program where users indicate their desired number of threads and a message. The message length is then divided equally among the threads to increase every character by 1\n");
  puts("Remember to include flag -pthread during compilation");

  size_t NUM_THREADS = atoi(arv[1]);
  pthread_t solders[NUM_THREADS];
  char *goods = argv[2];
  size_t weight = strlen(goods);
  char *box[NUM_THREADS];

  //considering edge cases
  if(NUM_THREADS>weight){
    for(size_t i=0;i<weight;i++){

    }

  }

  for(size_t i = 0;i<weight;i++){
    pthread_create(&solders[i],NULL,fighting, (void*)goods);
  }

  for(size_t i =0; i<NUM_THREADS;i++){
    pthread_join(solders[i],NULL);
  }
  printf("The result is %s\n",goods);

  return 0;
}