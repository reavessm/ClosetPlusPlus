#include "myCloset.h"
/**
 * @class Closet
 * @file closet.cc
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 *
 * @brief Creates and stores clothes
 *
 */

/**
 * Default Constructor
 */
Closet::Closet() {}

/**
 * Deconstructor
 *
 * @brief Closes the window, then kills the Closet
 */
Closet::~Closet() { window.Die(); }

/*******************************************************************************
 * Accessors and Mutators
 */

/**
 * GetClosetName
 *
 * @returns Name of the closet
 */
string Closet::GetClosetName() { return this->closet_name_; }

/******************************************************************************
 * General Functions
 */

/**
 * MakeCloset
 * @brief This function is the wrapper function that is responsible for
 *        creating the clothes and then inserting them to the appropriate map
 *
 * @detail For each type of clothing, this function asks the user if they want
 *         to add a new clothing of that type.  If they do then they call the
 *         clothing function to fill in the clothing specific details.  This
 *         function calls on 'Window' to handle the input.
 */
void Closet::MakeCloset() {
  // Initialize variables
  char ans = 'k';  // dummy character
  string str = "";
  string message = "";
  window.Init();

  // Name Closet
  message = "Enter a Closet Name: ";
  closet_name_ = window.MakeWindow(message);

  // Add Shirt(s)
  message = "Would you like to add a shirt? [y/n] ";
  ans = window.MakeWindowChar(message);
  while (ans == 'y' || ans == 'Y') {
    Shirt shirt;
    shirt = AddShirt();
    shirt_map_.insert(pair<int, Shirt>(shirt.GetID(), shirt));
    message = "Would you like to add another shirt? [y/n] ";
    ans = window.MakeWindowChar(message);
  }

  // Add Pants
  message = "Would you like to add a pants? [y/n] ";
  ans = window.MakeWindowChar(message);
  while (ans == 'y' || ans == 'Y') {
    Pants pants;
    pants = AddPants();
    pants_map_.insert(pair<int, Pants>(pants.GetID(), pants));
    message = "Would you like to add another pair of pants? [y/n] ";
    ans = window.MakeWindowChar(message);
  }

  // Add Belt
  message = "Would you like to add a belt? [y/n] ";
  ans = window.MakeWindowChar(message);
  while (ans == 'y' || ans == 'Y') {
    Belt belt;
    belt = AddBelt();
    belt_map_.insert(pair<int, Belt>(belt.GetID(), belt));
    message = "Would you like to add another belt? [y/n] ";
    ans = window.MakeWindowChar(message);
  }

  // Add Socks
  message = "Would you like to add some socks? [y/n] ";
  ans = window.MakeWindowChar(message);
  while (ans == 'y' || ans == 'Y') {
    Socks socks;
    socks = AddSocks();
    socks_map_.insert(pair<int, Socks>(socks.GetID(), socks));
    message = "Would you like to add more socks? [y/n] ";
    ans = window.MakeWindowChar(message);
  }

  // Add Shoes
  message = "Would you like to add some shoes? [y/n] ";
  ans = window.MakeWindowChar(message);
  while (ans == 'y' || ans == 'Y') {
    Shoes shoes;
    shoes = AddShoes();
    shoes_map_.insert(pair<int, Shoes>(shoes.GetID(), shoes));
    message = "Would you like to add some more shoes? [y/n] ";
    ans = window.MakeWindowChar(message);
  }
}

/**
 * ImportCloset
 * @brief This function builds a Closet from a file, then calls the default
 *         'MakeCloset' function.
 *
 * @note The filename must end in an acceptable filetype
 */
void Closet::ImportCloset(string filename) {
  // Use TinyXML-2
  //
  // string JSON = "json";
  // string CLO  = "clo";
  // size_t pos = filename.find('.');
  // if (pos == string::npos) {
  //  cerr << "Please enter a filename with the correct file extension" << endl
  //  exit 1
  //}
  // string filetype = filename.substr(pos);
  //
  // switch (filetype){
  //  case (JSON) :
  //    DO_JSON_STUFF
  //    break;;
  //  default :
  //   cerr << "Please enter an acceptable file type" << endl;
  //   exit 1
  //}
  //
  //}
}

/**
 * AddShirt
 * @brief Creates a 'Shirt' object
 *
 * @returns an instance of the 'Shirt' Class.
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Shirt'.  This function then calls the parameterized
 *         constructor for a 'Shirt' using those details.
 */
Shirt Closet::AddShirt() {
  // Instantiate variables with dummy values
  int shirtID = -1;
  string shirtName = "N/A";
  string shirtPrimColor = "N/A";
  string shirtSecColor = "N/A";
  string shirtTertColor = "N/A";
  string shirtPattern = "N/A";
  string shirtSleeveLength = "N/A";
  string shirtCollar = "N/A";

  cin.ignore();  // fixes issue where it 'forgot' to ask for name of shirt.  Idk
                 // why this works...

  // Begin putting in actual values
  shirtName = window.MakeWindow("Please enter the name of the shirt: ");
  shirtPrimColor = window.MakeWindow("Please enter the primary color for " +
                                     shirtName + ": ");
  shirtSecColor = window.MakeWindow("Please enter the secondary color for " +
                                    shirtName + ": ");
  shirtTertColor = window.MakeWindow("Please enter the tertiary color for " +
                                     shirtName + ": ");
  shirtPattern =
      window.MakeWindow("Please enter the pattern for " + shirtName + ": ");
  shirtSleeveLength = window.MakeWindow("Please enter the sleeve length for " +
                                        shirtName + " (short, long): ");

  do {
    shirtID = AssignID("shirt");
  } while (shirtID == -1);  // AssignID returns -1 if there is an error

  // Create Shirt object using the filled in variables
  Shirt shirt(shirtID, shirtName, shirtPrimColor, shirtSecColor, shirtTertColor,
              shirtPattern, shirtSleeveLength, shirtCollar);

  return shirt;
}

/**
 * AddPants
 * @returns An instance of the 'Pants' class.
 * @brief Creates a 'Pants' object
 * @detail This function will take user input to record the necessary details
 *         for making a new 'Pants'.  This function then calls the parameterized
 *         constructor for a 'Pants' using those details.
 */
Pants Closet::AddPants() {
  // instantiate variables with dummy values
  int pantsID = -1;
  string pantsName = "N/A";
  string pantsPrimColor = "N/A";
  string pantsSecColor = "N/A";
  string pantsTertColor = "N/A";
  string pantsMaterial = "N/A";
  string pantsLength = "N/A";
  string pantsCut = "N/A";

  cin.ignore();

  // Begin putting in actual values
  pantsName = window.MakeWindow("Please enter the name of the pants: ");
  pantsPrimColor = window.MakeWindow("Please enter the primary color for " +
                                     pantsName + ": ");
  pantsSecColor = window.MakeWindow("Please enter the secondary color for " +
                                    pantsName + ": ");
  pantsTertColor = window.MakeWindow("Please enter the tertiary color for " +
                                     pantsName + ": ");
  pantsMaterial =
      window.MakeWindow("Please enter the material for " + pantsName + ": ");
  pantsLength = window.MakeWindow("Please enter the sleeve length for " +
                                  pantsName + ": ");
  pantsCut = window.MakeWindow("Please enter the cut for " + pantsName + ": ");

  do {
    pantsID = AssignID("pants");
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
Socks Closet::AddSocks() {
  // instantiate variables with dummy values
  int socksID = -1;
  string socksName = "N/A";
  string socksPrimColor = "N/A";
  string socksSecColor = "N/A";
  string socksTertColor = "N/A";
  string socksPattern = "N/A";

  cin.ignore();

  // Begin putting in actual values
  socksName = window.MakeWindow("Please enter a name for this pair of socks: ");
  socksPrimColor = window.MakeWindow("Please enter the primary color for " +
                                     socksName + ": ");
  socksSecColor = window.MakeWindow("Please enter the secondary color for " +
                                    socksName + ": ");
  socksTertColor = window.MakeWindow("Please enter the tertiary color for " +
                                     socksName + ": ");
  socksPattern =
      window.MakeWindow("Please enter the pattern for " + socksName + ": ");

  do {
    socksID = AssignID("socks");
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
Shoes Closet::AddShoes() {
  // instantiate variables with dummy values
  int shoesID = -1;
  string shoesName = "N/A";
  string shoesPrimColor = "N/A";
  string shoesSecColor = "N/A";
  string shoesTertColor = "N/A";
  string shoesMaterial = "N/A";
  string shoesStyle = "N/A";

  cin.ignore();

  // Begin putting in actual values
  shoesName =
      window.MakeWindow("Please enter a name for these pairs of shoes: ");
  shoesPrimColor = window.MakeWindow("Please enter the primary color of " +
                                     shoesName + ": ");
  shoesSecColor = window.MakeWindow("Please enter the secondary color of " +
                                    shoesName + ": ");
  shoesTertColor = window.MakeWindow("Please enter the tertiary color of " +
                                     shoesName + ": ");
  shoesMaterial =
      window.MakeWindow("Please enter the material of " + shoesName + ": ");
  shoesStyle =
      window.MakeWindow("Please enter the style of " + shoesName + ": ");

  do {
    shoesID = AssignID("shoes");
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
Belt Closet::AddBelt() {
  // instantiate variables with dummy values
  int beltID = -1;
  string beltName = "N/A";
  string beltPrimColor = "N/A";
  string beltSecColor = "N/A";
  string beltTertColor = "N/A";
  string beltMaterial = "N/A";
  string beltPattern = "N/A";

  cin.ignore();

  // Begin putting in actual values
  beltName = window.MakeWindow("Please enter a name for this belt: ");
  beltPrimColor = window.MakeWindow("Please enter the primary color for " +
                                    beltName + ": ");
  beltSecColor = window.MakeWindow("Please enter the secondary color for " +
                                   beltName + ": ");
  beltTertColor = window.MakeWindow("Please enter the tertiary color for " +
                                    beltName + ": ");
  beltMaterial =
      window.MakeWindow("Please enter the material for " + beltName + ": ");
  beltPattern =
      window.MakeWindow("Please enter the style for " + beltName + ": ");

  do {
    beltID = AssignID("belt");
  } while (beltID == -1);  // AssignID returns -1 if there is an error

  // Create Belt using filled in variables
  Belt belt(beltID, beltName, beltPrimColor, beltSecColor, beltTertColor,
            beltMaterial, beltPattern);

  return belt;
}

/**
 * AssignID
 * @param type A string dictating the type of clothing to check.
 * @return An integer corrosponding to the next available ID for the given
 *         type, or -1 for an error.
 * @brief Assigns unique ID to clothes
 * @detail This function assigns the next available ID number for a given type.
 * The last two numbers represent the number of the given type, while the other
 *    numbers represent the type.  For Example, if there are currently 4
 *    shirts, then the next shirt will have the ID of 105.  The 100 represents
 *    shirts, while the 05 means it is the fifth shirt. This allows for 99
 *    items of a given type and (2^29)-1 types???
 *
 * @note So far the types are hard coded in.  Meaning you can only create
 *            clothes that are either shirts, pants, belts, socks, or shoes.
 *            There is currently no way to dynamically add types.  Underwear
 *            types were intentionally left out to test the best way to
 *            dynamically add new types.
 */
int Closet::AssignID(string type) {
  int id = -1;  // dummy id number
  // switch (type){
  //  case "shirt":
  ///<  @todo Use Switch-case for Closet::AssignID
  if (type == "shirt") {
    id = 100 + static_cast<int>(shirt_map_.size());
  } else if (type == "pants") {
    id = 200 + static_cast<int>(pants_map_.size());
  } else if (type == "belt") {
    id = 300 + static_cast<int>(belt_map_.size());
  } else if (type == "socks") {
    id = 400 + static_cast<int>(socks_map_.size());
  } else if (type == "shoes") {
    id = 500 + static_cast<int>(shoes_map_.size());
  } else {
    type =
        window.MakeWindow("ERROR: Please enter a correct type of clothing: ");
    id = AssignID(type);
  }
  return id;
}
/**
 * StoreCloset
 * @returns XML representation of closet
 */
string Closet::StoreCloset() const {
  string s = "";

  s += "<Closet>\n";
  for (map<int, Shirt>::const_iterator iter = shirt_map_.cbegin();
       iter != shirt_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }

  for (map<int, Pants>::const_iterator iter = pants_map_.cbegin();
       iter != pants_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }

  for (map<int, Socks>::const_iterator iter = socks_map_.cbegin();
       iter != socks_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }

  for (map<int, Shoes>::const_iterator iter = shoes_map_.cbegin();
       iter != shoes_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }

  for (map<int, Belt>::const_iterator iter = belt_map_.cbegin();
       iter != belt_map_.cend(); ++iter) {
    s += iter->second.ToXML();
  }

  s += "</Closet>\n";

  return s;
}

/**
 * ToString
 * @returns 'string' representing the closet
 */
string Closet::ToString() const {
  string s = "";

  s += "\n*********** Shirts ************\n";
  for (map<int, Shirt>::const_iterator iter = shirt_map_.cbegin();
       iter != shirt_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Pants **************\n";
  for (map<int, Pants>::const_iterator iter = pants_map_.cbegin();
       iter != pants_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Socks **************\n";
  for (map<int, Socks>::const_iterator iter = socks_map_.cbegin();
       iter != socks_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Shoes **************\n";
  for (map<int, Shoes>::const_iterator iter = shoes_map_.cbegin();
       iter != shoes_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  s += "\n********** Belts **************\n";
  for (map<int, Belt>::const_iterator iter = belt_map_.cbegin();
       iter != belt_map_.cend(); ++iter) {
    s += iter->second.ToString();
  }

  return s;
}
