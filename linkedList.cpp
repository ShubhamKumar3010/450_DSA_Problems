#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        next = NULL;
    }
};
Node *takeInput();
void print(Node *head);
Node *reverse(Node *head);
Node *reverse_k_group(Node *head, int k);
void loopCode();
bool detectLoop(Node *head);
bool detectLoopTwoPointer(Node *head);
void removeLoop(Node *head);
void removeLoopOptimized(Node *head);
void firstNodeOfCycle(Node *head);
Node *removeDuplicatesSortedLL(Node *head);
void removeDuplicatesUnsortedLL(Node *head);
Node *lastELement_to_first(Node *head);
Node *addOne(Node *head);
Node *addTwoLists(Node *first, Node *second);
void addTwoLL();
Node *findIntersection(Node *head1, Node *head2);
int intersectPoint(Node *head1, Node *head2);
void mergeSort();
void MergeSorting(Node **head);
void FindMiddle(Node *cur, Node **first, Node **second);
Node *MergeBoth(Node *first, Node *second);
void quickSort(struct node **headRef);
Node *middleNode(Node *head);
bool isCircular(Node *head);
void splitList(Node *head, Node **head1_ref, Node **head2_ref);
bool isPalindrome(Node *head);
void circularLinkedList();
void prinCircularLinkedList(Node *head);
void circularInsertAtTail(Node *head, int v);
void circularInsertAtHead(Node *head, int v);
void circularDeletion(Node *head, int pos);
void deleteAtHead(Node *head);
int main()
{

    return 0;
}

void deleteAtHead(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
    prinCircularLinkedList(head);
}
void circularDeletion(Node *head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *toBeDeleted = temp->next;
    temp->next = temp->next->next;
    delete toBeDeleted;
}
void circularInsertAtHead(Node *head, int v)
{
    Node *n = new Node(v);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void circularInsertAtTail(Node *head, int v)
{
    if (head == NULL)
    {
        circularInsertAtHead(head, v);
        return;
    }

    Node *n = new Node(v);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void prinCircularLinkedList(Node *head)
{
    //print
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void circularLinkedList()
{
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n1;
    Node *head = &n1;
    circularDeletion(head, 1);
}
bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *prev = NULL;
    Node *next;
    Node *cur = slow;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    fast = head;
    while (prev != NULL)
    {
        if (prev->data != fast->data)
        {
            return false;
        }
        fast = fast->next;
        prev = prev->next;
    }
    return true;
}
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head;
    Node *fast = head->next;
    while (fast != head and (fast->next) != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    Node *temp = *head2_ref;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = *head2_ref;
}
bool isCircular(Node *head)
{
    // Your code here
    if (head == NULL)
    {
        return 1;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            break;
        }
    }
    if (temp)
    {
        return 1;
    }
    return 0;
}
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void quickSort(struct node **headRef)
{
}
void mergeSort()
{
    // your code here
    Node n1(4);
    Node n2(5);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Node *head = &n1;
    MergeSorting(&head);
    print(head);
}
void MergeSorting(Node **head)
{
    Node *cur = *head;
    Node *first;
    Node *second;
    if (!cur or !cur->next)
        return;
    FindMiddle(cur, &first, &second);
    MergeSorting(&first);
    MergeSorting(&second);
    *head = MergeBoth(first, second);
}
void FindMiddle(Node *cur, Node **first, Node **second)
{
    Node *fast;
    Node *slow;
    slow = cur;
    fast = cur->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = cur;
    *second = slow->next;
    slow->next = NULL;
}
Node *MergeBoth(Node *first, Node *second)
{
    Node *ans = NULL;
    if (!first)
    {
        return second;
    }
    else if (!second)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        ans = first;
        ans->next = MergeBoth(first->next, second);
    }
    else
    {
        ans = second;
        ans->next = MergeBoth(first, second->next);
    }
    return ans;
}
int intersectPoint(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    int c1 = 0, c2 = 0;
    while (p1)
    {
        c1++;
        p1 = p1->next;
    }
    while (p2)
    {
        c2++;
        p2 = p2->next;
    }
    p1 = head1, p2 = head2;
    int dif = abs(c1 - c2);
    if (c1 > c2)
    {
        for (int i = 0; i < dif; i++)
        {
            p1 = p1->next;
        }
    }
    else
    {
        for (int i = 0; i < dif; i++)
        {
            p2 = p2->next;
        }
    }
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1)
        return p1->data;
    return -1;
}
Node *findIntersection(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *ans = NULL;
    Node *temp = NULL;
    while (p1 and p2)
    {
        if (p1->data == p2->data)
        {
            if (ans == NULL)
            {
                Node *newNode = new Node(p1->data);
                ans = newNode;
                temp = newNode;
            }
            else
            {
                Node *newNode = new Node(p1->data);
                temp->next = newNode;
                temp = temp->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            if (p1->data < p2->data)
            {
                p1 = p1->next;
            }
            else
            {
                p2 = p2->next;
            }
        }
    }
    return ans;
}
void addTwoLL()
{
    Node n1(4);
    Node n2(5);
    n1.next = &n2;
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n3.next = &n4;
    n4.next = &n5;
    Node *head1 = &n1;
    Node *head2 = &n3;
    Node *res = addTwoLists(head1, head2);
    print(res);
}
Node *addTwoLists(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);
    int sum = 0;
    int c = 0;
    Node *temp;
    Node *res = NULL;
    Node *cur = NULL;
    while (first != NULL or second != NULL)
    {
        sum = c + (first ? first->data : 0) + (second ? second->data : 0);
        c = (sum >= 10) ? 1 : 0;
        sum %= 10;
        temp = new Node(sum);
        if (res == NULL)
        {
            res = temp;
        }
        else
        {
            cur->next = temp;
        }
        cur = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (c > 0)
    {
        temp = new Node(c);
        cur->next = temp;
        cur = temp;
    }
    res = reverse(res);
    return res;
}
Node *addOne(Node *head)
{
    // Your Code here
    //reverse before adding
    head = reverse(head);
    Node *cur = head;
    bool lastCheck = true;
    while (lastCheck and cur != NULL)
    {
        if (cur->next == NULL and cur->data == 9)
        {
            cur->data = 1;
            Node *newNode = new Node(0);
            newNode->next = head;
            head = newNode;
            cur = cur->next;
        }
        else if (cur->data == 9)
        {
            cur->data = 0;
            cur = cur->next;
        }
        else
        {
            cur->data += 1;
            cur = cur->next;
            lastCheck = false;
        }
    }
    //reverse after adding
    head = reverse(head);
    return head;
}
Node *lastELement_to_first(Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *secondLast = NULL;
    Node *last = head;

    //By this we come to last and second last node.
    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }
    //we remove sonnection bw secondLast and last and add Null to secondLast.
    secondLast->next = NULL;

    last->next = head;
    head = last;
    return head;
}
void removeDuplicatesUnsortedLL(Node *head)
{
    // your code goes here
    map<int, int> m;
    Node *current = head;
    m[current->data] = 1;
    Node *prev = current;
    current = current->next;
    while (current != NULL)
    {
        if (!m[current->data])
        {
            m[current->data] = 1;
            prev = current;
        }
        else
        {
            prev->next = current->next;
            free(current);
        }
        current = prev->next;
    }
}
Node *removeDuplicatesSortedLL(Node *head)
{
    // your code goes here
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
void firstNodeOfCycle(Node *head)
{
    Node *high = head;
    Node *low = head;
    while (low != NULL and high != NULL and high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
        {
            break;
        }
    }
    if (low == head)
    {
        cout << "Loop starts from node : ";
        cout << head->data << endl;
    }
    else
    {
        low = head;
        while (low->next != high->next)
        {
            low = low->next;
            high = high->next;
        }
        cout << "Loop starts from node : ";
        cout << low->next->data << endl;
    }
}
void removeLoopOptimized(Node *head)
{

    Node *high = head;
    Node *low = head;

    while (low != NULL and high != NULL and high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
        {
            break;
        }
    }
    if (low == head)
    {
        while (high->next != low)
        {
            high = high->next;
        }
        high->next = NULL;
    }
    else if (low == high)
    {
        low = head;
        while (low->next != high->next)
        {
            low = low->next;
            high = high->next;
        }
        high->next = NULL;
    }
}
void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    if (!head)
        return;
    Node *prev = head;
    Node *cur = head->next;
    unordered_map<Node *, int> m;
    while (cur)
    {
        if (!m[cur])
        {
            m[cur] = 1;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            prev->next = NULL;
            break;
        }
    }
}
bool detectLoopTwoPointer(Node *head)
{
    //space - O(1) and time - O(n).
    if (!head)
        return false;
    Node *low = head;
    Node *high = head;
    while (high != NULL and high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
        {
            return true;
        }
    }
    return false;
}
bool detectLoop(Node *head)
{
    // your code here
    //space - O(n) and time - O(n).
    if (!head)
        return false;

    unordered_map<Node *, int> m;
    while (head)
    {
        if (!m[head])
        {
            m[head] = 1;
            head = head->next;
        }
        else
        {
            return true;
        }
    }
    return false;
}
void loopCode()
{
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n7(7);
    Node n8(8);
    Node n9(9);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n9;
    print(head);
    Node *head1 = addOne(head);
    print(head1);

    // cout << "Sorted LL with duplicate:" << endl;
    // print(head);
    // removeDuplicatesSortedLL(head);
    // cout << "Sorted LL after removal of duplicate" << endl;
    // print(head);

    // cout<<"Before remove  cycle called"<<endl;
    // if(detectLoopTwoPointer(head)){
    //     cout<<"Contain cycle"<<endl;
    // }else{
    //     cout<<"No cycle"<<endl;
    // }
    // removeLoopOptimized(head);
    // cout<<"Before remove  cycle called"<<endl;
    // if(detectLoopTwoPointer(head)){
    //     cout<<"Contain cycle"<<endl;
    // }else{
    //     cout<<"No cycle"<<endl;
    // }
}
Node *reverse_k_group(Node *head, int k)
{
    Node *next, *prev = NULL;
    Node *cur = head;
    int c = 0;
    while (cur != NULL and c < k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        c++;
    }
    if (next != NULL)
    {
        head->next = reverse_k_group(next, k);
    }
    return prev;
}
Node *reverse(Node *head)
{
    Node *next = NULL, *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}