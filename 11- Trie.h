#ifndef DS_TRIE_H
#define DS_TRIE_H

class Trie {
private:
    static const int MaxChilds = 26;
    Trie *Childs[MaxChilds];
    bool isLeaf{};
public:
    Trie() {
        memset(Childs, 0, sizeof(Childs));
    }

    void Insert(string str, int idx) {
        if (idx == str.size()) {
            isLeaf = true;
        } else {
            if (Childs[str[idx] - 'a'] == nullptr) {
                Childs[str[idx] - 'a'] = new Trie();
            }
            Childs[str[idx] - 'a']->Insert(str, idx + 1);
        }
    }

    bool WordExist(string str, int idx = 0) {
        if (idx == str.size()) {
            return isLeaf;
        }
        if (Childs[str[idx] - 'a'] == nullptr) {
            return false;
        }
        return Childs[str[idx] - 'a']->WordExist(str, idx + 1);
    }

    bool PrefixExist(string str, int idx = 0) {
        if (idx == str.size()) {
            return true;
        }
        if (Childs[str[idx] - 'a'] == nullptr) {
            return false;
        }
        return Childs[str[idx] - 'a']->PrefixExist(str, idx + 1);
    }

};

#endif //DS_TRIE_H
