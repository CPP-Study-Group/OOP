#include "stdafx.h"
#include "Tree.h"

Tree::Tree()
{
}

Tree::~Tree()
{
}

void Tree::AddNode(Node _child)
{
    root.AddChild(_child);
}

void Tree::DepthFirstSearch()
{
    root.SearchChildren();
}