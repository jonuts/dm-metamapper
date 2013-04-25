#ifndef O_PAGE_NONHTML
#define O_PAGE_NONHTML

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Page_NonHtml{
public:

    O_Page_NonHtml() {}
    O_Page_NonHtml(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page_NonHtml(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}

O_Page_NonHtml(const I_Page_NonHtml& id) 
        : _f_id(id)
        {}


    const Field<I_Page_NonHtml>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page_NonHtml>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
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
    const F_Integer::Base& _num_flash() const { 
        return _f_num_flash._base; 
    }
    F_Integer::Base& _num_flash() { 
        _f_num_flash._dirty = true; 
        return _f_num_flash._base; 
    }
    const F_Integer::Base& _num_javascript() const { 
        return _f_num_javascript._base; 
    }
    F_Integer::Base& _num_javascript() { 
        _f_num_javascript._dirty = true; 
        return _f_num_javascript._base; 
    }
    const F_Boolean::Base& _deleted() const { 
        return _f_deleted._base; 
    }
    F_Boolean::Base& _deleted() { 
        _f_deleted._dirty = true; 
        return _f_deleted._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_num_flash._dirty)
            field2Val["num_flash"] = 
                toSQLString(_f_num_flash._base);
        if (_f_num_javascript._dirty)
            field2Val["num_javascript"] = 
                toSQLString(_f_num_javascript._base);
        if (_f_deleted._dirty)
            field2Val["deleted"] = 
                toSQLString(_f_deleted._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("non_htmls", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            _f_num_flash._dirty = false;
            _f_num_javascript._dirty = false;
            _f_deleted._dirty = false;
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
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_num_flash._dirty)
            field2Val["num_flash"] = 
                toSQLString(_f_num_flash._base);
        if (_f_num_javascript._dirty)
            field2Val["num_javascript"] = 
                toSQLString(_f_num_javascript._base);
        if (_f_deleted._dirty)
            field2Val["deleted"] = 
                toSQLString(_f_deleted._base);
        
        if (DBFace::instance()->
                insert("non_htmls", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_page_id._dirty = false;
            _f_account_id._dirty = false;
            _f_num_flash._dirty = false;
            _f_num_javascript._dirty = false;
            _f_deleted._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Page_NonHtml> _f_id;
    Field<I_page_id> _f_page_id;
    Field<I_account_id> _f_account_id;
    F_Integer _f_num_flash;
    F_Integer _f_num_javascript;
    F_Boolean _f_deleted;

    friend class T_Page_NonHtml;
};

} //namespace DMMM
#endif //O_PAGE_NONHTML
