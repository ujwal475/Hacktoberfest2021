//Binary search tree
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<process.h>
//#include<chrono>
using namespace std;
//using namespace std::chrono;
//typedef std::chrono::high_resolution_clock getTime;

struct node
{
	int data;
	node *llink,*rlink;	
};
typedef node *NODE;

class bst
{
	public:NODE root;
	public:
		bst()
		{
			root=NULL;
		}
		int insert();
		int deleted();
		int search(int);
		int display(NODE,int);
		int inorder(NODE);
		int preorder(NODE);
		int postorder(NODE);
};
int bst::insert()
{
	NODE temp,pre,cur;
	int item;
	cout<<"Enter the item to insert"<<endl;
	cin>>item;
	temp=new node;
	temp->data=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
	{
		root=temp;
		return 0;
	}
	pre=NULL;
	cur=root;
	while(cur!=NULL)
	{
		pre=cur;
		if(item==cur->data)
		{
			cout<<"Duplicate items not allowed"<<endl;
			delete(temp);
			return 0;
		}
		if(item<cur->data)
		{
			cur=cur->llink;
		}
		else
		{
			cur=cur->rlink;
		}
	}
	if(item<pre->data)
	{
		cout<<"inserted";
		pre->llink=temp;
	}
	else
	{
		pre->rlink=temp;
	}
	return 0;
}
int bst::deleted()
{
	NODE cur,parent,suc,q;
	int item;
	cout<<"enter the item to be deleted"<<endl;
	cin>>item;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return 0;	
	}
	parent=NULL;
	cur=root;
	while(cur!=NULL)
	{
		if(item==cur->data)
			break;
		parent=cur;
		if(item<cur->data)
			cur=cur->llink;
		if(item>cur->data)
			cur=cur->rlink;
	}
	if(cur==NULL)
	{
		cout<<"Item not found in the tree"<<endl;
		return 0;
	}
	if(cur->llink==NULL && cur->rlink==NULL)
	{
		q=NULL;
//      OR
//		if(parent->llink==cur)
//		{
//			parent->llink=NULL;
//		}
//		else
//		{
//			parent->rlink=NULL;
//		}
//		delete cur;
//		return 0;
	}
	else if(cur->llink==NULL)
	{
		q=cur->rlink;
	}
	else if(cur->rlink==NULL)
	{
		q=cur->llink;
	}
	else
	{
		NODE suc=cur->rlink;
		while(suc->llink!=NULL)
			suc=suc->llink;
		suc->llink=cur->llink;
		q=cur->rlink;
	}
	if(parent==NULL)
		root=q;
	else if(parent->llink==cur)
	{
		parent->llink=q;
	}
	else
	{
		parent->rlink=q;
	}
	delete cur;
	return 0;
}
int bst::display(NODE root,int level)
{
	if(root==NULL)
	{
		return 0;
	}
	display(root->rlink,level+1);
	for(int i=0;i<level;i++)
	{
		cout<<"  "<<root->data<<endl;
		display(root->llink,level+1);
	}
	return 0;
}
int bst::inorder(NODE cur)
{
	if(cur!=NULL)
	{
		inorder(cur->llink);
		cout<<cur->data<<"  ";
		inorder(cur->rlink);
	}
return 0;
}

int bst::preorder(NODE cur)
{
	if(cur!=NULL)
	{
		cout<<cur->data<<"  ";
		preorder(cur->llink);
		preorder(cur->rlink);
	}
return 0;	
}
int bst::postorder(NODE cur)
{
	if(cur!=NULL)
	{
		postorder(cur->llink);
		postorder(cur->rlink);
		cout<<cur->data<<"  ";
	}
return 0;
}
int bst::search(int key)
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return 0;	
	}
	NODE cur=root;
	while(cur!=NULL && cur->data!=key)
	{
		cur=(key<cur->data)?cur->llink:cur->rlink;
	}
	if(cur==NULL)
	{
		cout<<"not found"<<endl;
		return 0;
	}
	cout<<"Found"<<endl;
	return 0;
}
int main()
{
	int ch;
	bst a;
	while(1)
	{
		cout<<endl<<"1.insert\n2.delete\n3.search\n4.preorder\n5.Inorder\n6.Postorder\n7.Exit\n";
		cout<<"Enter the choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					a.insert();
					break;	
				}
			case 2:
				{
					a.deleted();
					break;
				}
			case 3:
				{
					cout<<"Enter key: ";
					int key;
					cin>>key;
					a.search(key);
					break;
				}
			case 4:
				{
					a.display(a.root,1);
					a.preorder(a.root);
					break;
				}
			case 5:
				{
					a.display(a.root,1);
					a.inorder(a.root);
					break;
				}
			case 6:
				{
					a.display(a.root,1);
					a.postorder(a.root);
					break;
				}
			case 7:
				{
					exit(0);
				}
			defualt:cout<<"Invalid choice"<<endl;
		}
	}
	return 0;
}
