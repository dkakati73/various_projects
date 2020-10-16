#include <stdio.h>
#include <malloc.h>

#define NUM_Q_ELEM 100
typedef struct qnode_tag {
	int data;
	//more fields here
} qnode;

typedef struct qctrl_tag {
	int head;
	int tail;
	qnode q[NUM_Q_ELEM];
} qctrl;

qctrl myq;

void initqueue()
{
	myq.head = myq.tail = -1;
}

int insertqueue(int data)
{
	if ((myq.tail +1)%NUM_Q_ELEM == myq.head) {
		//queue full. cannot insert 
		//return fail
		return -1;
	}
	myq.tail = (myq.tail +1 ) % NUM_Q_ELEM;
	myq.q[myq.tail].data = data;
	if (myq.head == -1) 
		myq.head = myq.tail;
	printf("data %d inserted at index %d\n", data, myq.tail);
}

int popqueue()
{
	int data;
	if (myq.head == -1) {
		printf("queue is empty\n");
		return -1;
	}
	data = myq.q[myq.head].data;
	printf("data %d removed from index %d \n", data, myq.head);
	if (myq.head == myq.tail) 
		myq.head = myq.tail = -1;
	else
		myq.head = (myq.head+1)%NUM_Q_ELEM;
	return data;
}

void printqueue()
{
	int i;
	if (myq.head == myq.tail) {
		printf("queue is empty");
		return;
	}

	if (myq.tail > myq.head) {
	       for (i = myq.head; i <= myq.tail; i++) {
	           printf("PQ read data %d from index %d\n", i, myq.q[i].data);	       
	       }
	} else {
	       for (i = myq.head; i < NUM_Q_ELEM; i++) {
	           printf("PQ read data %d from index %d\n", i, myq.q[i].data);	       
	       }
	       for (i = 0; i <= myq.tail; i++) {
	           printf("PQ read data %d from index %d\n", i, myq.q[i].data);	       
	       }
	}
}

void main(int argc, char **argv)
{
    initqueue();
    insertqueue(10);
    insertqueue(20);
    insertqueue(30);
    printqueue();
    popqueue();
    popqueue();
    popqueue();
    insertqueue(200);
    insertqueue(300);
    printqueue();


}
