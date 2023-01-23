#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Function Prototypes
void DFS(int row, int col, vector<vector<char>>& matrix);
void regionsAlgo(vector<vector<char>>& matrixBoard);

int main() 
{
    vector<vector<char>> matrix;
    fstream inputFile;
    int n; //Holds number of rows and columns in matrix input file
    
    //Opens input file from repl.it
	inputFile.open( "proj3TestFile4.txt" );
    
    if (inputFile)
    {
        inputFile >> n;

        //Populate matrix from input file
        matrix.resize(n, vector<char>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                inputFile >> matrix[i][j];

        //Calculates regions
        regionsAlgo(matrix);

        //Displays regions 'taken' over by 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";

            cout << endl;
        }
    }
    else
        cout << "File failed to open!" << endl;

    inputFile.close();

    return 0;
}

/**
 * Function turns flippable (non-boundrey)'O's to 'X's and unflippable
 * 'P's back to 'O's. 
 **/
void regionsAlgo(vector<vector<char>>& matrix)
{
    int row = matrix.size();
    int col = matrix.size();
 
    //Check the first and last columns
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 'O')
            DFS(i, 0, matrix);
        if (matrix[i][col - 1] == 'O')
            DFS(i, col - 1, matrix);
    }

    //Check first row and last row
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[0][i] == 'O')
            DFS(0, i, matrix);
        if (matrix[row - 1][i] == 'O')
            DFS(row - 1, i, matrix);
    }

    //Flip 'O' to 'X' and 'P' to 'O'
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 'O')
                matrix[i][j] = 'X';
            if (matrix[i][j] == 'P')
                matrix[i][j] = 'O';
        }
    }
}

/**
* Function traverses boundries of a matrix, flipping any 'O' to 'P' as a flag 
* to signify an unflippable 'O'. 
**/
void DFS(int row, int col, vector<vector<char>>& matrix)
{
    if (row <= 0 || col <= 0    ||
        matrix[row][col] != 'O' ||
        row >= matrix.size()    || col >= matrix.size())
        return;

    //Flags unflippable 'O' to 'P'
    if (matrix[row][col] == 'O')
    {
        matrix[row][col] = 'P';

        //Checks matrix borders in order to prevent potential
        //overflow faults when called recursively
        if (row > 1)
            DFS(row - 1, col, matrix);
        if (row < matrix.size() - 2)
            DFS(row + 1, col, matrix);
        if (col > 1)
            DFS(row, col - 1, matrix);
        if (col < matrix.size() - 2)
            DFS(row, col + 1, matrix);
    }
}

/**
 * Output Sample: 3 Test Cases
 * ----
 * TestFile1:
 * X X X X X O 
 * X X X X X X 
 * X X X X X X 
 * X X X X X X 
 * X X X X O O 
 * X X X X X X
 * ----
 * TestFile2:
 * X O X X 
 * X X X X 
 * X X X X 
 * X X X X
 * ----
 * TestFile3
 * X O X X 
 * X X X O 
 * X X X X 
 * X X X X
 * ----
 * TestFile4
 * X O X X 
 * X X X X 
 * X X X X 
 * X O X O
 **/