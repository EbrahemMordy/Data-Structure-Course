#ifndef DS_BST_H
#define DS_BST_H
using namespace std;

struct TreeNode {
    int data{};
    TreeNode *Left{};
    TreeNode *Right{};

    TreeNode(int x = 0) : data(x) {}
};

class BST {
private:
    int val{};
    BST *Left{};
    BST *Right{};
    
public:

    BST(int x) : val(x) {

    }

    void PrintInOrder() {
        if (Left)
            Left->PrintInOrder();
        cout << val << " ";
        if (Right)
            Right->PrintInOrder();
    }

    void insert(int data) {
        if (data < val) {
            if (!Left) {
                //No Left create it
                Left = new BST(data);
            } else {
                Left->insert(data);
            }
        } else if (data > val) {
            if (!Right) {
                //No Right create it
                Right = new BST(data);
            } else {
                Right->insert(data);
            }
        }
    }

    bool search(int tar) {
        if (tar == val)
            return true;
        if (tar < val)
            return Left && Left->search(tar);
        else
            return Right && Right->search(tar);
    }

    int min() {
        if (Left)
            return Left->min();
        return val;
    }

    int max() {
        if (Right)
            return Right->min();
        return val;
    }

    void find_pars(vector<BST *> &par, BST *cur, int data) {
        if (!cur)
            return;
        par.push_back(cur);
        if (cur->val == data)
            return;
        if (cur->val < data) {
            return find_pars(par, Right, data);
        } else {
            return find_pars(par, Left, data);
        }
    }

    BST *get_cur(vector<BST *> &par) {
        if (par.empty())
            return nullptr;
        BST *cur = par.back();
        par.pop_back();
        return cur;
    }

    pair<bool, int> successor(int data) {
        vector<BST *> par;
        find_pars(par, this, data);
        if (par.empty()) {
            return {false, -1};
        }
        BST *cur = get_cur(par);
        if (cur->Right) {
            return {true, cur->Right->min()};
        }
        BST *dad = get_cur(par);
        while (dad && dad->Right == cur) {
            cur = dad;
            dad = get_cur(par);
        }
        if (dad)
            return {true, dad->val};
        return {false, -1};
    }

    pair<bool, int> predecessor(int data) {
        vector<BST *> par;
        find_pars(par, this, data);
        if (par.empty()) {
            return {false, -1};
        }
        BST *cur = get_cur(par);
        if (cur->Left) {
            return {true, cur->Left->max()};
        }
        BST *dad = get_cur(par);
        while (dad && dad->Left == cur) {
            cur = dad;
            dad = get_cur(par);
        }
        if (dad)
            return {true, dad->val};
        return {false, -1};
    }

    BST *FindNode(int data) {
        if (val == data)
            return this;
        if (val < data) {
            if (Right)
                return Right->FindNode(data);
            return nullptr;
        } else {
            if (Left)
                return Left->FindNode(data);
            return nullptr;
        }
    }

    BST *min_node() {
        BST *cur = this;
        while (cur && cur->Left)
            cur = cur->Left;
        return cur;
    }

    void special_delete(BST *child) {
        val = child->val;
        Left = child->Left;
        Right = child->Right;
        delete child;
    }

    BST *DeleteNode(BST *root, int data) {
        if (!root)
            return nullptr;
        if (data < root->val) {
            root->Left = DeleteNode(root->Left, data);
        } else if (root->val < data) {
            root->Right = DeleteNode(root->Right, data);
        } else {
            if (!root->Left && !root->Right) {
                delete root;
                root = nullptr;
            } else if (!root->Right) {
                root->special_delete(root->Left);
            } else if (!root->Left) {
                root->special_delete(root->Right);
            } else {
                BST *cur = FindNode(root->Right->min());
                root->val = cur->val;
                root->Right = DeleteNode(root->Right, root->val);
            }
        }
        return root;
    }

    void DeleteData(int data) {
        if (data == val && !Left && !Right)
            return;
        DeleteNode(this, data);
    }
};

#endif //DS_BST_H
