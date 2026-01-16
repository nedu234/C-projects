/* STUDENT NAME: CHINEDU NWOYE

   STUDENT NUMBER: 200521504
   
   ASSIGNMENT NUMBER: #2
   
   PROGRAM NAME: asg2.cpp
   
   DATE WRITTEN: 04-03-2025

   PROBLEM STATEMENT: This C++ program predicts the molecular geometry of molecules based on formulas like
   ABb, where the approximate shape is one A atom in the centre surrounded by b B atoms.

   INPUT: info for one molecule and contains the chemical symbols for two elements, and the number of atoms the second element respectively

   OUTPUT: the approximate geometrical shape of one A atom surrounded by b B atoms

   MAIN ALGORITHM: declare integer and string variables
                   declare input and output file variables
				   link the input and output variables files to their appropriate files
				   error check the files to ensure know when the file buffer is in a fail state
				   priming read, get first set of values needed to start the loop
				   use end of file loop template
				   Inside the loop, use nested if to get the valence electron for the first element
				                    solve expression for the no of non bonding electrons and bonding domains
									use nested if to determine the shape of the molecule based on the values of b and bonding domain
                                    print out the shape of the molecules into the output file
				                    get next values
				   end of loop.
				   close input and output files
				   end of code

    MAJOR VARIABLES: b - no of chem_symb1 atoms
	                 val_electrons - no of valence electrons for central atom
					 bond_domains - no of bonding domains
					 nonbond_electrons - no of non bonding electrons
					 chem_symb1 - chemical symbol for first element in the input file
					 chem_symb2 - chemical symbol for second element in the input file
					 shapeOfMolecule - molecular geometry

   PROGRAM LIMITATIONS: hardcoded values of the valence electrons and the shape of molecule
                        almost no formatting of output is performed
   */

#include <iostream> //Header file for input and output
#include <fstream> //Header file for file input and output
using namespace std; //gives access to the library

int main()
{
	int b; //declares the no of atoms of the second element as an integer variable
	int val_electrons; //declares the no of valence electrons as an integer variable
	int bond_domains; //declares the no of bonding domains as an integer variable
	int nonbond_electrons; //declares the no of non bonding electrons as an integer variable
	string chem_symb1; //declares the first chemical symbol, A, as a string variable
	string chem_symb2; //declares the second chemical symbol, B, as a string variable
	string shapeOfMolecule; //declares the geometrical shape of the molecule as a chemical symbol

	//declare the file buffers
	ifstream inFile; //call the input file inFile
	ofstream outFile; //call the output file outFile

	//try to open the input file
	inFile.open("molecules.txt");

	//error check file open
	if (!inFile)
	{
		cout << "Could not open input file successfully.." << endl;
		return 1;
	} 

	//try to open output file
	outFile.open("geometricalshapes.txt");

	//error check file open
	if (!outFile)
	{
		cout << "Could not open output file successfully.." << endl;
		return 1;
	}

	inFile >> chem_symb1 >> chem_symb2 >> b; //gets the first values needed to enter the EOF loop
	while (inFile) //while loop runs till the end of the input file
	{
		//nested if to assign a value to val_electrons
		if (chem_symb1 == "Be") 
			val_electrons = 3;
		else if ((chem_symb1 == "C") || (chem_symb1 == "Si"))
			val_electrons = 4;
		else if ((chem_symb1 == "N") || (chem_symb1 == "P") || (chem_symb1 == "As"))
			val_electrons = 5;
		else if ((chem_symb1 == "O") || (chem_symb1 == "S") || (chem_symb1 == "Se"))
			val_electrons = 6;
		else if ((chem_symb1 == "F") || (chem_symb1 == "Cl") || (chem_symb1 == "Br") || (chem_symb1 == "I"))
			val_electrons = 7;
		else val_electrons = 8;

		nonbond_electrons = val_electrons - b; //substracts b from val_electrons and stores the value in nonbond_electrons
		bond_domains = nonbond_electrons / 2; // divides nonbond_electrons by 2 and stores the value in noOfBondDomain 

		//nested if to get the molecular geometry based on the values of b and bond_domains
		if (((b == 2) && (bond_domains == 0)) || ((b == 2) && (bond_domains == 3)))
			shapeOfMolecule = "linear";
		else if (((b == 2) && (bond_domains == 1)) || ((b == 2) && (bond_domains == 2)))
			shapeOfMolecule = "bent";
		else if ((b == 3) && (bond_domains == 0))
			shapeOfMolecule = "triagonal planar";
		else if ((b == 3) && (bond_domains == 1))
			shapeOfMolecule = "triagonal pyramidal";
		else if ((b == 3) && (bond_domains == 2))
			shapeOfMolecule = "T-shaped";
		else if ((b == 4) && (bond_domains == 0))
			shapeOfMolecule = "tetrahedral";
		else if ((b == 4) && (bond_domains == 1))
			shapeOfMolecule = "seesaw";
		else if ((b == 4) && (bond_domains == 2))
			shapeOfMolecule = "square planar";
		else if ((b == 5) && (bond_domains == 0))
			shapeOfMolecule = "triagonal bipyramidal";
		else if ((b == 5) && (bond_domains == 1))
			shapeOfMolecule = "square pyramidal";
		else if ((b == 6) && (bond_domains == 0))
			shapeOfMolecule = "octahedral";
		else shapeOfMolecule = "unknown";

		//outputs the geometrical shape
		outFile << "The geometrical shape of one " << chem_symb1 << " atom surrounded by " << b << " " << chem_symb2 << " atoms is " << shapeOfMolecule << endl;

		//gets the next values
		inFile >> chem_symb1 >> chem_symb2 >> b;
	}

	inFile.close(); //closes the input file
	outFile.close(); //closes the output file

	return 0; //end of code

}