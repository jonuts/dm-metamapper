
#ifndef T_ORGANIZATION
#define T_ORGANIZATION
#include "O_Organization.hpp"

namespace DMMM {

class T_Organization{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Organization() 
    {
        _tables.push_back("organizations");
    }
    T_Organization(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("organizations");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "organizations.id";
        }
        std::string _field;
        typedef T_Organization::Condition ConditionType;
        typedef Field<I_Organization>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "organizations.name";
        }
        std::string _field;
        typedef T_Organization::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "organizations.created_at";
        }
        std::string _field;
        typedef T_Organization::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "organizations.updated_at";
        }
        std::string _field;
        typedef T_Organization::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_subdomain{
        E_subdomain() 
        {  
            _field = "organizations.subdomain";
        }
        std::string _field;
        typedef T_Organization::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_subdomain _subdomain(){ 
        return E_subdomain();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("subdomain");
        return ret;
    }

    std::vector<O_Organization> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Organization> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Organization>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_subdomain._base =
                UTILS::fromString<F_String::Base>(res[i]["subdomain"]);
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


    std::vector<O_Organization> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Organization> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Organization> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Organization, bool> select(const I_Organization& id){
        return first(E_id() == id);
    }

    std::pair<O_Organization, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Organization> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Organization(), false);
    }

    std::pair<O_Organization, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Organization>::const_iterator begin,
                         std::vector<O_Organization>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("subdomain"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Organization& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._subdomain()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("organizations",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Organization>::const_iterator begin,
                           std::vector<O_Organization>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Organization>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_subdomain._dirty){
                fields.push_back(std::string("subdomain"));
                row.push_back(toSQLString(it->_subdomain()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("organizations",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ORGANIZATION
