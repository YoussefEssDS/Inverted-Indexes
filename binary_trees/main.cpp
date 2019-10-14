#include <iostream>
#include "BTC.h"
using namespace std;

int main()
{

    node node1=node(51,NULL,NULL);
    node node2=node(48,NULL,NULL);
    node node3=node(50,&node1,&node2);
    node3.printKey();
    node a=node3.getLeft();
    node b=node3.getRight();
    cout <<node1.key<< endl;
    cout <<node2.key<< endl;
    return 0;
}
