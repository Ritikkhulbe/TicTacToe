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
    bool won(vector<vector<char>>& b, char ch){

        //checking rows
        for(int i = 0;i<3;i++){
            int c = 0;
            for(int j = 0;j<3;j++){
                if(b[i][j]==ch) 
                    c++;
            }
            if(c==3){
                return true;
            }
        }
        //checking coloumns
        for(int j = 0;j<3;j++){
            int c = 0;
            for(int i = 0;i<3;i++){
                if(b[i][j]==ch) 
                    c++;
            }
            if(c==3){
                return true;
            }
        }
        
        //checking diagonal left-top to right-bottom
        int c = 0;
        for(int x = 0; x < 3 ; x++){
            if(b[x][x]==ch)
                c++;
        }
        if(c==3){
            return true;
        }

        //checking diagonal right-top to left-bottom
        c = 0;
        int j = 0;
        for(int i = 2;i>=0;i--){
            if(b[i][j] == ch)
                c++;
            j++;
        }if(c==3){
            return true;
        }
        return false;
    }
    char Character(char c){
        if(c=='X' || c=='O'){
            return c;
        }else if(c=='a'){
            return ' ';
        }
        return 'a';
    }
    void print_board(vector<vector<char>>& b){
        cout<<"   BOARD              POSITIONS  "<<endl;
        cout<<" "<<Character(b[0][0])<<" | "<<Character(b[0][1])<<" | "<<Character(b[0][2])<<" "<<"          "<<"1 1|1 2|1 3"<<endl;
        cout<<"-----------"<<"          "<<"-----------"<<endl;
        cout<<" "<<Character(b[1][0])<<" | "<<Character(b[1][1])<<" | "<<Character(b[1][2])<<" "<<"          "<<"2 1|2 2|2 3"<<endl;
        cout<<"-----------"<<"          "<<"-----------"<<endl;
        cout<<" "<<Character(b[2][0])<<" | "<<Character(b[2][1])<<" | "<<Character(b[2][2])<<" "<<"          "<<"3 1|3 2|3 3"<<endl;
    }

    void tictactoe(){
        vector<vector<char>> board(3, vector<char>(3, 'a'));
        int a = 1;
        char ch;
        while(a){
            print_board(board);
            if(a%2!=0){
                cout << "Enter the position "<<p1<< "(O)" << endl;
                ch = 'O';
            }else{
                cout << "Enter the position  "<<p2<< "(X)"  << endl;
                ch = 'X';
            }
            
            int x,y;
            while(true){
                cin >> x >> y;
                if(x<1 || x>3 || y<1 || y>3){
                    cout<<"Invalid Position. Try again."<<endl;
                }else if(board[x-1][y-1] != 'a'){
                    cout<<"Position already occupied. Try Again."<<endl;
                }
                else{
                    break;
                }
            }
            board[x-1][y-1] = ch;
            a++;
            if(a>=6){
                if(won(board, ch)){   
                print_board(board);
                    if(ch == 'O'){
                        cout<<p1<< " won!!! Congrats!!"<<endl;
                    }else{
                        cout<<p2<< " won!!! Congrats!!"<<endl;
                    }
                    a=0;
                }
            }
        }
    }
    void Explanation(){
        cout<<"Tic Tac Toe is a two player game in which both the players take turns alternatively"<<endl;
        cout<<"\n Starts with player one(O) then player two(X). Who so ever makes a straight line \n\n even the diagonals on the board first wins. Positions are given in the below."<<endl;
        cout<<"1 1|1 2|1 3"<<endl;
        cout<<"-----------"<<endl;
        cout<<"2 1|2 2|2 3"<<endl;
        cout<<"-----------"<<endl;
        cout<<"3 1|3 2|3 3"<<endl;
        cout<<"\n\nLet's Start Playing"<<endl;
    }
};



int main(){
    bool play = true;
    
    t obj;
    obj.Explanation();
    string p1,p2;
    cout<<"Enter first player's name: ";
    cin>>p1;
    cout<<"Enter second player's name: ";
    cin>>p2;

    obj.getnames(p1,p2);

    while(play){
        obj.tictactoe();
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
    cout<< "Thanks for playing, come again soon <3"<<endl;
    cin>>p1;
    return 0;
}