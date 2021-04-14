#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s);

int isPlaindrome(char S[]);

void duplicateChar(char s[]);

bool areRotations(string str1, string str2);

int maxSubStr(string str, int n);

int main()
{
    string s1 = "0100110101";
    cout<<maxSubStr(s1,s1.length());
}

int maxSubStr(string str, int n)
{
    //Split the binary string into substrings with equal number of 0s and 1s.
    //Eg : "0100110101"
    //Output : 4
    //The required substrings are “01”, “0011”, “01” and “01”. 
    int count0 = 0, count1 = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        str[i]=='0'? count0++ : count1++;
        if(count1==count0){
            ans++;
        }
    }
    return ans;
}
bool areRotations(string str1, string str2)
{
    //check length of both strings are equal or not
    if(str1.length()!=str2.length()){
        return 0;
    }
    //we concatenate s1 to s1 because this will bring all rotation in the substring.
    string temp = str1+str1;
    //string::npos means until the end of the string. It is defined as -1
    //as temp.find(str2), will return
    int found = temp.find(str2);
    cout<<found<<endl;
    return (temp.find(str2) != string::npos);
}

void duplicateChar(char s[])
{
    unordered_map<char,int> m;
    int i = 0;
    while(s[i]!='\0'){
        m[s[i]]++;
        i++;
    }
    for(auto i : m){
        if(i.second>1){
            cout<<"Char: "<<i.first<<" Count:"<<i.second<<endl;
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