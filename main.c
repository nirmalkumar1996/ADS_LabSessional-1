#include <assert.h>
#include <stddef.h>
#include<stdint.h>
#include<string.h>
#include<stdio.h>
#include "appconst.h"
#include "mmb.h"
#include <stdlib.h>

void test_empty(){
    Queue q1 = queue_new(2);
    Queue *q = &q1;
    assert(queue_empty(q));
}

void test_addQ(){

    Customer c1 = customer_new('Nirmal', 24, 100, CURRENT, '9035194396', 1000);
    Customer c2 = customer_new('kumar', 22, 101, SAVING, '9035194392', 2000);
    Customer c3 = customer_new('Ankit', 15, NULL, STUDENT, '9035194393', 100);
    Customer c4 = customer_new('sam', 34, 102, SALARY, '9035194394', 5000);
    Customer c5 = customer_new('ram', 54, 103, JOINT, '9035194395', 3000);

    Queue q1 = queue_new(5);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q,&c1,&res);
    q = queue_add(q,&c2,&res);
    q = queue_add(q,&c3,&res);
    q = queue_add(q,&c4,&res);
    assert(queue_length(q) == 4);
    assert(res.status == QUEUE_OK);

}
int main()
{
    //printf("Hello world!\n");
    //test_empty();
    test_addQ();
    return 0;
}
