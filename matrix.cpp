#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c);

bool searchMatrix(vector<vector<int>> &matrix, int target);

int median_in_row_wise_sorted_matrix(vector<vector<int>> &matrix, int r, int c);

int rowWithMax1s(vector<vector<int>> arr, int n, int m);

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat);

void rotate90(vector<vector<int>> &m);

void printCommonElements(int mat[4][5],int M,int N);

int main()
{
    
}

void printCommonElements(int mat[4][5],int M,int N)
{
    //code here
    unordered_map<int,int> m;
    for(int i=0;i<N;i++){
        m[mat[0][i]]=1;
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(m[mat[i][j]] == i){
                m[mat[i][j]]++;
                //If this is last row
                if(i==M-1 && m[mat[i][j]]==M){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    //we will use max heap priority_queue is default max heap in c++.
    priority_queue<int,vector<int>> maxHeap;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maxHeap.size()<k){
                maxHeap.push(mat[i][j]);
            }else{
                if(mat[i][j]<maxHeap.top()){
                    maxHeap.pop();
                    maxHeap.push(mat[i][j]);
                }
            }
        }
    }
    return maxHeap.top();
}
void rotate90(vector<vector<int>> &m){
    int n = m.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(m[i][j],m[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(m[i].begin(),m[i].end());
    }
}

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    // code here
    int size = N * N;
    int a[size];
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[k++] = Mat[i][j];
        }
    }
    k = 0;
    sort(a, a + size);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = a[k++];
        }
    }
    return Mat;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 1)
            {
                return j;
            }
        }
    }
    return -1;
}

int median_in_row_wise_sorted_matrix(vector<vector<int>> &matrix, int r, int c)
{
    //max and min of row wise sorted matrix
    int min=matrix[0][0],max=matrix[0][0],n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]<min){
            min=matrix[i][0];
        }
        if(matrix[i][m-1]>max){
            max=matrix[i][m-1];
        }
    } 
    //desired element which we have to find.
    int desired_element = (1+n*m)/2;
    while(min<max){
        int mid = (max+min)/2;
        int count = 0;
        for(int i=0;i<n;i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        if(count<desired_element){
            min = mid+1;
        }else{
            max = mid;
        }
    }
    return min;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    bool found = false;
    int c = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++)
    {
        if (target <= matrix[i][c - 1])
        {
            found = binary_search(matrix[i].begin(), matrix[i].end(), target);
            break;
        }
    }
    return found;
}

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    vector<int> out;
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    //we will one variable direction to maintain the traversal.
    int dir = 1;
    //1-for left-right
    //2-for top-bottom
    //3-for righ-left
    //4-for bottom-up
    while (top <= bottom && left <= right)
    {
        if (dir == 1)
        {
            for (int i = left; i <= right; i++)
            {
                out.push_back(matrix[top][i]);
            }
            top++;
            dir = 2;
        }
        else if (dir == 2)
        {
            for (int i = top; i <= bottom; i++)
            {
                out.push_back(matrix[i][right]);
            }
            right--;
            dir = 3;
        }
        else if (dir == 3)
        {
            for (int i = right; i >= left; i--)
            {
                out.push_back(matrix[bottom][i]);
            }
            bottom--;
            dir = 4;
        }
        else if (dir == 4)
        {
            for (int i = bottom; i >= top; i--)
            {
                out.push_back(matrix[i][left]);
            }
            left++;
            dir = 1;
        }
    }
    return out;
}