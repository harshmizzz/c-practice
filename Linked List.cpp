#include <iostream>
using namespace std;
class node{
  public:
  int data;
  node* next;
  
  node(int val){
      data=val;
      next=NULL;
  }
};

void insertAtTail(node* &head ,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(node* &head,int val){
   node* n= new node(val);
   n->next=head;
   head=n;
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
            
        }temp=temp->next;
        
    }return false;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int key){
    
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    node* todelete= temp->next;
    temp->next=temp->next->next;
    
    delete todelete;
}

node* reverse(node* &head){
    node* currptr=head;
    node* prevptr=NULL;
    node* nextptr;
    
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }
   return prevptr;
}

node* returnRecursice(node* &head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* newHead = returnRecursice(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newHead;
}

node* reversek(node* &head,int key){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    
    int count=0;
    
    while(currptr!=NULL && count<key){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reversek(nextptr,key);
    }
    
    return prevptr;
}

void makecycle(node* &head,int pos){
    node*temp=head;
    node* startnode;
    int count=1;
    
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
            
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;
    
    while(fast!=NULL  && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(fast==slow){
            return true;
        }
        
    }
    return false;
}

void removecycle(node* &head){
      node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);
    
    fast=head;
    
    while(slow->next != fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main() {
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    makecycle(head,5);
     cout<<detectcycle(head);
    removecycle(head);
    cout<<detectcycle(head);
    
	return 0;
}
