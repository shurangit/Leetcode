/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> store;
public:
    BSTIterator(TreeNode *root) {
      left(root);  
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(store.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* t=store.top();
        store.pop();
        if(t->right) left(t->right);
        return t->val;
    }
    void left(TreeNode* root){
        TreeNode* tmp=root;
        while(tmp){
            store.push(tmp);
            tmp=tmp->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */