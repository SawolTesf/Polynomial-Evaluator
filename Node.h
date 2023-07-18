#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
    private:
        double coef;
        int exp;
        Node* next;
    public:
        // Default constructor
        Node();

        // Overloaded constructor
        Node(double coef, int exp);

        // Accessors
        double getCoef() const;
        int getExp() const;
        Node* getNext() const;

        // Mutators
        void setCoef(double coef);
        void setExp(int exp);
        void setNext(Node* next);

        // Overloaded insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Node& node);
};

#endif