#ifndef AHO_CORASICK
#define AHO_CORASICK

#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct TrieNode
{
    std::map<char, TrieNode *> children;
    TrieNode *fail;
    std::vector<int> output;

    TrieNode() : fail(nullptr) {}
};

class AhoCorasick
{
public:
    AhoCorasick()
    {
        root = new TrieNode();
    }

    void insertPattern(const std::string &pattern, int index)
    {
        TrieNode *current = root;

        for (char c : pattern)
        {
            if (!current->children[c])
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }

        current->output.push_back(index);
    }

    void build()
    {
        std::queue<TrieNode *> q;

        // Set failure links for the root's children
        for (auto &pair : root->children)
        {
            pair.second->fail = root;
            q.push(pair.second);
        }

        // Breadth-first traversal to set failure links
        while (!q.empty())
        {
            TrieNode *current = q.front();
            q.pop();

            for (auto &pair : current->children)
            {
                char key = pair.first;
                TrieNode *child = pair.second;

                q.push(child);

                TrieNode *failNode = current->fail;
                while (failNode && !failNode->children[key])
                {
                    failNode = failNode->fail;
                }

                child->fail = failNode ? failNode->children[key] : root;

                // Merge output lists
                child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());
            }
        }
    }

    std::vector<int> &search_for_patterns(const std::string &text)
    {
        TrieNode *current = root;

        for (char c : text)
        {
            while (current && !current->children[c])
            {
                current = current->fail;
            }

            if (current)
            {
                current = current->children[c];
                add_pattern_match(current);
            }
            else
            {
                current = root;
            }
        }
        return pattern_matches_positions;
    }

private:
    TrieNode *root;

    std::vector<int> pattern_matches_positions;

    void add_pattern_match(TrieNode *node)
    {
        for (int index : node->output)
        {
            pattern_matches_positions.push_back(index);
        }
    }
};

#endif // AHO_CORASICK