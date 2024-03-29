#ifndef DS_MINHEAP_H
#define DS_MINHEAP_H
using namespace std;

class MinHeap {
private:
    int size{};
    vector<int> heap;

    pair<int, int> childs(int idx) {
        int l = 2 * idx + 1;
        if (l >= size)
            l = -1;
        int r = 2 * idx + 2;
        if (r >= size)
            r = -1;
        return {l, r};
    }

    int parent(int idx) {
        return (idx == 0) ? -1 : (idx - 1) / 2;
    }

    void HeapifyUp(int idx) {
        int par = parent(idx);
        if (par == -1)
            return;
        if (heap[idx] < heap[par]) {
            swap(heap[idx], heap[par]);
            HeapifyUp(par);
        }
    }

    void HeapifyDown(int idx) {
        auto ch = childs(idx);
        if (ch.first == -1 && ch.second == -1)
            return;
        if (ch.first == -1) {//only right
            if (heap[idx] > heap[ch.second]) {
                swap(heap[idx], heap[ch.second]);
                HeapifyUp(ch.second);
            }
            return;
        }
        if (ch.second == -1) {//only left
            if (heap[idx] > heap[ch.first]) {
                swap(heap[idx], heap[ch.first]);
                HeapifyUp(ch.first);
            }
            return;
        }
        int st = heap[ch.first] < heap[ch.second];
        if (st) {//go left
            if (heap[idx] > heap[ch.first]) {
                swap(heap[idx], heap[ch.first]);
                HeapifyUp(ch.first);
            }
        } else {//go right
            if (heap[idx] > heap[ch.second]) {
                swap(heap[idx], heap[ch.second]);
                HeapifyUp(ch.second);
            }
        }
    }

    void Heapify() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            HeapifyDown(i);
        }
    }

public:
    MinHeap() {

    }

    MinHeap(const vector<int> &v) {
        heap.resize(v.size());
        size = v.size();
        for (int i = 0; i < size; i++)
            heap[i] = v[i];
        Heapify();
    }


    void Push(int val) {
        heap.push_back(val);
        size = heap.size();
        HeapifyUp(size - 1);
    }

    void pop() {
        swap(heap[0], heap[size - 1]);
        heap.pop_back();
        size = heap.size();
        HeapifyDown(0);
    }

    int Top() {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    bool Empty() {
        return heap.empty();
    }

    ~MinHeap() {
        size = 0;
    }
};

#endif //DS_MINHEAP_H
