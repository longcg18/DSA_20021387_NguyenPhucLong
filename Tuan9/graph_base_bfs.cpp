#include <iostream>

using namespace std;

//BFS
struct Node { //vertex
    Node *nextNodes;
    int data;
};

Node* createNewNode(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->nextNodes = NULL;
    return new_node;
}

struct Graph {
    int numOfNodes;

    Node **listNode;

    int *traversed;

    void add_edge(int src, int dest) {
        Node* new_node = createNewNode(dest);
        new_node->nextNodes = this->listNode[src];
        this->listNode[src] = new_node;
        new_node = createNewNode(src);
        new_node->nextNodes = this->listNode[dest];
        this->listNode[dest] = new_node;
    }
};

struct queue {
    int N = 0;
    int elements[N];
    int frontItem;
    int rearItem;

    queue() {
        this->frontItem = -1;
        this->rearItem = -1;
    }

    void add_element(int value) {
        if (this->rearItem == N - 1 && N > 0) {
            cout << "Full of queue." << endl;
        } else {
            if (this->frontItem == -1) {
                this->frontItem = 0;
            }
            this->rearItem = this->rearItem + 1;
            this->elements[this->rearItem] = value;
        }
    }

    bool isEmpty() {
        if (this->rearItem == -1) return true;
        return false;
    }

    int remove_element() {
        int item;
        if(this.isEmpty()) {
            cout << "Empty queue." << endl;
            item = -1;
        } else {
            item = this->elements[this->frontItem];
            this->frontItem++;
            if (this->frontItem > this->rearItem) {
                cout << "Reset queue." << endl;
                this->rearItem = -1;
                this->frontItem = this->rearItem;
            }
        }
        return item;
    }

    void print() {
        int i = this->frontItem;
        if (this.isEmpty()) {
            cout << "Empty queue." << endl;
        } else {
            for (i = this->frontItem; i <= this->rearItem; i++) {
                cout << this->elements[i] << " ";
            }
        }
    }
};

void bfs(Graph* g, int start) {
    queue *q = new queue();

    g->traversed[start] = 1;

    q.add_element(start);

    while(!q.isEmpty()) {
        q.print();
        int current = q.remove_element();
        cout << "Have traversed: " << current << endl;
        Node *temp = g->listNode[current];
        while(temp) {
            int nextdata = temp->data;
            if (g->traversed[nextdata] == 0) {
                g->traversed[nextdata] == 1;
                q.add_element(nextdata);
            }
            temp = temp->nextNodes;
        }
    }

}



Graph* create(int nums) {
    Graph* g = new Graph();
    g->numOfNodes = nums;
    g->listNode = malloc(nums* sizeof(Node*));
    g->traversed = malloc(nums* sizeof(int));
}


int main() {


    Graph* newGraph = create(6);
    newGraph.add_edge(1, 2);
    newGraph.add_edge(1, 3);
    newGraph.add_edge(2, 3);
    newGraph.add_edge(2, 5);
    newGraph.add_edge(2, 4);
    newGraph.add_edge(3, 5);
    newGraph.add_edge(4, 5);
    bfs(newGraph, 1);
    return 0;
}
