#include <malloc.h>
#include <stdio.h>

typedef struct t {
	struct t *right;
	struct t *left;
	int data;
} bstx;

bstx * insert_bst(bstx *root, int value)
{
	if (root == NULL) {
            root = (bstx *)malloc(sizeof(bstx));
	    if (!root) return NULL;
	    root->data = value;
	    root->right = root->left = NULL;
	    printf("inserted value %d \n", value);
	    return root;
	} else if (value < root->data) {
		printf("taking left\n");
		root->left = insert_bst(root->left, value);
	} else {
		printf("taking right\n");
		root->right = insert_bst(root->right, value);
	}
        return root;
}

int search_bst(bstx *root, int value)
{
	if (root == NULL) return 0;
	if (root->data == value) return 1;
	if (value < root->data) return search_bst(root->left, value);
	else if (value > root->data) return search_bst(root->right, value);
	return 0;
}

void print_bst(bstx *root)
{
	if (root == NULL) {
		return;
	} 
	print_bst(root->left);
	printf(" %d ", root->data);
	print_bst(root->right);
}

int main()
{
	int list[] = { 5, 4, 8, 9, 1 };
        int c;
	bstx *bst = NULL;

	for (c=0; c < 5; c++) {
		bst = insert_bst(bst, list[c]);
	}
	print_bst(bst); printf("\n");
	printf("%d %d %d %d \n", search_bst(bst,5), search_bst(bst, 4), search_bst(bst, 200), search_bst(bst, 9));
}

