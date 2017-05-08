#include "lista.h"
#include <iostream>

lista::lista(){
    this->head = 0;
}

lista::~lista(){
    node* temp;
    while(head != 0){
        temp = head;
        head = head->next;
        delete temp;
    }
}

void lista::headInsert(int dado){
    node* temp = new node(dado,head);
    head = temp;
}


int lista::headDelete(){

    node *temp;
    int el;
    el = head->dado;
    temp = head;
    head = head->next;
    temp->next = 0;
    delete temp;
    return el;
}

bool lista::isEmpty(){
    return head == 0;
}

int lista::getDado(int pos){
    node *temp = head;
    for(int cont = 0; cont < pos; cont++){
        temp = temp->next;
    }
    return temp->dado;
}
