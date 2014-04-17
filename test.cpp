#include <stdio.h>
#include <curl/curl.h>
#include <fstream>
#include <curl/easy.h>
#include <string>
#include "json/json.h"


class Jsonowanie
{
private:
  std::ifstream file;
  Json::Reader reader;
  CURL *curl;
  FILE *fp;
  CURLcode res;
  std::string url;
public:
  void downloadjson(std::string a);
  Json::Value root;
  Json::Value jdata;
  // void pobierzlink(std::string a);
  void parsejson();
  Jsonowanie();



};


size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written;
  written = fwrite(ptr, size, nmemb, stream);
  return written;
}




void Jsonowanie::downloadjson(std::string a)
{
  this->url = a; // "http://api.steampowered.com/ISteamUserStats/GetUserStatsForGame/v0002/?key=5EA2925C71116B95A5CF0E1DB6DD42B8&appid=730&steamid=76561198022618574";
  char outfilename[FILENAME_MAX] = "bbb.json";
  curl = curl_easy_init();
  if(curl)
    {
      fp = fopen(outfilename,"wb");
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
      res = curl_easy_perform(curl);
      /* always cleanup */
      curl_easy_cleanup(curl);
      fclose(fp);
    }


}

void Jsonowanie::parsejson()
{

  this->file.open("bbb.json");
  this->reader.parse(this->file, this->root, false);
  this->jdata =this->root.get("playerstats", 0).get("stats", 0);

  for(unsigned int i=0; i<this->jdata.size(); i++)
    {
      std::cout << this->jdata[i].get("name", 0).asString() << ":\t" << this->jdata[i].get("value", 0).asInt() << std::endl;
      // if(data[i].get("sex",0).asString() == "f")
      // 	cout << data[i].get("name",0).asString() << endl;
    }

    
}

Jsonowanie::Jsonowanie()
{

  downloadjson("http://api.steampowered.com/ISteamUserStats/GetUserStatsForGame/v0002/?key=5EA2925C71116B95A5CF0E1DB6DD42B8&appid=730&steamid=76561198022618574");  


}


int main(void)
{
  Jsonowanie csgo;
  csgo.parsejson();
  return 0;
}
