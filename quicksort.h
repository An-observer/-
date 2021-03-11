#pragma once

void quickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int temp = arr[left];

		while (i < j)
		{
			while (i<j && arr[j] >= temp)
				j--;
			arr[i] = arr[j];
			while (i < j && arr[i] <= temp)
				i++;
			arr[j] = arr[i];
		}
		arr[i] = temp;

		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}
	else
		return;
}