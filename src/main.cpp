/* Main Program of a self-balancing Merkle Tree*/

#include "../include/merkle_tree.h"

int main() {
    vector<Node*> leaves;

    //create sample data
    leaves.push_back(new Node(hash_sha256("The quick")));
    leaves.push_back(new Node(hash_sha256("brown fox")));
    leaves.push_back(new Node(hash_sha256("jumps")));
    leaves.push_back(new Node(hash_sha256("over the")));
    leaves.push_back(new Node(hash_sha256("lazy dog")));

    // initialize leaves
    for (unsigned int i = 0; i < leaves.size(); i++) {
        leaves[i]->left = NULL;
        leaves[i]->right = NULL;
    }

    merkle_tree *hashTree = new merkle_tree(leaves);
    cout << hashTree->root->hash << endl;
    hashTree->printTree(hashTree->root, 0);

    for (unsigned int k = 0; k < leaves.size(); k++) {
        delete leaves[k];
    }

    delete hashTree;

    return 0;
}
