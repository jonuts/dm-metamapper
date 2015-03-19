#ifndef O_PAGE_IMAGE
#define O_PAGE_IMAGE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_Image{
public:

    O_Page_Image() {}
    O_Page_Image(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Image(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Image(const I_Page_Image& id) 
        : _f_id(id)
        {}


    const Field<I_Page_Image>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Image>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _title() const { 
        return _f_title._base; 
    }
    F_String::Base& _title() { 
        _f_title._dirty = true; 
        return _f_title._base; 
    }
    const F_String::Base& _src() const { 
        return _f_src._base; 
    }
    F_String::Base& _src() { 
        _f_src._dirty = true; 
        return _f_src._base; 
    }
    const F_String::Base& _alt() const { 
        return _f_alt._base; 
    }
    F_String::Base& _alt() { 
        _f_alt._dirty = true; 
        return _f_alt._base; 
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
        if (_f_title._dirty)
            field2Val["title"] = 
                toSQLString(_f_title._base);
        if (_f_src._dirty)
            field2Val["src"] = 
                toSQLString(_f_src._base);
        if (_f_alt._dirty)
            field2Val["alt"] = 
                toSQLString(_f_alt._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("images", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_title._dirty = false;
            _f_src._dirty = false;
            _f_alt._dirty = false;
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
        if (_f_title._dirty)
            field2Val["title"] = 
                toSQLString(_f_title._base);
        if (_f_src._dirty)
            field2Val["src"] = 
                toSQLString(_f_src._base);
        if (_f_alt._dirty)
            field2Val["alt"] = 
                toSQLString(_f_alt._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("images", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_title._dirty = false;
            _f_src._dirty = false;
            _f_alt._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_Image> _f_id;
    F_String _f_title;
    F_String _f_src;
    F_String _f_alt;
    Field<I_page_id> _f_page_id;
    Field<I_account_id> _f_account_id;

    friend class T_Page_Image;
};

} //namespace DMMM
#endif //O_PAGE_IMAGE
