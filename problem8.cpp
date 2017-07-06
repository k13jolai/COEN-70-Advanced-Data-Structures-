//Coen 70 Homework 2: Chapter 3 problem 8
//Jordan Lai
#include<iostream>
#include<cstdlib>
//The following class keyed is a keyed bag, which assigns a key to 
//each individual value in the array of data. This key is used to keep 
//track of each individual element in the array.
using namespace std;

class keyed{

	public:
		typedef int value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY=30;

		keyed();
		void insert(const value_type& entry, int keynum);
		bool check_key(int keynum);

//In addition to an array of data elements, there is a corresponding
//array of keys (key) used to keep track of the keys of each element.
	private:
		value_type data[CAPACITY];
		value_type key[CAPACITY];
		size_type used;
};

keyed::keyed() {used=0;}
//Unlike the bag, the keyed bag not only checks to see if there is already
//an existing copy of a key, but also assigns a key to the corresponding 
//spot in the key array once a new element is inserted.
void keyed::insert(const value_type& entry, int keynum){
	if(used<CAPACITY){
		bool is=check_key(keynum);
		if(is==true){
			cout << "key already exists!"  << "\n";
			return;
		}
		data[used]=entry;
		key[used]=keynum;
		used++;
	}
	
	else
	cout << "Maximum capacity has been reached" << "\n";
}
//The function check_key goes through the array of keys to check if the 
//specified key number currently exists, and returns true if it does.
//This function is important when implementing other functions such as 
//insert and delete.  
bool keyed::check_key(int keynum){
	int i;
	bool result=false;
	for(i=0;i<used;i++){
		if(key[i]==keynum)
			result=true;
	}
	return result;
}

int main(){
	return 0;
}
