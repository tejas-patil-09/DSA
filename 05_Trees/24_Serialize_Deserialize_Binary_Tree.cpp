/*
Problem:
Convert a binary tree into a string and reconstruct
the same tree from that string.

Input:
A binary tree; later, its serialized string.

Output:
Serialized string and reconstructed tree.

Approach:
Use preorder traversal.
- Store node values.
- Store "#" for null children.
- During deserialization, read tokens in order
  and recursively rebuild the tree.

TC: O(N) for serialize and deserialize
SC: O(N)

Key Insight:
Null markers preserve the tree's structure,
including missing children.
==========================================================
*/

class Codec {
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(
        stringstream& ss
    ) {
        string value;
        ss >> value;

        if (value == "#")
            return nullptr;

        TreeNode* root =
            new TreeNode(stoi(value));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};