#include <stdio.h>
#include <curl/curl.h>
#include <fstream>
#include <curl/easy.h>
#include <string>
#include "json/json.h"
#include <sstream>

extern size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

class Jsonowanie
{

private:
  std::ifstream file;
  Json::Reader reader;
  CURL *curl;
  FILE *fp;
  CURLcode res;
  std::string url;
  bool doesFileExist(const std::string& name);


public:
  void downloadjson(std::string a);
  Json::Value root;
  Json::Value jdata;
  // void pobierzlink(std::string a);
  void parsejson(bool);
  Jsonowanie();
  ~Jsonowanie();

};
