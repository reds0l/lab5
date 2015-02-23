//Jared Rodgers
//Lab 5
//main.cpp

using namespace std;
#include"Puzzle.h"
#include<iostream>

int main()
{

Puzzle<int> sudoku1("sudoku.txt");

cout << endl << endl;
sudoku1.interactive();
}
