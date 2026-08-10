class BST {
private:
    struct TreeNode {
        int key;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr) return new TreeNode(key);
        if (key > root->key)
            root->right = insert(root->right, key);
        else if (key < root->key)
            root->left = insert(root->left, key);
        else
            return root; // Đã xử lý đúng phần tử trùng
        
        return root; // Thêm dòng này để đảm bảo mọi nhánh đều return (tránh compiler warning)
    }

    // để tìm node bên phải có giá trị nhỏ nhát thì chèn root->right vào
    // rồi cho nó chạy xuống hết bên trái
    TreeNode* minValueNode(TreeNode* root) {
        while (root->left) root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // trường hợp có nhiều nhất 1 con, có 1 con hoặc 0 con
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // trường hợp có 2 con
            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    bool searchNode(TreeNode* root, int key) {
        if (root == nullptr) return false;
        if (root->key == key) return true;
        else if (key < root->key)
            return searchNode(root->left, key);
        else
            return searchNode(root->right, key);
    }

    TreeNode* root;

public:
    BST() : root(nullptr) {}

    void add(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool contains(int key) {
        return searchNode(root, key); // SỬA LỖI Ở ĐÂY: Truyền thêm 'key' vào
    }
};

class MyHashSet {
private:
    const int size = 10000;
    vector<BST> buckets;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashSet() : buckets(size) {}

    void add(int key) {
        int index = hash(key);
        if (!contains(key))
            buckets[index].add(key);
    }

    void remove(int key) {
        int index = hash(key);
        buckets[index].remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        return buckets[index].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */