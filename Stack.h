#ifndef DS_STACK_H
#define DS_STACK_H
using namespace std;

struct Node {
    int Val{};
    Node *Next{};

    Node(int x = 0) : Val(x) {}
};

class Stack {
private:
    int len{};
    Node *head{};

    Stack() {}

    void Push(int x) {
        Node *cur = new Node(x);
        cur->Next = head;
        head = cur;
        len++;
    }

    void pop() {
        if (empty())
            return;
        Node *cur = head->Next;
        delete head;
        head = cur;
        len--;
    }

    int top() {
        if (len == 0)
            return -1;
        return head->Val;
    }

    int Size() {
        return len;
    }

    bool empty() {
        return !len;
    }

    ~Stack() {
        while (head) {
            pop();
        }
    }
};

#endif //DS_STACK_H
