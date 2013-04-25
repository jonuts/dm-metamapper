#ifndef O_MISSINGELEMENT
#define O_MISSINGELEMENT

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumMissingElementELEMENT { MISSINGELEMENT_ELEMENT_BODY = 1, MISSINGELEMENT_ELEMENT_TITLE = 2, MISSINGELEMENT_ELEMENT_H1 = 3, MISSINGELEMENT_ELEMENT_H2 = 4, MISSINGELEMENT_ELEMENT_H3 = 5, MISSINGELEMENT_ELEMENT_META_DESC = 6, MISSINGELEMENT_ELEMENT_META_KWS = 7, MISSINGELEMENT_ELEMENT_URL = 8, MISSINGELEMENT_ELEMENT_BACKLINK = 9 };


namespace DMMM {

class O_MissingElement{
public:

    O_MissingElement() {}
    O_MissingElement(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_MissingElement(const I_PageSearchKeyword& parent_id) 
        : _f_page_search_keyword_id(parent_id)
        {}

O_MissingElement(const I_MissingElement& id) 
        : _f_id(id)
        {}


    const Field<I_MissingElement>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_MissingElement>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const Field<EnumMissingElementELEMENT>::Base& _element() const { 
        return _f_element._base; 
    }
    Field<EnumMissingElementELEMENT>::Base& _element() { 
        _f_element._dirty = true; 
        return _f_element._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const Field<I_page_search_keyword_id>::Base& _page_search_keyword_id() const { 
        return _f_page_search_keyword_id._base; 
    }
    Field<I_page_search_keyword_id>::Base& _page_search_keyword_id() { 
        _f_page_search_keyword_id._dirty = true; 
        return _f_page_search_keyword_id._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_element._dirty)
            field2Val["element"] = 
                toSQLString(_f_element._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_page_search_keyword_id._dirty)
            field2Val["page_search_keyword_id"] = 
                toSQLString(_f_page_search_keyword_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("missing_elements", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_element._dirty = false;
            _f_account_id._dirty = false;
            _f_page_search_keyword_id._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_element._dirty)
            field2Val["element"] = 
                toSQLString(_f_element._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_page_search_keyword_id._dirty)
            field2Val["page_search_keyword_id"] = 
                toSQLString(_f_page_search_keyword_id._base);
        
        if (DBFace::instance()->
                insert("missing_elements", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_element._dirty = false;
            _f_account_id._dirty = false;
            _f_page_search_keyword_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_MissingElement> _f_id;
    Field<EnumMissingElementELEMENT> _f_element;
    Field<I_account_id> _f_account_id;
    Field<I_page_search_keyword_id> _f_page_search_keyword_id;

    friend class T_MissingElement;
};

} //namespace DMMM
#endif //O_MISSINGELEMENT
