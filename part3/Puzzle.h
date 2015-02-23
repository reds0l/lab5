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
        void addValue();    // adds value to board
        int validPlacement(int, int, int);  // checks if value can be placed
        int checkBox(int, int, int);    // checks value can be placed in 3x3
        void isComplete();          // checks if board is complete
        void interactive();         // starts interactive mode

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

// addes value to board (user input)
template <class T> void Puzzle<T>::addValue()
{
    int x, y, value;
    do
    {
        cout << "Enter the row for your value (0-8):" << endl;
        cin >> x;
        cout << "Enter the column for your value (0-8):" << endl;
        cin >> y;
        cout << "Enter the value you want to place(0-9):" << endl;
        cin >> value;
    }while (validPlacement(x,y,value)!=1);

    board[x][y] = value;
}

// checks if placement on the board is valid
template <class T> int Puzzle<T>::validPlacement(int x, int y, int value)
{
    if (x<0 || x>=size)         // checks if in row bounds 
    {
        cout << "Invalid input for row" << endl << endl;
        return 0;
    }
    else if (y<0 || y>=size)    // checks if in column bounds
    {
        cout << "Invalid input for column" << endl << endl;
        return 0;
    }
    if (value<0 || value>9)    // checks if in value bounds
    {
        cout << "Invalid input for value" << endl << endl;
        return 0;
    }
    if (value==0)
    {
        return 1;
    }

    int i,j;
    for (i=0;i<size;i++)
    {
        if (value==board[i][y]) // checks if there are any row conflicts
        {
            cout << "column conflict" << endl << endl;
            return 0;
        }
        if (value==board[x][i]) // checks if there are any col conflicts
        {
            cout << "row conflict" << endl << endl;
            return 0;
        }
    }
    
    // determines which 3x3 grid the value is being placed
    // in and passes those values to the check box method
    int boxX, boxY, boxCheck;
    (x<3 ? boxX=0 : (x>5 ? boxX=2 : boxX=1));
    (y<3 ? boxY=0 : (y>5 ? boxY=2 : boxY=1));
    boxCheck=checkBox(boxX, boxY, value);
    if (boxCheck==1)
        return 1;
    if (boxCheck==0)
        return 0;
}

/* 
 * checks if value can be placed in 3x3 grid
 * takes in the coordinates of the 3x3 box (0-2 for x 0-2 for y)
 * uses that value to find which elements to compare
*/ 
template <class T> int Puzzle<T>::checkBox(int boxX, int boxY, int value)
{
    int i,j ;
    int X = boxX*3;
    int Y = boxY*3;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (board[i+X][j+Y]==value)
            {
                cout << "value already exists in box" << endl << endl;
                return 0;
            }
        }
    }
    return 1;
}

// checks if board is complete (ie. no 0 on board)
template <class T> void Puzzle<T>::isComplete()
{
    int i,j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            if (board[i][j] == 0 || board[i][j] =='0')
            {
                cout << endl << "inComplete" << endl;
                return;
            }
        }
    }
}

// starts interactive mode
template <class T> void Puzzle<T>::interactive()
{
    char c='0';
    while (c!='q')
    {
        print();
        cout << endl << "type 'a' to add value board, 'c' to check if your board is correct, or 'q' to quit" << endl;
        cin >> c;
        if(c=='q')          // input of q quits game
            continue;
        else if (c=='c')    // input of c checks if board is complete
            isComplete();
        else if (c=='a')    // input of a prompts user to add value
            addValue();
    }
}
