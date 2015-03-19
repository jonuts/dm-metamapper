#ifndef O_ROLE
#define O_ROLE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_Role{
public:

    O_Role() {}

O_Role(const I_Role& id) 
        : _f_id(id)
        {}


    const Field<I_Role>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Role>::Base& _id() { 
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
    const Field<I_resource_id>::Base& _resource_id() const { 
        return _f_resource_id._base; 
    }
    Field<I_resource_id>::Base& _resource_id() { 
        _f_resource_id._dirty = true; 
        return _f_resource_id._base; 
    }
    const F_String::Base& _resource_type() const { 
        return _f_resource_type._base; 
    }
    F_String::Base& _resource_type() { 
        _f_resource_type._dirty = true; 
        return _f_resource_type._base; 
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

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_resource_id._dirty)
            field2Val["resource_id"] = 
                toSQLString(_f_resource_id._base);
        if (_f_resource_type._dirty)
            field2Val["resource_type"] = 
                toSQLString(_f_resource_type._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("roles", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_resource_id._dirty = false;
            _f_resource_type._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
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
        if (_f_resource_id._dirty)
            field2Val["resource_id"] = 
                toSQLString(_f_resource_id._base);
        if (_f_resource_type._dirty)
            field2Val["resource_type"] = 
                toSQLString(_f_resource_type._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        
        if (DBFace::instance()->
                insert("roles", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_resource_id._dirty = false;
            _f_resource_type._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Role> _f_id;
    F_String _f_name;
    Field<I_resource_id> _f_resource_id;
    F_String _f_resource_type;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;

    friend class T_Role;
};

} //namespace DMMM
#endif //O_ROLE
