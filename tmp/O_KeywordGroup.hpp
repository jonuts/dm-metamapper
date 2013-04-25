#ifndef O_KEYWORDGROUP
#define O_KEYWORDGROUP

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_KeywordGroup{
public:

    O_KeywordGroup() {}

O_KeywordGroup(const I_KeywordGroup& id) 
        : _f_id(id)
        {}


    const Field<I_KeywordGroup>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_KeywordGroup>::Base& _id() { 
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
    const F_Integer::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    F_Integer::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
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
    const F_String::Base& _csv_file() const { 
        return _f_csv_file._base; 
    }
    F_String::Base& _csv_file() { 
        _f_csv_file._dirty = true; 
        return _f_csv_file._base; 
    }
    const F_Boolean::Base& _from_file() const { 
        return _f_from_file._base; 
    }
    F_Boolean::Base& _from_file() { 
        _f_from_file._dirty = true; 
        return _f_from_file._base; 
    }
    const F_Text::Base& _manual_list() const { 
        return _f_manual_list._base; 
    }
    F_Text::Base& _manual_list() { 
        _f_manual_list._dirty = true; 
        return _f_manual_list._base; 
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
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_csv_file._dirty)
            field2Val["csv_file"] = 
                toSQLString(_f_csv_file._base);
        if (_f_from_file._dirty)
            field2Val["from_file"] = 
                toSQLString(_f_from_file._base);
        if (_f_manual_list._dirty)
            field2Val["manual_list"] = 
                toSQLString(_f_manual_list._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("keyword_groups", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_account_id._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_csv_file._dirty = false;
            _f_from_file._dirty = false;
            _f_manual_list._dirty = false;
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
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_csv_file._dirty)
            field2Val["csv_file"] = 
                toSQLString(_f_csv_file._base);
        if (_f_from_file._dirty)
            field2Val["from_file"] = 
                toSQLString(_f_from_file._base);
        if (_f_manual_list._dirty)
            field2Val["manual_list"] = 
                toSQLString(_f_manual_list._base);
        
        if (DBFace::instance()->
                insert("keyword_groups", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_account_id._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_csv_file._dirty = false;
            _f_from_file._dirty = false;
            _f_manual_list._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_KeywordGroup> _f_id;
    F_String _f_name;
    F_Integer _f_account_id;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;
    F_String _f_csv_file;
    F_Boolean _f_from_file;
    F_Text _f_manual_list;

    friend class T_KeywordGroup;
};

} //namespace DMMM
#endif //O_KEYWORDGROUP
