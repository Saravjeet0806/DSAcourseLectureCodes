#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0'); // empty character de diya
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assume word is in capslock
        int index = word[0] - 'A';
        TrieNode *child;
        // present , aage badho
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent create node and then aage badho
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL) // agar present hai to aage badho
        {
            child = root->children[index];
        }
        else
        { // absent
            return false;
        }

        // recursion call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
    bool removeUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Finding index through mapping
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // Present
            child = root->children[index];
        }
        else
        {
            // Absent
            return false;
        }

        return removeUtil(child, word.substr(1));
    }

    bool remove(string word)
    {
        return removeUtil(root, word);
    }

    bool eraseUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
                delete root;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Finding index through mapping
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // Present
            child = root->children[index];
        }
        else
        {
            // Absent
            return false;
        }

        bool ans = eraseUtil(child, word.substr(1));
        delete child;
        return ans;
    }

    bool erase(string word)
    {
        return eraseUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    // t->insertWord("abcd");
    // cout<<"present or not"<<t->searchWord("abcde")<<endl;   //0 false
    //  cout<<"present or not"<<t->searchWord("abcd")<<endl;   //1 true

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout << "present or not  " << t->searchWord("TIM") << endl;
    return 0;
}