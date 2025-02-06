class Solution {
public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preIndex = 0;
        return buildTreeHelper(inorder, preorder, preIndex, 0, inorder.size() - 1);
    }

private:
    Node* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        Node* root = new Node(preorder[preIndex++]);

        if (inStart == inEnd) {
            return root;
        }

        int inIndex = search(inorder, inStart, inEnd, root->data);

        root->left = buildTreeHelper(inorder, preorder, preIndex, inStart, inIndex - 1);
        root->right = buildTreeHelper(inorder, preorder, preIndex, inIndex + 1, inEnd);

        return root;
    }

    int search(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1; // Should not happen if inorder and preorder are valid
    }
};
