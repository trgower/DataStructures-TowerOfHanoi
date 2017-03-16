/*

  Tanner Gower
  11/28/2016
  Project 9: Tower Of Hanoi

*/

#include <iostream>
#include <string>
#include "MyStack.h"

using namespace std;

void solveTowerOfHanoi(int, int, int, int, int&, MyStack<int>*);
void doMove(int, int, MyStack<int>*);
void printBoard(MyStack<int>*);

const char labels[] = {'A', 'B', 'C'};

int main ()
{
  int moves = 0;
  int discs = 0;

  cout << "How many discs? ";
  cin >> discs;

  // Initialize board with 3 pegs
  MyStack<int> board[3];
  for (int i = 0; i < 3; i++) {
    board[i].reset(discs);
  }
  
  // Stack up initial discs
  for (int i = 0; i < discs; i++)
    board[0].push(discs - i);


  cout << "PegA\tPegB\tPegC" << endl;
  cout << "----------------------" << endl;
  printBoard(board);
  solveTowerOfHanoi(discs, 0, 1, 2, moves, board);
  cout << "Done in " << moves << " moves." << endl;

  return 0;
}

void solveTowerOfHanoi(int n, int beg, int aux, int end, int& m, MyStack<int>* b)
{
  if (n == 1) {
    m++;
    doMove(beg, end, b);
  } else {
    solveTowerOfHanoi(n-1, beg, end, aux, m, b);
    solveTowerOfHanoi(1, beg, aux, end, m, b);
    solveTowerOfHanoi(n-1, aux, beg, end, m, b);
  }
}

void doMove(int from, int to, MyStack<int>* board)
{
  cout << "                      " << labels[from] << " to " << labels[to] << endl;
  board[to].push(board[from].pop());
  printBoard(board);
}

void printBoard(MyStack<int>* board)
{
  for (int i = board[0].getSize()-1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      if (board[j].getElements()[i] != 0) {
        cout << "[ " << board[j].getElements()[i] << " ]   ";
      } else {
        cout << "        ";
      }
    }
    cout << endl;
  }
  cout << "----------------------" << endl;
}

template class MyStack<int>;
