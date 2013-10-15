tinyhtml
========

Expand tinyxml，support html
Query like jQuery:

+ "album" that search <album...  (Note: direct child only)
+ "#album" that search "id=album"
+ ".album" that search "class=album"
     
Also Support Multi-level use '/'
+ "album/song" that search "<album ...><song>...</song></album>"

Usage
--------
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
