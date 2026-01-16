/*STUDENT NAME: CHINEDU NWOYE
* 
* STUDENT NUMBER: 200521504
* 
* ASSIGNMENT NUMBER: 4
* 
* DATE WRITTEN: 04-04-2025
* 
* PROGRAM NAME: asg4.cpp
* 
* PROBLEM STATEMENT: This C++ program analyzes DNA. Checks if a person is anemic, a carrier, or normal. And checks
* if two people are related
* 
* INPUT: It contains the DNA of the two hemoglobin genes of four people
* 
* OUTPUT: It contains the analysis of all genes for sickle-cell anemia and relationship
* 
* MAIN ALGORITHM: header files
                  sub-function prototypes
				  declare constant value for 444 as it will be repititive in code 
				  declare eight character arrays
				  declare input and ouput file, link, then error check them
				  assign char values from the input file into their respective arrays
				  check if the 20th element in both the first and second gene of a person is T
				        output that the person is anemic
                  else check if only one gene has T in it's 20th element
				        output that the person is a carrier 
				  else
				        output that the person is normal 
				  if structure to check who is related to who based on what is returned from the boolean sub-function
				  check for AandB AandC AandD BandC BandD CandD
				  like that everyone has been checked
				  close input and output files 
				  end of program
* GET1GENE ALGORITHM: for loop that runs 444 times 
                         store the letters in the array in the same order they are gotten from the file
* 
* SAMEGENE ALGORITHM: for loop that runs 444 times
*                         check each element accordingly
*                         the loop only stops when two elements checked are not the same or when the index count reaches 444
* 
* MAJOR VARIABLES: These are the eight major arrays used
	 gene1A
	 gene2A
	 gene1B
	 gene2B
	 gene1C
	 gene2C
	 gene1D
	 gene2D
	 where A,B,C,D denote people, and 1 and 2 denote the first and second gene
*                 
*/
#include <iostream>//header file for input and output
#include <fstream>//header file for file input and output
using namespace std;//gives access to library

void get1Gene(ifstream&, char[], int);//sub-function prototype for get1Gene
bool sameGene(const char[],const char[], int);//sub-function prototype for sameGene

int main()//main function block entry
{
	const int ARRAY_SIZE = 444; //constant integer value declared for simplicity of code 

	//declares eight char arrays of size 444
	char gene1A[ARRAY_SIZE];
	char gene2A[ARRAY_SIZE];
	char gene1B[ARRAY_SIZE];
	char gene2B[ARRAY_SIZE];
	char gene1C[ARRAY_SIZE];
	char gene2C[ARRAY_SIZE];
	char gene1D[ARRAY_SIZE];
	char gene2D[ARRAY_SIZE];

	//declares input and output file variables
	ifstream inFile;
	ofstream outFile;

	//links input and output files buffers to actual files
	inFile.open("dna.txt");
	outFile.open("DNAanalysis.txt");

	//Error checks input file
	if (!inFile)//if there's a problem opening the input file,
	{
		cout << "Could not open input file successfully..." << endl; //print this
		return 1;//end program
	}

	//error checks output file
	if (!outFile)//if there's a problem opening the output file,
	{
		cout << "Could not open output file successfully..." << endl;//print this
		return 1;//end program
	}

	//calls get1Gene 8 times to share char values for all arrays initially created 
	get1Gene(inFile, gene1A, ARRAY_SIZE);
	get1Gene(inFile, gene2A, ARRAY_SIZE);
	get1Gene(inFile, gene1B, ARRAY_SIZE);
	get1Gene(inFile, gene2B, ARRAY_SIZE);
	get1Gene(inFile, gene1C, ARRAY_SIZE);
	get1Gene(inFile, gene2C, ARRAY_SIZE);
	get1Gene(inFile, gene1D, ARRAY_SIZE);
	get1Gene(inFile, gene2D, ARRAY_SIZE);

	//nested if else, analyzing all arrays to see who is anemic, a carrier, or normal
	if ((gene1A[19] == 'T') && (gene2A[19] == 'T'))//checks if 20th element of both the first and second gene is T
		outFile << "Person A is carrier." << endl;//yes? output this
	else if ((gene1A[19] == 'T') || (gene2A[19] == 'T'))//no? check if at least one has T in it's 20th element
		outFile << "Person A is a anemic." << endl;//yes? output this
	else //no one has T in their 20th?
		outFile << "Person A is normal." << endl;//output this

	if ((gene1B[19] == 'T') && (gene2B[19] == 'T'))//checks if 20th element of both the first and second gene is T
		outFile << "Person B is carrier." << endl;//yes? output this
	else if ((gene1B[19] == 'T') || (gene2B[19] == 'T'))//no? check if at least one has T in it's 20th element
		outFile << "Person B is a anemic." << endl;//yes? output this
	else//no one has T in their 20th?
		outFile << "Person B is normal." << endl;//output this

	if ((gene1C[19] == 'T') && (gene2C[19] == 'T'))//checks if 20th element of both the first and second gene is T
		outFile << "Person C is carrier." << endl;//yes? output this
	else if ((gene1C[19] == 'T') || (gene2C[19] == 'T'))//no? check if at least one has T in it's 20th element
		outFile << "Person C is a anemic." << endl;//yes? output this
	else//no one has T in their 20th?
		outFile << "Person C is normal." << endl;//output this

	if ((gene1D[19] == 'T') && (gene2D[19] == 'T'))//checks if 20th element of both the first and second gene is T
		outFile << "Person D is carrier." << endl;//yes? output this
	else if ((gene1D[19] == 'T') || (gene2D[19] == 'T'))//no? check if at least one has T in it's 20th element
		outFile << "Person D is a anemic." << endl;//yes? output this
	else//no one has T in their 20th?
		outFile << "Person D is normal." << endl;//output this

	//if structure to check who is related to who based on what is returned from the boolean sub-function
	//There are four conditions where personA can be related to personB, 
	if ((sameGene(gene1A, gene1B, ARRAY_SIZE)) || sameGene(gene1A, gene2B, ARRAY_SIZE) || sameGene(gene2A, gene1B, ARRAY_SIZE) || sameGene(gene2A, gene2B, ARRAY_SIZE))
		outFile << "Person A is related to person B." << endl;//output this is if any one of the conditions is true

	//There are four conditions where personA can be related to personC, 
	if ((sameGene(gene1A, gene1C, ARRAY_SIZE)) || sameGene(gene1A, gene2C, ARRAY_SIZE) || sameGene(gene2A, gene1C, ARRAY_SIZE) || sameGene(gene2A, gene2C, ARRAY_SIZE))
		outFile << "Person A is related to person C." << endl;//output this is if any one of the conditions is true

	//There are four conditions where personA can be related to personD, 
	if ((sameGene(gene1A, gene1D, ARRAY_SIZE)) || sameGene(gene1A, gene2D, ARRAY_SIZE) || sameGene(gene2A, gene1D, ARRAY_SIZE) || sameGene(gene2A, gene2D, ARRAY_SIZE))
		outFile << "Person A is related to person D." << endl;//output this is if any one of the conditions is true

	//There are four conditions where personB can be related to personC, 
	if ((sameGene(gene1B, gene1C, ARRAY_SIZE) || sameGene(gene1B, gene2C, ARRAY_SIZE) || sameGene(gene2B, gene1C, ARRAY_SIZE) || sameGene(gene2B, gene2C, ARRAY_SIZE)))
		outFile << "Person B is related to person C." << endl;//output this is if any one of the conditions is true

	//There are four conditions where personB can be related to personD, 
	if (sameGene(gene1B, gene1D, ARRAY_SIZE) || sameGene(gene1B, gene2D, ARRAY_SIZE) || sameGene(gene2B, gene1D, ARRAY_SIZE) || sameGene(gene2B, gene2D, ARRAY_SIZE))
		outFile << "Person B is related to person D." << endl;//output this is if any one of the conditions is true
	
	//There are four conditions where personC can be related to personD, 
	if(sameGene(gene1C, gene1D, ARRAY_SIZE) || sameGene(gene1C, gene2D, ARRAY_SIZE) || sameGene(gene2C, gene1D, ARRAY_SIZE) || sameGene(gene2C, gene2D, ARRAY_SIZE))
		outFile << "Person C is related to person D." << endl;//output this is if any one of the conditions is true

	inFile.close();//close input file
	outFile.close();//close output file

	return 0;//end of program
}

//getGene void sub-function definition
void get1Gene(ifstream& inFile, char gene[] , int ARRAY_SIZE)//takes input file by reference, array name, and array size
{
	for (int i = 0; i < ARRAY_SIZE; i++)//for loop runs 444 times
	{
		char letter;//declares char variabe for letter
		inFile.get(letter);//gets letter from input file
		gene[i] = letter;//stores every letters gotten from the input file into the proper array element
	}
}

//sameGene value-returning sub-function definition
bool sameGene(const char gene1[],const char gene2[], int ARRAY_SIZE)//takes two char array name and their size 
{
	for (int i = 0; i < ARRAY_SIZE; i++)//for loop that runs 444 times 
	{
		if (gene1[i] != gene2[i])//checks if gene1 and gene2 have the same character for every element 
			return false;//no? return false and sub-function ends meaning loop ends 
	}
	return true;//returns true when loop ends meaning all elements have been checked and no discrepancy
}