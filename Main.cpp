/*

  Tanner Gower
  11/28/2016
  Project 9: Tower Of Hanoi

*/

#include <iostream>
#include <string>

using namespace std;

void solveTowerOfHanoi(int, int, int, int, int, int&, int**&);
void doMove(int, int, int**&, int);
void printBoard(int**&, int);

int main ()
{
  int moves = 0;
  int discs = 0;

  cout << "How many discs? ";
  cin >> discs;

  // Initialize board with 3 pegs
  int** board = new int*[discs];
  for (int i = 0; i < discs; i++)
    board[i] = new int[3];

  // Initialize to zero! just to be safe
  for (int i = 0; i < discs; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = 0;

  // Stack up initial discs
  for (int i = 0; i < discs; i++)
    board[i][0] = discs - i;

  cout << "PegA\tPegB\tPegC" << endl;
  cout << "----------------------" << endl;
  printBoard(board, discs);
  solveTowerOfHanoi(discs, discs, 0, 1, 2, moves, board);
  cout << "Done in " << moves << " moves." << endl;

  return 0;
}

void solveTowerOfHanoi(int d, int n, int beg, int aux, int end, int& m, int**& b)
{
  if (n == 1) {
    m++;
    doMove(beg, end, b, d);
  } else {
    solveTowerOfHanoi(d, n-1, beg, end, aux, m, b);
    solveTowerOfHanoi(d, 1, beg, aux, end, m, b);
    solveTowerOfHanoi(d, n-1, aux, beg, end, m, b);
  }
}

void doMove(int from, int to, int**& b, int d)
{
  // Grab top from and set to 0 then set top of to to top of from....
  int top;
  for (int i = 0; i < d; i++) {
    if ((i+1) >= d || (b[i+1][from] == 0 && b[i][from] != 0)) {
      top = b[i][from];
      b[i][from] = 0;
      break;
    }
  }
  for (int i = 0; i < d; i++) {
    if ((i+1) >= d || b[i][to] == 0) {
      b[i][to] = top;
      break;
    }
  }

  for (int i = d-1; i >= 0; i--) {
    if (b[i][0] == 0 && b[i][1] == 0 && b[i][2] == 0)
      continue; // skip printing row if all 0
    for (int j = 0; j < 3; j++) {
      if (b[i][j] != 0)
        cout << "disc" << b[i][j] << "\t";
      else
        cout << "\t";
    }
    if (i == 0) {
      char f, t;
      if (from == 0) f = 'A';
      else if (from == 1) f = 'B';
      else if (from == 2) f = 'C';
      if (to == 0) t = 'A';
      else if (to == 1) t = 'B';
      else if (to == 2) t = 'C';

      cout << "\t[" << f << " to " << t << "]";
    }
    cout << endl;
  }
  cout << "----------------------" << endl;
}

void printBoard(int**& b, int d)
{
  for (int i = d-1; i >= 0; i--) {
    if (b[i][0] == 0 && b[i][1] == 0 && b[i][2] == 0)
      continue;
    for (int j = 0; j < 3; j++) {
      if (b[i][j] != 0)
        cout << "disc" << b[i][j] << "\t";
      else
        cout << "\t";
    }
    cout << endl;
  }
  cout << "----------------------" << endl;
}
