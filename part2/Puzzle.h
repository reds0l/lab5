//Jared Rodgers
//Lab 5
//Puzzle.h

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<typeinfo>
using namespace std;

template <class T>
class Puzzle {

    public:

        Puzzle();           // default constuctor
        Puzzle(int);        // non-default constuctor with int input
        Puzzle(string);     // non-default constuctor with char input
        void empty();       // empties the board
        void print();       // prints the board

    private:

        int size;                       // size of board
        vector < vector<T> > board;     // 2d vector array

};

// creates board defaulted to size 9
template <class T> Puzzle<T>::Puzzle()
{
    size=9;     // defaults to size of 9
    empty();    // makes board empty
}

//creates board with size input
template <class T> Puzzle<T>::Puzzle(int n)
{
    size=n;     // input n is size of board
    empty();    // makes board empty
}

// creates board with file input
template <class T> Puzzle<T>::Puzzle(string filename)
{
    int i;
    T temp;                 // makes a temp variable out of templated type
    vector <T> tempvector;  // makes a temp vector out of templated type
    size=9;

    ifstream infile;                // sets file to read in to program
    infile.open(filename.c_str());  // opens file
    while(!infile.eof())            // keeps going while file is not at end
    {
        for(i=0 ; i<size ; i++)
        {
            infile >> temp;
            if (typeid(T) == typeid(char) && temp==' ') // makes sure space is not taken as input
            {
                i--;
                continue;
            }
            tempvector.push_back(temp); // pushs one entry from file into temp vector
        }
        board.push_back(tempvector);    // pushs temp vector into main board
        tempvector.clear();             // clears temp vector
    }
    infile.close();                 // closes file
}

// creates empty board all 0's 
template <class T> void Puzzle<T>::empty()
{
    vector <T> temp;
    int i;

    for (i=0;i<size;i++)
    {
        if (typeid(T) == typeid(char)) // if T is char inputs char
            temp.push_back('0');
        else
            temp.push_back(0);
    }
    for (i=0;i<size;i++)
    {
        board.push_back(temp);
    }
}

// prints board
template <class T> void Puzzle<T>::print()
{
    int i,j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
