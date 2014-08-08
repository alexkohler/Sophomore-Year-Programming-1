#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

int main( )
{
	map <char, int> letters;		
	map <char, int>::iterator iter;	
	string user_text;		
	
	cout << endl << "Please enter some text and press enter: ";
		getline( cin, user_text );
		


for ( unsigned int i=0; i< user_text.size(); ++i )
{
   ++letters[user_text[i]] ;
}




}