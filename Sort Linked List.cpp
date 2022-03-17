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
    ListNode* mergeTwoSortedLists(ListNode* list1,ListNode* list2){
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* result = NULL;
        if(list1->val<=list2->val){
            result = list1;
            result->next = mergeTwoSortedLists(list1->next,list2);
        }
        else{
            result = list2;
            result->next = mergeTwoSortedLists(list1,list2->next);
        }
        return result;
    }
    
    ListNode* sortListUpdate(ListNode* head,ListNode* tail){
        if(head!=tail){
            int count = countNodes(head,tail);
            count/=2;
            ListNode* temp = head;
            while(count>1){
                temp = temp->next;
                count-=1;
            }
            ListNode* list1 = sortListUpdate(head,temp);
            ListNode* clear = temp->next;
            temp->next = NULL;
            ListNode* list2 = sortListUpdate(clear,tail);
            head = mergeTwoSortedLists(list1,list2);
            return head;
        }
        else return head;
    }
    
    int countNodes(ListNode* temp1,ListNode* temp2){
        int count = 0;
        while(temp1!=temp2){
            count+=1;
            temp1 = temp1->next;
        }
        return (count + 1);
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        
        head = sortListUpdate(head,tail);
        return head;
    }
};