#include <iostream>

#include "Algorithms/QuickSort.h"


int main()
{
	int a[20] = { 4, 2, 3, 9, 5, 1, 7, 6, 8, 0, 12, 19, 16, 14, 11, 18, 17, 15, 13, 10 };

	quicksort(a, 20);

	for (int i = 0; i < 20; ++i)
	{
		std::cout << a[i] << std::endl;
	}
}

