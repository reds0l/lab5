//Jared Rodgers
//Lab 5
//main.cpp

using namespace std;
#include"Puzzle.h"
#include<iostream>

int main()
{

Puzzle<int> sudoku1;
Puzzle<int> sudoku2("sudoku.txt");
Puzzle<char> sudoku3("wordoku.txt");
Puzzle<int> sudoku4(4);
Puzzle<char> sudoku5;

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
