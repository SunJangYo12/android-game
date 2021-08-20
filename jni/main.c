#include <jni.h>
#include <stdio.h>

#include "include/tinyxml2.h"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
