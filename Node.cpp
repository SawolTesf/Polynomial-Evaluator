#include "Node.h"
#include <cmath>
#include <iomanip>

// Default constructor
Node::Node()
{
    coef = 0.0;
    exp = 0;
    next = nullptr;
}

// Overloaded constructor
Node::Node(double coef, int exp)
{
    this->coef = coef;
    this->exp = exp;
    next = nullptr;
}

// Accessors
double Node::getCoef() const
{
    return coef;
}

int Node::getExp() const
{
    return exp;
}

Node* Node::getNext() const
{
    return next;
}

// Mutators
void Node::setCoef(double coef)
{
    this->coef = coef;
}

void Node::setExp(int exp)
{
    this->exp = exp;
}

void Node::setNext(Node* next)
{
    this->next = next;
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Node& node) {
    if (node.getCoef() != 1 || node.getExp() == 0) {
        os << std::fixed << std::setprecision(3) << fabs(node.getCoef());
    }
    if (node.getExp() != 0) {
        os << "x";
        if (node.getExp() != 1) {
            os << "^" << node.getExp();
        }
    }
    return os;
}