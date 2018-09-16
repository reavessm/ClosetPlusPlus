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

  //backend_ = Backend::Create();

  is_init_ = true;

  return is_init_;
}  // end Init

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
}  // end MakeWindowChar

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
}  // end MakeWindow

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
  char ans = 'k';  // dummy char
  string str = "";

  // Name Closet
  backend_.SetClosetName(this->MakeWindow(kClosetPrompt));

  // Add Shirt
  ans = this->MakeWindowChar(kShirtPrompt);
  while (ans == 'y' || ans == 'Y') {
    this->AddShirt();
    ans = this->MakeWindowChar(kShirtPrompt);
  }

  // Add Pants
  ans = this->MakeWindowChar(kPantsPrompt);
  while (ans == 'y' || ans == 'Y') {
    this->AddPants();
    ans = this->MakeWindowChar(kPantsPrompt);
  }

  // Add Belt
  ans = this->MakeWindowChar(kBeltPrompt);
  while (ans == 'y' || ans == 'Y') {
    this->AddBelt();
    ans = this->MakeWindowChar(kBeltPrompt);
  }

  // Add Socks
  ans = this->MakeWindowChar(kSocksPrompt);
  while (ans == 'y' || ans == 'Y') {
    this->AddSocks();
    ans = this->MakeWindowChar(kSocksPrompt);
  }

  // Add Shoes
  ans = this->MakeWindowChar(kShoesPrompt);
  while (ans == 'y' || ans == 'Y') {
    this->AddShoes();
    ans = this->MakeWindowChar(kShoesPrompt);
  }
}  // end CreateCloset

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
void Ncurses::AddShirt() {
  string shirtName;
  string shirtPrimColor;
  string shirtSecColor;
  string shirtTertColor;
  string shirtPattern;
  string shirtSleeveLen;
  string shirtCollar;

  shirtName = this->MakeWindow(kShirtNamePrompt);
  shirtPrimColor = this->MakeWindow(kPrimColorPrompt);
  shirtSecColor = this->MakeWindow(kSecColorPrompt);
  shirtTertColor = this->MakeWindow(kTertColorPrompt);
  shirtPattern = this->MakeWindow(kPatternPrompt);
  shirtSleeveLen = this->MakeWindow(kSleeveLenPrompt);
  shirtCollar = this->MakeWindow(kColPrompt);

  // Send info to backend
  backend_.InsertShirt(shirtName, shirtPrimColor, shirtSecColor,
                       shirtTertColor, shirtPattern, shirtSleeveLen,
                       shirtCollar);
}  // end AddShirt

/**
 * AddPants
 * @returns An instance of the 'Pants' class.
 * @brief Creates a 'Pants' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Pants'.  This function then calls the parameterized
 *         constructor for a 'Pants' using those details.
 */
void Ncurses::AddPants() {
  // instantiate variables with dummy values
  string pantsName;
  string pantsPrimColor;
  string pantsSecColor;
  string pantsTertColor;
  string pantsMaterial;
  string pantsLength;
  string pantsCut;

  // Begin putting in actual values
  pantsName      = this->MakeWindow(kPantsNamePrompt);
  pantsPrimColor = this->MakeWindow(kPrimColorPrompt);
  pantsSecColor  = this->MakeWindow(kSecColorPrompt);
  pantsTertColor = this->MakeWindow(kTertColorPrompt);
  pantsMaterial  = this->MakeWindow(kMatPrompt);
  pantsLength    = this->MakeWindow(kLenPrompt);
  pantsCut       = this->MakeWindow(kCutPrompt);

  // Send info to backend
  backend_.InsertPants(pantsName, pantsPrimColor, pantsSecColor, 
                       pantsTertColor, pantsMaterial, pantsLength, pantsCut);
}

/**
 * AddSocks
 * @returns An instance of the 'Socks' class.
 * @brief Creates a 'Socks' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Socks'.  This function then calls the parameterized
 *         constructor for a 'Socks' using those details.
 */
void Ncurses::AddSocks() {
  // instantiate variables with dummy values
  string socksName;
  string socksPrimColor;
  string socksSecColor;
  string socksTertColor;
  string socksPattern;

  // Begin putting in actual values
  socksName = this->MakeWindow(kSocksNamePrompt);
  socksPrimColor = this->MakeWindow(kPrimColorPrompt);
  socksSecColor = this->MakeWindow(kSecColorPrompt);
  socksTertColor = this->MakeWindow(kTertColorPrompt);
  socksPattern = this->MakeWindow(kPatternPrompt);

  // Send info to backend
  backend_.InsertSocks(socksName, socksPrimColor, socksSecColor, socksTertColor,
              socksPattern);
}

/**
 * AddShoes
 * @returns An instance of the 'Shoes' class.
 * @brief Creates a 'Shoes' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Shoes'.  This function then calls the parameterized
 *         constructor for a 'Shoes' using those details.
 */
void Ncurses::AddShoes() {
  // instantiate variables with dummy values
  string shoesName;
  string shoesPrimColor;
  string shoesSecColor;
  string shoesTertColor;
  string shoesMaterial;
  string shoesStyle;

  // Begin putting in actual values
  shoesName      = this->MakeWindow(kShoesNamePrompt);
  shoesPrimColor = this->MakeWindow(kPrimColorPrompt);
  shoesSecColor  = this->MakeWindow(kSecColorPrompt);
  shoesTertColor = this->MakeWindow(kTertColorPrompt);
  shoesMaterial  = this->MakeWindow(kMatPrompt);
  shoesStyle     = this->MakeWindow(kStylePrompt);

  // Send info to backend
  backend_.InsertShoes(shoesName, shoesPrimColor, shoesSecColor, shoesTertColor,
              shoesMaterial, shoesStyle);
}

/**
 * AddBelt
 * @returns An instance of the 'Belt' class.
 * @brief Creates a 'Belt' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Belt'.  This function then calls the parameterized
 *         constructor for a 'Belt' using those details.
 */
void Ncurses::AddBelt() {
  // instantiate variables with dummy values
  string beltName;
  string beltPrimColor;
  string beltSecColor;
  string beltTertColor;
  string beltMaterial;
  string beltPattern;

  // Begin putting in actual values
  beltName = this->MakeWindow(kBeltNamePrompt);
  beltPrimColor = this->MakeWindow(kPrimColorPrompt);
  beltSecColor = this->MakeWindow(kSecColorPrompt);
  beltTertColor = this->MakeWindow(kTertColorPrompt);
  beltMaterial = this->MakeWindow(kMatPrompt);
  beltPattern = this->MakeWindow(kPatternPrompt);

  // Send info to backend
  backend_.InsertBelt(beltName, beltPrimColor, beltSecColor, beltTertColor,
            beltMaterial, beltPattern);
}
