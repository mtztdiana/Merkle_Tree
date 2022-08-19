#ifndef MERKLE_TREE_H // include guard
#define MERKLE_TREE_H

#include "picosha2.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std; 
using namespace picosha2;

//--- Definition of an individual Node
struct Node {
    string hash;
    Node *left;
    Node *right;

    Node(string data);
};

//--- Definition of the elements and operations for a Merkle Tree
class merkle_tree
{
public:
	Node *root;

	merkle_tree(vector<Node *> blocks);
	~merkle_tree();
	
	void printTree(Node *ptr, int indent);
    void deleteTree(Node *ptr);
	
};


//--- Generating SHA256 hash hex string from std::string
inline string hash_sha256(string src_str) {
    string hash_hex_str = hash256_hex_string(src_str);
    return hash_hex_str;
}

// prints all hashes contained within a vector of nodes
inline void printNodeHashes(vector<Node*> v) {
    for (unsigned int a = 0; a < v.size(); a++) {
        cout << v[a]->hash << endl;
    }
}

#endif /* MERKLE_TREE_H */