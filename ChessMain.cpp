#include <iostream>

using namespace std;

#include "ChessBoard.h"

int main() {
  cout << endl;
  cout << "===========================" << endl;
  cout << "        Error Triggers     " << endl;
  cout << "===========================" << endl;
  cout << endl;

  ChessBoard cb;
  cout << endl;

  cout << "* Trying to move an empty square *" << endl;
  cout << "----------------------------------" << endl;
  cb.submitMove("C5", "C4");
  cout << endl;

  cout << "* Trying to move a piece not on right move *" << endl;
  cout << "--------------------------------------------" << endl;
  cb.submitMove("H7", "H6");
  cout << endl;

  cout << "* Invalid coordinates (file) *" << endl;
  cout << "------------------------------" << endl;
  cb.submitMove("I7", "I6");
  cout << endl;

  cout << "* Invalid coordinates (rank) *" << endl;
  cout << "------------------------------" << endl;
  cb.submitMove("H10", "H11");
  cout << endl;

  cout << "* Moving a piece off the board *" << endl;
  cout << "--------------------------------" << endl;
  cb.submitMove("H1", "H0");
  cout << endl;

  cout << "* Moving your pawn forward three spaces *" << endl;
  cout << "-----------------------------------------" << endl;
  cb.submitMove("C2", "C5");
  cout << endl;

  cout << "* Moving your knight forward two spaces *" << endl;
  cout << "-----------------------------------------" << endl;
  cb.submitMove("B1", "B3");
  cout << endl;

  cb.submitMove("D2", "D3");
  cb.submitMove("A7", "A6");
  cout << endl;

  cb.submitMove("C1", "E3");
  cb.submitMove("H7", "H6");
  cout << endl;

  cout << "* Moving your pawn backwards on its first move *" << endl;
  cout << "------------------------------------------------" << endl;
  cb.submitMove("C2", "C1");
  cout << endl;

  cout << "* Moving your pawn attacking on empty square *" << endl;
  cout << "----------------------------------------------" << endl;
  cb.submitMove("B2", "A3");
  cout << endl;

  cout << "* Moving your Bishop through a piece *" << endl;
  cout << "--------------------------------------" << endl;
  cb.submitMove("F1", "H3");
  cout << endl;

  cout << "* Moving your knight in invalid shape *" << endl;
  cout << "---------------------------------------" << endl;
  cb.submitMove("B1", "C1");
  cout << endl;

  cb.submitMove("F2", "F3");
  cout << endl;

  cout << "* Moving pawn two spaces on second move *" << endl;
  cout << "-----------------------------------------" << endl;
  cb.submitMove("A6", "A4");
  cout << endl;

  cb.submitMove("E7", "E6");
  cb.submitMove("E3", "A7");
  cout << endl;

  cout << "* Pawn attempting to capture backwards *" << endl;
  cout << "----------------------------------------" << endl;
  cb.submitMove("A6", "A7");
  cout << endl;

  cb.submitMove("D8", "H4");
  cout << endl;

  cout << "* White attempting a move not removing check *" << endl;
  cout << "----------------------------------------------" << endl;
  cb.submitMove("B1", "A3");
  cout << endl;

  cb.submitMove("E1", "D2");
  cb.submitMove("H4", "G5");
  cout << endl;

  cb.submitMove("E2", "E3");
  cout << endl;

  cout << "* Trying to move rook through a piece *" << endl;
  cout << "---------------------------------------" << endl;
  cb.submitMove("H8", "H4");
  cout << endl;

  cb.submitMove("G8", "F6");
  // ??
  cb.submitMove("D2", "E1");
  cout << endl;

  cb.submitMove("G5", "G6");
  cb.submitMove("D1", "D2");
  cout << endl;

  cb.submitMove("F8", "E7");
  cout << endl;

  cout << "* Invalid castling because king already moved *" << endl;
  cout << "-----------------------------------------------" << endl;
  cb.submitMove("E1", "C1");
  cout << endl;

  cb.submitMove("D2", "B4");
  cb.submitMove("G6", "E4");
  cout << endl;

  cb.submitMove("B4", "E4");
  cb.submitMove("F6", "D5");
  cout << endl;

  cb.submitMove("E4", "G4");
  cb.submitMove("G7", "G5");
  cout << endl;

  cb.submitMove("G4", "G5");
  cout << endl;

  cout << "* Invalid castling because king end in check *" << endl;
  cout << "----------------------------------------------" << endl;
  cb.submitMove("E8", "G8");
  cout << endl;

  cb.submitMove("B7", "B6");
  cb.submitMove("G5", "D5");
  cout << endl;

  cb.submitMove("C8", "B7");
  cb.submitMove("D5", "D4");
  cout << endl;

  cb.submitMove("D7", "D5");
  cb.submitMove("D4", "D5");
  cout << endl;

  cb.submitMove("B8", "C6");
  cb.submitMove("G2", "G4");
  cout << endl;

  cout << "* Invalid castling because king goes through under attack square *" << endl;
  cout << "------------------------------------------------------------------" << endl;
  cb.submitMove("E8", "C8");
  cout << endl;

  cb.submitMove("E6", "D5");
  cb.submitMove("F1", "G2");
  cout << endl;

  cb.submitMove("E8", "C8");
  cb.submitMove("F3", "F4");
  cout << endl;

  cb.submitMove("D8", "D7");
  cb.submitMove("G2", "H3");
  cout << endl;

  cb.submitMove("H6", "H5");
  cb.submitMove("G4", "G5");
  cout << endl;

  cout << "* Invalid move because puts king in check *" << endl;
  cout << "-------------------------------------------" << endl;
  cb.submitMove("D7", "D6");
  cout << endl;

  cb.submitMove("H5", "H4");
  cb.submitMove("H3", "D7");
  cout << endl;

  cb.submitMove("C8", "D7");
  cb.submitMove("G1", "F3");
  cout << endl;

  cb.submitMove("F7", "F6");
  cb.submitMove("G5", "F6");
  cout << endl;

  cb.submitMove("D7", "C8");
  cb.submitMove("H1", "G1");
  cout << endl;

  cb.submitMove("C6", "B4");
  cb.submitMove("G1", "G8");
  cout << endl;

  cb.submitMove("C8", "D7");
  cb.submitMove("E3", "E4");
  cout << endl;

  cb.submitMove("H8", "H7");
  cb.submitMove("E4", "D5");
  cout << endl;

  cb.submitMove("E7", "F8");
  cb.submitMove("D5", "D6");
  cout << endl;

  cb.submitMove("D7", "C8");
  cb.submitMove("D6", "D7");
  cout << endl;

  return 0;
}
