#ifndef O_ACCOUNTISSUE
#define O_ACCOUNTISSUE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_AccountIssue{
public:

    O_AccountIssue() {}
    O_AccountIssue(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_AccountIssue(const I_Issue& parent_id) 
        : _f_issue_id(parent_id)
        {}

O_AccountIssue(const I_AccountIssue& id) 
        : _f_id(id)
        {}


    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const Field<I_issue_id>::Base& _issue_id() const { 
        return _f_issue_id._base; 
    }
    Field<I_issue_id>::Base& _issue_id() { 
        _f_issue_id._dirty = true; 
        return _f_issue_id._base; 
    }
    const Field<I_AccountIssue>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_AccountIssue>::Base& _id() { 
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
    const F_Integer::Base& _number_of_pages() const { 
        return _f_number_of_pages._base; 
    }
    F_Integer::Base& _number_of_pages() { 
        _f_number_of_pages._dirty = true; 
        return _f_number_of_pages._base; 
    }
    const F_Integer::Base& _priority() const { 
        return _f_priority._base; 
    }
    F_Integer::Base& _priority() { 
        _f_priority._dirty = true; 
        return _f_priority._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_issue_id._dirty)
            field2Val["issue_id"] = 
                toSQLString(_f_issue_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        if (_f_number_of_pages._dirty)
            field2Val["number_of_pages"] = 
                toSQLString(_f_number_of_pages._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("account_issues", 
                                       field2Val, where))
        {
            _f_account_id._dirty = false;
            _f_issue_id._dirty = false;
            _f_id._dirty = false;
            _f_impact._dirty = false;
            _f_number_of_pages._dirty = false;
            _f_priority._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_issue_id._dirty)
            field2Val["issue_id"] = 
                toSQLString(_f_issue_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        if (_f_number_of_pages._dirty)
            field2Val["number_of_pages"] = 
                toSQLString(_f_number_of_pages._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        
        if (DBFace::instance()->
                insert("account_issues", field2Val,
                       _f_id._base.serialization()))
        {
            _f_account_id._dirty = false;
            _f_issue_id._dirty = false;
            _f_id._dirty = false;
            _f_impact._dirty = false;
            _f_number_of_pages._dirty = false;
            _f_priority._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_account_id> _f_account_id;
    Field<I_issue_id> _f_issue_id;
    Field<I_AccountIssue> _f_id;
    F_Float _f_impact;
    F_Integer _f_number_of_pages;
    F_Integer _f_priority;

    friend class T_AccountIssue;
};

} //namespace DMMM
#endif //O_ACCOUNTISSUE
