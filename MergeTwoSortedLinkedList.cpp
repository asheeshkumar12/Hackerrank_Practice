#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    //SinglyLinkedListNode* temp;
    SinglyLinkedListNode *w = head1;
    SinglyLinkedListNode *w1 = head2;
    SinglyLinkedListNode *newHead = new SinglyLinkedListNode(-1);
    SinglyLinkedListNode *p3 = newHead;

    while (w != nullptr && w1 != nullptr) {
      if (w->data <= w1->data) {
        p3->next = w;
        w = w->next;
      } else {
        p3->next = w1;
        w1 = w1->next;
      }
      p3 = p3->next;
    }
    if (w1 != nullptr) {
      p3->next = w1;
    } else {
      p3->next = w;
    }
   return newHead->next;
}
