
#ifndef T_ACCOUNTISSUE
#define T_ACCOUNTISSUE
#include "O_AccountIssue.hpp"

namespace DMMM {

class T_AccountIssue{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_AccountIssue() 
    {
        _tables.push_back("account_issues");
    }
    T_AccountIssue(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("account_issues");
    }

 

    T_AccountIssue(const I_Account& parentId)
    {
        _tables.push_back("account_issues");
        
        _constraint._cond = "(account_issues.account_id = " + parentId.to_s() + ")";
    } 
 

    T_AccountIssue(const I_Issue& parentId)
    {
        _tables.push_back("account_issues");
        
        _constraint._cond = "(account_issues.issue_id = " + parentId.to_s() + ")";
    } 
    
    
    struct E_account_id{
        E_account_id() 
        {  
            _field = "account_issues.account_id";
        }
        std::string _field;
        typedef T_AccountIssue::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_issue_id{
        E_issue_id() 
        {  
            _field = "account_issues.issue_id";
        }
        std::string _field;
        typedef T_AccountIssue::Condition ConditionType;
        typedef Field<I_issue_id>::Base ComparerType;
    };

    static E_issue_id _issue_id(){ 
        return E_issue_id();
    }
    struct E_id{
        E_id() 
        {  
            _field = "account_issues.id";
        }
        std::string _field;
        typedef T_AccountIssue::Condition ConditionType;
        typedef Field<I_AccountIssue>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_impact{
        E_impact() 
        {  
            _field = "account_issues.impact";
        }
        std::string _field;
        typedef T_AccountIssue::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_impact _impact(){ 
        return E_impact();
    }
    struct E_number_of_pages{
        E_number_of_pages() 
        {  
            _field = "account_issues.number_of_pages";
        }
        std::string _field;
        typedef T_AccountIssue::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_pages _number_of_pages(){ 
        return E_number_of_pages();
    }
    struct E_priority{
        E_priority() 
        {  
            _field = "account_issues.priority";
        }
        std::string _field;
        typedef T_AccountIssue::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_priority _priority(){ 
        return E_priority();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("account_id");
        ret.push_back("issue_id");
        ret.push_back("id");
        ret.push_back("impact");
        ret.push_back("number_of_pages");
        ret.push_back("priority");
        return ret;
    }

    std::vector<O_AccountIssue> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_AccountIssue> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_issue_id._base =
                UTILS::fromString<Field<I_issue_id>::Base>(res[i]["issue_id"]);
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_AccountIssue>::Base>(res[i]["id"]);
            ret[i]._f_impact._base =
                UTILS::fromString<F_Float::Base>(res[i]["impact"]);
            ret[i]._f_number_of_pages._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_pages"]);
            ret[i]._f_priority._base =
                UTILS::fromString<F_Integer::Base>(res[i]["priority"]);
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


    std::vector<O_AccountIssue> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_AccountIssue> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_AccountIssue> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_AccountIssue, bool> select(const I_AccountIssue& id){
        return first(E_id() == id);
    }

    std::pair<O_AccountIssue, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_AccountIssue> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_AccountIssue(), false);
    }

    std::pair<O_AccountIssue, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_AccountIssue>::const_iterator begin,
                         std::vector<O_AccountIssue>::const_iterator end)
    {
	std::vector<std::string> fields;
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("issue_id"));
                
        fields.push_back(std::string("impact"));
        
        fields.push_back(std::string("number_of_pages"));
        
        fields.push_back(std::string("priority"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_AccountIssue& r = *begin;
	    std::vector<std::string> row;
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._issue_id()));
                        
            row.push_back(toSQLString(r._impact()));
            
            row.push_back(toSQLString(r._number_of_pages()));
            
            row.push_back(toSQLString(r._priority()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("account_issues",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_AccountIssue>::const_iterator begin,
                           std::vector<O_AccountIssue>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_AccountIssue>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_issue_id._dirty){
                fields.push_back(std::string("issue_id"));
                row.push_back(toSQLString(it->_issue_id()));
            }
                        
            if (it->_f_impact._dirty){
                fields.push_back(std::string("impact"));
                row.push_back(toSQLString(it->_impact()));
            }
            
            if (it->_f_number_of_pages._dirty){
                fields.push_back(std::string("number_of_pages"));
                row.push_back(toSQLString(it->_number_of_pages()));
            }
            
            if (it->_f_priority._dirty){
                fields.push_back(std::string("priority"));
                row.push_back(toSQLString(it->_priority()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("account_issues",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ACCOUNTISSUE
