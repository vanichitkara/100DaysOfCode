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

//June 2

//https://leetcode.com/problems/linked-list-cycle/
//Approach- Declare slow and fast pointer at head. Move fast pointer twice as fast as slow pointer. If they meet at a node, the linked list has a cycle

bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }

//https://leetcode.com/problems/linked-list-cycle-ii/
//Approach- Same as Linked List 1, but after the slow and fast pointer meet, relocate slow at head and move fast and slow pointer one at at time. 
//The node at which they meet is the node where the cycle begins. We relocate the slow pointer at head because the distance between the slow pointer
//and the node where the cycle begins would be equal to the distance between the fast pointer and the required node.

ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&& fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        if(fast!=slow){
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }

//https://leetcode.com/problems/intersection-of-two-linked-lists/
//Approach 1- (if modifying the ll is allowed) Declare a tail pointer at headA and move it till the last node. Join the last node with headB and 
//run the detect cycle code to find the node where the linked lists intersect
//Approach 2- (Used in the question as modifying the ll was not allowed) Find the length of both the ll and move the pointer on the bigger list till the time
//its length is equal to the smaller list. Then move both the pointers till they point to the same node. Return that node

int len(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        if(headA==headB) return headA;
    
        int l1=len(headA);
        int l2=len(headB);
        
        ListNode* biggerList= l1>l2 ?headA:headB;
        ListNode* smallerList= l1>l2 ?headB:headA;
        
        int diff=max(l1,l2)-min(l1,l2);
        
        while(diff-->0){
            biggerList=biggerList->next;
        }
        
        while(biggerList!=smallerList){
            biggerList=biggerList->next;
            smallerList=smallerList->next;
        }
        return biggerList;
    }

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Approach- Have two pointers c1 and c2 declared at the head. move c2 till n becomes zero and then move c1 and c2 one step at a time. 
//This way, c1 will be at n-1 node and declare temp at c1->next i.e. at the node which has to be removed. Join c1->next with temp->next,
//break the connection between nth node and its next node and return the list.

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode* c1=head;
        ListNode* c2=head;
        while(n-->0){
            c2=c2->next;
        }
        if(c2==NULL){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            return head;
        }
        while(c2->next!=NULL){
            c1=c1->next;
            c2=c2->next;
        }
        ListNode*temp=c1->next;
        c1->next=temp->next;
        temp->next=NULL;
        return head;
    }

//https://leetcode.com/problems/reverse-linked-list-ii/
//Approach- The linked list uses an idx pointer which starts from 1 and while the pointer is between the range which is to be reversed, it breaks the ll and 
//joins it in a reverse manner with its next node. when idx goes beyond the right limit, the reversed list is joined with the original list that 
//remains unchanged and the head of the list is returned.

    ListNode* th=NULL;
    ListNode* tt=NULL;
    
    void addFirstNode (ListNode* node){
        if(th==NULL){
            th=node;
            tt=node;
        }
        else{
            node->next=th;
            th=node;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right) return head;
        int idx=1;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            while(idx>=left && idx<=right){
                ListNode* forw=curr->next;
                curr->next=NULL;
                addFirstNode(curr);
                curr=forw;
                idx++;
            }
            if(idx>right){
                if(prev!=NULL){
                    prev->next=th;
                    tt->next=curr;
                    return head;
                }
                else{
                    tt->next=curr;
                    return th;
                }
            }
            idx++;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }

//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
//Approach- start with two lists, dummmyOdd and dummyEven. Declare curr pointer at head and traverse the whole list while checking the values for odd and even.
//if the value is even, join it with even list else join with odd list and move ahead till the list ends. Then join the tail of dummyEven with dummyOdd head
//and return the even head. If there are no even elements then return odd head.

Node* divide(int N, Node *head){
        // code here
        Node* dummyOdd= new Node (-1);
        Node* dummyEven=new Node (-1);
        Node* odd=dummyOdd;
        Node* even=dummyEven;
        Node*curr=head;
        while(curr!=NULL){
            if(curr->data%2==0){
                even->next=curr;
                even=even->next;
            }
            else{
                odd->next=curr;
                odd=odd->next;
            }
            curr=curr->next;
        }
        even->next=dummyOdd->next;
        odd->next=NULL;
        return dummyEven->next;
    }

