#ifndef O_SANDBOXSETTING
#define O_SANDBOXSETTING

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumSandboxSettingPROP_TYPE { SANDBOXSETTING_PROP_TYPE_STRING = 1, SANDBOXSETTING_PROP_TYPE_INTEGER = 2, SANDBOXSETTING_PROP_TYPE_FLOAT = 3 };


namespace DMMM {

class O_SandboxSetting{
public:

    O_SandboxSetting() {}

O_SandboxSetting(const I_SandboxSetting& id) 
        : _f_id(id)
        {}


    const Field<I_SandboxSetting>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_SandboxSetting>::Base& _id() { 
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
    const Field<EnumSandboxSettingPROP_TYPE>::Base& _prop_type() const { 
        return _f_prop_type._base; 
    }
    Field<EnumSandboxSettingPROP_TYPE>::Base& _prop_type() { 
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
        if (DBFace::instance()->update("sandbox_settings", 
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
                insert("sandbox_settings", field2Val,
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
    Field<I_SandboxSetting> _f_id;
    F_String _f_prop_group;
    F_String _f_name;
    F_String _f_short_name;
    F_String _f_value;
    F_String _f_default_val;
    Field<EnumSandboxSettingPROP_TYPE> _f_prop_type;

    friend class T_SandboxSetting;
};

} //namespace DMMM
#endif //O_SANDBOXSETTING
