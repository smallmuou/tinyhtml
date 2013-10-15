/*
Author: xuwf
History:
    2013-10-14 create.

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#ifndef _TI_HTML_ELEMENT_H_
#define _TI_HTML_ELEMENT_H_

const int TIHTML_MAJOR_VERSION = 0;
const int TIHTML_MINOR_VERSION = 1;
const int TIHTML_PATCH_VERSION = 0;

class TiHtmlResult;

class TiHtmlElement {
public:
    TiHtmlElement( void* internal );
    TiHtmlElement( TiHtmlElement* element );
    const char* Attribute( const char* name ) const;
    const char* GetText() const;

    /*
     * Query
     * -Support # and . same as jQuery;
     *  like:
     *  "album" that search "<album..." (Note: direct child only)
     *  "#album" that search "id=album"
     *  ".album" that search "class=album"
     *
     * -Support Multi-level use '/'
     *  like:
     *  "album/song" that search "<album ...><song>...</song></album>"
     */
    TiHtmlResult* Query( const char* query );

    void* internal;
};

class TiHtmlResult {
public:
    TiHtmlResult();
    virtual ~TiHtmlResult();

    int Count();
    TiHtmlElement* Element(int index);

    bool Append( TiHtmlElement* element );
    bool Append( TiHtmlResult* result );
    void Clear();
private:
    TiHtmlElement** elements;
    int capacity;
    int count;
};

class TiHtmlDocument {
public:
	TiHtmlDocument();
    virtual ~TiHtmlDocument();

    bool ParseURL( const char * url );
    bool ParseData( const char * data );

    /*
     * Query
     * -Support # and . same as jQuery;
     *  like:
     *  "album" that search "<album..." (Note: direct child only)
     *  "#album" that search "id=album"
     *  ".album" that search "class=album"
     *
     * -Support Multi-level use '/'
     *  like:
     *  "album/song" that search "<album ...><song>...</song></album>"
     */

    TiHtmlResult* Query( const char* query );
private:
    void* internal;
};


#endif

