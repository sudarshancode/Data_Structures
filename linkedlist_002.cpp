#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
void insertNode(struct node* head,int d){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}
void deleteNode(struct node* head){
    struct node *ptr1=head;
    struct node *ptr2=head;
    while(ptr1->next!=NULL){
        ptr2=ptr1;
        ptr1=ptr1->next;
    }
    ptr2->next=NULL;
}
void display(struct node* head){
    cout<<"Linked list:";
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<" Null "<<endl;
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=12;
    head->next=NULL;

    insertNode(head,14);
    insertNode(head,24);
    insertNode(head,34);
    insertNode(head,44);
    display(head);

    insertNode(head,46);
    display(head);

    deleteNode(head);
    display(head);
    return 0;
}