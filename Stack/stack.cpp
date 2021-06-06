//June 4

//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
//Approach- Fill the stack until the top element is greater than than the array elements. When an element greater than the top of the stack is encountered,
//put that element at the index of new array where the top element is in the original array till the stack is empty or a larger element is encountered. 
//Then push the element in the stack

vector<long long> nextLargerElementOnRight(vector<long long> arr, int n){
        vector<long long> ans(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(st.size()!=0 && arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

//Approach- Same as Next Greater Element on Right, but here we start the array traversal from right to left to find the greater element on the left of the array

vector<long long> nextLargerElementOnLeft(vector<long long> arr, int n){
        vector<long long> ans(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(st.size()!=0 && arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

//Approach- Same as Next Greater Element on Right, but here we reverse the inequality sign in the while loop to fill smaller elements instead of larger elements

vector<long long> nextSmallerElementOnRight(vector<long long> arr, int n){
        vector<long long> ans(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(st.size()!=0 && arr[st.top()]>arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

//Approach- Same as Next Smaller Element on Right, but here we start the array traversal from right to left to find the greater element on the left of the array

vector<long long> nextSmallerElementOnLeft(vector<long long> arr, int n){
        vector<long long> ans(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(st.size()!=0 && arr[st.top()]>arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

//https://leetcode.com/problems/next-greater-element-ii/
//Approach- It is similar to next greater element on right, we push the elemnets in stack till we encounter a greater element and then place that element
//in a new array at the same index at which the element was present in the original array. We push the elements till i<n and after that, we just check the array
//once again for greater elemetns but we don't push the smaller elements in stack this time

vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0; i<(2*n); i++){
            while(st.size()!=0 && arr[st.top()]<arr[i%n]){
                ans[st.top()]=arr[i%n];
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        return ans;
    }

//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
//Approach- Use next greater on left to find index at which the greater element on left is present and store it in a new array
//To find the stock span, modify the new array with (index of original array - new array element present on that index) and return the final array

vector <int> calculateSpan(int price[], int n){
       vector<int> ans(n,-1);
       stack<int> st;
       for(int i=n-1; i>=0; i--){
           while(st.size()!=0 && price[st.top()]<price[i]){
               ans[st.top()]=i;
               st.pop();
           }
           st.push(i);
       }
       for(int i=0; i<n; i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }

//https://leetcode.com/problems/online-stock-span/
//Approach- Make a stack of vector<int< and insert -1,-1 at the beginning as a reference for finding the span. Then use Next greater on left to pop out the 
//smaller elements and when a bigger element is encountered, subtract the indexes to find the stock span. After finding the span, insert the next price in stack

stack<vector<int>> st;
    int day=0;
    
    StockSpanner() {
        st.push({-1,-1});
    }
    
    int next(int price) {
        while(st.top()[0]!=-1 && st.top()[1]<=price){
            st.pop();
        } 
        int span=day-st.top()[0];
        st.push({day++,price});
        return span;
    }

//https://leetcode.com/problems/valid-parentheses/submissions/
//Approach- Using stack to evaluate the expression. If opening brackets are encountered in a string, they are inserted in the stack. 
//If closing brackets are encountered first they won't be pushed, in that case stack would be empty and false would be returned.
//The closing brackets encountered when match with their opening brackets, the opening brakcets are removed from stack. 
//If the stack is empty at the end, true is returned or else false is returned.

bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch=='('||ch=='['||ch=='{') st.push(ch);
            else{
                if(st.size()==0) return false;
                else if(ch==')' && st.top()!='(') return false;
                else if(ch==']' && st.top()!='[') return false;
                else if(ch=='}' && st.top()!='{') return false;
                else st.pop();
            }   
        }
        return st.size()==0;
    }

//https://leetcode.com/problems/validate-stack-sequences/submissions/
//Approach- Push the elements of the pushed array in stack till first element of popped array is equal to the element at the top of stack. When the top element
//is equal to the first element of popper array, remove the top and move the pointer to next element, keep comparing and increase the count of elements
//encountered. If the size of array is equal to the elements encountered, this means the stack sequence was right or else the stack sequence was wrong

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0, n=popped.size();
        for(int ele:pushed){
            st.push(ele);
            while(st.size()!=0 && st.top()==popped[i]){
                st.pop();
                i++;
            }
        }
        return i==n;
    }

//June 5

//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//Approach- Maintaining vector as a stack and pushing closing bracket's index if vector is empty and opening bracket indixes. 
//Opening brackets are popped by its corresponding closing bracket. The resulting vector stores the index of extra parentheses. We make a new string
//and push back the characters from original string while ignoring the brackets present at the index stored in the vector

string minRemoveToMakeValid(string s) {
        vector<int> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch=='(') st.push_back(i);
            else if(ch==')') {
                if(st.size()!=0 && s[st.back()]=='(') st.pop_back();
                else st.push_back(i);
            }
        }
        int idx=0;
        string ans="";
        for(int i=0; i<n; i++){
            if(idx<st.size() && st[idx]==i){
                idx++;
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }

//https://leetcode.com/problems/asteroid-collision/
//Approach- Asteroids collide only when asteroids approaching each other collide. A stack is maintained and positive elements are pushed. Whena negative element
//is encountered, and while its mod is greater than top of the stack and the stack elements are positive, the elements in stack are popped out. 
//If the mod of element is equal to the mod of stack's top, the top is popped out, else if either stack is empty or the is stack members are negative, the element
//is pushed. Then the stack elements are pushed in a vector.

vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ele: asteroids){
            if(ele<0){
                while(st.size()!=0 && st.top()<-ele && st.top()>0) st.pop();
                if(st.size()==0 || st.top()<0) st.push(ele);
                if(ele==-st.top()) st.pop();
            }
            else st.push(ele);
        }
        int idx=st.size();
        vector<int> v(st.size(),0);
        while(idx-->0){
            v[idx]=st.top();
            st.pop();
        }
        return v;
    }

//https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
//Approach 1- Find nearest smaller element on left, and if not present fill array with -1. Find nearest smaller element on right and if not present fill array
//with the size of array. Find width using the formula NSOR[i]-NSOL[i]-1 and find maximum area by comparing the already stored area with width* height[i]

void NSOL(vector<int> &arr, vector<int>& ans){
        stack<int> st;
        int n=arr.size();
        ans.resize(n,-1);
        for(int i=n-1; i>=0 ;i--){
            while(st.size()!=0 && arr[st.top()]>arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n ;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    void NSOR(vector<int> &arr, vector<int>& ans){
        stack<int> st;
        int n=arr.size();
        ans.resize(n,n);
        for(int i=0; i<n ;i++){
            while(st.size()!=0 && arr[st.top()]>arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n ;i++) cout<<ans[i]<<" ";
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsol,nsor;
        NSOL(heights, nsol);
        NSOR(heights, nsor);
        int area=0;
        int n=heights.size();
        for(int i=0; i<n; i++){
            int width=nsor[i]-nsol[i]-1;
            area=max(area,width*heights[i]);
        }
        return area;
    }

//Approach 2- The indexes of heights are pushed into the stack. When a height is encountered which is less than or equal to height at the index present at 
//top of stack, the stack elements are popped out. Width is calculated by formula width=i-st.top()-1 and height is the height of index encountered.
//Max area is calculated by comparing max area with product of width and height of the index encountered. The remaining elements in the stack are also evaluated
//in the same way, but their width is calculated by formula width=n-st.top()-1

int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        st.push(-1);
        int maxArea=0;
        int i=0; 
        while(i<n){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                int idx=st.top();
                st.pop();
                int h=heights[idx];
                int w=i-st.top()-1;
                maxArea=max(maxArea,h*w);
            }
            st.push(i++);
        }
        while(st.top()!=-1){
            int idx=st.top();
            st.pop();
            int h=heights[idx];
            int w=n-st.top()-1;
            maxArea=max(maxArea,h*w);
        }
        return maxArea;
    }

//June 6

//https://leetcode.com/problems/maximal-rectangle/submissions/
//Approach- We'll use the approach to find largest recatngle in histogram. We'll check for the top row, then top two rows, then top 3 rows and so on.
//The maximum rectangle will be stored and compared with height*width of othe rectangles found.
//Code-1
void NSOL(vector<int>& arr, vector<int>& ans){
        int n=arr.size();
        ans.resize(n,-1);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(st.size()!=0 && arr[st.top()]>arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    
    void NSOR(vector<int>&arr, vector<int>& ans){
        int n=arr.size();
        ans.resize(n,n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(st.size()!=0 && arr[st.top()]>arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    
    int largestRectangle(vector<int>& heights){
        int largestRec=0;
        int n=heights.size();
        vector<int> nsol, nsor;
        NSOL(heights, nsol);
        NSOR(heights, nsor);
        for(int i=0; i<n; i++){
            int h=heights[i];
            int w=nsor[i]-nsol[i]-1;
            largestRec=max(largestRec, h*w);
        }
        return largestRec;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int maxRec=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch=matrix[i][j];
                heights[j]=ch=='1'?heights[j]+1:0;
            }
            maxRec=max(maxRec,largestRectangle(heights));
        }
        return maxRec;
    }
    
    //Code-2
    int largestRectangle(vector<int>& heights){
        int i=0;
        int n=heights.size();
        stack<int>st;
        st.push(-1);
        int largestRec=0;
        while(i<n){
            while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                int idx=st.top();
                st.pop();
                int h=heights[idx];
                int w=i-st.top()-1;
                largestRec=max(largestRec, h*w);
            }
            st.push(i++);
        }
        while(st.top()!=-1){
            int idx=st.top();
            st.pop();
            int h=heights[idx];
            int w=n-st.top()-1;
            largestRec=max(largestRec,h*w);
        }
        return largestRec;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int maxRec=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch=matrix[i][j];
                heights[j]=ch=='1'?heights[j]+1:0;
            }
            maxRec=max(maxRec,largestRectangle(heights));
        }
        return maxRec;
    }

//
