#include <cstdio>
using namespace std;

void quickSort(int* arr, int begin, int end) {
	// termination condition
	if(end-begin <= 1)
		return;

	int pivot = arr[begin];
	int left = begin + 1;
	int right = end;

	while(1) {
		while(left<=right && arr[left]<=pivot)
			left++;
		while(left<=right && arr[right]>=pivot)
			right--;

		if(left>right)
			break;

		swap(arr[left], arr[right]);
	}

	swap(pivot, arr[right]);
	quickSort(arr, begin, right);
	quickSort(arr, right+1, end);
}
