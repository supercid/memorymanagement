#include "node.h"

node::node()
{
    next = 0;
}

node::node(int dado, node *ptr = 0){
    this->dado = dado;
    this->next = ptr;
}

node::~node(){

}
