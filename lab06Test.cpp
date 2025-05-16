#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

int main() {

    WordCount hashT;
    ASSERT_EQUALS(0, hashT.getTotalWords());
    ASSERT_EQUALS(0, hashT.getNumUniqueWords());
    ASSERT_EQUALS(0, hashT.getWordCount("Hello"));
    ASSERT_EQUALS("a", hashT.makeValidWord("----A----"));

    hashT.incrWordCount("Hello");
    ASSERT_EQUALS(1, hashT.getTotalWords());
    ASSERT_EQUALS(1, hashT.getNumUniqueWords());
    ASSERT_EQUALS(1, hashT.getWordCount("Hello"));
    hashT.incrWordCount("Hello");
    hashT.incrWordCount("HelloFriend");
    ASSERT_EQUALS(2, hashT.getNumUniqueWords());
    ASSERT_EQUALS(2, hashT.getWordCount("Hello"));
    ASSERT_EQUALS(3, hashT.getTotalWords());
    hashT.decrWordCount("HelloFriend");
    ASSERT_EQUALS(1, hashT.getNumUniqueWords());
    ASSERT_EQUALS(2, hashT.getTotalWords());
    ASSERT_EQUALS(0, hashT.getWordCount("HelloFriend"));
    hashT.decrWordCount("Hello");
    ASSERT_EQUALS(1, hashT.getNumUniqueWords());
    ASSERT_EQUALS(1, hashT.getTotalWords());
    ASSERT_EQUALS(1, hashT.getWordCount("Hello"));

    return 0;
}