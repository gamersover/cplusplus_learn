/**
快速排序算法实现
**/
#include <iostream>
const int SIZE = 9;
using std::cout;
using std::endl;
void Show(int *arr, int len);
void Swap(int *arr, int i, int j);
int partition(int *arr, int start, int end);
void quick_sort(int *arr, int start, int end);

int main() {
	int a[SIZE] = { 42, 3, 12, 25, 9, 21, 17, 8, 23};
	bucket_sort(a, SIZE);
	Show(a, SIZE);
	std::cin.get();
	return 0;
}

int partition(int *arr, int start, int end) {
	int lptr = start + 1, rptr = end - 1, temp = arr[start];
	while (true) {
		while (arr[lptr] < temp && lptr < end)
			lptr++;
		while (arr[rptr] > temp && rptr > start)
			rptr--;
		if (lptr >= rptr)
			break;
		else
			Swap(arr, lptr, rptr);
	}
	Swap(arr, rptr, start);
	return rptr;
}

void quick_sort(int *arr, int start, int end) {
	if (start >= end)
		return;
	int pivot = partition(arr, start, end);
	quick_sort(arr, start, pivot);
	quick_sort(arr, pivot + 1, end);
}

void Show(int *arr, int len){
	for (int i = 0; i< len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Swap(int *arr, int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}