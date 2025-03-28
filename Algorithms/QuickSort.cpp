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

		/* Left와 Right이 엇갈리기 전까지는 무한 반복 */
		while (true)
		{
			/* Left Index가 가리키는 값이 Pivot 보다 커질때까지 증가 시킴*/
			while (nLeftIndex < nSize - 1 && pArray[nLeftIndex] <= pArray[nPivotIndex])
				nLeftIndex++;

			/* Right Index가 가리키는 값이 Pivot 보다 작아질 때까지 증가 시킴*/
			while (nRightIndex > 0 && pArray[nRightIndex] >= pArray[nPivotIndex])
				nRightIndex--;

			/* 예외 : Left와 Right이 엇갈린 경우, Pivot과 Right 값 교환 */
			/* 교환하지 않으면 Pivot보다 값들이 전부 크거나 작은 경우, */
			/* Quicksort(5)에서 Quicksort(5)가 호출되는 무한 루프 오류 */
			/* 6 | 4 2 1 8 */
			/*         R L */
			if (nLeftIndex > nRightIndex)
			{
				nTemp = pArray[nRightIndex];
				pArray[nRightIndex] = pArray[nPivotIndex];
				pArray[nPivotIndex] = nTemp;

				break;
			}

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