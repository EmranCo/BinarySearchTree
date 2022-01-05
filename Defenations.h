#include"Declarations.h"
#include<iostream>
#include<conio.h>
#define Equal(a,b)(a==b?0:-1)
#define MAX(a,b)(a>b?a:b)
using namespace std; 


//=========================================================================================

    TREE_LL::TREE_LL(DataType data) 
	{
	  Root=new Node(data);
	} /////////////////////

    int TREE_LL::SizeIs(Node* T ) 
	 {
        if (T==NULL) return 0;
        return (1+SizeIs(T->Left)+SizeIs(T->Right));  
     }
     
////////////////////// TREE STATEMENTS ///////////////////////////////
                              
     int TREE_LL::IsFullBTree(Node* T)					  
   {
   	if (T==NULL) return 1;
   	return (Equal(IsFullBTree(T->Left),IsFullBTree(T->Right)));
   	
	}
	
	int TREE_LL::IsCompleteBTree(Node *T)
	{
		if (T==NULL) return -1;
   	return ((1+IsCompleteBTree(T->Left))-(1+IsCompleteBTree(T->Right)));
		
	}	
		
	int TREE_LL::IsSkewedBTree(Node *T)
	{
		if (isempty()) return 1;
		if (T->IsLeaf()) return 1;
		if (T==NULL) return 0;
		
	if (Root->Left==NULL) return (1+IsSkewedBTree(T->Right));
	else if (Root->Right==NULL) return (IsSkewedBTree(T->Left));
	else return 0;	
		
	}
	
	int TREE_LL::IsBalanced(Node *T)
	{
		if (isempty()) return 10;
		if (T==NULL) return 0;
		if (SizeIs(T->Left)==SizeIs(T->Right)) return 1;
		return (IsBalanced(T->Left)-IsBalanced(T->Right));
	}
	
//////////////////////////////////////////////////
	 
     void TREE_LL::GetNode(DataType data ,Node *var)
{
	if (isempty())                 {  Root =MakeNode(data); return; }

     if (data==var->data)           {  cout<<"THE SAME DATA WITH DATA OF ROOT  ? ? ?\a"; return; }
	 
	 else if (data>var->data)
  {
	  if (var->Right==NULL)   {   var->Right=MakeNode(data);  return;  }
   
    GetNode(data ,var->Right); return;
  }

    else 
  {
 	if  (var->Left==NULL)   {   var->Left=MakeNode(data);  return;  }
   
 GetNode(data ,var->Left); return;
  }	

}   /////////////////////////////

///////////////////////////////////////////////

        void TREE_LL::CheckTree(Node* T)
    {
    First:
	    system("cls");	
        cout<<">>>>>> INPUT CHOICE <<<<<<";cout<<"\n\n\n\n";
        cout<<"1- IS FULL BINARY TREE ? ";
        cout<<"2- IS BALANCED BINARY TREE ? ";
        cout<<"3- IS COMPLETE BINARY TREE ? ";
        cout<<"4- IS SKEWED BINARY TREE  ? ";
    
        char ch=_getche();  system("cls");
        
        for (int i=0; i<10; i++) cout<<'\n';
        
          switch (ch)
      {
        case '1' : {        if (IsFullBTree(T)==0)
                       cout<<" YES SIRE  THE TREE NOW IS FULL BINARY TREE ";
	                       else cout<<" NO SIRE  THE TREE NOW IS NOT FULL BINARY TREE \a\a "; 
						   break;	}	
	                       
        case '2' : {      int X=IsBalanced(T);
                          if (X==0||X==1||X==-1)
                     cout<<" YES SIRE  THE TREE NOW IS BALANCED BINARY TREE ";
	            else cout<<" NO SIRE  THE TREE NOW IS NOT BALANCED BINARY TREE \a\a ";		break;	}
					   	
		case '3' : {        if (IsCompleteBTree(T)==0)
                       cout<<" YES SIRE  THE TREE NOW IS COMPELETE BINARY TREE ";
	                       else cout<<" NO SIRE  THE TREE NOW IS NOT COMPELETE BINARY TREE \a\a ";  break;	}
	                       
		case '4' : {                if (IsSkewedBTree(T)==SizeIs(T))
                       cout<<" YES SIRE  THE TREE NOW IS SKEWED BINARY TREE ";
	                       else cout<<" NO SIRE  THE TREE NOW IS NOT SKEWED BINARY TREE \a\a ";  break;	}
						   		
        default : { cout<<"Invalid choise !!";	goto First; }
		}
        
    _getche();
	}


//================= To DISPLAY TREE IN OTHER WAYS ========================= 


		void TREE_LL::Display(Node *T , int choice)
    {
		if (isempty()) 
	 { 
		cout<<" \aTREE IS EMPTY ! ! ! \a\a";
		return; 
	 }
	 
	   if (T==NULL) return;  
	   
	    if (choice==1) {  Display(T->Left,1); 
                      cout<<T->data;
                      cout<<T->Right,1);	 }
                      
       else if (choice==2)  {  cout<<T->data;
	                  Display(T->Left,2);
	                  Display(T->Right,2);	 }
	                  
	   else if (choice==3)  {  Display(T->Left,3);
		              Display(T->Right,3);
		              cout<<T->data;	 }
		
	   	              
	   else cout<<"\a\a\a\a\n\n\n EROOOOOOOOOOOOOOOOOOOOOOOR \n\n";
	 
	   } 

	

//============================= DISPLAY NODES ======================================================
	
	     void TREE_LL::AllDisplay(Node *T)
    {
    First:	
    	cout<<"\n\n\n";
        cout<<"<1> < Left Root Right > < In Order > \n";
	    cout<<"<2> < Root Left Right > < Pre Order > \n";
	    cout<<"<3> < Left Right Root > < Post Order > \n";

    char x=_getche(); system("cls"); char ch=x; cout<<"\n\n\n";
    switch(ch)
    {
    	case '1' : { cout<<"<1> < Left Root Right > < In Order > "; Display(T,1); break; }
    	case '2' : { cout<<"<2> < Root Left Right > < Pre Order > "; Display(T,2); break;  }
    	case '3' : { cout<<"<3> < Left Right Root > < Post Order > "; Display(T,3); break;  }
    	
    default : {  goto First; }
    	
	}
	
     }
	 

	
//=============================FIND NODE ======================================================
	
        void TREE_LL::FindNode( DataType data , Node * snode)
	{ 
	    system("cls"); for (int i=0; i<10; i++) cout<<'\n';

        if (isempty())  {  cout<<" EMPTY TREE  ! ! !\a\a\a ";  return; }

	    if (data==Root->data)  { cout<<" IT,S ROOT DATA "; return; }
	    
	    if (data==snode->data) {	cout<<"  THIS  DATA IS IN THE TREE "; return; }

        else if (data>snode->data)
      {
	     if (snode->Right==NULL)  
	   {   
         cout<<" SORRY \a\a... THIS DATA NOT IN THE TREE  ! ! ! ";
         return;
	   }
          FindNode(data ,snode->Right); return;
	  }

        else
	  {
 	     if (snode->Left==NULL)  
	   {   
         cout<<" SORRY \a\a... THIS DATA NOT IN THE TREE  ! ! ! ";
         return;
	   }
           FindNode(data ,snode->Left); return;
	  }	

    }

//============================== FIND MAX & MIN VALUE =====================================================

       Node* TREE_LL::Get_Max(Node *T)
   {
   	  if (isempty()) return NULL;
   	
   	if (T->Right==NULL) return T;
   	
   	  return (Get_Max(T->Right));
   	
   }
   
       Node* TREE_LL::Get_Min(Node *T)
   {
   	  if (isempty()) return NULL;
   	
   	  if (T->Left==NULL) return T;
   	
   	  return(Get_Max(T->Left));
   	
   }
   
//============================================ DELET ITEAM FROM BTREE  ========================================
   
   int  TREE_LL::Delete(Node *T,DataType D)
{ 

       system("cls");  
      for (int i=0; i<=27; i++)cout<<"\n";
	
	if (T==NULL)  {    cout<<"\a\a EMPTY TREE  ! ! ! "; return 0; }
	
	
	Node *Stack[SizeIs(T)];  int Top=-1; char Move='N';
	
	
	         while(T!=NULL)
	{
		
		 if (D>T->data) { Stack[++Top]=T; Move='R'; T=T->Right; }
	else if (D<T->data) { Stack[++Top]=T; Move='L'; T=T->Left; }
	
	else {
		
		    if (T->IsLeaf())         {      if (IsRoot(T)) { Root=NULL; delete Root; return 1; }
			                                if (Move=='L') Stack[Top--]->Left=NULL;
		                               else if (Move=='R') Stack[Top--]->Right=NULL;
							                               delete T; return 1;       }
							                      
	   else if (T->IsLeftSubTree())  {      if (IsRoot(T)) { Root=Root->Left; delete T; return 1; }
	                                        if (Move=='L')  Stack[Top--]->Left=T->Left;  
		                               else if (Move=='R')  Stack[Top--]->Right=T->Left;
							                   T->Left=NULL;  delete T;   return 1;       } 
							                
	   else if (T->IsRightSubTree()) {      if (IsRoot(T)) { Root=Root->Right; delete T;  return 1; }
	                                        if (Move=='L')  Stack[Top--]->Left=T->Right;  
		                               else if (Move=='R')  Stack[Top--]->Right=T->Right; 
							                              T->Right=NULL;  delete T;  return 1;       }
							                
	   else  {
	   	    
					Stack[++Top]=T; T=T->Left; // to tack the left subTree
	         
			  if (T->Right==NULL)  {  Node *X=Stack[Top--]; T->Right=X->Right; 
			                         if (Move=='L') Stack[Top]->Left=T;
									 else if (Move=='R') Stack[Top]->Right=T;
									 else if (Move=='N')Root=T;   X->Left=X->Right=NULL; delete X; return 1; }   
			 else {
			 
			 	Stack[++Top]=T;
			 	Node *Temp=Get_Max(Stack[Top--]);
			 	Stack[Top]->data=Temp->data; 
			    if (Delete(T,Temp->data)!=1) {cout<<"\a\a\a\a  ERRRRRRROOOOOOOOOOOOOORRRR\n\n"; return -1;  }
			    Temp=T=NULL;
			 	return 1;
			 	
			 	
			 }      
	   	
	   	
	      }
	     
		
	  }
	  
	}
	 if (T==NULL) {  cout<<" ITEAM NOT FOUND \a\a ! ! ! "; return -1; }
	
   }
   
   
   
   
   
//============================================ STATUESES OF BTREE  ========================================

int TREE_LL::Height(Node *T)
{
	if (T==NULL) return -1;
	
return (MAX(1+Height(T->Left),(1+Height(T->Right))));
	
}
////////////////////////////////////

int TREE_LL::Leafs(Node *T)
{
	
	if (T==NULL) return 0;
	if (T->IsLeaf()) return 1;
return (Leafs(T->Left)+Leafs(T->Right));

}
///////////////////////////////////

int TREE_LL::SubTrees(Node *T)
{
	if (T==NULL) return 0;
	if(T->IsLeaf()) return 1;
	
	return (SubTrees(T->Left)+SubTrees(T->Right));
}

/////////////////////////////////////

int TREE_LL::Level(Node *T)
{
	if (T==NULL) return 0;
	
return (MAX(1+Level(T->Left),1+Level(T->Right)));	
}

///////////////////////////////////////////////

   void TREE_LL::BTreeStatues()
{
	   cout<<" TREE HEIGHT  : "<<"\t { "<<Height(getroot())<<" }\n"; 
	  cout<"--------------------------------------------------------------------------\n";
	   cout<<" NUMBER OF LEAFS IS  : "<<"\t { "<<Leafs(getroot())<<" }\n"; 
	  cout<"--------------------------------------------------------------------------\n";
	   cout<<" NUMBER OF SUBTREES IS  : "<<"\t { "<<SubTrees(getroot())<<" }\n";
	  cout<"--------------------------------------------------------------------------\n";
	  cout<<" THE TREE IN THE LEVEL  : "<<"\t { "<<Level(getroot())<<" }\n";
	
}





