// DFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Tree.h"

int main()
{
    Tree tree;
    Node n1, n2, n3, n4, n5, n6, n7, n8, n9;

    n3.AddChild(n1);
    n3.AddChild(n2);
    n4.AddChild(n5);
    n4.AddChild(n6);
    n4.AddChild(n7);
    n8.AddChild(n9);

    tree.AddNode(n3);
    tree.AddNode(n4);
    tree.AddNode(n8);

    tree.DepthFirstSearch();

    return 0;
}

