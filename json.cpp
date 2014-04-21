#include "json.h"


Jsonowanie::~Jsonowanie()
{
  delete fp;
}



bool Jsonowanie::doesFileExist(const std::string& name)
{


  std::ifstream f(name.c_str());
  if (f.good())
    {
      f.close();
      return true;
    }
  else
    {
      f.close();
      return false;
    }   
}

void Jsonowanie::downloadjson(std::string url)
{

  this->url = url; // "http://api.steampowered.com/ISteamUserStats/GetUserStatsForGame/v0002/?key=5EA2925C71116B95A5CF0E1DB6DD42B8&appid=730&steamid=76561198022618574";
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



void Jsonowanie::parsejson(bool test)
{
  if(test)
    this->downloadjson("http://api.steampowered.com/ISteamUserStats/GetUserStatsForGame/v0002/?key=5EA2925C71116B95A5CF0E1DB6DD42B8&appid=730&steamid=76561198022618574");
  this->file.open("bbb.json");
  this->reader.parse(this->file, this->root, false);
  this->jdata =this->root.get("playerstats", 0).get("stats", 0);

  for(unsigned int i=0; i<10;i++) //this->jdata.size(); i++)
    { //same as root.get("playerstats", 0).get("stats", 0).get("name", 0) ...
      std::cout << this->jdata[i].get("name", 0).asString() << ":\t" << this->jdata[i].get("value", 0).asInt() << std::endl;
    }

    
}

Jsonowanie::Jsonowanie()
{

  downloadjson("http://api.steampowered.com/ISteamUserStats/GetUserStatsForGame/v0002/?key=5EA2925C71116B95A5CF0E1DB6DD42B8&appid=730&steamid=76561198022618574");  
}
