#ifndef DS_QUEUE_H
#define DS_QUEUE_H

struct NoDe {
    int Val{};
    NoDe *Next{};

    NoDe(int x = 0) : Val(x) {}
};

class Queue {
private:
    int len{};
    NoDe *head{};
    NoDe *tail{};
public:
    Queue() {

    }

    void push(int x) {
        NoDe *cur = new NoDe(x);
        cur->Next = head;
        head = cur;
        len++;
        if (len == 1)
            tail = head;
    }

    void pop() {
        NoDe *nxt = head->Next;
        delete head;
        head = nxt;
        len--;
        if (!len)
            tail = head;
    }

    int front() {
        if (empty())
            return -1;
        return head->Val;
    }

    int back() {
        if (empty())
            return -1;
        return tail->Val;
    }

    bool empty() {
        return !len;
    }

    bool size() {
        return len;
    }
};

#endif //DS_QUEUE_H
