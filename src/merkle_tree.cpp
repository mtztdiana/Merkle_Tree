// C++ program to implement a simple Merkle Tree


#include "../include/merkle_tree.h"
#include <iomanip>


//--- Constructor of the Node
Node::Node(string data) {
    this->hash = data;
}


//--- Constructor of the Merkle Tree
merkle_tree::merkle_tree(vector<Node *> blocks){
	vector<Node*> nodes;
    while (blocks.size() != 1) {
        printNodeHashes(blocks);
        for (unsigned int l = 0, n = 0; l < blocks.size(); l = l + 2, n++) {
            if (l != blocks.size() - 1) { // checks for adjacent block
                nodes.push_back(new Node(hash_sha256(blocks[l]->hash + blocks[l+1]->hash))); // combine and hash adjacent blocks
                nodes[n]->left = blocks[l]; // assign children
                nodes[n]->right = blocks[l+1];
            } else {
                nodes.push_back(blocks[l]);
            }
        }
        std::cout << "\n";
        blocks = nodes;
        nodes.clear();

    }
    this->root = blocks[0];
}


//---Destructor of Merkle Tree
merkle_tree::~merkle_tree() {
    deleteTree(root);
    std::cout << "Tree deleted" << std::endl;
}


//--- Display the Merkle Tree
void merkle_tree::printTree(Node *ptr, int indent){
	if (ptr) {
        if (ptr->left) {
            printTree(ptr->left, indent + 4);
        }
        if (ptr->right) {
             printTree(ptr->right, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << ptr->hash[0] << "\n ";
    }
}


//--- Delete the Merkle Tree
void merkle_tree::deleteTree(Node *ptr){
	if (ptr) {
        deleteTree(ptr->left);
        deleteTree(ptr->right);
        ptr = NULL;
        delete ptr;
    }
}