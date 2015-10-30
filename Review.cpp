#include "Review.h"
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> Review::split(string s, char delim){
	for(unsigned int i=0; i<s.length(); i++){
		if(!isalnum(s[i]) && s[i]!='\'')
			s[i] = ' ';
	}
	vector<string> v;
	string curstr = "";
	for(unsigned int i=0; i<s.length(); i++){
		if(s[i]==delim){
			v.push_back(curstr);
			curstr = "";
		}
		else{
			curstr+=s[i];
		}
	}
	v.push_back(curstr);
	return v;
}
bool Review::isNegWord(string word){
	return (word=="not" || word=="no" || word=="isnt" || word=="isn't" || word=="doesnt" || word=="doesn't" || word=="dont"
		|| word=="don't" || word=="non" || word=="never" || word=="aint" || word=="ain't");
}

int Review::getOccurrencesOf(string word){
	for(unsigned int i=0; i<word.length(); i++)
		word[i] = tolower(word[i]);
	string total = (title+"      "+text);
	for(unsigned int i=0; i<total.length(); i++)
		total[i] = tolower(total[i]);
	vector<string> words = split(total, ' ');
	int c = 0;
	for each (string str in words){
		if(str==word)
			c++;
	}
	return c;
}
int Review::getNonNegated(string word){
	for(unsigned int i=0; i<word.length(); i++)
		word[i] = tolower(word[i]);
	string total = (title+"      "+text);
	for(unsigned int i=0; i<total.length(); i++)
		total[i] = tolower(total[i]);
	vector<string> words = split(total, ' ');
	int c=0;
	for(unsigned int i=0; i<words.size(); i++){
		if(words[i]==word){
			bool nonnegated = true;
			for(int j=-3; j<=3; j++)
				if(i+j>=0 && i+j<words.size())
					if(isNegWord(words[i+j]))
						nonnegated = false;
			if(nonnegated) c++;
		}
	}
	return c;
}

int Review::compareRating(Review other){
	if (rating>other.rating)
		return 1;
	if(rating<other.rating)
		return -1;
	return 0;
}
int Review::compareTitle(Review other){
	return text.compare(other.text);
}
int Review::compareTime(Review other){
	time_t ttime = mktime(&time);
	time_t otime = mktime(&(other.time));
	return (int)(ttime-otime);
}

bool Review::operator<(Review other){
	switch(m){
	case TIME: 
		return curTime<other.curTime;
		break;
	case RATING: 
		return rating<other.rating;
		break;
	case TITLE: 
		return title<other.title;
		break;
	case OCCURRENCES: 
		return getOccurrencesOf(compareWord)<other.getOccurrencesOf(other.compareWord);
		break;
	case NONNEGATED: 
		return getNonNegated(compareWord)<other.getNonNegated(other.compareWord);
		break;
	}
	return false;
}

bool Review::operator>(Review other){
	switch(m){
	case TIME: 
		return curTime>other.curTime;
		break;
	case RATING: 
		return rating>other.rating;
		break;
	case TITLE: 
		return title>other.title;
		break;
	case OCCURRENCES: 
		return getOccurrencesOf(compareWord)>other.getOccurrencesOf(other.compareWord);
		break;
	case NONNEGATED: 
		return getNonNegated(compareWord)>other.getNonNegated(other.compareWord);
		break;
	}
	return false;
}

Review::Review() : curTime(std::time(NULL)), time(*localtime(&curTime)), compareWord(""){
}
Review::Review(tm time) : time(time), curTime(mktime(&time)), compareWord(""){
}