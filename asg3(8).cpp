/*STUDENT NAME: CHINEDU NWOYE
* 
* STUDENT NUMBER: 200521504
* 
* ASSIGNMENT NUMBER: 3
* 
* PROGRAM NAME: asg3.cpp
* 
* DATE WRITTEN: 27-03-2025
* 
* PROBLEM STATEMENT: A C++ program that plays a variation of craps: a popular dice game played in the casinos
* 
* MAIN ALGORITHM: 1. Declare your header file for input and output and header file for time
* 2. Declare GetRoll, CalcSum, and PrintRoll sub-function prototypes as void, value-returning, and void respectively
* 3. Main function block entry
* 4. Declare necessary integer variables
* 5. Statement that helps prevent getting the same random number all the time
* 6. Get the first roll of the die, then the second
* 7. Sum them up
* 8. If else to use the sum gotten to know what to print
* 9. Is the sum 7 or 11? If yes, the player wins
* 10. If the sum is 2, 3 or 12, the player loses
* 11. If the sum is anything else, print that a point has been made
* 12. We get the first new numbers(priming read) for our sentinel loop
* 12. Then we enter the sentinel loop that loops until the new sum generated from the process is the same as the first sum or same as 7
* 13. The loop keeps printing then gets the next values (two new rolls of a die, and new sum)
* 14. If-else to know what to print. if new sum is same as old, the user wins
* 15. If new sum is 7, the user loses
* 16. Main function block exit
* 17. GetRoll sub-function definition that gets a random number between 1 and 6. This sub-function collects integers by reference
* 18. CalcSum sub-function definition that sums the two numbers it received by value and returns to main
* 19. PrintRoll sub-function definition that prints the results of the roll of two dice to the player
* 
* MAJOR VARIABLES: int no1- what the main function calls the first integer variable passed to GetRoll
* int no2- what the main function calls the second integer variable passed to GetRoll
* int sum1- what the main function calls the sum of the first two random numbers generated
* int sum2- what the main function calls the sum of the random numbers generated from the loop
* int sum- what the sub-function PrintRoll calls the sum of the first two random numbers generated
* int num1- what the sub-functions PrintRoll and CalcSum call the first random number generated
* int num2- what the sub-functions PrintRoll and CalcSum call the second randon number 
* 
* PROGRAM LIMITATIONS:  Hardcoded the possible rolled values in the if-else statements
*/

#include <iostream>//header file for input and output
#include <time.h>//header file for time
using namespace std;//gives access to library

void GetRoll(int&);//void sub-function that has an integer parameter that is passed by reference
int CalcSum(int, int);//value returning sub-function that has two integer parameters
void PrintRoll(int, int, int);// void sub-function that has three integer parameters

int main()//main function block entry
{
	int no1;//declares integer variable no1
	int no2;//declares integer variable no2
	int sum1;//declares integer variable sum1
	int sum2;//declares integer variable sum2

	srand(time(NULL));//helps generate a random number with time. This helps prevent getting the same random number all the time
	GetRoll(no1);//calls subfunction GetRoll and pass no1 to it
	GetRoll(no2);//call subfunction GetRoll and pass no2 to it 
	sum1 = CalcSum(no1, no2);//passes no1 and no2 to CalcSum to sum the both of them

	//nested if to know what to print
	if ((sum1 == 7) || (sum1 == 11))//is sum1 equal to 7 or 11
		//yes? enter this block
	{
		PrintRoll(no1, no2, sum1);//passes no1 no2 and sum1 to PrintRoll to print result of the roll
		cout << "You win" << endl;//prints that the user has won
		cout << "You are a natural" << endl;//prints that the user is a natural
	}
	//no? 
	else if ((sum1 == 2) || (sum1 == 12) || (sum1 == 3))//is sum1 2, 12 or 3?
		//yes? enter this block
	{
		PrintRoll(no1, no2, sum1);//passes no1 no2 and sum1 to PrintRoll to print result of the roll
		cout << "You lose" << endl;//prints that the user has lost
		cout << "Craps" << endl;//prints craps 
	}
	//is sum1 anything else?
	else
		//yes? enter this block
	{
		PrintRoll(no1, no2, sum1);//passes no1 no2 and sum1 to PrintRoll to print result of the roll
		cout << "Point is " << sum1 << endl;//prints the point to the screen
		
		//Gets new rolled values for out loop
		GetRoll(no1);//passes no1 to GetRoll to get a new random number
		GetRoll(no2);//passes no2 to GetRoll to get the second new random number
		sum2 = CalcSum(no1, no2);//sums the two new random numbers and saves it in the new sum

			//sentinel loop that runs until the the new sum generated is either equal to the previous sum or 7
		while((sum2 != sum1) || (sum2 != 7))
		{
			PrintRoll(no1, no2, sum2);//prints out the new roll for the player
				
			GetRoll(no1);//passes no1 to GetRoll to get a new random number
			GetRoll(no2);//passes no2 to GetRoll to get the second new random number
			sum2 = CalcSum(no1, no2);//sums the two new random numbers and saves it in the new sum
		}
		if (sum2 == 7)//is the new sum equal to 7?
		   //yes? enter this block
		{
			PrintRoll(no1, no2, sum2);//print out the new roll for the player
			cout << "You lose" << endl;//print that the user has lost
		}
		else // is the new sum anything else?
				//yes? enter this block
		{
			PrintRoll(no1, no2, sum2);//prints out the new roll for the player
			cout << "You win" << endl;//prints that the user has won
		}
	}
	return 0;//end of code
}

void GetRoll(int& num)//sub-function definition to get a random number
{
	num = rand() % 6 + 1; //gets a random number between 1 and 6
}

int CalcSum(int num1, int num2)//sub-function definition to sum the two random numbers
{
	int sum;//declares integer variable sum
	sum = num1 + num2;//adds the two random numbers and saves it in sum
	return sum;//return sum to main function
}

void PrintRoll(int num1, int num2, int sum)//sub-function definition to print result of rolled and added dice to screen
{
	cout << "You rolled " << num1 << " + " << num2 << " = " << sum << endl; //prints the rolled results to the screen
}
