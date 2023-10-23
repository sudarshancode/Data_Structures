//Non-Recursive PreOrder Traversal
#include<bits/stdc++.h>
using namespace std;
struct BinaryNode{
	struct BinaryNode* left;
	int salary;
	struct BinaryNode* right;
};
stack<int> preOrderTraversal(struct BinaryNode* root){
	stack<int> list;
	stack<struct BinaryNode*> Stack;
	struct BinaryNode* temp=root;
	Stack.push(temp);
	while(!Stack.empty()){
		struct BinaryNode* temp= Stack.top();
		Stack.pop();
		list.push(temp->salary);
		if(temp->right != NULL){
			Stack.push(temp->right);
		}
		if(temp->left != NULL){
			Stack.push(temp->left);
		}
	}
	return list;
}
int main()
{
	struct BinaryNode* ceo=NULL;
	struct BinaryNode* head_oficer_1=NULL;
	struct BinaryNode* head_oficer_2=NULL;
	struct BinaryNode* h1_manager_1=NULL;
	struct BinaryNode* h1_manager_2=NULL;
	struct BinaryNode* h2_manager_1=NULL;
	struct BinaryNode* h2_manager_2=NULL;
	ceo=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	head_oficer_1=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	head_oficer_2=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	h1_manager_1=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	h1_manager_2=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	h2_manager_1=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	h2_manager_2=(struct BinaryNode*) malloc(sizeof(struct BinaryNode));
	
	ceo->salary=50000;
	ceo->left=head_oficer_1;
	ceo->right=head_oficer_2;

	head_oficer_1->salary=40000;
	head_oficer_1->left=h1_manager_1;
	head_oficer_1->right=h1_manager_2;

	h1_manager_1->salary=30000;
	h1_manager_1->left=NULL;
	h1_manager_1->right=NULL;

	h1_manager_2->salary=35000;
	h1_manager_2->left=NULL;
	h1_manager_2->right=NULL;

	head_oficer_2->salary=45000;
	head_oficer_2->left=h2_manager_1;
	head_oficer_2->right=h2_manager_2;

	h2_manager_1->salary=32000;
	h2_manager_1->left=NULL;
	h2_manager_1->right=NULL;

	h2_manager_2->salary=33000;
	h2_manager_2->left=NULL;
	h2_manager_2->right=NULL;
	int count=0;
	stack <int> pre_order_traversal=preOrderTraversal(ceo);
	stack<int> temp;
	while(!pre_order_traversal.empty()){
		temp.push(pre_order_traversal.top());
		pre_order_traversal.pop();
	}
	while(!temp.empty()){
		int x= temp.top();
		temp.pop();
		cout<<x<<"  ";
	}
	cout<<endl;
	return 0;
}
