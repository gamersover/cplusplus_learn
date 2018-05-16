/**
归并排序算法实现
**/
#include <iostream>
const int SIZE = 9;
using std::cout;
using std::endl;
void Show(int *arr, int len);
void Swap(int *arr, int i, int j);
void merge(int *arr, int start, int middle, int end);
void merge_sort(int *arr, int start, int end);

int main() {
	int a[SIZE] = { 42, 3, 12, 25, 9, 21, 17, 8, 23};
	bucket_sort(a, SIZE);
	Show(a, SIZE);
	std::cin.get();
	return 0;
}

void merge(int *arr, int start, int middle, int end) {
	int i = start, j = middle, k = 0;
	int *temp = new int[end - start];
	while (i < middle && j < end) {
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(j < end)
		temp[k++] = arr[j++];
	while(i < middle)
		temp[k++] = arr[i++];
	for (int p = start; p < end; p++)
		arr[p] = temp[p - start];
	delete[] temp;
}

void merge_sort(int *arr, int start, int end) {
	int middle = (start + end) >> 1;
	if (middle <= start)
		return;
	merge_sort(arr, start, middle);
	merge_sort(arr, middle, end);
	merge(arr, start, middle, end);
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