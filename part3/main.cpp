//Jared Rodgers
//Lab 5
//main.cpp

using namespace std;
#include"Puzzle.h"
#include<iostream>

int main()
{

Puzzle<int> sudoku1("sudoku.txt");

sudoku1.print();
cout << endl << endl;
sudoku1.addValue();
sudoku1.print();
}
