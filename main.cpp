// LCOV_EXCL_START

// Прописываю флаг выше, для того чтобы лишний файл не попадал в репорт
#include <iostream>
#include "AhoCorasick.hpp"
#include <cassert>

void emptyPatternTest()
{
    AhoCorasick ac;
    ac.build();
    assert(ac.search_for_patterns("Hello!").empty());
}

void oneMatchingPatternTest()
{
    AhoCorasick ac;
    ac.insertPattern("he", 0);
    ac.build();

    assert(ac.search_for_patterns("ushers").size() == 1);
}

void noMathicngPatternsTest()
{
    AhoCorasick ac;
    ac.insertPattern("Hello", 0);
    ac.insertPattern("World", 1);
    ac.build();

    assert(ac.search_for_patterns("abacaba").size() == 0);
}

void overlappingPatternsTest()
{
    AhoCorasick ac;
    ac.insertPattern("abc", 0);
    ac.insertPattern("abcd", 1);
    ac.insertPattern("abcde", 2);
    ac.build();

    assert(ac.search_for_patterns("abcde").size() == 3);
}

// Тут суфф ссылки +-интереснее: ведут в другие ветки бора (примерно можно глянуть у итмо в конспекте)
void suffixLinkTest()
{
    AhoCorasick ac;
    ac.insertPattern("she", 0);
    ac.insertPattern("he", 0);
    ac.build();
    assert(ac.search_for_patterns("hehe").size() == 2);
}

void runTests()
{
    std::cout << "Running tests..." << std::endl;
    emptyPatternTest();
    oneMatchingPatternTest();
    noMathicngPatternsTest();
    overlappingPatternsTest();
    suffixLinkTest();
    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    runTests();
    return 0;
}
// LCOV_EXCL_STOP
