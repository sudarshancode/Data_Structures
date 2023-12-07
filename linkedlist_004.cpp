#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
void addEnd(struct node* *head,int d){
    struct node* ptr=*head;

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;

    if(*head==NULL){
        *head=temp;
    }else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
    cout<<"Null"<<endl;
}
int main(){
    struct node* head=NULL;
    addEnd(&head,45);
    addEnd(&head,76);
    display(head);
    return 0;
}