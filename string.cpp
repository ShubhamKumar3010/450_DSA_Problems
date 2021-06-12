#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s);

int isPlaindrome(char S[]);

void duplicateChar(char s[]);

bool areRotations(string str1, string str2);

bool shuffleCheck(string first, string second, string result);

string countAndSay(int n);

string longestPalindrome (string s);

void print_subsequence(string input,string output);

int maxSubStr(string str, int n);

string printSequence(string input);

int main()
{  
    int a[]={1,2,3,4,5};
    cout<<binary_search(a,a+5,4);
}

string printSequence(string input)
{
    //print mobile keypad sequence
    //Input : XYZ
    //Output : 999999999
    string keypadAlpha_to_num[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            output += "0";
        }
        else
        {
            //logic to calculate the index
            int position = input[i] - 'A';
            output += keypadAlpha_to_num[position];
        }
    }
    return output;
}

int maxSubStr(string str, int n)
{
    //Split the binary string into substrings with equal number of 0s and 1s.
    //Eg : "0100110101"
    //Output : 4
    //The required substrings are “01”, “0011”, “01” and “01”.
    int count0 = 0, count1 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        str[i] == '0' ? count0++ : count1++;
        if (count1 == count0)
        {
            ans++;
        }
    }
    return ans;
}

void print_subsequence(string input,string output)
{
    //base case
    if(input.length()==0){
            cout<<output<<endl;
        return;
    }

    //recursive case
    //input.substr(1) this means we remove we start the string from from 1index.
    print_subsequence(input.substr(1),output);
    print_subsequence(input.substr(1),output+input[0]);
}

string longestPalindrome (string s){

    int n = s.length();

    //create n*n table to store the check of palindrome.
    bool table[n][n];

    //initialise with 0.
    memset(table,0,sizeof(table));

    int maxLength = 1;

    //now initialise diagonal and and its next element because it will help in covering whole matrix.

    //with this we will calculate 1,2 size palindrome.
    for(int i=0;i<n;i++){
        table[i][i] = true;
    }
    int start = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    //now for 3 size palindrome.
    //k is length of substring.
    for(int k = 3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if(table[i+1][j-1] && s[i]==s[j]){
                table[i][j]=true;
                if(k>maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    int low = start; 
    int high = start + maxLength - 1;
    string output;
    for(int i=low;i<=high;i++){
        output+=s[i];
    }
    return output;
}

string countAndSay(int n)
{
    /*
    Input: n = 4
    Output: "1211"
    Explanation:
    countAndSay(1) = "1"
    countAndSay(2) = say "1" = one 1 = "11"
    countAndSay(3) = say "11" = two 1's = "21"
    countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
    */

    //n is 0 then return
    if (n <= 0)
    {
        return "";
    }
    string res = "1";
    while (n > 1)
    {
        string temp = "";
        for (int i = 0; i < res.length(); i++)
        {
            int count = 1;
            while (i + 1 < res.length() && res[i] == res[i + 1])
            {
                count++;
                i++;
            }
            char t = '0' + count;
            temp += t;
            temp += res[i];
        }
        res = temp;
        n--;
    }
    return res;
}

bool shuffleCheck(string first, string second, string result)
{
    //String first = "XY";
    //String second = "12";
    //String[] results = {"1XY2", "Y12X"}; loop to check for the element.
    //1XY2 is a valid shuffle of XY and 12
    //Y12X is not a valid shuffle of XY and
    int l1 = first.length(), l2 = second.length(), lr = result.length();
    //length of two string does not matches result return false.
    if ((l1 + l2) != lr)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (k != lr)
    {
        //check char of result matches with first char of first string
        if (i < l1 && first[i] == result[k])
        {
            i++;
        }
        //check char of result matches with first char of second string
        else if (j < l2 && second[j] == result[k])
        {
            j++;
        }
        //else char does not matches.
        else
        {
            return false;
        }
        k++;
    }
    //if some char left in first and second string.
    if (i < l1 || j < l2)
    {
        return false;
    }
    return true;
}

bool areRotations(string str1, string str2)
{
    //check length of both strings are equal or not
    if (str1.length() != str2.length())
    {
        return 0;
    }
    //we concatenate s1 to s1 because this will bring all rotation in the substring.
    string temp = str1 + str1;
    //string::npos means until the end of the string. It is defined as -1
    //as temp.find(str2), will return
    int found = temp.find(str2);
    cout << found << endl;
    return (temp.find(str2) != string::npos);
}

void duplicateChar(char s[])
{
    unordered_map<char, int> m;
    int i = 0;
    while (s[i] != '\0')
    {
        m[s[i]]++;
        i++;
    }
    for (auto i : m)
    {
        if (i.second > 1)
        {
            cout << "Char: " << i.first << " Count:" << i.second << endl;
        }
    }
}

int isPlaindrome(char S[])
{
    int i = 0, count = 0;
    while (S[i++] != '\0')
    {
        count++;
    }
    int k = 0, j = count - 1;
    while (k < j)
    {
        if (S[k] != S[j])
        {
            return 0;
        }
        k++;
        j--;
    }
    return 1;
}

void reverseString(vector<char> &s)
{
    reverse(s.begin(), s.end());
}