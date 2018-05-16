/**
冒泡排序算法实现
**/
#include <iostream>
const int SIZE = 9;
using std::cout;
using std::endl;
void Show(int *arr, int len);
void Swap(int *arr, int i, int j);
void bubble_sort(int *arr, int len);

int main() {
	int a[SIZE] = { 42, 3, 12, 25, 9, 21, 17, 8, 23};
	bubble_sort(a, SIZE);
	Show(a, SIZE);
	return 0;
}

void bubble_sort(int *arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				Swap(arr, j, j + 1);
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