#include <iostream>

#include "Algorithms/QuickSort.h"


int main()
{
	int a[10] = { 4, 2, 3, 9, 5, 1, 7, 6, 8, 0 };

	quicksort(a, 10);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << a[i] << std::endl;
	}
}

