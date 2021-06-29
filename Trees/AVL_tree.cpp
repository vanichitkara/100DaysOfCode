//June 29

//https://practice.geeksforgeeks.org/problems/avl-tree-insertion/1
//Approach- Check height and balance of tree after every insertion. If balance>1 and data is less than node's left data, then do rigth rotation (left-left structure)
//If balance<-1 and data greater than node's right data, do left rotation (right-right structure). If balance>1 and data is greater than node's left data, first do
//left rotation and then right rotation (left-right structure). If balance<-1 and data is less than node's right data, first do right rotation and then left
//rotation (right-left structure)

int height (Node* node){
        return node==NULL?0:max(height(node->left),height(node->right))+1;
    }
    int getBalance(Node *N){
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    Node* leftRotation(Node* A){
        Node* B=A->right;
        Node* Bleft=B->left;
        B->left=A;
        A->right=Bleft;
        A->height = max(height(A->left),   
                    height(A->right)) + 1;
        B->height = max(height(B->left),
                    height(B->right)) + 1;
 
        return B;
    }
    Node* rightRotation(Node* A){
        Node* B=A->left;
        Node* Bright=B->right;
        B->right=A;
        A->left=Bright;
        A->height = max(height(A->left),
                    height(A->right)) + 1;
        B->height = max(height(B->left),
                    height(B->right)) + 1;
        return B;
    }
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        Node* newNode=new Node(data);
        if (node == NULL)
        return newNode;
 
        if (data < node->data)
            node->left = insertToAVL(node->left, data);
        else if (data > node->data)
            node->right = insertToAVL(node->right, data);
        else 
            return node;
     
        node->height = 1 + max(height(node->left),
                            height(node->right));
     
        int balance = getBalance(node);
     
        if (balance > 1 && data < node->left->data)
            return rightRotation(node);
     
        if (balance < -1 && data > node->right->data)
            return leftRotation(node);
     
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }
     
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
     
        return node;
    }
