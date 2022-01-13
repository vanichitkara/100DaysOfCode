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
