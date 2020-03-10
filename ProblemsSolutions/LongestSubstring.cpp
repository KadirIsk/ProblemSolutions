#include <set>
#include "LongestSubstring.h"

int LongestSubstring::findLongestSubstringLength(std::shared_ptr<std::string> str)
{
    auto itForErase = str.get()->begin();
    int max = 0;
    std::shared_ptr<std::set<char>> set = std::make_shared<std::set<char>>();
    for (auto it = str->begin(); it != str->end();) {
        if (set.get()->find(*it) == set.get()->end()) {
            set.get()->insert(*it);
            it++;
        }
        else {
            if (set.get()->size() > max) {
                max = set.get()->size();
            }
            set.get()->erase(*itForErase);
            itForErase++;
        }
    }
    return set.get()->size() > max ? set.get()->size() : max;
}
