typedef struct {
  int used;
  char* location;
} queue;

/* Enums are currently not being used. Commenting for future use.
enum {
  QUEUE_OK, // Never used, but is present in case of future need.
  QUEUE_ALLOC_FAILED, // Used when QueueInit() can't allocate the memory for Queue.
  QUEUE_POINTER_NULL, // When a NULL pointer is passed in any Queue function.
  QUEUE_APPEND_STRING_NULL, // When a NULL pointer is passed in QueueAppend().
  QUEUE_INVALID, // When a Invalid Queue is passed in QueueDestory.
  QUEUE_EMPTY_POP // When QueuePop() gets a NULL pointer instead of the Queue address.
};
*/

// ------------------------------------------------------------------------
// The queue must be passed by refrence. For eg -> QueueInit(&queue);, etc.
// ------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------
// [ANOTHER IMPORTANT NOTE]: ALWAYS USE QueueDestory() AFTER YOU ARE DONE WITH THE QUEUE, SO IT DOESN'T CAUSE A MEMEORY LEAK.
//---------------------------------------------------------------------------------------------------------------------------
// Initializes the queue, and store relevant information into the queue struct instance passed in by refrence.
// these include - used(the size of the queue) and location(in memory); for eg->
// queue myq;
// myq.used - current size of the queue.
// myq.location - current location of the queue in-memory(pointer).
void QueueInit(queue* q);

// Appends a given string to the end of the Queue, and returns the Index the new string is appended in.
int QueueAppend(queue* q, const char* str);

// As the name suggests, prints all the strings stored in the Queue.
void QueuePrintAll(queue* q);

// Pops the string in the 0 (first) Index of the Queue.
void QueuePop(queue* q);

// Gets a string stored in Queue at an Index, and returns it.
// ----------------------------------------------------------------------------------------------------
// [IMPORTANT]: REMEMBER TO free() WHATAVER address QueueGet() RETURNS, OR IT WILL CAUSE A MEMORY LEAK!
// for eg->
// queue myq;
// QueueAppend(&myq, "test");
// char* temp = QueueGet(&myq);
// printf("%s\n", temp); // prints the string returned from QueueAppend();
// free(temp); // [IMPORTANT]: FREE THE POINTER!
// ----------------------------------------------------------------------------------------------------
char* QueueGet(queue* q, int Index);

// Frees the memory by destroying the Queue. [IMPORTANT]: SHOULD BE DONE EVERYTIME A QUEUE IS MADE USING QueueInit(), OR IT CAUSE A MEMEORY LEAK!
void QueueDestroy(queue* q);
