#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

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

void merge(int arr1[], int arr2[], int n, int m);

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3);

int main() {
    int a[] = {1, 5, 10, 20, 40, 80};
    int b[] = {6, 7, 20, 80, 100};
    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = 6, n2 = 5, n3 = 8;
    vector<int> v = commonElements(a, b, c, n1, n2, n3);
    for (auto i:v) {
        cout << i << " ";
    }

}

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    //code here.
    int i = 0, j = 0, k = 0;
    vector<int> v1;
    set<int> v;
    while (i < n1 && j < n2 && k < n3) {
        if (A[i] == B[j] && B[j] == C[k]) {
            v.insert(A[i]);
            i++, j++, k++;
        } else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }
    for (auto item:v) {
        v1.push_back(item);
    }
    return v1;
}

void merge(int arr1[], int arr2[], int n, int m) {
    // code here
}

int findDuplicate(vector<int> &nums) {
    int size = nums.size();
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++) {
        v[nums[i]]++;
    }
    for (int i = 0; i < size; i++) {
        if (v[i] >= 2) {
            return i;
        }
    }
    return 0;
}

int minJumps(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        int max = 0;
        for (int j = i; j <= arr[i]; j++) {
            if (j >= n) {
                break;
            }
            max = std::max(max, arr[j]);
        }
        i += max - 1;
    }
    return count;
}

int minimize_the_height_2(int n, int a[], int k) {
    sort(a, a + n);
    //this can be one possibility.
    int ans = a[n - 1] - a[0];
    int mx, mn;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            mx = max(a[n - 1] - k, a[i - 1] + k);
            mn = min(a[0] + k, a[i] - k);
            ans = min(ans, mx - mn);
        }
    }
    return ans;
}

int kadane_algorithm(int n, int a[]) {
    int current_sum = 0;
    int max_so_far = INT_MIN;
    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        if (current_sum < 0) {
            current_sum = 0;
        }
        max_so_far = max(max_so_far, current_sum);
    }
}

void intersection_of_two_sorted_array() {
    int m;
    int n;
    cin >> m >> n;
    int a[m], b[n];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    set<int> s1, s2;
    for (int i = 0; i < m; i++) {
        s1.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        s2.insert(b[i]);
    }
    vector<int> intersection_output;
    for (int it : s1) {
        if (s2.find(it) != s2.end()) {
            intersection_output.push_back(it);
        }
    }
    for (int it: intersection_output) {
        cout << it << " ";
    }
}

void union_of_two_array() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        int y;
        cin >> x >> y;
        int a[x], b[y];
        set<int> s;
        for (int i = 0; i < x; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < y; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < x; i++) {
            s.insert(a[i]);
        }
        for (int i = 0; i < y; i++) {
            s.insert(b[i]);
        }
        cout << s.size() << endl;
    }
}

void negative_element_to_One_side_of_array() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (i != j) {
                swap(a[i], a[j]);
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void sort_0_1_2() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                if (a[j] > a[i]) {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void kthSmallestElement() {
    int n;
    cout << "Enter size of array";
    cin >> n;
    int a[n];
    cout << "Enter elements in array";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cout << "Enter the kth value to get kth smallest element:";
    cin >> k;
    //Sort the array using sort algorithm function from algorithm header.
    sort(a, a + n);
    cout << "Smallest kth value is:" << a[k - 1];
}

void max_min_elementOfArray() {
    int n;
    cout << "Enter size of array";
    cin >> n;
    int a[n];
    cout << "Enter elements in array";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int, int> pair;
    pair.first = a[0];
    pair.second = a[0];
    for (int i = 1; i < n; i++) {
        if (pair.first > a[i]) {
            pair.first = a[i];
        }
        if (pair.second < a[i]) {
            pair.second = a[i];
        }
    }
    cout << "Min and Max of Array:" << pair.first << " " << pair.second << endl;
}

void reverseArray() {
    int n;
    cout << "Enter size of array";
    cin >> n;
    int a[n];
    cout << "Enter elements in array";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Element before reverse:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int i = 0, j = n - 1;
    while (i < n / 2 && j < n) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    cout << "Element after reverse:" << endl;
    for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
    }
    cout << endl;
}
