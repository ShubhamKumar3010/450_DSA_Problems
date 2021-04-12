#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>
#include <climits>
using namespace std;

void reverseArray();

void max_min_elementOfArray();

void kthSmallestElement();

void sort_0_1_2();

void negative_element_to_One_side_of_array();

void union_of_two_array();

void intersection_of_two_sorted_array();

int kadane_algorithm(int n, int a[]);

int minimize_the_height_2(int n, int a[], int k);

int minJumps(int arr[], int n);

int findDuplicate(vector<int> &nums);

void merge_without_extra_space(int *arr1, int *arr2, int n, int m);

int nextGap(int gap);

int kadane_algorithm_contiguous_sub_array_max_sum(int n, int a[]);

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals);

void nextPermutation(vector<int> &nums);

long long int inversionCount(long long arr[], long long N);

long long int _mergeSort(long long arr[], int temp[], int left, int right);

long long int merge(long long arr[], int temp[], int left, int mid, int right);

int maxProfit(vector<int> &prices);

int getPairsCount(int arr[], int n, int k);

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3);

void rearrangeArray(int a[], int n);

bool subArrayExists(int a[], int n);

long long maxProduct(int *arr, int n);

int findLongestConseqSubseq(int arr[], int N);

int moreThanNdK(int a[], int n, int k);

string isSubset(int a1[], int a2[], int n, int m);

bool find3Numbers(int A[], int n, int X);

int trappingWater(int arr[], int n);

long long findMinDiff(vector<long long> a, long long n, long long m);

int minSubArray_with_some_greater_than_x(int arr[], int n, int x);

void threeWayPartition(vector<int> &array, int a, int b);

int find_median(vector<int> v);

int main()
{
    vector<int> v = {1, 2, 3, 3, 4};
    threeWayPartition(v, 1, 2);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}

int find_median(vector<int> v)
{
    // Code here.
    sort(v.begin(), v.end());
    int size = v.size();
    if (size & 1)
    {
        return v[size / 2];
    }
    else
    {
        return (v[size / 2] + v[(size / 2) - 1]) / 2;
    }
}

void threeWayPartition(vector<int> &array, int a, int b)
{
    // code here
    int n = array.size();
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; i++)
    {
        if (array[i] < a)
        {
            swap(array[i], array[j]);
            j++;
            i++;
        }
        else if (array[i] > b)
        {
            arr[k]
        }
    }
}
int minSubArray_with_some_greater_than_x(int arr[], int n, int x)
{
    int current_sum = 0, min_length = n + 1;
    int start = 0, end = 0;
    while (end < n)
    {
        //keep adding while sum is smaller than x
        while (current_sum <= x && end < n)
        {
            current_sum += arr[end++];
        }
        //if current sum increases.
        while (current_sum > x && start < n)
        {
            //update min length.
            if ((end - start) < min_length)
            {
                min_length = end - start;
            }
            //remove starting element.
            current_sum -= arr[start++];
        }
    }
    return min_length;
}

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    long long ans = INT_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i + m - 1 < n; i++)
    {
        int d = a[i + m - 1] - a[i];
        if (d < ans)
        {
            ans = d;
        }
    }
    return ans;
}

int trappingWater(int arr[], int n)
{
    // Code here
    int left_max[n], right_max[n];
    //filling left max for each index.
    left_max[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > left_max[i - 1])
        {
            left_max[i] = arr[i];
        }
        else
        {
            left_max[i] = left_max[i - 1];
        }
    }
    //filling right max for each index.
    right_max[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > right_max[i + 1])
        {
            right_max[i] = arr[i];
        }
        else
        {
            right_max[i] = right_max[i + 1];
        }
    }
    //Now we can take min(left_max[i],right_max[i])-arr[i]. By this we can get storage of every index.
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left_max[i], right_max[i]) - arr[i];
    }
    return ans;
}

bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == X)
            {
                return 1;
            }
            else if (A[i] + A[l] + A[r] < X)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return false;
}

string isSubset(int a1[], int a2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a1[i]);
    }
    int size = s.size();
    for (int i = 0; i < m; i++)
    {
        s.insert(a2[i]);
    }
    return s.size() == size ? "Yes" : "No";
}

int moreThanNdK(int a[], int n, int k)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    vector<int> v;
    for (auto i : m)
    {
        if (i.second > (n / k))
        {
            cout << i.first << endl;
        }
    }
}

int findLongestConseqSubseq(int arr[], int N)
{
    //Your code here
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }
    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        int temp = arr[i] - 1;
        if (s.find(temp) != s.end())
        {
            continue;
        }
        else
        {
            int count = 1;
            int t = arr[i] + 1;
            while (s.find(t) != s.end())
            {
                count++;
                t++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
    return 0;
}

long long maxProduct(int *arr, int n)
{
    long long maxProduct = arr[0];
    long long minProduct = arr[0];
    long long ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        long long choice1 = arr[i];
        long long choice2 = maxProduct * arr[i];
        long long choice3 = minProduct * arr[i];
        maxProduct = max(choice1, max(choice2, choice3));
        minProduct = min(choice1, min(choice2, choice3));
        ans = max(ans, maxProduct);
    }
    return ans;
}

bool subArrayExists(int a[], int n)
{
    //Your code here
    set<int> s;
    int sum = 0;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        s.insert(sum);
        sum += a[i];
        if (s.find(sum) != s.end())
        {
            found = true;
            break;
        }
    }
    return found;
}
void rearrangeArray(int a[], int n)
{
    int i = 0, j = n - 1;
    //arranging all positive one side and all negative other side.
    while (i <= j)
    {
        if ((a[i] < 0) && (a[j] > 0))
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        else if (a[i] > 0)
        {
            i++;
        }
        else if (a[j] < 0)
        {
            j--;
        }
    }
    //i==0 then all -ve no.
    //i==n then all is +ve no.
    if ((i == 0) || (i == n))
    {
        //print
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        //we need to swap
        int k = 0;
        while ((k < n) && (i < n))
        {
            swap(a[k], a[i]);
            k += 2;
            i++;
        }
        //print
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
}
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    int i = 0, j = 0, k = 0;
    vector<int> v1;
    set<int> v;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            v.insert(A[i]);
            i++, j++, k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    for (auto item : v)
    {
        v1.push_back(item);
    }
    return v1;
}
int getPairsCount(int arr[], int n, int k)
{
    // code here
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int twice_pairs = 0;
    for (int i = 0; i < n; i++)
    {
        twice_pairs += m[k - arr[i]];
        if (arr[i] == (k - arr[i]))
        {
            twice_pairs--;
        }
    }
    return twice_pairs / 2;
}
int maxProfit(vector<int> &prices)
{
    int minValue = INT_MAX;
    int maxProf = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minValue = min(minValue, prices[i]);
        maxProf = max(maxProf, prices[i] - minValue);
    }
    return maxProf;
}

long long int merge(long long arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    long long int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            //this is the part when two array are merged we count inversion
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long int _mergeSort(long long arr[], int temp[], int left, int right)
{
    int mid;
    long long int inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    int temp[N];
    return _mergeSort(arr, temp, 0, N - 1);
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int index, index2;
    bool possible = false;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            possible = true;
            index = i;
            break;
        }
    }
    if (!possible)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (int i = n - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                index2 = i;
                break;
            }
        }
        swap(nums[index], nums[index2]);
        reverse(nums.begin() + index + 1, nums.end());
    }
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> output;
    //if array is empty then return
    if (intervals.empty())
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= tempInterval[1])
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else
        {
            output.push_back(tempInterval);
            tempInterval = it;
        }
    }
    output.push_back(tempInterval);
    return output;
}

int kadane_algorithm_contiguous_sub_array_max_sum(int n, int a[])
{
    int current_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current_sum += a[i];
        if (current_sum < 0)
        {
            current_sum = 0;
        }
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

//next gap is used in merge_without_extra_space for checking up from which indices to start the check.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge_without_extra_space(int *arr1, int *arr2, int n, int m)
{
    // code here
    int gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        int i = 0, j = 0;
        //for comparing element in first array.
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
            {
                swap(arr1[i], arr1[i + gap]);
            }
        }

        //for comparing element in both the array.
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }

        //for comparing element in second array.
        if (j < m)
        {
            for (j = 0; j + gap; j++)
            {
                if (arr2[j] > arr2[j + gap])
                {
                    swap(arr2[j], arr2[j + gap]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int findDuplicate(vector<int> &nums)
{
    int size = nums.size();
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++)
    {
        v[nums[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (v[i] >= 2)
        {
            return i;
        }
    }
    return 0;
}

int minJumps(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        int max = 0;
        for (int j = i; j <= arr[i]; j++)
        {
            if (j >= n)
            {
                break;
            }
            max = std::max(max, arr[j]);
        }
        i += max - 1;
    }
    return count;
}

int minimize_the_height_2(int n, int a[], int k)
{
    sort(a, a + n);
    //this can be one possibility.
    int ans = a[n - 1] - a[0];
    int mx, mn;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= k)
        {
            mx = max(a[n - 1] - k, a[i - 1] + k);
            mn = min(a[0] + k, a[i] - k);
            ans = min(ans, mx - mn);
        }
    }
    return ans;
}

int kadane_algorithm(int n, int a[])
{
    int current_sum = 0;
    int min_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current_sum += a[i];
        if (current_sum < 0)
        {
            current_sum = 0;
        }
        min_so_far = max(min_so_far, current_sum);
    }
    return min_so_far;
}

void intersection_of_two_sorted_array()
{
    int m;
    int n;
    cin >> m >> n;
    int a[m], b[n];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    set<int> s1, s2;
    for (int i = 0; i < m; i++)
    {
        s1.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s2.insert(b[i]);
    }
    vector<int> intersection_output;
    for (int it : s1)
    {
        if (s2.find(it) != s2.end())
        {
            intersection_output.push_back(it);
        }
    }
    for (int it : intersection_output)
    {
        cout << it << " ";
    }
}

void union_of_two_array()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        int y;
        cin >> x >> y;
        int a[x], b[y];
        set<int> s;
        for (int i = 0; i < x; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < y; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < x; i++)
        {
            s.insert(a[i]);
        }
        for (int i = 0; i < y; i++)
        {
            s.insert(b[i]);
        }
        cout << s.size() << endl;
    }
}

void negative_element_to_One_side_of_array()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (i != j)
            {
                swap(a[i], a[j]);
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void sort_0_1_2()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = j + 1; i < n; i++)
            {
                if (a[j] > a[i])
                {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void kthSmallestElement()
{
    int n;
    cout << "Enter size of array";
    cin >> n;
    int a[n];
    cout << "Enter elements in array";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cout << "Enter the kth value to get kth smallest element:";
    cin >> k;
    //Sort the array using sort algorithm function from algorithm header.
    sort(a, a + n);
    cout << "Smallest kth value is:" << a[k - 1];
}

void max_min_elementOfArray()
{
    int n;
    cout << "Enter size of array";
    cin >> n;
    int a[n];
    cout << "Enter elements in array";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> pair;
    pair.first = a[0];
    pair.second = a[0];
    for (int i = 1; i < n; i++)
    {
        if (pair.first > a[i])
        {
            pair.first = a[i];
        }
        if (pair.second < a[i])
        {
            pair.second = a[i];
        }
    }
    cout << "Min and Max of Array:" << pair.first << " " << pair.second << endl;
}

void reverseArray()
{
    int n;
    cout << "Enter size of array";
    cin >> n;
    int a[n];
    cout << "Enter elements in array";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Element before reverse:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int i = 0, j = n - 1;
    while (i < n / 2 && j < n)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    cout << "Element after reverse:" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
    cout << endl;
}
