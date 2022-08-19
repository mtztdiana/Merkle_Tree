/* Test file */

#include <gtest/gtest.h>

#include "../include/merkle_tree.h"

using namespace std;

namespace {

    TEST(MerkleTreeTest, CreateTree){
    	vector<Node*> leaves;

        //create sample data
        leaves.push_back(new Node(hash_sha256("The quick brown fox jumps over the lazy dog")));

        // initialize leaves
        for (unsigned int i = 0; i < leaves.size(); i++) {
            leaves[i]->left = NULL;
            leaves[i]->right = NULL;
        }

        merkle_tree *hashTree = new merkle_tree(leaves);
        string result = "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592";
        ASSERT_EQ(result,hashTree->root->hash);

        for (unsigned int k = 0; k < leaves.size(); k++) {
            delete leaves[k];
        }
    }
} // namespace


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}