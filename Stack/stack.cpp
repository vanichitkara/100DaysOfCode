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
