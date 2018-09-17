/**
 * @class Backend
 * @author Stephen M. Reaves
 * @headerfile backend.h
 * @date Sep 16, 2018
 * @brief Abstract class for backend storage
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "belt.h"
#include "pants.h"
#include "shirt.h"
#include "shoes.h"
#include "socks.h"

using namespace std;

#ifndef BACKEND_H
#define BACKEND_H

class Backend {
 public:
  // Define these with empty braces to not inherit
  Backend(){};
  virtual ~Backend(){};

  // These abstract functions will be different for each type of backend
  virtual bool Init() = 0; ///< Starts the storage, returns true if successful
  virtual void Die() = 0; ///< Kills the storage, doesn't necessarily delete
                          ///< the data
  virtual bool Store(string file = kDummyFileName) const = 0; ///< Save
                                                              ///< contents to
                                                              ///< file
  virtual bool Open(string file = kDummyFileName) const = 0; ///< Create Closet
                                                             ///< from file
  virtual void MakeCloset() = 0; ///< Create Closet from scratch
  virtual string GetClosetName() = 0; ///< Returns the name of the Closet
  virtual string ToString() const = 0; ///< Returns the string-ified
                                       ///< represenation of the Closet
  void SetClosetName(string name = kDummyClosetName) { closet_name_ = name; }
  virtual bool InsertShirt(string name, string primary_color,
                           string secondary_color, string tertiary_color,
                           string pattern, string sleeve_length,
                           string collar) = 0;
  virtual bool InsertPants(string name, string primary_color,
                           string secondary_color, string tertiary_color,
                           string material, string length, string cut) = 0;
  virtual bool InsertSocks(string name, string primary_color,
                           string secondary_color, string tertiary_color,
                           string pattern) = 0;
  virtual bool InsertShoes(string name, string primary_color,
                           string secondary_color, string tertiary_color,
                           string material, string style) = 0;
  virtual bool InsertBelt(string name, string primary_color,
                          string secondary_color, string tertiary_color,
                          string material, string pattern) = 0;

 protected:
  bool isInit_ = false;
  string closet_name_ = kDummyClosetName;
  virtual int AssignID(string type) = 0; ///< Assigns and ID based on the type
                                         ///< of clothing
};

#endif /* BACKEND_H */
