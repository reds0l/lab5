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

        Puzzle();
        Puzzle(int);
        Puzzle(string);
        void empty();
        void print();
        void addValue();
        int validPlacement(int, int, int);
        int checkBox(int, int, int);
        void isComplete();
        void interactive();

    private:

        int size;
        T element;
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
            infile >> temp;
            if (typeid(T) == typeid(char) && temp==' ')
            {
                i--;
                continue;
            }
            tempvector.push_back(temp);
        }
        board.push_back(tempvector);
        tempvector.clear();
    }
    infile.close();
}

template <class T> void Puzzle<T>::empty()
{
    vector <T> temp;
    int i;

    for (i=0;i<size;i++)
    {
        if (typeid(T) == typeid(char))
            temp.push_back('0');
        else
            temp.push_back(0);
    }
    for (i=0;i<size;i++)
    {
        board.push_back(temp);
    }
}

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

template <class T> int Puzzle<T>::validPlacement(int x, int y, int value)
{
    if (x<0 || x>=size)
    {
        cout << "Invalid input for row" << endl << endl;
        return 0;
    }
    else if (y<0 || y>=size)
    {
        cout << "Invalid input for column" << endl << endl;
        return 0;
    }
    else if (value<0 || value>9)
    {
        if (value==0){return 0;}
        cout << "Invalid input for value" << endl << endl;
        return 0;
    }

    int i,j;
    for (i=0;i<size;i++)
    {
        if (value==board[i][y])
        {
            cout << "column conflict" << endl << endl;
            return 0;
        }
        if (value==board[x][i])
        {
            cout << "row conflict" << endl << endl;
            return 0;
        }
    }

    int boxX, boxY, boxCheck;
    (x<3 ? boxX=0 : (x>5 ? boxX=2 : boxX=1));
    (y<3 ? boxY=0 : (y>5 ? boxY=2 : boxY=1));
    boxCheck=checkBox(boxX, boxY, value);
    if (boxCheck==1)
        return 1;
    if (boxCheck==0)
        return 0;
}

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

template <class T> void Puzzle<T>::interactive()
{
    char c='0';
    while (c!='q')
    {
        print();
        cout << endl << "type 'a' to add value board, 'c' to check if your board is correct, or 'q' to quit" << endl;
        cin >> c;
        if(c=='q')
            continue;
        else if (c=='c')
            isComplete();
        else if (c=='a')
            addValue();
    }
}
