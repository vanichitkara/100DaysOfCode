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
