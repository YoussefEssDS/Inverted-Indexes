#include <iostream>
#include <stdlib.h>

using namespace std;

class node{
    public:
        int key;
        node* left;
        node* right;
        node(int cle,node* leftnode,node* rightnode){
            key=cle;
            left=leftnode;
            right=rightnode;
        };
        void printKey(){
            cout <<key<< endl;
        }
        void getLeft(){
            cout <<left->key<< endl;
        }
        void getRight(){
            cout <<right->key<< endl;
        }
};


