#include "stdafx.h"
#include "Node.h"
#include <iostream>
#include <sstream>

using namespace std;

size_t Node::counter = 0;

Node::Node()
{
    id = counter;
    counter++;
}

Node::~Node()
{
}


void Node::Print()
{
    stringstream ss;
    ss << id;
    cout << ss.str() << endl;
}

void Node::AddChild(Node _child)
{
    childNodes.push_back(_child);
}

void Node::SearchChildren()
{
    Print();

    for (size_t i = 0; i < childNodes.size(); i++)
    {
        childNodes[i].SearchChildren();
    }
}