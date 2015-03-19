
#ifndef T_SEARCHCOMPETITION
#define T_SEARCHCOMPETITION
#include "O_SearchCompetition.hpp"

namespace DMMM {

class T_SearchCompetition{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_SearchCompetition() 
    {
        _tables.push_back("search_competitions");
    }
    T_SearchCompetition(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("search_competitions");
    }

 

    T_SearchCompetition(const I_Account& parentId)
    {
        _tables.push_back("search_competitions");
        
        _constraint._cond = "(search_competitions.account_id = " + parentId.to_s() + ")";
    } 
 

    T_SearchCompetition(const I_SearchKeyword& parentId)
    {
        _tables.push_back("search_competitions");
        
        _constraint._cond = "(search_competitions.search_keyword_id = " + parentId.to_s() + ")";
    } 
 

    T_SearchCompetition(const I_Competition& parentId)
    {
        _tables.push_back("search_competitions");
        
        _constraint._cond = "(search_competitions.competition_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "search_competitions.id";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef Field<I_SearchCompetition>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_url{
        E_url() 
        {  
            _field = "search_competitions.url";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_url _url(){ 
        return E_url();
    }
    struct E_rank{
        E_rank() 
        {  
            _field = "search_competitions.rank";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_rank _rank(){ 
        return E_rank();
    }
    struct E_pr{
        E_pr() 
        {  
            _field = "search_competitions.pr";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_pr _pr(){ 
        return E_pr();
    }
    struct E_relevance{
        E_relevance() 
        {  
            _field = "search_competitions.relevance";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_relevance _relevance(){ 
        return E_relevance();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "search_competitions.created_at";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_search_engine_id{
        E_search_engine_id() 
        {  
            _field = "search_competitions.search_engine_id";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_search_engine_id _search_engine_id(){ 
        return E_search_engine_id();
    }
    struct E_tracked_keyword_id{
        E_tracked_keyword_id() 
        {  
            _field = "search_competitions.tracked_keyword_id";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_tracked_keyword_id _tracked_keyword_id(){ 
        return E_tracked_keyword_id();
    }
    struct E_in_url{
        E_in_url() 
        {  
            _field = "search_competitions.in_url";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_url _in_url(){ 
        return E_in_url();
    }
    struct E_in_title{
        E_in_title() 
        {  
            _field = "search_competitions.in_title";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_title _in_title(){ 
        return E_in_title();
    }
    struct E_in_meta_desc{
        E_in_meta_desc() 
        {  
            _field = "search_competitions.in_meta_desc";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_meta_desc _in_meta_desc(){ 
        return E_in_meta_desc();
    }
    struct E_in_meta_kws{
        E_in_meta_kws() 
        {  
            _field = "search_competitions.in_meta_kws";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_meta_kws _in_meta_kws(){ 
        return E_in_meta_kws();
    }
    struct E_in_backlink{
        E_in_backlink() 
        {  
            _field = "search_competitions.in_backlink";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_backlink _in_backlink(){ 
        return E_in_backlink();
    }
    struct E_in_h1{
        E_in_h1() 
        {  
            _field = "search_competitions.in_h1";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_h1 _in_h1(){ 
        return E_in_h1();
    }
    struct E_in_h2{
        E_in_h2() 
        {  
            _field = "search_competitions.in_h2";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_h2 _in_h2(){ 
        return E_in_h2();
    }
    struct E_in_h3{
        E_in_h3() 
        {  
            _field = "search_competitions.in_h3";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_h3 _in_h3(){ 
        return E_in_h3();
    }
    struct E_in_body{
        E_in_body() 
        {  
            _field = "search_competitions.in_body";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_body _in_body(){ 
        return E_in_body();
    }
    struct E_in_domain{
        E_in_domain() 
        {  
            _field = "search_competitions.in_domain";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_domain _in_domain(){ 
        return E_in_domain();
    }
    struct E_search_keyword_id{
        E_search_keyword_id() 
        {  
            _field = "search_competitions.search_keyword_id";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef Field<I_search_keyword_id>::Base ComparerType;
    };

    static E_search_keyword_id _search_keyword_id(){ 
        return E_search_keyword_id();
    }
    struct E_competition_id{
        E_competition_id() 
        {  
            _field = "search_competitions.competition_id";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef Field<I_competition_id>::Base ComparerType;
    };

    static E_competition_id _competition_id(){ 
        return E_competition_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "search_competitions.account_id";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_in_link{
        E_in_link() 
        {  
            _field = "search_competitions.in_link";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_link _in_link(){ 
        return E_in_link();
    }
    struct E_in_alt{
        E_in_alt() 
        {  
            _field = "search_competitions.in_alt";
        }
        std::string _field;
        typedef T_SearchCompetition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_in_alt _in_alt(){ 
        return E_in_alt();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("url");
        ret.push_back("rank");
        ret.push_back("pr");
        ret.push_back("relevance");
        ret.push_back("created_at");
        ret.push_back("search_engine_id");
        ret.push_back("tracked_keyword_id");
        ret.push_back("in_url");
        ret.push_back("in_title");
        ret.push_back("in_meta_desc");
        ret.push_back("in_meta_kws");
        ret.push_back("in_backlink");
        ret.push_back("in_h1");
        ret.push_back("in_h2");
        ret.push_back("in_h3");
        ret.push_back("in_body");
        ret.push_back("in_domain");
        ret.push_back("search_keyword_id");
        ret.push_back("competition_id");
        ret.push_back("account_id");
        ret.push_back("in_link");
        ret.push_back("in_alt");
        return ret;
    }

    std::vector<O_SearchCompetition> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_SearchCompetition> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_SearchCompetition>::Base>(res[i]["id"]);
            ret[i]._f_url._base =
                UTILS::fromString<F_String::Base>(res[i]["url"]);
            ret[i]._f_rank._base =
                UTILS::fromString<F_Integer::Base>(res[i]["rank"]);
            ret[i]._f_pr._base =
                UTILS::fromString<F_Integer::Base>(res[i]["pr"]);
            ret[i]._f_relevance._base =
                UTILS::fromString<F_Integer::Base>(res[i]["relevance"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_search_engine_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["search_engine_id"]);
            ret[i]._f_tracked_keyword_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["tracked_keyword_id"]);
            ret[i]._f_in_url._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_url"]);
            ret[i]._f_in_title._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_title"]);
            ret[i]._f_in_meta_desc._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_meta_desc"]);
            ret[i]._f_in_meta_kws._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_meta_kws"]);
            ret[i]._f_in_backlink._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_backlink"]);
            ret[i]._f_in_h1._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_h1"]);
            ret[i]._f_in_h2._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_h2"]);
            ret[i]._f_in_h3._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_h3"]);
            ret[i]._f_in_body._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_body"]);
            ret[i]._f_in_domain._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_domain"]);
            ret[i]._f_search_keyword_id._base =
                UTILS::fromString<Field<I_search_keyword_id>::Base>(res[i]["search_keyword_id"]);
            ret[i]._f_competition_id._base =
                UTILS::fromString<Field<I_competition_id>::Base>(res[i]["competition_id"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_in_link._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_link"]);
            ret[i]._f_in_alt._base =
                UTILS::fromString<F_Integer::Base>(res[i]["in_alt"]);
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


    std::vector<O_SearchCompetition> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_SearchCompetition> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_SearchCompetition> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_SearchCompetition, bool> select(const I_SearchCompetition& id){
        return first(E_id() == id);
    }

    std::pair<O_SearchCompetition, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_SearchCompetition> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_SearchCompetition(), false);
    }

    std::pair<O_SearchCompetition, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_SearchCompetition>::const_iterator begin,
                         std::vector<O_SearchCompetition>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("url"));
        
        fields.push_back(std::string("rank"));
        
        fields.push_back(std::string("pr"));
        
        fields.push_back(std::string("relevance"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("search_engine_id"));
        
        fields.push_back(std::string("tracked_keyword_id"));
        
        fields.push_back(std::string("in_url"));
        
        fields.push_back(std::string("in_title"));
        
        fields.push_back(std::string("in_meta_desc"));
        
        fields.push_back(std::string("in_meta_kws"));
        
        fields.push_back(std::string("in_backlink"));
        
        fields.push_back(std::string("in_h1"));
        
        fields.push_back(std::string("in_h2"));
        
        fields.push_back(std::string("in_h3"));
        
        fields.push_back(std::string("in_body"));
        
        fields.push_back(std::string("in_domain"));
        
        fields.push_back(std::string("search_keyword_id"));
        
        fields.push_back(std::string("competition_id"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("in_link"));
        
        fields.push_back(std::string("in_alt"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_SearchCompetition& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._url()));
            
            row.push_back(toSQLString(r._rank()));
            
            row.push_back(toSQLString(r._pr()));
            
            row.push_back(toSQLString(r._relevance()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._search_engine_id()));
            
            row.push_back(toSQLString(r._tracked_keyword_id()));
            
            row.push_back(toSQLString(r._in_url()));
            
            row.push_back(toSQLString(r._in_title()));
            
            row.push_back(toSQLString(r._in_meta_desc()));
            
            row.push_back(toSQLString(r._in_meta_kws()));
            
            row.push_back(toSQLString(r._in_backlink()));
            
            row.push_back(toSQLString(r._in_h1()));
            
            row.push_back(toSQLString(r._in_h2()));
            
            row.push_back(toSQLString(r._in_h3()));
            
            row.push_back(toSQLString(r._in_body()));
            
            row.push_back(toSQLString(r._in_domain()));
            
            row.push_back(toSQLString(r._search_keyword_id()));
            
            row.push_back(toSQLString(r._competition_id()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._in_link()));
            
            row.push_back(toSQLString(r._in_alt()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("search_competitions",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_SearchCompetition>::const_iterator begin,
                           std::vector<O_SearchCompetition>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_SearchCompetition>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_url._dirty){
                fields.push_back(std::string("url"));
                row.push_back(toSQLString(it->_url()));
            }
            
            if (it->_f_rank._dirty){
                fields.push_back(std::string("rank"));
                row.push_back(toSQLString(it->_rank()));
            }
            
            if (it->_f_pr._dirty){
                fields.push_back(std::string("pr"));
                row.push_back(toSQLString(it->_pr()));
            }
            
            if (it->_f_relevance._dirty){
                fields.push_back(std::string("relevance"));
                row.push_back(toSQLString(it->_relevance()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_search_engine_id._dirty){
                fields.push_back(std::string("search_engine_id"));
                row.push_back(toSQLString(it->_search_engine_id()));
            }
            
            if (it->_f_tracked_keyword_id._dirty){
                fields.push_back(std::string("tracked_keyword_id"));
                row.push_back(toSQLString(it->_tracked_keyword_id()));
            }
            
            if (it->_f_in_url._dirty){
                fields.push_back(std::string("in_url"));
                row.push_back(toSQLString(it->_in_url()));
            }
            
            if (it->_f_in_title._dirty){
                fields.push_back(std::string("in_title"));
                row.push_back(toSQLString(it->_in_title()));
            }
            
            if (it->_f_in_meta_desc._dirty){
                fields.push_back(std::string("in_meta_desc"));
                row.push_back(toSQLString(it->_in_meta_desc()));
            }
            
            if (it->_f_in_meta_kws._dirty){
                fields.push_back(std::string("in_meta_kws"));
                row.push_back(toSQLString(it->_in_meta_kws()));
            }
            
            if (it->_f_in_backlink._dirty){
                fields.push_back(std::string("in_backlink"));
                row.push_back(toSQLString(it->_in_backlink()));
            }
            
            if (it->_f_in_h1._dirty){
                fields.push_back(std::string("in_h1"));
                row.push_back(toSQLString(it->_in_h1()));
            }
            
            if (it->_f_in_h2._dirty){
                fields.push_back(std::string("in_h2"));
                row.push_back(toSQLString(it->_in_h2()));
            }
            
            if (it->_f_in_h3._dirty){
                fields.push_back(std::string("in_h3"));
                row.push_back(toSQLString(it->_in_h3()));
            }
            
            if (it->_f_in_body._dirty){
                fields.push_back(std::string("in_body"));
                row.push_back(toSQLString(it->_in_body()));
            }
            
            if (it->_f_in_domain._dirty){
                fields.push_back(std::string("in_domain"));
                row.push_back(toSQLString(it->_in_domain()));
            }
            
            if (it->_f_search_keyword_id._dirty){
                fields.push_back(std::string("search_keyword_id"));
                row.push_back(toSQLString(it->_search_keyword_id()));
            }
            
            if (it->_f_competition_id._dirty){
                fields.push_back(std::string("competition_id"));
                row.push_back(toSQLString(it->_competition_id()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_in_link._dirty){
                fields.push_back(std::string("in_link"));
                row.push_back(toSQLString(it->_in_link()));
            }
            
            if (it->_f_in_alt._dirty){
                fields.push_back(std::string("in_alt"));
                row.push_back(toSQLString(it->_in_alt()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("search_competitions",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_SEARCHCOMPETITION
