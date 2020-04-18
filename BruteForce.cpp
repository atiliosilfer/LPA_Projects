#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> substrings1;
  vector<string> substrings2;

  string s1, s2, teste;
  int numCases;
  bool contains = false;
  cin >> numCases;

  for (int i = 0; i < numCases; i++) {
    cin >> s1 >> s2;
    substrings1.clear();
    substrings2.clear();
    contains = false;

    for (int j = 0; j < s1.length(); j++) {
      for (int k = 1; k < s1.length()+1; k++) {
        for (int l = 0; l < substrings1.size(); l++) {
          contains = substrings1.at(l) == s1.substr(j, k);
          l = contains ? substrings1.size() : l;
        }
        if (!contains) {
          substrings1.push_back(s1.substr(j, k));
        }
        contains = false;
      }
      
    }

    for (int j = 0; j < s2.length(); j++) {
      for (int k = 1; k < s2.length()+1; k++) {
        for (int l = 0; l < substrings2.size(); l++) {
          contains = substrings2.at(l) == s2.substr(j, k);
          l = contains ? substrings2.size() : l;
        }
        if (!contains) {
          substrings2.push_back(s2.substr(j, k));
        }
        contains = false;
      }
      
    }

    ((substrings1.size()) == (substrings2.size())) ? cout << "s" << endl : cout << "n" << endl;
  }

  return 0;
}