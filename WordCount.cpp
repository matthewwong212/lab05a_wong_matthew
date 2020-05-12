// WordCount.cpp

#include "WordCount.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <algorithm>

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

	//Fill new vector
	for (size_t i = 0; i < CAPACITY; i++) {		//iterate through array
		for(size_t j = 0; j < table[i].size(); j++) {	//iterate through vector
			temp = table[i].at(j);
			sort.push_back(temp);
		}
	}

	//Sort vector
	for (size_t i = 0; i < sort.size()-1; i++) {
		for (size_t j = 0; j < sort.size()-i-1; j++) {
			if (sort.at(j).first < sort.at(j+1).first) {
				swap(sort[j], sort[j+1]);
			}
		}
	}

	//Write vector to out
	for (size_t i = 0; i < sort.size(); i++) {
		out << sort.at(i).first << "," << sort.at(i).second << "\n";
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	vector<pair<string, int>> sort;
	pair<string, int> temp;

	//Write all values to new vector
	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			temp = table[i].at(j);
			sort.push_back(temp);
		}
	}
	
	//Sort vector
	for (size_t i = 0; i < sort.size()-1; i++) {
		for (size_t j = 0; j < sort.size()-i-1; j++) {
			if (sort.at(j).second > sort.at(j+1).second) {		//Compare by occurence, swap is needed
				swap(sort[j], sort[j+1]);
			} else if ( (sort.at(j).second == sort.at(j+1).second) && (sort.at(j).first > sort.at(j+1).first) ){		//Compare by string, swap if needed
				swap(sort[j], sort[j+1]);	
			}
		}
	}

	//Write sorted vector to out
	for (size_t i = 0; i < sort.size(); i++) {
		out << sort.at(i).first << "," << sort.at(i).second << "\n";
	}
}

void WordCount::addAllWords(std::string text) {
	char c[text.size() + 1];
	strcpy(c, text.c_str());

	string temp = "";
	for (auto i : text) {
		if (i == ' ' || i == ',' || i == '\n' || i == '\t') {
			incrWordCount(temp);
			temp = "";
		} else {
			temp = temp + i;
		}
	}
	incrWordCount(temp);
}