#pragma once

#include <vector>
using namespace std;

class Node
{
public:

    Node();
    ~Node();

    static size_t counter;

    size_t id;

    vector<Node> childNodes;

    void Print();

    void AddChild(Node _child);

    void SearchChildren();

};

