#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "book.h"



void printBookList(struct Node* node)
{
    while (node != NULL) {

            printf("the book id => %d \nthe book name => %s \nthe book auther => %s \n", node->_book->ID,node->_book->name,node->_book->auther);
            printf("==================%d===============================\n",node->next);
        node = node->next;
    }
}




#endif
