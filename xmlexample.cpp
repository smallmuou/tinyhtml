/*
   Example program for TinyHTML.
*/

#include "tinyhtml.h"
#include <stdio.h>

int main()
{
    TiHtmlDocument doc;
    doc.ParseURL( "test.html" );

    /* Get Album */
    TiHtmlResult* result = doc.Query(".album/ul/li/a");
    if (result) {
        printf("count=%d\n", result->Count());
        for (int ii = 0; ii < result->Count(); ii++) {
            printf("channel:%s, rel:%s\n", result->Element(ii)->GetText(),  result->Element(ii)->Attribute("rel"));
        }
        delete(result);
    }

    return 0;
}
