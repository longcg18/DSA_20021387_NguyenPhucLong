#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild; // Con trái nhất
    Node* nextChild; // Con tiếp theo
    Node* previousChild; // Con đằng trước
    int numberOfChildren; // Số lượng con

public:
    Node(int _data = 0, Node* _father = NULL) {
        // ...
        data = _data;
        fatherNode = _father;
        firstChild = NULL;
        nextChild = NULL;
        previousChild = NULL;
        numberOfChildren = 0;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm này thêm một Node con vào một Node cho trước
    void insertNode(Node* node) {
        if (firstChild == NULL) {
            firstChild = node;
        } else {
            if (node->data < firstChild->data) {
                node->nextChild = firstChild;

                firstChild->previousChild = node;

                firstChild = node;
            } else {
                Node* temp = firstChild;

                while (temp -> nextChild != NULL && node->data > temp->nextChild->data)
                    temp = temp->nextChild;

                node->nextChild = temp->nextChild;

                if (temp->nextChild != NULL)
                    temp->nextChild->previousChild = node;

                node->previousChild = temp;

                temp->nextChild = node;
            }
        }
        numberOfChildren++;
    }
    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;

    // Hàm này đi tìm Node nhận mà có data đã biết trước, trả về Node đầu tiên tìm được
    Node* nodeSearch(Node* father, int data) {
        if (father->firstChild == NULL) return NULL; // Nếu không có con, trả về NULL

        Node* headChild = father->firstChild; //con trỏ duyệt hàng con

        while (headChild != NULL) {

            if (headChild->data == data) return headChild;

            Node* goRight = nodeSearch(headChild, data); // duyệt tiếp node bên phải

            if (goRight != NULL) return goRight;

            headChild = headChild->nextChild;
        }
        return NULL;
    }

    // Hàm xóa Node
    int deleteNode(Node* node) {
        int del = 0;
        Node* temp = node->firstChild;
        while (temp != NULL) {
            del = del + deleteNode(temp);
            Node* pos = temp;
            temp = temp->nextChild;
            delete[] pos;
            del++;
        }
        return del;
    }

    int maxChildIndex = -1;
    int maxChildNumber = 0;

    //Tìm Node con có giá trị lớn nhất
    void findMaxNode(Node* pos = NULL) {
        if (pos == NULL) {
            findMaxNode(root);
            return;
        } else {
            if (pos->numberOfChildren > maxChildNumber) {
                maxChildNumber = pos->numberOfChildren;
                maxChildIndex = pos->data;
            }

            Node* temp = pos->firstChild;
            while(temp != NULL) {
                findMaxNode(temp);
                temp = temp->nextChild;
            }
        }
    }

public:
    Tree(int data) {
        // ...
        root = new Node(data);
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {

        Node *pos;

        if (root->data == father) pos = root;

        else pos = nodeSearch(root, father);

        if (pos == NULL) return false;

        pos->insertNode(new Node(data, pos));

    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        Node* pos;
        if (root->data == data) {
            pos = root;
        } else {
            pos = nodeSearch(root, data);
        } if (pos == NULL) {
            return 0;
        }
        int del = deleteNode(pos);
        if (pos->previousChild == NULL) {
            pos->fatherNode->firstChild = pos->nextChild;
        } else {
            pos->previousChild->nextChild = pos->nextChild;
        } if (pos->nextChild != NULL) {
            pos->nextChild->previousChild = pos->previousChild;
        }
        pos->fatherNode->numberOfChildren--;
        del++;
        return del;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* pos = NULL) {
        if (pos == NULL) {
            preorder(root);
            return;
        }
        cout << pos->data << " ";
        Node* temp = pos->firstChild;
        while (temp != NULL) {
            if (temp->fatherNode == pos) {
                preorder(temp);
            }
            temp = temp->nextChild;
        }
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node* pos = NULL) {
        if (pos == NULL) {
            postorder(root);
            return;
        }
        Node* temp = pos->firstChild;
        while (temp != NULL) {
            if (temp->fatherNode == pos) {
                postorder(temp);
            }
            temp = temp->nextChild;
        }
        cout << pos->data << " ";
        return;
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree(Node* pos = NULL) {
        if (pos == NULL) {
            return isBinaryTree(root);
        }
        int cnt = 0;
        Node* temp = pos->firstChild;
        while (temp != NULL) {
            cnt++;
            if (!isBinaryTree(temp)) {
                return false;
            }
            temp = temp->nextChild;
        }
        if (cnt <= 2 && cnt >= 0) {
            return true;
        }
        return false;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node* pos = NULL) {
        if (pos == NULL) {
            if (isBinaryTree()) {
                inorder(root);
                return;
            }
        } else {
            if (pos->numberOfChildren == 0) {
                cout << pos->data << " ";
            } else {
                inorder(pos->firstChild);
                cout << pos->data << " ";
                if (pos->firstChild->nextChild != NULL) {
                    inorder(pos->firstChild->nextChild);
                }
            }

        }
    }

    // Hàm trả về độ cao của cây
    int height(Node* pos = NULL) {
        if (pos == NULL) {
            return height(root);
        } else {
            int high = 0;
            Node* temp = pos->firstChild;
            while (temp != NULL) {
                int r = height(temp);
                if (r > high) {
                    high = r;
                }
                temp = temp->nextChild;
            }
            return high + 1;
        }
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node* t = nodeSearch(root, data);
        return height(root) - height(t);
    }

    // Hàm đếm số lượng lá
    int numOfLeaves(Node* pos = NULL) {
        if (pos == NULL) {
            return numOfLeaves(root);
        } else {
            if (pos->numberOfChildren == 0) {
                return 1;
            }
            int count = 0;
            Node* temp = pos->firstChild;
            while(temp != NULL) {
                count = count + numOfLeaves(temp);
                temp = temp->nextChild;
            }
            return count;
        }
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax(Node* pos = NULL) {
        if (pos == NULL) {
            return findMax(root);
        } else {
            int max = pos->data;
            Node* temp = pos->firstChild;
            while (temp != NULL) {
                int temp2 = findMax(temp);
                if (temp2 > max) {
                    max = temp2;
                }
                temp = temp->nextChild;
            }
            return max;
        }
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        maxChildNumber = 0;
        maxChildIndex = -1;

        findMaxNode();
        return maxChildIndex;
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây
    Tree tree(1);
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(2, 4);
    tree.insert(2, 5);
    tree.insert(3, 6);
    tree.insert(3, 7);
    tree.insert(4, 8);
    tree.insert(4, 9);
    tree.insert(5, 10);
    tree.insert(5, 11);

    cout << "pre: ";
    tree.preorder();
    cout << endl;

    cout << "post: ";
    tree.postorder();
    cout << endl;

    cout << "in: ";
    tree.inorder();
    cout << endl;

    cout << "Height of tree: " << tree.height() << endl;

    cout << "Node data = 5, depth of node is: " << tree.depth(5) << endl;

    cout << "Number of leaves: " << tree.numOfLeaves() << endl;

    cout << "Find max: " << tree.findMax() << endl;

    cout << "Find max child: " << tree.findMaxChild() << endl;

    //cout <<"Is binary tree? "<< (tree.isBinaryTree() ? "True" : "False")<< endl;
    if (tree.isBinaryTree()) {
        cout << "This tree is a binary tree" << endl;
    } else {
        cout << "This tree is not a binary tree." << endl;
    }

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại

    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
