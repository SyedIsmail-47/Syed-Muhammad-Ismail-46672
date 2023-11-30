 #include <iostream>
using namespace std;
class Node{
	public:
 		int value;
 		Node *next;
 		Node *previous;
 		Node(int v)
 		{
 			value = v;
 			next = NULL;
 			previous = NULL;
 		}
};

class singlylinkedlist{
	public:
		int v;
		int value;
		int index;
 		Node *head;
 		singylinkedlist() 
 	{ 
 		head = NULL; 
 	}
 		
 	
 	void add(int v)
 	{
 		cout<<"Enter Number to add a new Node: ";
 		while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 		Node *newNode = new Node(v);
 		if (head == NULL)
 		{
 			head = newNode;
 		}
 		else
 		{
 			Node *current = head;
 			while (current->next != NULL)
 			{
				current = current->next;
 			}
			current->next = newNode;
 		}
 }
 
 
void display()
 {
 if (head == NULL)
 {
 return;
 }
 else
 {
 Node *current = head;
 while (current != NULL)
 {
 cout << current->value << " ";
 current = current->next;
 }
 cout << endl;
 }
 }
 
 
 	void addFirst(int v)
 	{
 		cout<<"Enter Data for Node: ";
 		while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 		Node *newNode = new Node(v);
 		newNode->next = head;
 		head = newNode;
 	}
 	
 	
 	void deleteFirst()
 	{
 		if (head == NULL)
 		{
 			cout<<"The Node is Empty"<<endl;
 			singlylistmenu();
 		}
 		else
 		{
 			Node *temp = head;
 			head = head->next;
 			delete temp;
 		}
 	}
 
 
 	void deleteLast()
 	{
 		if (head == NULL)
 		{
 			cout<<"The Node is Empty"<<endl;
 			singlylistmenu();
 		}
 		else
 		{
 			Node *current = head;
 			Node *previous = NULL;
 			while (current->next != NULL)
 			{
 				previous = current;
 				current = current->next;
 			}
 			previous->next = NULL;
 			delete current;
 		}
 }
 
 bool isEmpty() { return head == NULL; }
 
 	void insertAt(int value, int index)
	{
 		cout<<"Enter Data For the Node: ";
 		while(!(cin>>value)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 		cout<<"Enter the Position of Node to insert At: ";
 		while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 		int i=0;
 		Node *newNode = new Node(value);
 		Node *current = head;
 		if(index==0)
		{
 			newNode->next=head;
 			head=newNode;
	 	}
	 	while(i<index-1 && current->next!=NULL)
		{
 		 	current=current->next;
 		 	i++;
	 	}
	 	newNode->next=current->next;
	 	current->next = newNode;
 	}
 
 
 	int search(int value){
 	if (head == NULL)
 		{
 			cout<<"The Node is Empty"<<endl;
 			singlylistmenu();
 		}
 	else
 	{
 		cout<<"Enter Number for Search: ";
 		while(!(cin>>value)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 		int i=1;
 		Node *current = head;
 		while(current !=NULL){
 			if(current->value == value){
 				cout<<"element found at index "<<i<<endl;
			return 0; }
 		current=current->next;
 		i++;
	 }
	 	cout<<"not found "<<endl;	 
 	}
}
 
	int countnodes(){
	int count=1;
	Node *current= head;
	if(head=NULL){
		cout<<"0"<<endl;
	}
	while(current->next !=NULL){
		count++;
		current=current->next;
	}
	cout<<"total number of Nodes are "<<count<<endl;
}

	void maximum(){
		if (head == NULL)
 		{
 			cout<<"The Node is Empty"<<endl;
 			singlylistmenu();
 		}
 		else{
	int max = head->value;
	Node *current =head;
 while (current != NULL){
 
		if(max < current->value){
			max=current->value;
		}
		current=current->next;
	 }
	 cout<<"the maximum number node is :"<<max<<endl;
	}
}

void average(){
	if (head == NULL)
 		{
 			cout<<"The Node is Empty"<<endl;
 			singlylistmenu();
 		}
 		else{
	float count=1;
	int value=0;
	Node *current=head;
	value=current->value;
	while(current->next !=NULL){
		count++;
		current=current->next;
		value=value+current->value;
	}
	float average;
	average=(value/count);
	cout<<"The average of the all nodes is :"<<average<<endl;
}
}

void reverse(){
	Node *current=head;
	Node *previous=NULL;
	Node *next=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=previous;
	previous=current;
		current=next;//=next;
	}
	head=previous;
}
void detectloop(){
	Node *single=head;
	Node *double1=head;
 
	while(double1!=NULL && double1->next!=NULL){
		single=single->next;
		double1=double1->next->next;

	if(single==double1){
		cout<<"loop detected"<<endl;
		return ;}
	}
	if(single!=double1){
		cout<<"no loop detected"<<endl;
	}
}


void ispalindrome() {
    Node *current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    current = head;

    int *Array = new int[count];
   for (int i = 0; i < count; i++) {
        Array[i] = current->value;
        current = current->next;
    }
    reverse();
    current = head;
    for (int i = 0; i < count; i++) {
        if (Array[i] != current->value) {
            cout << "It is not Palindrome" << endl;
           reverse();
            delete[] Array;
            return;
        }
        current = current->next;
    }

    cout << "It is Palindrome" << endl;
	 reverse();
    delete[] Array; 
}
	
	void singlylistmenu(){
		int select;
		cout<<"1 to add a New Node: "<<endl;
		cout<<"2 to Add on First Node: "<<endl;
		cout<<"3 to Delete on First Node: "<<endl;
		cout<<"4 to Delete on Last Node: "<<endl;
		cout<<"5 to Insert At: "<<endl;
		cout<<"6 to Search: "<<endl;
		cout<<"7 to CountNodes: "<<endl;
		cout<<"8 to find the Maximum: "<<endl;
		cout<<"9 to find average: "<<endl;
		cout<<"10 to reverse the order: "<<endl;
		cout<<"11 to detect loop: "<<endl;
		cout<<"12 for Palindrome Function: "<<endl;
		cout<<"13 to back on Menu: "; 
		while(!(cin>>select)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
		switch(select)
		{
			case 1:
				system("cls");
				add(v);
				display();
			break;
			case 2:
				system("cls");
				addFirst(v);
				display();
			break;
			case 3:
				system("cls");
				deleteFirst();
				display();
			break;
			case 4:
				system("cls");
				deleteLast();
				display();
			break;
			case 5:
				system("cls");
				insertAt(value,index);
				display();
			break;
			case 6:
				system("cls");
				search(value);
			break;
			case 7:
				system("cls");
				countnodes();
			break;
			case 8:
				system("cls");
				maximum();
			break;
			case 9:
				system("cls");
				average();
			break;
			case 10:
				system("cls");
				reverse();
				display();
			break;
			case 11:
				system("cls");
				detectloop();
			break;
			case 12:
				system("cls");
				ispalindrome();
			break;
			case 13:
				system("cls");
				goto one;
			break;
			default:
				system("cls");
				cout<<"Wrong Input"<<endl;
				singlylistmenu();
		}
		singlylistmenu();
		one:;
	}
};


class doublylinkedlist {
	public:
		Node *head;
	doublylinkedlist(){
		head=NULL;
	}
	void addfirst(){
		cout<<"Add value this value is added at first:";
		int v;
		while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
		Node *new_Node= new Node(v);
		if(head==NULL){
			head=new_Node;
		}
		else{
		new_Node->next=head;
		head->previous=new_Node;
		head=new_Node;
}
}
	void addlast(){
		int v;
		cout<<"Add the data for Node: ";
		while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
		Node *new_Node=new Node(v);
		Node *current=head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=new_Node;
		new_Node->previous=current;
		
	}

	
	void add()	{
		int v;
		cout<<"enter value to make a new node:";
		while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
		Node *new_Node=new Node(v);
		if(head == NULL){
			head=new_Node;
		}
		else
 		{
 			Node *current = head;
 			while (current->next != NULL)
 			{
				current = current->next;
 			}
			current->next = new_Node;
 		}
		}

	
void display()
 {
 if (head == NULL)
 {
 return;
 }
 else
 {
 Node *current = head;
 while (current != NULL)
 {
 cout << current->value << " ";
 current = current->next;
 }
 cout << endl;
 }
 }
 
 
 void insertat(){
 	int v,i=1,index;
 	cout<<"add value you want to insert :";
 	while(!(cin>>v)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 	cout<<"enter location :";
 	while(!(cin>>index)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
 	Node *new_Node= new Node(v);
 	Node *current=head;
 	if(index==1){
 		new_Node->next=head;
 		head->previous=new_Node;
 		head=new_Node;
 		return;
	 }
	 
 	while(current!=NULL){
 		if(i==index-1){
 			new_Node->next=current->next;
			 current->next=new_Node;
			 current->next->previous=new_Node;
 			new_Node->previous=current;
// 			current=new_Node;
 			return;
		 }
 		current=current->next;
		 i++;
	 }
	 if(current==NULL){
	 	cout<<"no index found re enter index :"; //yaha function recurrsion ke zariye call krenge
	 }
	 	
	 }
 void deleteFirst()
{
if (head == NULL)
{
return;
}
Node *temp = head;
head = head->next;
if (head != NULL)
{
head->previous = NULL;
}
delete temp;
}

 void deletelast(){
 	Node *current =head;
 	while(current->next!=NULL){
 		current=current->next;
	 }
	current->previous->next=NULL; 
	delete current;
 }
void deleteat(){
	int i=1,index;
	cout<<"which index value you want to delete";
	while(!(cin>>index)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
	Node *current=head;
	if(index==1){
 		head=head->next;
		if (head != NULL)
	{
		head->previous = NULL;
	}
delete current;
return;
} 
 	while(current!=NULL){
 		if(i==index){
 			if (current->next != NULL) {
 			current->next->previous=current->previous;}
 			current->previous->next=current->next;
			 
			 delete current;
// 			current=new_Node;
 			return;
		 }
 		current=current->next;
		 i++;
	 }
	 if(current==NULL){
	 	cout<<"no index found to delete:"; //yaha function recurrsion ke zariye call krenge
	 }
	 
} 
int countnodes(){
	int count=1;
	Node *current= head;
	if(head=NULL){
		cout<<"0";
	}
	while(current->next !=NULL){
		count++;
		current=current->next;
	}
	cout<<"total number of Nodes are "<<count;
}
void search(){
	int i=1,value;
	cout<<"Enter the Value You want to Search :";
	while(!(cin>>value)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
 	Node *current = head;
 	while(current!=NULL){
 		if(current->value == value){
 			cout<<"element found at index "<<i; 
			 return ;}
 		current=current->next;
 		i++;
	 }
	 	cout<<"not found ";
	 
 }
 
void maximum(){
	
	int max = head->value;
	Node *current =head;
 while (current != NULL){
 
		if(max < current->value){
			max=current->value;
		}
		current=current->next;
	 }
	 cout<<"the maximum number node is :"<<max;
}

void average(){
	float count=1;
	int value=0;
	Node *current=head;
	value=current->value;
	while(current->next !=NULL){
		count++;
		current=current->next;
		value=value+current->value;
	}
	float average;
	average=(value/count);
	cout<<"The average of the all nodes is :"<<average;
}

void reverse() {
    Node *current = head;
    Node *newHead = NULL;

    // Move current to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    newHead = current; // Set newHead to the last node

    while (current != NULL) {
        Node *temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->next;
    }

    head = newHead; // Update head to the new head of the reversed list
    head->previous = NULL; // Set the previous of the new head to NULL
}

void detectloop(){
	Node *single=head;
	Node *double1=head;
 
	while(double1!=NULL && double1->next!=NULL){
		single=single->next;
		double1=double1->next->next;

	if(single==double1){
		cout<<"loop detected";
		return ;}
	}
	if(single!=double1){
		cout<<"no loop detected";
	}
}

	void doublylistmenu(){
		int select;
		cout<<"1 to add a First Node: "<<endl;
		cout<<"2 to Add on Last Node: "<<endl;
		cout<<"3 to add a New Node: "<<endl;
		cout<<"4 to Insert At: "<<endl;
		cout<<"5 to Delete on First Node: "<<endl;
		cout<<"6 to Delete on Last Node: "<<endl;
		cout<<"7 to Delete at: "<<endl;
		cout<<"8 to CountNodes: "<<endl;
		cout<<"9 to Search: "<<endl;
		cout<<"10 to find the Maximum: "<<endl;
		cout<<"11 to find average: "<<endl;
		cout<<"12 to reverse the order: "<<endl;
		cout<<"13 to detect loop: "<<endl;
		cout<<"14 to back on Menu: ";
		while(!(cin>>select)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
		}
		switch(select)
		{
			case 1:
				system("cls");
				addfirst();
				display();
			break;
			case 2:
				system("cls");
				addlast();
				display();
			break;
			case 3:
				system("cls");
				add();
				display();
			break;
			case 4:
				system("cls");
				insertat();
				display();
			break;
			case 5:
				system("cls");
				deleteFirst();
				display();
			break;
			case 6:
				system("cls");
				deletelast();
				display();
			break;
			case 7:
				system("cls");
				deleteat();
				display();
			break;
			case 8:
				system("cls");
				countnodes();
			break;
			case 9:
				system("cls");
				search();
			break;
			case 10:
				system("cls");
				maximum();
			break;
			case 11:
				system("cls");
				average();
			break;
			case 12:
				system("cls");
				reverse();
			break;
			case 13:
				system("cls");
				detectloop();
			break;
			case 14:
				system("cls");
				goto two;
			break;
			default:
				system("cls");
				cout<<"wrong input";
				doublylistmenu();
		}
		doublylistmenu();
		two:;
	}
};


class circularLinkedList {
public:
    Node *head;
    circularLinkedList() {
        head = NULL;
    }

    void addlast() {
    int v;
    cout << "Enter Number To Add in Node: ";
    while(!(cin>>v)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
    Node *new_Node = new Node(v);

    if (head == NULL) {
        head = new_Node;
        new_Node->next = head;
    } else {
        Node *current = head;
		while (current->next != head) {
            current = current->next;
        }
        current->next = new_Node;
        new_Node->next = head;
    }
}
    void addfirst() {
    int v;
    cout << "Enter Value to add at first Node :";
    while(!(cin>>v)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
    Node *new_Node = new Node(v);

    if (head == NULL) {
        new_Node->next = new_Node;  
        head = new_Node;
    } else {
        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        new_Node->next = head;
        current->next = new_Node;
        head = new_Node;
    }
}

    void display() {
        if (head == NULL) {
            return;
        }

        Node *current = head;
        do {
            cout << current->value << "  ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
    
    void  deletefirst(){
    	if (head == NULL) {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    	Node *current = head;
    	Node *temp =head;
		//current=current->next;
    	while(current->next!=head){
    		current=current->next;
		}
//		delete temp;
		head=head->next;
		delete temp;
		current->next=head;
			
	}
	
	void deletelast(){
		Node *current=head;
		Node *temp=head;
		while(current->next->next!=head){
			current=current->next;
		}
		temp=current->next;
		current->next=head;
	}

int search(){int value,i=1;
	cout<<"enter value to search:";
	while(!(cin>>value)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
 	Node *current = head;
 	while(current->next!=head){
 		if(current->value == value){
 			cout<<"element found at index "<<i;
		return 0; }
 		current=current->next;
 		i++;
	 }
	 if(current->value==value){
	 	cout<<"element found at index :"<<i++;
	 	return 0;
	 }
	 	cout<<"not found ";
	 
 }
 
 void insertAt(){
    if (head == NULL) {
        cout << "List is empty. Cannot insert at specified index." << endl;
        return;
    }

    int index, value;
    cout << "Enter the number you want to add: ";
    while(!(cin>>value)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
    cout << "Enter the index at which you want to insert: ";
    while(!(cin>>index)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}

    if (index <= 0) {
        cout << "Invalid index. Index should be greater than 0." << endl;
        return;
    }

    Node *newNode = new Node(value);
    Node *current = head;
    int i = 1;
    if (index == 1) {
        newNode->next = head;
			while (current->next != head) {
            current = current->next;
        }

        head = newNode;
        current->next = head;}
    
	 else {
         while (i < index-1 && current->next != head) {
            current = current->next;
            i++;
        }

        if (i != index-1) {
            cout << "Invalid index. Index exceeds the length of the list." << endl;
            delete newNode; 
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int countnodes(){
	int count=1;
	Node *current= head;
	if(head==NULL){
		cout<<"0";
	}
	while(current->next !=head){
		count++;
		current=current->next;
	}
	cout<<"total number of Nodes are "<<count;
}

void maximum(){
	int max = head->value;
	Node *current =head;
 while (current->next != head){
 
		if(max < current->value){
			max=current->value;
		}
		current=current->next;
	 }
	 cout<<"the maximum number node is :"<<max;
}

 void average(){
	float count=1;
	int value=0;
	Node *current=head;
	value=current->value;
	while(current->next !=head){
		count++;
		current=current->next;
		value=value+current->value;
	}
	float average;
	average=(value/count);
	cout<<"The average of the all nodes is :"<<average;
}

void reverse() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    Node* previous = NULL;
    Node* next = NULL;

    do {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    } while (current != head);

    head->next = previous;
    head = previous;
}

void detectloop(){
	Node *single=head;
	Node *double1=head;
 
	while(double1!=head && double1->next!=head){
		single=single->next;
		double1=double1->next->next;

	if(single->value==double1->value){
		cout<<"loop detected";
		return ;}
	}
//	if(single->value!=double1->value){
		cout<<"no loop detected";
	
}


void circularlistmenu(){
	int select;
		cout<<"1 to add a Last Node: "<<endl;
		cout<<"2 to Add on First Node: "<<endl;
		cout<<"3 to Delete on First Node: "<<endl;
		cout<<"4 to Delete on Last Node: "<<endl;
		cout<<"5 to Insert At: "<<endl;
		cout<<"6 to Search: "<<endl;
		cout<<"7 to CountNodes: "<<endl;
		cout<<"8 to find the Maximum: "<<endl;
		cout<<"9 to find average: "<<endl;
		cout<<"10 to reverse the order: "<<endl;
		cout<<"11 to detect loop: "<<endl;
		cout<<"12 to back on Menu: "; 
		while(!(cin>>select)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
		switch(select)
		{
			case 1:
				system("cls");
				addlast();
				display();
			break;
			case 2:
				system("cls");
				addfirst();
				display();
			break;
			case 3:
				system("cls");
				deletefirst();
				display();
			break;
			case 4:
				system("cls");
				deletelast();
				display();
			break;
			case 5:
				system("cls");
				insertAt();
				display();
			break;
			case 6:
				system("cls");
				search();
			break;
			case 7:
				system("cls");
				countnodes();
			break;
			case 8:
				system("cls");
				maximum();
			break;
			case 9:
				system("cls");
				average();
			break;
			case 10:
				system("cls");
				reverse();
				display();
			break;
			case 11:
				system("cls");
				detectloop();
			break;
			case 12:
				system("cls");
				goto three;
			break;
			default:
				system("cls");
				cout<<"wrong input";
				circularlistmenu();
		}
		circularlistmenu();
		three:;
	}

};


class circulardoublylinkedlist {
public:
    Node *head;

    circulardoublylinkedlist() {
        head = NULL;
    }

   void addfirst() {
    cout << "Add value; this value is added at first: ";
    int v;
    while(!(cin>>v)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
    Node *new_Node = new Node(v);

    if (head == NULL) {
        head = new_Node;
    } else {
    	Node *current=head;
    	while(current->next!=head){
    		current=current->next;
		}
		
        new_Node->next = head;
        head->previous = new_Node;
        head = new_Node;
        head->previous = current; 
 		current->next=head;   
	}
}

    void addlast() {
        int value;
        cout << "Enter value to add: ";
        while(!(cin>>value)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
		}

        Node *new_Node = new Node(value);

        if (head == NULL) {
            head = new_Node;
            head->next=head;
            head->previous = head;
        } else {
            Node *current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = new_Node;
            new_Node->previous = current;
            new_Node->next = head;
        }
    }

 void display() {
        if (head == NULL) {
            return;
        }

        Node *current = head;
        do {
            cout << current->value << "  ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
    
    void deleteFirst(){
if (head == NULL)
{
cout<<"The Node is empty";
}
Node *temp = head;
//head = head->next;
if (head != NULL)
{
	Node *current=head;
	while(current->next!=head){
	current=current->next;}
	head=head->next;
	current->next=head;
head->previous = current;
}
delete temp;
}

void deletelast(){
	Node *temp=head;
	Node *current=head;
	while(current->next!=head){
		current=current->next;
		temp=temp->next;
	}
	current=current->previous;
	current->next=head;
	head->previous=current;
	delete temp;
}

void insertat() {
    int v, i = 1, index;
    cout << "add value you want to insert: ";
    while(!(cin>>v)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
    cout << "enter location: ";
    while(!(cin>>index)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}

    Node *new_Node = new Node(v);
    Node *current = head;

    if (index == 1) {
        if (head == NULL) {
            new_Node->next = new_Node;
            new_Node->previous = new_Node;
            head = new_Node;
        } 
		else {
            new_Node->next = head;
            new_Node->previous = head->previous;
            head->previous->next = new_Node;
            head->previous = new_Node;
            head = new_Node;
        }
        return;
    }

    while (current != NULL) {
        if (i == index - 1) {
            new_Node->next = current->next;
            if (current->next != NULL) {
                current->next->previous = new_Node;
            }
            current->next = new_Node;
            new_Node->previous = current;
            return;
        }
        current = current->next;
        i++;
    }
    cout << "no index found re-enter index." << endl;
}

int search(){int value,i=1;
	cout<<"enter value to search:";
	while(!(cin>>value)){
		cout<<"Wrong Input :";
		cin.clear();
		cin.ignore();
	}
 	Node *current = head;
 	while(current->next!=head){
 		if(current->value == value){
 			cout<<"element found at index "<<i;
		return 0; }
 		current=current->next;
 		i++;
	 }
	 if(current->value==value){
	 	cout<<"element found at index :"<<i++;
	 	return 0;
	 }
	 	cout<<"not found ";
	 
 }
 
 int countnodes(){
	int count=1;
	Node *current= head;
	if(head==NULL){
		cout<<"0";
	}
	while(current->next !=head){
		count++;
		current=current->next;
	}
	cout<<"total number of Nodes are "<<count;
}

void maximum(){
	int max = head->value;
	Node *current =head;
 while (current->next!= head){
		current=current->next;
		if(max < current->value){
			max=current->value;
		}
	 }
	 cout<<"the maximum number node is :"<<max;
}

void average(){
	float count=1;
	int value=0;
	Node *current=head;
	value=current->value;
	while(current->next !=head){
		count++;
		current=current->next;
		value=value+current->value;
	}
	float average;
	average=(value/count);
	cout<<"The average of the all nodes is :"<<average;
}

void reverse() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    Node* previous = NULL;
    Node* next = NULL;

    do {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    } while (current != head);

    head->next = previous;
    head = previous;
}

void circulardoublylistmenu(){
	int select;
		cout<<"1 to add a Last Node: "<<endl;
		cout<<"2 to Add on First Node: "<<endl;
		cout<<"3 to Delete on First Node: "<<endl;
		cout<<"4 to Delete on Last Node: "<<endl;
		cout<<"5 to Insert At: "<<endl;
		cout<<"6 to Search: "<<endl;
		cout<<"7 to CountNodes: "<<endl;
		cout<<"8 to find the Maximum: "<<endl;
		cout<<"9 to find average: "<<endl;
		cout<<"10 to reverse the order: "<<endl;
		cout<<"11 to back on Menu: "; 
		while(!(cin>>select)){
			cout<<"Wrong Input :";
			cin.clear();
			cin.ignore();
		}
		switch(select)
		{
			case 1:
				system("cls");
				addlast();
				display();
			break;
			case 2:
				system("cls");
				addfirst();
				display();
			break;
			case 3:
				system("cls");
				deleteFirst();
				display();
			break;
			case 4:
				system("cls");
				deletelast();
				display();
			break;
			case 5:
				system("cls");
				insertat();
				display();
			break;
			case 6:
				system("cls");
				search();
			break;
			case 7:
				system("cls");
				countnodes();
			break;
			case 8:
				system("cls");
				maximum();
			break;
			case 9:
				system("cls");
				average();
			break;
			case 10:
				system("cls");
				reverse();
				display();
			break;
			case 11:
				system("cls");
				goto four;
				break;
			default:
				system("cls");
				cout<<"wrong input";
				circulardoublylistmenu();
		}
		circulardoublylistmenu();
		four:;
	}
};
int main(){
	 	 int choice;
    do {
        cout << "Select the type of linked list to work with:" << endl;
        cout << "1. Singly Linked List" << endl;
        cout << "2. Doubly Linked List" << endl;
        cout << "3. Circular Linked List" << endl;
        cout << "4. Circular Doubly Linked List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        
        while(!(cin >> choice)){
            cout << "Wrong Input. Please enter a number: ";
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
            case 1: {
                singlylinkedlist sll;
                sll.singlylistmenu();
                break;
            }
            case 2: {
                doublylinkedlist dll;
                dll.doublylistmenu();
                break;
            }
            case 3: {
                circularLinkedList cll;
                cll.circularlistmenu();
                break;
            }
            case 4: {
                circulardoublylinkedlist cdll;
                cdll.circulardoublylistmenu();
                break;
            }
            case 5: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }
    } while (choice != 5);
    return 0;
}


