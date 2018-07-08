/******************************************************************************
 * File Name: main.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary:
 *
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>

#include "myCloset.h"
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

