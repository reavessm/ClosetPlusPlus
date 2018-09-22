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
  virtual bool Init() = 0;  ///< Starts the storage, returns true if successful
  virtual void Die() = 0;   ///< Kills the storage, doesn't necessarily delete
                            ///< the data
  virtual bool Store(string file = kDummyFileName) const = 0;  ///< Save
                                                               ///< contents to
                                                               ///< file
  virtual bool Open(string file = kDummyFileName) const = 0;  ///< Create Closet
                                                              ///< from file
  virtual void MakeCloset() = 0;        ///< Create Closet from scratch
  virtual string GetClosetName() = 0;   ///< Returns the name of the Closet
  virtual string ToString() const = 0;  ///< Returns the string-ified
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
  // virtual int AssignID(string type) = 0;  ///< Assigns and ID based on the
  // type
  ///< of clothing
  unsigned int num_of_shirts_ = 0;
  unsigned int num_of_pants_ = 0;
  unsigned int num_of_socks_ = 0;
  unsigned int num_of_shoes_ = 0;
  unsigned int num_of_belts_ = 0;
  ///< @todo Find a way to get num of clothes
  int AssignID(Type type) {
    int id = -1;

    switch (type) {
      case Type::Shirt:
        id = 100 + num_of_shirts_;
        break;
      case Type::Pants:
        id = 200 + num_of_pants_;
        break;
      case Type::Belt:
        id = 300 + num_of_belts_;
        break;
      case Type::Socks:
        id = 400 + num_of_socks_;
        break;
      case Type::Shoes:
        id = 500 + num_of_shoes_;
        break;
    }

    return id;
  }
  int AssignID(string type) {  ///< @todo User std::unordered_set<string, Enum>
    int id = -1;

    if (type == "shirt") {
      id = 100 + num_of_shirts_;
    } else if (type == "pants") {
      id = 200 + num_of_pants_;
    } else if (type == "belt") {
      id = 300 + num_of_belts_;
    } else if (type == "socks") {
      id = 400 + num_of_socks_;
    } else if (type == "shoes") {
      id = 500 + num_of_shoes_;
    }

    return id;
  }
};

#endif /* BACKEND_H */
