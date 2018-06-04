#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

string isWord( string s ){
    
    string word;
    
    for( int i=0 ; i<s.size() ; i++ )
        if( isalpha(s[i]) )
            word+=tolower(s[i]);
    
    return word;
}

int main(int argc, const char * argv[]) {
    ifstream fstopWords;
    fstopWords.open("/Users/main/DataStr practices/lab12/lab12/stopWords.txt");
    string curWord;
    set< string > stopWords;
    while(fstopWords>>curWord){
        stopWords.insert(curWord);
    }
    fstopWords.close();
    ifstream finput;
    finput.open("/Users/main/DataStr practices/lab12/lab12/input.txt");
    map < string, int > freq;
    while(finput>>curWord){
        curWord = isWord(curWord);
        if(stopWords.find(curWord) != stopWords.end()){
            freq[curWord]++;
        }
    }
    multimap<int, string> toSort;
    map<string,int>::iterator it;
    for(it=freq.begin();it!=freq.end();it++)
        toSort.insert(make_pair(it->second,it->first));
    multimap <int,string>::reverse_iterator myit;
    multimap <int,string>::iterator toPercent;
    float percent = 0;
    for (toPercent = toSort.begin();toPercent != toSort.end(); toPercent++)
        percent = percent + (*toPercent).first;
    for (myit=toSort.rbegin(); myit != toSort.rend() ;myit++)
        cout<<(*myit).second<<" "<<(*myit).first<<" %"<<(((*myit).first)/percent)*100<<endl;
    return 0;
}
