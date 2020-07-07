#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void prompt(); //Prints header and allows user to change settings
void printBoard(); //Prints the board
char userPrompt(char c); //Asks user for a location
void userInput(char c); //Places symbol at location
void computerInput(char c); //Randomly places
void updateBoard(); //Updates the board or main loop
bool checkWinner(); //Checks if there is a winner

vector<vector<char> > board = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
}; //Tic Tac Toe Board
int slotsLeft = 9; //Available slots left
string result = "Error"; //Results of game
char player[4] = " XO"; //Storing symbols

struct Player {
  char symbol; //X or O
  bool user; //User or computer?
  string name; //Storing some random text
  //Creates new player
  Player (char s, bool u, string n) {
    symbol = s;
    user = u;
    name = n;
  }
  //Chooses an input method based on 'user'
  void playerInput() {
    if (user) {
      userInput(symbol);
    }
    else {
      computerInput(symbol);
    }
  }
};

//Defaults to Player versus Computer
struct Player p1 = Player(player[1], true, "Player 1 <X>");
struct Player p2 = Player(player[2], false, "Computer <O>");

int main() {
  /*
  prompt();
  updateBoard();
  cout << result << endl;
  return 0;
  */
}

void prompt() {
  //Prints a standard header
  cout << "Tic Tac Toe" << endl;
  cout << p1.name << "    " << p2.name << endl;
  printBoard();
  //Changes settings (PvC, PvP, CvC)
  char input;
  cout << "Change settings? Y or N: ";
  cin >> input;
  if (input == 'Y' || input == 'y') {
    cout << "Enter 1 for Player   versus Player" << endl;
    cout << "Enter 2 for Player   versus Computer" << endl;
    cout << "Enter 3 for Computer versus Computer" << endl;
    cin >> input;
    if (input == '1') {
      p1 = Player(player[1], true, "Player 1 <X>");
      p2 = Player(player[2], true, "Player 2 <O>");
      prompt();
    }
    else if (input == '2') {
      p1 = Player(player[1], true, "Player 1 <X>");
      p2 = Player(player[2], false, "Computer <O>");
      prompt();
    }
    else if (input == '3') {
      p1 = Player(player[1], false, "Computer <X>");
      p2 = Player(player[2], false, "Computer <O>");
      prompt();
    }
  }
}

void printBoard() {
  //Prints board
  for (size_t i = 0; i < board.size(); i++) {
    for (size_t j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
/*
void changeDimensions(vector<vector<string> > B, size_t n, size_t m) {
  int slotValue = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; i < m; i++) {

    }
  }
}
*/
char userPrompt(char c = p1.symbol) {
  //Asks user where to place their symbol
  char input;
  cout << "Please pick where you want your " << c << ": ";
  cin >> input;
  return input;
}

void userInput(char c = p1.symbol) {
  //User places their symbol
  bool valid = false;
  do {
    char input = userPrompt(c);
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[i].size(); j++) {
        if (input == board[i][j]
            && board[i][j] != 'X'
            && board[i][j] != 'O') {
          board[i][j] = c;
          valid = true;
        }
      }
    }
    //Continue if valid AND there are slots left
  } while(!valid && slotsLeft > 0);
  slotsLeft--;
}

void computerInput(char c = p2.symbol) {
  //Randomly places a given symbol
  bool valid = false;
  do {
    char input = rand() % 9 + 49; // [49, 57]
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[i].size(); j++) {
        if (input == board[i][j] &&
            board[i][j] != 'X' &&
            board[i][j] != 'O') {
          board[i][j] = c;
          valid = true;
        }
      }
    }
    //Continue if valid AND there are slots left
  } while(!valid && slotsLeft > 0);
  slotsLeft--;
}

void updateBoard() {
  //Updates the board
  bool stop = false;
  do {
    //Player 1
    p1.playerInput();
    stop = checkWinner();
    if (stop) {
      printBoard();
      break;
    }
    //Prints the board in between if PvP or CvC
    if (p1.user == p2.user) {
      //Sleeps in between if CvC
      if (!p1.user) {
        sleep(1);
      }
      printBoard();
    }
    //Player 2
    p2.playerInput();
    stop = checkWinner();
    if (stop) {
      printBoard();
      break;
    }
    //Sleeps in between if CvC
    if (!p1.user && !p2.user) {
      sleep(1);
    }
    printBoard();
    //Check if a player won, if not, repeat
  } while (!stop);
}

bool checkWinner() {
  //Checks rows, columns and diagnols for a winner
  char c = '?';
  //Rows and columns
  for (size_t i = 0; i < board.size(); i++) {
    if (board[i][0] == board[i][1] &&
        board[i][1] == board[i][2]) {
      c = board[i][0];
    }
    else if (board[0][i] == board[1][i] &&
        board[1][i] == board[2][i]) {
      c = board[0][i];
    }
  }
  //Diagnols
  if (board[0][0] == board[1][1] &&
      board[1][1] == board[2][2]) {
    c = board[1][1];
  }
  else if (board[0][2] == board[1][1] &&
           board[1][1] == board[2][0]) {
    c = board[1][1];
  }
  //Winner or tie
  if (c == 'X') {
    result = "X wins";
    return true;
  }
  else if (c == 'O') {
    result = "O wins";
    return true;
  }
  else if (slotsLeft == 0) {
    result = "Tie";
    return true;
  }
  return false;
}