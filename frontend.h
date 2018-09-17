/**
 * @class Frontend
 * @author Stephen M. Reaves
 * @headerfile frontend.h
 * @date Sep 16, 2018
 * @brief Abstract class for User Interfaces
 */

#ifndef FRONTEND_H
#define FRONTEND_H

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "belt.h"
#include "pants.h"
#include "shirt.h"
#include "shoes.h"
#include "socks.h"

#ifdef SQL
#include "sql.h"
#else
#include "map.h"
#endif

using namespace std;

class Frontend {
 public:
  // Define these with empty braces to not inherit
  Frontend(){};
  virtual ~Frontend(){};

  // These abstract functions will be different for each type of frontend
  virtual bool Init() = 0;  ///< Starts frontend and returns boolean determining
                            ///< if frontend was started correctly
  virtual void Die() = 0;   ///< Kills frontend
  virtual void CreateCloset() = 0;  ///< Initializes Backend
  virtual string MakeWindow(
      string message) = 0;  ///< Puts message in window and returns string
  virtual char MakeWindowChar(
      string message) = 0;  ///< Puts message in window and returns char
  string GetClosetName() { return backend_.GetClosetName(); };
  string ToString() const { return backend_.ToString(); };

 protected:
  bool is_init_ = false;  ///< True if window is started, fasle otherwise
  string closet_name_ = kDummyClosetName;

#ifdef SQL
  SQL backend_;
#else
  Map backend_;
#endif
};

#endif /* FRONTEND_H */
