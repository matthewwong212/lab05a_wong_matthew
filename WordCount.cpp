// WordCount.cpp

#include "WordCount.h"
#include <iostream>
#include <sstream>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int words = 0;

	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			words = words + table[i].at(j).second;
		}
	}

	return words;
}

int WordCount::getNumUniqueWords() const {
	int words = 0;

	for (size_t i = 0; i < CAPACITY; i++) {
		words = words + table[i].size();
	}

	return words;
}

int WordCount::getWordCount(std::string word) const {
	string valid = makeValidWord(word);
	size_t ndx = hash(valid);

	//search for word
	for (size_t i = 0; i < table[ndx].size(); i++) {
		if (table[ndx].at(i).first == valid) {
			return table[ndx].at(i).second;
		}
	}

	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string valid = makeValidWord(word);
	size_t ndx = hash(valid);

	//invalid word, do nothing
	if (valid == "") {
		return 0;
	}

	//Search for repeated word
	for (size_t i = 0; i < table[ndx].size(); i++) {
		//Repeated word, increment word count
		if (table[ndx].at(i).first == valid) {
			table[ndx].at(i).second++;
			return table[ndx].at(i).second;
		}
	}

	//Word not found, append to vector
	pair<string, int> temp;
	temp.first = valid;
	temp.second = 1;
	table[ndx].push_back(temp);
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	string valid = makeValidWord(word);
	size_t ndx = hash(valid);

	for (size_t i = 0; i < table[ndx].size(); i++) {
		if (table[ndx].at(i).first == valid) {			//Found matching word
			if (table[ndx].at(i).second == 1) {			//only one word
				table[ndx].erase(table[ndx].begin()+i);	//Erase entry
				return 0;
			} else {
				table[ndx].at(i).second--;
				return table[ndx].at(i).second;
			}
		}
	}

	//word not found
	return -1;
}


bool WordCount::isWordChar(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return true;
	} else {
		return false;
	}
}

std::string WordCount::makeValidWord(std::string word) {
	std::ostringstream oss;

	for (unsigned i = 0; i < word.length(); i++) {
		if (isWordChar(word.at(i))) {
			oss << word.at(i);
		} else if (i > 0 && i < word.length()-1) {
			if ( (isWordChar(word.at(i-1))) && ((word.at(i) == '-') || (word.at(i) == '\'')) && (isWordChar(word.at(i+1))) ) {
				oss << word.at(i);
			}
		}
	}

	string temp = oss.str();
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

	return temp;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	vector<pair<string, int>> sort;
	pair<string, int> temp;
	size_t sortedSize;

	//Insert in sorted order into new vector
	for (size_t i = 0; i < CAPACITY; i++) {		//iterate through array
		for(size_t j = 0; j < table[i].size(); j++) {	//iterate through vector
			temp = table[i].at(j);

			sortedSize = sort.size();
			size_t k = 0;
			do {
				if (k == 0) {
					if (sortedSize == 0) {			//empty vector
						sort.push_back(temp);
						break;
					} else if (sortedSize == 1) {	//one element in vector
						if (temp.first < sort.at(0).first) {
							sort.push_back(temp);
							break;
						} else {
							sort.insert(sort.begin(), temp);
							break;
						}
					}
				} else {							//At least 2 elements in vector, starts at k=1
					if ( (temp.first < sort.at(k-1).first) && (temp.first > sort.at(k).first) ) {	//Insert between element k-1 and k
						sort.insert(sort.begin()+k, temp);
						break;
					} else if (k == sortedSize - 1) {	//Last (smallest) element in list, append at back
						sort.push_back(temp);
						break;
					} else {
						cout << "ERROR: Didn't meet any conditions.  Should not reach this." << endl;
					}
				}
				k++;
			} while (k < sortedSize);
		}
	}

	//Write vector to out
	for (size_t i = 0; i < sort.size(); i++) {
		out << sort.at(i).first << "," << sort.at(i).second << "\n";
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// STUB
}

void WordCount::addAllWords(std::string text) {
	//STUB
}
