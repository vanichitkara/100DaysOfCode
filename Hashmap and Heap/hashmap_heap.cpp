//June 9

//https://leetcode.com/problems/kth-largest-element-in-an-array/
//Approach- Make a min priority queue and insert elements till size of queue is greater than given K. Do this till all elements are traversed, pushed and 
//the minimum element is popped out, leaving the Kth largest element to be popped out by the end of the loop

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int ele: nums){
            pq.push(ele);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }

//https://leetcode.com/problems/kth-largest-element-in-an-array/
//Approach- First add the given stream of numbers in the priority queues in the same way as the Kth largest element in an array question. Then add the values
//given one by one and pop out the smallest element when size of queues becomes greater than given K. After each iteration, we'll get Kth largest element in the 
//gievn stream

priority_queue<int, vector<int>, greater<int>> pq;
    int k=0;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int ele:nums){
            pq.push(ele);
            if(this->pq.size()>this->k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }

//https://leetcode.com/problems/intersection-of-two-arrays/
//Approach- First insert all the elements of the first array in the set. Then traverse through the second array and if the elements in set are also present in the
//second array, then insert those common elements in a new vector and return it as the answer

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int>set;
        for(int ele:nums1){
            set.insert(ele);
        }
        for(int ele:nums2){
            if(set.find(ele)!=set.end()){
                res.push_back(ele);
                set.erase(ele);
            }
        }
        return res;
    }

//June 10

//https://leetcode.com/problems/intersection-of-two-arrays-ii/
//Approach- Same as intersection of two arrays, but here duplicate elements are allowd so instead of removing the element from set after inserting it in the vector,
//its frequency can be reduced and it should be added again till the freqeuency of the element becomes zero

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> map;
        for(int i=0; i<nums1.size(); i++){
            map[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            if(map[nums2[i]]>0){
                res.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }
        return res;
    }

//https://leetcode.com/problems/top-k-frequent-elements/
//Approach- Elements are added in their map and their frequency is counted and added. The frequency and value pair is pushed into a priority queue and the element
//having the least frequency will be popped out everytime size of queue will be greater than K. All the elements present in the queue after the iteration are
//iterated again and the values from the frequency value pairs in the queue is pushed into a new vector which is returned as the answer

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int ele:nums) map[ele]++;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(pair<int,int> p: map){
            int val=p.first;
            int freq=p.second;
            pq.push({freq,val});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()!=0){
            vector<int> p=pq.top();
            pq.pop();
            int freq=p[0];
            int val=p[1];
            ans.push_back(val);
        }
        return ans;
    }

//https://leetcode.com/problems/longest-consecutive-sequence/
//Approach- The elements are inserted in set and one by one, the elements are iterated and thier immediate left and right elements are searched for in the set.
//If the element is present, and its left and right immediate elements are also present, we decrement the left ekement and increment the right element and search
//for them. This goes on till no more immediate left and right elements are found. The lenght of string is found as right element-left element-1. The elements
//which are found are removed from the set to improve its time complexity

int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int ele:nums) set.insert(ele);
        int len=0;
        for(int ele:nums){
            if(!set.count(ele)) continue;
            int ple=ele-1;
            int pre=ele+1;
            set.erase(ele);
            while(set.find(ple)!=set.end()) set.erase(ple--);
            while(set.find(pre)!=set.end()) set.erase(pre++);
            len=max(len,pre-ple-1);
        }
        return len;
    }

//https://leetcode.com/problems/k-closest-points-to-origin/
//Appraoch- Make a comparator class which compares the distances of two points from the origin. Make a priority queues which works according to this comparator
//class and removes the point which is farthest from origin when size of queue becomes greater than K. In this way, the K closest elements are present in the queue
//and they are pushed into a vector and returned as the answer.

class comp{
        public:
        bool operator() (const vector<int>& a, const vector<int>& b){
            int d1=a[0]*a[0]+a[1]*a[1];
            int d2=b[0]*b[0]+b[1]*b[1];
            return d2>d1;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for(vector<int>&p :points){
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()!=0){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

//June 11

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//Approach- Insert the first row of matrix in min priority queue and pop them while k is greater than zero. When first element of first row is popped, first element
//of second row is added. The elements are added row wise to optimise the space in hashmap and improve time complexity, When k becomes 0, the Kth smallest element
//is popped out

int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(); int m=matrix[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({matrix[i][0],i,0});
        }
        int ans;
        while(k-->0){
            vector<int> rv=pq.top(); 
            pq.pop();
            int val=rv[0];
            int x=rv[1];
            int y=rv[2];
            ans=val;
            y++;
            if(y<m) pq.push({matrix[x][y],x,y});
        }
        return ans;
    }

//https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
//Approach- Insert the elements if not already present in the vector and keep a track of its index using hashmap. To pop the element in O(1) time, replace the 
//element to be removed with the last element of the vector and update the indexes accordingly. The pop back the element to be removed from the vector

vector<int> v;
    unordered_map<int,int> map;
    
    bool insert(int val) {
        if(map.find(val)!=map.end()) return false;
        v.push_back(val);
        int idx=v.size()-1;
        map[val]=idx;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val)!=map.end()){
            int idx=map[val];
            int lidx=v.size()-1;
            v[idx]=v[lidx];
            map[v[lidx]]=idx;
            v.pop_back();
            map.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx=rand() % v.size();
        return v[idx];
    }

//https://leetcode.com/problems/maximum-frequency-stack/
//Approach 1- Maintain a vector of stacks and push elements with frequency=1 in one stack, frequency=2 in another stack and so on. Pop the element with maximum
//frequency ad reduce its frequency in the hashmap which is maintaining the elements inserted and their frequency. If the stack with maximum freqeuncy value is
//empty, decrement the maximum freuqency and if frequency of the value is zero, remove the value from the hashmap

vector<stack<int>> v;
    unordered_map<int,int> map;
    int maxfreq;
    FreqStack() {
        maxfreq=0;
        v.push_back(stack<int>());
    }
    
    void push(int val) {
        map[val]++;
        maxfreq=max(maxfreq,map[val]);
        if(v.size()==maxfreq)
            v.push_back(stack<int>());
        v[map[val]].push(val);
    }
    
    int pop() {
        int rv=v[maxfreq].top();
        v[maxfreq].pop();
        map[rv]--;
        if(v[maxfreq].size()==0)
            maxfreq--;
        if(map[rv]==0)
            map.erase(rv);
        return rv;
    }

//Approach 2-Make a priority queue of pair class which compares the values based on their frequency. The push and pop work the same way as approach 1

class pair{
        public:
        int val=0;
        int freq=0;
        int idx=0;
        
        pair(int val, int freq, int idx){
            this->val=val;
            this->freq=freq;
            this->idx=idx;
        }
    };
    
    class comp{
        public:
        bool operator() (const pair &a, const pair &b)const{
            if(a.freq==b.freq)
                return b.idx>a.idx;
            return b.freq>a.freq;
        }
    };
    
    unordered_map<int,int> map;
    priority_queue<pair,vector<pair>,comp>pq;
    int idx=0;
    
    void push(int val) {
        map[val]++;
        pq.push(pair(val,map[val],idx++));
    }
    
    int pop() {
        pair p=pq.top();
        pq.pop();
        map[p.val]--;
        if(map[p.val]==0)
            map.erase(p.val);
        return p.val;
    }


