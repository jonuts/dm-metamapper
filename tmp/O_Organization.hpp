#ifndef O_ORGANIZATION
#define O_ORGANIZATION

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_User.hpp"
#include "T_Account.hpp"



namespace DMMM {

class O_Organization{
public:

    O_Organization() {}

O_Organization(const I_Organization& id) 
        : _f_id(id)
        {}


    std::vector<O_User> _users() const
    {
        T_User table;
        return table.select(table._organization_id() == _id());   
    }
    std::vector<O_User> 
    _organization_id(const T_User::Condition& c) const
    {
        T_User table(c);
        return table.select(table._organization_id() == _id());   
    }

    std::vector<O_Account> _accounts() const
    {
        T_Account table;
        return table.select(table._organization_id() == _id());   
    }
    std::vector<O_Account> 
    _organization_id(const T_Account::Condition& c) const
    {
        T_Account table(c);
        return table.select(table._organization_id() == _id());   
    }

    const Field<I_Organization>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Organization>::Base& _id() { 
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
    const F_Datetime::Base& _created_at() const { 
        return _f_created_at._base; 
    }
    F_Datetime::Base& _created_at() { 
        _f_created_at._dirty = true; 
        return _f_created_at._base; 
    }
    const F_Datetime::Base& _updated_at() const { 
        return _f_updated_at._base; 
    }
    F_Datetime::Base& _updated_at() { 
        _f_updated_at._dirty = true; 
        return _f_updated_at._base; 
    }
    const F_String::Base& _subdomain() const { 
        return _f_subdomain._base; 
    }
    F_String::Base& _subdomain() { 
        _f_subdomain._dirty = true; 
        return _f_subdomain._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_subdomain._dirty)
            field2Val["subdomain"] = 
                toSQLString(_f_subdomain._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("organizations", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_subdomain._dirty = false;
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
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_subdomain._dirty)
            field2Val["subdomain"] = 
                toSQLString(_f_subdomain._base);
        
        if (DBFace::instance()->
                insert("organizations", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_subdomain._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Organization> _f_id;
    F_String _f_name;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;
    F_String _f_subdomain;

    friend class T_Organization;
};

} //namespace DMMM
#endif //O_ORGANIZATION
