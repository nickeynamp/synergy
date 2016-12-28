#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t lock;

typedef struct {
  char *data;
  size_t exec_times;
}Info;

void* fighting(void *ptr){
  pthread_mutex_lock(&lock);
  char *part = ((Info*) ptr) ->data;
  size_t exec_times = ((Info*) ptr) ->exec_times;
  pthread_mutex_unlock(&lock);

  for(size_t i =0; i< exec_times;i++){
    pthread_mutex_lock(&lock);
    part[i] = part[i]+1;
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main(int argc, char *argv[]){
  //if(argc != 3){
    //perror("Incorrect number of arguments (3)");
    //puts("Remember to include -pthread flag during COMPILING");
    //puts("\n Usage: ./a.out <NUM_THREADS> <MESSAGE> \n");
    //exit(1);
  //}
  printf("Hi there! This is a multi-threaded C program where users indicate their desired number of threads and a message. The message length is then divided equally among the threads to increase every character by 1\n\n");
  puts("Remember to include -pthread flag during COMPILING");
  size_t NUM_THREADS = 4;//atoi(argv[1]);
  pthread_t solders[NUM_THREADS];
  char *mess = "Long message";
  size_t weight = strlen(mess);

  size_t rem = weight % NUM_THREADS;
  
  //considering edge cases
  //diving the message accoring to num_threads and weight
  Info *box[1000];
  if(weight >= NUM_THREADS){
    //box = malloc(1000000);
    size_t j=0;
    for(;j< NUM_THREADS-1;j++){
      puts("a messaage");
      box[j]->data = mess+ j*(weight/NUM_THREADS);
      box[j]->exec_times = weight/NUM_THREADS;
    }
    puts("a messaage");
    box[j]->data = mess+ j*(weight/NUM_THREADS);
    if(weight%NUM_THREADS ==0) box[j]->exec_times = weight/NUM_THREADS;
    else box[j]->exec_times = weight%NUM_THREADS;
  }else{
    //box = malloc(weight* sizeof(Info*));
    for(size_t j=0;j< weight;j++){
      box[j]->data = mess+ j;
      box[j]->exec_times = 1;
    }
  }
  //sending threads to encode the message
  for(size_t i = 0;i<NUM_THREADS;i++){
    pthread_create(&solders[i],NULL,fighting, (void*)box[i]);
  }
  for(size_t i =0; i<NUM_THREADS;i++){
    pthread_join(solders[i],NULL);
  }

  //free(box);
  printf("Encoded message:  %s\n",mess);

  return 0;
}