/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *headofhead;
        ListNode *first, *second, *pre;
        
        headofhead = new ListNode(0);
        headofhead->next = head;
        
        pre = headofhead;
        first = head;
        if (head == NULL) return head;
        second = head->next;
        if ( second == NULL) return head;
        while((second!= NULL)&& (first != NULL) ){
            //FIRST AND SECOND ARE TURE
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
            first = pre->next;
            if (first != NULL){
                second = first->next;
                }
             
        }
        return headofhead->next;
    }
};