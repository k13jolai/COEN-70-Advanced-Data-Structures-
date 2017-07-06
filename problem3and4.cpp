//Coen 70 Homework 2 Chapter 3 Problem 3/4
//Jordan Lai
//
#include<iostream>
#include<cstdlib>

using namespace std;
//The following class "sequence," stores a sequence of numbers using
//an array. Along with this array are a variety of functions that can
//be used to alter the sequence of numbers.
class sequence
{
	public:
		typedef double value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY=30;

		sequence();
		void remove_first();
		void insert_first(const value_type& entry);
		void insert_last(const value_type& entry);
		void last_current();
		friend sequence operator+(const sequence& rhs, const sequence& lhs);
		void operator+=(const sequence& rhs);
//The functions above allow the user to insert/delete/and combine elements
//of one or more sequences
		value_type operator[](size_type index) const;
			
		void start();
		void advance();
		void attach(const value_type& entry);
		void remove_current();
		void insert(const value_type& entry);
		
		size_type size() const;
		bool is_item() const;
		value_type current() const;

	private:
		value_type data[CAPACITY];
		size_type used;
		size_type current_index;

};



sequence::sequence(){used=0, current_index=0;}

void sequence::remove_first(){

	if(used==0){
	cout << "There's nothing here! " << "\n";
	return;	
	}

	data[0]=data[used-1];
	used--;
}

void sequence::insert_first(const value_type& entry){
	if(used==CAPACITY){
		cout << "Maximum capacity has been reached" << "\n";
		return;
	}

	data[used]=data[0];
	data[0]=entry;
	used++;
}

void sequence::insert_last(const value_type& entry){
	if(used==CAPACITY){
		cout <<"Maximum capacity has been reached"  << "\n";
		return;
	}

	data[used]=entry;
	used++;
}

void sequence::last_current(){
	if(used==0){
	cout << "Nothing is the sequence" << "\n";
	return;
	}
	current_index=used-1;
	
}


sequence operator+(const sequence& lhs, const sequence& rhs)
{
	sequence x;
	int i;
	for(i=0;i<lhs.used;i++){
		x.data[i]=lhs.data[i];
		x.used++;
	}

	for(i=0;i<rhs.used;i++){
		x.data[x.used+i]=rhs.data[i];
	}
	
	x.used+=rhs.used;
	
	return x;
}


void sequence::operator+=(const sequence& rhs)
{
	int i;
	for(i=0;i<rhs.used;i++){
		data[used+i]=rhs.data[i];
	}

	used+=rhs.used;
}

void sequence::start(){
	if(used>0)
		current_index=0;
}

void sequence::advance(){
	bool is=is_item();
	if(is==true)
	{
		if(current_index==used-1){
		current_index=-1;
		return;
		}

		current_index++;
	}
}

void sequence::insert(const value_type& entry){

	if(used<CAPACITY){
		
		data[used]=data[current_index-1];
		data[current_index-1]=entry;
		used++;

	}

}

void sequence:: attach(const value_type& entry){
	if(used<CAPACITY){
		data[used]=data[current_index+1];
		data[current_index+1]=entry;
		used++;
	}
}

void sequence::remove_current(){
	bool is=is_item();
	if(is==true)
	{
		data[current_index]=data[used-1];
		used--;
	}
}

sequence::size_type sequence::size() const{
	return used;

}

bool sequence::is_item() const{
	bool result=false;
	if(current_index!=-1)
		result=true;
	return result;
}

sequence::value_type sequence::current() const{
	bool is=is_item();
	if(is==true){
	return data[current_index];
	}

	else 
	return 0;
}
//The following member function [], refers to problem 4. This subscript
//operator allows the user to access individual members of a number
//sequence such as sequence[1], x[4], or y[8].
sequence::value_type sequence::operator[](size_type index)const{
	if(index<used){
	return data[index];
	}

	else
	cout << "not a valid index" << "\n";
	return 0;
}


int main(){


return 0;


}
