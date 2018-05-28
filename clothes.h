/******************************************************************************
 * File Name: clothes.h
 * Created by: Stephen M. Reaves
 * Date Last Modified:
 *
 * Summary: Clothes abstract class to be used by members of closet.
 *          Handles the light work.
 *
 */


#ifndef CLOTHES_H
#define CLOTHES_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

static const int kDummyID = -1;
static const string kDummyName = "Fake Name";
static const string kDummyPrimColor = "Fake Primary Color";
static const string kDummySecColor = "Fake Secondary Color";
static const string kDummyTertColor = "Fake Tertiary Color";
static const string kDummyPattern = "Fake Pattern";
static const string kDummyMaterial = "Fake Material";
static const string kDummyStyle = "Fake Style";
static const string kDummyLength = "Fake Length";
static const string kDummyCut = "Fake Cut";
static const string kDummySleeveLength = "Fake Sleeve Length";
static const string kDummyCollar = "Fake Collar";

class Clothes {
  public:
    //Constructors and Deconstructors
    Clothes();
    virtual ~Clothes();

    //General Functions
    int GetID() { return id_; }
    string GetName() { return name_; }
    string GetPrimColor() { return primary_color_; }
    string GetSecColor() { return secondary_color_; }
    string GetTertColor() { return tertiary_color_; }
    string GetPattern() { return pattern_; }
    string GetMaterial() { return material_; }
    string GetStyle() { return style_; }
    string GetLength() { return length_; }
    string GetCut() { return cut_; }
    string GetSleeveLength() { return sleeve_length_; }
    string GetCollar() { return collar_; }

    void SetName(string name) { name_ = name; }
    void SetPrimColor(string color) { primary_color_ = color; }
    void SetSecColor(string color) { secondary_color_ = color; }
    void SetTertColor(string color) { tertiary_color_ = color; }
    void SetPattern(string pattern) { pattern_ = pattern; }
    void SetMatterial(string material) { material_ = material; }
    void SetStyle(string style) { style_ = style; }
    void SetLength(string length) { length_ = length; }
    void SetCut(string cut) { cut_ = cut; }
    void SetSleeveLength(string length) { sleeve_length_ = length; }
    void SetCollar(string collar) { collar_ = collar; }

 // These are what makes this a purely abstract class.  The implementation of 
 // these will be changed from one article of clothing to the next.
    // virtual bool IsDirty() = 0;
    virtual string ToString() const = 0;

  protected:
    // Set Globals
    int id_ = kDummyID;
    string name_ = kDummyName;
    string primary_color_ = kDummyPrimColor;
    string secondary_color_ = kDummySecColor;
    string tertiary_color_ = kDummyTertColor;
    string pattern_ = kDummyPattern;
    string material_ = kDummyMaterial;
    string style_ = kDummyStyle;
    string length_ = kDummyLength;
    string cut_ = kDummyCut;
    string sleeve_length_ = kDummySleeveLength;
    string collar_ = kDummyCollar;

};


#endif /* CLOTHES_H */ 
