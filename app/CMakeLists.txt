cmake_minimum_required(VERSION 3.4.1)

add_library(native-lib SHARED
            src/main/cpp/main.cpp
            src/main/cpp/discord_api.cpp)

find_library(log-lib log)
find_library(curl-lib curl)

target_link_libraries(native-lib ${log-lib} ${curl-lib})
