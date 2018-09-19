/**
 * @class sql
 * @author Stephen M. Reaves
 * @file sql.cc
 * @date Sep 17, 2018
 * @brief This class stores clothes using a sqlite3 interface
 */

#include "sql.h"

using namespace std;

/**
 * Default Constructor
 */
SQL::SQL() {}

/**
 * Deconstructor
 */
SQL::~SQL() {}

/**
 * Init
 * @returns Boolean representing success (or failure) of initialization
 */
bool SQL::Init() {
  isInit = false;

  // Create a connection to the db
  rc = sqlite3_open(closet_name_ + ".db", &db);

  // Check if connection failed
  if (!rc) {
    isInit = true;
  }

  // Create Shirt Table
  sql = "CREATE TABLE IF NOT EXISTS Shirts(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "PATTERN         TEXT  NOT NULL,";
  sql += "SLEEVE_LENGTH   TEXT  NOT NULL,";
  sql += "COLLAR          TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Pants Table
  sql = "CREATE TABLE IF NOT EXISTS Pants(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "MATERIAL        TEXT  NOT NULL,";
  sql += "LENGTH          TEXT  NOT NULL,";
  sql += "STYLE           TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Socks Table
  sql = "CREATE TABLE IF NOT EXISTS Socks(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "PATTERN         TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Shoes Table
  sql = "CREATE TABLE IF NOT EXISTS Shoes(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "MATERIAL        TEXT  NOT NULL,";
  sql += "STYLE           TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // Create Belt Table
  sql = "CREATE TABLE IF NOT EXISTS Belt(";
  sql += "ID INT PRIMARY KEY NOT NULL,";
  sql += "NAME            TEXT  NOT NULL,";
  sql += "PRIMARY_COLOR   TEXT  NOT NULL,";
  sql += "SECONDARY_COLOR TEXT  NOT NULL,";
  sql += "TERTIARY_COLOR  TEXT  NOT NULL,";
  sql += "MATERIAL        TEXT  NOT NULL,";
  sql += "PATTERN         TEXT  NOT NULL);";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
    isInit = false;
  }

  // could `return exec1 || exec2 || ..`
  return isInit;
}

/**
 * Die
 */
void SQL::Die() { sqlite3_close(db); }

/**
 * Callback
 * @brief Buffer to replay Select statements
 */
static int SQL::Callback(void *data, int argc, char **argv,
                         char **azColName) {
  for (int i = 0; i < argc; ++i) {
    printf("%s = %s\n", azColName[i], argv[i], ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

/**
 * InsertShirt
 */
bool SQL::InsertShirt(string name, string primary_color, string secondary_color,
                      string tertiary_color, string pattern,
                      string sleeve_length, string collar) {
  isSuccessful = false;

  // Get ID
  int id = this->AssignID("shirt");

  // Prepare Insert statement
  sql = "INSERT INTO Shirt VALUES (";
  sql += id;
  sql += ",'" + name + "',";
  sql += "'" + primary_color + "',";
  sql += "'" + secondary_color + "',";
  sql += "'" + tertiary_color + "',";
  sql += "'" + pattern + "',";
  sql += "'" + sleeve_length + "',";
  sql += "'" + collar + "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertPants
 */
bool SQL::InsertPants(string name, string primary_color, string secondary_color,
                 string tertiary_color, string material, string length,
                 string cut) {
  isSuccessful = false;

  // Get ID
  int id = this->AssignID("pants");

  // Prepare Insert Statement
  sql =  "INSERT INTO Pants VALUES(";
  sql += id;
  sql += ",'" +  name            +  "'";
  sql += "'"  +  primary_color   +  "'";
  sql += "'"  +  secondary_color +  "'";
  sql += "'"  +  tertiary_color  +  "'";
  sql += "'"  +  material        +  "'";
  sql += "'"  +  length          +  "'";
  sql += "'"  +  cut             +  "');";

  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertSocks
 */
bool SQL::InsertSocks(string name, string primary_color, string secondary_color, 
                      string tertiary_color, string pattern) {
  isSuccessful = false;

  // Get ID
  int id = this ->AssignID("socks");

  // Prepare Insert Statement
  sql = "INSERT INTO Socks VALUES(";
  sql += id;
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + pattern + "');";
  
  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertShoes
 */
bool SQL::InsertShoes(string name, string primary_color, string secondary_color, 
                      string tertiary_color, string material, string style) {
  isSuccessful = false;

  // Get ID
  int id = this ->AssignID("shoes");

  // Prepare Insert Statement
  sql = "INSERT INTO Shoes VALUES(";
  sql += id;
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + material + "'";
  sql += "'" + style + "');";
  
  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    isSuccessful = true;
  }

  return isSuccessful;
}

/**
 * InsertBelt
 */
bool SQL::InsertBelt(string name, string primary_color, string secondary_color, 
                     string tertiary_color, string material, string pattern) {
  isSuccessful = false;

  // Get ID
  int id = this ->AssignID("belt");

  // Prepare Insert Statement
  sql = "INSERT INTO Belt VALUES(";
  sql += id;
  sql += ",'" + name + "'";
  sql += "'" + primary_color + "'";
  sql += "'" + secondary_color + "'";
  sql += "'" + tertiary_color + "'";
  sql += "'" + material + "'";
  sql += "'" + pattern + "');";
  
  // Insert and check for errors
  if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK) {
    cerr << "SQL error: " << zErrMsg << endl;
  } else {
    isSuccessful = true;
  }

  return isSuccessful;
}
