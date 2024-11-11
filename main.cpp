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

int main()
{
    ahoCorasickDefaultTest();
    return 0;
}
