#include <iostream>
#include <cstdlib> // For system("clear") to clear the screen (optional)
using namespace std;
// Function to print the current game board
void printBoard(int board[3][3]) {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3 ||
				board[i][j] == 4 || board[i][j] == 5 || board[i][j] == 6 ||
				board[i][j] == 7 || board[i][j] == 8 || board[i][j] == 9) {
				cout << " " << board[i][j] << " ";
			}
			else {
				cout << " " << (char)board[i][j] << " "; // Print 'X' or 'O'
			}
		}
		cout << endl;
		cout << "\n";
	}
}
// Function to check if there is a winner
bool checkWin(int board[3][3], char player) {
	// Check rows, columns, and diagonals
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == player && board[i][1] == player && board[i][2] ==
			player) || // Row
			(board[0][i] == player && board[1][i] == player && board[2][i] ==
				player)) { // Column
			return true;
		}
	}
	// Check diagonals
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player)
		||
		(board[0][2] == player && board[1][1] == player && board[2][0] == player))
	{
		return true;
	}
	return false;
}
// Function to check if the board is full (tie game)
bool isBoardFull(int board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				return false; // If there's a number (empty spot), the board is not
			}
		}
	}
	return true;
}
int main() {
	// Initialize the board with numbers from 1 to 9
	int board[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int move;
	int playerTurn = 0; // 0 for X's turn, 1 for O's turn
	char currentPlayer;
	int totalMoves = 0;
	// Print the initial empty board
	printBoard(board);
	while (totalMoves < 9) {
		if (playerTurn == 0) {
			currentPlayer = 'X';
		}
		else {
			currentPlayer = 'O';
		}
		cout << "Player " << currentPlayer << ", enter your move (1-9): ";
		cin >> move;
		// Validate move
		if (move < 1 || move > 9) {
			cout << "Invalid move! Please enter a number between 1 and 9.\n";
			continue;
		}
		// Convert move to row and column
		int row = (move - 1) / 3;
		int col = (move - 1) % 3;
		// Check if the cell is already taken
		if (board[row][col] == 'X' || board[row][col] == 'O') {
			cout << "This spot is already taken! Try again.\n";
			continue;
		}
		// Place the player's mark on the board
		board[row][col] = currentPlayer;
		// Print the updated board
		printBoard(board);
		// Check if the current player has won
		if (checkWin(board, currentPlayer)) {
			cout << "Player " << currentPlayer << " wins!" << endl;
			break;
		}
		// Check if the board is full (tie game)
		if (isBoardFull(board)) {
			cout << "It's a tie!" << endl;
			break;
		}
		// Alternate the turn
		playerTurn = 1 - playerTurn;
		totalMoves++;
	}
	return 0;
}