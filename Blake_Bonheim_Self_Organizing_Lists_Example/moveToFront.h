#ifndef MOVETOFRONT_H
#define	MOVETOFRONT_H

#include<string>
#include<vector>
#include "SelfOrderedListADT.h"
#include "llist.h"
#include "link.h"


//Created by Blake Bonheim and Jarred Patterson


template <typename E>
class MoveToFront : public SelfOrderedListADT<E>
{
public:
    MoveToFront()
    {
        list = new LList<E>();
        compares = 0;
    };
    ~MoveToFront() {};
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

                bool done = false;
                list->moveToStart();
                while (done == false)
                {
                    if (list->getValue() == it) //when the element is found, swap with the head
                    {
                        compares++;

                        list->swapFirst(); //swaps the 'find element' with the head element        
                        compares += 2;
                        done = true;
                        return true; //the value was found, frequency increased, and swapped
                    }
                    list->next();
                }
            }
        }

        add(it); //if the element is not found in the list, add it to the Linked List and give it a frequency of 0
        compares += 2;
        return false;
    };
    void add(const E& it) //add an item to the front of the list
    {
        list->insert(it);
        list->swapFirst();
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
    void printlist() //prints the entire list
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
    vector<E> values;//remembers the values contained in the list and corresponds to the frequency
    vector<int> freq;//remebers the frequency of value
};


#endif