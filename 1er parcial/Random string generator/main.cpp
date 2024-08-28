#include <iostream>
#include <string>
#include "random.h"

using namespace std;

string genstring(int, char, char);

int main(int argc, char const *argv[]){
    initialize();
    
    int words_number, len;
    char alpha, beta;

    cin >> words_number;
    cin >> len;
    cin >> alpha;
    cin >> beta;

    cout<<endl;

    for (int i = 0; i < words_number; i++){
        string random_word = genstring(len, alpha, beta);
        cout<<random_word<<endl;
    }

    return 0;
}

string genstring(int len, char alpha, char beta){
    int word_len = random_int(0, len);

    if (word_len < 1){
        return "<void>";
    }
    
    string random_word = "";


    for (int i = 0; i < word_len; i++)
    {
        int random_char = random_int((int)alpha, (int)beta);
        random_word += ((char)random_char);
    }

    return random_word;
    
    
    
}