#ifndef REVIEW_H
#define REVIEW_H
#include <ctime>
#include <string>
#include <vector>
using namespace std;
class Review{
private:
	tm time;
	time_t curTime;
	bool isNegWord(string word);
	vector<string> split(string s, char delim);

public:
	Review();
	Review(tm time);

	double rating;
	string title,
		poster,
		text;

	const enum Measure {TIME, RATING, TITLE, OCCURRENCES, NONNEGATED};
	Measure m;
	string compareWord;
	
	int getOccurrencesOf(string word);
	int getNonNegated(string word);

	int compareRating(Review other);
	int compareTime(Review other);
	int compareTitle(Review other);

	bool operator<(Review other);
	bool operator>(Review other);
};
#endif 