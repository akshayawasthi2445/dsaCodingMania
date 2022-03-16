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
    ListNode* mergeTwoLinkedList(ListNode* list1,ListNode* list2){
        ListNode* res = NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val<=list2->val){
            res = list1;
            res->next = mergeTwoLinkedList(list1->next,list2);
        }
        else{
            res = list2;
            res->next = mergeTwoLinkedList(list1,list2->next);
        }
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        while(lists.size()>1){ // try with n also in the while loop.
            for(int i=0;i<lists.size();i+=2){
                if(i==lists.size()-1)
                    continue;
                lists[i] = mergeTwoLinkedList(lists[i],lists[i+1]);
                
                lists.erase(lists.begin()+i+1);
            }
        }
        return lists[0];
    }
};


// myvector= {1, 2, 3, 4, 5}, iterator= myvector.begin()+2
//  myvector.erase(iterator);