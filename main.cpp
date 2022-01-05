#include <iostream>
#include"Defenations.h"

 
int Inputchoice();




int main(int argc, char** argv)
{
	  int c; double data;	
	  TREE_LL  *EvenTree=new TREE_LL;
First:
	  
do { 
	system("cls");
	  switch (c=Inputchoice())
	{
		
	  case '1' : {
	  
		system("cls");
		cout<<" ENTER ITEAM TO ADD INTO THE TREE  : "<<" >>>> ";  
		cin>>data; 
		EvenTree->GetNode(data,EvenTree->getroot()); 
		break;  }
		       
	  case '2' : {  
	    EvenTree->AllDisplay(EvenTree->getroot());
	    _getche();	break;
	           }
			   	
	  case '3' :  { 
		  cout<<"\n\n";
	  cout<<" ENTER THE DATA TO SEARCH  "<<" >>>> ";
	  cin>>data; system("cls");
	  EvenTree->FindNode(data , EvenTree->getroot());
      _getche(); break;
	            }
    
      case '4' : { 	  
      cout<<" SIZE IS :  "; 
      cout<<" { "<<EvenTree->SizeIs(EvenTree->getroot())<<" } \n"; 
      _getche(); break;		
	           }
	           
	  case '5' : {  EvenTree->CheckTree(EvenTree->getroot()); break; }
	  
	  case '6' : { double data;  system("cls"); 
	  for (int i=0; i<15; i++
	  cout<<"\n"; 
	  cout<<" ENTER THE DATA TO DELETE : ";
	               cin>>data; 
				   if (EvenTree->Delete(EvenTree->getroot(),data))  
				   cout<<" COMPLETE DELETION "; 
	                    _getche();   break;  }
	  
	  case '7' : {   Node *X=EvenTree->Get_Max(EvenTree->getroot());
	               if (X==NULL)  {  cout<<"EMPTY TREE\a\a"; _getche(); break; }
	               cout<<" THE MAXIMUM DATA IN THIS BINARY TREE IS ";
	               cout<<X->getdata(); _getche(); break;   }
	  
	  case '8' : {  Node *X=EvenTree->Get_Min(EvenTree->getroot());
	               if (X==NULL)  {  cout<<"EMPTY TREE\a\a"; ; _getche(); break; }
	               cout<<" THE MINEMUM  DATA IN THIS BINARY TREE IS "; 
	               cout<<X->getdata(); _getche();  break;   }
	               
	  case '9' : {system("cls"); 
	  cout<<" THIS IS BINARY TREE STATUESES "; EvenTree->BTreeStatues();
	                _getche();   break; }
	  
      case '0' : {  exit(1);  }
      
	  default  : { cout<<"\a";   break; }
	
    }


  } while (c!=0);

     

} // END OF MAIN


   
      int Inputchoice()
  {
      
	  system("cls"); 
	  cout<<" ENTER YOUR CHOICE PLEASE ";
      cout<<"\n\n";
	  cout<<"1 - INSERT  ITEAMS \n";
	  cout<<"2 - DISPLAY ITEAMS \n";
	  cout<<"3 - FIND ITEAM IN TREE \n";
      cout<<"4 - TREE SIZE \n";
      cout<<"5 - CHECK BTREE STATUOSE  \n";
      cout<<"6 - DELET ITEAMS \n";
      cout<<"7 - FIND THE MAXIMUM DATA \n";
      cout<<"8 - FIND THE MINEMUM DATA \n";
      cout<<"9 - SEE THE TREE STAUSE  \n";
      cout<<"0 - EXITE  \n";
	  cout<<"\n\t  ENTER >>>>>  ";
	  char choice=_getche();
	system("cls");
	  return choice;
	
  }
  