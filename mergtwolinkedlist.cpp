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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		ListNode head(0);
	 
		ListNode * tail;
		tail = &head;
		
		while ( !(l1 == NULL && l2 == NULL) ){
			
			if (  l1 == NULL ) {
			    tail->next = l2;
				break;
			}
			if ( l2 == NULL ){
			    tail->next = l1;
				break;
			}
		    
			if ( (l1 ->val ) < ( l2->val ) ){
			     tail->next = l1;
				 l1 = l1->next;
				 tail = tail->next;
			}else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
			
		}
		
        return head.next;
    }
};