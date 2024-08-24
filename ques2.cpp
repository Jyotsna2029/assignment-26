// Reverse Pairs (Leetcode Problem) : Given an integer array nums, return the number of reverse
// pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
#include<iostream>
#include<vector>
using namespace std;
int reversepairs(vector<int>&a,vector<int>&b){
    int c = 0;
    int i = 0, j = 0;
    while(i<a.size() && j<b.size()){
        if((long long)a[i]>(long long)(2*b[j])) {
            c +=(a.size()-i); 
            j++;
        }
        else i++;
    }
    return c;
}
void merge(vector<int>&a,vector<int>&b,vector<int>&nums){
    int i = 0; 
    int j = 0;
    int k = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) {
            nums[k] = a[i];
            i++;
        }
        else{
            nums[k] = b[j];
            j++;
        }
        k++;
    }
    if(i==a.size()) {
        while(j<b.size()){
            nums[k++] = b[j++];
        }
    }
    if(j==b.size()) {
        while(i<a.size()){
            nums[k++] = a[i++];
        }
    }
}
int mergeSort(vector<int>&nums){
    int count = 0;
    int n = nums.size();
    if(n==1) return 0;
    // make 2 arrays
    int n1 = n/2, n2 = n-n/2;
    vector<int>a(n1), b(n2);
    for(int i=0; i<n1; i++){
        a[i] = nums[i];
    }
    for(int i = 0 ; i<n2; i++){
        b[i] = nums[i+n1];
    }
    // recursion
    count += mergeSort(a);
    count += mergeSort(b);
    // count inversion
    count += reversepairs(a,b);
    // merge
    merge(a,b,nums);
    a.clear();
    b.clear();

    return count;
}
int main(){
    int arr[] ={2,4,3,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> res(arr, arr+n);
    for(int i = 0 ; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    cout<<"The total number of reverse paire are: "<<mergeSort(res);
}