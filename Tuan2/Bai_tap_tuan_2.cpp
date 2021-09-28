
// Bai 1

#include <iostream>
using namespace std;

int main ()
{
    int n;
    int a[1000];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }
    }
    cout << count << endl;
    return 0;
}

// Bai 2

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int NodeSize = 0; // size of Node

Node *getNode (int data) // get new Node
{
    Node *newNode = new Node ();
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void insertNode (Node **current, int data, int pos) // insert Node at Nth position
{
    if (pos < 1 || pos > NodeSize + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }
    while (pos--)
    {
        if (pos == 0)
        {
            Node *temp = getNode (data);
            temp -> next = *current;
            *current = temp;
        }
        else
        {
            current = &(*current) -> next;

        }

    }
        NodeSize++; // after insert a Node then size of Node + 1
}

void deleteNode(Node **head, int pos) // delete Node at position x
{
    if (head == NULL)
        return;
    Node *temp = *head;
    if (pos == 0)
    {
        *head = temp -> next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp -> next;
    if (temp == NULL || temp-> next == NULL)
        return;
    Node *next = temp-> next -> next;
    free(temp -> next);
    temp -> next = next;
}
void printList(Node *head) // print Node
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// main
int main ()
{
    Node * head = NULL;
    string quiz;
    getline(cin, quiz);
    int q = stoi(quiz); // number of quiz
    const string del = "delete";
    const string ins = "insert";
    for (int i = 0; i < q; i++)
    {
        string get_input;
        getline(cin, get_input);
        if (get_input.substr(0, 6) == del)
        {
            int pos = stoi(get_input.substr(7, get_input.size())); // cut string , I think I have should used stringstream

            deleteNode(&head, pos);
        }
        else
            if (get_input.substr(0, 6) == ins)
        {
            //cout << "INSERT NODE" << endl;
            int pos = stoi(get_input.substr(7, 2));                 // get position
            int data = stoi (get_input.substr(9,get_input.size())); // get data
            //cout << "POS: " << pos << " DATA: " << data << endl;
            insertNode(&head, data, pos+1);
        }
    }
    printList(head);
    return 0;
}

// Bai 3

#include <iostream>
using namespace std;

struct Node  // I will use struct instead of class because i think in small problem liked this, we dont need to protect variables
{
    int data;
    Node *next;
    Node *prev;
};
void insert(struct Node** head, int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
int count_triplets (Node* head)
{
    int cnt = 0;
    Node *p1, *p2, *p3;
    for (p1 = head; p1 != NULL; p1 = p1 -> next)
        for (p2 = p1-> next; p2 != NULL; p2 = p2 -> next)
            for (p3 = p2 -> next; p3 != NULL; p3 = p3 -> next)
        {
            if (p1 -> data + p2 -> data + p3 -> data == 0)
                cnt++;
        }
    return cnt;
}

int main ()
{
    Node *head = NULL;
    int number;
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        int temp;
        cin >> temp;
        insert(&head, temp);
    }
    cout << count_triplets(head);
    return 0;
}

// Bai 4

/**
Enqueue x : add x at the tail of queue

Dequeue: remove at the head of queue

*/
#include <iostream>
#include <queue>   //use default queue lib

using namespace std;

void printQ (queue <int> q)
{
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main ()
{
    queue<int> newQueue;
    string quiz = "";
    getline(cin, quiz);
    int q = stoi (quiz);
    const string de = "dequeue";  //
    const string en = "enqueue";  //
    for (int i = 0; i < q; i++)
    {
        string input;
        getline(cin, input);
        if (input.substr(0, 7) == de)
        {
            newQueue.pop();
        }
        else
            if (input.substr(0, 7) == en)
        {
            int data = stoi (input.substr(8, input.size()));
            newQueue.push(data);
        }
                else return 1; // end program  if input is neither dequeue nor enqueue
    }
    printQ(newQueue);

    return 0;
}

// Bai 5
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//in the problem (Word), the output is bottom to top of Stack
// so i have to rewrite the print function

void print (stack<int> s)
{
    stack <int> temp = s;
    vector <int> out;
    while (!temp.empty())
    {
        out.push_back(temp.top());
        temp.pop();
    }
    for (int i = 0; i < out.size(); i++)
        cout << out[out.size() - i - 1] << " ";
}

int main () // stack in this problem will be default stack in stack_lib
{
    const string push = "push"; // add at top
    const string pop = "pop"; // delete top
    // quiz
    string quiz;
    getline (cin ,quiz);
    int q = stoi (quiz);

    stack <int> st;
    for(int i = 0; i < q; i++)
    {
        string in;
        getline(cin, in);
        if (in.substr(0, 4) == push)
        {
            int data = stoi (in.substr(5, in.size()));
            st.push(data);
        }
        else
            if (in.substr(0, 3) == pop)
        {
            st.pop();
        }
    }

    print(st);
    return 0;
}
