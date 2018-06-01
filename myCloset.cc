#include "myCloset.h"
/******************************************************************************
 * File Name: myCloset.cc
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

/******************************************************************************
 * Constructor
 */
Closet::Closet() {}

/******************************************************************************
 * Deconstructor
 */
Closet::~Closet() {}

/**********************************************1********************************
 * Accessors and Mutators
 */

string Closet::GetClosetName() { return this->closet_name_; }


/******************************************************************************
 * General Functions
 */

/******************************************************************************
 * Funtion 'MakeCloset'
 * Summary: This function is the wrapper function that is responsible for
 * creating the clothes and then inserting them to the appropriate map
 */
void Closet::MakeCloset() {
  // Initialize variables
  char ans = 'k'; //dummy character
  string str = "";
  string message = "";

  //Name Closet
  closet_name_ = Window("Enter a Closet Name: ");
 
  //Add Shirt(s)
  ans = WindowChar("Would you like to add a shirt? [y/n] ");
  while ( ans == 'y' || ans == 'Y' ) {
    Shirt shirt;
    shirt = AddShirt();
    shirt_map_.insert(pair<int, Shirt>(shirt.GetID(), shirt));
    ans = WindowChar("Would you like to add another shirt? [y/n] ");
  }
  //endwin();

//  cin.ignore();
  //Add Pants
  ans = WindowChar("Would you like to add a pants? [y/n] ");
  while (ans == 'y' || ans == 'Y') {
    Pants pants;
    pants = AddPants();
    pants_map_.insert(pair<int, Pants>(pants.GetID(), pants));
    ans = WindowChar("Would you like to add another pair of pants? [y/n] ");
  }
//  endwin();

  //Add Belt(s)
/*  cout << "Would you like to add a belt? [y/n]" << endl;
  cin >> ans;
  while ( ans == 'y' || ans == 'Y' ) {
    Belt belt;
    belt = AddBelt();
    belt_map_.insert(pair<int, Belt>(belt.GetID(), belt));
    cout << "Would you like to add another belt? [y/n]" << endl;
    cin >> ans;
  }
*/
  ans = WindowChar("Would you like to add a belt? [y/n] ");
  while (ans == 'y' || ans == 'Y') {
    Belt belt;
    belt = AddBelt();
    belt_map_.insert(pair<int, Belt>(belt.GetID(), belt));
    ans = WindowChar("Would you like to add another pair of pants? [y/n] ");
  }

//  cin.ignore();
  //Add Socks
/*  cout << "Would you like to add a pair of socks? [y/n]" << endl;
  cin >> ans;
  while ( ans == 'y' || ans == 'Y' ) {
    Socks socks;
    socks = AddSocks();
    socks_map_.insert(pair<int, Socks>(socks.GetID(), socks));
    cout << "Would you like to add another pair of socks? [y/n]" << endl;
    cin >> ans;
  }
*/
  ans = WindowChar("Would you like to add some socks? [y/n] ");
  while (ans == 'y' || ans == 'Y') {
    Socks socks;
    socks = AddSocks();
    socks_map_.insert(pair<int, Socks>(socks.GetID(), socks));
    ans = WindowChar("Would you like to add more socks? [y/n] ");
  }

  cin.ignore();
  //Add Shoes
  cout << "Would you like to add a pair of shoes? [y/n]" << endl;
  cin >> ans;
  while ( ans == 'y' || ans == 'Y' ) {
    Shoes shoes;
    shoes = AddShoes();
    shoes_map_.insert(pair<int, Shoes>(shoes.GetID(), shoes));
    cout << "Would you like to add another pair of shoes? [y/n]" << endl;
    cin >> ans;
  }
}

/******************************************************************************
 *  Function 'MakeCloset'
 *  Summary: This function builds a Closet from an XML file, then calls the
 *  default 'MakeCloset' function.
 */
void Closet::MakeCloset(string filename) {
  // Use TinyXML-2
  //}
}

/******************************************************************************
 * Funtion 'AddShirt'
 * Returns:
 *    an instance of the 'Shirt' Class.
 * Summary:
 *    This function will take user input to record the necessary details for
 *    making a new 'Shirt'.  This function then calls the parameterized
 *    constructor for a 'Shirt' using those details.
 */
Shirt Closet::AddShirt() {
  //Instantiate variables with dummy values
  int shirtID = -1;
  string shirtName = "N/A";
  string shirtPrimColor = "N/A";
  string shirtSecColor = "N/A";
  string shirtTertColor = "N/A";
  string shirtPattern = "N/A";
  string shirtSleeveLength = "N/A";
  string shirtCollar = "N/A";

  cin.ignore();//fixes issue where it 'forgot' to ask for name of shirt.  Idk why this works...

  //Begin putting in actual values
  shirtName = Window("Please enter the name of the shirt: ");
  shirtPrimColor = Window("Please enter the primary color for " 
                           + shirtName + ": ");
  shirtSecColor = Window("Please enter the secondary color for " 
                           + shirtName + ": ");
  shirtTertColor = Window("Please enter the tertiary color for " 
                           + shirtName + ": ");
  shirtPattern = Window("Please enter the pattern for " 
                           + shirtName + ": ");
  shirtSleeveLength = Window("Please enter the sleeve length for " 
                           + shirtName + " (short, long): ");

  do {
    shirtID = AssignID("shirt");
  } while (shirtID == -1); //AssignID returns -1 if there is an error

  //Create Shirt object using the filled in variables
  Shirt shirt(shirtID, shirtName, shirtPrimColor, shirtSecColor, 
              shirtTertColor, shirtPattern, shirtSleeveLength, shirtCollar);
  
  return shirt;
}

/******************************************************************************
 * Function 'AddPants'
 * Returns:
 *    an instance of the 'Pants' class.
 * Summary:
 *    This function will take user input to record the necessary details for
 *    making a new 'Pants'.  This function then calls the parameterized
 *    constructor for a 'Pants' using those details.
 */
Pants Closet::AddPants() {
  //instantiate variables with dummy values
  int pantsID = -1;
  string pantsName = "N/A";
  string pantsPrimColor = "N/A";
  string pantsSecColor = "N/A";
  string pantsTertColor = "N/A";
  string pantsMaterial = "N/A";
  string pantsLength = "N/A";
  string pantsCut = "N/A";

  cin.ignore();

  //Begin putting in actual values
/*  cout << "Please enter a name for this pair of pants:" << endl;
  getline(cin, pantsName);

  cout << "Please enter the primary color for " << pantsName << "." << endl;
  getline(cin, pantsPrimColor);

  cout << "Please enter the secondary color for " << pantsName << ", or n/a." << endl;
  getline(cin, pantsSecColor);

  cout << "Please enter the tertiary color for " << pantsName << ", or n/a." << endl;
  getline(cin, pantsTertColor);
  
  cout << "Please enter the material for " << pantsName << " (denim, chino, etc.)." << endl;
  getline(cin, pantsMaterial);

  cout << "Please enter the length for " << pantsName << " (long, shorts, capris, etc.)." << endl;
  getline(cin, pantsLength);

  cout << "Please enter the cut for " << pantsName << " (boot, skinny, etc.)." << endl;
  getline(cin, pantsCut);
*/
  pantsName = Window("Please enter the name of the pants: ");
  pantsPrimColor = Window("Please enter the primary color for " 
                           + pantsName + ": ");
  pantsSecColor = Window("Please enter the secondary color for " 
                           + pantsName + ": ");
  pantsTertColor = Window("Please enter the tertiary color for " 
                           + pantsName + ": ");
  pantsMaterial = Window("Please enter the material for " 
                           + pantsName + ": ");
  pantsLength = Window("Please enter the sleeve length for " 
                           + pantsName + ": ");
  pantsCut = Window("Please enter the cut for "
                           + pantsName + ": ");

  do {
    pantsID = AssignID("pants");
  } while (pantsID == -1); //AssignID returns -1 if there is an error

  //Create Pants using filled in variables
  Pants pants(pantsID, pantsName, pantsPrimColor, pantsSecColor, pantsTertColor, pantsMaterial, pantsLength, pantsCut);

  return pants;
}

/******************************************************************************
 * Function 'AddSocks'
 * Returns:
 *    an instance of the 'Socks' class.
 * Summary:
 *    This function will take user input to record the necessary details for
 *    making a new 'Socks'.  This function then calls the parameterized
 *    constructor for a 'Socks' using those details.
 */
Socks Closet::AddSocks() {
  //instantiate variables with dummy values
  int socksID = -1;
  string socksName = "N/A";
  string socksPrimColor = "N/A";
  string socksSecColor = "N/A";
  string socksTertColor = "N/A";
  string socksPattern = "N/A";

  cin.ignore();

  //Begin putting in actual values
  cout << "Please enter a name for this pair of socks:" << endl;
  getline(cin, socksName);

  cout << "Please enter the primary color for " << socksName << "." << endl;
  getline(cin, socksPrimColor);

  cout << "Please enter the secondary color for " << socksName << ", or n/a." << endl;
  getline(cin, socksSecColor);

  cout << "Please enter the tertiary color for " << socksName << ", or n/a." << endl;
  getline(cin, socksTertColor);
  
  cout << "Please enter the pattern for " << socksName << ", or n/a." << endl;
  getline(cin, socksPattern);

  do {
    socksID = AssignID("socks");
  } while (socksID == -1); //AssignID returns -1 if there is an error

  //Create Socks using filled in variables
  Socks socks(socksID, socksName, socksPrimColor, socksSecColor, socksTertColor, socksPattern);

  return socks;
}

/******************************************************************************
 * Function 'AddShoes'
 * Returns:
 *    an instance of the 'Shoes' class.
 * Summary:
 *    This function will take user input to record the necessary details for
 *    making a new 'Shoes'.  This function then calls the parameterized
 *    constructor for a 'Shoes' using those details.
 */
Shoes Closet::AddShoes() {
  //instantiate variables with dummy values
  int shoesID = -1;
  string shoesName = "N/A";
  string shoesPrimColor = "N/A";
  string shoesSecColor = "N/A";
  string shoesTertColor = "N/A";
  string shoesMaterial = "N/A";
  string shoesStyle = "N/A";

  cin.ignore();

  //Begin putting in actual values
  cout << "Please enter a name for this pair of shoes:" << endl;
  getline(cin, shoesName);

  cout << "Please enter the primary color for " << shoesName << "." << endl;
  getline(cin, shoesPrimColor);

  cout << "Please enter the secondary color for " << shoesName << ", or n/a." << endl;
  getline(cin, shoesSecColor);

  cout << "Please enter the tertiary color for " << shoesName << ", or n/a." << endl;
  getline(cin, shoesTertColor);
  
  cout << "Please enter the material for " << shoesName << " (leather, suede, etc.)." << endl;
  getline(cin, shoesMaterial);

  cout << "Please enter the style for " << shoesName << " (tennis, oxford, etc.)." << endl;
  getline(cin, shoesStyle);

  do {
    shoesID = AssignID("shoes");
  } while (shoesID == -1); //AssignID returns -1 if there is an error

  //Create Shoes using filled in variables
  Shoes shoes(shoesID, shoesName, shoesPrimColor, shoesSecColor, shoesTertColor, shoesMaterial, shoesStyle);

  return shoes;
}

/******************************************************************************
 * Function 'AddBelt'
 * Returns:
 *    an instance of the 'Belt' class.
 * Summary:
 *    This function will take user input to record the necessary details for
 *    making a new 'Belt'.  This function then calls the parameterized
 *    constructor for a 'Belt' using those details.
 */
Belt Closet::AddBelt() {
  //instantiate variables with dummy values
  int beltID = -1;
  string beltName = "N/A";
  string beltPrimColor = "N/A";
  string beltSecColor = "N/A";
  string beltTertColor = "N/A";
  string beltMaterial = "N/A";
  string beltPattern = "N/A";

  cin.ignore();

  //Begin putting in actual values
  cout << "Please enter a name for this belt:" << endl;
  getline(cin, beltName);

  cout << "Please enter the primary color for " << beltName << "." << endl;
  getline(cin, beltPrimColor);

  cout << "Please enter the secondary color for " << beltName << ", or n/a." << endl;
  getline(cin, beltSecColor);

  cout << "Please enter the tertiary color for " << beltName << ", or n/a." << endl;
  getline(cin, beltTertColor);
  
  cout << "Please enter the material for " << beltName << " (leather, tweed, etc.)." << endl;
  getline(cin, beltMaterial);

  cout << "Please enter the pattern for " << beltName << " (solid, striped, etc.)." << endl;
  getline(cin, beltPattern);

  do {
    beltID = AssignID("belt");
  } while (beltID == -1); //AssignID returns -1 if there is an error

  //Create Belt using filled in variables
  Belt belt(beltID, beltName, beltPrimColor, beltSecColor, beltTertColor, beltMaterial, beltPattern);

  return belt;
}


/******************************************************************************
 * Function 'AssignID'
 * Parameters:
 *    a string dictating the type of clothing to check.
 * Returns:
 *    an integer corrosponding to the next available ID for the given type, or
 *    -1 for an error.
 * Summary:
 *    This function assigns the next available ID number for a given type.  The
 *    last two numbers represent the number of the given type, while the other
 *    numbers represent the type.  For Example, if there are currently 4
 *    shirts, then the next shirt will have the ID of 105.  The 100 represents
 *    shirts, while the 05 means it is the fifth shirt. This allows for 99
 *    items of a given type and (2^29)-1 types??? 
 *
 *    NOTE:   So far the types are hard coded in.  Meaning you can only create
 *            clothes that are either shirts, pants, belts, socks, or shoes.
 *            There is currently no way to dynamically add types.  Underwear
 *            types were intentionally left out to test the best way to
 *            dynamically add new types.
 */
int Closet::AssignID(string type) {
  int id = -1; //dummy id number
  //switch (type){
  //  case "shirt":
  //  TODO Use Switch-case
  if ( type == "shirt" ) {
      id = 100 + static_cast<int>(shirt_map_.size());
  } else if ( type == "pants" ) {
      id = 200 + static_cast<int>(pants_map_.size());
  } else if ( type == "belt" ) {
      id = 300 + static_cast<int>(belt_map_.size());
  } else if ( type == "socks") {
      id = 400 + static_cast<int>(socks_map_.size());
  } else if ( type == "shoes" ) {
      id = 500 + static_cast<int>(shoes_map_.size());
  } else {
      cout << "Error, please enter a correct type of clothing" << endl;
      cin >> type;
      id = AssignID(type);
  }
  return id;
}
/******************************************************************************
 * Function 'StoreCloset'
 * Returns:
 *    XML representation of closet
 */
string Closet::StoreCloset() const {
  string s = "";
  
  s += "<Closet>\n";
  for (map<int, Shirt>::const_iterator iter = shirt_map_.cbegin(); iter != shirt_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }
  
  for (map<int, Pants>::const_iterator iter = pants_map_.cbegin(); iter != pants_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }
 
  for (map<int, Socks>::const_iterator iter = socks_map_.cbegin(); iter != socks_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }
  
  for (map<int, Shoes>::const_iterator iter = shoes_map_.cbegin(); iter != shoes_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }
  
  for (map<int, Belt>::const_iterator iter = belt_map_.cbegin(); iter != belt_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }
 
  s += "</Closet>\n";

  return s;
}

/******************************************************************************
 * Function 'ToString'
 * Returns:
 *    'string' representing the closet
 */
string Closet::ToString() const {
  string s = "";

  s += "\n*********** Shirts ************\n";
  for (map<int, Shirt>::const_iterator iter = shirt_map_.cbegin(); iter != shirt_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Pants **************\n";
  for (map<int, Pants>::const_iterator iter = pants_map_.cbegin(); iter != pants_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Socks **************\n";
  for (map<int, Socks>::const_iterator iter = socks_map_.cbegin(); iter != socks_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Shoes **************\n";
  for (map<int, Shoes>::const_iterator iter = shoes_map_.cbegin(); iter != shoes_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Belts **************\n";
  for (map<int, Belt>::const_iterator iter = belt_map_.cbegin(); iter!= belt_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  return s;
}

/*******************************************************************************
 * Function 'WindowChar'
 * Returns: char representing user input
 * Summary: This function rewrites the ncurses window
 */

char Closet::WindowChar(string message) {
  clear();
  
  // Initialize variables
  int row, col;
  getmaxyx(stdscr,row,col);


  // Print Message
  mvprintw(row/2,(col-message.length())/2,"%s",message.c_str());

  return getch();
}
/*******************************************************************************
 * Function 'Window'
 * Returns: string representing user input
 * Summary: This function rewrites the ncurses window
 */

string Closet::Window(string message) {
  clear();
  
  // Initialize variables
  string s = "";
  int row, col;
  getmaxyx(stdscr,row,col);


  // Print Message
  mvprintw(row/2,(col-message.length())/2,"%s",message.c_str());

  // Get Input
  int ch = getch();
  while (ch != '\n') {
    s.push_back(ch);
    ch = getch();
  }

  // Confirm Input
  mvprintw(LINES -2, 0, "You Entered: %s", s.c_str());
  getch();

  return s;
}


