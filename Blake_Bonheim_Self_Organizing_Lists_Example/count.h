#ifndef COUNT_H
#define	COUNT_H

#include<string>
#include<vector>
#include "SelfOrderedListADT.h"
#include "llist.h"
#include "link.h"

//Created by Blake Bonheim and Jarred Patterson


template <typename E>
class Count : public SelfOrderedListADT<E>
{
public:
    Count()
    {
        list = new LList<E>();
        compares = 0;
    };
    ~Count() {};
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

                    if (list->getValue() == it) //when the element is found, check if the next element has a lower frequency
                    {
                        compares++;
                        bool done = false;

                        while (done == false) //continue swapping values until the current frequency is not greater than the previous
                        {
                            compares++;

                            //search for the frequency of the corresponding next value
                            for (int n = 0; n < values.size(); n++)
                            {
                                compares++;
                                if (list->getPrev() == values[n]) //when the value is found, compare freqencys
                                {
                                    compares++;
                                    if (freq[n] < freq[i]) //if the next freqency is lower then the find's value, then swap 
                                    {
                                        compares++;
                                        list->swapForward(); //swaps the 'find element' with the next element                 
                                        compares += 2;
                                    }
                                    else
                                    {
                                        done = true;  //if the frequency of 'it' has been increased and does not need to be moved up in the list
                                    }
                                }
                            }

                        }

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
    void add(const E& it) //add an item to the list without sorting it at all
    {
        list->append(it);
        values.push_back(it);
        freq.push_back(0);
    };
    int getCompares() const //return the amount of comparisons made
    {
        return compares;
    };
    int size() const //return the size
    {
        return list->length();
    };
    void printlist() //print the entire list with frequencys
    {
        list->print(values, freq);
    };
    void printlist(int n) //print the list to the specified amount
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