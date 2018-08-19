/**
* @class Backend
* @author Stephen M. Reaves
* @headerfile backend.h
* @date Jul 30, 2018
*/

#include <cstdlib>
#include <iostream>
#include <string>

#include "map.h"
#include "belt.h"
#include "pants.h"
#include "shirt.h"
#include "socks.h"
#include "shoes.h"

using namespace std;

#ifndef BACKEND_H
#define BACKEND_H

const string kDummyFileName = "NOT_A_FILE_NAME";
const string kDummyClosetName = "Dummy Closet";

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
#ifdef SQL
  static SQL Create() { ///< Creates instance of SQL
    cerr << "Please implement SQLite3 Backend" << endl;
    exit 1;
  }
#else
  static Map Create() { ///< Returns instance of Map
    return Map();
  }
#endif

 protected:
  bool isInit_ = false;
  string closet_name_ = kDummyClosetName;
};

#endif /* BACKEND_H */
