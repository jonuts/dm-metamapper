#ifndef O_SUBDOMAIN
#define O_SUBDOMAIN

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Subdomain{
public:

    O_Subdomain() {}
    O_Subdomain(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}

O_Subdomain(const I_Subdomain& id) 
        : _f_id(id)
        {}


    const Field<I_Subdomain>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Subdomain>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _name() const { 
        return _f_name._base; 
    }
    F_String::Base& _name() { 
        _f_name._dirty = true; 
        return _f_name._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_Boolean::Base& _selected() const { 
        return _f_selected._base; 
    }
    F_Boolean::Base& _selected() { 
        _f_selected._dirty = true; 
        return _f_selected._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_selected._dirty)
            field2Val["selected"] = 
                toSQLString(_f_selected._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("subdomains", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_account_id._dirty = false;
            _f_selected._dirty = false;
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
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_selected._dirty)
            field2Val["selected"] = 
                toSQLString(_f_selected._base);
        
        if (DBFace::instance()->
                insert("subdomains", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_account_id._dirty = false;
            _f_selected._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Subdomain> _f_id;
    F_String _f_name;
    Field<I_account_id> _f_account_id;
    F_Boolean _f_selected;

    friend class T_Subdomain;
};

} //namespace DMMM
#endif //O_SUBDOMAIN
