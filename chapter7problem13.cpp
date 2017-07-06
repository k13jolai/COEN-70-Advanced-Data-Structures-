//This function compare_stacks is a friend function of the stack class
//that looks directly into the stack to check the elements.
//
//Jordan Lai Coen70 Homework 4
//Chapter 7 Problem 13 

bool compare_stacks(stack const& rhs){
	int i,j=0;
	bool result=false;
//The while loop checks all members of two stacks. If the counter, j, is 
//equal to the size after the loop ends, then the two stacks are equal.
	while(numstack[i]!='0'){
		if(numstack[i]==rhs.numstack[i]){
			j++;
		}
		
		i++;


	}
	if(j==size){
	result=true;
	}

	return result;
}	
int main(){


}
