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
void data();
void print(Node *head);
Node *reverseDLL(Node *head);
void pairSum(Node *head, int x);
void tripletSum(Node *head, int x);
void optimisedTripletSum(Node *head, int x);
void optimised_1_TripletSum(Node *head, int x);
int main()
{
    data();
    return 0;
}
void optimised_1_TripletSum(Node *head, int x)
{
    //O(n^2)-Time
    //O(1) - space
    if(head==NULL){
        cout<<0<<endl;
        return;
    }
    Node *cur,*first,*last,*temp;
    last = head;
    while(last->next!=NULL){
        last = last->next;
    }
    for(cur=head;cur!=NULL;cur=cur->next){
        first = cur->next;
        temp = last;
        while(first!=temp){
            if((cur->data+first->data+temp->data)==x){
                cout<<cur->data<<" "<<first->data<<" "<<temp->data<<endl;
                temp=temp->prev;
                first=first->next;
            }else{
                if((cur->data+first->data+temp->data)>x){
                    temp=temp->prev;
                }else{
                    first=first->next;
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
    Node n1(1);
    Node n2(2);
    Node n3(4);
    Node n4(5);
    Node n5(6);
    Node n6(8);
    Node n7(9);
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
    n6.next = &n7;
    n7.prev = &n6;
    Node *head = &n1;
    optimised_1_TripletSum(head, 17);
}