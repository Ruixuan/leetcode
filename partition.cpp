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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       ListNode * small_head, * small_tail;
       ListNode * large_head , * large_tail;

       small_head = NULL;
       large_head = NULL;
       small_tail = small_head;
       large_tail = large_head;

       ListNode * pt, *tmp;
       pt = head;
       while ( pt != NULL){
            tmp = pt;
		pt = pt -> next;
		tmp->next = NULL;
		if ( (tmp->val) < x ) {//insert small
			if ( small_head== NULL) {
				small_head = tmp;
				small_tail = tmp;
			}else{
				small_tail -> next = tmp;
				small_tail = small_tail -> next;
 				}		
		}else {//insert large
			if ( large_head == NULL ) {
				large_head = tmp;
				large_tail = tmp;
			
			}else{
				large_tail -> next = tmp;
				large_tail = large_tail-> next;
			}
		}
       }

       if ( small_tail == NULL ) return large_head;

       small_tail->next = large_head;
       return small_head;
    }
};


