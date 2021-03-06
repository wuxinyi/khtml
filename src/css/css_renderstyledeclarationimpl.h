/*
 * css_renderstyleimpl.h
 *
 * Copyright 2004  Zack Rusin <zack@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */
#ifndef CSS_RENDERSTYLEIMPL_H
#define CSS_RENDERSTYLEIMPL_H

#include "css/css_valueimpl.h"
#include "dom/dom_string.h"
#include "rendering/render_style.h"

namespace DOM
{
class NodeImpl;
}

namespace khtml
{

// Used by DOM::Counter::listStyle()
DOM::DOMString stringForListStyleType(khtml::EListStyleType type);

class RenderStyleDeclarationImpl : public DOM::CSSStyleDeclarationImpl
{
public:
    RenderStyleDeclarationImpl(DOM::NodeImpl *node);
    virtual ~RenderStyleDeclarationImpl();

    DOM::DOMString cssText() const;
    void setCssText(DOM::DOMString str);

    DOM::CSSValueImpl *getPropertyCSSValue(int propertyID) const override;
    DOM::DOMString getPropertyValue(int propertyID) const override;
    bool getPropertyPriority(int propertyID) const override;
    unsigned long length() const override;

    void removeProperty(int propertyID, DOM::DOMString *old = nullptr) override;
    bool removePropertiesInSet(const int *set, unsigned length) override;
    bool isPropertyImplicit(int /*propertyID*/) const override
    {
        return false;
    }
    bool setProperty(int propertyId, const DOM::DOMString &value, bool important, int &ec) override;
    bool setProperty(int propertyId, const DOM::DOMString &value, bool important = false) override;
    void setProperty(int propertyId, int value, bool important = false) override;
    void setLengthProperty(int id, const DOM::DOMString &value, bool important, bool multiLength = false) override;

    void setProperty(const DOM::DOMString &propertyString) override;
    DOM::DOMString item(unsigned long index) const override;

protected:
    DOM::CSSProperty property(int id) const;

protected:
    SharedPtr<DOM::NodeImpl> m_node;
};

}

#endif
