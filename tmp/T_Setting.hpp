
#ifndef T_SETTING
#define T_SETTING
#include "O_Setting.hpp"

namespace DMMM {

class T_Setting{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Setting() 
    {
        _tables.push_back("settings");
    }
    T_Setting(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("settings");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "settings.id";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef Field<I_Setting>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_prop_group{
        E_prop_group() 
        {  
            _field = "settings.prop_group";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_prop_group _prop_group(){ 
        return E_prop_group();
    }
    struct E_name{
        E_name() 
        {  
            _field = "settings.name";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_short_name{
        E_short_name() 
        {  
            _field = "settings.short_name";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_short_name _short_name(){ 
        return E_short_name();
    }
    struct E_value{
        E_value() 
        {  
            _field = "settings.value";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_value _value(){ 
        return E_value();
    }
    struct E_default_val{
        E_default_val() 
        {  
            _field = "settings.default_val";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_default_val _default_val(){ 
        return E_default_val();
    }
    struct E_prop_type{
        E_prop_type() 
        {  
            _field = "settings.prop_type";
        }
        std::string _field;
        typedef T_Setting::Condition ConditionType;
        typedef Field<EnumSettingPROP_TYPE>::Base ComparerType;
    };

    static E_prop_type _prop_type(){ 
        return E_prop_type();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("prop_group");
        ret.push_back("name");
        ret.push_back("short_name");
        ret.push_back("value");
        ret.push_back("default_val");
        ret.push_back("prop_type");
        return ret;
    }

    std::vector<O_Setting> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Setting> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Setting>::Base>(res[i]["id"]);
            ret[i]._f_prop_group._base =
                UTILS::fromString<F_String::Base>(res[i]["prop_group"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_short_name._base =
                UTILS::fromString<F_String::Base>(res[i]["short_name"]);
            ret[i]._f_value._base =
                UTILS::fromString<F_String::Base>(res[i]["value"]);
            ret[i]._f_default_val._base =
                UTILS::fromString<F_String::Base>(res[i]["default_val"]);
            ret[i]._f_prop_type._base =
                (Field<EnumSettingPROP_TYPE>::Base)UTILS::fromString<size_t>(res[i]["prop_type"]);
        }
        return ret;
    }

    size_t count(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return DBFace::instance()->count(_tables, c1._cond);
    }

    void erase(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        DBFace::instance()->erase(_tables, c1._cond);
    }

    void erase()
    {   
        DBFace::instance()->erase(_tables, _constraint._cond);
    }


    std::vector<O_Setting> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Setting> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Setting> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Setting, bool> select(const I_Setting& id){
        return first(E_id() == id);
    }

    std::pair<O_Setting, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Setting> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Setting(), false);
    }

    std::pair<O_Setting, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Setting>::const_iterator begin,
                         std::vector<O_Setting>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("prop_group"));
        
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("short_name"));
        
        fields.push_back(std::string("value"));
        
        fields.push_back(std::string("default_val"));
        
        fields.push_back(std::string("prop_type"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Setting& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._prop_group()));
            
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._short_name()));
            
            row.push_back(toSQLString(r._value()));
            
            row.push_back(toSQLString(r._default_val()));
            
            row.push_back(toSQLString(r._prop_type()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("settings",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Setting>::const_iterator begin,
                           std::vector<O_Setting>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Setting>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_prop_group._dirty){
                fields.push_back(std::string("prop_group"));
                row.push_back(toSQLString(it->_prop_group()));
            }
            
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_short_name._dirty){
                fields.push_back(std::string("short_name"));
                row.push_back(toSQLString(it->_short_name()));
            }
            
            if (it->_f_value._dirty){
                fields.push_back(std::string("value"));
                row.push_back(toSQLString(it->_value()));
            }
            
            if (it->_f_default_val._dirty){
                fields.push_back(std::string("default_val"));
                row.push_back(toSQLString(it->_default_val()));
            }
            
            if (it->_f_prop_type._dirty){
                fields.push_back(std::string("prop_type"));
                row.push_back(toSQLString(it->_prop_type()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("settings",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_SETTING
