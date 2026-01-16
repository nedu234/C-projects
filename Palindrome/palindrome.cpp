#include <iostream>
using namespace std;

bool isPalindrome(char[], int, int);
const unsigned long int MAX = 10000;

int main()
{
	int length;
	string sentence;
	char item[MAX];
	cout << "Enter a string: ";
	cin >> sentence;
	length = sentence.length();
	bool result;
	int i;

	for (i = 0; i < length; i++)
	{
		item[i] = sentence[i];
	}

	result = isPalindrome(item, 0, length - 1);
	if (result == true)
		cout << "This is a palindrome." << endl;
	else if (result == false)
		cout << "This is not a palindrome." << endl;

}

bool isPalindrome(char items[], int first, int last)
{
	while (first < last)
	{
		if (items[first] != items[last])
			return false;
		else
		{
			first++;
			last--;
		}
	}
	return true;
}
