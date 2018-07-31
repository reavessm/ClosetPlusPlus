/**
* @class Backend
* @author Stephen M. Reaves
* @headerfile backend.h
* @date Jul 30, 2018
*/

#include <cstdlib>
#include <iostream>
#include <string>

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
  virtual bool Init() = 0;
  virtual void Die() = 0;
  virtual bool Store(string file = k_file_name_)  = 0;
  virtual bool Open(string file = k_file_name_) = 0;

 protected:
  bool isInit_ = false;
};

#endif /* BACKEND_H */
