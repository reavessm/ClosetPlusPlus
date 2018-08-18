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
  is_init_ = false;

  initscr();
  start_color();

  init_pair(1, COLOR_BLUE, COLOR_RED);

  wbkgd(stdscr, COLOR_PAIR(1));
  refresh();

  backend_ = Backend::Create();

  is_init_ = true;

  return is_init_;
} // end Init

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
} // end MakeWindowChar

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
} // end MakeWindow

/**
 * Make Closet
 * @brief This function is responsible for creating the backend and inserting
 *        the clothes.
 *
 * @detail For each type of clothing, this function asks the user if they want
 *         to add a new article. If they do, then call on 'Backend' to do the
 *         inserting
 */
void Ncurses::CreateCloset() {
  // Initialize variables
  char ans = 'k'; // dummy char
  string str = "";

  // Name Closet
  closet_name_ = this.MakeWindow(kClosetPrompt);

  // Add Shirt
  ans = this.MakeWindowChar(kShirtPrompt);
  while (ans == 'y' || ans == 'Y') {
    Shirt shirt;
    shirt = this.AddShirt();
    backend_.Insert(shirt.GetID(), shirt);
    ans = this.MakeWindowChar(kShirtPrompt);
  }

  // Add Pants
  ans = this.MakeWindowChar(kPantsPrompt);
  while (ans == 'y' || ans == 'Y') {
    Pants pants;
    pants = this.AddPants();
    backend_.Insert(pants.GetID(), pants);
    ans = this.MakeWindowChar(kPantsPrompt);
  }

  // Add Belt
  ans = this.MakeWindowChar(kBeltPrompt);
  while (ans == 'y' || ans == 'Y') {
    Belt belt;
    belt = this.AddBelt();
    backend_.Insert(belt.GetID(), belt);
    ans = this.MakeWindowChar(kBeltPrompt);
  }

  // Add Socks
  ans = this.MakeWindowChar(kSocksPrompt);
  while (ans == 'y' || ans == 'Y') {
    Socks socks;
    socks = this.AddSocks();
    backend_.Insert(socks.GetID(), socks);
    ans = this.MakeWindowChar(kSocksPrompt);
  }

  // Add Shoes
  ans = this.MakeWindowChar(kShoesPrompt);
  while (ans = 'y' || ans == 'Y') {
    Shoes shoes;
    shoes - this.AddShoes();
    backend_.Insert(shoes.GetID(), shoes);
    ans = this.MakeWindowChar(kShoesPrompt);
  }
} // end CreateCloset

/**
 * AddShirt
 * @brief Creates a 'Shirt' object
 * 
 * @detail This function will take user input to record the necessary details
 * for making a new 'Shirt'.  This calls the parameterized constructor for a
 * 'Shirt' using those details.
 * 
 * @returns an instance of the 'Shirt' class
 */
Shirt Ncurses::AddShirt() {
  string shirtName;
  string shirtPrimColor;
  string shirtSecColor;
  string shirtTertColor;
  string shirtPattern;
  string shirtSleeveLen;
  string shirtCollar;
  int shirtID = -1;

  shirtName = this.MakeWindow(kShirtNamePrompt);
  shirtPrimColor = this.MakeWindow(kPrimColorPrompt);
  shirtSecColor = this.MakeWindow(kSecColorPrompt);
  shirtTertColor = this.MakeWindow(kTertColorPrompt);
  shirtPattern = this.MakeWindow(kPatternPrompt);
  shirtSleeveLen = this.MakeWindow(kSleeveLenPrompt);
  shirtCollar = this.MakeWindow(kColPrompt);

  do {
    shirtID = backend_.AssignID("shirt");
  } while (shirtID == -1); // AssignID returns -1 if there is an error

  return shirt;
} // end AddShirt
