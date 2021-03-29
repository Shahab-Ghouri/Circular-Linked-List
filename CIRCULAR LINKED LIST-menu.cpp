//	Code By   SHAHAB GHOURI
// NOTE : CLL = Circular Linked List

#include <iostream>
using namespace std;

class node{			// creating class for nodes
	public:
		int data;
		node *next;
};
	// class for CLL
class LinkedList{
	public:
		node *head,*tail;			// declaring head and tail node pointers
		
		LinkedList(){		// default constructor
			head = NULL;
			tail = NULL;
		}
		
		
// FUNCTIONS FOR INSERTION
		
		
		// Function to insert a node at the end of CLL 
		void insertAtEnd(int n){
			node *temp = new node;
			temp->data = n;
			
			if(head == NULL){		// if no node is found, create one
				head =temp;
				tail = temp;
				tail->next = head;
			}
									
			else{					// else create node at the end
				tail->next = temp;
				tail = temp;
				tail->next = head;
			}
		}
		
		
		// Function To Add A Node at The Front
		void insertAtFront(int n){
			node *temp = new node;
			
			temp->data = n;
			 temp->next = head;
			 head = temp;
			 tail->next = head;
		}
		
		
		// Function To Add A Node At the Given Position
		int insertAtPosition(int n,int pos){
			node *temp = new node;
			temp->data = n;
			node *curr , *prev;
			curr =  head;
			
			if(pos<= 0){	// if position is lesser than 0, displays an error and returns without any insertion
				cout<<" Invalid Position.."<<endl<<" Press Any Key To Continue..."<<endl;
				fflush(stdin);
				cin.get();
				return 0;
			}				// if postion is equal to 1, simply add the node at the front
			if(pos==1){
				insertAtFront(n);
			}		
			else{			// else add the node at the given position
				for(int i=0; i<pos-1; i++){
					prev = curr;
					curr = curr->next;
				}
			
				prev->next = temp;
				temp->next = curr;
			
			}
		}
//		----------------------------------
	//	FUNCTION TO DISPLAY CLL
		void traverse(){
			node *temp;
			
			temp = head;
			cout<<"head("<<temp->data<<")"<<" -> ";
			temp = temp->next;
			while(temp != head ){
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
			cout<<" head ("<<temp->data<<")"<<endl;
		}
//		-----------------------------------
	// FUNCTIONS FOR DELETING NODES
	
		// Function To Delete The Node from the starting
		void deleteFirst(){
			node *temp;
			temp = head->next;
			tail->next = temp;
			head->next = NULL;
			head = temp;
		}
		
		// Function To Delete The Node From the End
		void deleteEnd(){
			node *curr,*prev;
			curr = head;
			while(curr->next != head){
				prev = curr;
				curr = curr->next;
			}
			prev->next = head;
			tail = prev;
			curr->next = NULL;
			delete curr;
		}
		
		// Function To Delete The Node From the Given Position
		int deletePosition(int pos){
			node *curr,*prev;
			if(pos<=0){
				cout<<" INVALID POSITION.."<<endl<<" Press Any Key To Continue.."<<endl;
				cin.get();
				return 0;
			}
			if(pos == 1){
				deleteFirst();
				return 1;
			}
			else{
				curr = head;
				for(int i=0 ; i<pos-1 ; i++){
					prev = curr;
					curr = curr->next;
				}
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				return 1;
			}
		}
//		----------------------------------
		// Function To Find The Maximum Number in The List
		int Max(){
			node *temp;
			temp = head;
			int max = 0 ;			// let minimum number in the list is 0
			do{
				if(max < temp->data){
					max = temp->data; 
				}
				temp = temp->next;
			}while(temp!= head);
			return max;
		}
//		-----------------------------------
		// Function To Find The Mean of The nodes
		float Mean(){
			node *temp;
			temp = head;
			int sum = 0,count = 0;
			
			do{
				sum += temp->data;
				temp = temp->next;
				count++;
			}while(temp != head);
			
			return sum/(float)count;
		}
//		-------------------------------------
		// Function To sort the CLL
		void sorting(){
			node *temp,*temp1;
			int a;
			temp =  head;
			while(temp->next != head){
				temp1 = head;
				while(temp1->next != head){
					if(temp1->data > temp1->next->data){
						a = temp1->data ; 
						temp1->data = temp1->next->data ;
						temp1->next->data = a;
					}
					temp1 = temp1->next; 	
				}
				
				temp = temp->next;
			}
		}
//		------------------------------------
	// Function To Reverse the CLL
		void Reverse(){
			node *temp,*curr , *prev;
			temp = head;
			curr = head;
			prev = head;
			curr = curr->next;
			temp = temp->next->next;
			while(curr != head){
				curr->next = prev;
				prev = curr;
				curr = temp;
				temp = temp->next;
			}	
			head = prev;
			curr->next = head;
		}
};

 
// start of MAIN
main(){
	
	LinkedList obj;
	int ch,n,pos;
	
	cout<<" CIRCULAR LINKED LIST\n\n"<<endl;
	while(1){		// start of while Loop
		system("cls");
	cout<<" 1- traverse()\n 2- insertAtFront()\n 3- insertAtEnd()\n 4- insertAtPosition()\n 5- deleteFirst()\n 6- deleteEnd()\n 7- deletePosition()\n 8- maximum()\n 9- mean()\n 10- sort()\n 11- reverseLL()\n 0 -EXIT\n" ;
	cout<<endl<<" Enter Your Choice : ";cin>>ch;
	if(ch==0){
		break;
	}
	switch(ch){		// start of switch case
		case 1 :
		{
				obj.traverse();
				cout<<" \nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		case 2:
		{		
				cout<<endl<<" Enter A value : ";cin>>n;
				obj.insertAtFront(n);
				cout<<" Value Added\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		case 3: {
				cout<<endl<<" Enter A value : ";cin>>n;
				obj.insertAtEnd(n);
				cout<<" Value Added\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();				
			break;
		}
		
		case 4 :{
				
				cout<<endl<<" Enter A value : ";cin>>n;	
				cout<<endl<<" Enter the Position : ";cin>>pos;
				if(obj.insertAtPosition(n,pos))
				{
					cout<<" Value Added\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				}
			
			break;
		}
		case 5 :{
				obj.deleteFirst();
				cout<<" \n Value Deleted From Start.\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		
		case 6 : {
				obj.deleteEnd();
				cout<<" \n Value Deleted From End.\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		case 7 : {
				cout<<" Enter Position : ";cin>>pos;
				if(obj.deletePosition(pos)){
					cout<<" \n Value Deleted.\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				}
			break;
		}
		case 8 : {
				cout<<endl<<" Maximum Number in the List is : "<<obj.Max()<<endl;
				cout<<" \n\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		case 9 :{
				cout<<endl<<" Mean Of the List is : "<<obj.Mean()<<endl;
				cout<<" \n\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		case 10 : {
				cout<<endl<<" Sorted Circular Linked List is : "<<endl<<endl;
				obj.sorting();
				obj.traverse();
				cout<<" \n\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		case 11 : {
				cout<<" Reversed Linked List is : "<<endl<<endl;
				obj.Reverse();
				obj.traverse();
				cout<<" \n\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		}
		default:{
				cout<<" INVALID OPTION..";
				cout<<" \n\nPress Any Key To Continue..\n";
				fflush(stdin);
				cin.get();
			break;
		} 
			
	}			// end of Switch Case
		
	
	}		// end of while loop
}			// end of MAIN

