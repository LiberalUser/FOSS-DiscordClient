#include "discord_api.h"
#include <curl/curl.h>
#include <string>

std::string getDiscordUser(const std::string& token) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bot " + token).c_str());
        curl_easy_setopt(curl, CURLOPT_URL, "https://discord.com/api/v10/users/@me");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
            +[](char* ptr, size_t size, size_t nmemb, std::string* data) {
                data->append(ptr, size * nmemb);
                return size * nmemb;
            });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return response;
}
