#ifndef SAT_TRACK_ENGINE_CURL_AGENT_H
#define SAT_TRACK_ENGINE_CURL_AGENT_H

#include <tuple>
#include <string>

namespace SatTrackEngine
{
  std::tuple<int,std::string,std::string> get();
}

#endif //SAT_TRACK_ENGINE_CURL_AGENT_H