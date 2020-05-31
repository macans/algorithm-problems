/**
 * @authors: https://github.com/macans
 * @date: 2020-05-31 14:06:25
 */
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec1 {

private:
    static const int inf = 0x3f3f3f3f;
    int getVal(string &s, int &p){
        int res = 0;
        if(p > s.length() - 1) return inf;
        if(s[p] == 'n'){
            p += 4;
            return inf;
        }
        int neg = 1;
        while(s[p] != ',' && s[p] != ']'){
            if(s[p] == '-'){
                neg = -1;
                ++p;
                continue;
            }
            res = res * 10 + s[p++] - '0';
        }
        cout << res * neg << " " << p << "\n";
        return res * neg;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        string ans;
        TreeNode* cur = root;
        ans.append("[" + to_string(cur->val));
        queue<TreeNode*> q;
        q.push(cur);
        int pos = ans.size();
        while(!q.empty()){
            cur = q.front(); 
            q.pop();
            if(cur->left != NULL){
                ans.append("," + to_string(cur->left->val));
                pos = ans.size();
                q.push(cur->left);
            }
            else {
                ans.append(",null");
            }
            if(cur->right != NULL){
                ans.append("," + to_string(cur->right->val));
                pos = ans.size();               
                q.push(cur->right);
            }
            else {
                ans.append(",null");
            }
        }
        ans.resize(pos);
        ans.append("]");
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0, x;
        queue<TreeNode*> q;
        TreeNode* head = nullptr;
        while(p < data.length() - 2){
            x = getVal(data, ++p);
            if(q.empty()){
                head = new TreeNode(x);
                q.push(head);
                continue;
            }
            TreeNode* cur = q.front();
            q.pop();
            cur->left = x == inf ? nullptr : new TreeNode(x);
            x = getVal(data, ++p);
            cur->right = x == inf ? nullptr : new TreeNode(x);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            //break;
        }
        return head;
    }
};

class Codec2 {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};


int main(){

}
