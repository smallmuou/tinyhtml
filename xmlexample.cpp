/*
   Example program for TinyHTML2
*/

#include "tinyhtml2.h"
#include <stdio.h>

int main()
{
    tinyhtml2::HTMLDocument doc;
    doc.ParseURL( "test.html" );

    /* Get Album */
    tinyhtml2::HTMLResult* result = doc.Query(".album/ul/li/a");
    if (result) {
        printf("count=%d\n", result->Count());
        for (int ii = 0; ii < result->Count(); ii++) {
            printf("channel:%s, rel:%s\n", result->Element(ii)->GetText(),  result->Element(ii)->Attribute("rel"));
        }
        delete(result);
    }

    return 0;
}
