#ifndef LISTA_H
#define LISTA_H

#include "node.h"

class lista
{
public:
    lista();
    ~lista();

    void headInsert(int dado);
    int headDelete();
    bool isEmpty();
    int getDado(int pos);
private:
    node* head;
};

#endif // LISTA_H
