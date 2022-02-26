SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist==nullptr||llist->next==nullptr)
    {
        return llist;
    }
    SinglyLinkedListNode* head=llist;
    while(llist->next!=nullptr)
    {
        if(llist->data!=llist->next->data)
        {
          llist=llist->next;
        }
        else {
            llist->next=llist->next->next;
        }
       
    }
  return head;
}
