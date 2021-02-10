#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<vector<string>> parseText(string& text){
    string sentence;
    string word;
    vector<vector<string>> sepText;
    vector<string> words;
    int i = 0;
    int j;
    while(i != text.length() - 1){
        sentence += text[i];
        if(text[i] == '.'){ //separate text by sencteces
            j = 0;
            while (j < sentence.size()){
                if(sentence[j] == ' '|| sentence[j] == '.'){ //separate sencteces by words
                    words.push_back(word); // save words in vector that represents vectors
                    word.clear();
                    j++;
                } else{
                    word += sentence[j];
                    j++;}
            }
            sepText.push_back(words);
            words.clear();
            sentence.clear();
            i++;
        }
        i++;
    }
    sentence += text[i];
    j = 0;
    while (j < sentence.size()){ //the last sentence words deploy int vector
        if(sentence[j] == ' '|| sentence[j] == '.'){
            words.push_back(word);
            word.clear();
            j++;
        } else{
            word += sentence[j];
            j++;}
    }
    sepText.push_back(words); // saving the last one sentence words into text vector
    return sepText;
}





vector<string> getSentences(vector<vector<string>> text, string& word){
    bool flag = false;
    bool word_check_flag = false;
    string senten;
    string wordchecker;
    vector<string> selSen;
    vector<int> p;
    for (auto & sentence : text) { //check all sentences
        for (auto & j: sentence) { // check all words in senctences
            word_check_flag = true;
            if(j.size() > word.size()){
                wordchecker = j.substr(word.size(), j.size() - word.size()); // "word, word;:&^75" case checking 
                for (auto & c:wordchecker) {
                    if(toupper(c) >= 'A' && toupper(c) <= 'Z'){
                        word_check_flag = false;
                    }
                }
            } 
            if(j == word || (j.substr(0, word.size()) == word && word_check_flag)){ // word validation
                flag = true;
                for (char & i : j) {
                    i = toupper(i);
                }

            }
            senten += j; //saving word with sentence sintaxis
            senten += ' ';
        }
        senten[senten.size() - 1] = '.';
        if (flag) {
            selSen.push_back(senten);
            flag = false;
        }
        senten.clear();
    }
    return selSen;
}


int main() {
    freopen("C:\\Users\\rus8-\\CLionProjects\\untitled4\\in.txt", "r", stdin); // input file stdin assosiation 
    freopen("C:\\Users\\rus8-\\CLionProjects\\untitled4\\out.txt", "w", stdout); // output file stoud assosiation
    string text;
    getline(cin, text);
    vector<vector<string>> parsedText = parseText(text); // text parser
    text.clear();
    int n;
    cin>>n;
    vector<string> sentences;
    for (int i = 0; i < n; ++i) {
        cin>>text;
        sentences = getSentences(parsedText, text); // word checker 
        cout<<sentences.size()<<'\n';
        for (auto & sentence : sentences) {
            cout<<sentence<<'\n';
        }
        text.clear();}

}
