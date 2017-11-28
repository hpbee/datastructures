#include<iostream>
#include"BST.h"
#include<queue>
using namespace std;
struct BST::node
{
	int data;
	node* left;
	node* right;
};
BST::BST()
{
	root=NULL;
}
//--------------------------------------
//Insert an integer x in the binary tree
void BST::insert(int x)
{
	if(root==NULL)
	{
		BST::node* n=new node;
		n->data=x;
		root=n;
		n->left=NULL;
		n->right=NULL;
	}
	else insert(x,root);
}

void BST::insert(int x,BST::node* temp)
{
	BST::node* n=new node;
	n->data=x;
	n->left=NULL;
	n->right=NULL;

	if (x<=temp->data)
	{
		if(temp->left==NULL) temp->left=n;
		else insert(x,temp->left);
	}

	else if(x>temp->data)
	{
		if(temp->right==NULL) temp->right=n;
		else insert(x,temp->right);
	}
}

//----------------------------------------------------------------------
//search function:
bool BST::search(int x)
{
	BST::node * temp=root;
	while(temp)
	{
		if(temp->data==x) {return true;}
		else if (x>(temp->data)) temp=temp->right;
		else temp=(temp->left);
	}
	return false;
}

//----------------------------------------------------------------------
//find height of tree
int BST::height()
{
	height(root);
}
int BST::height(node* temp)
{
	if(temp==NULL) return -1;
	return max(height(temp->left),height(temp->right))+1;
}

//----------------------------------------------------------------------
//Level order traversal of BST
void BST::LevelOrder()
{
	node* current;
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		current=Q.front();
		cout<<current->data<<" ";
		if (current->left)Q.push(current->left);
		if(current->right)Q.push(current->right);
		Q.pop();
	}
}
//----------------------------------------------------------------------
//preorder traversal of tree
void BST::preorder(node *current)
{
	if(current)
	{
		cout<<current->data<<" ";
		preorder(current->left);
		preorder(current->right);
	}
}
void BST::preorder()
{
	preorder(root);
}

//----------------------------------------------------------------------
//Inorder traversal of tree
void BST::inorder()
{
	inorder(root);
}
void BST::inorder(node* current)
{
	if(current)
	{
		inorder(current->left);
		cout<<current->data<<" ";
		inorder(current->right);
	}
}
//----------------------------------------------------------------------
//check if tree is binary search tree

bool BST::isBST()
{
	isBST2(root,-999,+999);
	//isBST(root);
}
bool BST::isBST(node*current)
{
	if(current==NULL) return true;
	if(islesser(current->left,current->data)&&
		isgreater(current->right,current->data)&&
		isBST(current->left)&&
		isBST(current->right) )
		return true;
	else return false;
}
bool BST::islesser(node* current,int x)
{
	if(current==NULL) return true;
	if(current->data<x &&
	 islesser(current->left,x)&&
	 islesser(current->right,x)
	 ) return true;
	else return false;

}
bool BST::isgreater(node* current,int x)
{
	if(current==NULL) return true;
	if(current->data>x &&
	 isgreater(current->left,x)&&
	 isgreater(current->right,x)
	 ) return true;
	else return false;
}
//The same effect as above can be acheived using
//two functions FindMin and FindMax for each subtree and
//checking if Findmax of a left subtree is lesser than
//value at currentNode and Findmin of a right subtree is greater
//than value at currentNode insteadd of the isgreater and islesser
//functions.Both have O(n2) time complexity.
//----------------------------------------------------------------------

//Efficient method to find if tree is BST
bool BST::isBST2(node* current,int MIN,int MAX)
{
	if(current==NULL) return true;
	if((current->data)>MIN && (current->data)<MAX)
		return (isBST2(current->left,MIN,current->data) && isBST2(current->right,current->data,MAX));
	return false;
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//method to delete an integer from tree
void BST::del(int x)
{
	del(NULL,root,x);
}
void BST::del(node* parent,node* current,int x)
{
    if (current==NULL) {cout<<"The element "<<x<<" doesn't exist.\n";return;}
    if (current->data<x) del(current,current->right,x);
    else if(current->data>x) del(current,current->left,x);
    else
    {
        //case:1:leaf nodes
        if (current->right==NULL && current->left==NULL)
        {
            if(parent==NULL)
            {
                delete root;
                root=NULL;
            }
            else if(parent->right)
            {
                if(parent->right->data==x) {delete current;parent->right=NULL;}
                else {delete current;parent->left=NULL;}
            }
        }
        //case2:only left node is present
        else if(current->right==NULL)
        {
            node* temp=current->left;
            if(parent==NULL) {delete root;root=temp;}
            else if(parent->left)
                {
                    if(parent->left->data==x) {delete current;parent->left=temp;}
                    else {delete current;parent->right=temp;}
                }
        }
        //case3:only right node is present
        else if(current->left==NULL)
        {
            node* temp=current->right;
            if(parent==NULL) {delete root;root=temp;}
            else if(parent->left)
            {
                if(parent->left->data==x) {delete current;parent->left=temp;}
                else {delete current;parent->right=temp;}
            }
        }
        //last case when current has both child nodes
        else
        {

            node* t_parent=current;
            node* temp=current->right;
			if (temp->left) {temp=temp->left;t_parent=t_parent->right;}
            while(temp->left) {temp=temp->left;t_parent=t_parent->left;}
            current->data=temp->data;
            del(t_parent,temp,temp->data);
        }
    }
}

//Display the tree in the same format of tree
void BST::display()
{
	display(root,0);
}
void BST::display(node* temp,int level)
{
	if(temp!=NULL)
	{
		display(temp->right,level+1);
		for(int i=0;i<=level;i++) cout<<"      ";
		cout<<temp->data;
		cout<<endl;
		display(temp->left,level+1);
	}
}

int main()
{
	BST boob;
	int n;
	boob.insert(8);
	boob.insert(10);
    boob.insert(4);
	boob.insert(13);
	boob.insert(9);
	boob.insert(16);
	boob.insert(6);
	boob.insert(22);
	boob.insert(2);
	if (boob.search(13)) cout<<"13 is present\n";
	if(boob.search(75)) cout<<"75 is present\n";
	if(!boob.search(76)) cout<<"76 is not present\n";
	cout<<"height of tree is "<<boob.height()<<endl;
	boob.display();
	cout<<"Level order traversal of tree: ";
	boob.LevelOrder();
	cout<<"\n preorder traversal: ";
	boob.preorder();
	cout<<"\n inorder traversal: ";
	boob.inorder();
	int x;
	cout<<"enter number to be deleted: ";
	cin>>x;
	boob.del(x);
	cout<<"\n tree after deleting "<<x<<" is :\n";
	boob.display();
	if(boob.isBST()) cout<<"\nThe tree is binary search tree\n";
	return 0;
}
