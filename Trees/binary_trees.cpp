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
