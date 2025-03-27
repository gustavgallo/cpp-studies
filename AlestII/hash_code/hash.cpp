#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;


int main() {
    
    ifstream file("dc2.txt");
    
    if (!file.is_open()) {
        throw runtime_error("Deu erro");
    }

    unordered_map<string,int> wordCount;
    string word;

    while(file >> word){
        for(size_t i = 0; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }

        wordCount[word]++;
    }
    
    string mostFrequentWord;
    int maxCount = 0;

    for (const auto &entry : wordCount) {
        if (entry.second > maxCount) {
            mostFrequentWord = entry.first;
            maxCount = entry.second;
        }
    }
   
    for(const auto entry : wordCount){
        cout<< entry.first << " : "<< entry.second << endl;
    }

    cout << "Palavra mais frequente: " << mostFrequentWord << " (" << maxCount << " vezes)" << endl;
    


    return 0;
}







