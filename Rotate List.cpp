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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size+=1;
            temp = temp->next;
        }
        
        //k=0:lastptr=5
        //k=1:lastptr=4
        //k=2:lastptr=3
        //k=3:lastptr=2
        //k=4:lastptr=1
        if(k>size){
            while(k>size)
                k-=size;
        }
        
        if(k==0 || k%size==0)
            return head;
        
        ListNode* lastptr = head;
        
        int count = size-k; // k=2 count = 5-2 = 3
        int itr = 0;
        
        while(itr<count-1){ //count-1=2
            lastptr = lastptr->next;
            itr+=1;//2
        }

        ListNode* new_start = lastptr->next;
        lastptr->next = NULL;
        
        
        temp = new_start;
        
        
        while(temp->next){
            temp=temp->next;
        }
        
        temp->next = head;
        return new_start;
        
    }
};