// LCOV_EXCL_START

// Прописываю флаг выше, для того чтобы лишний файл не попадал в репорт
#include <iostream>
#include "AhoCorasick.hpp"
#include <cassert>

void ahoCorasickDefaultTest()
{
    AhoCorasick ac;
    ac.insertPattern("he", 0);
    ac.insertPattern("she", 1);
    ac.insertPattern("his", 2);
    ac.insertPattern("hers", 3);

    ac.build();

    std::vector<int> matches = ac.search_for_patterns("ushers");

    assert(matches.size() == 3);
}

void ahoCorasickEmptyTest()
{
    AhoCorasick ac;
    ac.build();

    std::vector<int> matches = ac.search_for_patterns("ushers");

    assert(matches.empty());
}

void ahoCorasickOnePatternTest()
{
    AhoCorasick ac;
    ac.insertPattern("he", 0);

    ac.build();

    std::vector<int> matches = ac.search_for_patterns("ushers");

    assert(matches.size() == 1);
}

int main()
{
    ahoCorasickDefaultTest();
    ahoCorasickEmptyTest();
    ahoCorasickOnePatternTest();

    return 0;
}
// LCOV_EXCL_STOP
