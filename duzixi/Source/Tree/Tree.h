#pragma once

#include "Node.h"

class Tree
{
public:
    Tree();
    ~Tree();

    Node root;

    void AddNode(Node _child);

    void DepthFirstSearch();
};

