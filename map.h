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
#include "backend.h"

using namespace std;

#ifndef MAP_H
#define MAP_H

class Map : public Backend {
 public:
  // Constructors and Destructors
  Map();
  virtual ~Map();
  bool Init();
  void Die();
  bool Store(string file = kDummyFileName) const { return true; };
  bool Open(string file = kDummyFileName) const { return true; };
  void MakeCloset(){};
  string GetClosetName();
  string ToString() const;

  // Inserts for each type of clothing
  // @todo Refactor?
  bool InsertShirt(string name, string primary_color, string secondary_color,
                   string tertiary_color, string pattern, string sleeve_length,
                   string collar);
  bool InsertPants(string name, string primary_color, string secondary_color,
                   string tertiary_color, string material, string length,
                   string cut);
  bool InsertSocks(string name, string primary_color, string secondary_color,
                   string tertiary_color, string pattern);
  bool InsertShoes(string name, string primary_color, string secondary_color,
                   string tertiary_color, string material, string style);
  bool InsertBelt(string name, string primary_color, string secondary_color,
                  string tertiary_color, string material, string pattern);

 private:
  // Variables
  string closet_name_ = kDummyClosetName;
  int AssignID(string type);
  map<int, Shirt> shirt_map_;
  map<int, Pants> pants_map_;
  map<int, Socks> socks_map_;
  map<int, Shoes> shoes_map_;
  map<int, Belt> belt_map_;
  /* #ifdef VULKAN */
  /*   Vulkan window_; */
  /* #else */
  /*   Ncurses window_; */
  /* #endif */

  // Private Functions
  Shirt AddShirt();
  Pants AddPants();
  Socks AddSocks();
  Shoes AddShoes();
  Belt AddBelt();
};

#endif /* MAP_H */
