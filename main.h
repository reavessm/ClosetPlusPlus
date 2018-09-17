/**
 * @headerfile main.h
 * @author Stephen M. Reaves
 * @date Sep 16, 2018
 */

#include <ncurses.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#ifdef VULKAN ///< Type of frontend is determined at compile-time
#include "vulkan.h"
#else
#include "ncurses.h"
#endif

using namespace std;

#ifndef MAIN_H
#define MAIN_H

#ifdef VULKAN ///< Type of frontend is determined at compile-time
Vulkan frontend_;
#else
Ncurses frontend_;
#endif

string fileSurname = " Closet.txt";
string cloSurname = " Closet.clo";
string fileFrontName = "Dummy";
string filename = "FakeFileName";
string cloname = "fakeCLoName";
string output = "";

ofstream myFile;
ofstream myClo;

#endif /* MAIN_H */
