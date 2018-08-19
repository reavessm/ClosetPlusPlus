/**
 * @class Frontend
 * @author Stephen M. Reaves
 * @headerfile frontend.h
 * @date Jul 19, 2018
 * @brief Abstract class for User Interfaces
 */

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "backend.h"
#include "belt.h"
#include "pants.h"
#include "shirt.h"
#include "socks.h"
#include "shoes.h"
#include "vulkan.h"
#include "ncurses.h"

using namespace std;

#ifndef FRONTEND_H
#define FRONTEND_H

const string kDummyClosetName = "Fake Closet Name";
const string kClosetPrompt = "Enter a Closet Name: ";
const string kShirtPrompt = "Would you like to add a shirt? [y/n] ";
const string kPantsPrompt = "Would you like to add a pair of pants? [y/n] ";
const string kShoesPrompt = "Would you like to add a pair of shoes? [y/n] ";
const string kSocksPrompt = "Would you like to add a pair of socks? [y/n] ";
const string kBeltPrompt = "Would you like to add a belt? [y/n] ";
const string kShirtNamePrompt = "Please enter the name of the shirt: ";
const string kPantsNamePrompt = "Please enter the name of the pants: ";
const string kSocksNamePrompt = "Please enter the name of the socks: ";
const string kShoesNamePrompt = "Please enter the name of the shoes: ";
const string kBeltNamePrompt = "Please enter the name of the belt: ";
const string kPrimColorPrompt = "Please enter the primary color: ";
const string kSecColorPrompt = "Please enter the secondary color: ";
const string kTertColorPrompt = "Please enter the tertiary color: ";
const string kPatternPrompt = "Please enter the pattern: ";
const string kSleeveLenPrompt = "Please enter the sleeve length: ";
const string kStylePrompt = "Please enter the style: ";
const string kMatPrompt = "Please enter the material: ";
const string kColPrompt = "Please enter the collar type: ";
const string kCutPrompt = "Please enter the cut: ";
const string kLenPrompt = "Please enter the length: ";

class Frontend {
 public:
  // Define these with empty braces to not inherit
  Frontend(){};
  virtual ~Frontend(){};

  // These abstract functions will be different for each type of frontend
  virtual bool Init() = 0; ///< Starts frontend and returns boolean determining if inherited frontend was started correctly
  virtual void Die() = 0; ///< Kills frontend
  virtual char MakeWindowChar(string message) = 0; ///< Puts message in window and returns char
  virtual string MakeWindow(string message) = 0; ///< Puts message in window and returns string
  virtual void CreateCloset() = 0; ///< Initializes Backend
  
  // Static method to handle different types of frontend
#ifdef VULKAN
  static Vulkan Create() { ///< Creates backend and returns instance of Vulkan
    return Vulkan();
  }
#else
  static Ncurses Create() { ///< Creates backend and returns instance of Ncurses
    return Ncurses(); 
  }
#endif

 protected:
  bool is_init_ = false; ///< True if window is started, fasle otherwise
  auto backend_; ///< Instance of backend
  string closet_name_ = kDummyClosetName;
};

#endif /* FRONTEND_H */
