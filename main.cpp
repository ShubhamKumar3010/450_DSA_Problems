#include <iostream>
#include <algorithm>
using namespace std;
void reverseArray();
void max_min_elementOfArray();
void kthSmallestElement();
int main() {
    kthSmallestElement();
    return 0;
}
void kthSmallestElement(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    cout<<"Enter elements in array";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cout<<"Enter the kth value to get kth smallest element:";
    cin>>k;
    //Sort the array using sort algorithm function from algorithm header.
    sort(a,a+n);
    cout<<"Smallest kth value is:"<<a[k-1];
}
void max_min_elementOfArray(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    cout<<"Enter elements in array";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pair<int,int> pair;
    pair.first=a[0];
    pair.second=a[0];
    for(int i = 1;i<n;i++){
        if(pair.first>a[i]){
            pair.first = a[i];
        }
        if(pair.second<a[i]){
            pair.second = a[i];
        }
    }
    cout<<"Min and Max of Array:"<<pair.first<<" "<<pair.second<<endl;
}
void reverseArray(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    cout<<"Enter elements in array";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Element before reverse:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int i = 0, j = n-1;
    while(i<n/2 && j<n){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    cout<<"Element after reverse:"<<endl;
    for(int k=0;k<n;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
}
