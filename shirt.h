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

using namespace std;


const int kDummyShirtID = -1;
const string kDummyShirtName = "Fake Name";
const string kDummyShirtPrimColor = "Fake Primary Color";
const string kDummyShirtSecColor = "Fake Secondary Color";
const string kDummyShirtTertColor = "Fake Tertiary Color";
const string kDummyShirtPattern = "Fake Pattern";
const string kDummyShirtSleeveLength = "Fake Sleeve Length";
const string kDummyShirtCollar = "Fake Collar";

class Shirt {
  public:
    //Constructors and Deconstructors
    Shirt();
    Shirt(int id, string name, string prim_color, string sec_color, 
          string tert_color, string pattern, string sleeve_length, 
          string collar);
    virtual ~Shirt();

    //General Functions
    int GetID();
    string GetName();
    string GetPrimColor();
    string GetSecColor();
    string GetTertColor();
    string GetPattern();
    string GetSleeveLength();
    string GetCollar();

    void SetName(string name);
    void SetPrimColor(string color);
    void SetSecColor(string color);
    void SetTertColor(string color);
    void SetPattern(string pattern);
    void SetSleeveLength(string length);
    void SetCollar(string collar);

    //bool IsDirty();

    string ToXML() const;
    string ToString() const;
  
  private:
    //Variables
    int id_ = kDummyShirtID;
    string name_ = kDummyShirtName;
    string primary_color_ = kDummyShirtPrimColor;
    string secondary_color_ = kDummyShirtSecColor;
    string tertiary_color_ = kDummyShirtTertColor;
    string pattern_ = kDummyShirtPattern;
    string sleeve_length_ = kDummyShirtSleeveLength;
    string collar_ = kDummyShirtCollar;

    //Private Functions


};


#endif /* SHIRT_H */ 
