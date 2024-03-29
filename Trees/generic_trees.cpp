//June 30

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/size-generic-tree-official/ojquestion
//Approach- Check for all the children nodes and count them till all the children are traversed, then return with size+1 as 1 isadded for the root node

int size(Node* node){
    int size=0;
    for(Node* child:node->children){
        size+=size(child);
    }
    return size+1;
  }

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/height-of-generic-tree-official/ojquestion
//Approach- Check for all the children and get the maximum height out of all the children subtrees and then add 1 to the maximum height to count for root's branch

int height(Node* node) {
    int h=-1;
    for(Node* child: node->children){
        h=max(h,height(child));
    }
    return h+1;
  }

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/max-generic-tree-official/ojquestion
//Approach- Assign root's data as maximum element and compare all the values of children subtrees and return the maximum of them all

int maximum(Node* node) {
    int maxEle=node->data;
    for(Node* child: node->children){
        maxEle=max(maxEle,maximum(child));
    }
    return maxEle;
  }

//Minimum element
//Approach- Assign root's data as minimum element and compare all the values of children subtrees and return the minimum of them all

int minimum(Node* node) {
    int minEle=node->data;
    for(Node* child: node->children){
        minEle=min(minEle,minimum(child));
    }
    return minEle;
  }

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/find-in-tree-official/ojquestion
//Approach- If the data to be found is present at the root only, return true. If not, then traverse through all the children nodes and if data is found return true
//else return false

bool find(Node* node, int data) {
    if(node->data==data) return true;
    for(Node* child: node->children){
        if(find(child,data)) return true;
    }
    return false;
  }

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/node-to-root-path-official/ojquestion
//Approach- If the root is eqaul to the given data from whcih the root to node path is found, push that value and return true, i.e. the path is found. If that's not
//the case, then traverse through all the children to find the data from which root to node path is found. If that data is found, push all the values from that node
//to root, if data is not found, return false and the vector will remain empty.

bool nodeToRootPath(Node* node, int data, vector<int> ans){
     if(node->data==data){
         ans.push_back(node->data);
         return true;
     }
     bool res=false;
     for(Node* child:node->children){
         res=res||nodeToRootPath(child,data,ans);
     }
     if(res)
     ans.push_back(node->data);
     return res;
 }
 vector<int> nodeToRootPath(Node* node, int data){
    vector<int> ans;
    nodeToRootPath (node,data,ans);
    return ans;
 }

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/lca-generic-tree-official/ojquestion
//Appraoch- find the root to node path from both l1 and l2. And then traverse the vector in which their root to ndoe path is stored. When the nodes at the index
//are not equal, break the loop and the ast common value found in the vector is the lowest common ancestor of l1 and l2

bool nodeToRootPath(Node* node, int data, vector<Node*> ans){
     if(node->data==data){
         ans.push_back(node);
         return true;
     }
     bool res=false;
     for(Node* child:node->children){
         res=res||nodeToRootPath(child,data,ans);
     }
     if(res)
     ans.push_back(node);
     return res;
 }

  int lca(Node* node, int d1, int d2) {
    vector<Node*> l1;
    nodeToRootPath(node,d1,l1);
    vector<Node*> l2;
    nodeToRootPath(node,d2,l2);
    int i=l1.size()-1;
    int j=l2.size()-1;
    int lca=0;
    while(i>=0 && j>=0){
        if(l1[i]!=l2[j]) break;
        lca=l1[i]->data;
        i--;
        j--;
    }
    return lca;
  }

//https://leetcode.com/problems/n-ary-tree-level-order-traversal/
//Approach- Make a queue and push the root node in it. Then pop it and insert it in a vector and push it's children in the queue. Now those children are popped one
//by one and inserted into the vector while their children are inserted in the queue. This goes on till all the nodes are traversed and are pushed into the vector

vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>>res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>tmp;
            for(int i=0;i<n;i++){
                Node* cur=q.front();
                q.pop();
                tmp.push_back(cur->val);
                for(Node* it: cur->children){
                    q.push(it);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }

//https://www.pepcoding.com/resources/online-java-foundation/generic-tree/is-generic-tree-symmetric-official/ojquestion
//Approach- If the size of the trees whose symmetry is to checked is not same, return false. Then check for each node of the trees whether they are symmetric or not

bool areMirror (Node* n1, Node* n2){
      if(n1->children.size()!=n2->children.size())
      return false;
      for(int i=0, j=n1->children.size()-1; j>=0; i++,j--){
          Node* child1= n1->children[i];
          Node* child2= n2->children[j];
          if(!areMirror(child1,child2))
          return false;
      }
      return true;
  }
  bool IsSymmetric(Node* node) {
    return areMirror(node, node);
  }
