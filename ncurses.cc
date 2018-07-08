/******************************************************************************
 * File Name: ncurses.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

#include "ncurses.h"

using namespace std;

/*******************************************************************************
 * Constructor
 */
Ncurses::Ncurses() {}

/*******************************************************************************
 * Deconstructor
 */
Ncurses::~Ncurses() {}

/*******************************************************************************
 * Function 'Init'
 * Returns: boolean representing success (or failure) of initialization
 * Summary:
 */
bool Ncurses::Init() {
  isInit_ = false;
  
  initscr();
  start_color();

  init_pair(1, COLOR_BLUE, COLOR_RED);

  wbkgd(stdscr, COLOR_PAIR(1));
  refresh();

  isInit_ = true;

  return isInit_;
}

void Ncurses::Die() {
  endwin();
}


/*******************************************************************************
 * Function 'MakeWindowChar'
 * Returns: char representing user input
 * Summary: This function rewrites the ncurses window
 */
char Ncurses::MakeWindowChar(string message) {
  clear();

  // Initialize Variables
  int row, col;
  getmaxyx(stdscr, row, col);

  // Print Message
  mvprintw(row/2,(col-message.length())/2, "%s", message.c_str());

  return getch();
}




/*******************************************************************************
 * Function 'Window'
 * Returns: string representing user input
 * Summary: This function rewrites the ncurses window
 */
string Ncurses::MakeWindow(string message) {
  clear();

  // Initialize Variables
  string s = "";
  int row, col;
  getmaxyx(stdscr,row,col);

  // Print Message
  mvprintw(row/2,(col-message.length())/2, "%s", message.c_str());

  // Get Input
  int ch = getch();
  while (ch != '\n') {
    s.push_back(ch);
    ch = getch();
  }

  return s;
}
