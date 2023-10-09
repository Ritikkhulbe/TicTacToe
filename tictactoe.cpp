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

    void tictactoe(){
        vector<vector<char>> board(3, vector<char>(3, 'a'));
        int a = 1;
        char ch;
        while(a){
            if(a%2!=0){
                cout << "Enter the position of player one (O)" << endl;
                ch = 'O';
            }else{
                cout << "Enter the position of player two (X)" << endl;
                ch = 'X';
            }
            
            int x,y;
            while(true){
                cin >> x >> y;
                if(x<1 || x>3 || y<1 || y>3){
                    cout<<"Invalid Position. Try again."<<endl;
                }else if(board[x-1][y-1] == 'a'){
                    cout<<"Position already occupied"<<endl;
                }
                else{
                    break;
                }
            }
            board[x-1][y-1] = ch;
            a++;
        }
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