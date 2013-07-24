#ifndef O_MIRRORPAGE
#define O_MIRRORPAGE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumMirrorPageSOURCE { MIRRORPAGE_SOURCE_SEARCH_ENGINE = 1, MIRRORPAGE_SOURCE_BACKLINKS = 2, MIRRORPAGE_SOURCE_GOOGLE_ANALYTICS = 3, MIRRORPAGE_SOURCE_USER = 4 };


namespace DMMM {

class O_MirrorPage{
public:

    O_MirrorPage() {}
    O_MirrorPage(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_MirrorPage(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}
    O_MirrorPage(const I_SearchKeyword& parent_id) 
        : _f_search_keyword_id(parent_id)
        {}

O_MirrorPage(const I_MirrorPage& id) 
        : _f_id(id)
        {}


    const Field<I_MirrorPage>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_MirrorPage>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_String::Base& _url() const { 
        return _f_url._base; 
    }
    F_String::Base& _url() { 
        _f_url._dirty = true; 
        return _f_url._base; 
    }
    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<I_search_keyword_id>::Base& _search_keyword_id() const { 
        return _f_search_keyword_id._base; 
    }
    Field<I_search_keyword_id>::Base& _search_keyword_id() { 
        _f_search_keyword_id._dirty = true; 
        return _f_search_keyword_id._base; 
    }
    const Field<EnumMirrorPageSOURCE>::Base& _source() const { 
        return _f_source._base; 
    }
    Field<EnumMirrorPageSOURCE>::Base& _source() { 
        _f_source._dirty = true; 
        return _f_source._base; 
    }
    const F_Integer::Base& _score() const { 
        return _f_score._base; 
    }
    F_Integer::Base& _score() { 
        _f_score._dirty = true; 
        return _f_score._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_source._dirty)
            field2Val["source"] = 
                toSQLString(_f_source._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("mirror_pages", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_account_id._dirty = false;
            _f_url._dirty = false;
            _f_page_id._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_source._dirty = false;
            _f_score._dirty = false;
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
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_source._dirty)
            field2Val["source"] = 
                toSQLString(_f_source._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        
        if (DBFace::instance()->
                insert("mirror_pages", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_account_id._dirty = false;
            _f_url._dirty = false;
            _f_page_id._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_source._dirty = false;
            _f_score._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_MirrorPage> _f_id;
    Field<I_account_id> _f_account_id;
    F_String _f_url;
    Field<I_page_id> _f_page_id;
    Field<I_search_keyword_id> _f_search_keyword_id;
    Field<EnumMirrorPageSOURCE> _f_source;
    F_Integer _f_score;

    friend class T_MirrorPage;
};

} //namespace DMMM
#endif //O_MIRRORPAGE
