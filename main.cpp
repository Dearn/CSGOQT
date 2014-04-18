#include "json.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written;
  written = fwrite(ptr, size, nmemb, stream);
  return written;
}


int main(int argc, char **argv)
{
  Jsonowanie csgo;
  csgo.parsejson();
  return 0;
}
