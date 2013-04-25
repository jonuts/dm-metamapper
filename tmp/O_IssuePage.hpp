#ifndef O_ISSUEPAGE
#define O_ISSUEPAGE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_IssuePage{
public:

    O_IssuePage() {}
    O_IssuePage(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_IssuePage(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}
    O_IssuePage(const I_Issue& parent_id) 
        : _f_issue_id(parent_id)
        {}

O_IssuePage(const I_IssuePage& id) 
        : _f_id(id)
        {}


    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<I_issue_id>::Base& _issue_id() const { 
        return _f_issue_id._base; 
    }
    Field<I_issue_id>::Base& _issue_id() { 
        _f_issue_id._dirty = true; 
        return _f_issue_id._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const Field<I_IssuePage>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_IssuePage>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Float::Base& _impact() const { 
        return _f_impact._base; 
    }
    F_Float::Base& _impact() { 
        _f_impact._dirty = true; 
        return _f_impact._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_issue_id._dirty)
            field2Val["issue_id"] = 
                toSQLString(_f_issue_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("issue_pages", 
                                       field2Val, where))
        {
            _f_page_id._dirty = false;
            _f_issue_id._dirty = false;
            _f_account_id._dirty = false;
            _f_id._dirty = false;
            _f_impact._dirty = false;
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
        if (_f_issue_id._dirty)
            field2Val["issue_id"] = 
                toSQLString(_f_issue_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        
        if (DBFace::instance()->
                insert("issue_pages", field2Val,
                       _f_id._base.serialization()))
        {
            _f_page_id._dirty = false;
            _f_issue_id._dirty = false;
            _f_account_id._dirty = false;
            _f_id._dirty = false;
            _f_impact._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_page_id> _f_page_id;
    Field<I_issue_id> _f_issue_id;
    Field<I_account_id> _f_account_id;
    Field<I_IssuePage> _f_id;
    F_Float _f_impact;

    friend class T_IssuePage;
};

} //namespace DMMM
#endif //O_ISSUEPAGE
