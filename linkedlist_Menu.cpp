//Linked list menu driven program
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void Menu( struct Node* head);
void addEnd(struct Node* head,int d){
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=d;
    temp->next=NULL;
    struct Node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}
void addAnyPos(struct Node* head,int d,int p){
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=d;
    int i=1;
    /*
    p--;
    while(p!=1){
        head=head->next;
        p--;
    }
    */
    while(i<p-1){
        head=head->next;
        i++;
    }
    temp->next=head->next;
    head->next=temp;
}
struct Node* addFont(struct Node* head,int d){
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data=d;
    temp->next=head;
    head=temp;
    return head;
}
void delEnd(struct Node* head){
    struct Node* ptr1=head;
    struct Node* ptr2= head;
    while(ptr1->next!=NULL){
        ptr2=ptr1;
        ptr1=ptr1->next;
    }
    ptr2->next=NULL;
}
struct Node* delFont(struct Node* head){
    head=head->next;
    return head;
}
void delAnyPos(struct Node* head,int p){
    struct Node* ptr = head;
    int i=1;
    while(i<p-1){
        ptr=ptr->next;
        i++;
    }
    struct Node* delNode= ptr->next;
    struct Node* nextDelNode=ptr->next->next;
    ptr->next=nextDelNode;
    delNode->next=NULL;
}
void display(struct Node* head)
{
    int cho;
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL\n";
    cout<<"Go Main Menu(99):";
    cin>>cho;
    if(cho==99){ 
        Menu(head);
    }else{
        system("clear");
        display(head);
    }
}
void Insertion(struct Node* head){
    system("clear");// if you use windows then, clear-> cls;
    int cho,data,pos;
    cout<<"----------INSERTION-----------"<<endl;
    cout<<"-------1. Insert at Font"<<endl;
    cout<<"-------2. Insert at End"<<endl;
    cout<<"-------3. Insert at any Postion"<<endl;
    cout<<"          Go Main Menu(99)"<<endl;
    cout<<"Enter your chose:";
    cin>>cho;
    if(cho!=99){
        cout<<"Enter value:";
        cin>>data;
        switch(cho){
            case 1:
                head=addFont(head,data);
                break;
            case 2:
                addEnd(head,data);
                break;
            case 3:
                cout<<"Enter position:";
                cin>>pos;
                addAnyPos(head,data,pos);
                break;
            default:
                cout<<"Enter correct option....."<<endl;
                system("clear");
                Insertion(head);
        }
    }
    else if( cho == 99){
        Menu(head);
    }else{
        cout<<"Enter correct option...."<<endl;
        system("clear");
        Insertion(head);
    }
}
void Deletion(struct Node* head){
    system("clear");
    int cho,pos;
    cout<<"----------DELETION-----------"<<endl;
    cout<<"-------1. Delete at Font"<<endl;
    cout<<"-------2. Delete at End"<<endl;
    cout<<"-------3. Delete at any Postion"<<endl;
    cout<<"          Go Main Menu(99)"<<endl;
    cout<<"Enter your chose:";
    cin>>cho;
    if(cho!=99){
        switch(cho){
            case 1:
                head=delFont(head);

                break;
            case 2:
                delEnd(head);
                break;
            case 3:
                cout<<"Enter position:";
                cin>>pos;
                delAnyPos(head,pos);
                break;
            default:
                cout<<"Enter correct option....."<<endl;
                system("clear");
                Insertion(head);
        }
    }
    else if( cho == 99){
        Menu(head);
    }else{
        cout<<"Enter correct option...."<<endl;
        system("clear");
        Deletion(head);
    }
}

void Menu( struct Node* head)
{
    
    int chose;
    cout<<"-----------MENU-----------\n";
    cout<<"      1.Insertion\n";
    cout<<"      2.Deleation"<<endl;
    cout<<"      3.Display"<<endl;
    cout<<"Enter your chose:";
    cin>>chose;
    switch(chose){
        case 1:
            Insertion(head);
            break;
        case 2:
            Deletion(head);
            break;
        case 3:
            display(head);
            break;
        default:
            cout<<"Enter correct option..."<<endl;
            system("clear");
            Menu(head);
    }
}
int main()
{
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    head->data=0;
    head->next=NULL;
    while(1){
        system("clear");
        Menu(head);
    }
    return 0;
}
