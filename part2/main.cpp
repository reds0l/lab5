//Jared Rodgers
//Lab 5
//main.cpp

using namespace std;
#include"Puzzle.h"
#include<iostream>

int main()
{

Puzzle<int> sudoku1;                    // runs default constructor with int
Puzzle<int> sudoku2("sudoku.txt");      // runs non-default with text file input
Puzzle<char> sudoku3("wordoku.txt");    // runs non-default with text file input
Puzzle<int> sudoku4(4);                 // runs non-default with integer input
Puzzle<char> sudoku5;                   // runs default constructor with char

//prints each out.
sudoku1.print();
cout << endl << endl;
sudoku2.print();
cout << endl << endl;
sudoku3.print();
cout << endl << endl;
sudoku4.print();
cout << endl << endl;
sudoku5.print();
}
