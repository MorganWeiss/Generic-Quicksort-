#include <algorithm>
#include <iostream>
#include <vector>




template<class T>
int partition(std::vector<T>& array, int low, int high) {
	int pivotIndex = (low + high) / 2;
	std::swap(array[pivotIndex], array[high]);
	
	int i = low;
	for (int j = low; j < high; j++) {
		if (array[j] < array[high]) {
			std::swap(array[i], array[j]);
			i++;
		}
	}
	std::swap(array[i], array[high]);

	return i;
}

template <class T>
void quicksort(std::vector<T>& array, int low, int high) {
	if (low >= high) return;

	int pivot = partition(array, low, high);
	quicksort(array, low, pivot - 1);
	quicksort(array, pivot + 1, high);
}

template <class T>
void sort(std::vector<T>& array) {
	int n = array.size();
	quicksort(array, 0, n-1);
}

template <class T>
void print(std::vector<T>& array) {
	for (auto it : array) {
		std::cout << it << " ";
	}
	std::cout << "\n";
}


int main() {
	std::vector<int> data = { 0,3,65,3,1,2,35,6 };
	int n = data.size();
	std::vector<int> temp(n,0);
	sort(data);
	print(data);


	std::cin.get();
}