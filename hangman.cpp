#include <bits/stdc++.h>
using namespace std;

string choose_word(vector<string> words) {
    srand(time(0));    
    int lb = 0;
    int ub = words.size()-1;
    int random_index = rand() % (lb - ub + 1) + lb;

    return words[random_index];
}

bool check_input(char input, string word, string& blanks) {
    for(int i=0; i<word.size(); i++) {
        if(word[i] == input and blanks[i * 2] == '_') return true;
    }
    return false;
}

string after_input_result(char input_char, string word, string& blanks) {
    for(int i=0; i<word.size(); i++) {
        if(word[i] == input_char) {
            blanks[i * 2] = input_char;

        }
    }
    return blanks;
}

bool check_win_status(string& blanks) {
    for(char c : blanks) 
        if(c == '_') return false;
        
    return true;
}
int main() {
    vector<string> words = {"elephant", "apple", "watermelon", "spider", "audi", "kohli", "cricket", "wicket", "programmer", "success"};

    string choosen_word = choose_word(words);

    int lives = 6;

    bool win_status = false;

    cout << "Welcome to HangMan!" << endl;
    cout << "Next Word Is Loaded, Go Ahead & Choose A Letter:" << endl;

    string blanks = "";
    for(int i=0; i<choosen_word.size(); i++) {
        blanks += "_ ";
    }   
    cout << blanks << "(" << choosen_word.size() << " Characters)" << endl << endl;

    while(lives > 0) {
        cout << "Lives Remaining: " << lives << endl;

        char input;
        cin >> input;

        if(check_input(input, choosen_word, blanks) == true) {
            string filled_blanks_after_input = after_input_result(input, choosen_word, blanks);
            cout << filled_blanks_after_input << endl;
            win_status = check_win_status(blanks);
            if(win_status) {
                cout << "!!! WINNER, CONGRATULATIONS, YOU'VE KILLED IT !!!" << endl;
                break;
            }
            else cout << "You guessed it RIGHT! carry on!" << endl;
        } 
        else {
            lives--;
            if(lives==0) cout << "!!! GAME OVER, FU*# OFF !!!";
            else cout << "Wrong guess, try again!" << endl;
        }
    }
 
    return 0;
}