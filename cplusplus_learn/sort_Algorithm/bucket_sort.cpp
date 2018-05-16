/**
桶排序算法实现
**/
#include <iostream>
const int SIZE = 9;
using std::cout;
using std::endl;
void Show(int *arr, int len);
void Swap(int *arr, int i, int j);

struct Node {
	Node() {
		v = 0;
		next = NULL;
	}
	int v;
	Node *next;
};

Node* insert(Node *head, int v);
void bucket_sort(int *arr, int len, int buckets);

int main() {
	int a[SIZE] = { 42, 3, 12, 25, 9, 21, 17, 8, 23 };
	bucket_sort(a, SIZE, 5);
	Show(a, SIZE);
	return 0;
}

Node* insert(Node *head, int v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->v = v;
	if (head == NULL || head->v > node->v) {
		node->next = head;
		head = node;
	}
	else {
		Node *parent = (Node *)malloc(sizeof(Node));
		Node *current = (Node *)malloc(sizeof(Node));
		parent = head;
		current = parent;
		while (current != NULL && current->v < node->v) {
			parent = current;
			current = current->next;
		}
		parent->next = node;
		node->next = current;
	}
	return head;
}

void bucket_sort(int *arr, int len, int buckets) {
	Node **p;
	p = (Node **)malloc(sizeof(Node *) * buckets);
	for (int i = 0; i < buckets; i++)
		p[i] = NULL;
	Node *current;
	for (int i = 0; i < len; i++) {
		p[arr[i] / 10] = insert(p[arr[i] / 10], arr[i]);
	}
	for (int i = 0, k = 0; i < buckets; i++) {
		current = p[i];
		while (current != NULL) {
			arr[k++] = current->v;
			current = current->next;
		}
	}
}

void Show(int *arr, int len) {
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