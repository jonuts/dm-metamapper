#ifndef O_PAGE_HEADER
#define O_PAGE_HEADER

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_Header{
public:

    O_Page_Header() {}
    O_Page_Header(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Header(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Header(const I_Page_Header& id) 
        : _f_id(id)
        {}


    const Field<I_Page_Header>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Header>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Integer::Base& _h_type() const { 
        return _f_h_type._base; 
    }
    F_Integer::Base& _h_type() { 
        _f_h_type._dirty = true; 
        return _f_h_type._base; 
    }
    const F_String::Base& _text() const { 
        return _f_text._base; 
    }
    F_String::Base& _text() { 
        _f_text._dirty = true; 
        return _f_text._base; 
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
        if (_f_h_type._dirty)
            field2Val["h_type"] = 
                toSQLString(_f_h_type._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("page_headers", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_h_type._dirty = false;
            _f_text._dirty = false;
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
        if (_f_h_type._dirty)
            field2Val["h_type"] = 
                toSQLString(_f_h_type._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("page_headers", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_h_type._dirty = false;
            _f_text._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_Header> _f_id;
    F_Integer _f_h_type;
    F_String _f_text;
    Field<I_page_id> _f_page_id;
    Field<I_account_id> _f_account_id;

    friend class T_Page_Header;
};

} //namespace DMMM
#endif //O_PAGE_HEADER
