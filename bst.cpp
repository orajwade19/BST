/*
 * bst.cpp
 *
 *  Created on: 29-Jan-2018
 *      Author: student
 */
#include<iostream>
#include<algorithm>
using std::cout;
using std::cin;
using std::max;

class node {
private:
	int data;
	node* left;
	node* right;
	friend class bst;
public:
	void set(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	void display()
	{
		cout<<data<<"  ";
	}
};

class queue
{
	private:
		node* arrq[30];
		int front,back;
	public:
		queue()
	{
			front=0;
			back=0;
	}
		void push(node* pushed)
		{
			arrq[back++] = pushed;
		}

		node* delet()
		{
			return arrq[front++];
		}

		int isEmpty()
		{
			if(front==back)
				return 1;
			return 0;
		}
};
class stack
{
private:
	node* arr[30];
	int top;
public:
	stack()
{
		top=-1;
}
	void push(node* q)
	{
		arr[++top] = q;
	}
	node* pop()
	{
		return arr[top--];
	}
	int isEmpty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
};
class bst {
private:
	node* root;
public:
	bst() {
		root = NULL;
	}
	void nrCreate() {
		//Accept root
		root = new node;
		cout << "\nEnter A Number: ";
		int temp;
		cin >> temp;
		root->set(temp);
		//root accepted
		cout << "\nDo you want to continue? ";
		char choice = 'n';
		cin >> choice;
		while (choice == 'y' || choice == 'Y') {
			//loop for accepting multiple numbers
			cout << "\nEnter A Number: ";
			cin >> temp;
			insert(temp);
			cout<<"\nDo you want to continue adding numbers? ";
			cin>>choice;
		}
	}
	void display_inorder()
	{
		display_inorder(root);
	}
	void display_inorder(node* current)
	{
		if(current->left!=NULL)
			display_inorder(current->left);
		current->display();
		if(current->right!=NULL)
			display_inorder(current->right);
	}
	void insert()
	{
		cout<<"\nEnter number to be inserted: ";
		int temp;
		cin>>temp;
		insert(temp);
	}
	void insert(int currentNumber)
	{
		node* current = root;
		while (true) {
			if (current->data > currentNumber) {
				if (current->left == NULL) {
					current->left = new node;
					current->left->set(currentNumber);
					break;
				}
				current = current->left;
			}
			if (current->data < currentNumber) {
				if (current->right == NULL) {
					current->right = new node;
					current->right->set(currentNumber);
					break;
				}
				current = current->right;
			}
		}
	}
	void numberOfNodes()
	{
		cout<<"\nNumber of nodes in the longest path is: "<<numberOfNodes(root);
	}
	int numberOfNodes(node* current)
	{
		if(current->left!=NULL && current->right==NULL)
		{
			return numberOfNodes(current->left)+1;
		}
		if(current->left==NULL && current->right!=NULL)
		{
			return numberOfNodes(current->right)+1;
		}
		if(current->left==NULL && current->right==NULL)
		{
			return 1;
		}
		return max(numberOfNodes(current->left),numberOfNodes(current->right))+1;
	}
	node* minimum(node* current)
	{
		if(current->left!=NULL)
			return minimum(current->left);
		return current;
	}
	void minimum()
	{
		node* least = minimum(root);
		cout<<"\nThe smallest number is: ";
		least->display();
	}
	void search()
	{
		cout<<"\nEnter search term: ";
		int temp;
		cin>>temp;
		if(search(root,temp))
			cout<<"\nNumber found!";
		else
			cout<<"\nNumber not found.";
	}
	int search(node* current,int searched)
	{
		if(current->data==searched)
			return 1;
		if(current->data<searched)
		{
			if(current->right==NULL)
				return 0;
			return search(current->right,searched);
		}
		if(current->data>searched)
		{
			if(current->left==NULL)
				return 0;
			return search(current->left,searched);
		}
		return -1;
	}
	void swap(node* current)
	{
		node* temp = current->right;
		current->right = current->left;
		current->left = temp;
		if(current->left!=NULL)
			swap(current->left);
		if(current->right!=NULL)
			swap(current->right);
	}
	void swap()
	{
		swap(root);
	}
	void bfs()
	{
		queue p,q;
		p.push(root);
		while(!p.isEmpty())
		{
			while(!p.isEmpty())
			{
			 node* temp = p.delet();
			 temp->display();
			 if(temp->left!=NULL)
				 q.push(temp->left);
			 if(temp->right!=NULL)
				 q.push(temp->right);
			}
			cout<<"\n";
			while(!q.isEmpty())
			{
				p.push(q.delet());
			}
		}
	}
	void nrSwap()
	{
		stack s;
		node* temp = root;
		s.push(temp);
		while(!s.isEmpty())
		{
			node* temp = s.pop();
			node* temp2 = temp->right;
			if(temp->left!=NULL)
				s.push(temp->left);
			if(temp->right!=NULL)
				s.push(temp->right);
			temp->right = temp->left;
			temp->left = temp2;
		}
	}
	int nrSearch(int searched)
	{
		node* temp = root;
		while(temp!=NULL)
		{
			if(temp->data==searched)
				return 1;
			if(searched<temp->data)
				temp = temp->left;
			if(searched>temp->data)
				temp = temp->right;
		}
		return 0;
	}
};

int main()
{
	bst k;
	int choice;
	int searched;
	do
	{
		cout<<"\n1.Create BST\n2.Insert number\n3.Number of nodes in the longest path\n4.Minimum data value in tree\n5.Swap left and right pointers non-recursively\n6.Search recursively\n7.BFS\n8.Display\n9.Swap left and right pointers recursively\n10.Search non-recursively\n11.Exit";
		cin>>choice;
		switch(choice)
		{
		case 1:
			k.nrCreate();
			break;
		case 2:
			k.insert();
			break;
		case 3:
			k.numberOfNodes();
			break;
		case 4:
			k.minimum();
			break;
		case 5:
			k.nrSwap();
			break;
		case 6:
			k.search();
			break;
		case 7:
			k.bfs();
			break;
		case 8:
			k.display_inorder();
			break;
		case 9:
			k.swap();
			break;
		case 10:
			cout<<"\nEnter Number To Be Searched: ";
			cin>>searched;
			searched = k.nrSearch(searched);
			if(searched==1)
				cout<<"\nNumber Found!";
			else
				cout<<"\nNumber not found.";
			break;
		case 11:
			break;
		default:
			cout<<"\nEntered choice must be in the 1-7 range.";
			break;
		}
	}while(choice!=11);
}

