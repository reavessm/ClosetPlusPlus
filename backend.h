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

string k_file_name_ = "NOT_A_FILE_NAME";

class Backend {
 public:
  // Define these with empty braces to not inherit
  Backend(){};
  virtual ~Backend(){};

  // These abstract functions will be different for each type of backend
  virtual bool Init() = 0; ///< Sets up instance of backend and returns true on success, false otherwise
  virtual void Die() = 0; ///< Kills instance of backend
  virtual bool Store(string file = k_file_name_)  = 0; ///< Save Closet to file
  virtual bool Open(string file = k_file_name_) = 0; ///< Opens Closet from file
  //virtual bool CreateCloset() = 0; ///< Creates instance of Closet
  virtual int AssignID(string type) = 0;
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
  Closet closet_;
};

#endif /* BACKEND_H */
