#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void QueueInit(queue* q){
  if(q == NULL) {printf("[ERROR]: Null passed in QueueInit, doing nothing. (QueueInit)\n"); return;}
  char* temp = malloc(0);

  if(temp == NULL){
    printf("[ERROR]: malloc returned NULL, doing nothing. (QueueInit)\n");
  } else {
    q->location = temp;
    q->used = 0;
  }
}

int QueueAppend(queue* q, const char* str){
  if(q == NULL) {printf("[ERROR]: Null pointer passed in QueueAppend, doing nothing and returning 1. (QueueAppend)\n"); return 1;}
  else if(str == NULL){printf("[ERROR]: String passed down in QueueAppend is NULL, doing nothing and returning 1. (QueueAppend)\n"); return 1;}
  else if(q->location == NULL){printf("[ERROR]: Invalid Queue, doing nothing and returning 1. (QueueAppend)\n"); return 1;}

  int newStrlen = strlen(str) + 1;

  char* temp = realloc(q->location, q->used+newStrlen);

  if(temp == NULL){
    printf("[ERROR]: realloc() failed for appending the Queue, doing nothing. (QueueAppend)\n");
    return 1;
  }
  q->location = temp;

  int Index = 0;
  for (int i = 0; i < q->used; i++) {
    if (*(q->location+i) == '\0') Index++;
  }

  memcpy(q->location+q->used, str, newStrlen);
  q->used += newStrlen;

  return Index;
}

void QueuePrintAll(queue *q){
  if(q == NULL) {printf("[ERROR]: Null pointer passed in QueuePrintAll, doing nothing.\n"); return;}
  else if(q->location == NULL){printf("[ERROR]: Invalid Queue, doing nothing. (QueuePrintAll)\n"); return;}

  for(int i = 0; i < q->used; i++){
    if(*(q->location+i) == '\0') {printf("\n"); continue;}
    printf("%c", *(q->location+i));
  }
}

void QueueDestroy(queue *q){
  if(q == NULL) {printf("[ERROR]: Null pointer passed in QueueDestory, doing nothing.\n"); return;}
  else if(q->location == NULL){printf("[ERROR]: Invalid Queue, doing nothing. (QueueDestroy)\n"); return;}

  free(q->location);
  q->location = NULL;
  q->used = 0;
}

void QueuePop(queue* q){
  if(q == NULL) {printf("[ERROR]: Null pointer passed in QueuePop, doing nothing.\n"); return;}
  else if(q->location == NULL){printf("[ERROR]: Invalid Queue. (QueuePop)\n"); return;}
  else if(q->used == 0){printf("[ERROR]: Popping from a empty Queue, doing nothing. (QueuePop)\n"); return;}

  int firstIndexSize = strlen(q->location)+1;

<<<<<<< HEAD
  char tval[firstIndexSize];
  
  memcpy(tval, q->location, firstIndexSize);

  char* val = tval;

=======
>>>>>>> 5ebfade (Fixed dangling pointers, improved dev experience, improved documentation, and fixed README.md)
  for(int i = 0; i < q->used-firstIndexSize; i++){
    *(q->location+i) = *(q->location+firstIndexSize+i);
    *(q->location+firstIndexSize+i) = 0;
  }
  char* temp;
  if(q->used-firstIndexSize == 0){
    free(q->location);
    q->location = malloc(0);
    q->used = 0;
  } else {
    temp = realloc(q->location, q->used-firstIndexSize);
    if(temp == NULL){
      printf("[ERROR]: realloc() failed for popping the element in Queue, doing nothing. (QueuePop)\n");
      return;
    } else {
        q->location = temp;
        q->used -= firstIndexSize;
    }
  }



}

char* QueueGet(queue* q, int Index){
  if(q == NULL) {printf("[WARNING]: Null pointer passed in QueuePop, returning NULL.\n"); return NULL;}
  else if(q->location == NULL){printf("[ERROR]: Invalid Queue, returning NULL.(QueueGet)\n"); return NULL;}

  if(Index == 0){
    char* str = malloc(strlen(q->location)+1);
    if(str != NULL){
      memcpy(str, q->location, strlen(q->location)+1);
      return str;
    } else {
      printf("[WARNING]: Could not malloc(), returning NULL pointer.(QueueGet)\n");
      return str;
    }
  }

  int bytesOffset = 0;
  int NullTermCount = 0;
  int IndexFound = 0;

  for(int i = 0; i < q->used; i++){
    if(*(q->location+i) == '\0') NullTermCount++;
    if(NullTermCount == Index) {bytesOffset = i+1; IndexFound = 1; break;}
  }

  if(!IndexFound){
    printf("[ERROR]: Index out of range, Returning NULL. (QueueGet)\n");
    return NULL;
  }
<<<<<<< HEAD

  char val[strlen(q->location+bytesOffset)+1];
  memcpy(val, q->location+bytesOffset, strlen(q->location+bytesOffset)+1);
  return val;
=======
  char* str = malloc(strlen(q->location+bytesOffset)+1);
  if(str != NULL){
    memcpy(str, q->location+bytesOffset, strlen(q->location+bytesOffset)+1);
    return str;
  } else {
    printf("[WARNING]: Could not malloc(), returning NULL pointer.(QueueGet)\n");
    return str;
  }
>>>>>>> 5ebfade (Fixed dangling pointers, improved dev experience, improved documentation, and fixed README.md)
}
