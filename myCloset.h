/**
 * @class Closet
 * @headerfile myCloset.h
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 */

#include <ncurses.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "belt.h"
#include "ncurses.h"
#include "pants.h"
#include "shirt.h"
#include "shoes.h"
#include "socks.h"
#include "vulkan.h"
#include "window.h"

using namespace std;

#ifndef MYCLOSET_H
#define MYCLOSET_H

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

#endif /* MYCLOSET_H */
