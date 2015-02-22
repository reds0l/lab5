//Jared Rodgers
//Lab 5
//Puzzle.h

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

template <class T>
class Puzzle {

    public:

        Puzzle();
        Puzzle(int);
        Puzzle(string);
        void empty();
        void print();

    private:

        int size;
        vector < vector<T> > board;

};

template <class T> Puzzle<T>::Puzzle()
{
    size=9;
    empty();
}

template <class T> Puzzle<T>::Puzzle(int n)
{
    size=n;
    empty();
}

template <class T> Puzzle<T>::Puzzle(string filename)
{
    int i;
    T temp;
    vector <T> tempvector;
    size=9;

    ifstream infile;
    infile.open(filename.c_str());
    while(!infile.eof())
    {
        for(i=0 ; i<size ; i++)
        {
            filename >> tempvector;
            tempvector.push_back(temp);
        }
        board.push_back(tempvector);
        tempvector.clear();
    }
}

template <class T> void Puzzle<T>::empty()
{
    vector <T> temp;
    int i;

    for (i=0;i<size;i++)
    {
        temp.push_back(0);
    }
    for (i=0;i<size;i++)
    {
        board.push_back(temp);
    }
}

template <class T> void Puzzle<T>::print()
{
    int i;
    for (i=0;i<size;i++)
    {
        cout << board[i] << endl;
    }
}
