#ifndef DS_AVL_H
#define DS_AVL_H
using namespace std;

class AVL {
private:
    struct TreeNode {
        int Data{};
        int Height{};
        TreeNode *Left{};
        TreeNode *Right{};

        TreeNode(int val = 0) : Data(val) {}

        int ChildHeight(TreeNode *node) {
            return (!node) ? 0 : node->Height;
        }

        int UpdateHeight() {
            return Height = 1 + max(ChildHeight(this->Left), ChildHeight(this->Right));
        }

        int BF() {
            return (ChildHeight(this->Left) - ChildHeight(this->Right));
        }
    };

    TreeNode *root{};

    bool Serach(int val, TreeNode *node) {
        if (!node)
            return false;
        if (val == node->Data)
            return true;
        if (val < node->Data)
            return Serach(val, node->Left);
        return Serach(val, node->Right);
    }

    TreeNode *LeftRotation(TreeNode *P) {
        TreeNode *Q = P->Right;
        P->Right = Q->Left;
        Q->Left = P;
        P->UpdateHeight();
        Q->UpdateHeight();
        return Q;
    }

    TreeNode *RightRotation(TreeNode *Q) {
        TreeNode *P = Q->Right;
        Q->Left = P->Right;
        P->Right = Q;
        P->UpdateHeight();
        Q->UpdateHeight();
        return Q;
    }

    TreeNode *Balance(TreeNode *node) {
        int bf = node->BF();
        if (bf == 2) {//L
            if (node->Left->BF() == -1) {//LR
                node->Left = LeftRotation(node->Left);
            }
            node = RightRotation(node);
        } else if (bf == -2) {//R
            if (node->Right->BF() == 1) {//RL
                node->Right = RightRotation(node->Right);
            }
            node = LeftRotation(node);
        }
        return node;
    }

    TreeNode *InsertNode(int val, TreeNode *cur) {
        if (val < cur->Data) {
            if (cur->Left) {
                cur->Left = InsertNode(val, cur->Left);
            } else {
                cur->Left = new TreeNode(val);
            }
        } else if (val > cur->Data) {
            if (cur->Right) {
                cur->Right = InsertNode(val, cur->Right);
            } else {
                cur->Right = new TreeNode(val);
            }
        }
        cur->UpdateHeight();
        return Balance(cur);
    }

    TreeNode *MinNode(TreeNode *cur) {
        if (!cur)
            return cur;
        if (cur->Left)
            return MinNode(cur->Left);
        return cur;
    }

    TreeNode *DeleteNode(int val, TreeNode *cur) {//same as Delete in BST
        if (!cur)
            return cur;
        if (val < cur->Data) {
            cur->Left = DeleteNode(val, cur->Left);
        } else if (val > cur->Data) {
            cur->Right = DeleteNode(val, cur->Right);
        } else {
            TreeNode *tmp = cur;

            if (!cur->Left && !cur->Right)    // case 1: no child
                cur = nullptr;
            else if (!cur->Right)    // case 2: has Left only
                cur = cur->Left;        // connect with child
            else if (!cur->Left)    // case 2: has Right only
                cur = cur->Right;
            else {    // 2 children: Use successor
                TreeNode *mn = MinNode(cur->Right);
                cur->Data = mn->Data;    // copy & go delete
                cur->Right = DeleteNode(cur->Data, cur->Right);
                tmp = nullptr;    // Don't delete me. Successor will be deleted
            }
            if (tmp)
                delete tmp;
        }
        if (cur) {
            cur->UpdateHeight();
            cur = Balance(cur);
        }
        return cur;
    }

    bool IsBST(TreeNode *cur) {
        if (abs(cur->BF()) > 1) {
            return false;
        } else {
            return IsBST(cur->Left) && IsBST(cur->Right);
        }
    }

    void PrintInorder(TreeNode *cur) {
        if (!cur)
            return;
        PrintInorder(cur->Left);
        cout << cur->Data << " ";
        PrintInorder(cur->Right);
    }

    void Verify() {
        assert(abs(root->BF()) <= 1);
        assert(IsBST(root));
    }

public:


    void InsertValue(int val) {
        if (!root)
            root = new TreeNode(val);
        else {
            root = InsertNode(val, root);
        }
        Verify();
    }

    void DeleteValue(int val) {
        if (root) {
            root = DeleteNode(val, root);
            Verify();
        }
    }

    bool SearchVal(int val) {
        return Serach(val, root);
    }

    void PrintINOrder() {
        PrintInorder(root);
    }
};

#endif //DS_AVL_H
