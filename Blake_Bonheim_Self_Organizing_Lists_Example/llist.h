#ifndef LLIST_H
#define	LLIST_H

#include "book.h"
#include "link.h"
#include "list.h"
#include <vector>
//Modified  by Blake Bonheim and Jarred Patterson



// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete LList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation
template <typename E> class LList : public List<E> {
private:
    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int cnt;    	       // Size of list

    void init() {        // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }

    void removeall() {   // Return link nodes to free store
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList() { init(); }    // Constructor
    ~LList() { removeall(); }                   // Destructor

    void print(vector<E> v, vector<int> f)                 // Print list contents
    {
        curr = head;
        int count = 0;
        while (count < cnt)
        {
            //find the corresponding frequency
            for (int n = 0; n < cnt; n++)
            {
                if (v[n] == curr->element)
                {
                    cout << curr->element;
                    std::cout << "-" << f[n] << " ";
                    next();
                    count++;
                }
            }
        }
    }
    void printAmount(vector<E> v, vector<int> f, int amount)
    {
        if (amount > cnt)
        {
            amount = cnt;
        }
        curr = head;
        int count = 0;
        while (true)
        {
            //find the corresponding frequency
            for (int n = 0; n < cnt; n++)
            {
                if (v[n] == curr->element)
                {
                    cout << curr->element;
                    std::cout << "-" << f[n] << " ";
                    count++;
                    next();
                }
                if (count == amount)
                {
                    return;
                }
            }
        }
    }

    void clear() { removeall(); init(); }       // Clear list

    // Insert "it" at current position
    void insert(const E& it) {
        Link<E>* tempNext = curr->next; //remember link infront of current selection
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next;  // New tail
        curr = curr->next;
        curr->next = tempNext;

        cnt++;
    }

    void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        if (cnt == 0)
        {
            setHead(tail); //if this is the first link in the list, set it as the head and tail
        }
        cnt++;
    }

    // Remove and return current element
    E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element;      // Remember value
        Link<E>* ltemp = curr->next;     // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next;   // Remove from list
        delete ltemp;                    // Reclaim space
        cnt--;			     // Decrement the count
        return it;
    }

    void moveToStart() // Place curr at list start
    {
        curr = head;
    }

    void moveToEnd()   // Place curr at list end
    {
        curr = tail;
    }

    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return;       // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next != curr) temp = temp->next;
        curr = temp;
    }

    // Move curr one step right; no change if already at end
    void next()
    {
        if (curr != tail) curr = curr->next;
    }

    int length() const { return cnt; } // Return length

    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i = 0; curr != temp; i++)
            temp = temp->next;
        return i;
    }

    // Move down list to "pos" position
    void moveToPos(int pos) {
        Assert((pos >= 0) && (pos <= cnt), "Position out of range");
        curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
    }

    const E& getValue() const { // Return current element
        Assert(curr != NULL, "No value");
        return curr->element;
    }

    E getPrev()  //returns the previous link's value 
    {
        prev();
        E tempReturn = curr->element; //grab previous element
        next();
        return tempReturn;
    }

    void setHead(Link<E>* link)
    {
        head = link;
    }


    void swapForward() //swap current element with the one infront of it
    {
        Link<E>* tempCurrent = curr;
        Link<E>* tempNext = curr->next; //save the next for later     step 1

        prev(); //curr is not set to prev
        Link<E>* tempPrev = curr; //save the prev for later     step 2

        prev(); //curr is now set to prev->prev

        if (head != tempPrev)//if the previous is not the head
        {
            curr->next = curr->next->next; //set the 'prev->prev' value to point to the 'current' value    step 3
        }
        else
        {
            head = tempCurrent;
        }

        curr = tempCurrent;
        curr->next = tempPrev; //set the current value to point to the tempPrev value (which is the location of the previous element)   step 4

        if (tempCurrent != tail)//if the element being swapped is the tail, do not do this step
        {
            tempPrev->next = tempNext; //set the previous' value to tempNext's pointer which points to the 'next' value    step 5
        }
        else
        {
            tail = tempCurrent->next;    //if the element being swapped is the tail, set the new tail
            tail->next = new Link<E>;
        }
    }

    void swapFirst() //swap the current selection witht the head
    {
        if (curr != head)
        {
            Link<E>* tempCurrent = curr; //step 1 remeber current selection

            prev();
            if (tempCurrent != tail)
            {
                curr->next = curr->next->next; //step 2 
            }
            else
            {
                tail = curr; //set the new tail
                tail->next = new Link<E>;
            }

            tempCurrent->next = head; //step 3

            head = tempCurrent; //step 4
        }
    }
};

#endif