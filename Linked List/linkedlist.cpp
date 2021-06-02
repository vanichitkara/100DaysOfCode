//June 1

//https://leetcode.com/problems/middle-of-the-linked-list/  

//Approach- Use fast and slow pointer, move fast pointer at twice the speed of the slow pointer. 
//When fast pointer will reach to the end, slow pointer will be at the middle

ListNode* middleNode(ListNode* head) {
        ListNode*slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

//https://leetcode.com/problems/reverse-linked-list/

//Approach- Use prev, curr and forw pointer. set prev as null and curr as head. 
//while curr!=NULL, initialize forw as curr->next, put curr->next as prev and move the pointers ahead.

ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }

//https://leetcode.com/problems/palindrome-linked-list/
//Approach- First find the middle of the list, break the list from the middle and reverse the second half of the list. 
//Then compare the values of the two linked list, if they are same, then the linked list is palindromic, else not.

bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* mid=middleNode(head);
        ListNode* newHead=mid->next;
        mid->next=NULL;
        newHead=reverseList(newHead);
        ListNode* curr1=head, *curr2=newHead;
        bool res=true;
        while(curr1!=NULL&&curr2!=NULL){
            if(curr1->val!=curr2->val){
                res=false;
                break;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return res;
    }

//https://leetcode.com/problems/reorder-list/
//Approch- Find the middle of the list and break it into two. Reverse the second half of the list. Declare curr1=head1 and curr2=head2
//Decalre forw1=curr1->next and forw2=curr2->next. Connect the curr1 with curr2 and curr2 with forw1. Move curr1 to forw 1 and curr2 to forw2 till they become NULL

void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL) return;
        
        ListNode* mid= middleNode(head);
        ListNode* newhead=mid->next;
        mid->next=NULL;
        newhead=reverseList(newhead);
        ListNode *curr1=head;
        ListNode *curr2=newhead;
        
        while(curr1!=NULL&&curr2!=NULL){
            ListNode*forw1=curr1->next;
            ListNode*forw2=curr2->next;
            curr1->next=curr2;
            curr2->next=forw1;
            curr1=forw1;
            curr2=forw2;

        }
    }

//https://leetcode.com/problems/merge-two-sorted-lists/
//Approach- Make a dummy node and declare prev=dummy. Now compare the values of the list and connect the smaller one with prev. Return prev->next (head of ll)

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev=dummy;
        ListNode* c1=l1;
        ListNode* c2=l2;
        while(c1!=NULL&&c2!=NULL){
            if(c1->val<=c2->val){
                prev->next=c1;
                c1=c1->next;
            }
            else if(c2->val<c1->val){
                prev->next=c2;
                c2=c2->next;
            }
            prev=prev->next;
        }
        prev->next=c1!=NULL?c1:c2;
        ListNode*h=dummy->next;
        delete dummy;
        return h;
    }

//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//Appraoch- Decare curr=head, compare value of curr and curr->next. If they're equal, connect curr with curr->next->next else move the curr pointer ahead.

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL&&curr->next!=NULL){
            if(curr->next->val==curr->val)
                curr->next=curr->next->next;
            else curr=curr->next;
        }
        return head;
    }

//https://leetcode.com/problems/sort-list/
//Approach-Break the list from the middle and merge those two parts after sorting them individually. 
//Do this recursively until each element is attached in sorted manner.

ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* mid=middleNode(head);
        ListNode* newHead=mid->next;
        mid->next=NULL;
        return mergeTwoSortedLists(sortList(head),sortList(newHead));
    }

//https://leetcode.com/problems/merge-k-sorted-lists/
//Approach- The linked list is stored in vector form so find mid using si+(ei-si)/2. The list will continue to divide into two recursively
//Then merge the list from start to mid and then mid+1 to end. The smaller lists will sort themselves and merge with their other halves to return sorted list

ListNode* mergeKLists (vector<ListNode*> & lists, int si, int ei){
        if(si==ei) return lists[si];
        int mid=si+(ei-si)/2;
        ListNode*list1=mergeKLists(lists, si, mid);
        ListNode*list2=mergeKLists(lists,mid+1,ei);
        return mergeTwoSortedLists(list1,list2);
    }
ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeKLists(lists,0,lists.size()-1);
    }
