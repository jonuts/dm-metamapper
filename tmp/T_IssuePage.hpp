
#ifndef T_ISSUEPAGE
#define T_ISSUEPAGE
#include "O_IssuePage.hpp"

namespace DMMM {

class T_IssuePage{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_IssuePage() 
    {
        _tables.push_back("issue_pages");
    }
    T_IssuePage(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("issue_pages");
    }

 

    T_IssuePage(const I_Account& parentId)
    {
        _tables.push_back("issue_pages");
        
        _constraint._cond = "(issue_pages.account_id = " + parentId.to_s() + ")";
    } 
 

    T_IssuePage(const I_Page& parentId)
    {
        _tables.push_back("issue_pages");
        
        _constraint._cond = "(issue_pages.page_id = " + parentId.to_s() + ")";
    } 
 

    T_IssuePage(const I_Issue& parentId)
    {
        _tables.push_back("issue_pages");
        
        _constraint._cond = "(issue_pages.issue_id = " + parentId.to_s() + ")";
    } 
    
    struct E_page_id{
        E_page_id() 
        {  
            _field = "issue_pages.page_id";
        }
        std::string _field;
        typedef T_IssuePage::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_issue_id{
        E_issue_id() 
        {  
            _field = "issue_pages.issue_id";
        }
        std::string _field;
        typedef T_IssuePage::Condition ConditionType;
        typedef Field<I_issue_id>::Base ComparerType;
    };

    static E_issue_id _issue_id(){ 
        return E_issue_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "issue_pages.account_id";
        }
        std::string _field;
        typedef T_IssuePage::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_id{
        E_id() 
        {  
            _field = "issue_pages.id";
        }
        std::string _field;
        typedef T_IssuePage::Condition ConditionType;
        typedef Field<I_IssuePage>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_impact{
        E_impact() 
        {  
            _field = "issue_pages.impact";
        }
        std::string _field;
        typedef T_IssuePage::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_impact _impact(){ 
        return E_impact();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("page_id");
        ret.push_back("issue_id");
        ret.push_back("account_id");
        ret.push_back("id");
        ret.push_back("impact");
        return ret;
    }

    std::vector<O_IssuePage> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_IssuePage> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
            ret[i]._f_issue_id._base =
                UTILS::fromString<Field<I_issue_id>::Base>(res[i]["issue_id"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_IssuePage>::Base>(res[i]["id"]);
            ret[i]._f_impact._base =
                UTILS::fromString<F_Float::Base>(res[i]["impact"]);
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


    std::vector<O_IssuePage> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_IssuePage> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_IssuePage> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_IssuePage, bool> select(const I_IssuePage& id){
        return first(E_id() == id);
    }

    std::pair<O_IssuePage, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_IssuePage> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_IssuePage(), false);
    }

    std::pair<O_IssuePage, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_IssuePage>::const_iterator begin,
                         std::vector<O_IssuePage>::const_iterator end)
    {
	std::vector<std::string> fields;
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("issue_id"));
        
        fields.push_back(std::string("account_id"));
                
        fields.push_back(std::string("impact"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_IssuePage& r = *begin;
	    std::vector<std::string> row;
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._issue_id()));
            
            row.push_back(toSQLString(r._account_id()));
                        
            row.push_back(toSQLString(r._impact()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("issue_pages",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_IssuePage>::const_iterator begin,
                           std::vector<O_IssuePage>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_IssuePage>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
            
            if (it->_f_issue_id._dirty){
                fields.push_back(std::string("issue_id"));
                row.push_back(toSQLString(it->_issue_id()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
                        
            if (it->_f_impact._dirty){
                fields.push_back(std::string("impact"));
                row.push_back(toSQLString(it->_impact()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("issue_pages",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ISSUEPAGE
