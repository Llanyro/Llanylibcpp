#include "../Corelib/Libs/llanytypeslib.h"

#define SORT_LIB Llanylib::Corelib::Libs::Math

/*
https://en.wikipedia.org/wiki/Sorting_algorithm


*/

namespace Llanylib {
namespace Corelib {
namespace Libs {
namespace Sort {

ll_bool_t bubbleSort(
	const void* memBlock,
	const len_t& inicio,
	const len_t& fin,
	const len_t& sizeType,
	Compare_int compare);

ll_bool_t selectionSort(
	const void* memBlock,
	const len_t& inicio,
	const len_t& fin,
	const len_t& sizeType,
	Compare_int compare);

ll_bool_t mergeSort(
	const void* memBlock_1,
	const len_t& inicio_1,
	const len_t& fin_1,

	const void* memBlock_2,
	const len_t& inicio_2,
	const len_t& fin_2,

	const len_t& sizeType,
	Compare_int compare);

#ifdef GPU_FUNCTIONS_ACTIVATED

namespace GPU {




} /* namespace Math */

#endif // GPU_FUNCTIONS_ACTIVATED





/*
 *We need 2 arrays 'a' and 'b', of equal size
 *Here 'a' is the primary array (i.e which contains initial
     input, and final output)
 *And 'b' is the temporary array,
     used for merging 2 sorted half's in 'a'
 */

void merge(int *a, int low, int mid, int high)
{
    int b[10000];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
void mergesort(int *a, int low, int high)
{
    if (low < high) {
        int m = (high + low) / 2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}


// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int* A, int* L, int leftCount, int* R, int rightCount) {
	int i, j, k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k = 0;

	while (i < leftCount && j < rightCount) {
		if (L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while (i < leftCount) A[k++] = L[i++];
	while (j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int* A, int n) {
	int mid, i, * L, * R;
	if (n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n / 2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid * sizeof(int));
	R = (int*)malloc((n - mid) * sizeof(int));

	for (i = 0; i < mid; i++) L[i] = A[i]; // creating left subarray
	for (i = mid; i < n; i++) R[i - mid] = A[i]; // creating right subarray

	MergeSort(L, mid);  // sorting the left subarray
	MergeSort(R, n - mid);  // sorting the right subarray
	Merge(A, L, mid, R, n - mid);  // Merging L and R into A as sorted list.
	free(L);
	free(R);
}



} /* namespace Math */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */
