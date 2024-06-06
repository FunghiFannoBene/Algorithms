//Handcopied vers

#include <iostream>

struct BinTree
{
	int value;
	BinTree *left;
	BinTree *right;
	BinTree(int val): value(val), left(nullptr), right(nullptr) {}
};

class BST
{
	public:
	BinTree *root;
	BST(): root(nullptr){}

	void insert(int val){root = insertRec(root, val);}
	bool search(int val){return searchRec(root, val);}
	void inorder(){inorderRec(root); std::cout << std::endl;}

	private:
		BinTree* insertRec(BinTree *root, int val)
		{
			if(!root) return new BinTree(val);
			if(val < root->value)
				root->left = insertRec(root->left, val);
			else if(val > root->value)
				root->right = insertRec(root->right, val);
			return(root);
		}


		bool searchRec(BinTree *root, int val)
		{
			if(!root) return false;
			if(root->value == val)
				return true;
			if(val < root->value)
				return searchRec(root->left, val);
			return(searchRec(root->right, val));
		}

		void inorderRec(BinTree *root)
		{
			if(!root) return;
			inorderRec(root->left);
			std::cout << root->value << " ";
			inorderRec(root->right);
		}

};

int main()
{
	BST bst;
	bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inorder();


    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << std::endl;
	return(0);
}