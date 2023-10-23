#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};
int main()
{
	struct Node *head=NULL;
	struct Node *second=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));

	head->data=30;
	head->next=second;
	second->data=50;
	second->next=NULL;

	struct Node* ptr;
	ptr=head;

	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
	return 0;
}
