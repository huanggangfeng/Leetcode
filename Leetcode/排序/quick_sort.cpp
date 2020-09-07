//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void quicksort(std::vector<int> &v, int left, int right);

void init_vec(std::vector<int> &vec, int size)
{
	int i = 0;
	srand(time(NULL));
	while (i < size) {
		vec.emplace_back(rand() % 100);
		i++;
	}
}

int main() {
	std::vector<int> my_vec;
	init_vec(my_vec, 10);
	for (auto &i:my_vec)
		std::cout << i << "\t";
	cout << "\n";
	quicksort(my_vec, 0, my_vec.size() - 1);
	for (auto &i:my_vec)
		std::cout << i << "\t";
	return 0;
}

int partition(std::vector<int> &v, int left, int right)
{
	int key = v[left];
	while (left < right) {
		while (v[right] >= key && right > left)
			right--;
		int tmp = v[right];
		v[right] = v[left];
		v[left] = tmp;
		while (v[left] <= key && right > left)
			left++;
		tmp = v[right];
		v[right] = v[left];
		v[left] = tmp;
	}
	return left;
}

//[left, right]
void quicksort(std::vector<int> &v, int left, int right)
{
	if (left >= right)
		return;

	int pos = partition(v, left, right);
	quicksort(v, left, pos - 1);
	quicksort(v, pos + 1, right);
}
