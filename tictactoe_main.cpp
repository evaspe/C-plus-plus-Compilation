//
//  main.cpp
//  tictactoe
//
//  Created by Eva on 1/10/21.
//  Copyright © 2021 Eva. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Player {
    int score = 0;
    string name;

public:
    /**
    This is a setter function for player name
    @string it takes in the string of the player name
     */
   void setName(string n)
    {name = n;};

     /**
    This is a setter function for player name
    @string it returns player name
      */
    string getName()
    {return name;};
    
    /**
    This function adds a point to player score
     */
    void addScore()
    {++score;};
    
    /**
    This is a setter function for player score
    @int it returns player score
     */
    int getScore()
    {return score;};
    
   
    
};

class Game {
    int rounds;
    bool p1turn = true;
    vector <vector<char>> vec = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

public:
    /**
    I created these variables to be able to access functions of Player class from within functions in Game class
     */
    Player player1;
    Player player2;
    void play();
    void printboard(vector <vector<char>> &vec);
    void clearboard(vector <vector<char>> &vec);
    void turn(bool &p1turn);
    bool win(bool &p1turn);
    bool tie();
};




/**
This function controls the whole game, it takes in user input of rounds and names, and contains the loops calling win and turn functions
 */
void Game::play() {

    cout << "This is a Tic Tac Toe game!\n" << "How many rounds would you like to play?\n";
    cin >> rounds;
    cin.ignore();

    cout << "Please enter the name of player 1: ";
    string n;
    getline(cin, n);
    player1.setName(n);



    cout << "Thanks. please enter the name of player 2: ";
    getline(cin, n);
    player2.setName(n);


    cout << "Let the game begin! \n";

  
    /**
    This loop controls how many rounds are played
     */
    for (int i = 0; i < rounds; ++i) {
        do
        {
            turn(p1turn);
        }

        while (win(p1turn) == false && tie()==false);

    
        if (win(p1turn) == true && p1turn == false) { cout << player1.getName() <<" has won this round\n";
            player1.addScore();
            clearboard(vec);
        }
        
        if (win(p1turn) && p1turn) { cout << player2.getName() << " has won this round\n";
            player2.addScore();
            clearboard(vec);}
        
        if (tie()) { cout << "that round was a tie\n"; clearboard(vec);}
        
        cout << "Currently, " << player1.getName() << " has " << player1.getScore() << " points and " << player2.getName() << " has " << player2.getScore() << " points.\n";

    }
    
    if (player1.getScore()>player2.getScore()) {cout << player1.getName() << " has won the game!";}
    if (player2.getScore()>player1.getScore()) {cout << player2.getName() << " has won the game!";}
    if (player1.getScore()==player2.getScore()) {cout << "It is a tie!";}
};


/**
This function prints the tic tac toe board
@vector vector it takes the vector vector as a parameter so it can print it*/
void Game::printboard(vector <vector<char>> &vec){
    cout <<
    " 1 2 3 \n" <<
    "1" << vec[0][0] <<"|" <<vec[0][1]<<"|"<<vec[0][2]<<"\n" <<
    " _____\n" <<
    "2"<<vec[1][0]<<"|"<<vec[1][1]<<"|"<<vec[1][2]<<"\n" <<
    " _____\n" <<
    "3"<<vec[2][0]<<"|"<<vec[2][1]<<"|"<<vec[2][2]<<"\n";
};



/**
This function controls which players turn it is and prompts them to enter a move
@bool this function has the boolean parameter p1turn turn to know if it is player 1's turn or not
 */
void Game::turn(bool &p1turn) {

    if (p1turn == true) {
        printboard(vec);
        cout << "It is " << player1.getName() << "'s turn.\n";
        //cout << "it is " << "evas" << "'s turn\n";
        cout << "Where would you like to play? Enter your row position and column position: ";
        int rows, cols;
        cin >> rows;
        cin >> cols;
        vec[rows - 1][cols - 1] = 'x';

        p1turn = false;
    }
    else {

        printboard(vec);
        cout << "It is " << player2.getName() << "'s turn\n";
        //cout << "it is " << "mers" << "'s turn\n";
        cout << "Where would you like to play? Enter your row position and column position: ";
        int rows, cols;
        cin >> rows;
        cin >> cols;
        vec[rows - 1][cols - 1] = 'o';
        
        p1turn = true;
    }
};

/**
This function checks if any player has won
@bool  this function has the boolean parameter p1turn to keep track of which player may have won
@bool this function returns a boolean value, true if the game has been won, false if not */
bool Game::win(bool &p1turn) {

    char t;
    if (p1turn == false) { t = 'x'; }
    else if (p1turn) { t = 'o'; }


    if (t == vec[0][0] && t == vec[0][1] && t == vec[0][2])  {return true;}
    else if (t == vec[1][0] && t == vec[1][1] && t == vec[1][2]) {return true;}
    else if (t == vec[1][0] && t == vec[1][1] && t == vec[1][2]) {return true;}
    else if (t == vec[2][0] && t == vec[2][1] && t == vec[2][2]) {return true;}
    else if (t == vec[0][0] && t == vec[1][0] && t == vec[2][0]) {return true;}
    else if (t == vec[0][1] && t == vec[1][1] && t == vec[2][1]) {return true;}
    else if (t == vec[0][2] && t == vec[1][2] && t == vec[2][2]) {return true;}

    else if (t == vec[0][0] && t == vec[1][1] && t == vec[2][2]) {return true;}

    else if (t == vec[2][0] && t == vec[1][1] && t == vec[0][2]) {return true;}


    else { return false; };

};

/**
This function checks if the individual game is a tie
@bool this function returns a boolean value, true if the game has been tied, false if not */
bool Game::tie() {

    if (' ' != vec[0][0] && ' ' != vec[0][1] && ' ' != vec[0][2] && vec[1][0] && ' ' != vec[1][1] && ' ' != vec[1][2] && ' ' != vec[2][0] && ' ' != vec[2][1] && ' ' != vec[2][2])
    {return true;}
    
    else { return false; }
};

/**
This function clears the board
@vector vector this function has the vector vector parameter so it can clear it  */
void Game::clearboard(vector <vector<char>> &vec){
vec = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
};


int main() {

    Game tictactoe;
    tictactoe.play();
    return 0;
}
