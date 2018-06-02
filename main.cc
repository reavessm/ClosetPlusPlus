#include "main.h"
/******************************************************************************
 * File Name: main.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

int main(int argc, char** argv) {
 
	// if arg is Make, Build, Pick, do things

  string fileSurname = " Closet.txt";
  string cloSurname = " Closet.clo";
  string fileFrontName = "Dummy";
  string filename = "FakeFileName";
  string cloname = "fakeCLoName";
//  string storeFileSurName = " Closet.clo";
//  string storeFileName = "FakerFileName";
//  ofstream storeMyFile;
  ofstream myFile;
  ofstream myClo;

  Closet closet;

//  if ( there is a clo file) {
//	  Ask if they want to use one of those files
//	  if ( yes ) {
//		closet.BuildCloset( chosen clo file);
//	  } else {
//		closet.MakeCloset();
//	  }
//  } else {

    initscr();
    start_color();

    init_color(COLOR_RED, 500, 0, 100);

    init_pair(1, COLOR_BLUE, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_BLUE);
    

   // attron(COLOR_PAIR(1));
    wbkgd(stdscr, COLOR_PAIR(1));
    refresh();

  	closet.MakeCloset();

    endwin();
//  }

  fileFrontName = closet.GetClosetName();
  filename = fileFrontName + fileSurname;
  cloname = fileFrontName + cloSurname;
//  storeFileName = fileFrontName + storeFileSurname;

  myFile.open(filename.c_str());
  myClo.open(cloname.c_str());

//  storeMyFile.open(storeFileName.c_str());

  myFile << closet.ToString();
  cout << closet.ToString();
  myClo << closet.StoreCloset();
//  storeMyFile << closet.StoreCloset();

  myFile.close();
  myClo.close();
//  storeMyFile.close();

  return 0;
}
