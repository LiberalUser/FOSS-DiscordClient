#include <jni.h>
#include <string>
#include "discord_api.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_discordlite_MainActivity_getDiscordInfo(JNIEnv *env, jobject thiz) {
    std::string token = "YOUR_BOT_TOKEN_HERE";
    std::string info = getDiscordUser(token);
    return env->NewStringUTF(info.c_str());
}
