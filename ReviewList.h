#ifndef REVIEWLIST_H
#define REVIEWLIST_H
#include <vector>
#include "Review.h"
#include <string>
using namespace std;
class ReviewList{
public:
	ReviewList();
	ReviewList(vector<Review> v);

	vector<Review> reviews;

	vector<Review> getSortedByTime();
	vector<Review> getSortedByRating();
	vector<Review> getSortedByTitle();

	vector<Review> getSortedByOccurrences(string word);
	vector<Review> getSortedByNonNegated(string word);

	Review getMedianByTime();
	Review getMedianByRating();
	Review getMedianByTitle();

	int getMeanRating();
	
	Review getTypical();
	Review getTypicalWith(vector<string> words);
};
#endif