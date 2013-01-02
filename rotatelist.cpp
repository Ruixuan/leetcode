class Solution {
	public:
	    ListNode *rotateRight(ListNode *head, int k) {
	            // Start typing your C/C++ solution below
	            // DO NOT write int main() function
		    ListNode * pt , * pre , * head_head;
		    int i,n;

		    if ( k == 0 ) return head;
		    if ( head == NULL ) return head;
		    pt = head;
		    n = 1;
		    while ( pt->next != NULL ) {
			    pt = pt->next;
			    n ++;
		    }

		    pt->next = head;
		    pt = head;
		    k =  k % n;	
		    for ( i = 1 ; i < n-k ; i ++ ){
			    pt = pt ->next ;
		    }

		    head = pt->next;
		    pt->next = NULL;

		    return head;
		   

				            
        }
};
