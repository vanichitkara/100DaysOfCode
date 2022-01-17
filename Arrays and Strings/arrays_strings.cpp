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
