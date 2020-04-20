
// MADE BY VIKRANT JUDGE
// CSE BRANCH
// ROLL NO.: 11911016
// DATA STRUCTURE LAB WORK
//IT IS VALID FOR (1,2,3,4,5,6) OR ANY OTHER ENTRY

#include<stdio.h>
#include<stdlib.h>

 
typedef struct node
{
	int data;
	struct node *left,*right;   
	int H; //used to store height of each node
}node;

int height(node *T)
{
	int A,B;
	if(T==NULL)
		return(0);
	
	if(T->left==NULL)
		A=0;
	else
		A=1+T->left->H;
		
	if(T->right==NULL)
		B=0;
	else
		B=1+T->right->H;
	
	if(A>B)
		return(A);
	else
	      return(B);
}

node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->H=height(x);
	y->H=height(y);
	return(y);
}
node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->H=height(x);
	y->H=height(y);
	
	return(y);
}

node * RR(node *T)
{
	T=rotateleft(T);
    printf("RR rotation done\n");
	return(T);
}
 
node * LL(node *T)
{
	T=rotateright(T);
    printf("LL rotation done\n");
	return(T);
}

node * LR(node *T)
{
	T->left=rotateleft(T->left);
    printf("RL rotation done\n");
	T=rotateright(T);
    printf("RR rotation done\n");
	
	return(T);
}

node * RL(node *T)
{
	T->right=rotateright(T->right);
    printf("RR rotation done\n");
	T=rotateleft(T);
    printf("RL rotation done\n");
	return(T);
}
 
int BF(node *T)
{
	int A,B;
	if(T==NULL)
		return(0);
 
	if(T->left==NULL)
		A=0;
	else
		A=1+T->left->H;
 
	if(T->right==NULL)
		B=0;
	else
		A=1+T->right->H; 
	return(A-B);
}

void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d)",T->data,BF(T));
		inorder(T->right);
	}
}

node * insert(node *T,int x)
{
	if(T==NULL)
	{
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=insert(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);     //RR means right right imbalance,,,so we are performing right right rotation
				else
					T=RL(T);    //RR means right left imbalance,,,so we are performing right left rotation
		}
		else
			if(x<T->data)   //insert in left subtree
			{
				T->left=insert(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);    //RR means left left imbalance,,,so we are performing left left rotation
					else
						T=LR(T);    //RR means left right imbalance,,,so we are performing left right rotation
			}
		
		T->H=height(T);
		
		return(T);
}

int main()
{
	node *root=NULL;
	int x,n,i,op;
	do
	{
		printf("\n1)Create:");
		printf("\n2)Print:");
		printf("\n3)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;
			
			case 2: printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;			
		}
	}while(op!=3);
	
	return 0;
}