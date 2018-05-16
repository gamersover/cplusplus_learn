/**
堆排序算法实现
**/
#include <iostream>
const int SIZE = 9;
using std::cout;
using std::endl;
void Show(int *arr, int len);
void Swap(int *arr, int i, int j);
void build_heap(int *arr, int len);
void heap_sort(int *arr, int len);

int main() {
	int a[SIZE] = { 42, 3, 12, 25, 9, 21, 17, 8, 23};
	heap_sort(a, SIZE);
	Show(a, SIZE);
	return 0;
}

void build_heap(int *arr, int len) {
	int current, parent;
	for (int i = 1; i < len; i++) {
		current = i;
		parent = (current - 1) >> 1;
		while (arr[parent] < arr[current]) {
			Swap(arr, parent, current);
			current = parent;
			if (current <= 0)
				break;
			parent = (current - 1) >> 1;
		}
	}
}

void heap_sort(int *arr, int len) {
	int current, idx, last;
	int left, right;
	build_heap(arr, len);
	for (int i = 0; i < len - 1; i++) {
		current = 0;
		last = len - i - 1;
		Swap(arr, 0, last);
		while (current * 2 + 1 < last) {
			left = current * 2 + 1;
			right = current * 2 + 2;
			idx = left;
			if (right < last)
				idx = arr[right] > arr[left] ? right : left;
			if (arr[current] < arr[idx])
				Swap(arr, current, idx);
			else
				break;
			current = idx;
		}
	}
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