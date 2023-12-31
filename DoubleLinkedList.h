#ifndef DS_DOUBLELINKEDLIST_H
#define DS_DOUBLELINKEDLIST_H
using namespace std;
struct DoubleNode {
    int Val{};
    DoubleNode *Pre{};
    DoubleNode *Next{};

    DoubleNode(int x = 0) : Val(x) {}
};
class DoubleLinkedList {
public:
    DoubleNode *head{};
    DoubleNode *tail{};
    int len{};
public:
    void InsertFro(int x) {
        DoubleNode *cur = new DoubleNode(x);
        cur->Next = head;
        head->Pre = cur;
        head = cur;
        len++;
        if (len == 1)
            tail = head;
    }

    void InsertEnd(int x) {
        DoubleNode *cur = new DoubleNode(x);
        if (head == nullptr) {
            head = cur;
            tail = cur;
            head->Next = tail;
            tail->Pre = head;
        } else {
            cur->Pre = tail;
            tail->Next = cur;
            tail = cur;
        }
        len++;
    }

    void InsertBeforidx(int idx, int x) {
        //befor idx (idx=3)
        // 1 2 X [3] 4 5 6
        int m = len - idx + 1;
        auto cur = head;
        if (idx <= m) {
            int cot = 1;
            while (cur && cot < idx) {
                cur = cur->Next;
                cot++;
            }
        } else {
            cur = tail;
            int cot = 1;
            while (cur && cot < m) {
                cur = cur->Pre;
                cot++;
            }
        }
        DoubleNode *node = new DoubleNode(x);
        cur->Pre->Next = node;
        node->Pre = cur->Pre;
        cur->Pre = node;
        node->Next = cur;
    }

    void InsertAfteridx(int idx, int x) {
        //after idx (idx=3)
        // 1 2 [3] X 4 5 6
        int m = len - idx + 1;
        auto cur = head;
        if (idx <= m) {
            int cot = 1;
            while (cur && cot < idx) {
                cur = cur->Next;
                cot++;
            }
        } else {
            cur = tail;
            int cot = 1;
            while (cur && cot < m) {
                cur = cur->Pre;
                cot++;
            }
        }
        DoubleNode *node = new DoubleNode(x);
        node->Next = cur->Next;
        cur->Next->Pre = node;
        node->Pre = cur;
        cur->Next = node;
    }

    void DeleteFro() {
        if (!len)
            return;
        if (len == 1) {
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else if (len > 1) {
            DoubleNode *cur = head->Next;
            cur->Pre = nullptr;
            delete head;
            head = cur;
        }
        len--;
    }

    void DeleteEnd() {
        if (len <= 1) {
            DeleteFro();
        } else {
            DoubleNode *pre = tail->Pre;
            pre->Next = nullptr;
            delete tail;
            tail = pre;
            len--;
        }
    }

    void DeleteAt(int n) {
        if (n == 1) {
            DeleteFro();
        } else if (n == len) {
            DeleteEnd();
        } else {
            DoubleNode *cur = GetNth(len - 1);
            cur->Pre->Next = cur->Next;
            cur->Next->Pre = cur->Pre;
            delete cur;
            cur = nullptr;
            len--;
        }
    }

    DoubleNode *GetNth(int n) {
        int m = len - n + 1;
        if (n <= m) {
            auto cur = head;
            int cot = 1;
            while (cur && cot < n) {
                cur = cur->Next;
                cot++;
            }
            return cur;
        } else {
            auto cur = tail;
            int cot = 1;
            while (cur && cot < m) {
                cur = cur->Pre;
                cot++;
            }
            return cur;
        }
    }

    DoubleNode *GetNthBack(int n) {
        int m = len - n + 1;
        swap(n, m);
        if (n <= m) {
            auto cur = head;
            int cot = 1;
            while (cur && cot < n) {
                cur = cur->Next;
                cot++;
            }
            return cur;
        } else {
            auto cur = tail;
            int cot = 1;
            while (cur && cot < m) {
                cur = cur->Pre;
                cot++;
            }
            return cur;
        }
    }

    void Print() {
        DoubleNode *temp = head;
        while (temp != nullptr) {
            cout << temp->Val << " ";
            temp = temp->Next;
        }
        cout << endl;
    }

    bool issame(const DoubleLinkedList &x) {
        if (len != x.len)
            return false;
        DoubleNode *l = head;
        DoubleNode *r = x.head;
        while (l != nullptr) {
            if (l->Val != r->Val)
                return false;
            l = l->Next;
            r = r->Next;
        }
        return true;
    }

    int compare(const DoubleLinkedList &x) {
        // -1 if first list is smaller
        //  0 if equal
        //  1 if second list is smaller
        DoubleNode *head1 = head;
        DoubleNode *head2 = x.head;
        while (head1 && head2) {
            if (head1->Val < head2->Val) {
                return -1;
            } else if (head1->Val > head2->Val) {
                return 1;
            }
            head1 = head1->Next;
            head2 = head2->Next;
        }
        if (!head1 && head2) {
            return -1;
        } else if (head1 && !head2) {
            return 1;
        }
        return 0;
    }

    int Search(int k) {
        DoubleNode *front = head;
        DoubleNode *back = tail;
        int l = 1, r = len;
        while (l <= r) {
            if (front->Val == k) {
                return l;
            }
            if (back->Val == k) {
                return r;
            }
            l++;
            front = front->Next;
            r--;
            back = back->Pre;
        }
        return -1;
    }

    ~DoubleLinkedList() {
        //O(N) Time, O(1) Memory
        while (head != nullptr) {
            DoubleNode *cur = head->Next;
            delete head;
            head = cur;
        }
        len = 0;
    }
};
#endif //DS_DOUBLELINKEDLIST_H
