#include <iostream>

using namespace std;


struct node {
	int value;
	node* left;
	node* right;
};

class btree {
public:
	btree();
	~btree();

	void insert(int key);
	node* search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
	void sum_tree();
	void isBTSUntil();

private:
	void destroy_tree(node* leaf);
	void insert(int key, node* leaf);
	node* search(int key, node* leaf);
	void inorder_print(node* leaf);
	void postorder_print(node* leaf);
	void preorder_print(node* leaf);
	int sum_tree(node* leaf);
	int isBTSUntil(node* leaf, int min, int max);

	node* root;
};


btree::btree() {
	root = NULL;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node* leaf) {

	if (key < leaf->value) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->value) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insert(int key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node* btree::search(int key, node* leaf) {
	if (leaf != NULL) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

node* btree::search(int key) {
	return search(key, root);
}

void btree::destroy_tree() {
	destroy_tree(root);
}

void btree::inorder_print() {
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print() {
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::isBTSUntil()
{
	if (isBTSUntil(root, INT_MIN, INT_MAX)) {
		cout << "Is BST";
	}
	else {
		cout << "Not a BST";
	}
}

int btree::isBTSUntil(node* leaf, int min, int max)
{
	if (leaf == NULL) {
		return 1;
	}
	if (leaf->value < min || leaf->value > max) {
		return 0;
	}
	return isBTSUntil(leaf->left,min, leaf->value-1) && isBTSUntil(leaf-> right, leaf ->value+1, max);
}

void btree::preorder_print() {
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node* leaf) {
	if (leaf != NULL) {
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

void btree::sum_tree() {
	int sum = root->value;
	cout << sum_tree(root);
}

int btree::sum_tree(node* leaf) {
	if (leaf == NULL) {
		
		return 0;
	}
	return (leaf->value + sum_tree(leaf->left)+ sum_tree(leaf->right));
}

int main() {

	//btree tree;
	btree* tree = new btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);


	tree->isBTSUntil();
	

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();
	tree->sum_tree();

	delete tree;

}