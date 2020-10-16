#include <stdio.h>
#include <malloc.h>


char memory[1000];

typedef struct t {
	int free;
	int size;
	struct t *next;
} mnode;

void* allocate(int size)
{
	mnode *m = (mnode *)&memory[0];

	while (m != NULL) {
		if (m->free && size <= m->size - sizeof(mnode)) {
			mnode *next = (mnode*)((char*)m + sizeof(mnode) + size);
			next->free = 1;
			next->next = m->next;
			next->size = m->size - size - sizeof(mnode);
			m->size = size;
			m->next = next;
			next->free = 0;
                        return (void*)(++m);
		} else {
			m = m->next;
		}
	}
	return NULL;
}


void initmem()
{
	mnode *m = (mnode *)&memory[0];
	m->free = 1;
	m->next = NULL;
	m->size = 1000 - sizeof(mnode);
}

void merge()
{
	mnode *m = (mnode *)&memory[0];

	while (m != NULL) {
		if (m->free == 1 && m->next && m->next->free == 1) {
	            m->size = m->size + sizeof(mnode) + m->next->size;
                    m->next = m->next->next;
		} else {
			m = m->next;
		}
	}
}

void free(void *mem)
{
	// check that range (void*)memory <= mem && mem <= (void*)(memory+1000)
	mnode *m = mem;
	--m;
	m->free = 1;
	merge();
}




int main()
{


}
