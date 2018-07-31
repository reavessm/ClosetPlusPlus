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

const string kDummyClosetName = "Fake Closet Name";

class Closet {
 public:
  // Constructors and Destructors
  Closet();
  virtual ~Closet();

  // General Functions
  string ToXML() const;
  string ToString() const;
  string StoreCloset() const;
  void ImportCloset(string filename);
  void MakeCloset();

  string GetClosetName();

 private:
  // Variables
  string closet_name_ = kDummyClosetName;
  map<int, Shirt> shirt_map_;
  map<int, Pants> pants_map_;
  map<int, Socks> socks_map_;
  map<int, Shoes> shoes_map_;
  map<int, Belt> belt_map_;
#ifdef VULKAN
  Vulkan window;
#else
  Ncurses window;
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
