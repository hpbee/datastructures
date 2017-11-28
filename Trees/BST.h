#ifndef BST_H
#define BST_H
class BST
{
	public:
		BST();
		struct node;
		void insert(int x);
		bool search(int );
		int height();
		void LevelOrder();
		void preorder();
		void inorder();
		bool isBST();
		void del(int x);
		void display();
	private:
		node* root;
	//utility functions.
		void insert(int x,node* temp);
		int height(node*);
		void preorder(node*);
		void inorder(node*);
		bool isBST(node * );
		bool isBST2(node*,int,int);
		bool islesser(node* ,int);
		bool isgreater(node* ,int);
		void del(node* parent,node* current,int x);
		void display(node* ,int);
};
#endif // BST_H
