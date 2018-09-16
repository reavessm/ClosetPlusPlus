/**
 * @class Map
 * @author Stephen M. Reaves
 * @file map.cc
 * @date Aug 05, 2018
 * @brief
 */

#include "map.h"

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
 * InsertShirt
 * @returns true if insert was succesful, false otherwise
 * @brief Inserts 'Shirt' into 'shirt_map_'
 */
bool Map::InsertShirt(string name, string primary_color, string secondary_color,
                      string tertiary_color, string pattern,
                      string sleeve_length, string collar) {
  int status = false;
  int id = -1;

  do {
    id = this->AssignID("shirt");
  } while (id == -1);  // This should never happen

  Shirt shirt(id, name, primary_color, secondary_color, tertiary_color, pattern,
              sleeve_length, collar);

  shirt_map_.insert(pair<int, Shirt>(id, shirt));

  status = true;

  return status;
}

/**
 * InsertPants
 * @returns true if insert was successful, false otherwise
 * @brief Inserts 'Pants' into 'pants_map_'
 */
bool Map::InsertPants(string name, string primary_color, string secondary_color,
                      string tertiary_color, string material, string length,
                      string cut) {
  int status = false;
  int id = -1;

  do {
    id = this->AssignID("pants");
  } while (id == -1);  // This should never happen

  Pants pants(id, name, primary_color, secondary_color, tertiary_color,
              material, length, cut);

  pants_map_.insert(pair<int, Pants>(id, pants));

  status = true;

  return status;
}

bool Map::InsertSocks(string name, string primary_color, string secondary_color,
                      string tertiary_color, string pattern) {
  int status = false;
  int id = -1;

  do {
    id = this->AssignID("socks");
  } while (id == -1);  // This should never happen

  Socks socks(id, name, primary_color, secondary_color, tertiary_color,
              pattern);

  socks_map_.insert(pair<int, Socks>(id, socks));

  status = true;

  return status;
}

bool Map::InsertShoes(string name, string primary_color, string secondary_color,
                      string tertiary_color, string material, string style) {
  int status = false;
  int id = -1;

  do {
    id = this->AssignID("shoes");
  } while (id == -1);  // This should never happen

  Shoes shoes(id, name, primary_color, secondary_color, tertiary_color,
              material, style);

  shoes_map_.insert(pair<int, Shoes>(id, shoes));

  status = !status;

  return status;
}

bool Map::InsertBelt(string name, string primary_color, string secondary_color,
                     string tertiary_color, string material, string pattern) {
  int status = false;
  int id = -1;

  do {
    id = this->AssignID("belt");
  } while (id == -1);  // if this happens i will dye

  Belt belt(id, name, primary_color, secondary_color, tertiary_color, material,
            pattern);

  belt_map_.insert(pair<int, Belt>(id, belt));

  status = true;

  return status;
}

/**
 * GetClosetName
 * @returns Closet Name
 */
string Map::GetClosetName() { return this->closet_name_; }

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

/**
 * AssignID
 * @param type A string dictating the type of clothing to check.
 * @return An integer corrosponding to the next available ID for the given
 * type, or -1 for an error.
 * @brief Assigns unique ID to clothes
 * @detail This function assigns the next available ID number for a given
 * type.
 * The last two numbers represent the number of the given type, while the
 * other
 * numbers represent the type.  For Example, if there are currently 4
 * shirts, then the next shirt will have the ID of 105.  The 100
 * represents
 * shirts, while the 05 means it is the fifth shirt. This allows
 * for 99
 * items of a given type and (2^29)-1 types???
 *
 * @note So far the types are hard coded in.  Meaning you can only
 * create
 * clothes that are either shirts, pants, belts, socks,
 * or shoes.
 * There is currently no way to dynamically add types.
 * Underwear
 * types were intentionally left out to test the best
 * way to
 * dynamically add new types.
 */
int Map::AssignID(string type) {
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
  }

  return id;
}
