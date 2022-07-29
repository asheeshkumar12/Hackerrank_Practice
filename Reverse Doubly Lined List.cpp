DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* curr=llist;
    if(curr==nullptr || curr->next==nullptr)
     return curr;
    while(curr->next!=nullptr)
     curr=curr->next;
    llist=curr;
    curr->next=curr->prev;
    curr->prev=NULL;
    curr=curr->next;
    while(curr->prev!=nullptr){
        DoublyLinkedListNode* t=curr->next;
        curr->next=curr->prev;
        curr->prev=t;
        curr=curr->next;
    }
   curr->prev=curr->next;
   curr->next=nullptr;
   return llist;
}
