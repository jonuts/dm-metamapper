
#ifndef T_PAGESEARCHKEYWORD
#define T_PAGESEARCHKEYWORD
#include "O_PageSearchKeyword.hpp"

namespace DMMM {

class T_PageSearchKeyword{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_PageSearchKeyword() 
    {
        _tables.push_back("page_search_keywords");
    }
    T_PageSearchKeyword(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("page_search_keywords");
    }

 

    T_PageSearchKeyword(const I_Account& parentId)
    {
        _tables.push_back("page_search_keywords");
        
        _constraint._cond = "(page_search_keywords.account_id = " + parentId.to_s() + ")";
    } 
 

    T_PageSearchKeyword(const I_Page& parentId)
    {
        _tables.push_back("page_search_keywords");
        
        _constraint._cond = "(page_search_keywords.page_id = " + parentId.to_s() + ")";
    } 
 

    T_PageSearchKeyword(const I_SearchKeyword& parentId)
    {
        _tables.push_back("page_search_keywords");
        
        _constraint._cond = "(page_search_keywords.search_keyword_id = " + parentId.to_s() + ")";
    } 
    
    struct E_page_id{
        E_page_id() 
        {  
            _field = "page_search_keywords.page_id";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_search_keyword_id{
        E_search_keyword_id() 
        {  
            _field = "page_search_keywords.search_keyword_id";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef Field<I_search_keyword_id>::Base ComparerType;
    };

    static E_search_keyword_id _search_keyword_id(){ 
        return E_search_keyword_id();
    }
    struct E_id{
        E_id() 
        {  
            _field = "page_search_keywords.id";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef Field<I_PageSearchKeyword>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_current_rank{
        E_current_rank() 
        {  
            _field = "page_search_keywords.current_rank";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_current_rank _current_rank(){ 
        return E_current_rank();
    }
    struct E_target_rank{
        E_target_rank() 
        {  
            _field = "page_search_keywords.target_rank";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_target_rank _target_rank(){ 
        return E_target_rank();
    }
    struct E_deleted_at{
        E_deleted_at() 
        {  
            _field = "page_search_keywords.deleted_at";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_deleted_at _deleted_at(){ 
        return E_deleted_at();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "page_search_keywords.account_id";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_set_by_user{
        E_set_by_user() 
        {  
            _field = "page_search_keywords.set_by_user";
        }
        std::string _field;
        typedef T_PageSearchKeyword::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_set_by_user _set_by_user(){ 
        return E_set_by_user();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("page_id");
        ret.push_back("search_keyword_id");
        ret.push_back("id");
        ret.push_back("current_rank");
        ret.push_back("target_rank");
        ret.push_back("deleted_at");
        ret.push_back("account_id");
        ret.push_back("set_by_user");
        return ret;
    }

    std::vector<O_PageSearchKeyword> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_PageSearchKeyword> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
            ret[i]._f_search_keyword_id._base =
                UTILS::fromString<Field<I_search_keyword_id>::Base>(res[i]["search_keyword_id"]);
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_PageSearchKeyword>::Base>(res[i]["id"]);
            ret[i]._f_current_rank._base =
                UTILS::fromString<F_Integer::Base>(res[i]["current_rank"]);
            ret[i]._f_target_rank._base =
                UTILS::fromString<F_Integer::Base>(res[i]["target_rank"]);
            ret[i]._f_deleted_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["deleted_at"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_set_by_user._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["set_by_user"]);
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


    std::vector<O_PageSearchKeyword> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_PageSearchKeyword> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_PageSearchKeyword> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_PageSearchKeyword, bool> select(const I_PageSearchKeyword& id){
        return first(E_id() == id);
    }

    std::pair<O_PageSearchKeyword, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_PageSearchKeyword> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_PageSearchKeyword(), false);
    }

    std::pair<O_PageSearchKeyword, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_PageSearchKeyword>::const_iterator begin,
                         std::vector<O_PageSearchKeyword>::const_iterator end)
    {
	std::vector<std::string> fields;
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("search_keyword_id"));
                
        fields.push_back(std::string("current_rank"));
        
        fields.push_back(std::string("target_rank"));
        
        fields.push_back(std::string("deleted_at"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("set_by_user"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_PageSearchKeyword& r = *begin;
	    std::vector<std::string> row;
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._search_keyword_id()));
                        
            row.push_back(toSQLString(r._current_rank()));
            
            row.push_back(toSQLString(r._target_rank()));
            
            row.push_back(toSQLString(r._deleted_at()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._set_by_user()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("page_search_keywords",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_PageSearchKeyword>::const_iterator begin,
                           std::vector<O_PageSearchKeyword>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_PageSearchKeyword>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
            
            if (it->_f_search_keyword_id._dirty){
                fields.push_back(std::string("search_keyword_id"));
                row.push_back(toSQLString(it->_search_keyword_id()));
            }
                        
            if (it->_f_current_rank._dirty){
                fields.push_back(std::string("current_rank"));
                row.push_back(toSQLString(it->_current_rank()));
            }
            
            if (it->_f_target_rank._dirty){
                fields.push_back(std::string("target_rank"));
                row.push_back(toSQLString(it->_target_rank()));
            }
            
            if (it->_f_deleted_at._dirty){
                fields.push_back(std::string("deleted_at"));
                row.push_back(toSQLString(it->_deleted_at()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_set_by_user._dirty){
                fields.push_back(std::string("set_by_user"));
                row.push_back(toSQLString(it->_set_by_user()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("page_search_keywords",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGESEARCHKEYWORD
