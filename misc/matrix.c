#include <stdio.h>

int main()
{
	int arr[5][5] = {{1,2,3,4,5},
		          {1,2,3,4,5},
			  {1,2,3,4,5},
			  {1,2,3,4,5},
			  {1,2,3,4,5}};
	int j;
	int rowmin=0, colmin=0;
	int rowmax=4, colmax=4;

	while (1) {
	    for (j=colmin; j <= colmax; j++) {
		    printf(" %d ",arr[rowmin][j]);
	    }
	    printf("\n");
	    ++rowmin;
	    for (j=rowmin; j <= rowmax; j++) {
		    printf(" %d ", arr[j][colmax]);
	    }
	    --colmax;
	    printf("\n");
	    for (j=colmax; j >= colmin; j--) {
	            printf(" %d ", arr[rowmax][j]);
	    }
	    printf("\n");
	    --rowmax;
	    for (j=rowmax; j >= rowmin; j--) {
	            printf(" %d ", arr[j][colmin]);
	    }
	    printf("\n");
	    ++colmin;
	    if (rowmin > rowmax || colmin > colmax) {
	        break;
	    }
	}
return 0;
}


