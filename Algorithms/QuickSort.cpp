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

		/* Left�� Right�� �������� �������� ���� �ݺ� */
		while (true)
		{
			/* Left Index�� ����Ű�� ���� Pivot ���� Ŀ�������� ���� ��Ŵ*/
			while (nLeftIndex < nSize - 1 && pArray[nLeftIndex] <= pArray[nPivotIndex])
				nLeftIndex++;

			/* Right Index�� ����Ű�� ���� Pivot ���� �۾��� ������ ���� ��Ŵ*/
			while (nRightIndex > 0 && pArray[nRightIndex] >= pArray[nPivotIndex])
				nRightIndex--;

			/* ���� : Left�� Right�� ������ ���, Pivot�� Right �� ��ȯ */
			/* ��ȯ���� ������ Pivot���� ������ ���� ũ�ų� ���� ���, */
			/* Quicksort(5)���� Quicksort(5)�� ȣ��Ǵ� ���� ���� ���� */
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