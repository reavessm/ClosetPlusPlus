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

#include "myCloset.h"
#include "frontend.h"
#include "backend.h"
#include "ncurses.h"
#include "vulkan.h"
#include "window.h"

using namespace std;

#ifndef MAIN_H
#define MAIN_H

#ifdef VULKAN
string window_type_ = "vulkan";
#else
string window_type_ = "ncurses";
#endif

#endif /* MAIN_H */
