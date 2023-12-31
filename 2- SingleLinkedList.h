#ifndef SINGLELINKEDLIST
#define SINGLELINKEDLIST
using namespace std;
struct TheNode {
    int Val{};
    TheNode *Next{};

    TheNode(int x = 0) : Val(x) {}
};
class SingleLinkedList {
public:
    TheNode *head{};
    TheNode *tail{};
    int len{};
public:
    void InsertFro(int x) {
        TheNode *cur = new TheNode(x);
        cur->Next = head;
        head = cur;
        len++;
        if (len == 1)
            tail = head;
    }

    void InsertEnd(int x) {
        TheNode *cur = new TheNode(x);
        if (head == nullptr) {
            head = cur;
            tail = cur;
        } else {
            tail->Next = cur;
            tail = cur;
        }
        len++;
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
            TheNode *cur = head->Next;
            delete head;
            head = cur;
        }
        len--;
    }

    void DeleteEnd() {
        if (len <= 1) {
            DeleteFro();
        } else {
            TheNode *pre = GetNth(len - 1);
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
            TheNode *pre = GetNth(len - 1);
            TheNode *cur = pre->Next;
            pre->Next = cur->Next;
            delete cur;
            cur = nullptr;
            len--;
        }
    }

    TheNode *GetNth(int n) {
        auto cur = head;
        int cot = 1;
        while (cur && cot < n) {
            cur = cur->Next;
            cot++;
        }
        return cur;
    }

    TheNode *GetNthBack(int n) {
        n = len - n + 1;
        auto cur = head;
        int cot = 1;
        while (cur && cot < n) {
            cur = cur->Next;
            cot++;
        }
        return cur;
    }

    void Print() {
        TheNode *temp = head;
        while (temp != nullptr) {
            cout << temp->Val << " ";
            temp = temp->Next;
        }
        cout << endl;
    }

    bool issame(const SingleLinkedList &x) {
        if (len != x.len)
            return false;
        TheNode *l = head;
        TheNode *r = x.head;
        while (l != nullptr) {
            if (l->Val != r->Val)
                return false;
            l = l->Next;
            r = r->Next;
        }
        return true;
    }

    int compare(const SingleLinkedList &x) {
        // -1 if first list is smaller
        //  0 if equal
        //  1 if second list is smaller
        TheNode *head1 = head;
        TheNode *head2 = x.head;
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
        auto cur = head;
        int cot = 0;
        while (cur != nullptr && cur->Val != k) {
            cur = cur->Next;
            cot++;
        }
        return (cur != nullptr && cur->Val == k) ? cot : -1;
    }

    int ImpSearch(int k) {
        TheNode *cur = head;
        int cot = 0;
        TheNode *last = nullptr;
        while (cur != nullptr && cur->Val != k) {
            last = cur;
            cur = cur->Next;
            cot++;
        }
        if (cur->Val == k) {
            if (last != nullptr) {
                swap(last->Val, cur->Val);
                return cot - 1;
            } else
                return cot;
        } else
            return -1;
    }

    ~SingleLinkedList() {
        //O(N) Time, O(1) Memory
        while (head != nullptr) {
            TheNode *cur = head->Next;
            delete head;
            head = cur;
        }
        len = 0;
    }
};
#endif //SINGLELINKEDLIST
