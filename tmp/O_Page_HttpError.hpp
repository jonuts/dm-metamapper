#ifndef O_PAGE_HTTPERROR
#define O_PAGE_HTTPERROR

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_HttpError{
public:

    O_Page_HttpError() {}
    O_Page_HttpError(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_HttpError(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_HttpError(const I_Page_HttpError& id) 
        : _f_id(id)
        {}


    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<I_Page_HttpError>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_HttpError>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _linked_url() const { 
        return _f_linked_url._base; 
    }
    F_String::Base& _linked_url() { 
        _f_linked_url._dirty = true; 
        return _f_linked_url._base; 
    }
    const F_Text::Base& _anchor() const { 
        return _f_anchor._base; 
    }
    F_Text::Base& _anchor() { 
        _f_anchor._dirty = true; 
        return _f_anchor._base; 
    }
    const F_Integer::Base& _code() const { 
        return _f_code._base; 
    }
    F_Integer::Base& _code() { 
        _f_code._dirty = true; 
        return _f_code._base; 
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
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_linked_url._dirty)
            field2Val["linked_url"] = 
                toSQLString(_f_linked_url._base);
        if (_f_anchor._dirty)
            field2Val["anchor"] = 
                toSQLString(_f_anchor._base);
        if (_f_code._dirty)
            field2Val["code"] = 
                toSQLString(_f_code._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("http_errors", 
                                       field2Val, where))
        {
            _f_page_id._dirty = false;
            _f_id._dirty = false;
            _f_linked_url._dirty = false;
            _f_anchor._dirty = false;
            _f_code._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_linked_url._dirty)
            field2Val["linked_url"] = 
                toSQLString(_f_linked_url._base);
        if (_f_anchor._dirty)
            field2Val["anchor"] = 
                toSQLString(_f_anchor._base);
        if (_f_code._dirty)
            field2Val["code"] = 
                toSQLString(_f_code._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("http_errors", field2Val,
                       _f_id._base.serialization()))
        {
            _f_page_id._dirty = false;
            _f_id._dirty = false;
            _f_linked_url._dirty = false;
            _f_anchor._dirty = false;
            _f_code._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_page_id> _f_page_id;
    Field<I_Page_HttpError> _f_id;
    F_String _f_linked_url;
    F_Text _f_anchor;
    F_Integer _f_code;
    Field<I_account_id> _f_account_id;

    friend class T_Page_HttpError;
};

} //namespace DMMM
#endif //O_PAGE_HTTPERROR
