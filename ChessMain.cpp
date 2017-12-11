#include <iostream>

using namespace std;

#include "ChessBoard.h"

int main() {
  // White in checkmate
  cout << "=======================" << endl;
  cout << "Keres vs. Menke (1933)" << endl;
  cout << "=======================" << endl;
  cout << "White in checkmate" << endl;
  cout << endl;

  ChessBoard cb;

  cb.submitMove("E2", "E4");
  cb.submitMove("E7", "E5");
  cout << endl;

  cb.submitMove("F2", "F4");
  cb.submitMove("E5", "F4");
  cout << endl;

  cb.submitMove("B1", "C3");
  cb.submitMove("D8", "H4");
  cout << endl;

  cb.submitMove("E1", "E2");
  cb.submitMove("D7", "D5");
  cout << endl;

  cb.submitMove("C3", "D5");
  cb.submitMove("C8", "G4");
  cout << endl;

  cb.submitMove("G1", "F3");
  cb.submitMove("B8", "C6");
  cout << endl;

  cb.submitMove("D5", "C7");
  cb.submitMove("E8", "D8");
  cout << endl;

  cb.submitMove("C7", "A8");
  cb.submitMove("C6", "E5");
  cout << endl;

  cb.submitMove("H2", "H3");
  cb.submitMove("G4", "H5");
  cout << endl;

  cb.submitMove("H1", "G1");
  cb.submitMove("H4", "G3");
  cout << endl;

  cb.submitMove("D1", "E1");
  cb.submitMove("E5", "F3");
  cout << endl;

  cb.submitMove("G2", "F3");
  cb.submitMove("G3", "F3");
  cout << endl;

  // Black in chackmate
  cout << "===========================" << endl;
  cout << "Hohmeister vs. Frank (1933)" << endl;
  cout << "===========================" << endl;
  cout << "Black in checkmate" << endl;
  cout << endl;

  cb.resetBoard();

  cb.submitMove("E2","E4");
  cb.submitMove("C7","C6");
  cout << endl;

  cb.submitMove("D2","D4");
  cb.submitMove("D7","D5");
  cout << endl;

  cb.submitMove("B1","C3");
  cb.submitMove("D5","E4");
  cout << endl;

  cb.submitMove("C3","E4");
  cb.submitMove("B8","D7");
  cout << endl;

  cb.submitMove("G1","F3");
  cb.submitMove("G8","F6");
  cout << endl;

  cb.submitMove("D1","E2");
  cb.submitMove("G7","G6");
  cout << endl;

  cb.submitMove("E4","D6");
  cout << endl;

  // Black in checkmate
  cout << "==========================" << endl;
  cout << "Alekhine vs. Tenner (1911)" << endl;
  cout << "==========================" << endl;
  cout << "Black in checkmate" << endl;
  cout << endl;

  cb.resetBoard();

  cb.submitMove("E2","E4");
  cb.submitMove("E7","E5");
  cout << endl;

  cb.submitMove("F2","F4");
  cb.submitMove("F8","C5");
  cout << endl;

  cb.submitMove("G1","F3");
  cb.submitMove("D7","D6");
  cout << endl;

  cb.submitMove("B1","C3");
  cb.submitMove("G8","F6");
  cout << endl;

  cb.submitMove("F1","C4");
  cb.submitMove("B8","C6");
  cout << endl;

  cb.submitMove("D2","D3");
  cb.submitMove("C8","G4");
  cout << endl;

  cb.submitMove("C3","A4");
  cb.submitMove("E5","F4");
  cout << endl;

  cb.submitMove("A4","C5");
  cb.submitMove("D6","C5");
  cout << endl;

  cb.submitMove("C1","F4");
  cb.submitMove("F6","H5");
  cout << endl;

  cb.submitMove("F4","E3");
  cb.submitMove("C6","E5");
  cout << endl;

  cb.submitMove("F3","E5");
  cb.submitMove("G4","D1");
  cout << endl;

  cb.submitMove("C4","F7");
  cb.submitMove("E8","E7");
  cout << endl;

  cb.submitMove("E3","C5");
  cb.submitMove("E7","F6");
  cout << endl;

  cb.submitMove("E1","G1");
  cb.submitMove("F6","E5");
  cout << endl;

  cb.submitMove("F1","F5");
  cout << endl;

  // Black in checkmate
  cout << "=======================" << endl;
  cout << "Lasker vs. Thomas (1912)" << endl;
  cout << "=======================" << endl;
  cout << "Black in checkmate" << endl;
  cout << endl;

  cb.resetBoard();

  cb.submitMove("D2","D4");
  cb.submitMove("E7","E6");
  cout << endl;

  cb.submitMove("G1","F3");
  cb.submitMove("F7","F5");
  cout << endl;

  cb.submitMove("B1","C3");
  cb.submitMove("G8","F6");
  cout << endl;

  cb.submitMove("C1","G5");
  cb.submitMove("F8","E7");
  cout << endl;

  cb.submitMove("G5","F6");
  cb.submitMove("E7","F6");
  cout << endl;

  cb.submitMove("E2","E4");
  cb.submitMove("F5","E4");
  cout << endl;

  cb.submitMove("C3","E4");
  cb.submitMove("B7","B6");
  cout << endl;

  cb.submitMove("F3","E5");
  cb.submitMove("E8","G8");
  cout << endl;

  cb.submitMove("F1","D3");
  cb.submitMove("C8","B7");
  cout << endl;

  cb.submitMove("D1","H5");
  cb.submitMove("D8","E7");
  cout << endl;

  cb.submitMove("H5","H7");
  cb.submitMove("G8","H7");
  cout << endl;

  cb.submitMove("E4","F6");
  cb.submitMove("H7","H6");
  cout << endl;

  cb.submitMove("E5","G4");
  cb.submitMove("H6","G5");
  cout << endl;

  cb.submitMove("H2","H4");
  cb.submitMove("G5","F4");
  cout << endl;

  cb.submitMove("G2","G3");
  cb.submitMove("F4","F3");
  cout << endl;

  cb.submitMove("D3","E2");
  cb.submitMove("F3","G2");
  cout << endl;

  cb.submitMove("H1","H2");
  cb.submitMove("G2","G1");
  cout << endl;

  cb.submitMove("E1","D2");
  cout << endl;

  // Black in checkmate
  cout << "============================" << endl;
  cout << "Nimzowitsch vs. Alapin (1914)" << endl;
  cout << "=============================" << endl;
  cout << "Black in checkmate" << endl;
  cout << endl;

  cb.resetBoard();

  cb.submitMove("E2","E4");
  cb.submitMove("E7","E6");
  cout << endl;

  cb.submitMove("D2","D4");
  cb.submitMove("D7","D5");
  cout << endl;

  cb.submitMove("B1","C3");
  cb.submitMove("G8","F6");
  cout << endl;

  cb.submitMove("E4","D5");
  cb.submitMove("F6","D5");
  cout << endl;

  cb.submitMove("G1","F3");
  cb.submitMove("C7","C5");
  cout << endl;

  cb.submitMove("C3","D5");
  cb.submitMove("D8","D5");
  cout << endl;

  cb.submitMove("C1","E3");
  cb.submitMove("C5","D4");
  cout << endl;

  cb.submitMove("F3","D4");
  cb.submitMove("A7","A6");
  cout << endl;

  cb.submitMove("F1","E2");
  cb.submitMove("D5","G2");
  cout << endl;

  cb.submitMove("E2","F3");
  cb.submitMove("G2","G6");
  cout << endl;

  cb.submitMove("D1","D2");
  cb.submitMove("E6","E5");
  cout << endl;

  cb.submitMove("E1","C1");
  cb.submitMove("E5","D4");
  cout << endl;

  cb.submitMove("E3","D4");
  cb.submitMove("B8","C6");
  cout << endl;

  cb.submitMove("D4","F6");
  cb.submitMove("G6","F6");
  cout << endl;

  cb.submitMove("H1","E1");
  cb.submitMove("F8","E7");
  cout << endl;

  cb.submitMove("F3","C6");
  cb.submitMove("E8","F8");
  cout << endl;

  cb.submitMove("D2","D8");
  cb.submitMove("E7","D8");
  cout << endl;

  cb.submitMove("E1","E8");
  cout << endl;

  cb.resetBoard();
  /* This game includes castling */
/* Link - http://www.thechesswebsite.com/levitsky-vs-marshall-gold-coin-chess-game/ */
cout << "=======================" << endl;
cout << "XXX vs. YYY (1933)" << endl;
cout << "=======================" << endl;
    cout << "This game includes castling" << endl;
    cb.submitMove("D2", "D4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("C7", "C5");
    cout << endl;

    cb.submitMove("G1", "F3");
    cb.submitMove("B8", "C6");
    cout << endl;

    cb.submitMove("E4", "D5");
    cb.submitMove("E6", "D5");
    cout << endl;

    cb.submitMove("F1", "E2");
    cb.submitMove("G8", "F6");
    cout << endl;
    /* The next move here is castling */
    cout << "The next move here is castling" << endl;
    cb.resetBoard();

    // testing for errors
    cout << "=======================" << endl;
    cout << "Error checking" << endl;
    cout << "=======================" << endl;
    cout << "Moving your pawn forward three spaces:" << endl;
    cb.submitMove("C2", "C5");
    cout << endl;

    cout << "Moving your knight forward two spaces:" << endl;
    cb.submitMove("B1", "B3");
    cout << endl;

    cb.submitMove("D2", "D3");
    cb.submitMove("A7", "A6");
    cout << endl;

    cb.submitMove("C1", "E3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cout << "Moving your pawn backwards on its first move:" << endl;
    cb.submitMove("C2", "C1");
    cout << endl;

    cb.resetBoard();
    cout << "=======================" << endl;
    cout << "Castling fails while castling" << endl;
    cout << "=======================" << endl;
    // Castling fails
    cout << "This test fails while castling" << endl;
    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cb.submitMove("C2", "C4");
    cb.submitMove("E7", "E6");
    cb.submitMove("B1", "C3");
    cb.submitMove("G8", "F6");
    cb.submitMove("C1", "G5");
    cb.submitMove("F6", "G4");
    cb.submitMove("D1", "D2");
    cb.submitMove("G4", "F2");
    cb.submitMove("E1", "C1");
    cout << endl;

    cb.resetBoard();

    //Short Checkmate
//Alekhine vs Bruce (1938)
cout << "=======================" << endl;
cout << "Alekhine vs Bruce (1938)" << endl;
cout << "=======================" << endl;
    cout << "Short checkmate1" << endl;
    cb.submitMove("E2", "E4"); //1
    cb.submitMove("C7", "C6");
    cout << endl;

    cb.submitMove("B1", "C3"); //2
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("G1", "F3"); //3
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("C3", "E4"); //4
    cb.submitMove("C8", "F5");
    cout << endl;

    cb.submitMove("E4", "G3"); //5
    cb.submitMove("F5", "G6");
    cout << endl;

    cb.submitMove("H2", "H4");//6
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("F3", "E5");//7
    cb.submitMove("G6", "H7");
    cout << endl;

    cb.submitMove("D1", "H5"); //8
    cb.submitMove("G7", "G6");
    cout << endl;

    cb.submitMove("F1", "C4"); //9
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("H5", "E2");//10
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E5", "F7"); //11
    cb.submitMove("E8", "F7");
    cout << endl;

    cb.submitMove("E2", "E6"); //12
    cb.submitMove("F7", "G7");
    cout << endl;

    cb.submitMove("E6", "F7"); //12
    cout << endl;

    cb.resetBoard();
    // Short Checkmate 2
    cout << "=======================" << endl;
    cout << "Short Checkmate 2" << endl;
    cout << "=======================" << endl;
    cout << "Shrot checkmate 2" << endl;
    cb.submitMove("E2", "E4"); //1
    cb.submitMove("C7", "C6");
    cout << endl;

    cb.submitMove("B1", "C3"); //2
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("G1", "F3"); //3
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("C3", "E4"); //4
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("D1", "E2"); //5
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("E4", "D6");//6

    cb.resetBoard();
    // Short checkmate 3
    cout << "=======================" << endl;
    cout << "Short Checkmate 3" << endl;
    cout << "=======================" << endl;
    cout << "Short checkmate3 " << endl;
    cb.submitMove("E2", "E4"); //1
    cb.submitMove("C7", "C6");
    cout << endl;

    cb.submitMove("D2", "D4"); //2
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("F1", "D3"); //3
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "E5"); //4
    cb.submitMove("F6", "D7");
    cout << endl;

    cb.submitMove("E5", "E6"); //5
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D1", "H5");//6
    cb.submitMove("G7", "G6");
    cout << endl;

    cb.submitMove("H5", "G6");//7
    cb.submitMove("H7", "G6");
    cout << endl;

    cb.submitMove("D3", "G6"); //8

    cout << endl;

    cb.resetBoard();
    //Short Stalemate
  //Upmark vs Johansson (1995)
  cout << "=======================" << endl;
  cout << "Upmark vs Johansson (1995)" << endl;
  cout << "=======================" << endl;
  cout << "Short stalemate 1" << endl;
  cb.submitMove("E2", "E3"); //1
  cb.submitMove("A7", "A5");
  cout << endl;

  cb.submitMove("D1", "H5"); //2
  cb.submitMove("A8", "A6");
  cout << endl;

  cb.submitMove("H5", "A5"); //3
  cb.submitMove("H7", "H5");
  cout << endl;

  cb.submitMove("H2", "H4"); //4
  cb.submitMove("A6", "H6");
  cout << endl;

  cb.submitMove("A5", "C7"); //5
  cb.submitMove("F7", "F6");
  cout << endl;

  cb.submitMove("C7", "D7");//6
  cb.submitMove("E8", "F7");
  cout << endl;

  cb.submitMove("D7", "B7");//7
  cb.submitMove("D8", "D3");
  cout << endl;

  cb.submitMove("B7", "B8"); //8
  cb.submitMove("D3", "H7");
  cout << endl;

  cb.submitMove("B8", "C8"); //9
  cb.submitMove("F7", "G6");
  cout << endl;

  cb.submitMove("C8", "E6"); //10

  cout << endl;

  cb.resetBoard();
  cout << "=======================" << endl;
  cout << "Hohmeister vs Frank (1993)" << endl;
  cout << "=======================" << endl;

  //Short Stalemate
  //Hohmeister vs Frank (1993)
  cout << "Short Stalemate 2" << endl;
  cb.submitMove("D2", "D4"); //1
  cb.submitMove("E7", "E5");
  cout << endl;

  cb.submitMove("D1", "D2"); //2
  cb.submitMove("E5", "E4");
  cout << endl;

  cb.submitMove("D2", "F4"); //3
  cb.submitMove("F7", "F5");
  cout << endl;

  cb.submitMove("H2", "H3"); //4
  cb.submitMove("F8", "B4");
  cout << endl;

  cb.submitMove("B1", "D2"); //5
  cb.submitMove("D7", "D6");
  cout << endl;

  cb.submitMove("F4", "H2");//6
  cb.submitMove("C8", "E6");
  cout << endl;

  cb.submitMove("A2", "A4");//7
  cb.submitMove("D8", "H4");
  cout << endl;

  cb.submitMove("A1", "A3"); //8
  cb.submitMove("C7", "C5");
  cout << endl;

  cb.submitMove("A3", "G3"); //9
  cb.submitMove("F5", "F4");
  cout << endl;

  cb.submitMove("F2", "F3");//10
  cb.submitMove("E6", "B3");
  cout << endl;

  cb.submitMove("D4", "D5"); //11
  cb.submitMove("B4", "A5");
  cout << endl;

  cb.submitMove("C2", "C4"); //12
  cb.submitMove("E4", "E3");
  cout << endl;

  cout << "===========================" << endl;
  cout << "Hohmeister vs. Frank (1993)" << endl;
  cout << "===========================" << endl;
  cout << "Stalemate 3" << endl;
  cout << endl;

  cb.resetBoard();
  cout << endl;

  cb.submitMove("D2", "D4");
  cb.submitMove("E7", "E5");
  cout << endl;

  cb.submitMove("D1", "D2");
  cb.submitMove("E5", "E4");
  cout << endl;

  cb.submitMove("D2", "F4");
  cb.submitMove("F7", "F5");
  cout << endl;

  cb.submitMove("H2", "H3");
  cb.submitMove("F8", "B4");
  cout << endl;

  cb.submitMove("B1", "D2");
  cb.submitMove("D7", "D6");
  cout << endl;

  cb.submitMove("F4", "H2");
  cb.submitMove("C8", "E6");
  cout << endl;

  cb.submitMove("A2", "A4");
  cb.submitMove("D8", "H4");
  cout << endl;

  cb.submitMove("A1", "A3");
  cb.submitMove("C7", "C5");
  cout << endl;

  cb.submitMove("A3", "G3");
  cb.submitMove("F5", "F4");
  cout << endl;

  cb.submitMove("F2", "F3");
  cb.submitMove("E6", "B3");
  cout << endl;

  cb.submitMove("D4", "D5");
  cb.submitMove("B4", "A5");
  cout << endl;

  cb.submitMove("C2", "C4");
  cb.submitMove("E4", "E3");
  cout << endl;

  cb.resetBoard();
  cout << endl;
  cout << "===============================" << endl;
  cout << "Lindemann vs Echtermeyer (1893)" << endl;
  cout << "===============================" << endl;
  cout << "White is in checkmate" << endl;
  cout << endl;

  cout << endl;

  cb.submitMove("E2", "E4");
  cb.submitMove("D7", "D5");
  cout << endl;

  cb.submitMove("E4", "D5");
  cb.submitMove("D8", "D5");
  cout << endl;

  cb.submitMove("E1", "E2");
  cb.submitMove("D5", "E4");
  cout << endl;


  return 0;
}
