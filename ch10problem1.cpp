#include<iostream>
//Coen 70 HW6, CH10 problem 1
//Jordan Lai
using namespace std;

class express_tree{

	public:
		express_tree();
		~express_tree();
	
		class node{
			public:
				node(node*p, node*q);
				node* lc;
				node* rc;
				char expression;
				int data;
		};
		void set_tree(node* d);
		int evaluate_tree(node*d);
	private:
		node* root;
};

express_tree::node::node(node*p, node*q){
	
	lc=p;
	rc=q;
	
};

express_tree::express_tree(){
	root=new node(NULL, NULL);


}

void express_tree::set_tree(node* d){
	int expornum;
	node* temp=d;
	if(temp->expression=='0')
		cout<< "an expression for the root" <<
   		"\n";
	else
		cout<<"please insert 0 for a new int or 1 for a new expression"
		<< "\n";
	cin>>expornum;
	if(expornum==0){
		cout<<"please insert a new integer then"<<"\n";
		cin>>temp->data;
	}

	if(expornum==1){
		cout<<"please insert a + or * expression please"<<"\n";
		cin>>temp->expression;
		cout<<"New expression detected,";
		set_tree(temp->lc);
		set_tree(temp->rc);
	}

}

int express_tree::evaluate_tree(node* d){
	int answer;
	node* temp=d;
	if(temp->lc->expression!='0'){
		temp=temp->lc;
		evaluate_tree(temp);
	}
		
	else if(temp->rc->expression!='0'){
		temp=temp->rc;
		evaluate_tree(temp);
	}
	else 
		if(temp->expression=='+'){
			answer=temp->lc->data+temp->rc->data;
			return answer;
		}

		if(temp->expression=='*'){
			answer=temp->lc->data*temp->rc->data;
			return answer;
		}

return answer;

}


int main(){
	return 0;

};
