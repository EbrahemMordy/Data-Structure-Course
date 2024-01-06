#ifndef DS_BT_H
#define DS_BT_H
using namespace std;

struct TreeNode {
    int data{};
    TreeNode *Left{};
    TreeNode *Right{};

    TreeNode(int x = 0) : data(x) {}
};


class BinaryTree {
private:
    TreeNode *root{};

    void printpreorder(TreeNode *cur) {
        if (!cur)
            return;
        cout << cur->data << " ";
        printpreorder(cur->Left);
        printpreorder(cur->Right);
    }

    void printinorder(TreeNode *cur) {
        if (!cur)
            return;
        printpreorder(cur->Left);
        cout << cur->data << " ";
        printpreorder(cur->Right);
    }

    void printpostorder(TreeNode *cur) {
        if (!cur)
            return;
        printpreorder(cur->Left);
        printpreorder(cur->Right);
        cout << cur->data << " ";
    }

public:
    BinaryTree(int val = 0) : root(new TreeNode(val)) {}

    void PrintPreOrder() {
        printpreorder(root);
        cout << endl;
    }

    void PrintInOrder() {
        printinorder(root);
        cout << endl;
    }

    void PrintPostOrder() {
        printpostorder(root);
        cout << endl;
    }

    void LevelOrder() {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int curlevelsize = q.size();
            cout << "Level " << level << " :-" << endl;
            while (curlevelsize--) {
                TreeNode *cur = q.front();
                q.pop();
                cout << cur->data << " ";
                if (cur->Left)
                    q.push(cur->Left);
                if (cur->Right)
                    q.push(cur->Right);
            }
            level++;
            cout << endl;
        }
    }
};

#endif //DS_BT_H
