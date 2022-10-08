/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   #define pi pair<int,ListNode*>
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        for(ListNode* list: lists){
            if(list){
                pq.push({list->val,list});
            }
        }
        while(!pq.empty()){
            temp->next = pq.top().second;
            pq.pop();
            temp = temp->next;
            if(temp->next) pq.push({temp->next->val,temp->next});
        }
        return dummy->next;
    }
};
