#include "QuickSort.h"

void quicksort(int* pArray, int nSize)
{
	int nTemp;

	switch (nSize)
	{
	case 0:
	case 1:
		break;

	case 2:
	{
		if (pArray[0] > pArray[1])
		{
			nTemp = pArray[0];
			pArray[0] = pArray[1];
			pArray[1] = nTemp;
		}
		break;
	}

	default:
	{
		constexpr int nPivotIndex = 0;
		int nLeftIndex = 0;
		int nRightIndex = nSize - 1;

		while (nLeftIndex <= nRightIndex)
		{
			while (pArray[nLeftIndex] <= pArray[nPivotIndex])
				nLeftIndex++;

			while (pArray[nRightIndex] >= pArray[nPivotIndex])
				nRightIndex--;

			nTemp = pArray[nLeftIndex];
			pArray[nLeftIndex] = pArray[nRightIndex];
			pArray[nRightIndex] = nTemp;

		}

		quicksort(pArray, nLeftIndex);
		quicksort(pArray + nLeftIndex, nSize - nLeftIndex);

		break;
	}
	}

	return;
}