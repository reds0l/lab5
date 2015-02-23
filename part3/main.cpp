//Jared Rodgers
//Lab 5
//main.cpp

using namespace std;
#include"Puzzle.h"
#include<iostream>

int main()
{

Puzzle<int> sudoku1("sudoku.txt");  // creates given sudoku board

cout << endl << endl;
sudoku1.interactive();              // starts interactive mode
}
