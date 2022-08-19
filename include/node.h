#ifndef NODE_H // include guard
#define NODE_H

#include "picosha2.h"
#include <string>

using namespace std; 

struct Node {
    string hash;
    Node *left;
    Node *right;

    Node(string data);
};

#endif /* NODE_H */