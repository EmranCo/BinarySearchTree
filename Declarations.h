#include<string>
#include<Windows.h>

using namespace std; 


struct Node
{
	double data;
	Node *Left , *Right;
    Node()                             {     Left=NULL;    Right=NULL;          }
	Node(double d)                   {data=d;     Left=NULL;    Right=NULL;   }
    bool IsParent()             {return (this->Left!=NULL&&this->Right!=NULL); }
    bool IsLeaf()               {return (this->Left==NULL&&this->Right==NULL); }
	bool IsLeftSubTree()        {return (this->Left!=NULL&&this->Right==NULL); }
	bool IsRightSubTree()       {return (this->Right!=NULL&&this->Left==NULL); }
	double getdata() { return this->data; }
};

	
	class TREE_LL
{
	Node *Root;  
	bool isempty()                     { return Root==NULL; }
	Node* MakeNode(double d)         { Node* T=new Node(d); return T;	}
	int IsFullBTree(Node* T);
	int IsCompleteBTree(Node *T);
	int IsSkewedBTree(Node *T);
	int IsBalanced(Node *T);
	bool IsRoot(Node *T) { return (this->Root==T); }
	

	

public :
	int Height(Node *T);
	int Leafs(Node *T);
	int SubTrees(Node *T);
	int Level(Node *T);
	
    TREE_LL (){ Root=NULL; }
    TREE_LL(double data);	
    int SizeIs(Node* T );
    Node *getroot() { return this->Root; }
    void GetNode(double data ,Node *var);
    void Display(Node *T,int c);
    void LEVEL_ORDER(Node *T);
    void FindNode( double data , Node * snode);
    void AllDisplay(Node *T);
    void CheckTree(Node* T);
    Node* Get_Max(Node *T);
    Node* Get_Min(Node *T);
    int Delete(Node *,double);
    void BTreeStatues();

	
		
}; // END OF CLASS TREE

void Draw(string x,char t[]);
void Draw(double x,char t[]);
