ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode* ptr=head;
        while(ptr!=nullptr) //To count total number of notes
        {
            c++;
            ptr=ptr->next;
        }
        int x=c-n;//To get the previous node of the node to be deleted
        ListNode* temp=head;
        ListNode* prev=head;
        if(n==1 && c==1)// If number of node is 1 and n is also 1
        {
            return nullptr;
        }
        if(n==1)// If the last node has to be removed
        {
            while(temp->next!=nullptr)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=nullptr;
            return head;
        }
        else
        if(n==c)// If the first node has to be removed
        {
            head=head->next;
            return head;
        }
        while(x>1)
        {
            temp=temp->next;
            x--;
        }
        temp->next=temp->next->next;
        return head;
    }
