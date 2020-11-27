//
// Created by Assistant_2 on 2020-11-16.
//

#ifndef _DATASTRUCTURE_FORANODE_H
#define _DATASTRUCTURE_FORANODE_H
#include <iostream>

using namespace std;

class foraNode {
private:
public:
    int data;
    foraNode* tail;
    foraNode();
    ~foraNode();
};


#endif //_DATASTRUCTURE_FORANODE_H
