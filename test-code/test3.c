#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  queue idk;
  QueueInit(&idk);
  QueueAppend(&idk,"Test1");
  QueueAppend(&idk,"Test2");
  char* temp = QueueGet(&idk, 0);
  printf("%s", temp);
  free(temp);
  QueuePop(&idk);
  QueueDestroy(&idk);
  return 0;
}
