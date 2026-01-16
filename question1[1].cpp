#include <iostream>
#include<string>
using namespace std;

int reverseDigit(int num);

int main()
{
	int number;
	int reversedNumber;
	cout << "Enter an integer: ";
	cin >> number;
	reversedNumber = reverseDigit(number);
	cout << "The number with its digits reversed is: " << reversedNumber << endl;

	cout << "Enter an integer: ";
	cin >> number;
	reversedNumber = reverseDigit(number);
	cout << "The number with its digits reversed is: " << reversedNumber << endl;

	cout << "Enter an integer: ";
	cin >> number;
	reversedNumber = reverseDigit(number);
	cout << "The number with its digits reversed is: " << reversedNumber << endl;
	return 0;
}

int reverseDigit(int num)
{
	string number = to_string(num);
	int digit;
	string newNumber;

	if (number[0] == '-')
	{
		newNumber = "-";
	}

	digit = ((number.length()) - 1);
	while (digit >= 0 && number[digit] == '0') {
		digit--;
	}

	for (int i = digit; i >= 0; i--)
	{
		newNumber += number[i];
	}
	int numeral = stoi(newNumber);
	return numeral;
}