#include <iostream>
using namespace std;

const unsigned int ARRAY_MAXSIZE = 100;

void sortArray(int[], int);
int binarySearch(int[], int, int);
void printArray(int[], int);

int main()
{
	int n;
	int number[ARRAY_MAXSIZE];
	int target;
	cout << "Enter the number of elements of you want in the array: ";
	cin >> n;
	cout << "Enter the elements: ";

	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}

	sortArray(number, n);
	cout << "The sorted array is ";
	printArray(number, n);

	cout << "Enter the element you are searching for: ";
	cin >> target;

	if (binarySearch(number, n, target) != -1)
		cout << "The index of " << target << " is " << binarySearch(number, n, target) << endl;
	else
		cout << "Thee element " << target << " does not exist in the array" << endl;

	cout << "Thank you!" << endl;

	return 0;
}

void sortArray(int num[], int size)
{
	int tempNum;
	for (int i = size-1; i > 0; i--) 
	{
		int largestIndex = 0;
		for (int j = 1; j <= i; j++)
		{
			if (num[largestIndex] < num[j])
				largestIndex = j;
		}
		tempNum = num[i];
		num[i] = num[largestIndex];
		num[largestIndex] = tempNum;
	}
}

void printArray(int num[], int size)
{
	for (int i = 0; i < size; i++)
		cout << num[i] << " ";
	cout << endl;
}

int binarySearch(int num[], int size, int target)
{
	int mid, difference;
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		mid = ((low + high) / 2);
		difference = num[mid] - target;

		if (difference == 0)
			return mid;
		else if (difference < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}