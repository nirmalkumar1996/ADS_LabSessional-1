#ifndef MMB_H_INCLUDED
#define MMB_H_INCLUDED
#include<stdint.h>

typedef struct _customer_ Customer;

struct _customer_ {
    char* name;
    int32_t age;
    int32_t pan;
    int32_t acctype;
    char* phoneno;
    int32_t depamt;
};
typedef struct _account_details_ Account;

struct _account_details_ {
    char* name;
    int32_t acctype;
    char* accno;
};
typedef struct _queue_ Queue;
struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t rear;
    uint32_t front;
    Account a[MAX_QUEUE_LEN];
    Customer c[MAX_QUEUE_LEN];
};

typedef struct _queue_result_ QueueResult;

struct _queue_result_ {
    char* name;
    int32_t acctype;
    uint32_t status;
    uint32_t tstatus; //credit or dbit
};

Customer customer_new(char* name, int32_t age, int32_t pan, int32_t acctype, char* phoneno, int32_t depamt);
Queue queue_new(uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue* queue_add(Queue *q, Customer *c, QueueResult *res);
uint32_t queue_length(Queue *q);



#endif // MMB_H_INCLUDED
