/*
Copyright (C) 2011 for LGPL 2.1

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/

/*
 * Copyright (C) 2004 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef markup_h
#define markup_h

#include "HTMLInterchange.h"
#include "MappedAttributeEntry.h"
#include <wtf/Forward.h>
#include <wtf/Vector.h>
////////SISO_HTMLCOMPOSER begin
#include "CachedResource.h"
#include "PlatformString.h"

namespace android {
    class WebHTMLMarkupData;
}

////////SISO_HTMLCOMPOSER end
namespace WebCore {

    class Document;
    class DocumentFragment;
    class Node;
    class Range;
    class String;

    enum EChildrenOnly { IncludeNode, ChildrenOnly };

    PassRefPtr<DocumentFragment> createFragmentFromText(Range* context, const String& text);
    PassRefPtr<DocumentFragment> createFragmentFromMarkup(Document*, const String& markup, const String& baseURL, FragmentScriptingPermission = FragmentScriptingAllowed);
    PassRefPtr<DocumentFragment> createFragmentFromNodes(Document*, const Vector<Node*>&);

////////SISO_HTMLCOMPOSER begin
    String createLocalResource(CachedResource* resource, const String& basePath, android::WebHTMLMarkupData* markupData = 0);
    android::WebHTMLMarkupData* createFullMarkup(const Node* node,const String& basePath /* = String()*/);
////////SISO_HTMLCOMPOSER end
		// SAMSUNG CHANGE
	bool saveCachedImageToFile(CachedResource* resource, const String& imageUrl, const String& filePath);

    bool isPlainTextMarkup(Node *node);
    String createMarkup(const Range*, Vector<Node*>* = 0, EAnnotateForInterchange = DoNotAnnotateForInterchange, bool convertBlocksToInlines = false, const String& basePath = String()/*SAMSUNG_HTML_EDIT_EXTENSION*/, android::WebHTMLMarkupData* markupData = 0);
    String createMarkup(const Node*, EChildrenOnly = IncludeNode, Vector<Node*>* = 0, const String& basePath = String()/*SAMSUNG_HTML_EDIT_EXTENSION*/, android::WebHTMLMarkupData* markupData = 0);
    
    String createFullMarkup(const Node*);
    String createFullMarkup(const Range*);


}

#endif // markup_h
