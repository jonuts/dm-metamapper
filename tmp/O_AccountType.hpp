#ifndef O_ACCOUNTTYPE
#define O_ACCOUNTTYPE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_AccountType{
public:

    O_AccountType() {}

O_AccountType(const I_AccountType& id) 
        : _f_id(id)
        {}


    const Field<I_AccountType>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_AccountType>::Base& _id() { 
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
    const F_Integer::Base& _ttl() const { 
        return _f_ttl._base; 
    }
    F_Integer::Base& _ttl() { 
        _f_ttl._dirty = true; 
        return _f_ttl._base; 
    }
    const F_Boolean::Base& _deletable() const { 
        return _f_deletable._base; 
    }
    F_Boolean::Base& _deletable() { 
        _f_deletable._dirty = true; 
        return _f_deletable._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_ttl._dirty)
            field2Val["ttl"] = 
                toSQLString(_f_ttl._base);
        if (_f_deletable._dirty)
            field2Val["deletable"] = 
                toSQLString(_f_deletable._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("account_types", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_ttl._dirty = false;
            _f_deletable._dirty = false;
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
        if (_f_ttl._dirty)
            field2Val["ttl"] = 
                toSQLString(_f_ttl._base);
        if (_f_deletable._dirty)
            field2Val["deletable"] = 
                toSQLString(_f_deletable._base);
        
        if (DBFace::instance()->
                insert("account_types", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_ttl._dirty = false;
            _f_deletable._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_AccountType> _f_id;
    F_String _f_name;
    F_Integer _f_ttl;
    F_Boolean _f_deletable;

    friend class T_AccountType;
};

} //namespace DMMM
#endif //O_ACCOUNTTYPE
