#include <stdio.h>
#include <malloc.h>

#define CAPACITY 10
struct stack {
	int top;
	int capacity;
	int *data;
} mystack;

struct stack *createstack()
{
	struct stack *s = malloc(sizeof(struct stack));
	if (!s)
		return NULL;
	s->capacity = CAPACITY;
	s->top = -1;
	s->data = malloc(sizeof(int)*s->capacity);
	if (!s->data) 
		return NULL;
	return s;
}

int isemptystack(struct stack *s)
{
	return (s->top == -1);
}

int isfullstack(struct stack *s)
{
	return (s->top == s->capacity-1);
}

void deletestack(struct stack *s)
{
	if (s) {
	    if (s->data) {
		free(s->data);
	    }
	}
}

void push(struct stack *s, int data)
{
	if (isfullstack(s)) {
		printf("stack full");
		return;
	}
	s->data[++s->top] = data;
	printf("top = %d data = %d\n", s->top, data);
        return;
}

int pop(struct stack *s) 
{
	if (isemptystack(s)) {
		printf("stack is empty");
		return -1;
	} else {
	    return s->data[s->top--];
	}
}
	
void main()
{
	int a,b,c;
	struct stack *s = createstack();
	if (s) {
		push(s,10);
		push(s,100);
		push(s,300);
		a = pop(s); b=pop(s); c=pop(s);
	        printf("%d %d %d \n", a, b, c);
	}
}

