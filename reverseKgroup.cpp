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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    ListNode * head_head , * pre , * first , * last, * pt , * tmp ;
	int i=1;
	if ( head == NULL ) return head;
	if ( k == 1) return head;
	head_head = new ListNode(0);
	head_head->next = head;
	pre = head_head;
	pt = head;
        first = NULL;

	while ( pt != NULL){
		tmp = pt->next;

		if ( i % k == 1 ){
			last = pt ;
			last->next = NULL;
			first = NULL;
		}

		pt->next = first;
		first = pt;

		if ( i % k == 0 ) {
			pre->next = first;
			last->next = tmp;
			pre = last;
		}
		i ++;
		pt = tmp;
	}

	if ( i%k != 1) {//we should recover the remaining nodes that less that it

		pt = first->next;
		first->next = NULL; 

		while ( pt != NULL){
			tmp = pt->next;
			pt->next = first;
			first = pt;
			pt = tmp;
				
		}

		pre->next = last;
		

	}
	


	head = head_head->next;
	delete head_head;
	return head;

        
    }
};

 
