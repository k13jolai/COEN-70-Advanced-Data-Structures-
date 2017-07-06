//Coen 70 Homework 2 Problem 2
//Jordan Lai
#include<iostream>
#include<cstdlib>
//The follwoing class bag stores a group of numbers into an array.
using namespace std;

class bag{

	public:
		typedef int value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY=30;

		bag();
		void insert(int y);
		friend bag operator-(const bag& lhs, const bag& rhs);
		void  operator-=(const bag& rhs);
		//the following operators - and -= have been overloaded into this 
		//file.
	


	private:
		value_type data[CAPACITY];
		size_type used;

};

bag::bag() {used=0;};

void bag::insert(int y)
{
	if(used<CAPACITY){
		data[used]=y;
		used++;
	}

	else
	cout << "Maximum capacity has been reached" << "\n";

}
//The -= function takes a given bag and removes any elements found in the
//current bag. It should be noted that if there are more copies of a certain element in the current bag, only the amount found in the specified bag will be removed. 
void bag::operator-=(const bag& rhs)
{
	int i;
	int target;
	int found=0;
	for(i=0;i<rhs.used;i++){
		target=rhs.data[i];
		while(found==0){
			for(i=0;i<used;i++){
				if(data[i]==target){
					data[i]=data[used-1];
					used--;
					found=1;
				}
			}
		}

	}
}
//The - function operates the same way the -= operator does, execpt for the
//fact that a new bag is returned instead of internally changing a 
//pre-existing one. 
bag operator-(const bag& lhs, const bag& rhs){

	int i;
	int target;
	int found;
	int count;
	int count2;
	bag difference;
	for(i=0;i<rhs.used;i++){
		count=0;
		count2=0;
		found=0;
		target=rhs.data[i];
		for(i=1;i<rhs.used;i++)
		{
			if(rhs.data[i]==target)
			{
				count++;
			}
		for(i=0;i<lhs.used;i++)
		{
			if(lhs.data[i]==target)
				found++;
		}
		if(found>count)
			for(i=0;i<difference.used;i++)
			if(difference.data[i]==target)
				count2++;
			if (found>(count+count2))
			difference.data[difference.used]=target;
			difference.used++;
		}
	}
	return difference;
}
int main(){

	return 0;
}

