
#ifndef T_ACCOUNTTYPE
#define T_ACCOUNTTYPE
#include "O_AccountType.hpp"

namespace DMMM {

class T_AccountType{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_AccountType() 
    {
        _tables.push_back("account_types");
    }
    T_AccountType(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("account_types");
    }

    
    
    struct E_id{
        E_id() 
        {  
            _field = "account_types.id";
        }
        std::string _field;
        typedef T_AccountType::Condition ConditionType;
        typedef Field<I_AccountType>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "account_types.name";
        }
        std::string _field;
        typedef T_AccountType::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_ttl{
        E_ttl() 
        {  
            _field = "account_types.ttl";
        }
        std::string _field;
        typedef T_AccountType::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_ttl _ttl(){ 
        return E_ttl();
    }
    struct E_deletable{
        E_deletable() 
        {  
            _field = "account_types.deletable";
        }
        std::string _field;
        typedef T_AccountType::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_deletable _deletable(){ 
        return E_deletable();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("ttl");
        ret.push_back("deletable");
        return ret;
    }

    std::vector<O_AccountType> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_AccountType> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_AccountType>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_ttl._base =
                UTILS::fromString<F_Integer::Base>(res[i]["ttl"]);
            ret[i]._f_deletable._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["deletable"]);
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


    std::vector<O_AccountType> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_AccountType> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_AccountType> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_AccountType, bool> select(const I_AccountType& id){
        return first(E_id() == id);
    }

    std::pair<O_AccountType, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_AccountType> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_AccountType(), false);
    }

    std::pair<O_AccountType, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_AccountType>::const_iterator begin,
                         std::vector<O_AccountType>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("ttl"));
        
        fields.push_back(std::string("deletable"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_AccountType& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._ttl()));
            
            row.push_back(toSQLString(r._deletable()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("account_types",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_AccountType>::const_iterator begin,
                           std::vector<O_AccountType>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_AccountType>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_ttl._dirty){
                fields.push_back(std::string("ttl"));
                row.push_back(toSQLString(it->_ttl()));
            }
            
            if (it->_f_deletable._dirty){
                fields.push_back(std::string("deletable"));
                row.push_back(toSQLString(it->_deletable()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("account_types",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ACCOUNTTYPE
