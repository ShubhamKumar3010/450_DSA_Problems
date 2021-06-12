#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> find(int arr[], int n, int x);
vector<int> valueEqualToIndex(int arr[], int n);
int search(vector<int> &nums, int target);
int binarySearch(vector<int> nums, int s, int e, int k);
int countSquares(int N);
int middle(int A, int B, int C);
int *findTwoElement(int *arr, int n);
int majorityElement(int a[], int size);
int find_in_adjacent_differ_k(int a[], int n, int k, int x);
bool findPair(int arr[], int size, int n);
vector<vector<int>> fourSum(vector<int> &arr, int k);
ll FindMaxSumNonAdjacent(ll arr[], ll n);
ll solve(ll i, ll a[],ll dp[]);
ll countTriplets(ll arr[], int n, ll sum);
int main()
{
    int arr[] = {90, 70, 20, 80, 50};
    cout << findPair(arr, 5, 45);
    return 0;
}
long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    long long ans = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {
            long long t = arr[i] + arr[start] + arr[end];
            if (t >= sum)
            {
                end--;
            }
            else
            {
                ans += (end - start);
                start++;
            }
        }
    }
    return ans;
}
ll solve(ll i, ll a[],ll dp[])
{
    //Solved using DP
    if (i <= -1)
    {
        return 0;
    }
    //memoisation
    if (dp[i] != -1)
    {
        return dp[i];
    }
    ll op1 = a[i] + solve(i - 2, a,dp);
    ll op2 = solve(i - 1, a,dp);
    return dp[i] = max(op1, op2);
}
ll FindMaxSumNonAdjacent(ll arr[], ll n)
{
    //Using Dynamic Programming.
    ll dp[10001];
    dp[n];
    memset(dp, -1, sizeof(dp));
    ll ans = solve(n - 1, arr,dp);
    return ans;
}
vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    //Given an array of integers and another number.
    // Find all the unique quadruple from the given array that sums up to the given number.

    //we can give output also but repititon of quadraples are coming so to avoid it we put it on set.
    set<vector<int>> output;
    vector<vector<int>> uniqueOutput;
    sort(arr.begin(), arr.end());
    int size = arr.size();

    //we will fix two values from left side and find two next to them
    //if sum == k we will add all 4 element to the output.
    for (int i = 0; i < size - 3; i++)
    {
        for (int j = i + 1; j < size - 2; j++)
        {
            int targetSum = k - (arr[i] + arr[j]);
            int start = j + 1;
            int end = size - 1;
            while (start < end)
            {
                int t = arr[start] + arr[end];
                if (t == targetSum)
                {
                    vector<int> v = {arr[i], arr[j], arr[start], arr[end]};
                    output.insert(v);
                    start++;
                    end--;
                }
                else if (t < targetSum)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
    for (auto i : output)
    {
        uniqueOutput.push_back(i);
    }
    return uniqueOutput;
}
bool findPair(int arr[], int size, int n)
{
    set<int> s;
    for (int i = 0; i < size; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        if (s.find(arr[i] + n) != s.end())
        {
            return 1;
        }
    }
    return -1;
}
int find_in_adjacent_differ_k(int a[], int n, int k, int x)
{
    //n size of array, k is difference bw neighbours, x is the key to be searched.
    int i = 0;
    while (i < n)
    {
        if (a[i] == x)
        {
            return i;
        }
        //else make jump i by using k logic
        i = i + max(1, abs(a[i] - x) / k);
    }
}
int majorityElement(int a[], int size)
{
    // your code here
    int majorityElement = a[0];
    int count = 1;
    for (int i = 1; i < size; i++)
    {
        if (majorityElement == a[i])
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                count = 1;
                majorityElement = a[i];
            }
        }
    }
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == majorityElement)
        {
            count++;
        }
    }
    if (count > (size / 2))
    {
        return majorityElement;
    }
    else
    {
        return -1;
    }
}
int *findTwoElement(int *arr, int n)
{
    // code here
    bool b[n] = {false};
    int *out = new int[2];
    for (int i = 0; i < n; i++)
    {
        if (b[arr[i] - 1] == true)
        {
            out[0] = arr[i];
            cout << "Repeating no. is: " << arr[i] << endl;
        }
        b[arr[i] - 1] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == false)
        {
            out[1] = i + 1;
            cout << "Missing no. is: " << i + 1 << endl;
            break;
        }
    }
    return out;
}
int middle(int A, int B, int C)
{
    //code here//Position this line where user code will be pasted.
    if (A > B && B > C)
    {
        return B;
    }
    if (B > A && A > C)
    {
        return A;
    }
    if (B > C && C > A)
    {
        return C;
    }
}
int countSquares(int N)
{
    int a = sqrt(N);
    if (a * a == N)
    {
        return a - 1;
    }
    else
    {
        return a;
    }
}
int binarySearch(vector<int> nums, int s, int e, int k)
{
    if (s > e)
    {
        return -1;
    }
    int mid = (s + e) / 2;
    if (nums[mid] == k)
    {
        return mid;
    }
    if (nums[mid] >= nums[s])
    {
        if (k >= nums[s] && k < nums[mid])
            return binarySearch(nums, s, mid - 1, k);
        else
            return binarySearch(nums, mid + 1, e, k);
    }
    if (k >= nums[mid] && k <= nums[e])
    {
        return binarySearch(nums, mid + 1, e, k);
    }
    else
    {
        return binarySearch(nums, s, mid - 1, k);
    }
}
int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}
vector<int> valueEqualToIndex(int arr[], int n)
{
    // code here
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        int temp = i + 1;
        if (arr[i] == temp)
        {
            output.push_back(temp);
        }
    }
    return output;
}
vector<int> find(int arr[], int n, int x)
{
    // code here
    vector<int> out;
    int low = 0, high = n - 1;
    int firstOccurence = -1, lastOccurence = -1;
    while (low <= high)
    {
        int mid = low + (high - low / 2);
        if (arr[mid] == x)
        {
            firstOccurence = mid;
            high = mid - 1;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low / 2);
        if (arr[mid] == x)
        {
            lastOccurence = mid;
            low = mid + 1;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    out.push_back(firstOccurence);
    out.push_back(lastOccurence);
}