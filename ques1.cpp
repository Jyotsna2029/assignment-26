// Given an array of integers, sort it in descending order using merge sort algorithm.
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a, vector<int>&b, vector<int> &v){
    int i = 0; // pointer for arr a
    int j = 0; // pointer for arr b
    int k = 0; // pointer for arr v
    while(i<a.size() && j<b.size()){
        if(a[i]>=b[j]){
            v[k] = a[i];
            k++;
            i++;
        }
        else v[k++] = b[j++]; // OR // v[k] = b[j];  // j++;// k++;  
    }
    if(i==a.size()){
        while(j<b.size()) v[k++] = b[j++];  
    }
    if(j==b.size()){
        while(i<a.size()) v[k++] = a[i++];  
    }
}
void mergeSort(vector<int>&v){
    int n = v.size();
    //  base case
    if(n==1) return;

    int n1 = n/2, n2 = n-n/2;
    vector<int>a(n1);    // vector<int>a(n1), b(n2);
    vector<int>b(n2);

    //copy paste;
    for(int i=0; i<n1;i++){
        a[i] = v[i];
    }
    for(int i = 0;i<n2;i++){
        b[i] = v[i+n1];
    }

    // magic
    mergeSort(a);
    mergeSort(b);

    // merge
    merge(a,b,v);
    // after merging delete the formed array
    a.clear();
    b.clear();
}

int main(){
    int arr[] = {5,1,3,0,4,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n); // make a copy of array in vector
    for(int i = 0; i <v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

}