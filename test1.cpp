
#include <iostream>
#include <string>
#include <vector>
#include "Review.h"
using namespace std;

int main(){
	Review r;
	string str = "Clean is not a word I'd use to describe this; it really isn't clean";
	r.text = str;
	cout << "string: " << str << endl;
	cout << "Occurrences of 'clean:' " << r.getOccurrencesOf("clean") << endl;
	cout << "Nonnegated occurrences of 'clean:' " << r.getNonNegated("clean") << endl;
	
	getchar();
}