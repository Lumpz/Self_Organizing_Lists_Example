using namespace std;
//Created by Blake Bonheim and Jarred Patterson



#include "SelfOrderedListADT.h"
#include "count.h"
#include "moveToFront.h"
#include "transpose.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

int main()
{
    //char test
    char c[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' }; //characters to add to the lists
    char input[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' }; //characters to find in the list
    Count<char> countChar;
    MoveToFront<char> moveToFrontChar;   //create 3 different lists for the three heuristics
    Transpose<char> transposeChar;

    for (int i = 0; i < 8; i++) //add initial chars
    {
        countChar.add(c[i]);
        moveToFrontChar.add(c[i]);
        transposeChar.add(c[i]);
    }

    for (int i = 0; i < 14; i++) //add new chars
    {
        countChar.find(input[i]);
        moveToFrontChar.find(input[i]);
        transposeChar.find(input[i]);
    }

    //print results
    cout << endl << "Count Heuristic: " << "    Size of list: " << countChar.size() << endl << "Number of Compares: " << countChar.getCompares() << endl;
    countChar.printlist();
    cout << endl;
    cout << endl << "Move to Front Heuristic: " << "    Size of list: " << moveToFrontChar.size() << endl << "Number of Compares: " << moveToFrontChar.getCompares() << endl;
    moveToFrontChar.printlist();
    cout << endl;
    cout << endl << "Transpose Heuristic: " << "    Size of list: " << transposeChar.size() << endl << "Number of Compares: " << transposeChar.getCompares() << endl;
    transposeChar.printlist();
    cout << endl << endl << endl << endl << endl;

    // test.txt string test
    Count<string> count;
    MoveToFront<string> moveToFront;    //create 3 different lists for the three heuristics
    Transpose<string> transpose;

    ifstream file;

    file.open("test.txt"); //open test file

    string word;

    while (file >> word)
    {
        count.find(word);
        moveToFront.find(word);
        transpose.find(word);
    }

    file.close();

    //print results
    cout << endl << "Count Heuristic: " << "    Size of list: " << count.size() << endl << "Number of Compares: " << count.getCompares() << endl;
    count.printlist(10);
    cout << endl;
    cout << endl << "Move to Front Heuristic: " << "    Size of list: " << moveToFront.size() << endl << "Number of Compares: " << moveToFront.getCompares() << endl;
    moveToFront.printlist(10);
    cout << endl;
    cout << endl << "Transpose Heuristic: " << "    Size of list: " << transpose.size() << endl << "Number of Compares: " << transpose.getCompares() << endl;
    transpose.printlist(10);
    cout << endl << endl << endl << endl;

}