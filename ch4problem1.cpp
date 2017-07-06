//Coen 70 Homework 2 Chapter 4 Problem 1
//Jordan Lai
#include<iostream>
#include<string>

using namespace std;
//The class strings holds an array of characters within the allocated 
//length. 
class strings{

	public:
	strings(const char str[]);
	strings(char a);
	~strings();
	void replace_char(char a, char b);
	bool search_char(char a);
	int search_occurence(char a);
	bool search_string(const char str[]);

//Based on the string given, the class allocates a given amount of memory 
//to hold that string.
	private:
	int allocated;
	char* characters;
	int current_length;

};



strings::strings(const char str[]){

current_length = strlen(str);
allocated= current_length+1;
characters = new char[allocated];
strcpy(characters, str);


}
//The member function below takes one character and creates a string 
//holding only that character
strings::strings(char a){
	current_length=1;
	allocated=current_length+1;
	characters=new char[allocated];
	characters[0]=a;

}
//The deconstructor deletes the memory of the string.
strings::~strings(){

	delete [] characters;


}
//The replace_char function searches for a character a and replaces it with 
//character b
void strings::replace_char(char a, char b){
	int i;
	for(i=0;i<current_length;i++){
		if(characters[i]==a){
			characters[i]=b;
			return;
		}
	}
	return;
}
//The function search char searches a string for a given character a and 
//returns true if it does, and false otherwise.
bool strings::search_char(char a){
	int i;
	bool result=false;
	for(i=0;i<current_length;i++){
		if(characters[i]==a){
			result=true;
		}
	}
	return result;
	
}
//The function search_occurence searches a string and returns the number
//of times character a occurs 
int strings::search_occurence(char a){
	int i;
	int count=0;
	for(i=0;i<current_length;i++){
		if(characters[i]==a){
				count++;
		}
	}	
	return count;
}

//The function search_string searches a string to see if it 
//contains a smaller given string

bool strings::search_string(const char str[])
{
	int i;
	bool result=false;
	int length=strlen(str);
	int count;
	for(i=0;i<current_length;i++){
		if(characters[i]==str[0]){
			int start=i;
			for(i=0;i<length;i++){
				if(characters[start+i]==str[i])
					count++;
			}
		}
	}
	if(count==length){
		result=true;
	}
	return result;
}
int main(){
	return 0;

}
