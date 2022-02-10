#include "curl_agent.h"
#include "curl_agent_constants.h"
#include <curl/curl.h>
#include <string>
#include <iostream>

namespace SatTrackEngine
{
    std::size_t writeFunction(void *ptr, std::size_t size, std::size_t nmemb, std::string* data)
    {
        data->append((char*) ptr, size * nmemb);
        return size * nmemb;
    }

    std::tuple<int,std::string,std::string> get()
    {
        int ret = -1;
        std::string header_string;
        std::string response_string;

        //std::cout << "CALL curl_easy_init" << std::endl;
        auto curl = curl_easy_init();
        if (curl)
        {
            ret = 0;

            curl_easy_setopt(curl, CURLOPT_URL, base_url.c_str());
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
            curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
            curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

            char* url;
            long response_code;
            double elapsed;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
            curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

            //std::cout << "CALL curl_easy_perform" << std::endl;
            curl_easy_perform(curl);
            std::cout << "response_code = " << response_code << ", elapsed = " << elapsed << ", url = " << url << std::endl << std::endl;
            curl_easy_cleanup(curl);
            curl = NULL;
        }

        return std::make_tuple(ret, header_string, response_string);
    }
}