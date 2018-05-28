/******************************************************************************
 * File Name: shirt.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Header File for 'Shirt' class in the Closet++ program
 *
 */


#ifndef SHIRT_H
#define SHIRT_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "clothes.h"

using namespace std;


/* Implemented with Interface
const int kDummyShirtID = -1;
const string kDummyShirtName = "Fake Name";
const string kDummyShirtPrimColor = "Fake Primary Color";
const string kDummyShirtSecColor = "Fake Secondary Color";
const string kDummyShirtTertColor = "Fake Tertiary Color";
const string kDummyShirtPattern = "Fake Pattern";
const string kDummyShirtSleeveLength = "Fake Sleeve Length";
const string kDummyShirtCollar = "Fake Collar"; 
*/

class Shirt {
  public:
    //Constructors and Deconstructors
    Shirt();
    Shirt(int id, string name, string prim_color, string sec_color, 
          string tert_color, string pattern, string sleeve_length, 
          string collar);
    virtual ~Shirt();

    //General Functions
/* Implemented with Interface
    int GetID();
    string GetName();
    string GetPrimColor();
    string GetSecColor();
    string GetTertColor();
    string GetPattern();
*/
    string GetSleeveLength() { return sleeve_length_; }
    string GetCollar() { return collar_; }

/* Implemented with Interface
    void SetName(string name);
    void SetPrimColor(string color);
    void SetSecColor(string color);
    void SetTertColor(string color);
    void SetPattern(string pattern);
*/
    void SetSleeveLength(string length) { sleeve_length_ = length; }
    void SetCollar(string collar) { collar_ = collar; }

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables
/* Implemented with Interface
    int id_ = kDummyShirtID;
    string name_ = kDummyShirtName;
    string primary_color_ = kDummyShirtPrimColor;
    string secondary_color_ = kDummyShirtSecColor;
    string tertiary_color_ = kDummyShirtTertColor;
    string pattern_ = kDummyShirtPattern;
*/
    string sleeve_length_ = kDummySleeveLength;
    string collar_ = kDummyCollar;

    //Private Functions


};


#endif /* SHIRT_H */ 
