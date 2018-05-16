/**
希尔排序算法实现
**/
#include <iostream>
const int SIZE = 9;
using std::cout;
using std::endl;
void Show(int *arr, int len);
void Swap(int *arr, int i, int j);
void shell_sort(int *arr, int len);

int main() {
	int a[SIZE] = { 42, 3, 12, 25, 9, 21, 17, 8, 23};
	shell_sort(a, SIZE);
	Show(a, SIZE);
	return 0;
}

void shell_sort(int *arr, int len) {
	int h = 1;
	while (h <= len / 3)
		h = 3 * h + 1;
	while (h >= 1) {
		for (int i = h; i < len; i += h) {
			for (int j = i - h; j >= 0; j -= h) {
				if (arr[j] > arr[j + h])
					Swap(arr, j, j + h);
			}
		}
		h = (h - 1) / 3;
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