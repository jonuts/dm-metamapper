#ifndef O_PAGE_DUPLICATE
#define O_PAGE_DUPLICATE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumPage_DuplicateTYPE { PAGE_DUPLICATE_TYPE_VARIANT = 1, PAGE_DUPLICATE_TYPE_PARAMS = 2, PAGE_DUPLICATE_TYPE_UNRELATED = 3 };


namespace DMMM {

class O_Page_Duplicate{
public:

    O_Page_Duplicate() {}
    O_Page_Duplicate(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Duplicate(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Duplicate(const I_Page_Duplicate& id) 
        : _f_id(id)
        {}


    const Field<I_Page_Duplicate>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Duplicate>::Base& _id() { 
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
    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<EnumPage_DuplicateTYPE>::Base& _type() const { 
        return _f_type._base; 
    }
    Field<EnumPage_DuplicateTYPE>::Base& _type() { 
        _f_type._dirty = true; 
        return _f_type._base; 
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
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_type._dirty)
            field2Val["type"] = 
                toSQLString(_f_type._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("duplicates", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_page_id._dirty = false;
            _f_type._dirty = false;
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
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_type._dirty)
            field2Val["type"] = 
                toSQLString(_f_type._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("duplicates", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_page_id._dirty = false;
            _f_type._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_Duplicate> _f_id;
    F_String _f_url;
    Field<I_page_id> _f_page_id;
    Field<EnumPage_DuplicateTYPE> _f_type;
    Field<I_account_id> _f_account_id;

    friend class T_Page_Duplicate;
};

} //namespace DMMM
#endif //O_PAGE_DUPLICATE
