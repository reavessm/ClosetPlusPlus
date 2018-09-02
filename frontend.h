/**
 * @class Frontend
 * @author Stephen M. Reaves
 * @headerfile frontend.h
 * @date Jul 19, 2018
 * @brief Abstract class for User Interfaces
 */

#ifndef FRONTEND_H
#define FRONTEND_H

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "backend.h"
#include "belt.h"
#include "ncurses.h"
#include "pants.h"
#include "shirt.h"
#include "shoes.h"
#include "socks.h"
#include "vulkan.h"
#include "label.h"

using namespace std;

class Frontend {
 public:
  // Define these with empty braces to not inherit
  Frontend(){};
  virtual ~Frontend(){};

  // These abstract functions will be different for each type of frontend
  virtual bool Init() = 0;  ///< Starts frontend and returns boolean determining
                            ///< if inherited frontend was started correctly
  virtual void Die() = 0;   ///< Kills frontend
  virtual char MakeWindowChar(
      string message) = 0;  ///< Puts message in window and returns char
  virtual string MakeWindow(
      string message) = 0;  ///< Puts message in window and returns string
  virtual void CreateCloset() = 0;    ///< Initializes Backend
  virtual void ToString() const = 0;  ///< Displays 'string' representing closet

  // Static method to handle different types of frontend
#ifdef VULKAN
  static Frontend* Create() {  ///< Creates backend and returns instance of Vulkan
    Vulkan vulkan;
    return vulkan;
  }
#else
  static Frontend* Create() {  ///< Creates backend and returns instance of Ncurses
    Ncurses ncurses;
    return ncurses;
  }
#endif

 protected:
  bool is_init_ = false;  ///< True if window is started, fasle otherwise
  static Backend* backend_;          ///< Instance of backend
  string closet_name_ = kDummyClosetName;
};

#endif /* FRONTEND_H */
