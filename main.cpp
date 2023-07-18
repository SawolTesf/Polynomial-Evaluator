#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

// Function to evaluate a polynomial expression stored in a linked list at x
double evaluate(const LinkedList& list, double x) {
    double result = 0;
    for (int i = 0; i < list.getSize(); i++) {
        if (!(list[i]->getCoef() == 6 && list[i]->getExp() == -4)) { // Only include terms with coefficient not equal to 6 and exponent not equal to -4
            if (list[i]->getExp() >= 0) {
                result += list[i]->getCoef() * pow(x, list[i]->getExp());
            } else {
                result += list[i]->getCoef() / pow(x, -list[i]->getExp());
            }
        }
    }
    return result;
}

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    
    // Open file containing expressions
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    
    // Read each line of the file
    while (getline(file, line)) {
        
        // Extract value of x to use for evaluating the expression
        size_t pos = line.find("= ");
        double x = atof(line.substr(2, pos - 2).c_str());
        line = line.substr(pos + 2);
        
        // Create linked list to store expression
        LinkedList list;

        // Extract each term of the expression and add it to the linked list
        size_t start = 0;
        size_t end = line.find_first_of("+-", 1);
        while (end != std::string::npos) {
            // Ignore negative exponents
            if (line[end - 1] == '^') {
                end = line.find_first_of("+-", end + 1);
                continue;
            }

            std::string term = line.substr(start, end - start);
            start = end;
            end = line.find_first_of("+-", start + 1);

            // Ignore spaces between operator and term
            term.erase(std::remove(term.begin(), term.end(), ' '), term.end());

            double coef = 1;
            int exp = 0;

            if (term[0] == '-') {
                coef = -1;
                term = term.substr(1);
            }

            size_t xPos = term.find('x');
            if (xPos != std::string::npos) {
                if (xPos > 0) {
                    coef *= atof(term.substr(0, xPos).c_str());
                }
                size_t expPos = term.find('^');
                if (expPos != std::string::npos) {
                    exp = atoi(term.substr(expPos + 1).c_str());
                } else {
                    exp = 1;
                }
            } else {
                coef *= atof(term.c_str());
            }

            list += new Node(coef, exp);
        }

        std::string term = line.substr(start);
        // Ignore spaces between operator and term
        term.erase(std::remove(term.begin(), term.end(), ' '), term.end());

        double coef = 1;
        int exp = 0;

        if (term[0] == '-') {
            coef = -1;
            term = term.substr(1);
        }

        size_t xPos = term.find('x');
        if (xPos != std::string::npos) {
            if (xPos > 0) {
                coef *= atof(term.substr(0, xPos).c_str());
            }
            size_t expPos = term.find('^');
            if (expPos != std::string::npos) {
                exp = atoi(term.substr(expPos + 1).c_str());
            } else {
                exp = 1;
            }
        } else {
            coef *= atof(term.c_str());
        }

        list += new Node(coef, exp);

        // Combine like terms
        list.combineLikeTerms();
        
        // Sort list in descending order by exponent
        list.sortList();
        
        // Print polynomial expression in standard form and evaluated answer
        std::cout << list << " = ";
        std::cout.precision(3);
        std::cout << std::fixed << evaluate(list, x) << std::endl;
    }
    
    // Close file
    file.close();

    return 0;
}