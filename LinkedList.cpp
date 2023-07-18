#include "LinkedList.h"
#include <cmath>

// Default constructor
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

// Overloaded constructor
LinkedList::LinkedList(const LinkedList& list)
{
    head = nullptr;
    size = 0;
    Node* current = list.head;
    while (current != nullptr)
    {
        this->addNode(current->getCoef(), current->getExp());
        current = current->getNext();
    }
}

// Destructor
LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
}

// Accessors
int LinkedList::getSize() const
{
    return size;
}

Node* LinkedList::getHead() const
{
    return head;
}

// Mutators
void LinkedList::setSize(int size)
{
    this->size = size;
}

void LinkedList::setHead(Node* head)
{
    // Delete current list
    Node* current = this->head;
    while (current != nullptr)
    {
        Node* next = current->getNext();
        delete current;
        current = next;
    }

    // Deep copy new list
    this->head = nullptr;
    this->size = 0;
    current = head;
    while (current != nullptr)
    {
        this->addNode(current->getCoef(), current->getExp());
        current = current->getNext();
    }
}

// Overloaded [] operator
const Node* LinkedList::operator[](int index) const {
    if (index < 0 || index >= size) {
                return nullptr;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current;
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        if (current->getCoef() < 0) {
            os << "- ";
        } else if (current != list.head) {
            os << "+ ";
        }
        os << *current << " ";
        current = current->getNext();
    }
    return os;
}

// Overloaded += operator
void LinkedList::operator+=(Node* node) {
    if (head == nullptr) {
        head = node;
    } else {
        Node* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(node);
    }
    size++;
}


// Sort function – named sortList.
void LinkedList::sortList() {
    if (head == nullptr || head->getNext() == nullptr)
        return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;
        while (current->getNext() != nullptr) {
            if (current->getExp() < current->getNext()->getExp()) {
                if (prev == nullptr)
                    head = current->getNext();
                else
                    prev->setNext(current->getNext());

                Node* temp = current->getNext();
                current->setNext(temp->getNext());
                temp->setNext(current);

                prev = temp;
                swapped = true;
            } else {
                prev = current;
                current = current->getNext();
            }
        }
    } while (swapped);
}

// Display function - named displayList.
void LinkedList::displayList() const
{
    std::cout << *this << std::endl;
}

// Helper functions
void LinkedList::addNode(double coef, int exp)
{
  Node *new_node = new Node(coef, exp);
  if (head == nullptr) {
      head = new_node;
  } else {
      Node *temp = head;
      while (temp->getNext() != nullptr) {
          temp = temp->getNext();
      }
      temp->setNext(new_node);
  }
  size++;
}

void LinkedList::combineLikeTerms()
{
    Node* current1 = head;
    while (current1 != nullptr && current1->getNext() != nullptr) {
        Node* prev2 = current1;
        Node* current2 = current1->getNext();
        while (current2 != nullptr) {
            if (current1->getExp() == current2->getExp()) {
                double newCoef = current1->getCoef() + current2->getCoef();
                if (newCoef == 0) {
                    if (prev2 == head) {
                        head = head->getNext();
                    } else {
                        prev2->setNext(current2->getNext());
                    }
                    delete current2;
                    size--;
                    current2 = prev2->getNext(); // Move to next node after deletion
                } else {
                    current1->setCoef(newCoef);
                    prev2->setNext(current2->getNext());
                    delete current2;
                    size--;
                }
            } else {
                prev2 = prev2->getNext();
            }
            current2 = prev2->getNext(); // Move to next node
        }
        current1 = current1->getNext();
    }
}


double LinkedList::evaluate(double x) const
{
    double result = 0;
    Node* current = head;
    while (current != nullptr) {
        double term = current->getCoef();
        if (current->getExp() >= 0) {
            for (int i = 0; i < current->getExp(); i++) {
                term *= x;
            }
        } else {
            for (int i = 0; i < -current->getExp(); i++) {
                term /= x;
            }
        }
        result += term;
        current = current->getNext();
    }
    return result;
}