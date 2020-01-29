#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Class Player
class Player{
public:
	Player(int id);
	void setScore();
	int getScore() const;
private:
	int score;
	int id;
}p1(1),p2(2);

Player::Player(int id){
	this->id = id;
	score = 0;
}
int Player::getScore() const{
	return score;
}
void Player::setScore(){
	this->score++;
}
// end of class
//User Interface + global value of turn
bool turn = 1;
vector<vector<string> > ui{ { "+", " ", "+", " ", "+"},
							{ " ", " ", " ", " ", " "},  
                            { "+", " ", "+", " ", "+"},
							{ " ", " ", " ", " ", " "}, 
                            { "+", " ", "+", " ", "+"} 
						};
//Print the UI
void display(){
	 for (int i = 0; i < ui.size(); i++) { 
        for (int j = 0; j < ui[i].size(); j++) 
            cout << ui[i][j]; 
        cout << endl; 
    }
}
//Has someone scored a point?
inline string point(int playerId){
	if (playerId == 1){
		cout << "Player 1 has scored a point! Extra turn!" << endl;
		turn = 1;
		p1.setScore();
		return "1";
	}else{
		cout << "Player 2 has scored a point! Extra turn!" << endl;
		turn = 0;
		p2.setScore();
		return "2";
	}
}
//Check for a completed Square
bool statement1,statement2,statement3,statement4 = false;
void squareCheck(int playerId){
		if(!statement1 && ui[0][1] != " " && ui[1][0] != " " && ui[2][1] != " " && ui[1][2] != " " ){
			statement1 = true;
			ui[1][1] = point(playerId);
		} 
		if(!statement2 && ui[2][1] != " " && ui[3][0] != " " && ui[3][2] != " " && ui[4][1] != " " ){
			statement2 = true;
			ui[3][1] = point(playerId);
		} 
		if(!statement3 && ui[0][3] != " " && ui[1][2] != " " && ui[1][4] != " " && ui[2][3] != " " ){
			statement3 = true;
			ui[1][3] = point(playerId);
		} 
		if(!statement4 && ui[4][3] != " " && ui[2][3] != " " && ui[3][2] != " " && ui[3][4] != " " ){
			statement4 = true;
			ui[3][3] = point(playerId);
		}
		display();
}
//Start a game
void play(int playerId){
	cout << "Enter starting point: " << endl;
	string str = "";
	getline(cin, str);
	cout << "Enter ending point: " << endl;
	string str2 = "";
	getline(cin, str2);
	str = str + "," + str2;

	//ignore commas and spaces
	vector<int> vect;
	stringstream ss(str);
    for (int i; ss >> i;) {
        vect.push_back(i);    
        while (ss.peek() == ',' || ss.peek() == ' ')
            ss.ignore();
    }

	int x, y, z, k = 0;
	x = vect[0];
	y = vect[1];
	z = vect[2];
	k = vect[3];
	//check if the line is taken
	if(ui[x+z][y+k] != " "){
		cout << "Already taken line, try again!" << endl;
		turn = !turn;
	}else{
		//determine the line symbol
		if(x == z){
			ui[x+z][y+k] = "-";
		}else{
			ui[x+z][k+y] = "|";
		}
		squareCheck(playerId);
	}
}
//Switch the turns
inline void turns(){
	if(!turn){
		cout << "Player 2" << endl;
		turn = !turn;
		play(2);
	}else{
		cout << "Player 1" << endl;
		turn = !turn;
		play(1);
	}
}
//Has someone won?
inline bool hasWon(int score1, int score2){
	if((score1 + score2) == 4){
		cout << "Player 1 score: " << score1 << endl << "Player 2 score: " << score2 << endl;
		if(score1 > score2){
			cout << "Player 1 won!";
		}else{
			cout << "Player 2 won!";
		}
		return true; 	
	}
	return false;
}
//Begining
int main(){
	display();
	bool won = hasWon(p1.getScore(), p2.getScore());
	while(!won){
		turns();
		won = hasWon(p1.getScore(), p2.getScore());
	}
	return 0;
}// main
