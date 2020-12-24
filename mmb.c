#include <assert.h>
#include <stddef.h>
#include<stdint.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "appconst.h"
#include "mmb.h"

Customer customer_new(char* name, int32_t age, int32_t pan, int32_t acctype, char* phoneno, int32_t depamt){
    Customer c = {name, age, pan, acctype, phoneno, depamt};
    return c;
}

Queue queue_new(uint32_t size){
    size = ( size > 0 && size < MAX_QUEUE_LEN ) ? size : MAX_QUEUE_LEN;
    Queue q1 =  { size, 0,0,0,NULL,{0} };
    return q1;
}

uint8_t queue_full(Queue *q){
    assert( q != NULL );
    return ( q->count == q->size );
}

uint8_t queue_empty(Queue *q){
    assert( q != NULL );
    return ( q->count == 0 );
}

static char* _generate_accno_(int32_t acctype, int32_t count){

    char* accno;
    char* bankcode= malloc(12);
    snprintf(bankcode, sizeof(bankcode), "%d", BANKCODE);
    char* areacode = malloc(12);
    snprintf(areacode, sizeof(areacode), "%d", AREACODE);
    char* atype = malloc(12);
    snprintf(atype, sizeof(atype), "%d", acctype);
    accno = strcat(bankcode,areacode);
    accno = strcat(accno,atype);
    if (count < 10){
        char* a = (char*)000;
        char* b = (char*)count + '0';
        char* c = strcat(a,b);
        accno = strcat(accno,c);
    }else if ( count >= 10 && count < 100){
        char* a = (char*)00;
        char* b = (char*)count + '0';
        char* c = strcat(a,b);
        accno = strcat(accno,c);
    }else if ( count >= 100 && count < 1000){
        char* a = (char*)0;
        char* b = (char*)count + '0';
        char* c = strcat(a,b);
        accno = strcat(accno,c);
    }
    return accno;
}

Queue* queue_add(Queue *q, Customer *c, QueueResult *res){
    assert( q != NULL );
    if ( q->count < q->size ){
        q->c[q->rear] = *c;
        q->a[q->rear].name = c->name;
        q->a[q->rear].acctype = c->acctype;
        char* accno = _generate_accno_(c->acctype, q->count);
        q->a[q->rear].accno = accno;
        q->rear = (q->rear+1)%q->size;
        ++q->count;
        res->status = QUEUE_OK;
    }else{
        res->status = QUEUE_FULL;
    }
    return q;
}

uint32_t queue_length(Queue *q){
    assert( q != NULL );
    return q->count;
}

