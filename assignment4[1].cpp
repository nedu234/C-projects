#include <iostream>
using namespace std;

class myInt
{
private:
	int number;//private variable for our class "myInt"

public:
	//public boolean functions that can access "number" but cannnot alter because of const involved. 
	//They would be called from the main function and an instance of our class would be passed to them, giving them access to "number"
	bool isPrimeNumber() const;  
	bool isSum() const;
	bool isMultiple7() const;
	bool isMultiple11() const;
	bool isMultiple13() const;
	myInt(int num);
};


int main()
{
	int integer;
	cout << "Enter an integer: ";
	cin >> integer;

	//Creates an instance of the structure myInt that takes the variable integer from main to initialize "number" in main
	myInt numeral(integer);

	//pass the instance "numeral" to the function isMultiple7 of our class to check if it's a multiple of 7
	if (numeral.isMultiple7())
		cout << "This integer is a multiple of 7" << endl;
	else
		cout << "This integer is not a multiple of 7" << endl;

	if (numeral.isMultiple11())
		cout << "This integer is a multiple of 11" << endl;
	else
		cout << "This integer is not a multiple of 11" << endl;

	if (numeral.isMultiple13())
		cout << "This integer is a multiple of 13" << endl;
	else
		cout << "This integer is not a multiple of 13" << endl;

	if (numeral.isSum())
		cout << "The sum of the digits of the integer is an even number." << endl;
	else
		cout << "The sum of the digits of the integer is an odd number." << endl;

	if (numeral.isPrimeNumber())
		cout << "The integer is a prime number." << endl;
	else
		cout << "The integer is not a prime number." << endl;

	cout << "Thank you!" << endl;

	return 0;
}

//Function declaration stating that the function isPrimenumber is a function of our class myInt and returns 
//a boolean functon.
//const in this declaration makes sure that when we're working with our variable we do not alter original value
bool myInt::isPrimeNumber() const
{
	if (number <= 1)
		return false;           // 0 and 1 are not prime
	if (number <= 3)
		return true;            // 2 and 3 are prime
	if (number % 2 == 0 || number % 3 == 0)
		return false;           // eliminate multiples of 2 and 3

	// Check only up to sqrt(n), skipping even numbers
	for (int i = 5; i * i <= number; i += 6) 
	{
		if (number % i == 0 || number % (i + 2) == 0)
			return false;
	}
	return true;
}

bool myInt::isSum() const
{
	int num2 = 0;
	int tempSum1 = 0;
	int tempSum2 = 0;

	if (number == 0)
		return false;

	tempSum1 = ((number + num2)) % 10;
	tempSum2 = (number / 10);

	if ((tempSum1 + tempSum2) % 2 == 0)
		return true;
	else
		return false;
}

bool myInt::isMultiple7() const
{
	if ((number % 7) == 0)
		return true;
	else
		return false;
}

bool myInt::isMultiple11() const
{
	if ((number % 11) == 0)
		return true;
	else
		return false;
}

bool myInt::isMultiple13() const
{
	if ((number % 13) == 0)
		return true;
	else
		return false;
}

myInt::myInt(int num)
{
	number = num;
}

