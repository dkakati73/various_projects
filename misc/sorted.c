#include <stdio.h>
#include <malloc.h>

typedef struct t {
	struct t *next;
	int v;
} node;

void print(node *root)
{
	if (!root) {
		printf("tree is empty\n");
		return;
	}
	while (root) {
		printf(" %d ", root->v);
		root=root->next;
	}
	printf("\n");
}

void insert(node **root, int v) {

	node *tnode = malloc(sizeof(node));
	if (!tnode) {
		return;
	}
	tnode->v = v;
	tnode->next = *root;
	*root = tnode;
	return;
}

node *merge_sorted(node **root1, node **root2)
{
	node *headnode = NULL, *x = NULL;
	node *t1 = *root1;
	node *t2 = *root2;

	if (!*root1) {
		return *root2;
	}
	if (!*root2) {
		return *root1;
	}

	while (1) {
	if (!t1) {
		printf("t1 is over\n");
		break;
	} else if (!t2) {
		printf("t2 is over\n");
		break;
	} else if (t1 && t2) {
		if (t1->v > t2->v) {
		    printf("t1 > t2\n");
		    if (t1->next) {
		        while (t1->next->v > t2->v) 
			    t1 = t1->next;
		    }
		    if (!headnode) { 
			    headnode = t1;
			    printf("headnode val: %d \n", headnode->v);
		    }
		    x = t1->next;
		    t1->next = t2;
		    t1 = x;
		} else {
		    printf("t1 <= t2\n");
		    if (t2->next) {
		        while (t2->next->v > t1->v) 
			    t2 = t2->next;
		    }
		    if (!headnode) {
			    headnode = t2;
			    printf("headnode val: %d \n", headnode->v);
		    }
		    x = t2->next;
		    t2->next = t1;
		    t2 = x;
		}
        }
	}
        return headnode;
}

void remove_dupvals(node **root)
{
	node *r = *root;
        node *t = NULL, *f, *g;
	int skipval = 0;

	while (r) {
		t = r;
		printf("considering %d \n", t->v);
	        skipval = 0;
		if (r->next) {
		    while (r->v == r->next->v) {
			    printf("skipping %d\n", r->v);
			    r=r->next;
			    skipval = 1;
		    }
		}
		if (skipval) {
		    printf("changing pointer %p to %p \n", t->next, r);
		    t->next = r;
		}
		r = r->next;
	}
        print(*root);
}

int main()
{
   node *root1 = NULL, *root2 = NULL;

   insert(&root1, 1);
   insert(&root1, 3);
   insert(&root1, 5);
   insert(&root1, 6);
   print(root1);

   insert(&root2, 2);
   insert(&root2, 4);
   insert(&root2, 5);
   insert(&root2, 8);
   print(root2);

   node *root3 = merge_sorted(&root1, &root2);
   print(root3);
   remove_dupvals(&root3);
   print(root3);
   return 0;
}

