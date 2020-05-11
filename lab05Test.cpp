#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>

using namespace std;

int main() {
	//Test basic function
	ostringstream test0, test1;
	WordCount basicTest;
	basicTest.addAllWords("sentence is a fun fun sentence");
	basicTest.dumpWordsSortedByWord(test0);
	basicTest.dumpWordsSortedByOccurence(test1);
	ASSERT_EQUALS("sentence,2\nis,1\nfun,2\na,1\n", test0.str());
	ASSERT_EQUALS("a,1\nis,1\nfun,2\nsentence,2\n", test1.str());

	//Test with hyphens
	ostringstream hTest0, hTest1;
	WordCount hyphenTest;
	hyphenTest.addAllWords("purple people chicken-feet event act-ual some-way");
	hyphenTest.dumpWordsSortedByWord(hTest0);
	hyphenTest.dumpWordsSortedByOccurence(hTest1);
	ASSERT_EQUALS("some-way,1\npurple,1\npeople,1\nevent,1\nchicken-feet,1\nact-ual,1\n", hTest0.str());
	ASSERT_EQUALS("act-ual,1\nchicken-feet,1\nevent,1\npeople,1\npurple,1\nsome-way,1\n", hTest1.str());

	//Test with varying occurences
	ostringstream nTest0, nTest1;
	WordCount numTest;
	numTest.addAllWords("a a a a a a c c c c c c z z z j j b");
	numTest.dumpWordsSortedByWord(nTest0);
	numTest.dumpWordsSortedByOccurence(nTest1);
	ASSERT_EQUALS("z,3\nj,2\nc,6\nb,1\na,6\n", nTest0.str());
	ASSERT_EQUALS("b,1\nj,2\nz,3\na,6\nc,6\n", nTest1.str());

	//Test with apostrophes
	ostringstream aTest0, aTest1;
	WordCount aposTest;
	aposTest.addAllWords("ain't a thang isn't a thang");
	aposTest.dumpWordsSortedByWord(aTest0);
	aposTest.dumpWordsSortedByOccurence(aTest1);
	ASSERT_EQUALS("thang,2\nisn't,1\nain't,1\na,2\n", aTest0.str());
	ASSERT_EQUALS("ain't,1\nisn't,1\na,2\nthang,2\n", aTest1.str());

	return 0;
}