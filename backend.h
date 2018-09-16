/**
 * @class Backend
 * @author Stephen M. Reaves
 * @headerfile backend.h
 * @date Jul 30, 2018
 */


#include <cstdlib>
#include <iostream>
#include <string>

#include "belt.h"
//#include "map.h"
#include "pants.h"
#include "shirt.h"
#include "shoes.h"
#include "socks.h"
#include "label.h"

using namespace std;

#ifndef BACKEND_H
#define BACKEND_H

//class Map;

class Backend {
 public:
  // Define these with empty braces to not inherit
  Backend(){};
  virtual ~Backend(){};

  // These abstract functions will be different for each type of backend
  virtual bool Init() = 0;
  virtual void Die() = 0;
  virtual bool Store(string file = kDummyFileName) const = 0;
  virtual bool Open(string file = kDummyFileName) const = 0;
  virtual int AssignID(string type) = 0;
  virtual void MakeCloset() = 0;
  virtual string GetClosetName() = 0;
  virtual string ToString() const = 0;
  static Backend* Create();

 protected:
  bool isInit_ = false;
  string closet_name_ = kDummyClosetName;
};

class Map : Backend;

Backend* Backend::Create() {
#ifdef SQL
  //SQL* backend;
#else
  Map* backend;
  //return &backend;
  return backend;
  //return new Backend;
#endif
  //return backend;
  }

#endif /* BACKEND_H */
