#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* node_will_be_inserted = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* tmp = llist;
    if(tmp->data > node_will_be_inserted->data){ // if node has to be inserted to front of the list
        node_will_be_inserted->next = tmp;
        node_will_be_inserted-> prev = nullptr;
        tmp->prev = node_will_be_inserted;
        return node_will_be_inserted;
    }
    while(tmp->next != nullptr && tmp->next->data < node_will_be_inserted->data){
        tmp = tmp->next;
    }
    if(tmp->next == nullptr){ // check if the value has to be inserted to end of the linkedlist
        tmp->next = node_will_be_inserted;
        node_will_be_inserted->prev = tmp;
        node_will_be_inserted->next = nullptr;
        return llist;
    }
    node_will_be_inserted->next = tmp->next;
    tmp->next->prev = node_will_be_inserted;
    node_will_be_inserted->prev = tmp;
    tmp->next = node_will_be_inserted;
    return llist;
}
int main()