#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef map<int,char, greater<int>> Map;
typedef pair<int,char> Pair;

Map checkForOccurrences(string);
void printNewString(Map&, Map&, string);

int main(){
    int numCases;
    cin >> numCases;
    string input1, input2, newString;
    Map occurrences1;
    Map occurrences2;
    int flag = 0;

    while(numCases > 0){
        newString = "";
        cin >> input1 >> input2;
        occurrences1 = checkForOccurrences(input1);
        occurrences2 = checkForOccurrences(input2); 
        if(flag == 1){cout << endl;}
        flag = 1;
        printNewString(occurrences1,occurrences2, input2);
        numCases--;
    } 
    return 0;
}

Map checkForOccurrences(string input){
    vector<char> alreadyChecked;
    int count;
    bool checked; 
    Map output;
    for(int i = 0; i < input.size(); i++){
        count = 0;
        checked = false;
        for(int j = 0; j < input.size(); j++){
            for(int k = 0; k < alreadyChecked.size(); k++){
                if(input[i] == alreadyChecked[k]){
                    checked = true;
                    break;
                }
            }
            if(checked){
                break;
            }else{
                if(input[i] == input[j]){
                    count++;
                }       
            }
        }
        output.insert(Pair(count, input[i]));
    }
    return output;
}

void printNewString(Map& one, Map& two, string input2){
    vector<char> firstInput;
    vector<char> secondInput;
    auto it1 = one.begin();
    int pos;
    for(auto it2: two){
        firstInput.push_back((*it1).second);
        secondInput.push_back(it2.second);
        it1++;
    }
    for(int i = 0; i < input2.size(); i++){
        for(int j = 0; j < secondInput.size(); j++){
            if(input2[i] == secondInput[j]){
                pos = j;
            }
        }
        cout << firstInput[pos];
    }
    
    cout << endl;
}







