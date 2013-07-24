
#ifndef T_SUBDOMAIN
#define T_SUBDOMAIN
#include "O_Subdomain.hpp"

namespace DMMM {

class T_Subdomain{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Subdomain() 
    {
        _tables.push_back("subdomains");
    }
    T_Subdomain(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("subdomains");
    }

 

    T_Subdomain(const I_Account& parentId)
    {
        _tables.push_back("subdomains");
        
        _constraint._cond = "(subdomains.account_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "subdomains.id";
        }
        std::string _field;
        typedef T_Subdomain::Condition ConditionType;
        typedef Field<I_Subdomain>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "subdomains.name";
        }
        std::string _field;
        typedef T_Subdomain::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "subdomains.account_id";
        }
        std::string _field;
        typedef T_Subdomain::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_selected{
        E_selected() 
        {  
            _field = "subdomains.selected";
        }
        std::string _field;
        typedef T_Subdomain::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_selected _selected(){ 
        return E_selected();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("account_id");
        ret.push_back("selected");
        return ret;
    }

    std::vector<O_Subdomain> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Subdomain> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Subdomain>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_selected._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["selected"]);
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


    std::vector<O_Subdomain> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Subdomain> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Subdomain> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Subdomain, bool> select(const I_Subdomain& id){
        return first(E_id() == id);
    }

    std::pair<O_Subdomain, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Subdomain> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Subdomain(), false);
    }

    std::pair<O_Subdomain, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Subdomain>::const_iterator begin,
                         std::vector<O_Subdomain>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("selected"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Subdomain& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._selected()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("subdomains",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Subdomain>::const_iterator begin,
                           std::vector<O_Subdomain>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Subdomain>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_selected._dirty){
                fields.push_back(std::string("selected"));
                row.push_back(toSQLString(it->_selected()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("subdomains",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_SUBDOMAIN
