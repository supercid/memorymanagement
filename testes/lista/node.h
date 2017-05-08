#ifndef NODE_H
#define NODE_H

class node
{
public:
    node();
    node(int dado, node* next);
    ~node();


    int dado;
    node *next;

};

#endif // NODE_H
