#ifndef O_PAGE_KEYWORD
#define O_PAGE_KEYWORD

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumPage_KeywordPOSITION { PAGE_KEYWORD_POSITION_BODY = 1, PAGE_KEYWORD_POSITION_TITLE = 2, PAGE_KEYWORD_POSITION_H1 = 3, PAGE_KEYWORD_POSITION_H2 = 4, PAGE_KEYWORD_POSITION_H3 = 5, PAGE_KEYWORD_POSITION_META_DESC = 6, PAGE_KEYWORD_POSITION_META_KWS = 7, PAGE_KEYWORD_POSITION_DOMAIN = 8, PAGE_KEYWORD_POSITION_URL = 9, PAGE_KEYWORD_POSITION_BACKLINK = 10, PAGE_KEYWORD_POSITION_OVERALL = 11, PAGE_KEYWORD_POSITION_LINK = 12, PAGE_KEYWORD_POSITION_ALT = 13 };


namespace DMMM {

class O_Page_Keyword{
public:

    O_Page_Keyword() {}
    O_Page_Keyword(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Keyword(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Keyword(const I_Page_Keyword& id) 
        : _f_id(id)
        {}


    const Field<I_Page_Keyword>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Keyword>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Integer::Base& _size() const { 
        return _f_size._base; 
    }
    F_Integer::Base& _size() { 
        _f_size._dirty = true; 
        return _f_size._base; 
    }
    const F_String::Base& _text() const { 
        return _f_text._base; 
    }
    F_String::Base& _text() { 
        _f_text._dirty = true; 
        return _f_text._base; 
    }
    const F_Integer::Base& _frequency() const { 
        return _f_frequency._base; 
    }
    F_Integer::Base& _frequency() { 
        _f_frequency._dirty = true; 
        return _f_frequency._base; 
    }
    const F_Integer::Base& _relevance() const { 
        return _f_relevance._base; 
    }
    F_Integer::Base& _relevance() { 
        _f_relevance._dirty = true; 
        return _f_relevance._base; 
    }
    const Field<EnumPage_KeywordPOSITION>::Base& _position() const { 
        return _f_position._base; 
    }
    Field<EnumPage_KeywordPOSITION>::Base& _position() { 
        _f_position._dirty = true; 
        return _f_position._base; 
    }
    const F_Boolean::Base& _directory() const { 
        return _f_directory._base; 
    }
    F_Boolean::Base& _directory() { 
        _f_directory._dirty = true; 
        return _f_directory._base; 
    }
    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_size._dirty)
            field2Val["size"] = 
                toSQLString(_f_size._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_frequency._dirty)
            field2Val["frequency"] = 
                toSQLString(_f_frequency._base);
        if (_f_relevance._dirty)
            field2Val["relevance"] = 
                toSQLString(_f_relevance._base);
        if (_f_position._dirty)
            field2Val["position"] = 
                toSQLString(_f_position._base);
        if (_f_directory._dirty)
            field2Val["directory"] = 
                toSQLString(_f_directory._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("keywords", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_size._dirty = false;
            _f_text._dirty = false;
            _f_frequency._dirty = false;
            _f_relevance._dirty = false;
            _f_position._dirty = false;
            _f_directory._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
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
        if (_f_size._dirty)
            field2Val["size"] = 
                toSQLString(_f_size._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_frequency._dirty)
            field2Val["frequency"] = 
                toSQLString(_f_frequency._base);
        if (_f_relevance._dirty)
            field2Val["relevance"] = 
                toSQLString(_f_relevance._base);
        if (_f_position._dirty)
            field2Val["position"] = 
                toSQLString(_f_position._base);
        if (_f_directory._dirty)
            field2Val["directory"] = 
                toSQLString(_f_directory._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("keywords", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_size._dirty = false;
            _f_text._dirty = false;
            _f_frequency._dirty = false;
            _f_relevance._dirty = false;
            _f_position._dirty = false;
            _f_directory._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_Keyword> _f_id;
    F_Integer _f_size;
    F_String _f_text;
    F_Integer _f_frequency;
    F_Integer _f_relevance;
    Field<EnumPage_KeywordPOSITION> _f_position;
    F_Boolean _f_directory;
    Field<I_page_id> _f_page_id;
    Field<I_account_id> _f_account_id;

    friend class T_Page_Keyword;
};

} //namespace DMMM
#endif //O_PAGE_KEYWORD
