/* Lock Based Concurrent Data Structure : San Kim (Ref : OSTEP) */
#include <stdio.h>
#include <pthread.h>

#define NUMCPUS 8
#define BUCKETS 101

/* Data Sturctures */
typedef struct __counter_t {
    int             global;
    pthread_mutex_t glock;
    int             local[NUMCPUS];
    pthread_mutex_t llock[NUMCPUS];
    int             threshold;
}counter_t;

typedef struct __node_t {
    int             key,value;
    struct __node_t *next;
}node_t;

typedef struct __list_t {
    node_t          *head;
    pthread_mutex_t lock;
}list_t;

typedef struct __queue_t {
    node_t          *head;
    node_t          *tail;
    pthread_mutex_t head_lock, tail_lock;
} queue_t;

typedef struct __hash_t {
    list_t lists[BUCKETS];

} hash_t;

/* Concurrent Counter */
void Counter_Init(counter_t *,int);
void Counter_Update(counter_t *, int threadID, int amt);
int  Counter_Get(counter_t *);

/* Concurrent Linked List */
void List_Init(list_t *);
int  List_Insert(list_t *, int);
int  List_LookUp();

/* Concurrent Queue */
void Queue_Init(queue_t *);
void Queue_Enqueue(queue_t *, int);
void Queue_Dequeue(queue_t *, int *);

/* Concurrent Hash Table */
void Hash_Init(hash_t *);
int  Hash_Insert(hash_t *, int);
int  Hash_LookUp(hash_t *, int);

