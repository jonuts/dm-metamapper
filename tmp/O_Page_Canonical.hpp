#ifndef O_PAGE_CANONICAL
#define O_PAGE_CANONICAL

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_Canonical{
public:

    O_Page_Canonical() {}
    O_Page_Canonical(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Canonical(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Canonical(const I_Page_Canonical& id) 
        : _f_id(id)
        {}


    const Field<I_Page_Canonical>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Canonical>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _url() const { 
        return _f_url._base; 
    }
    F_String::Base& _url() { 
        _f_url._dirty = true; 
        return _f_url._base; 
    }
    const F_String::Base& _canonical_url() const { 
        return _f_canonical_url._base; 
    }
    F_String::Base& _canonical_url() { 
        _f_canonical_url._dirty = true; 
        return _f_canonical_url._base; 
    }
    const F_Integer::Base& _canonical_tag() const { 
        return _f_canonical_tag._base; 
    }
    F_Integer::Base& _canonical_tag() { 
        _f_canonical_tag._dirty = true; 
        return _f_canonical_tag._base; 
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
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_canonical_url._dirty)
            field2Val["canonical_url"] = 
                toSQLString(_f_canonical_url._base);
        if (_f_canonical_tag._dirty)
            field2Val["canonical_tag"] = 
                toSQLString(_f_canonical_tag._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("canonicals", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_canonical_url._dirty = false;
            _f_canonical_tag._dirty = false;
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
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_canonical_url._dirty)
            field2Val["canonical_url"] = 
                toSQLString(_f_canonical_url._base);
        if (_f_canonical_tag._dirty)
            field2Val["canonical_tag"] = 
                toSQLString(_f_canonical_tag._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("canonicals", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_canonical_url._dirty = false;
            _f_canonical_tag._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_Canonical> _f_id;
    F_String _f_url;
    F_String _f_canonical_url;
    F_Integer _f_canonical_tag;
    Field<I_page_id> _f_page_id;
    Field<I_account_id> _f_account_id;

    friend class T_Page_Canonical;
};

} //namespace DMMM
#endif //O_PAGE_CANONICAL
