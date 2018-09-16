/**
 * @headerfile main.h
 * @author Stephen M. Reaves
 * @date July 14th, 2018
 */

#include <ncurses.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

//#include "backend.h"
//#include "frontend.h"
//#include "myCloset.h"
#ifdef VULKAN
#include "vulkan.h"
#else
#include "ncurses.h"
#endif
//#include "window.h"

using namespace std;

#ifndef MAIN_H
#define MAIN_H

#ifdef VULKAN
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
