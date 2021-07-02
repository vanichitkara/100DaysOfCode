//June 24

//https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1
//Approach- If root is NULL, return 0, else return size of left subtree + size of right subtree + 1. The recursive function gets size of each subtree

int getSize(Node* node){
   return node==NULL?0:getSize(node->left)+getSize(node->right)+1;
}

//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
//Approach- If root is NULL, return 0, else return the maximum of height of left and right subtree + 1 for the root. The recursive function return height of 
//every subtree

int height(struct Node* node){
    return node==NULL? 0 : max(height(node->left),height(node->right))+1;
}

//Maximum element in BST
//Approach- The maximum value in the BST is its rightmost node. Make a curr node and take it to the rightmost node 

int minValue(Node* root){
    if(root==NULL) return -1;
    if(root->left==NULL) return root->data;
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

//https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
//Approach- The minimum value in the BST is its leftmost node. Make a curr node and take it to the rightmost node 

int minValue(Node* root){
    if(root==NULL) return -1;
    if(root->left==NULL) return root->data;
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

//https://leetcode.com/problems/search-in-a-binary-search-tree/
//Approach 1- Recursive approach traverses in left and right subtree to find the element if root is not the value to be searched for

TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        if(val<root->val){
            return searchBST(root->left,val);
        }
        else{
            return searchBST(root->right,val);
        }
    }

//Approach 2- Iterative approach traverses left subtree if the value to be found is less than root's value and right subtree if the value to be found is greater
//than root's value

TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->val==val) return curr;
            else if(val<curr->val) curr=curr->left;
            else curr=curr->right;
        }
        return curr;
    }

//https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/
//Approach 1- Recursively insert the node where it should be placed. The node will be placed in left or right subtree according to the comparison of the inserted
//value and root's value

TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(root==NULL) return node;
        if(val<root->val) 
            root->left=insertIntoBST(root->left,val);
        else root->right=insertIntoBST(root->right,val);
        return root;
    }

//Approach 2- Iterative approach to insert the node in the tree

TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        while(curr!=NULL){
            prev=curr;
            if(val<curr->val) curr=curr->left;
            else curr=curr->right;
        }
        TreeNode* node=new TreeNode(val);
        if(prev==NULL) return node;
        else if(val<prev->val) prev->left=node;
        else prev->right=node;
        return root;
    }

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//Approach- The lowest common ancestor is founf accordingly in left or right subtree depending on the value of p and q. If p is greater than root's value and q is
//greater than root's value, then root is the lowest common ancestor

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(curr!=NULL){
            if(p->val<curr->val && q->val<curr->val){
                curr=curr->left;
            }
            else if(p->val>curr->val && q->val>curr->val){
                curr=curr->right;
            }
            else return curr;
        }
        return NULL;
    }

//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//Approach- The array is sorted recursively by finding the middle of the given vector and then partitioning it into two parts and arranging it into left and right
//subtree

TreeNode* sortedArrayToBST(vector<int>& nums, int si, int ei) {
        if(si>ei) return NULL;
        int mid=(si+ei)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=sortedArrayToBST(nums,si,mid-1);
        node->right=sortedArrayToBST(nums,mid+1,ei);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }

//June 26

//https://leetcode.com/problems/delete-node-in-a-bst/
//Approach- If the node to be deleted has no child, simply attach NULL to its parent. If the node had left child or righ child, make its parent node point directly
//to its child. If the node to be removed has both left and righ child, find the maximum node in leftsubtree, replace the value of the node to be removed with
//the maximum in left subtree, and then remove the node with max value in left subtree to maintain the order of BST

int maxNode (TreeNode* root){
        TreeNode* curr=root;
        while(curr->right!=NULL){
            curr=curr->right;
        }
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else if(key>root->val)
            root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL||root->right==NULL)
                return root->left!=NULL?root->left:root->right;
            int maxValue=maxNode(root->left);
            root->val=maxValue;
            root->left=deleteNode(root->left,maxValue);
        }
        return root;
    }

//June 27

//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
//Approach- To find predecessor and successor, a root's predecessor will be the rightmost node of its left subtree if not null, and successor will be leftmost node
//of right subtree if not null, when current node is equal to key. If current node is smaller than the given key, the predeseccor is set as current node and current
//is shifted to its right. Else if the current node is greater than the given key, the successor is set as curr and current node is shifted to its left

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    Node* curr=root;
    bool isDataPresent=false;
    while(curr!=NULL){
        if(curr->key==key){
            isDataPresent=true;
            if(curr->left!=NULL){
                pre=curr->left;
                while(pre->right!=NULL) pre=pre->right;
            }
            if(curr->right!=NULL){
                suc=curr->right;
                while(suc->left!=NULL) suc=suc->left;
            }
            break;
        }
        else if(curr->key<key){
            pre=curr;
            curr=curr->right;
        }
        else{
            suc=curr;
            curr=curr->left;
        }
    }
}

//https://leetcode.com/problems/binary-search-tree-iterator/
//Approach- Make a stack of tree nodes and push the root and it's left children till there exist none. And then pop the topmost element when next function is called
//and push all of the right children of the popped node. When hasnext function is call, check if the size of stack is zero and return true when size is not zero.

stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        addAllLeft(root);
    }
    
    void addAllLeft(TreeNode* root){
        if(root==NULL) return;
        TreeNode* curr=root;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        addAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.size()!=0;
    }

//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
//Approach- Traverse through the preorder array and when checking for each node and set it's range. If the next node belongs to left node's range, attach it there
//else attach it to the right side of the node

int idx=0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int lr, int rr) {
        if(idx>=preorder.size() || preorder[idx]<lr || preorder[idx]>rr)
            return NULL;
        
        TreeNode* node=new TreeNode(preorder[idx++]);
        node->left=bstFromPreorder(preorder,lr,node->val);
        node->right=bstFromPreorder(preorder,node->val,rr);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     return bstFromPreorder(preorder,-(int)1e8,(int)1e8);
    }

//https://leetcode.com/problems/validate-binary-search-tree/
//Approach- Check if the left subtree has values shorter than root's value and right subtree has values greater than root's value, i.e., the property of BST is 
//maintained

bool isValidBST(TreeNode* root, long min, long max){
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, -(long)1e13, (long)1e13);
    }

//June 28

//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//Approach- Make two stacks of BST, one containing the left boundary node and the other containing right boundary nodes. Then add top of the two stacks and if 
//they are equal to the sum required, return true. If it's smaller than required sum, pop the top of stack containing left boundary nodes and insert its right
//nodes till there are no more nodes left to add. If it's greater than required sum, pop the top of stack containing right boundary nodes and insert its left nodes
//till there are none left to add. If there is no two sum pair in the BST, return false

void insertAllLeft(stack<TreeNode*>&st, TreeNode* node){
        while (node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
    void insertAllRight (stack<TreeNode*>&st, TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        stack<TreeNode*> lst;
        stack<TreeNode*> rst;
        
        insertAllLeft(lst,root);
        insertAllRight(rst,root);
        
        while(lst.top()->val<rst.top()->val){
            int sum=lst.top()->val+rst.top()->val;
            if(sum==k) return true;
            else if(sum<k){
                TreeNode* node=lst.top();
                lst.pop();
                insertAllLeft(lst,node->right);
            }
            else{
                TreeNode* node=rst.top();
                rst.pop();
                insertAllRight(rst,node->left);
            }
        }
        return false;
    }

//https://leetcode.com/problems/balance-a-binary-search-tree/
//Approach- Push the values of the tree in inorder sequence. Then take the middle of the vector and make it the root. Then populate the left and right subtree
//by taking middle recursively within the given range for left and right subtree.

vector<int> vec;
    
    void values(TreeNode* root){
        if(!root) return;
        values(root->left);
        vec.push_back(root->val);
        values(root->right);
    }
    
    TreeNode* create(int l, int r, vector<int>& vec){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(vec[mid]);
        root->left=create(l,mid-1,vec);
        root->right=create(mid+1,r,vec);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        values(root);
        int l=0, r=vec.size()-1;
        return create(l,r,vec);
    }

//July 1

//https://leetcode.com/problems/recover-binary-search-tree/
//Approach- set the first pointer as the node which is out of order, i.e. which disturbs the order of the inorder traversal, set the second pointer as the node with
//which it should be swapped to restore the correct inorder traversal which follows the property of BST

TreeNode* prev=NULL, *first=NULL, *second=NULL;
    void recover(TreeNode* root){
        if(root==NULL) return;
        recover(root->left);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL)
                first=prev;
            second=root;
        }
        prev=root;
        recover(root->right);
    }
    void recoverTree(TreeNode* root) {
        recover(root);
        int temp=0;
        temp=first->val;
        first->val=second->val;
        second->val=temp;
    }

//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//Approach- Push the root node and all the right nodes of it, then pop them one by one and push all the left elements of the popped element till it's left node is 
//null. The tree will be pushed in inorder manner and while k is reater than 1, the nodes will be popped and their left elements will be pushed.

void insertLeftMost(stack<TreeNode*> &st, TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->left; 
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        insertLeftMost(st,root);
        while(k-- > 1){
            TreeNode* node=st.top();
            st.pop();
            insertLeftMost(st,node->right);
        }
        return st.top()->val;
    }

//https://practice.geeksforgeeks.org/problems/median-of-bst/1
//Approach- First traverse the given tree in inorder manner, then find the size of the tree. if size is odd then return middle element, else return the average of
// the two middle elements

int x,y;
void inOrder(Node* root,int &count,int n){
    if(root==NULL)
        return;
    inOrder(root->left,count,n);
    count++;
    if(count==n/2){
        x=root->data;
    }
    if(count==(n/2)+1){
        y=root->data;
    }
    inOrder(root->right,count,n);
}
int size(Node* root){
    if(root==NULL)
        return 0;
    
    return size(root->left) + 
           size(root->right) + 1;
}
float findMedian(struct Node *root)
{
    x=0;
    y=0;
    int count=0;
    int n=size(root);
    inOrder(root,count,n);
    if(n%2==0)
        return (float)(x+y)/2.0;
    else
        return y;
}

//https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
//Approach- Check the array one by one, the first element is the root, and the following elements will go in left subtree if they are less than root's value and 
//right subtree if they are greater than root' value

Node *construct(Node *root,int key){
    if(root==NULL)
    return new Node(key);
    if(root->data<key)
    root->right=construct(root->right,key);
    if(root->data>key)
    root->left=construct(root->left,key);
    return root;
}
Node* constructBst(int arr[], int n)
{
     Node *root=new Node(arr[0]);
     for(int i=0;i<n;i++){
         if(root->data>arr[i])
         root->left=construct(root->left,arr[i]);
         if(root->data<arr[i])
         root->right=construct(root->right,arr[i]);
     }
     return root;
}
