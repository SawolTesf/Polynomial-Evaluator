#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList
{
    private:
        Node* head;
        int size;
    public:
        // Default constructor
        LinkedList();

        // Overloaded constructor
        LinkedList(const LinkedList& list);

        // Destructor
        ~LinkedList();

        // Accessors
        int getSize() const;
        Node* getHead() const;

        // Mutators
        void setSize(int size);
        void setHead(Node* head);

        // Overloaded [] operator
        const Node* operator[](int index) const;

        // Overloaded += operator
        void operator+=(Node* node);

        // Overloaded insertion operator
        friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

        // Sort function – named sortList.
        void sortList();

        // Display function - named displayList.
        void displayList() const;

        // Helper functions
        void addNode(double coef, int exp);
        void combineLikeTerms();
        double evaluate(double x) const;
};

#endif