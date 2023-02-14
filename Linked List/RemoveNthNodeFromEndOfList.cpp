// Slow and Fast Pointer Approach
ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
        {
            return head;
        }

        if(head->next == NULL)
        {
            head = NULL;
            return head;
        }

        ListNode *slow=head,*fast=head;

        while(n--)
        {
            fast=fast->next;
        }

        if(fast == NULL)
        {
            return slow->next;
        }

        
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

    

        slow->next = slow->next->next;

        return head;
    }


//Approach 1

 ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
        {
            return head;
        }

        if(head->next == NULL)
        {
            head = NULL;
            return head;
        }

        ListNode *curr = head,*prev=head;
        int count = 0;


        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        int target = count - n;
        //cannot delete
        if(target < 0)
        {
            return head;
        }

        //delete first node
        if(target == 0)
        {
            return head->next;
        }

        curr=head;
        while(target--)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        return head;
    }

