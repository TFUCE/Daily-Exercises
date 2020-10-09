#include<iostream>
using namespace std;
/*��������*/
void swap(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
/*��׼ֵ����*/
int partion(int* array, int begin, int end) {
	int key = array[begin];
	int start = begin;
	while (begin < end) {
		while (begin < end && array[end] >= key)
			--end;
		while (begin < end && array[begin] <= key)
			++begin;
		swap(array, begin, end);
	}
	swap(array, start, end);
	return begin;
}

void quicksort(int* array, int begin, int end) {
	if (begin >= end)
		return;
	int keypos = partion(array, begin, end);
	quicksort(array, begin, keypos - 1);
	quicksort(array, keypos+1, end);
}

int main() {
	int n;
	cin >>n;
	int *array=new int[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	quicksort(array, 0, n-1);
	for (int i=0;i<n;i++)
		cout <<array[i]<<" ";
	delete[]array;
}

