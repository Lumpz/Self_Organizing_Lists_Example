#ifndef TRANSPOSE_H
#define	TRANSPOSE_H

#include<string>
#include<vector>
#include "SelfOrderedListADT.h"
#include "llist.h"
#include "link.h"

//Created by Blake Bonheim and Jarred Patterson

template <typename E>
class Transpose : public SelfOrderedListADT<E>
{
public:
    Transpose()
    {
        list = new LList<E>();
        compares = 0;
    };
    ~Transpose() {};
    bool find(const E& it)
    {
        //loop through linked-list to find desired value location
        for (int i = 0; i < values.size(); i++) //check is value is in the array storing used values
        {
            compares++;
            if (values[i] == it) // if the value is already present in the linked list
            {
                compares++;
                freq[i]++;     //increase value frequency           

                //iterate through the linked-list to find the element with the desired value
                list->moveToStart();
                for (int b = 0; b < list->length(); b++)
                {
                    compares++;

                    if (list->getValue() == it) //when the element is found, swap ot forward
                    {
                        compares++;

                        list->swapForward(); //swaps the 'find element' with the next element                 
                        compares += 2;
                    }
                    list->next(); //move forward in list
                    compares++;
                }

                return true; //the value was found, frequency increased, and swapped if necessary
            }
        }

        add(it); //if the element is not found in the list, add it to the Linked List and give it a frequency of 0
        return false;
    };
    void add(const E& it) //add an item to the list
    {
        list->append(it);
        values.push_back(it);
        freq.push_back(0);
    };
    int getCompares() const //returns the amount of comparisons made
    {
        return compares;
    };
    int size() const //returns the size of the list
    {
        return list->length();
    };
    void printlist() // prints the entire list
    {
        list->print(values, freq);
    };
    void printlist(int n) //prints the list to the specified amount
    {
        list->printAmount(values, freq, n);
    };


private:
    int compares;
    LList<E>* list;
    vector<E> values; //remembers the values contained in the list and corresponds to the frequency
    vector<int> freq;//remebers the frequency of value
};


#endif