#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int main(){
  queue q;
  QueueInit(&q);
  QueueAppend(&q, "hmmmmmmmmm");
  QueueAppend(&q, "MORE hmmmmmmmmm");
  char* temp = QueueGet(&q, 0);
  char* temp2 = QueueGet(&q, 1);
  printf("%s\n", temp);
  printf("%s\n", temp2);
  QueuePop(&q);
  QueuePop(&q);
  QueueAppend(&q, "MORE MORE hmmmmmm");
  char* temp3 = QueueGet(&q,0);
  printf("%s\n", temp3);
  free(temp);
  free(temp2);
  free(temp3);
  QueueDestroy(&q);
  return 0;
}
