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

//June 15

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

//June 16

//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//Approach- if root is equal to target node, print K down with no block node. Then print K down in left subtree and block the left sub tree if the left sub tree
//is not null and then print the rest of the K down. Do the same for right subtree. Push the K down values in the vector and return the answer vector

void printKDown (TreeNode* root, TreeNode* block, int depth, vector<int>& ans){
        if(root==NULL || depth<0 ||root==block)
            return;
        
        if(depth==0){
            ans.push_back(root->val);
            return;
        }
        
        printKDown(root->left, block, depth-1, ans);
        printKDown(root->right, block, depth-1, ans);
    }
    int distanceK(TreeNode* root, TreeNode* target, int k, vector<int>& ans){
        if(root==NULL) return -1;
        
        if(root==target){
            printKDown(root,NULL,k,ans);
            return 1;
        }
        
        int lans=distanceK(root->left, target, k, ans);
        if(lans!=-1){
            printKDown(root,root->left,k-lans,ans);
            return lans+1;
        }
        
        int rans=distanceK(root->right, target, k, ans);
        if(lans!=-1){
            printKDown(root,root->right,k-rans,ans);
            return rans+1;
        }
        
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        vector<int> ans;
        distanceK (root,target,k,ans);
        return ans;
    }

//https://leetcode.com/problems/diameter-of-binary-tree/
//Approach- Calculate the diameter of left and right subtree and compare it with the sum of left height + right height + 2 (for the two edges of the root). Return
//the maximum value out of the three calculated values as the diameter of the tree

int height(TreeNode* root){
        return root==NULL?-1 : max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return -1;
        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        return max(max(leftDia,rightDia), leftheight+rightheight+2);
    }

//https://leetcode.com/problems/path-sum/
//Approach- if root is null, return false. if root has no left and right subtree, return true if targetSum is equal to the root value, return false if otherwise.
//Then check for the path sum in left ans right subtree, and return true if the root to leaf path sum is available, else return false

bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return (targetSum-root->val==0);
        }
        return hasPathSum(root->left, targetSum-root->val)||hasPathSum(root->right, targetSum-root->val);
    }

//https://leetcode.com/problems/path-sum-ii/
//Approach- The approach is same as path sum, but here we store the path sum in the smallAns vector, and then store the smallAns in result vector and empty the
//smallAns vector to store another path sum and push it again to result vector. Return all the path sums in the tree

void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& smallAns){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            if(targetSum-root->val==0){
                smallAns.push_back(root->val);
                res.push_back(smallAns);
                smallAns.pop_back();
            }
            return;
        }
        smallAns.push_back(root->val);
        pathSum(root->left, targetSum-root->val,res,smallAns);
        pathSum(root->right, targetSum-root->val,res,smallAns);
        smallAns.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> smallAns;
        pathSum(root,targetSum,res,smallAns);
        return res;
    }

//June 17

//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#
//Approach- If root has no subtrees, return the value of the root. Find the maximum path sum in left and right sub tree and compare it with sum from one leaf node 
//to another. If left or rigth subtree is absent, the maximum of left and right node to leaf sum is added to the root's value. The maximum path sum is stored in 
//the maxLeafToLeaf variable and is returned as the answer

int maxLeafToLeaf= -(int)1e9;
    int maxPathSum_(Node* root)
    {
        // code here
        if(root==NULL) 
        return -(int)1e9;
        if(root->left==NULL&&root->right==NULL) 
        return root->data;
        int leftNodeToLeafMaxSum=maxPathSum_(root->left);
        int rightNodeToLeafMaxSum=maxPathSum_(root->right);
        if(root->left!=NULL&&root->right!=NULL){
            maxLeafToLeaf=max(maxLeafToLeaf,leftNodeToLeafMaxSum+rightNodeToLeafMaxSum+root->data);
        }
        return max(leftNodeToLeafMaxSum,rightNodeToLeafMaxSum)+root->data;
    }
    int maxPathSum(Node* root){
        if(root==NULL) return -(int)1e9;
        maxPathSum_(root);
        return maxLeafToLeaf;
    }

//https://leetcode.com/problems/binary-tree-maximum-path-sum/
//Approach- Get left and right subtree's max path sum for the given tree. The max sum till root will be the max of left and right subtree plus the root value. 
//Compare this with max path sum node to node, root's val and sum of left and right path sum plus the root value. The maximum of all these will be the answer

int maxNTN=-(int)1e9;
    int maxPathSum_(TreeNode* root){
        if(root==NULL) return -(int)1e9;
        int leftPathSum=maxPathSum_(root->left);
        int rightPathSum=maxPathSum_(root->right);
        int maxSumTillRoot=max(leftPathSum,rightPathSum)+root->val;
        maxNTN=max(max(maxNTN,maxSumTillRoot),max(root->val,leftPathSum+rightPathSum+root->val));
        return max(maxSumTillRoot,root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        maxPathSum_(root);
        return maxNTN;
    }

//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
//Approach- Push the value of root in the queue and while the size of queue is not zero, push back the front element in the answer vector and then pop the 
//values from the queue and insert their left and right child respectively. The value inserted in the vector are the left view of the tree

vector<int> answer;
   if(root==NULL) return answer;
   queue<Node*> que; 
   que.push(root);
   while(que.size()!=0){
       int size=que.size();
       answer.push_back(que.front()->data);
       while(size-->0){
            Node* rn=que.front();
            que.pop();
            if(rn->left!=NULL) que.push(rn->left);
            if(rn->right!=NULL) que.push(rn->right);
       }
   }
   return answer;

//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#
//https://leetcode.com/problems/binary-tree-right-side-view/
//Approach- The apporach is same as the left view of binary tree but here the right child is pushed before the left child so it becomes the front element of the 
//queue which is inserted into the answer vector

vector<int> answer;
        if(root==NULL) return answer;
        queue<Node*> que; 
        que.push(root);
        while(que.size()!=0){
            int size=que.size();
            answer.push_back(que.front()->data);
            while(size-->0){
                Node* rn=que.front();
                que.pop();
                if(rn->right!=NULL) que.push(rn->right);
                if(rn->left!=NULL) que.push(rn->left);
           }
       }
       return answer;
    }

//June 18

//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
//Approach 1- A vertical{air class is made to maintain the value of root along with its horizontal level. A queue of verticalPair elements is made and root's value is 
//inserted along with 0 as its horizontal level. Nodes on the left of root have negative horizontal level and right of root have positive horizontal level
//Then the elements of que are popped, and are mapped in hashmap with their horizontal levels and their left and right child are inserted till the whole tree is
//traversed. Then all the elements in the hashmap are inserted in a result vector according to increading order of the horizontal level

class verticalPair{
        public:
        TreeNode* node=NULL;
        int hl=0;
        
        verticalPair(TreeNode* node, int hl){
            this->node=node;
            this->hl=hl;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<verticalPair> que;
        que.push(verticalPair(root,0));
        int minhl=0, maxhl=0;
        unordered_map<int,vector<int>> map;
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                verticalPair rp=que.front();
                que.pop();
                map[rp.hl].push_back(rp.node->val);
                minhl=min(minhl,rp.hl);
                maxhl=max(maxhl,rp.hl);
                if(rp.node->left!=NULL){
                    que.push(verticalPair(rp.node->left,rp.hl-1));
                }
                if(rp.node->right!=NULL){
                    que.push(verticalPair(rp.node->right,rp.hl+1));
                }
            }
        }
        vector<vector<int>> res;
        while(minhl<=maxhl){
            res.push_back(map[minhl++]);
        }
        return res;
    }

//Approach 2- A vertical pair class is made, which has the node, it's horizontal and vertical level denoted by x and y respectively. Length is also calculated which
//is maximum horizontal level-minimum horizontal level+1. It is used to declare the size of the result vector. This time a priority queue is made so that the 
//smaller number gets inserted first into the result vector which was not the case with the previous approach. The rest is the same as Approach 1

class verticalPair{
        public:
        TreeNode* node=NULL;
        int x=0;
        int y=0;
        
        verticalPair(TreeNode* node, int x, int y){
            this->node=node;
            this->x=x;
            this->y=y;
        }
    };
    struct comp{
        public:
        bool operator()(const verticalPair a, const verticalPair b)const{
            if(a.y!=b.y)
                return a.y>b.y;
            else
                return a.node->val>b.node->val;
        }  
    };
    void width(TreeNode* root, int hl, vector<int>&ans){
        if(root==NULL) return;
        ans[0]=min(hl,ans[0]);
        ans[1]=max(hl,ans[1]);
        
        width(root->left,hl-1,ans);
        width(root->right,hl+1,ans);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<verticalPair, vector<verticalPair>, comp> que;
        vector<int> minMax(2,0);
        width(root,0,minMax);
        int len=minMax[1]-minMax[0]+1;
        vector<vector<int>> res(len);
        que.push(verticalPair(root,-minMax[0],0));
        while(que.size()!=0){
            int size=que.size();
            while(size-- > 0){
                verticalPair rp=que.top();
                que.pop();
                res[rp.x].push_back(rp.node->val);
                if(rp.node->left!=NULL){
                    que.push(verticalPair(rp.node->left,rp.x-1,rp.y+1));
                }
                if(rp.node->right!=NULL){
                    que.push(verticalPair(rp.node->right,rp.x+1,rp.y+1));
                }
            }
        }
        return res;
    }

//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
//Approach- Almost the same as vertical order traversal, but here the result vector keeps updating to the bottom most value find till now as we traverse the tree
//When the whole tree is traversed, the res vector will hold the bottom most values for its respective horizontal level on the indexes.

class verticalPair{
    public:
    Node* node=NULL;
    int hl=0;
    verticalPair(Node* node, int hl){
        this->node=node;
        this->hl=hl;
    }
};
void width(Node* root, int hl, vector<int>& ans){
    if(root==NULL) return;
    ans[0]=min(hl,ans[0]);
    ans[1]=max(hl,ans[1]);
    width(root->left,hl-1,ans);
    width(root->right,hl+1,ans);
}
vector <int> bottomView(Node *root)
{
   queue<verticalPair>que;
   vector<int>minMax(2,0);
   width(root,0,minMax);
   int len=minMax[1]-minMax[0]+1;
   vector<int> res(len,0);
   que.push(verticalPair(root,-minMax[0]));
   while(que.size()!=0){
       int size=que.size();
       while(size-- > 0){
           verticalPair rp=que.front();
           que.pop();
           res[rp.hl]=rp.node->data;
           if(rp.node->left!=NULL){
               que.push(verticalPair(rp.node->left,rp.hl-1));
           }
           if(rp.node->right!=NULL){
               que.push(verticalPair(rp.node->right,rp.hl+1));
           }
       }
   }
   return res;
}

//https://practice.geeksforgeeks.org/problems/vertical-sum/1
//Approach- It is the same as bottom view but when the tree is traversed, instead of replacing the old bottom most value with the new one for the same level, we
//add there values and keep them stored on the index corresponding to their horizontal level

class verticalPair{
        public:
        Node* node=NULL;
        int hl=0;
        verticalPair(Node* node, int hl){
            this->node=node;
            this->hl=hl;
        }
    };
    void width(Node* root, int hl, vector<int>& ans){
        if(root==NULL) return;
        ans[0]=min(hl,ans[0]);
        ans[1]=max(hl,ans[1]);
        width(root->left,hl-1,ans);
        width(root->right,hl+1,ans);
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
        queue<verticalPair> que;
        vector<int> minMax(2,0);
        width(root,0,minMax);
        int len=minMax[1]-minMax[0]+1;
        vector<int> res(len,0);
        que.push(verticalPair(root,-minMax[0]));
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                verticalPair rp=que.front();
                que.pop();
                res[rp.hl]+=rp.node->data;
                if(rp.node->left!=NULL)
                que.push(verticalPair(rp.node->left,rp.hl-1));
                if(rp.node->right!=NULL)
                que.push(verticalPair(rp.node->right,rp.hl+1));
            }
        }
        return res;
    }

//June 19

//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
//Approach- Push the root in a queue and pop the queue elements till the size of queue becomes zero. If the left subtree of the popped element exists, push that
//in the queue. Move the temp pointer to the right child of popped element and keep pushing them in the answer vector till temp becomes NULL. push the answer vector
//in the result vector and again back to a new 1D answer vector that is to be returned

vector<int> diagonal(Node *root)
{
   // your code here
   if(root==NULL) return {};
   vector<vector<int>> result;
   queue<Node*> que;
   que.push(root);
   while(que.size()!=0){
       int size=que.size();
       vector<int> answer;
       while(size-->0){
           Node* temp=que.front();
           que.pop();
           while(temp){
               answer.push_back(temp->data);
               if(temp->left)
               que.push(temp->left);
               temp=temp->right;
            }
       }   
       result.push_back(answer);
   }
   vector<int> answer;
   for(int i=0; i<result.size(); i++){
       for(int j=0; j<result[i].size(); j++){
           int a=result[i][j];
           answer.push_back(a);
       }
   }
   return answer;
}

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//Approach- Put idx on the position where the tree root is located. According to the preorder traversal, the root is the first element of the traversal. So move
//idx till it reaches the root in inorder traversal. Calculate the total number of elements in the left subtree by subtracting the starting point of inorder 
//traversal by the idx of root in inorder traversal. Then pass the array to left and right subtree of the root according to the calculated values.

TreeNode* buildTree(vector<int>& preorder, int psi, int pei, vector<int>& inorder, int isi, int iei){
        if(psi>pei) return NULL;
        int idx=isi;
        TreeNode* root=new TreeNode(preorder[psi]);
        while(inorder[idx]!=preorder[psi]) idx++;
        int tnel=idx-isi;
        root->left=buildTree(preorder,psi+1,psi+tnel,inorder,isi,idx-1);
        root->right=buildTree(preorder,psi+tnel+1,pei,inorder,idx+1,iei);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//Approach- Same as constructing tree from inorder and preorder traversal, but here the root is at the end of the postorder traversal, so idx and tnel and the
//passed values in the recursion will change accordingly

TreeNode* buildTree(vector<int>& postorder, int psi, int pei, vector<int>& inorder, int isi, int iei){
        if(psi>pei) return NULL;
        TreeNode* root=new TreeNode(postorder[pei]);
        int idx=isi;
        while(inorder[idx]!=postorder[pei]) idx++;
        int tnel=idx-isi;
        root->left=buildTree(postorder, psi, psi+tnel-1, inorder, isi, idx-1);
        root->right=buildTree(postorder,psi+tnel, pei-1, inorder,idx+1, iei);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        return buildTree(postorder, 0 ,n-1, inorder, 0, n-1);
    }

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
//Approach- Here the root is present at the start of preorder traversal and at the end of postorder traversal. The number of elements in the left subtree are
//calaculated by taking idx to the place where the last element of left subtree is present and then subtracting starting point of postorder from idx+1.
//The values are passed accordingly to calculate the left and right subtree

TreeNode* buildTree(vector<int>&pre, int psi, int pei, vector<int>& post, int ppsi, int ppei){
        if(psi>pei) return NULL;
        int idx=ppsi;
        TreeNode* root=new TreeNode(pre[psi]);
        if(psi==pei) return root;
        while(pre[psi+1]!=post[idx]) idx++;
        int tnel=idx-ppsi+1;
        root->left=buildTree(pre,psi+1, psi+tnel, post, ppsi, idx);
        root->right=buildTree(pre,psi+tnel+1,pei,post,idx+1,ppei-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return buildTree(pre,0,n-1,post,0,n-1);
    }

//June 20

//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//Approach 1- Call the flatten function on both left and right tree so that they both are flattened individually. Then traverse the left subtree to get its tail
//node. Then join the right subtree to the tail and then shift the left subtree to the right subtree and make the root's left null

TreeNode* getTail(TreeNode* root){
        if(root==NULL) return root;
        TreeNode* curr= root;
        while(curr->right!=NULL){
            curr=curr->right;
        }
        return curr;
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* tail=getTail(root->left);
        if(tail!=NULL){
            tail->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
    }

//Approach 2- Same as approach 1 but with a better time complexity

TreeNode* flatten1(TreeNode* root){
        if(root==NULL||(root->left==NULL && root->right==NULL)) return root;
        TreeNode* leftTail=flatten1(root->left);
        TreeNode* rightTail=flatten1(root->right);
        
        if(leftTail!=NULL){
            leftTail->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        return rightTail==NULL? leftTail:rightTail;
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten1(root);
    }

//June 21

//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#
//Approach- Call the function on left subtree to make it a doubly linked list first. Here the left most node is made prev->right and the node's left is prev, then
//prev moves to node and it attaches itself the same way to the root of the left most node, then the root of the leftmost node is attached to its right node in 
//the same way. Then the root of the tree is attached to the rightmost node of left tree and its right pointer is attached to the left most node of right subtree
//The right subtree is also converted into doubly linked list the same way as the left subtree. The head of the doubly linked is returned which is the leftmost
//node of the whole tree

Node* prev=NULL;
Node* head=NULL;
    void bToDLL1(Node* root){
        if(root==NULL) return;
        bToDLL1(root->left);
        if(head==NULL) head=root;
        else{
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        bToDLL1(root->right);
    }
    Node* bToDLL(Node *root)
    {
        // your code here
        if(root==NULL) return root;
        bToDLL1(root);
        return head;
    }

//https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1
//Approach- The same as doubly linked list, but here the head is connected to the previous node and previous is connected to head node to make the list circular

Node* prev=NULL;
Node* head=NULL;
    void bTreeToCList1(Node* root){
        if(root==NULL) return;
        bTreeToCList1(root->left);
        if(head==NULL) head=root;
        else{
            prev->right=root;
            root->left=prev;
        }
        prev=root;
        bTreeToCList1(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
    if(root==NULL) return root;
    bTreeToCList1(root);
    prev->right=head;
    head->left=prev;
    return head;
    }

//
