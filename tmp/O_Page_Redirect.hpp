#ifndef O_PAGE_REDIRECT
#define O_PAGE_REDIRECT

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_Redirect{
public:

    O_Page_Redirect() {}
    O_Page_Redirect(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Redirect(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Redirect(const I_Page_Redirect& id) 
        : _f_id(id)
        {}


    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<I_Page_Redirect>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Redirect>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _from_url() const { 
        return _f_from_url._base; 
    }
    F_String::Base& _from_url() { 
        _f_from_url._dirty = true; 
        return _f_from_url._base; 
    }
    const F_String::Base& _to_url() const { 
        return _f_to_url._base; 
    }
    F_String::Base& _to_url() { 
        _f_to_url._dirty = true; 
        return _f_to_url._base; 
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
    const F_String::Base& _linking_page_url() const { 
        return _f_linking_page_url._base; 
    }
    F_String::Base& _linking_page_url() { 
        _f_linking_page_url._dirty = true; 
        return _f_linking_page_url._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_from_url._dirty)
            field2Val["from_url"] = 
                toSQLString(_f_from_url._base);
        if (_f_to_url._dirty)
            field2Val["to_url"] = 
                toSQLString(_f_to_url._base);
        if (_f_anchor._dirty)
            field2Val["anchor"] = 
                toSQLString(_f_anchor._base);
        if (_f_code._dirty)
            field2Val["code"] = 
                toSQLString(_f_code._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_linking_page_url._dirty)
            field2Val["linking_page_url"] = 
                toSQLString(_f_linking_page_url._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("redirects", 
                                       field2Val, where))
        {
            _f_page_id._dirty = false;
            _f_id._dirty = false;
            _f_from_url._dirty = false;
            _f_to_url._dirty = false;
            _f_anchor._dirty = false;
            _f_code._dirty = false;
            _f_account_id._dirty = false;
            _f_linking_page_url._dirty = false;
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
        if (_f_from_url._dirty)
            field2Val["from_url"] = 
                toSQLString(_f_from_url._base);
        if (_f_to_url._dirty)
            field2Val["to_url"] = 
                toSQLString(_f_to_url._base);
        if (_f_anchor._dirty)
            field2Val["anchor"] = 
                toSQLString(_f_anchor._base);
        if (_f_code._dirty)
            field2Val["code"] = 
                toSQLString(_f_code._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_linking_page_url._dirty)
            field2Val["linking_page_url"] = 
                toSQLString(_f_linking_page_url._base);
        
        if (DBFace::instance()->
                insert("redirects", field2Val,
                       _f_id._base.serialization()))
        {
            _f_page_id._dirty = false;
            _f_id._dirty = false;
            _f_from_url._dirty = false;
            _f_to_url._dirty = false;
            _f_anchor._dirty = false;
            _f_code._dirty = false;
            _f_account_id._dirty = false;
            _f_linking_page_url._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_page_id> _f_page_id;
    Field<I_Page_Redirect> _f_id;
    F_String _f_from_url;
    F_String _f_to_url;
    F_Text _f_anchor;
    F_Integer _f_code;
    Field<I_account_id> _f_account_id;
    F_String _f_linking_page_url;

    friend class T_Page_Redirect;
};

} //namespace DMMM
#endif //O_PAGE_REDIRECT
