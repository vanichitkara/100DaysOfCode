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
