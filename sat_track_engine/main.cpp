#include <iostream>
#include "curl_agent.h"

int main(int argc, char** argv)
{
  if(auto [ret, head, resp] = SatTrackEngine::get(); ret == 0)
  {
    std::cout << "********** HEADER" << std::endl;
    std::cout << head;
    std::cout << "********** RESPONSE" << std::endl;
    std::cout << resp;
    return 0;
  }
  else
  {
    return -1;
  }
}
