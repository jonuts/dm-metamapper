#ifndef O_SETTING
#define O_SETTING

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumSettingPROP_TYPE { SETTING_PROP_TYPE_STRING = 1, SETTING_PROP_TYPE_INTEGER = 2, SETTING_PROP_TYPE_FLOAT = 3 };


namespace DMMM {

class O_Setting{
public:

    O_Setting() {}

O_Setting(const I_Setting& id) 
        : _f_id(id)
        {}


    const Field<I_Setting>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Setting>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _prop_group() const { 
        return _f_prop_group._base; 
    }
    F_String::Base& _prop_group() { 
        _f_prop_group._dirty = true; 
        return _f_prop_group._base; 
    }
    const F_String::Base& _name() const { 
        return _f_name._base; 
    }
    F_String::Base& _name() { 
        _f_name._dirty = true; 
        return _f_name._base; 
    }
    const F_String::Base& _short_name() const { 
        return _f_short_name._base; 
    }
    F_String::Base& _short_name() { 
        _f_short_name._dirty = true; 
        return _f_short_name._base; 
    }
    const F_String::Base& _value() const { 
        return _f_value._base; 
    }
    F_String::Base& _value() { 
        _f_value._dirty = true; 
        return _f_value._base; 
    }
    const F_String::Base& _default_val() const { 
        return _f_default_val._base; 
    }
    F_String::Base& _default_val() { 
        _f_default_val._dirty = true; 
        return _f_default_val._base; 
    }
    const Field<EnumSettingPROP_TYPE>::Base& _prop_type() const { 
        return _f_prop_type._base; 
    }
    Field<EnumSettingPROP_TYPE>::Base& _prop_type() { 
        _f_prop_type._dirty = true; 
        return _f_prop_type._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_prop_group._dirty)
            field2Val["prop_group"] = 
                toSQLString(_f_prop_group._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_short_name._dirty)
            field2Val["short_name"] = 
                toSQLString(_f_short_name._base);
        if (_f_value._dirty)
            field2Val["value"] = 
                toSQLString(_f_value._base);
        if (_f_default_val._dirty)
            field2Val["default_val"] = 
                toSQLString(_f_default_val._base);
        if (_f_prop_type._dirty)
            field2Val["prop_type"] = 
                toSQLString(_f_prop_type._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("settings", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_prop_group._dirty = false;
            _f_name._dirty = false;
            _f_short_name._dirty = false;
            _f_value._dirty = false;
            _f_default_val._dirty = false;
            _f_prop_type._dirty = false;
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
        if (_f_prop_group._dirty)
            field2Val["prop_group"] = 
                toSQLString(_f_prop_group._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_short_name._dirty)
            field2Val["short_name"] = 
                toSQLString(_f_short_name._base);
        if (_f_value._dirty)
            field2Val["value"] = 
                toSQLString(_f_value._base);
        if (_f_default_val._dirty)
            field2Val["default_val"] = 
                toSQLString(_f_default_val._base);
        if (_f_prop_type._dirty)
            field2Val["prop_type"] = 
                toSQLString(_f_prop_type._base);
        
        if (DBFace::instance()->
                insert("settings", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_prop_group._dirty = false;
            _f_name._dirty = false;
            _f_short_name._dirty = false;
            _f_value._dirty = false;
            _f_default_val._dirty = false;
            _f_prop_type._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Setting> _f_id;
    F_String _f_prop_group;
    F_String _f_name;
    F_String _f_short_name;
    F_String _f_value;
    F_String _f_default_val;
    Field<EnumSettingPROP_TYPE> _f_prop_type;

    friend class T_Setting;
};

} //namespace DMMM
#endif //O_SETTING
