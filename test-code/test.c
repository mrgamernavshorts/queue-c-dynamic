#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

queue myq;

int main() {
  QueueInit(&myq);
  QueueAppend(&myq, "henlo");
  QueueDestroy(&myq);
  QueueInit(&myq);
  //QueuePrintAll(&myq);
  QueueAppend(&myq, "ahh i think i leaked");
  QueueAppend(&myq, "time to pop two times and empty the queue, what could possibly go wrong?");
  //QueuePrintAll(&myq);
  printf("\n");
  QueuePop(&myq);
  QueueAppend(&myq, "hehehehehehehehehehe");
  QueueAppend(&myq, "hmmmmm");
  char* temp = QueueGet(&myq, 0);
  printf("%s\n", temp);
  free(temp);
  QueueDestroy(&myq);
  return 0;
}
