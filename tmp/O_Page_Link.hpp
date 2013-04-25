#ifndef O_PAGE_LINK
#define O_PAGE_LINK

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_Link{
public:

    O_Page_Link() {}
    O_Page_Link(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_Link(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_Link(const I_Page_Link& id) 
        : _f_id(id)
        {}


    const Field<I_Page_Link>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_Link>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _text() const { 
        return _f_text._base; 
    }
    F_String::Base& _text() { 
        _f_text._dirty = true; 
        return _f_text._base; 
    }
    const F_String::Base& _href() const { 
        return _f_href._base; 
    }
    F_String::Base& _href() { 
        _f_href._dirty = true; 
        return _f_href._base; 
    }
    const F_Boolean::Base& _nofollow() const { 
        return _f_nofollow._base; 
    }
    F_Boolean::Base& _nofollow() { 
        _f_nofollow._dirty = true; 
        return _f_nofollow._base; 
    }
    const F_Boolean::Base& _relevant_text() const { 
        return _f_relevant_text._base; 
    }
    F_Boolean::Base& _relevant_text() { 
        _f_relevant_text._dirty = true; 
        return _f_relevant_text._base; 
    }
    const F_Boolean::Base& _is_image() const { 
        return _f_is_image._base; 
    }
    F_Boolean::Base& _is_image() { 
        _f_is_image._dirty = true; 
        return _f_is_image._base; 
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
    const F_Integer::Base& _target_page_id() const { 
        return _f_target_page_id._base; 
    }
    F_Integer::Base& _target_page_id() { 
        _f_target_page_id._dirty = true; 
        return _f_target_page_id._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_href._dirty)
            field2Val["href"] = 
                toSQLString(_f_href._base);
        if (_f_nofollow._dirty)
            field2Val["nofollow"] = 
                toSQLString(_f_nofollow._base);
        if (_f_relevant_text._dirty)
            field2Val["relevant_text"] = 
                toSQLString(_f_relevant_text._base);
        if (_f_is_image._dirty)
            field2Val["is_image"] = 
                toSQLString(_f_is_image._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_target_page_id._dirty)
            field2Val["target_page_id"] = 
                toSQLString(_f_target_page_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("links", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_text._dirty = false;
            _f_href._dirty = false;
            _f_nofollow._dirty = false;
            _f_relevant_text._dirty = false;
            _f_is_image._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            _f_target_page_id._dirty = false;
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
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_href._dirty)
            field2Val["href"] = 
                toSQLString(_f_href._base);
        if (_f_nofollow._dirty)
            field2Val["nofollow"] = 
                toSQLString(_f_nofollow._base);
        if (_f_relevant_text._dirty)
            field2Val["relevant_text"] = 
                toSQLString(_f_relevant_text._base);
        if (_f_is_image._dirty)
            field2Val["is_image"] = 
                toSQLString(_f_is_image._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_target_page_id._dirty)
            field2Val["target_page_id"] = 
                toSQLString(_f_target_page_id._base);
        
        if (DBFace::instance()->
                insert("links", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_text._dirty = false;
            _f_href._dirty = false;
            _f_nofollow._dirty = false;
            _f_relevant_text._dirty = false;
            _f_is_image._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            _f_target_page_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_Link> _f_id;
    F_String _f_text;
    F_String _f_href;
    F_Boolean _f_nofollow;
    F_Boolean _f_relevant_text;
    F_Boolean _f_is_image;
    Field<I_page_id> _f_page_id;
    Field<I_account_id> _f_account_id;
    F_Integer _f_target_page_id;

    friend class T_Page_Link;
};

} //namespace DMMM
#endif //O_PAGE_LINK
