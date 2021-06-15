//June 14

//https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1
//Approach- Size of binary tree means the number of nodes present in it. If the root of the tree is null, return 0. Bring the size of the left sub-tree and the
//right sub-tree and return the sum of the left and right sub-tree and add 1 for the root node

int getSize(Node* node){
   return node==NULL? 0: getSize(node->left)+getSize(node->right)+1;
}

//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
//Approach- Height of binaru tree is zero if the root of the tree is null, i.e., the tree is empty. Bring the height of the left and right subtree and find the 
//maximum out of them and add 1 for the root and return this as height

int height(struct Node* node){
    return node==NULL? 0: max(height(node->left), height(node->right))+1;
}

//https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1#
//Approach- For finding node with maximum value, find the maximum from left and right subtree, compare them and then compare the max value with the value of root
//and return the value which is maximum amongst all. Same for finding the minimum value

int findMax(Node *root){
    if(root==NULL) return INT_MIN; 
    int leftMax=findMax(root->left);
    int rightMax=findMax(root->right);
    return max(max(leftMax,rightMax),root->data);
}
int findMin(Node *root){
    if(root==NULL) return INT_MAX;
    int leftMin=findMin(root->left);
    int rightMin=findMin(root->right);
    return min(min(leftMin, rightMin),root->data);
}

//Search for given data in a binary tree
//Approach- If the binary tree is empty, return false and if the value to be searched for is at the root only, return true. Find the value in the left and right 
//sub-tree and return true if the value is found in left or right subtree

bool ifNodeExists(struct Node* root, int key){
    if(root==NULL) return false;
    if(root->data==key) return true;
    return ifNodeExists(root->left,key) || ifNodeExists(root->right,key);
}

//https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
//Approach- If the binary tree is empty, the sum of nodes is 0. Find the sum of left and right subtree and add the value of root node to it, sum it all and return

long int sumBT(Node* root){
    if(root==NULL) return 0;
    int leftSum=sumBT(root->left);
    int rightSum=sumBT(root->right);
    return leftSum+rightSum+root->key;
}

//https://leetcode.com/problems/binary-tree-paths/
//Approach- If the root is null, return empty string. If the root has no child, just add the value of root an return. If the root has children, enter the value of
//the root followed by an arrow, then call on left and right children. The string will be filled with all the root to node paths, push it in the vector and return

void getPaths (TreeNode* root, string s, vector<string>& res){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            s= s + to_string(root->val);
            res.push_back(s);
        }
        s= s + to_string(root->val) + "->";
        getPaths(root->left,s,res);
        getPaths(root->right,s,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return{};
        vector<string> res;
        getPaths(root,"",res);
        return res;
    }

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//Approach- Store the path from the root to first node given and the path from root to second node given in vectors. Lowest common ancestors of the two given nodes
//are to be found. The vector has the node to root path, i.e, the root is at the last index of vector. Compare the vectors and break the loop when the values become
//different. The last value which was common between the two lists is the lowest common ancestor of the two given nodes

bool rootToNodePath(TreeNode* root, TreeNode* data, vector<TreeNode*> &ans){
        if(root==NULL)
            return false;
        if(root==data){
            ans.push_back(root);
            return true;
        }
        bool res=rootToNodePath(root->left,data,ans)||rootToNodePath(root->right,data,ans);
        if(res)
            ans.push_back(root);
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> list1;
        vector<TreeNode*> list2;
        
        rootToNodePath(root,p,list1);
        rootToNodePath(root,q,list2);
        
        int i=list1.size()-1;
        int j=list2.size()-1;
        
        TreeNode* LCA;
        
        while(i>=0 && j>=0){
            if(list1[i]!=list2[j])
                break;
            LCA=list1[i];
            i--;
            j--;
        }
        return LCA;
    }

//https://leetcode.com/problems/binary-tree-inorder-traversal/
//Approach- If the root is null, return from the function. Then call the function on left only if the left sub-tree is not null, add the value of the root 
//in the value and then call right sub-tree only if it is not null. The resulting pattern in the vector is the inorder traversal of the binary tree

vector<int> ans;
    void recursion(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left!=NULL){
            recursion(root->left);
        }
        ans.push_back(root->val);
        if(root->right!=NULL){
            recursion(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        recursion(root);
        return ans;
    }

//https://leetcode.com/problems/binary-tree-preorder-traversal/
//Approach- If the root is null, return from the function. Then add the value of the root, call the function on left sub-tree only if it is not null, 
//and then call right sub-tree only if it is not null. The resulting pattern in the vector is the preorder traversal of the binary tree

vector<int> ans;
    void recur(TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root->val);
        if(root->left!=NULL) recur(root->left);
        if(root->right!=NULL) recur(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        recur(root);
        return ans;
    }

//https://leetcode.com/problems/binary-tree-postorder-traversal/
//Approach- If the root is null, return from the function. Then call the function on left sub-tree and right sub-tree only if they are not null. Then add the value
//of the root. The resulting pattern in the vector is the postorder traversal of the binary tree.

vector<int> ans;
    void recur(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL) recur(root->left);
        if(root->right!=NULL) recur(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        recur(root);
        return ans;
    }

//https://leetcode.com/problems/binary-tree-level-order-traversal/
//Approach- The value of the root is pushed in the queue and while the queue is not emplty, pop the front element and store its left and right child in a temporary
//queue. Push the popped element from the queue in a temporary vector and push this vector in the answer vector. The elements in the temporary queue is pushed into
//the queue and the process is repeated till the whole tree is traversed and the answer vector is returned. The vector has the level order traversal of binary tree

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(q.size()!=0){
            vector<int> vtemp;
            queue<TreeNode*> qtemp;
            while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                vtemp.push_back(temp->val);
                if(temp->left!=NULL) qtemp.push(temp->left);
                if(temp->right!=NULL) qtemp.push(temp->right);
            }
            ans.push_back(vtemp);
            while(!qtemp.empty()){
                q.push(qtemp.front());
                qtemp.pop();
            }
        }
        return ans;
    }

