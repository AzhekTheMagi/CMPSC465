/**
 * File Name: main.cpp
 * Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, 
 * debugging and validating this program, the program itself is my own work. I understand that submitting 
 * code which is the work of other individuals is a violation of the course Academic Integrity Policy and 
 * may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. 
 * I also understand that if I knowingly give my original work to another individual that it could also result in a 
 * zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board.
 * Assisted by and Assisted line numbers:
 * Name: Anthony Vallin
 * PSU ID: aav5195
 * Course title: CMPSC 465, Summer 2021
 * Due Time: 2359, Sunday, June 13, 2021
 * Time of Last Modification: 0945, Friday, June 11, 2021
 * Description: 
 **/

#include <iostream>
#include <string>
using namespace std;

//Function prototype
void parCheck(int leftP, int rightP, string str);

int main() {
    const int ARRAYSIZE = 3;      // Elements in array
    int n[ARRAYSIZE] = {2, 3, 4}; // Holds test case values

    //Tests 3 test cases for the parenthesis algorithm
    for (int i = 0; i < ARRAYSIZE; i++) {
        cout << "Test " << (i + 1) << ": " << endl;
        parCheck(n[i], n[i], "");
    }

    return 0;
}

void parCheck(int leftP, int rightP, string str) {
    
    //Prints valid sequence of left and right parenthesis. 
    if (!leftP && !rightP) {
        cout << str << endl;
    }

    //Uneven right and left parenthesis sequence is invalid and returns nothing.
    if (leftP > rightP) {
        return;
    }

    //Recursive call for left parenthesis, counting down until none left.
    if (leftP > 0) {
        parCheck(leftP - 1, rightP, str + "(");
    }

    //Recursive call for right parenthesis, counting down until none left.
    if (rightP > 0) {
        parCheck(leftP, rightP - 1, str + ")");
    }
}