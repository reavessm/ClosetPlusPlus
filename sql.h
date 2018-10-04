/**
 * @class SQL
 * @author Stephen M. Reaves
 * @headerfile sql.h
 * @date Sep 18, 2018
 */

#ifndef SQL_H
#define SQL_H

#include <sqlite3.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "backend.h"

using namespace std;

class SQL : public Backend {
 public:
  // Constructors and Destructors
  SQL();
  virtual ~SQL();
  bool Init();
  bool Init(string name);
  void Die();
  bool Store(string file = kDummyFileName) const { return true; };
  bool Open(string file = kDummyFileName) const { return true; };
  void MakeCloset(){};
  string GetClosetName() { return closet_name_; };
  string ToString() const { return ""; };
  string ToString();

  // Inserts for each type of clothing
  ///< @todo Refactor?
  bool InsertShirt(string name, string primary_color, string secondary_color,
                   string tertiary_color, string pattern, string sleeve_length,
                   string collar);
  bool InsertPants(string name, string primary_color, string secondary_color,
                   string tertiary_color, string material, string length,
                   string cut);
  bool InsertSocks(string name, string primary_color, string secondary_color,
                   string tertiary_color, string pattern);
  bool InsertShoes(string name, string primary_color, string secondary_color,
                   string tertiary_color, string material, string style);
  bool InsertBelt(string name, string primary_color, string secondary_color,
                  string tertiary_color, string material, string pattern);
  string SelectShirt(int id);
  string SelectPants(int id);
  string SelectSocks(int id);
  string SelectShoes(int id);
  string SelectBelt(int id);
  string SelectAllShirts();
  string SelectAllPants();
  string SelectAllSocks();
  string SelectAllShoes();
  string SelectAllBelts();

 private:
  // Variables
  string closet_name_ = kDummyClosetName;
  sqlite3 *db;  ///< DB connection
  string sql;   ///< Prepared SQL statements
  char *zErrMsg = 0;
  int rc;
  static string myResults;

  // Functions
  // int AssignID(string type);
  static int Callback(void *unused, int count, char **data, char **columns);
  void UpdateNumbers();
};

// Define statics
// int SQL::Callback(void *unused, int count, char **data, char **columns);

#endif /* SQL_H */
