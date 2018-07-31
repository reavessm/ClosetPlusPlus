/**
 * @class Ncurses
 * @file ncurses.cc
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 */

#include "ncurses.h"

using namespace std;

/**
 * Default Constructor
 */
Ncurses::Ncurses() {}

/**
 * Deconstructor
 */
Ncurses::~Ncurses() {}

/**
 * Init
 * @returns Boolean representing success (or failure) of initialization
 * @brief Creates window and color pairs for Ncurses
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

/**
 * Die
 * @brief Kills the window
 */
void Ncurses::Die() { endwin(); }

/**
 * MakeWindowChar
 * @param message String to be displayed
 * @returns Char representing user input
 * @brief This function rewrites the ncurses window and returns a char
 */
char Ncurses::MakeWindowChar(string message) {
  clear();

  // Initialize Variables
  int row, col;
  getmaxyx(stdscr, row, col);

  // Print Message
  mvprintw(row / 2, (col - message.length()) / 2, "%s", message.c_str());

  return getch();
}

/**
 * MakeWindow
 * @param message String to be displayed
 * @returns String representing user input
 * @brief This function rewrites the ncurses window and returns a string
 */
string Ncurses::MakeWindow(string message) {
  clear();

  // Initialize Variables
  string s = "";
  int row, col;
  getmaxyx(stdscr, row, col);

  // Print Message
  mvprintw(row / 2, (col - message.length()) / 2, "%s", message.c_str());

  // Get Input
  int ch = getch();
  while (ch != '\n') {
    s.push_back(ch);
    ch = getch();
  }

  return s;
}
