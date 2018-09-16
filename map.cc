/**
 * @class Map
 * @author Stephen M. Reaves
 * @file map.cc
 * @date Aug 05, 2018
 * @brief
 */

//#include "backend.h"
#include "map.h"
#include "clothes.h"

using namespace std;

/**
 * Default Constructor
 */
Map::Map() {}

/**
 * Deconstructor
 */
Map::~Map() {}

/**
 * Init
 * @returns Boolean representing success (or failure) of initialization
 */
bool Map::Init() {
  isInit_ = false;

  // Do stuff here

  isInit_ = true;

  return isInit_;
}

/**
 * Die
 */
void Map::Die() {}

/**
 * Insert
 * @returns true if insert was successful, false otherwise
 * @brief Inserts clothing into correct map according to clothing ID
 */
bool Map::Insert(int id = kDummyID, string name = kDummyName,
                 string primary_color = kDummyPrimColor,
                 string secondary_color = kDummySecColor,
                 string tertiary_color = kDummyTertColor,
                 string pattern = kDummyPattern,
                 string material = kDummyMaterial, string style = kDummyStyle,
                 string length = kDummyLength, string cut = kDummyCut,
                 string sleeve_length = kDummySleeveLength,
                 string collar = kDummyCollar) {
  int status = false;

  // id tells us Clothes type
  switch (id / 100) {
    // Shirt
    case 1:
      Shirt shirt(id, name, primary_color, secondary_color, tertiary_color,
                  pattern, sleevelength, collar);
      shirt_map_.insert(pair<int, Shirt>(shirt.GetID(), shirt));
      status = true;
      break;

    // Pants
    case 2:
      Pants pants(id, name, primary_color, secondary_color, tertiary_color,
                  material, length, cut);
      pants_map_.insert(pair<int, Pants>(pants.GetID(), pants));
      status = true;
      break;

    // Belt
    case 3:
      Belt belt(id, name, primary_color, secondary_color, tertiary_color,
                material, pattern);
      belt_map_.insert(pair<int, Belt>(belt.GetID(), belt));
      status = true;
      break;

    // Socks
    case 4:
      Socks socks(id, name, primary_color, secondary_color, tertiary_color,
                  pattern);
      socks_map_.insert(pair<int, Socks>(socks.GetID(), socks));
      status = true;
      break;

    // Shoes
    case 5:
      Shoes shoes(id, name, primary_color, secondary_color, tertiary_color,
                  material, style);
      shoes_map_.insert(pair<int, Shoes>(shoes.GetID(), shoes);
      status = true;
      break;

    // Other
    default :
      cerr << "Please Enter Appropiate ID" << endl;
      break;
  }

  return status;
}

/**
 * GetClosetName
 * @returns Closet Name
 */
string Map::GetClosetName() { return this.closet_name_; }

/**
 * ToString
 * @returns 'string' representing the closet
 */
string Map::ToString() const {
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
