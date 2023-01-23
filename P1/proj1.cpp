/**
 * File Name: proj1.cpp
 *
 * Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, 
 * the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course 
 * Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. 
 * I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, 
 * or course failure and a report to the Academic Dishonesty Board.
 * Assisted by and Assisted line numbers:
 *
 * Name: Anthony Vallin
 * User ID: aav5195
 * Course Title: CMPSC465, Summer 2021
 * Due: 2359, Sunday, May 30, 2021
 * Time of Last Modification: 0900, Thursday, May 27, 2021
 * Program checks if a sequence (block) of random integers can be reorganized 
 * into the same order found in the input file. 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<int> trainStation; // Train car transfer from track A to track B
	fstream    inputFile;    // Reads file
	ofstream   writeFile;    // Writes file
	int trainCar[162];       // Holds each train block from input file
	int n;                   // Total # of train cars per input file block
	
	// Opens input file from repl.it
	inputFile.open( "lab1in.txt" );
	// Repl.it write file
	writeFile.open( "lab1output.txt" );
	
	if (inputFile && writeFile)
	{
		do
		{
			inputFile >> n; // Total number of cars per block. Note: trainCoach array requires resizing if n changes.

			while (inputFile >> trainCar[0] && trainCar[0]) // trainCar[0] always assigned the first value from the line block.
			{
				for (int i = 1; i < n; i++)   // The values after the first value from the line block are copied to array.
					inputFile >> trainCar[i];

				while (!trainStation.empty()) // Previous contents of stack removed.
					trainStation.pop();

				int tCar = 0, aTrack = 1;     // Holds current positions of respective train cars.

				while (aTrack < n)               
				{
					if (aTrack == trainCar[tCar])  // "Moves" train car from train station(stack) to "track B"
					{
						tCar++;
						while (!trainStation.empty() && trainStation.top() == trainCar[tCar])
						{
							trainStation.pop();
							tCar++;
						}
					}
					else                           // "Moves" train car from track A to train station (stack)
						trainStation.push(aTrack);
					aTrack++;
				}

				if (trainStation.empty()) // Empty station means train blocks from track A xferred to track B in order of input file.
				{
					writeFile << "Yes" << endl;
				}
				else
				{
					writeFile << "No" << endl;
				}
			}
		} while (n);
	}
	else
		cout << "Read and/or Write file failed to open" << endl;
	
	inputFile.close();
	writeFile.close();
	
	return 0;
}

/** Output
 * No
 *Yes
 *No
 *No
 *No
 *Yes
 *Yes
 */