#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>

using namespace std;

int main() {
	//Test incremenent and decrement of valid words
	// WordCount testValidWords, testEmpty;

	// testValidWords.incrWordCount("one");
	// testValidWords.incrWordCount("two");
	// testValidWords.incrWordCount("two");
	// testValidWords.incrWordCount("three");
	// testValidWords.incrWordCount("three");
	// testValidWords.incrWordCount("three");

	// ASSERT_EQUALS(0, testEmpty. getWordCount("one"));
	// ASSERT_EQUALS(1, testValidWords.getWordCount("one"));
	// ASSERT_EQUALS(2, testValidWords.getWordCount("two"));
	// ASSERT_EQUALS(3, testValidWords.getWordCount("three"));

	// ASSERT_EQUALS(3, testValidWords.getNumUniqueWords());
	// ASSERT_EQUALS(6, testValidWords.getTotalWords());


	// testValidWords.decrWordCount("one");
	// testValidWords.decrWordCount("two");
	// testValidWords.decrWordCount("three");

	// ASSERT_EQUALS(0, testValidWords.getWordCount("one"));
	// ASSERT_EQUALS(1, testValidWords.getWordCount("two"));
	// ASSERT_EQUALS(2, testValidWords.getWordCount("three"));

	// ASSERT_EQUALS(2, testValidWords.getNumUniqueWords());
	// ASSERT_EQUALS(3, testValidWords.getTotalWords());



	// //Test use of invalid words
	// WordCount testInvalidWords;

	// testInvalidWords.incrWordCount("!!!!!!!");
	// testInvalidWords.incrWordCount("inV&*#a**lid");
	// testInvalidWords.incrWordCount("Invali!!!!!d");
	// testInvalidWords.incrWordCount("INVA    LID!!!!");
	// testInvalidWords.incrWordCount("thisisa88242word");

	// ASSERT_EQUALS(0, testInvalidWords.getWordCount("!!!!!!!"));
	// ASSERT_EQUALS(3, testInvalidWords.getWordCount("invalid"));

	// testInvalidWords.decrWordCount("!!!!!!!");
	// testInvalidWords.decrWordCount("inva1562354lid");

	// ASSERT_EQUALS(0, testInvalidWords.getWordCount("!!!!!!!"));
	// ASSERT_EQUALS(2, testInvalidWords.getWordCount("invalid"));

	// //Test number of unique words
	// ASSERT_EQUALS(2, testInvalidWords.getNumUniqueWords());
	// ASSERT_EQUALS(0, testEmpty.getNumUniqueWords());

	// //Test total words
	// ASSERT_EQUALS(3, testInvalidWords.getTotalWords());
	// ASSERT_EQUALS(0, testEmpty.getTotalWords());

	//Test ostream
	ostringstream test;
	WordCount nTest;
	//nTest.addAllWords("Sentence \nis a sentence");
	nTest.addAllWords("sentence is a fun fun sentence");
	// nTest.incrWordCount("this-a");
	// nTest.incrWordCount("and");
	// nTest.incrWordCount("z");
	// nTest.incrWordCount("this-b");
	//nTest.dumpWordsSortedByWord(test);
	nTest.dumpWordsSortedByOccurence(test);
	cout << test.str();

	return 0;
}