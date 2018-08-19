/**
* @class Map
* @author Stephen M. Reaves
* @headerfile map.h
* @date Jul 30, 2018
*/

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#ifndef MAP_H
#define MAP_H

const string kDummyClosetName = "Fake Map Name";

class Map {
 public:
  // Constructors and Destructors
  Map();
  virtual ~Map();

 private:
  // Variables
  string closet_name_ = kDummyClosetName;
  map<int, Shirt> shirt_map_;
  map<int, Pants> pants_map_;
  map<int, Socks> socks_map_;
  map<int, Shoes> shoes_map_;
  map<int, Belt> belt_map_;
#ifdef VULKAN
  Vulkan window_;
#else
  Ncurses window_;
#endif

  // Private Functions
  Shirt AddShirt();
  Pants AddPants();
  Socks AddSocks();
  Shoes AddShoes();
  Belt AddBelt();

  int AssignID(string type);
};

#endif /* MAP_H */
