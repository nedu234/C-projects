/* NAME: CHINEDU NWOYE
SID: 200521504
ASSIGNMENT 1
CS110 code that converts tons to pounds, ounces, kilograms, grams and displays the conversion factors*/

#include <iostream> //Header files for input and output
#include <iomanip> //Header files for io manipulators
#include <fstream> //Header files for io stream
using namespace std;

int main()
{
	cout << fixed; //Avoids scientific notation in our output
	
	ifstream inFile; //Declares the variable inFile
	ofstream outFile; //Declares the variable outFile

	inFile.open("tons.txt"); //connects the inFile variable to the appropriate file
	outFile.open("report.txt"); //connects the outFile variable to the appropriate file

	if (!inFile) //Error checking to ensure that we know when buffer is in fail state
	{
		cout << "Can't open input file successfully. " << endl;
		return 1;
	}

	if (!outFile) //Error checking to ensure that we know when buffer is in fail state
	{
		cout << "Can't open output file successfully. " << endl;
		return 2;
	}

	int ton; //Declares the ton variable

	const double pound = 2204.62; //Declares the constant pound
	const int ounce = 35274; //Declares the constant ounce
	const int kilogram = 1000; //Declares the constant kilogram
	const int gram = 1000000; //Declares the constant gram

	inFile >> ton; //reads ton from "tons.txt"

	double result1; //Declares the variable result1
	int result2; //Declares the variable result2
	int result3; //Declares the variable result3
	int result4; //Declares the variable result4

	result1 = double(ton) * pound; //Calculates result1 and typecasts to prevent typecoersion
	result2 = ton * ounce; //Calculates result2 
	result3 = ton * kilogram; //Calculates result3
	result4 = ton * gram; //Calculates result4

	outFile << result1 << "pounds" << endl; //Prints result1 to "report.txt"
	outFile << result2 << "ounces" << endl; //Prints result2 to "report.txt"
	outFile << result3 << "kilograms" << endl; //Prints result3 to "report.txt"
	outFile << result4 << "grams" << endl; //Prints result4 to "report.txt"

	outFile << "1 ton = 2204.62pounds" << endl; //Prints conversion factors to "report.txt"
	outFile << "1 ton = 35274ounces" << endl;
	outFile << "1 ton = 1000kilograms" << endl;
	outFile << "1 ton = 1,000,000grams" << endl;

	inFile.close(); //closes input file
	outFile.close(); //closes output file

	return 0; //end of code
}
