// January 13

//https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1/
//Approach- The approach is to reverse the first part of array till index d-1, and then reverse the later part by swapping the elements until the iterators reach the same index.
//Then reverse the whole array by swapping the first and the last element and moving the iterators till they are on the same index.

void swap (int nums[], int i, int j){
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}

void reverse(int nums[], int i, int j){
    while(i<j){
        swap(nums, i++, j--);
    }
}
//Function to rotate an array by d elements in counter-clockwise direction. 
void rotateArr(int arr[], int d, int n){
    // code here
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

//https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1/
//Approach- Keep a pointer at -1 and keep an iterator which will iterate the array, whenever that iterator reaches an index with the element zero, the pointer is moved ahead and
//the elements at the iterator and pointer are swapped, and this continues till the iterator iterates the whole array.

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void segregate0and1(int arr[], int n) {
    // code here
    int ptr=-1;
    int itr=0;
    while(itr<n){
        if(arr[itr]==0){
            swap(arr,++ptr,itr);
        }
        itr++;
    }
}

//https://leetcode.com/problems/sort-colors/
//Approach- Make three pointers, ptr1, ptr2 and itr. Keep ptr1=-1, itr=0, and ptr2=size-1. itr will iterate the array. from 0 to ptr1, we'll have all zeroes, from ptr1+1 to 
//itr-1 we'll have all the ones, from itr to ptr2-1, the area is left to be traversed when the iteration si going on and from ptr2 to size-1, we have all the twos. 
//Start the iteration and when a zero is encountered, move forward ptr1 and swap the elements at itr and ptr1 and then move forward itr. If a 1 is encountered, just move the
//iterator forward. If a two is encountered, just swap elements at itr and ptr2 and then move ptr2 backward. When itr crosses ptr2, we have our whole array sorted.

void swap(vector<int>&nums, int i, int j){
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}
void sortColors(vector<int>& nums) {
    int n=nums.size();
    int ptr1=-1;
    int itr=0;
    int ptr2=n-1;

    while(itr<=ptr2){
        if(nums[itr]==0){
            ptr1++;
            swap(nums,ptr1,itr);
            itr++;
        }
        else if(nums[itr]==2){
            swap(nums,ptr2,itr);
            ptr2--;
        }
        else itr++;
    }
}

//https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1
//Approach- First find the sum of all elements and then find the sum of elements multiplied with their indices. Then to find the maximum sum, we need to rotate the array and
//again find the sum of elements multiplied with their indices, but instead of that, we find a formula to work around the same. Using that foruma, find the max sum

int max_sum(int A[],int N)
{
    int sum=0;
    for(int i=0; i<N; i++){
        sum+=A[i];
    }
    
    int csum=0;
    for(int i=0; i<N; i++){
        csum+=i*A[i];
    }
    
    int ans=csum;
    for(int i=1; i<N; i++){
        int nsum=csum-sum+N*A[i-1];
        ans=max(ans,nsum);
        csum=nsum;
    }
    
    return ans;
}


// January 15

//https://leetcode.com/problems/container-with-most-water/
//Approach- Using two pounter approach, we calculate the area by multiplying the width with the height of the vertical line present at the index. If the height of line at index
//i is less than height of line at index j, then area is calculated by multiplying the width with the height of line at i, and then i is moved forward and width is recalculated.
//And if height of line at j is smaller than that at i, then area is calculated by multiplying the width with the height of line at j and then j is moved backward. 

int maxArea(vector<int>& height) {
    int n=height.size();
    int i=0; 
    int j=n-1;
    int maxArea=0;
    while(i<j){
        int w=j-i;
        if(height[i]<height[j]){
            maxArea=max(maxArea,height[i++]*w);
        }
        else maxArea=max(maxArea,height[j--]*w);
    }
    return maxArea;
}

//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Approach- We keep a count of repeated characters by seeing the frequency of the characters. If the frequency of characters is greter than 1, we increase the count. If the 
// while the repeating character count is greater than 0, we move the pointer at the start and shorten the length by eliminating the repeating characters, when the repeating
//character count is again 0, we calculate the maximum length of substring without repeating characters

int lengthOfLongestSubstring(string s) {
    int si=0, ei=0, count=0, len=0;
    int n=s.size();
    if(n<=1) return n;
    vector<int> freq (128,0);
    while(ei<n){
        if(freq[s[ei]]++>0) count++;
        ei++;
        while(count>0){
            if (freq[s[si]]-->1) count--;
            si++;
        }
        len=max(len,ei-si);
    }
    return len;
}

//https://www.lintcode.com/problem/longest-substring-with-at-most-two-distinct-characters/description
//Approach- We keep the count of distinct character by using the freqeuncy of the occuring characters. When the count of distinct characater becomes more than 2, we move the
//si pointer at the start and try to reduce the number of distinct character and after that we update the new length. The longest length encountered is returned.

int lengthOfLongestSubstringTwoDistinct(string &s) {
    int n=s.size();
    if(n<=2) return n;
    int si=0, ei=0, count=0, len=0;
    vector<int> freq(128,0);
    while(ei<n){
        if(freq[s[ei]]==0) count++;
        freq[s[ei]]++;
        ei++;
        while(count>2){
            if(freq[s[si]]==1) count--;
            freq[s[si]]--;
            si++;
        }
        len=max(len,ei-si);
    }
    return len;
}


// January 17

//https://leetcode.com/problems/minimum-window-substring/
//Approach- First we increase the frequency of the characters that appear in string t and then we find the same characters in string s, once we find all characters, we update 
//the length and then try to find even a shorter length by moving the si pointer and updating the length if we find an even shorter length.

string minWindow(string s, string t) {
    int ns=s.size();
    int nt=t.size();

    if(ns<nt) return "";

    vector<int> freq(128,0);
    for(int i=0; i<nt; i++){
        freq[t[i]]++;
    }

    int si=0, ei=0, count=nt, len=1e9, gsi=0;

    while(ei<ns){
        if(freq[s[ei]]>0) count--;
        freq[s[ei]]--;
        ei++;

        while(count==0){
            if(ei-si<len){
                len=ei-si;
                gsi=si;
            }

            if(freq[s[si]]==0) count++;
            freq[s[si]]++;
            si++;
        }
    }

    return len==1e9?"":s.substr(gsi,len);
}

//https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1/#
//Approach- first we find out those characters that appear in the string s and maintain their count. Then we check the string s again to find the smallest substring hahving all
//those characters. We do so by maintaining the frequency and when the we find a string having all characters, we update the length of the string found and try to find even
//a smaller string by moving the si pointer. We keep updating the lenght until we are not done traversing the whole string.

string findSubString(string s)
{
    vector<int> freq(128,-1);
    int n=s.size();
    int count=0;

    for(int i=0; i<n; i++){
        if(freq[s[i]]==-1){
            freq[s[i]]=0;
            count++;
        } 
    }

    int si=0, ei=0, gsi=0, len=1e9;

    while(ei<n){
        if(freq[s[ei]]==0) count--;
        freq[s[ei]]++;
        ei++;

        while(count==0){
            if(ei-si<len){
                len=ei-si;
                gsi=si;
            }

            if(freq[s[si]]==1) count++;
            freq[s[si]]--;
            si++;
        }
    }
    return s.substr(gsi,len);
}

//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/
//Approach- We need to find longest substring with k number of unique characters, so if the lenfth of the string is smaller then k, then it is impossible to find such string.
//We keep the count of occuring characters and once the count reaches k, we update the length and try to find an even longer string by moving the si pointer. If the fianl count
//of unique characters is less than k, then also it is impossible to find the longest string. We return the maximum length found after traversing the string.

int longestKSubstr(string s, int k) {
    int n=s.size();
    int si=0, ei=0, count=0, len=0;
    if(k>n) return -1;
    vector<int> freq(128,0);
    while(ei<n){
        if(freq[s[ei]]==0) count++;
        freq[s[ei]]++;
        ei++;
        while(count>k){
            if(freq[s[si]]==1) count--;
            freq[s[si]]--;
            si++;
        }
        len=max(len,ei-si);
    }
    if(count<k) return -1;
    return len;
}

//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/
//Approach- To find the maximum number of vowels in a string of length k, we keep a count of the maximum vowels found, and once we find a string of length k, we update the 
//maximum vowel count and try to get an even better count by checking the string ahead and updating the vowel count. We return the maximum vowel count once we traverse the whole
//string

bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
    else return false;
}
int maxVowels(string s, int k) {
    int n=s.size(), si=0, ei=0, count=0, countVowel=0, maxCountVowel=0;
    int len=1e9, gsi=0;
    vector<int> freq(128,0);
    while(ei<n){
        if(freq[s[ei]]>=0) count++;
        if(isVowel(s[ei])) countVowel++;
        freq[s[ei]]++;
        ei++;

        while(count==k){
            if(ei-si<len){
                len=ei-si;
                gsi=si;
            }
            maxCountVowel=max(maxCountVowel,countVowel);
            if(freq[s[si]]>0) count--;
            if(isVowel(s[si])) countVowel--;
            freq[s[si]]--;
            si++;
        }
    }
    return maxCountVowel;
}


// January 18

//https://leetcode.com/problems/subarrays-with-k-different-integers/
//Approach- To get subarrays with exactly k different interegers, we get subarrays with atmost k different integers and then subtract the number of subarrays having atmost k-1
//integers from it. To find the subarrays with atmost k different integers, we keep a frequency map and when the elements in map exceed k, we reduce the number of elements by
//moving si pointer. We keep adding the length of ei-si in the answer everytime we move the ei pointer and acquire new element.

int atmostKDistinct(vector<int>& nums, int k){
    unordered_map<int,int> freq;
    int n=nums.size(), si=0, ei=0, ans=0;

    while(ei<n){
        freq[nums[ei]]++;
        ei++;
        while(freq.size()>k){
            freq[nums[si]]--;
            if(freq[nums[si]]==0) freq.erase(nums[si]);
            si++;
        }
        ans+=ei-si;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atmostKDistinct(nums, k)-atmostKDistinct(nums, k-1);
}

//https://leetcode.com/problems/count-number-of-nice-subarrays/
//Approach- To find the nice subarrays with k odd integers in it, we find the number of subarrays having atmost k odd integers and subtract the number of subarrays having atmost
//k-1 integers from it. To find the subarrays with atmost k integers, we keep a count of the odd inteegrs we encounter and once the count goes beyond k, we decrease the length
//of subarray by moving si pointer. We keep on incrementing our answer everytime we move the ei pointer

int atmostKSubarrays(vector<int>& nums, int k){
    int n=nums.size(); int si=0, ei=0, count=0, ans=0;
    while(ei<n){
        if(nums[ei]%2!=0) count++;
        ei++;
        while(count>k){
            if(nums[si]%2!=0) count--;
            si++;
        }
        ans+=ei-si;
    }
    return ans;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return atmostKSubarrays(nums,k)-atmostKSubarrays(nums,k-1);
}

//https://leetcode.com/problems/fruit-into-baskets/
//Approach- We have two fruit baskets, so the number of unique elements that we can have should not exceed 2. When the number of elements goes beyond 2, we shorten the length of
//subarray by moving the si pointer. Whenever we move the ei pointer, we calculate the ans which stores the maximum length of subarray and return that answer.

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int>freq;
    int n=fruits.size(), si=0, ei=0, ans=0;
    while(ei<n){
        freq[fruits[ei]]++;
        ei++;
        while(freq.size()>2){
            freq[fruits[si]]--;
            if(freq[fruits[si]]==0) freq.erase(fruits[si]);
            si++;
        }
        ans=max(ans,ei-si);
    }
    return ans;
}

//https://leetcode.com/problems/binary-subarrays-with-sum/
//Approach- We keep adding the elements to get the sum and whent that sum becomes greater than the goal, we move the si pointer to reduce the sum and make it equal to goal.
//Whenever we move the ei pointer, we increase the count by adding the length ei-si in it. To get the number of subarrays with sum equal to goal, we get the numer of subarrays 
//with sum atmost equal to goal and then subtract the number of subarrays with sum atmoast equal to goal-1 from it.

int atmostSum (vector<int>& nums, int goal){
    int n=nums.size(), si=0, ei=0, sum=0, count=0;
    while(ei<n){
        sum+=nums[ei];
        ei++;
        while(sum>goal){
            sum-=nums[si];
            si++;
        }
        count+=ei-si;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    if(goal!=0){
        return atmostSum(nums,goal)-atmostSum(nums,goal-1);
    }
    else return atmostSum(nums, goal);
}


// January 19

//https://leetcode.com/problems/max-consecutive-ones/
//Approach- Till we encounter a zero, we keep on moving the ei pointer and calculate the maximum length of consecutive ones. When a zero is encountered, we move the si pointer
//so that we can calculate the new length which doesn't include the zero.

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n=nums.size(),si=0, ei=0, len=0;
    while(ei<n){
        if(nums[ei]==0){
            ei++;
            si=ei;
        }
        else ei++;
        len=max(len,ei-si);
    }
    return len;
}

//https://www.lintcode.com/problem/883/description
//Approach- Since we can flip one 0 to 1, we can keep a count of zeroes we encounter, once the count reaches 2, i.e. we have one extra 0, we move the si pointer to eliminate the
//0 and reduce the count back to 1, and we calculate the length of subarray everytime we move ei pointer.

int findMaxConsecutiveOnes(vector<int> &arr) {
    int n = arr.size(), si = 0, ei = 0, count = 0, len = 0;

    while (ei < n) {
        if (arr[ei++] == 0)
            count++;

        while (count == 2)
            if (arr[si++] == 0)
                count--;

        len = max(len, ei - si);
    }
    return len;
}

//https://leetcode.com/problems/max-consecutive-ones-iii/
//Approach- We have k 0s flipped to 1 and inlcuded in our subarray, so till the time we encounter zeroes, we increase the count, but once that count reaches beyond k, we need to
//eliminate the previous 0s to find if we can have even a longer subarray. Everytime we move the ei pointer, we calculate the length of subarray and return the maximum length

int longestOnes(vector<int>& nums, int k) {
    int n=nums.size(), si=0, ei=0, len=0, count=0;
    while(ei<n){
        if(nums[ei++]==0) count++;
        while(count>k){
            if(nums[si++]==0) count--;
        }
        len=max(len,ei-si);
    }
    return len;
}

//https://leetcode.com/problems/subarray-sums-divisible-by-k/
//Approach- We calculate the sum by traversing through the array and then find the remainder and store the number of times we get the same remainder. The subarray between the
//subarray that had reminder r and the next subarray that will have the remainder r is the subarray that is exactly divisble by k. We calcuate our answer by adding the number
//of times we encounter the same remainder from the sum of subarray.

int subarraysDivByK(vector<int>& nums, int k) {
    int ans=0;
    unordered_map<int,int> rem;
    rem[0]=1;
    int sum=0, r=0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        int r=sum%k;
        if(r<0){
            r+=k;
        }
        ans+=rem[r];
        rem[r]++;
    }
    return ans;    
}


// January 20

//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1/
//Approach: We'll store the number of times we encounter the same sum in a hashmap. The subarray, between the subarrays that have the same sum, will have equal number of 0s and 
//1s. To find the subarrays, we add the frequency of the sum and then increase its frequency.

long long int countSubarrWithEqualZeroAndOne(int arr[], int n){
    unordered_map<int,int> freq;
    freq[0]=1;
    int sum=0, ans=0;
    for(int i=0; i<n; i++){
        int val=arr[i];
        sum+=val;
        if(val==0) sum+=-1;
        ans+=freq[sum];
        freq[sum]++;
    }
    return ans;
}

//https://leetcode.com/problems/contiguous-array/
//Approach: The approach is similar to the last one, but here we find the length of the subarray by subtracting the frequency of the sum from the current index. And if we get 
//that sum for the first time, we map it with the index at which we got that sum. In hashmap, 0 is mapped with -1 so that we can calculate the length of array from zero to
//index i when required.

int findMaxLength(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int> map;
    map[0]=-1;
    int len=0, sum=0;
    for(int i=0; i<n; i++){
        int val=nums[i];
        sum+=val;
        if(val==0) sum+=-1;
        if(map.find(sum)!=map.end()) len=max(len,i-map[sum]);
        else map[sum]=i;
    }
    return len;
}

//https://leetcode.com/problems/sliding-window-maximum/
//Approach: We use a max heap to store the array elements and find the maximum in subarrays of k length. Whenever the length goes beyond k, we pop out the max element. The top
//element, which is the largest element in the subarray of length k, is added to the answer vector and that vector is returned.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<vector<int>> pq;
    int n=nums.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
        while(pq.size()!=0 && pq.top()[1]<=i-k) pq.pop();
        pq.push({nums[i],i});
        if(i>=k-1) ans.push_back(pq.top()[0]);
    }
    return ans;
}


// January 22

//https://leetcode.com/problems/maximum-subarray/
//Approach- We add the elements of the subarray till the time that subarray sum becomes less than the next element which has to be added. In that case, the next element starts 
//its own subarrray and we store the sum of previous subarray in the maxSum variable. Whenever a new subarray is started, we update the maximum sum and return the overall maxSum

int maxSubArray(vector<int>& nums) {
    int maxSumSoFar=0, maxSum=-1e9;
    for(int i=0; i<nums.size(); i++){
        maxSumSoFar+=nums[i];
        if(maxSumSoFar<nums[i]) maxSumSoFar=nums[i];
        maxSum=max(maxSumSoFar,maxSum);
    }
    return maxSum;
}

//https://leetcode.com/problems/k-concatenation-maximum-sum/
//Approach- First we write Kadane's algorithm and then write a function to concatenate the given array and make an array of twice the size of given array. Then we check that if
//k=1, then we simply apply Kadanes's algo. The sum of the array that we have found earlier, if that sum is less than zero, then we know that sum of subarray of the first and
//last subarrays out of the K subarrays will give then maximum sum. And if sum>0, then we find the maximum sum by finding maximum subarray of first and last arrays and adding 
//the (k-2)subarray sum along with it.

long long mod=1e9+7;
int Kadanes(vector<int>& arr){
    long long maxSumSoFar=0;
    long long maxSum=0;
    for(int i=0; i<arr.size(); i++){
        maxSumSoFar+=arr[i];
        if(maxSumSoFar<arr[i]) maxSumSoFar=arr[i];
        maxSum=max(maxSum,maxSumSoFar);
    }
    return maxSum%mod;
}

int Kadanes2(vector<int>&arr){
    vector<int>narr(arr.size()*2);
    for(int i=0; i<arr.size(); i++){
        narr[i]=arr[i];
    }
    for(int i=0; i<arr.size(); i++){
        narr[i+arr.size()]=arr[i];
    }
    int maxsum=Kadanes(narr);
    return maxsum%mod;
}
int kConcatenationMaxSum(vector<int>& arr, int k) {
    long long sum=0;
    int result=0;
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
    }
    sum=sum%mod;
    if(k==1) 
        result=Kadanes(arr);
    else if(sum<0) 
        result=Kadanes2(arr);
    else 
        result=Kadanes2(arr)+(((k-2)*sum)%mod);

    return result%mod;
}

//https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
//Approach- We make a vector of size of the row whenever we move the i pointer, in that vector we store the elements of the row and aplly kadane's algo to find max sum. Then we
//add the elements in the vector which belong to the row below it and again apply kadane's algo. By doing this, we find the maximum sum and we check that what all elements are
//covered to make that maximum sum and that matrix is the one with the maximum sum.

int Kadanes(vector<int> arr){
    int maxSum=-1e9, maxSumSoFar=0;
    for(int i=0; i<arr.size(); i++){
        maxSumSoFar+=arr[i];
        if(maxSumSoFar<arr[i]) maxSumSoFar=arr[i];
        maxSum=max(maxSum,maxSumSoFar);
    }
    return maxSum;
}
int maximumSumRectangle(int R, int C, vector<vector<int>> a) {
    int ans=-1e9;
    for(int i=0; i<a.size(); i++){
        vector<int> v(a[0].size(),0);
        for(int j=i;j<a.size();j++){
            for(int k=0;k<a[0].size();k++)
                v[k]+=a[j][k];
            ans=max(ans,Kadanes(v));
        }
    }
    return ans;
}

//https://leetcode.com/problems/rabbits-in-forest/
//Approach- We make a hashamp which will store the number of rabits of a given color. When we first encounter a rabit of a new color, we know that there is x more rabits of the
//same color, so we add x+1 to our answer and increase the count in hashmap. When the count goes beyond a given x, we rest the hashmap count to zero to accomodate all the rabits

int numRabbits(vector<int>& answers) {
    unordered_map <int,int> map;

    int ans = 0;
    for (int ele : answers) {
        if (map[ele] == 0)
            ans += (ele + 1);
        map[ele]++;

        if (map[ele] == ele + 1)
            map[ele] = 0;
    }

    return ans;
}

//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
//Approach- The approach is quite similar to maximum sum matrix in 2D array, but here we count the frequency of sum-target elements and give that count for the vector formed
//everytime we move the i pointer to cover the whole vector.

int countSubarraysGivenTarget(vector<int> arr, int tar) {
    unordered_map<int,int> map;
    map[0]=1;
    int count = 0, sum = 0;
    for (int ele : arr) {
        sum += ele;
        count += map[sum-tar];
        map[sum]++;
    }

    return count;
}
int numSubmatrixSumTarget(vector<vector<int>>& arr, int tar) {
    int n = arr.size(), m = arr[0].size();
    int count = 0;

    for (int fixedRow = 0; fixedRow < n; fixedRow++) {

        vector<int>prefixColArray(m,0);
        for (int row = fixedRow; row < n; row++) {
            for (int col = 0; col < m; col++)
                prefixColArray[col] += arr[row][col];

            count += countSubarraysGivenTarget(prefixColArray, tar);
        }
    }

    return count;
}


// January 24

//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/submissions/
//Approach- Here we modify the kadane's algo to check that the sum should be less than K. Other than that, the question is similar to maximum sum matrix in 2D array

int kadane(vector<int>arr, int k){
    int maxSum=-1e9;
    for(int i=0; i<arr.size(); i++){
        int maxSumSoFar=0;
        for(int j=i; j<arr.size(); j++){
            maxSumSoFar+=arr[j];
            if(maxSumSoFar<=k && maxSumSoFar>maxSum) maxSum = maxSumSoFar;
        } 
    }
    return maxSum;
}

int maxSumSubmatrix(vector<vector<int>>&arr, int k) {
    int n = arr.size(), m = arr[0].size();
    int ans = -1e9;

    for (int fixedRow = 0; fixedRow < n; fixedRow++) {

        vector<int>prefixColArray(m,0);
        for (int row = fixedRow; row < n; row++) {
            for (int col = 0; col < m; col++)
                prefixColArray[col] += arr[row][col];

            ans = max(ans,kadane(prefixColArray,k));  
        }
    }

    return ans;
}
