#include <iostream>
#include <cstdlib>
#include "TREE.H"

using namespace std;

#ifndef TREE_CPP_INCLUDED
#define TREE_CPP_INCLUDED

BST::BST(){
    root = NULL;
}

BST::node* BST::CreateLeaf(int key){
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::AddLeaf(int key){
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* ptr){
    if (root == NULL){
        root = CreateLeaf(key);
    }
    else if (key < ptr->key) {
        if (ptr->left !=NULL){
            AddLeafPrivate(key, ptr->left);
        }
        else{// inserer ici
            ptr->left = CreateLeaf(key);
        }
    }
    else if (key > ptr->key) {
        if (ptr->right !=NULL){
            AddLeafPrivate(key, ptr->right);
        }
        else{// inserer ici
            ptr->right = CreateLeaf(key);
        }
    }
    else {
        cout << "The Key "<< key << " Already exists \n";
    }
}

void BST::PrintTree(){
    PrintTreePrivate(root);
}

void BST::PrintTreePrivate(node* ptr){
    if (root!= NULL){
        if (ptr->left != NULL){
          PrintTreePrivate(ptr->left);
        }
        cout << ptr->key << " ** ";

        if (ptr->right != NULL){
          PrintTreePrivate(ptr->right);
        }
        //cout << endl;
    }
    else{
        cout << "The tree is Empty \n";
    }
}

BST::node* BST::GetNode(int key){
    return GetNodePrivate(key, root);
}

BST::node* BST::GetNodePrivate(int key, node* ptr){
    if (ptr !=NULL){
        if(ptr->key == key){
            return ptr;
        }
        else {
            if (key < ptr->key){
                 return GetNodePrivate(key, ptr->left);
            }
            else {
                return GetNodePrivate(key, ptr->right);
            }
        }
    }
    else {
        return NULL;
    }
}

int BST::GetRootKey(){
    if (root !=NULL){
        return root->key;
    }
    else return -999;
}

void BST::ShowChilds(int key){
    node* ptr = GetNode(key);
    cout << "ptr->key:  " << ptr->key;
    if (ptr != NULL){
       cout<<"The parent node is ="<< ptr->key << endl;
       ptr->left == NULL ?
       cout << "No left child! \n" :
       cout << "The left child is = " << ptr->left->key<<"/n" <<endl;

       ptr->right == NULL ?
       cout << "No right child! \n" :
       cout << "The right child is = "<< ptr->right->key <<"/n"<<endl;
    }
    else{
        cout << "The Key " << key << " does not exist in the Tree \n";
    }
}

int BST::FindSmallestKey(){
   return FindSmallestKeyPrivate(root);
}
int BST::FindSmallestKeyPrivate(node* ptr){
    if (root == NULL){
        cout << "The Tree is Empty.... \n" ;
        return -999;
    }
    else {
        if(ptr->left !=NULL){
            return FindSmallestKeyPrivate(ptr->left);
        }
        else {
            return ptr->key;
        }
    }
}

void BST::DeleteSubTree(node* ptr){
    if(ptr != NULL){
        if (ptr->left != NULL){
            DeleteSubTree(ptr->left);
        }
         if (ptr->right != NULL){
            DeleteSubTree(ptr->right);
        }
        cout << "Deleting node with the key: " << ptr->key << endl;
        delete ptr;
    }
}

void BST::DeleteMatch(node* parent, node* match, bool left){
if(root!= NULL){
        node* ptrSup;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // case0 - 0 children
        if (match->left == NULL && match->right ==NULL){
            ptrSup = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete ptrSup;
            cout << "The node with the Key: " << matchKey <<
            " has been deleted \n";
        }
        // Case 1 - 1 child
        else if (match->left == NULL && match->right != NULL){
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            ptrSup = match;
            delete ptrSup;
            cout << " The node with the Key: "<< matchKey << " has been deleted \n";
        }
        else if (match->left != NULL && match->right == NULL){
            left == true ? parent->left = match->left : parent->right = match->right;
            match->left = NULL;
            ptrSup = match;
            delete ptrSup;
            cout << " The node with the Key: "<< matchKey << " has been deleted \n";
        }
        // case 2 -2 children
        else {
            smallestInRightSubtree = FindSmallestKeyPrivate(match->right);
            DeleteNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else{
        cout << " The Tree is Empty.... Nothing to delete \n";
    }
}

void BST::DeleteNodematch(){
 if(root != NULL){
        node* ptrSup = root;
        int rootKey = root->key;
        int smallestInRightSubTree;
        // case 0 - 0 children
        if(root->left == NULL && root->right == NULL){
            root = NULL;
            delete ptrSup;
        }
        // Case 1- 1 Child
        else if(root->left == NULL && root->right != NULL){
            root = root->right;
            ptrSup->right = NULL;
            delete ptrSup;
            cout << "The root node " << rootKey << " has been deleted \n" <<
                    "The newest root node is " << root->key << endl;
        }
        else if(root->left !=NULL && root->right ==NULL){
            root = root->left;
            ptrSup->left = NULL;
            delete ptrSup;
            cout << "The root node " << rootKey << " has been deleted \n" <<
                    "The new root node is " << root->key << endl;
        }
        // case 2- la racine a deux fils (nodes)
        else{
            smallestInRightSubTree = FindSmallestKeyPrivate(root->right);
            DeleteNodePrivate(smallestInRightSubTree, root);
            root->key = smallestInRightSubTree;
            cout <<"The root node has the Key: " << rootKey <<
                    " replaced with the key " << root->key << endl;
        }
    }
    else {
        cout << " The Tree is Empty. Cannot delete \n";
    }
}

void BST::DeleteNode(int key){
    DeleteNodePrivate(key, root);
}

void BST::DeleteNodePrivate(int key, node* parent){
    if(root != NULL){
        if(root->key ==key){
            //to do
            DeleteNodematch(); // a implementer
        }
        else{
            if(key < parent->key && parent->left!=NULL){
                DeleteMatch(parent, parent->left, true);
                // to do
                // true veut dire navigation left;
                DeleteNodePrivate(key,parent->left );
            }
            else if(key > parent->key && parent->right!=NULL){
                parent->right->key == key ?
                DeleteMatch(parent, parent->right, false):
                DeleteNodePrivate(key,parent->right );
            }
        }
    }
    else{
        cout << "The Tree is Empty.... \n";
    }
}

void BST::InverseTree()
{
    InverseTreePrivate(root);
}

void BST::InverseTreePrivate(node* ptr){
    if (root!= NULL){
        if (ptr->right != NULL){
          InverseTreePrivate(ptr->right);
        }
        cout << ptr->key << " ** ";

        if (ptr->left != NULL){
          InverseTreePrivate(ptr->left);
        }
        //cout << endl;
    }
    else{
        cout << "The tree is Empty \n";
    }
}

BST::~BST(){
    DeleteSubTree(root);
}

#endif // TREE_CPP_INCLUDED
