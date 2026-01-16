#include <iostream>
using namespace std;

const unsigned int ARRAY_MAXSIZE = 100;
int linearSearch(int[], int, int);

int main()
{
	int n;
	int target;
	int index;
	int number[ARRAY_MAXSIZE];
	cout << "Enter the number of elements that you want in the array: ";
	cin >> n;
	cout << "Enter the elements: ";

	for (int i = 0; i < n; i++)
	{
		cin >> number[i];  
	}

	cout << "Enter the element that you are searching for: ";
	cin >> target;
	index = linearSearch(number, n, target);
	if (index != -1)
		cout << "The index of " << target << " is " << index << endl;
	else
		cout << "The element " << target << "does not exist in the array" << endl;

	cout << "Thank you!" << endl;
	return 0;

}

int linearSearch(int num[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (num[i] == target)
			return i;
	}
	return -1;
}
