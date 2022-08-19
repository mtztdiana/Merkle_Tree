# Merkle_Tree
Simple self-balancing Merkle Tree implementation on C++

It uses for hashing [PicoSHA2](https://github.com/okdshin/PicoSHA2)

## Build
To build the program in the main directory
> $ make

## To run the example
On the main directory
> $ ./mtree
This will give the hash result of creating a Merkle Tree with the input 
> "

## To run the test
First you need to compile the test with the next line from the main directory. This uses [Google Test](https://github.com/google/googletest)
> $ g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread docs/MerkleTreeTest.cpp src/merkle_tree.cpp googletest-release-1.8.0/libgtest.a -o docs/tests

Then run the test
> $ ./docs/tests
This will give the result of the hash as the example provided by [PicoSHA2](https://github.com/okdshin/PicoSHA2) for the string ""The quick brown fox jumps over the lazy dog""
