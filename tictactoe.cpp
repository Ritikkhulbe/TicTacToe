#include <iostream>
#include <vector>
using namespace std;

int main(){
    bool play = true;
    while(play){
        tictactoe();
        char ch;
        cout << "Do you want to play again? (y/n)";
        cin>>ch;
        if(ch == 'y' || ch == 'Y'){
            play = true;
        }else if(ch == 'n' || ch == 'N'){
            play = false;
        }else{
            cout<<"Wrong argument: Game Ended"<<endl;
        }
    }
}