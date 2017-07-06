//Coen 70 Homework 2 Chapter 3 Problem 5
//Jordan Lai
#include<iostream>
#include<cstdlib>
 //The following class set contains a group of unique numbers, which are
 //all stored in an array
using namespace std;
	     
class set{
			   
    public:
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY=30;
				  
    set();
	void insert(int y);
    friend set operator-(const set& lhs, const set& rhs);
	bool contains(const value_type& target) const;				   
						     
//Unlike the bag data type, a set has a member function contains that
//checks for the user whether or not the specified value already exists in 
//the set. 	
							   
	 private:
     value_type data[CAPACITY];
     size_type used;
						  
 };
 
//default contructor time: O(1)
set::set() {used=0;}

//Insert time: is O(n), since it must call contains to search for y in the
//set
void set::insert(int y)
{
   bool can_i=contains(y);
   if(can_i==true){
	 cout << "value already exists in set" << "\n";
	}
   if(used<CAPACITY){
      data[used]=y;
			     
    }

   else
     cout << "Maximum capacity has been reached" << "\n";
				  
}

//Contains run time: O(n), since it runs through an array to search for
//a specified value.
bool set::contains(const value_type& target) const{
	bool result=false;
	int i;
	for(i=0;i<used;i++)
	{
		if(data[i]==target)
		{
			result=true;
			return result;
		}
	}
	return result;
}
//subtraction operator run time: O(n^2), since there is a nested for loop.
set operator-(const set& lhs, const set& rhs){
	int i;
	int target;
	int found;
	set difference;
	for(i=0;i<rhs.used;i++){
		found=0;
		target=rhs.data[i];
		for(i=0;i<lhs.used;i++)
		{
			if(lhs.data[i]==target){
				found=1;
			}
		}
		if(found==1){
			difference.data[difference.used]=target;
			difference.used++;
		}
	}
return difference;
}

int main(){
	return 0;
}
