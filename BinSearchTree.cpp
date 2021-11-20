struct Node {
  int value = -1;
  Node* left = nullptr;
  Node* right = nullptr;
};

struct BinTree {
  Node* root = nullptr;
};

void Insert(Node*& node, int value) {
  if (node == nullptr) {
    node = new Node{value};
    return;
  }
  if (value == node->value) {
    return;
  }
  if (value >= node->value) {
    Insert(node->right, value);
  } else {
    Insert(node->left, value);
  }
}

void Insert(BinTree& tree, int value) {
  Insert(tree.root, value);
}

void OrderWalk(Node* node) {
  if (node == nullptr) {
    return;
  }
  OrderWalk(node->left);
  cout << node->value << " ";
  OrderWalk(node->right);
}

void OrderWalk(BinTree& tree, int& counter) {
  OrderWalk(tree.root, counter);
 }

void Clear(Node* node) {
  if (node == nullptr) {
    return;
  }
  Clear(node->left);
  Clear(node->right);
  delete node;
}

void Clear(BinTree& tree) { 
  Clear(tree.root);
}

int SearchHeight(Node* temp) {
  if (temp == nullptr) {
    return 0;
  }
  if (temp->left == nullptr && temp->right == nullptr) {
    return 0;
  }
  int max1 = 0;
  int max2 = 0;
  if (temp->left != nullptr) {
    max1 = 1 + SearchHeight(temp->left);
  }
  if (temp->right != nullptr) {
    max2 = 1 + SearchHeight(temp->right);
  }
  return std::max(max1, max2);
}
