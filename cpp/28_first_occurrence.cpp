#include <iostream>
#include <vector>

/**
 * use the KMP (knuth-Morris-Pratt algorithm) to get the
 * first occurrence of string needle from haystack
 *
 */

std::vector<int> createLPS(const std::string &pattern)
{

    std::vector<int> lps(pattern.size(), 0);

    int i = 0, j = 1, m = pattern.size();
    while (j < m)
    {

        if (pattern[i] == pattern[j])
        {
            lps[j] = i + 1;
            j++;
            i++;
        }
        else
        {

            if (i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }
    }

    return lps;
}

int strStr(std::string haystack, std::string needle)
{
    std::vector<int> lps = createLPS(needle);

    int i = 0, j = 0, n = haystack.size(), m = needle.size();

    while (i < n)
    {

        if (haystack[i] == needle[j])
        {
            i++;
            j++;

            if (j == m)
            { // whole needle pattern found

                return i - j;
            }
        }
        else
        {

            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return -1;
}

int main()
{
    std::cout << strStr("mississippi", "issip");
    return 0;
}