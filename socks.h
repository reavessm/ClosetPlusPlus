/******************************************************************************
 * File Name: socks.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Socks' class in the Closet++ program
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;

#ifndef SOCKS_H
#define SOCKS_H

/* const int kDummySocksID = -1;
const string kDummySocksName = "Fake Name";
const string kDummySocksPrimColor = "Fake Primary Color";
const string kDummySocksSecColor = "Fake Secondary Color";
const string kDummySocksTertColor = "Fake Tertiary Color";
const string kDummySocksPattern = "Fake Pattern"; */

class Socks : public Clothes {
  public:
    //Constructors and Deconstructors
    Socks();
    Socks(int id, string name, string prim_color, string sec_color, 
          string tert_color, string pattern); 
    virtual ~Socks();

    //General Functions
/* Implemented by Interface    
    int GetID();
    string GetName();
    string GetPrimColor();
    string GetSecColor();
    string GetTertColor();
    string GetPattern();

    void SetName(string name);
    void SetPrimColor(string color);
    void SetSecColor(string color);
    void SetTertColor(string color);
    void SetPattern(string pattern);
*/    

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables
/* Implemented by Interface    
    int id_ = kDummySocksID;
    string name_ = kDummySocksName;
    string primary_color_ = kDummySocksPrimColor;
    string secondary_color_ = kDummySocksSecColor;
    string tertiary_color_ = kDummySocksTertColor;
    string pattern_ = kDummySocksPattern;
*/

    //Private Functions


};


#endif /* SOCKS_H */ 
