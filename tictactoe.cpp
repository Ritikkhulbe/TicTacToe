#include <iostream>
#include <vector>
using namespace std;

class t{
    public:
    string p1;
    string p2;

    void getnames(string name1, string name2){
        this->p1 = name1;
        this->p2 = name2;
    }
};

int main(){
    bool play = true;
    string p1,p2;
    cout<<"Enter first player's name: ";
    cin>>p1;
    cout<<"Enter second player's name: ";
    cin>>p2;

    t obj;
    obj.getnames(p1,p2);


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