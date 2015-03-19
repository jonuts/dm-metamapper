
#ifndef T_ENGINERANK
#define T_ENGINERANK
#include "O_EngineRank.hpp"

namespace DMMM {

class T_EngineRank{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_EngineRank() 
    {
        _tables.push_back("search_engine_search_keywords");
    }
    T_EngineRank(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("search_engine_search_keywords");
    }

 

    T_EngineRank(const I_Account& parentId)
    {
        _tables.push_back("search_engine_search_keywords");
        
        _constraint._cond = "(search_engine_search_keywords.account_id = " + parentId.to_s() + ")";
    } 
 

    T_EngineRank(const I_SearchEngine& parentId)
    {
        _tables.push_back("search_engine_search_keywords");
        
        _constraint._cond = "(search_engine_search_keywords.search_engine_id = " + parentId.to_s() + ")";
    } 
 

    T_EngineRank(const I_SearchKeyword& parentId)
    {
        _tables.push_back("search_engine_search_keywords");
        
        _constraint._cond = "(search_engine_search_keywords.search_keyword_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "search_engine_search_keywords.id";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef Field<I_EngineRank>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "search_engine_search_keywords.created_at";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_baseline_ranking{
        E_baseline_ranking() 
        {  
            _field = "search_engine_search_keywords.baseline_ranking";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_baseline_ranking _baseline_ranking(){ 
        return E_baseline_ranking();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "search_engine_search_keywords.account_id";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_search_keyword_id{
        E_search_keyword_id() 
        {  
            _field = "search_engine_search_keywords.search_keyword_id";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef Field<I_search_keyword_id>::Base ComparerType;
    };

    static E_search_keyword_id _search_keyword_id(){ 
        return E_search_keyword_id();
    }
    struct E_search_engine_id{
        E_search_engine_id() 
        {  
            _field = "search_engine_search_keywords.search_engine_id";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef Field<I_search_engine_id>::Base ComparerType;
    };

    static E_search_engine_id _search_engine_id(){ 
        return E_search_engine_id();
    }
    struct E_tracked{
        E_tracked() 
        {  
            _field = "search_engine_search_keywords.tracked";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_tracked _tracked(){ 
        return E_tracked();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "search_engine_search_keywords.updated_at";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_current_ranking{
        E_current_ranking() 
        {  
            _field = "search_engine_search_keywords.current_ranking";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_current_ranking _current_ranking(){ 
        return E_current_ranking();
    }
    struct E_change_from_last{
        E_change_from_last() 
        {  
            _field = "search_engine_search_keywords.change_from_last";
        }
        std::string _field;
        typedef T_EngineRank::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_change_from_last _change_from_last(){ 
        return E_change_from_last();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("created_at");
        ret.push_back("baseline_ranking");
        ret.push_back("account_id");
        ret.push_back("search_keyword_id");
        ret.push_back("search_engine_id");
        ret.push_back("tracked");
        ret.push_back("updated_at");
        ret.push_back("current_ranking");
        ret.push_back("change_from_last");
        return ret;
    }

    std::vector<O_EngineRank> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_EngineRank> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_EngineRank>::Base>(res[i]["id"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_baseline_ranking._base =
                UTILS::fromString<F_Integer::Base>(res[i]["baseline_ranking"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_search_keyword_id._base =
                UTILS::fromString<Field<I_search_keyword_id>::Base>(res[i]["search_keyword_id"]);
            ret[i]._f_search_engine_id._base =
                UTILS::fromString<Field<I_search_engine_id>::Base>(res[i]["search_engine_id"]);
            ret[i]._f_tracked._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["tracked"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_current_ranking._base =
                UTILS::fromString<F_Integer::Base>(res[i]["current_ranking"]);
            ret[i]._f_change_from_last._base =
                UTILS::fromString<F_Integer::Base>(res[i]["change_from_last"]);
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


    std::vector<O_EngineRank> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_EngineRank> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_EngineRank> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_EngineRank, bool> select(const I_EngineRank& id){
        return first(E_id() == id);
    }

    std::pair<O_EngineRank, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_EngineRank> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_EngineRank(), false);
    }

    std::pair<O_EngineRank, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_EngineRank>::const_iterator begin,
                         std::vector<O_EngineRank>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("baseline_ranking"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("search_keyword_id"));
        
        fields.push_back(std::string("search_engine_id"));
        
        fields.push_back(std::string("tracked"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("current_ranking"));
        
        fields.push_back(std::string("change_from_last"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_EngineRank& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._baseline_ranking()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._search_keyword_id()));
            
            row.push_back(toSQLString(r._search_engine_id()));
            
            row.push_back(toSQLString(r._tracked()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._current_ranking()));
            
            row.push_back(toSQLString(r._change_from_last()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("search_engine_search_keywords",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_EngineRank>::const_iterator begin,
                           std::vector<O_EngineRank>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_EngineRank>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_baseline_ranking._dirty){
                fields.push_back(std::string("baseline_ranking"));
                row.push_back(toSQLString(it->_baseline_ranking()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_search_keyword_id._dirty){
                fields.push_back(std::string("search_keyword_id"));
                row.push_back(toSQLString(it->_search_keyword_id()));
            }
            
            if (it->_f_search_engine_id._dirty){
                fields.push_back(std::string("search_engine_id"));
                row.push_back(toSQLString(it->_search_engine_id()));
            }
            
            if (it->_f_tracked._dirty){
                fields.push_back(std::string("tracked"));
                row.push_back(toSQLString(it->_tracked()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_current_ranking._dirty){
                fields.push_back(std::string("current_ranking"));
                row.push_back(toSQLString(it->_current_ranking()));
            }
            
            if (it->_f_change_from_last._dirty){
                fields.push_back(std::string("change_from_last"));
                row.push_back(toSQLString(it->_change_from_last()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("search_engine_search_keywords",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ENGINERANK
