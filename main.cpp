#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> parseText(string& text){
    string sentence;
    vector<string> sepText;
    int i = 0;
    while(i != text.length() - 1){
        sentence += text[i];
        if(text[i] == '.'){
            sepText.push_back(sentence);
            sentence.clear();
            i++;
        }
        i++;
    }
    sepText.push_back(sentence);
    return sepText;
}





vector<string> getSentences(vector<string> text, string& word){
    bool flag = false;
    vector<string> selSen;
    int lenght = word.size();
    for (auto & i : text) {
        while(i.find(word) != string::npos){
            int index = i.find(word);
            if ((i[index + lenght] == ' '|| i[index + lenght] == '.') && (index == 0 || i[index-1] == ' ')){
                for(int j = 0; j < lenght; ++j) {
                    flag = true;
                    i[index + j] = toupper(i[index+j]);
                }
            }
        }
        if(flag){
            selSen.push_back(i);
            flag = false;
        }
    }
    return selSen;
}


int main() {
    freopen("C:\\Users\\rus8-\\CLionProjects\\untitled4\\in.txt", "r", stdin);
    freopen("C:\\Users\\rus8-\\CLionProjects\\untitled4\\out.txt", "w", stdout);
    string text;
    getline(cin, text);
    vector<string> parsedText = parseText(text);
    text.clear();
    int n;
    cin>>n;
    vector<string> sentences;
    for (int i = 0; i < n; ++i) {
        cin>>text;
        sentences = getSentences(parsedText, text);
        cout<<sentences.size()<<'\n';
        for (auto & sentence : sentences) {
            cout<<sentence<<'\n';
        }
        text.clear();    }

}
