/*
AUTOR:      Luis Villalobos
CURSO:      Teoria de la computación
PROGRAMA:   Operaciones con lenguajes
FECHA:      18 de septiembre del 2024
*/
#include <iostream>
#include <set>
#include <string>
#include "random.h"


using namespace std;

typedef set<string> lang;

string genstring(int, char, char);
lang generate(int, int, char, char);
void print(lang);
lang lang_union(lang,lang);
lang lang_intersection(lang,lang);
lang lang_difference(lang,lang);
lang lang_concatenation(lang,lang);
lang lang_power(lang,int);

int main(int argc, char const *argv[]){
    initialize();
    
    int m, n, p;
    char alpha,beta;
    cin>>m;
    cin>>n;
    cin>>p;
    cin>>alpha;
    cin>>beta;

    int leng_lang_a = random_int(1,m);
    int leng_lang_b = random_int(1,m);

    lang lang_a = generate(n, leng_lang_a, alpha, beta);
    lang lang_b = generate(n, leng_lang_b, alpha, beta);

    cout <<"\n"<<"A: ";
    print(lang_a);
    cout << "B: ";
    print(lang_b);
    cout<<"\n"<<"Union: "<<endl;
    print(lang_union(lang_a,lang_b));
    cout<<"\n"<<"Intersection: "<<endl;
    print(lang_intersection(lang_a,lang_b));
    cout<<"\n"<<"Difference: "<<endl;
    print(lang_difference(lang_a,lang_b));
    cout<<"\n"<<"Concatenation: "<<endl;
    print(lang_concatenation(lang_a,lang_b));
    cout<<"\n"<<"A power "<<p<<":"<<endl;
    print(lang_power(lang_a,p));
    cout<<"\n"<<"B power "<<p<<":"<<endl;
    print(lang_power(lang_b,p));

    return 0;
}

void print(lang l){
    cout << "[ ";
    for (set<string>::iterator it = l.begin(); it != l.end(); it++){
        if (*it == ""){
            cout << "<void> ";
            continue;
        }
        cout << *it << " ";
    }
    cout << "]" << endl;
    return;
}

lang generate(int n, int m, char alpha, char beta){
    lang l;
    if (m < 1){
        //l.insert("");
        return l;
    }
    for (int i = 0; i < m; i++)
    {
        l.insert(genstring(n, alpha, beta));
    }
    return l;
}

lang lang_union(lang a,lang b){
    lang l;
    for (set<string>::iterator it = a.begin(); it != a.end(); it++){
        l.insert(*it);
    }
    for (set<string>::iterator it = b.begin(); it != b.end(); it++){
        l.insert(*it);
    }
    return l;
}

lang lang_intersection(lang a,lang b){
    lang l;

    for (set<string>::iterator it = a.begin(); it != a.end(); it++){
        if (b.find(*it) != b.end()){
            // if (*it == ""){
            //     continue;
            // }
            l.insert(*it);
        }
    }

    return l;    
}

lang lang_difference(lang a,lang b){
    lang l;
    for (set<string>::iterator it = a.begin(); it != a.end(); it++){
        if (b.find(*it) == b.end()){
            l.insert(*it);
        }
    }
    return l;
}

lang lang_concatenation(lang a,lang b){
    lang l;
    for (set<string>::iterator it = a.begin(); it != a.end(); it++){
        for (set<string>::iterator it2 = b.begin(); it2 != b.end(); it2++){
            l.insert(*it + *it2);
        }
    }
    return l;
}

lang lang_power(lang a,int p){
    lang l;
    if (p == 0){
        l.insert("");
        return l;
    }
    lang temp = a;
    for (int i = 1; i < p; i++){
        temp = lang_concatenation(temp, a);
    }
    return temp;
}

string genstring(int len, char alpha, char beta){
    int word_len = random_int(0, len);

    if (word_len < 1){
        return "";
    }
    
    string random_word = "";


    for (int i = 0; i < word_len; i++)
    {
        int random_char = random_int((int)alpha, (int)beta);
        random_word += ((char)random_char);
    }

    return random_word;
    
    
    
}