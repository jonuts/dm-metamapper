
#ifndef T_ROLE
#define T_ROLE
#include "O_Role.hpp"

namespace DMMM {

class T_Role{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Role() 
    {
        _tables.push_back("roles");
    }
    T_Role(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("roles");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "roles.id";
        }
        std::string _field;
        typedef T_Role::Condition ConditionType;
        typedef Field<I_Role>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "roles.name";
        }
        std::string _field;
        typedef T_Role::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_resource_id{
        E_resource_id() 
        {  
            _field = "roles.resource_id";
        }
        std::string _field;
        typedef T_Role::Condition ConditionType;
        typedef Field<I_resource_id>::Base ComparerType;
    };

    static E_resource_id _resource_id(){ 
        return E_resource_id();
    }
    struct E_resource_type{
        E_resource_type() 
        {  
            _field = "roles.resource_type";
        }
        std::string _field;
        typedef T_Role::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_resource_type _resource_type(){ 
        return E_resource_type();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "roles.created_at";
        }
        std::string _field;
        typedef T_Role::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "roles.updated_at";
        }
        std::string _field;
        typedef T_Role::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("resource_id");
        ret.push_back("resource_type");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        return ret;
    }

    std::vector<O_Role> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Role> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Role>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_resource_id._base =
                UTILS::fromString<Field<I_resource_id>::Base>(res[i]["resource_id"]);
            ret[i]._f_resource_type._base =
                UTILS::fromString<F_String::Base>(res[i]["resource_type"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
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


    std::vector<O_Role> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Role> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Role> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Role, bool> select(const I_Role& id){
        return first(E_id() == id);
    }

    std::pair<O_Role, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Role> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Role(), false);
    }

    std::pair<O_Role, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Role>::const_iterator begin,
                         std::vector<O_Role>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("resource_id"));
        
        fields.push_back(std::string("resource_type"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Role& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._resource_id()));
            
            row.push_back(toSQLString(r._resource_type()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("roles",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Role>::const_iterator begin,
                           std::vector<O_Role>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Role>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_resource_id._dirty){
                fields.push_back(std::string("resource_id"));
                row.push_back(toSQLString(it->_resource_id()));
            }
            
            if (it->_f_resource_type._dirty){
                fields.push_back(std::string("resource_type"));
                row.push_back(toSQLString(it->_resource_type()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("roles",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ROLE
