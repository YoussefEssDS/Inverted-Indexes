#include <iostream>
#include <cstdlib>

using namespace std;
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
class BST{
    private:
        struct node{
            int key;
            node* left;
            node* right;
        };
        node* root;
        void  AddLeafPrivate(int key, node* ptr);
        void  PrintTreePrivate(node* ptr);
        node* GetNodePrivate(int key, node* ptr);
        int   FindSmallestKeyPrivate(node* ptr);
        void  DeleteNodePrivate(int key, node* parent);
        void  DeleteSubTree(node* ptr);
        void  InverseTreePrivate(node* ptr);


    public:
       BST(); // constructeur
       node* CreateLeaf(int key);
       void  AddLeaf(int key);
       void  PrintTree();
       node* GetNode(int key);
       int   GetRootKey();
       void  ShowChilds(int key);
       int   FindSmallestKey();
       void  DeleteNode(int key);
       void  DeleteNodematch();
       void  DeleteMatch(node* parent, node* match, bool left);
       ~BST();
       // here is the assignement
       void InverseTree();
};

#endif // TREE_H_INCLUDED
