#include <iostream>
#include <vector>
#include <string>
#include "TREE.h"
using namespace std;

int main(){
    int Tabkeys[16]= {51, 77, 22, 5, 16, 33, 65, 53, 15, 101, 84, 3, 4, 71, 88, 81};
    BST myTree;
    //cout << "Print before insertion \n";
    //myTree.PrintTree();
    for(int i = 0; i<16; i++){
        myTree.AddLeaf(Tabkeys[i]);
    }
    cout << "Print all keys sorted \n";
    myTree.PrintTree();
    cout<< "------------- \n";
    int rooot;
    rooot = myTree.GetRootKey();
    cout << "The key in the root node is: " << rooot << endl;

    cout<< "The smallest Key in the Tree is: " <<
    myTree.FindSmallestKey()<< endl;

    cout << "Show inverted Tree" << endl;
    cout<< "------------- \n";
    // uncommente these 2 lines when you are done with the function of invertion
    myTree.InverseTree();
    cout<< "------------ \n";
    myTree.PrintTree();

    cout<< "------------ \n";
    //myTree.ShowChilds(53);

    int input = 0;
   /*cout << "Enter the Node to delete ? -1 to exit \n";
   while(input != -1){
    cout << "Delete a node: ";
    cin >> input;
    if(input != -1){
        cout << endl;
        myTree.DeleteNode(input);
        myTree.PrintTree();
        cout << endl;
    }
   }*/

    return 0;
}
