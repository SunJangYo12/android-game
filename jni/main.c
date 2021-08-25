#include <jni.h>
#include <stdio.h>
#include "include/tinyxml2.h"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#if (defined __MWERKS__)
#include <SIOUX.h>
#endif

#if (defined PHYSFS_HAVE_READLINE)
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include "include/physfs.h"

#define PHYSFS_DEPRECATED
#define TEST_VERSION_MAJOR  3
#define TEST_VERSION_MINOR  0
#define TEST_VERSION_PATCH  2

using namespace tinyxml2;

const char *aksesTinyXML()
{
   TIXMLASSERT(true);
   static const char* xml =
        "<?xml version=\"1.0\"?>"
        "<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
        "<PLAY>"
        "<TITLE>A Midsummer Night's Dream</TITLE>"
        "</PLAY>";

    XMLDocument doc;
    doc.Parse( xml );

    XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
    const char* title = titleElement->GetText();
    //printf( "Name of play (1): %s\n", title );
    return title;

    /*XMLText* textNode = titleElement->FirstChild()->ToText();
    title = textNode->Value();
    printf( "Name of play (2): %s\n", title );

    return doc.ErrorID();*/
}

int Java_com_game_trigger_MainActivity_call( JNIEnv* env, jobject thiz)
{
    return 7;
}

extern "C" jstring Java_com_game_trigger_MainActivity_callTinyXML( JNIEnv* env, jobject thiz )
{
    return env->NewStringUTF(aksesTinyXML());
}

extern "C" jstring Java_com_game_trigger_MainActivity_callPHYSFS( JNIEnv* env, jobject thiz )
{
    const char *output = NULL;

    if (!PHYSFS_init("libphysfs.so"))
    {
        output = "PHYSFS init error";
    }
    else {
        PHYSFS_permitSymbolicLinks(1);
        output = PHYSFS_getBaseDir();
    }

    return env->NewStringUTF(output);
}
