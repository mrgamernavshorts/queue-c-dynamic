// Use this for testing ig :D
#include "../include/queue.h"
#include <stdio.h>

int main(){
  queue idk;
  const char* buff = "yay";
  QueueInit(&idk);
  QueueAppend(&idk, buff);
  QueueAppend(&idk, "yay2");
  QueuePop(&idk);
  QueueAppend(&idk, "yay3");
  QueueAppend(&idk, "yay4");
  QueueAppend(&idk, "yay5");
  QueueAppend(&idk, "yay6");
  QueuePrintAll(&idk);
  printf("The value at Index 0 is: %s\n", QueueGet(&idk, 0));
  printf("The value at Index 1 is: %s\n", QueueGet(&idk, 1));

  printf("used: %i\n",idk.used);
  printf("location: %p\n",idk.location);

  QueueDestory(&idk);

  return 0;
}
