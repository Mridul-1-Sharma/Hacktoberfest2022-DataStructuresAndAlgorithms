// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
        ListNode* back = head;
        ListNode* front = head;
        
        while(--n){
            front=front->next;
        }
        while(front->next!=NULL){
            back=back->next;
            front=front->next;
        }
        ListNode* temp = head;
        while(temp!=NULL){
		// removing first node case
            if(temp==back){  
                head=head->next;
                return head;
            }
		// rest of the cases
            if(temp->next==back){
                temp->next=temp->next->next;
            }
            temp=temp->next;
        }
        return head;
    }