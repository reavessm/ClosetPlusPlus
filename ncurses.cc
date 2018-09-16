/**
 * @class Ncurses
 * @file ncurses.cc
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 */

#include "frontend.h"
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
  closet_name_ = this.MakeWindow(kClosetPrompt);
  backend_.closet_name_ = this.closet_name_;

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
  } while (shirtID == -1);  // AssignID returns -1 if there is an error

  // Create Shirt object using the filled in variables
  Shirt shirt(shirtID, shirtName, shirtPrimColor, shirtSecColor, shirtTertColor,
              shirtPattern, shirtSleeveLength, shirtCollar);

  return shirt;
}  // end AddShirt

/**
 * AddPants
 * @returns An instance of the 'Pants' class.
 * @brief Creates a 'Pants' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Pants'.  This function then calls the parameterized
 *         constructor for a 'Pants' using those details.
 */
Pants Ncurses::AddPants() {
  // instantiate variables with dummy values
  string pantsName;
  string pantsPrimColor;
  string pantsSecColor;
  string pantsTertColor;
  string pantsMaterial;
  string pantsLength;
  string pantsCut;
  int pantsID = -1;

  // Begin putting in actual values
  pantsName = this.MakeWindow(kPantsNamePrompt);
  pantsPrimColor = this.MakeWindow(kPrimColorPrompt);
  pantsSecColor = this.MakeWindow(kSecColorPrompt);
  pantsTertColor = this.MakeWindow(kTertColorPrompt);
  pantsMaterial = this.MakeWindow(kMatPrompt);
  pantsLength = this.MakeWindow(kLenPrompt);
  pantsCut = this.MakeWindow(kCutPrompt);

  do {
    pantsID = backend_.AssignID("pants");
  } while (pantsID == -1);  // AssignID returns -1 if there is an error

  // Create Pants using filled in variables
  Pants pants(pantsID, pantsName, pantsPrimColor, pantsSecColor, pantsTertColor,
              pantsMaterial, pantsLength, pantsCut);

  return pants;
}

/**
 * AddSocks
 * @returns An instance of the 'Socks' class.
 * @brief Creates a 'Socks' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Socks'.  This function then calls the parameterized
 *         constructor for a 'Socks' using those details.
 */
Socks Ncurses::AddSocks() {
  // instantiate variables with dummy values
  string socksName;
  string socksPrimColor;
  string socksSecColor;
  string socksTertColor;
  string socksPattern;
  int socksID = -1;

  // Begin putting in actual values
  socksName = this.MakeWindow(kSocksNamePrompt);
  socksPrimColor = this.MakeWindow(kPrimColorPrompt);
  socksSecColor = this.MakeWindow(kSecColorPrompt);
  socksTertColor = this.MakeWindow(kTertColorPrompt);
  socksPattern = this.MakeWindow(kPatternPrompt);

  do {
    socksID = backend_.AssignID("socks");
  } while (socksID == -1);  // AssignID returns -1 if there is an error

  // Create Socks using filled in variables
  Socks socks(socksID, socksName, socksPrimColor, socksSecColor, socksTertColor,
              socksPattern);

  return socks;
}

/**
 * AddShoes
 * @returns An instance of the 'Shoes' class.
 * @brief Creates a 'Shoes' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Shoes'.  This function then calls the parameterized
 *         constructor for a 'Shoes' using those details.
 */
Shoes Ncurses::AddShoes() {
  // instantiate variables with dummy values
  string shoesName;
  string shoesPrimColor;
  string shoesSecColor;
  string shoesTertColor;
  string shoesMaterial;
  string shoesStyle;
  int shoesID = -1;

  // Begin putting in actual values
  shoesName = this.MakeWindow(kShoesNamePrompt);
  shoesPrimColor = this.MakeWindow(kPrimColorPrompt);
  shoesSecColor = this.MakeWindow(kSecColorPrompt);
  shoesTertColor = this.MakeWindow(kTertColorPrompt);
  shoesMaterial = this.MakeWindow(kMatPrompt);
  shoesStyle = this.MakeWindow(kStylePrompt);

  do {
    shoesID = backend_.AssignID("shoes");
  } while (shoesID == -1);  // AssignID returns -1 if there is an error

  // Create Shoes using filled in variables
  Shoes shoes(shoesID, shoesName, shoesPrimColor, shoesSecColor, shoesTertColor,
              shoesMaterial, shoesStyle);

  return shoes;
}

/**
 * AddBelt
 * @returns An instance of the 'Belt' class.
 * @brief Creates a 'Belt' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Belt'.  This function then calls the parameterized
 *         constructor for a 'Belt' using those details.
 */
Belt Ncurses::AddBelt() {
  // instantiate variables with dummy values
  string beltName;
  string beltPrimColor;
  string beltSecColor;
  string beltTertColor;
  string beltMaterial;
  string beltPattern;
  int beltID = -1;

  cin.ignore();

  // Begin putting in actual values
  beltName = this.MakeWindow(kBeltNamePrompt);
  beltPrimColor = this.MakeWindow(kPrimColorPrompt);
  beltSecColor = this.MakeWindow(kSecColorPrompt);
  beltTertColor = this.MakeWindow(kTertColorPrompt);
  beltMaterial = this.MakeWindow(kMatPrompt);
  beltPattern = this.MakeWindow(kPatternPrompt);

  do {
    beltID = backend_.AssignID("belt");
  } while (beltID == -1);  // AssignID returns -1 if there is an error

  // Create Belt using filled in variables
  Belt belt(beltID, beltName, beltPrimColor, beltSecColor, beltTertColor,
            beltMaterial, beltPattern);

  return belt;
}
/**
 * ToString
 * @brief displays 'string' representing the closet
 */
void Ncurses::ToString() const { this.MakeWindow(backend_.ToString()); }
