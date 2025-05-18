#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

int main() {

    WordCount hashT;
    //Check full battery to start
    ASSERT_EQUALS(0, hashT.getTotalWords());
    ASSERT_EQUALS(0, hashT.getNumUniqueWords());
    ASSERT_EQUALS(0, hashT.getWordCount(""));

    hashT.incrWordCount("Hello-$");
    ASSERT_EQUALS(1, hashT.getWordCount("Hello"));
    ASSERT_EQUALS(1, hashT.getTotalWords());
    ASSERT_EQUALS(1, hashT.getWordCount("Hello-$"));
    ASSERT_EQUALS(1, hashT.getNumUniqueWords());
    hashT.incrWordCount("--Hello~~");
    ASSERT_EQUALS(2, hashT.getWordCount("Hello!"));

    hashT.incrWordCount("Friend");
    ASSERT_EQUALS(2, hashT.getNumUniqueWords());
    hashT.incrWordCount("-~Fr-end~!");
    ASSERT_EQUALS(3, hashT.getNumUniqueWords());
    ASSERT_EQUALS(1, hashT.getWordCount("Friend"));
    ASSERT_EQUALS(0, hashT.decrWordCount("Friend!"));
    ASSERT_EQUALS(-1, hashT.decrWordCount("--Friend"));
    ASSERT_EQUALS(3, hashT.getTotalWords());
    ASSERT_EQUALS(2, hashT.getNumUniqueWords());
    ASSERT_EQUALS(1, hashT.decrWordCount("Hello"));
    ASSERT_EQUALS(2, hashT.getTotalWords());
    ASSERT_EQUALS(2, hashT.incrWordCount("!-Hello"));
    ASSERT_EQUALS(2, hashT.incrWordCount("Fr-end"));
    ASSERT_EQUALS(4, hashT.getTotalWords());
    ASSERT_EQUALS(2, hashT.getNumUniqueWords());

    return 0;
}