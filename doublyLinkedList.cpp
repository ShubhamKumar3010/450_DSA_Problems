#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class FlattenNode
{
public:
    int data;
    FlattenNode *next;
    FlattenNode *bottom;
    FlattenNode(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
class compare
{
public:
    bool operator()(Node *first, Node *second)
    {
        return first->data > second->data;
    }
};
void data();
void print(Node *head);
Node *reverseDLL(Node *head);
void pairSum(Node *head, int x);
void tripletSum(Node *head, int x);
void optimisedTripletSum(Node *head, int x);
void optimised_1_TripletSum(Node *head, int x);
Node *k_sorted_DLL(Node *head, int k);
void rotate_n_clockWise(Node *head, int n);
Node *reverse_DLL_by_K(Node *head, int k);
void flattenData();
void flattePrint(FlattenNode *head);
FlattenNode *flatten(FlattenNode *root);
FlattenNode *merge(FlattenNode *a, FlattenNode *b);
int main()
{
    flattenData();
    return 0;
}
FlattenNode *merge(FlattenNode *a, FlattenNode *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    FlattenNode *result;
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
FlattenNode *flatten(FlattenNode *root)
{
    // Your code here
    if (root == NULL or root->next == NULL)
    {
        return root;
    }
    return merge(root, flatten(root->next));
}
void flattePrint(FlattenNode *head)
{
    FlattenNode *temp = head;
    while(temp->bottom!=NULL){
        cout<<temp->data<<" ";
        temp = temp->bottom;
    }
}
void flattenData()
{
    FlattenNode n1(5);
    FlattenNode n2(7);
    FlattenNode n3(8);
    FlattenNode n4(30);
    FlattenNode n5(10);
    FlattenNode n6(19);
    FlattenNode n7(22);
    FlattenNode n8(50);
    FlattenNode n9(28);
    //next connection
    n1.next = &n5;
    n5.next = &n6;
    n6.next = &n9;
    //bottom connection
    n1.bottom = &n2;
    n2.bottom = &n3;
    n3.bottom = &n4;

    n6.bottom = &n7;
    n7.bottom = &n8;

    FlattenNode *head = &n1;
    FlattenNode *ans = flatten(head);
    flattePrint(ans);
}
Node *reverse_DLL_by_K(Node *head, int k)
{
    if (!head)
    {
        return NULL;
    }
    head->prev = NULL;
    Node *cur = head;
    Node *newHead, *temp;
    int count = 0;
    while (count < k and cur != NULL)
    {
        newHead = cur;
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
        count++;
    }
    if (count >= k)
    {
        head->next = reverse_DLL_by_K(cur, k);
    }
    return newHead;
}
void rotate_n_clockWise(Node *head, int n)
{
    if (n == 0)
    {
        return;
    }
    Node *cur = head;
    int count = 1;
    while (count < n and cur != NULL)
    {
        cur = cur->next;
        count++;
    }
    Node *nthNode = cur;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = head;
    head->prev = cur;

    head = nthNode->next;
    head->prev = NULL;

    nthNode->next = NULL;
    print(head);
}
Node *k_sorted_DLL(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    // Syntax to create a min heap for priority queue
    // priority_queue <int, vector<int>, greater<int>> g = gq;
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *newHead = NULL;
    Node *cur;

    //k+1 element will go in pq.
    for (int i = 0; i <= k and head != NULL; i++, head = head->next)
    {
        pq.push(head);
    }
    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            cur = pq.top();
        }
        else
        {
            cur->next = pq.top();
            pq.top()->prev = cur;
            cur = pq.top();
        }
        pq.pop();
        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }
    cur->next = NULL;
    return newHead;
}
void optimised_1_TripletSum(Node *head, int x)
{
    //O(n^2)-Time
    //O(1) - space
    if (head == NULL)
    {
        cout << 0 << endl;
        return;
    }
    Node *cur, *first, *last, *temp;
    last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    for (cur = head; cur != NULL; cur = cur->next)
    {
        first = cur->next;
        temp = last;
        while (first != temp)
        {
            if ((cur->data + first->data + temp->data) == x)
            {
                cout << cur->data << " " << first->data << " " << temp->data << endl;
                temp = temp->prev;
                first = first->next;
            }
            else
            {
                if ((cur->data + first->data + temp->data) > x)
                {
                    temp = temp->prev;
                }
                else
                {
                    first = first->next;
                }
            }
        }
    }
}
void optimisedTripletSum(Node *head, int x)
{
    //O(n^2)-Time
    //O(n) - space
    Node *p, *p1, *p2;
    int count = 0;

    unordered_map<int, Node *> m;
    for (p = head; p != NULL; p = p->next)
    {
        m[p->data] = p;
    }
    // int count = 0;
    for (p1 = head; p1 != NULL; p1 = p1->next)
    {
        for (p2 = p1->next; p2 != NULL; p2 = p2->next)
        {
            int twoSum = p1->data + p2->data;
            if (m.find(x - twoSum) != m.end() and m[x - twoSum] != p1 and m[x - twoSum] != p2)
            {
                //Here we will get one pair thrice because of repition.
                cout << x - twoSum << " " << p1->data << " " << p2->data << endl;
                // count++;
            }
        }
    }
    // return count/3;
}
void tripletSum(Node *head, int x)
{
    //O(n^3)
    Node *p1;
    Node *p2;
    Node *p3;
    for (p1 = head; p1 != NULL; p1 = p1->next)
    {
        for (p2 = p1->next; p2 != NULL; p2 = p2->next)
        {
            for (p3 = p2->next; p3 != NULL; p3 = p3->next)
            {
                if (p1->data + p2->data + p3->data == x)
                {
                    cout << p1->data << " " << p2->data << " " << p3->data << endl;
                }
            }
        }
    }
}
void pairSum(Node *head, int x)
{
    //sorted linked list.
    Node *temp = head;
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    while (temp != temp1)
    {
        if (temp->data + temp1->data == x)
        {
            cout << temp->data << " " << temp1->data << endl;
            temp = temp->next;
            temp1 = temp1->prev;
        }
        else
        {
            if (temp->data + temp1->data > x)
            {
                temp1 = temp1->prev;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}
Node *reverseDLL(Node *head)
{
    Node *cur = head;
    if (cur == NULL or cur->next == NULL)
    {
        return head;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    head = cur;
    swap(cur->next, cur->prev);
    cur = cur->next;
    while (cur->prev != NULL)
    {
        swap(cur->next, cur->prev);
        cur = cur->next;
    }
    swap(cur->next, cur->prev);
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void data()
{
    Node n1(3);
    Node n2(6);
    Node n3(2);
    Node n4(12);
    Node n5(56);
    Node n6(8);
    n1.next = &n2;
    n2.prev = &n1;
    n2.next = &n3;
    n3.prev = &n2;
    n3.next = &n4;
    n4.prev = &n3;
    n4.next = &n5;
    n5.prev = &n4;
    n5.next = &n6;
    n6.prev = &n5;
    Node *head = &n1;
    Node *ans = reverse_DLL_by_K(head, 2);
    print(ans);
}