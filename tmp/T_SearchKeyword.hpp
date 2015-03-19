
#ifndef T_SEARCHKEYWORD
#define T_SEARCHKEYWORD
#include "O_SearchKeyword.hpp"

namespace DMMM {

class T_SearchKeyword{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_SearchKeyword() 
    {
        _tables.push_back("search_keywords");
    }
    T_SearchKeyword(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("search_keywords");
    }

 

    T_SearchKeyword(const I_Account& parentId)
    {
        _tables.push_back("search_keywords");
        
        _constraint._cond = "(search_keywords.account_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "search_keywords.id";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef Field<I_SearchKeyword>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "search_keywords.name";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "search_keywords.account_id";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_score{
        E_score() 
        {  
            _field = "search_keywords.score";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_score _score(){ 
        return E_score();
    }
    struct E_priority{
        E_priority() 
        {  
            _field = "search_keywords.priority";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_priority _priority(){ 
        return E_priority();
    }
    struct E_word_tracker{
        E_word_tracker() 
        {  
            _field = "search_keywords.word_tracker";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_word_tracker _word_tracker(){ 
        return E_word_tracker();
    }
    struct E_difficulty{
        E_difficulty() 
        {  
            _field = "search_keywords.difficulty";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_difficulty _difficulty(){ 
        return E_difficulty();
    }
    struct E_head_or_tail{
        E_head_or_tail() 
        {  
            _field = "search_keywords.head_or_tail";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_head_or_tail _head_or_tail(){ 
        return E_head_or_tail();
    }
    struct E_avg_search_volume{
        E_avg_search_volume() 
        {  
            _field = "search_keywords.avg_search_volume";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_avg_search_volume _avg_search_volume(){ 
        return E_avg_search_volume();
    }
    struct E_last_month_search_volume{
        E_last_month_search_volume() 
        {  
            _field = "search_keywords.last_month_search_volume";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_last_month_search_volume _last_month_search_volume(){ 
        return E_last_month_search_volume();
    }
    struct E_market_share{
        E_market_share() 
        {  
            _field = "search_keywords.market_share";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_market_share _market_share(){ 
        return E_market_share();
    }
    struct E_competition_scale{
        E_competition_scale() 
        {  
            _field = "search_keywords.competition_scale";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_competition_scale _competition_scale(){ 
        return E_competition_scale();
    }
    struct E_is_ranked{
        E_is_ranked() 
        {  
            _field = "search_keywords.is_ranked";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_ranked _is_ranked(){ 
        return E_is_ranked();
    }
    struct E_traffic{
        E_traffic() 
        {  
            _field = "search_keywords.traffic";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_traffic _traffic(){ 
        return E_traffic();
    }
    struct E_goal_completions{
        E_goal_completions() 
        {  
            _field = "search_keywords.goal_completions";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_goal_completions _goal_completions(){ 
        return E_goal_completions();
    }
    struct E_conversion_rate{
        E_conversion_rate() 
        {  
            _field = "search_keywords.conversion_rate";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_conversion_rate _conversion_rate(){ 
        return E_conversion_rate();
    }
    struct E_suggestion_text{
        E_suggestion_text() 
        {  
            _field = "search_keywords.suggestion_text";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_suggestion_text _suggestion_text(){ 
        return E_suggestion_text();
    }
    struct E_tracked{
        E_tracked() 
        {  
            _field = "search_keywords.tracked";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_tracked _tracked(){ 
        return E_tracked();
    }
    struct E_variation_type{
        E_variation_type() 
        {  
            _field = "search_keywords.variation_type";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_variation_type _variation_type(){ 
        return E_variation_type();
    }
    struct E_source{
        E_source() 
        {  
            _field = "search_keywords.source";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef Field<EnumSearchKeywordSOURCE>::Base ComparerType;
    };

    static E_source _source(){ 
        return E_source();
    }
    struct E_main_ranking{
        E_main_ranking() 
        {  
            _field = "search_keywords.main_ranking";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_main_ranking _main_ranking(){ 
        return E_main_ranking();
    }
    struct E_main_competition{
        E_main_competition() 
        {  
            _field = "search_keywords.main_competition";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_main_competition _main_competition(){ 
        return E_main_competition();
    }
    struct E_refresh_google_suggest_date{
        E_refresh_google_suggest_date() 
        {  
            _field = "search_keywords.refresh_google_suggest_date";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_refresh_google_suggest_date _refresh_google_suggest_date(){ 
        return E_refresh_google_suggest_date();
    }
    struct E_deleted_at{
        E_deleted_at() 
        {  
            _field = "search_keywords.deleted_at";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_deleted_at _deleted_at(){ 
        return E_deleted_at();
    }
    struct E_got_rank{
        E_got_rank() 
        {  
            _field = "search_keywords.got_rank";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_got_rank _got_rank(){ 
        return E_got_rank();
    }
    struct E_is_instanting{
        E_is_instanting() 
        {  
            _field = "search_keywords.is_instanting";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_is_instanting _is_instanting(){ 
        return E_is_instanting();
    }
    struct E_instant_suggest_score{
        E_instant_suggest_score() 
        {  
            _field = "search_keywords.instant_suggest_score";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_instant_suggest_score _instant_suggest_score(){ 
        return E_instant_suggest_score();
    }
    struct E_instant_suggest_score_updated_at{
        E_instant_suggest_score_updated_at() 
        {  
            _field = "search_keywords.instant_suggest_score_updated_at";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_instant_suggest_score_updated_at _instant_suggest_score_updated_at(){ 
        return E_instant_suggest_score_updated_at();
    }
    struct E_keyword_basket_id{
        E_keyword_basket_id() 
        {  
            _field = "search_keywords.keyword_basket_id";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_keyword_basket_id _keyword_basket_id(){ 
        return E_keyword_basket_id();
    }
    struct E_source_note{
        E_source_note() 
        {  
            _field = "search_keywords.source_note";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_source_note _source_note(){ 
        return E_source_note();
    }
    struct E_yandex_volume{
        E_yandex_volume() 
        {  
            _field = "search_keywords.yandex_volume";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_yandex_volume _yandex_volume(){ 
        return E_yandex_volume();
    }
    struct E_yandex_competition{
        E_yandex_competition() 
        {  
            _field = "search_keywords.yandex_competition";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_yandex_competition _yandex_competition(){ 
        return E_yandex_competition();
    }
    struct E_analytic_got_traffic{
        E_analytic_got_traffic() 
        {  
            _field = "search_keywords.analytic_got_traffic";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_analytic_got_traffic _analytic_got_traffic(){ 
        return E_analytic_got_traffic();
    }
    struct E_analytic_end_traffic_date{
        E_analytic_end_traffic_date() 
        {  
            _field = "search_keywords.analytic_end_traffic_date";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Date::Base ComparerType;
    };

    static E_analytic_end_traffic_date _analytic_end_traffic_date(){ 
        return E_analytic_end_traffic_date();
    }
    struct E_analytic_start_process{
        E_analytic_start_process() 
        {  
            _field = "search_keywords.analytic_start_process";
        }
        std::string _field;
        typedef T_SearchKeyword::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_analytic_start_process _analytic_start_process(){ 
        return E_analytic_start_process();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("account_id");
        ret.push_back("score");
        ret.push_back("priority");
        ret.push_back("word_tracker");
        ret.push_back("difficulty");
        ret.push_back("head_or_tail");
        ret.push_back("avg_search_volume");
        ret.push_back("last_month_search_volume");
        ret.push_back("market_share");
        ret.push_back("competition_scale");
        ret.push_back("is_ranked");
        ret.push_back("traffic");
        ret.push_back("goal_completions");
        ret.push_back("conversion_rate");
        ret.push_back("suggestion_text");
        ret.push_back("tracked");
        ret.push_back("variation_type");
        ret.push_back("source");
        ret.push_back("main_ranking");
        ret.push_back("main_competition");
        ret.push_back("refresh_google_suggest_date");
        ret.push_back("deleted_at");
        ret.push_back("got_rank");
        ret.push_back("is_instanting");
        ret.push_back("instant_suggest_score");
        ret.push_back("instant_suggest_score_updated_at");
        ret.push_back("keyword_basket_id");
        ret.push_back("source_note");
        ret.push_back("yandex_volume");
        ret.push_back("yandex_competition");
        ret.push_back("analytic_got_traffic");
        ret.push_back("analytic_end_traffic_date");
        ret.push_back("analytic_start_process");
        return ret;
    }

    std::vector<O_SearchKeyword> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_SearchKeyword> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_SearchKeyword>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_score._base =
                UTILS::fromString<F_Float::Base>(res[i]["score"]);
            ret[i]._f_priority._base =
                UTILS::fromString<F_String::Base>(res[i]["priority"]);
            ret[i]._f_word_tracker._base =
                UTILS::fromString<F_Integer::Base>(res[i]["word_tracker"]);
            ret[i]._f_difficulty._base =
                UTILS::fromString<F_Integer::Base>(res[i]["difficulty"]);
            ret[i]._f_head_or_tail._base =
                UTILS::fromString<F_String::Base>(res[i]["head_or_tail"]);
            ret[i]._f_avg_search_volume._base =
                UTILS::fromString<F_Integer::Base>(res[i]["avg_search_volume"]);
            ret[i]._f_last_month_search_volume._base =
                UTILS::fromString<F_Integer::Base>(res[i]["last_month_search_volume"]);
            ret[i]._f_market_share._base =
                UTILS::fromString<F_Integer::Base>(res[i]["market_share"]);
            ret[i]._f_competition_scale._base =
                UTILS::fromString<F_Integer::Base>(res[i]["competition_scale"]);
            ret[i]._f_is_ranked._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_ranked"]);
            ret[i]._f_traffic._base =
                UTILS::fromString<F_Integer::Base>(res[i]["traffic"]);
            ret[i]._f_goal_completions._base =
                UTILS::fromString<F_Integer::Base>(res[i]["goal_completions"]);
            ret[i]._f_conversion_rate._base =
                UTILS::fromString<F_Integer::Base>(res[i]["conversion_rate"]);
            ret[i]._f_suggestion_text._base =
                UTILS::fromString<F_String::Base>(res[i]["suggestion_text"]);
            ret[i]._f_tracked._base =
                UTILS::fromString<F_Integer::Base>(res[i]["tracked"]);
            ret[i]._f_variation_type._base =
                UTILS::fromString<F_String::Base>(res[i]["variation_type"]);
            ret[i]._f_source._base =
                (Field<EnumSearchKeywordSOURCE>::Base)UTILS::fromString<size_t>(res[i]["source"]);
            ret[i]._f_main_ranking._base =
                UTILS::fromString<F_Integer::Base>(res[i]["main_ranking"]);
            ret[i]._f_main_competition._base =
                UTILS::fromString<F_Integer::Base>(res[i]["main_competition"]);
            ret[i]._f_refresh_google_suggest_date._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["refresh_google_suggest_date"]);
            ret[i]._f_deleted_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["deleted_at"]);
            ret[i]._f_got_rank._base =
                UTILS::fromString<F_Integer::Base>(res[i]["got_rank"]);
            ret[i]._f_is_instanting._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["is_instanting"]);
            ret[i]._f_instant_suggest_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["instant_suggest_score"]);
            ret[i]._f_instant_suggest_score_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["instant_suggest_score_updated_at"]);
            ret[i]._f_keyword_basket_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["keyword_basket_id"]);
            ret[i]._f_source_note._base =
                UTILS::fromString<F_Text::Base>(res[i]["source_note"]);
            ret[i]._f_yandex_volume._base =
                UTILS::fromString<F_Integer::Base>(res[i]["yandex_volume"]);
            ret[i]._f_yandex_competition._base =
                UTILS::fromString<F_Integer::Base>(res[i]["yandex_competition"]);
            ret[i]._f_analytic_got_traffic._base =
                UTILS::fromString<F_Integer::Base>(res[i]["analytic_got_traffic"]);
            ret[i]._f_analytic_end_traffic_date._base =
                UTILS::fromString<F_Date::Base>(res[i]["analytic_end_traffic_date"]);
            ret[i]._f_analytic_start_process._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["analytic_start_process"]);
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


    std::vector<O_SearchKeyword> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_SearchKeyword> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_SearchKeyword> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_SearchKeyword, bool> select(const I_SearchKeyword& id){
        return first(E_id() == id);
    }

    std::pair<O_SearchKeyword, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_SearchKeyword> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_SearchKeyword(), false);
    }

    std::pair<O_SearchKeyword, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_SearchKeyword>::const_iterator begin,
                         std::vector<O_SearchKeyword>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("score"));
        
        fields.push_back(std::string("priority"));
        
        fields.push_back(std::string("word_tracker"));
        
        fields.push_back(std::string("difficulty"));
        
        fields.push_back(std::string("head_or_tail"));
        
        fields.push_back(std::string("avg_search_volume"));
        
        fields.push_back(std::string("last_month_search_volume"));
        
        fields.push_back(std::string("market_share"));
        
        fields.push_back(std::string("competition_scale"));
        
        fields.push_back(std::string("is_ranked"));
        
        fields.push_back(std::string("traffic"));
        
        fields.push_back(std::string("goal_completions"));
        
        fields.push_back(std::string("conversion_rate"));
        
        fields.push_back(std::string("suggestion_text"));
        
        fields.push_back(std::string("tracked"));
        
        fields.push_back(std::string("variation_type"));
        
        fields.push_back(std::string("source"));
        
        fields.push_back(std::string("main_ranking"));
        
        fields.push_back(std::string("main_competition"));
        
        fields.push_back(std::string("refresh_google_suggest_date"));
        
        fields.push_back(std::string("deleted_at"));
        
        fields.push_back(std::string("got_rank"));
        
        fields.push_back(std::string("is_instanting"));
        
        fields.push_back(std::string("instant_suggest_score"));
        
        fields.push_back(std::string("instant_suggest_score_updated_at"));
        
        fields.push_back(std::string("keyword_basket_id"));
        
        fields.push_back(std::string("source_note"));
        
        fields.push_back(std::string("yandex_volume"));
        
        fields.push_back(std::string("yandex_competition"));
        
        fields.push_back(std::string("analytic_got_traffic"));
        
        fields.push_back(std::string("analytic_end_traffic_date"));
        
        fields.push_back(std::string("analytic_start_process"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_SearchKeyword& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._score()));
            
            row.push_back(toSQLString(r._priority()));
            
            row.push_back(toSQLString(r._word_tracker()));
            
            row.push_back(toSQLString(r._difficulty()));
            
            row.push_back(toSQLString(r._head_or_tail()));
            
            row.push_back(toSQLString(r._avg_search_volume()));
            
            row.push_back(toSQLString(r._last_month_search_volume()));
            
            row.push_back(toSQLString(r._market_share()));
            
            row.push_back(toSQLString(r._competition_scale()));
            
            row.push_back(toSQLString(r._is_ranked()));
            
            row.push_back(toSQLString(r._traffic()));
            
            row.push_back(toSQLString(r._goal_completions()));
            
            row.push_back(toSQLString(r._conversion_rate()));
            
            row.push_back(toSQLString(r._suggestion_text()));
            
            row.push_back(toSQLString(r._tracked()));
            
            row.push_back(toSQLString(r._variation_type()));
            
            row.push_back(toSQLString(r._source()));
            
            row.push_back(toSQLString(r._main_ranking()));
            
            row.push_back(toSQLString(r._main_competition()));
            
            row.push_back(toSQLString(r._refresh_google_suggest_date()));
            
            row.push_back(toSQLString(r._deleted_at()));
            
            row.push_back(toSQLString(r._got_rank()));
            
            row.push_back(toSQLString(r._is_instanting()));
            
            row.push_back(toSQLString(r._instant_suggest_score()));
            
            row.push_back(toSQLString(r._instant_suggest_score_updated_at()));
            
            row.push_back(toSQLString(r._keyword_basket_id()));
            
            row.push_back(toSQLString(r._source_note()));
            
            row.push_back(toSQLString(r._yandex_volume()));
            
            row.push_back(toSQLString(r._yandex_competition()));
            
            row.push_back(toSQLString(r._analytic_got_traffic()));
            
            row.push_back(toSQLString(r._analytic_end_traffic_date()));
            
            row.push_back(toSQLString(r._analytic_start_process()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("search_keywords",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_SearchKeyword>::const_iterator begin,
                           std::vector<O_SearchKeyword>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_SearchKeyword>::const_iterator it = begin; 
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
            
            if (it->_f_score._dirty){
                fields.push_back(std::string("score"));
                row.push_back(toSQLString(it->_score()));
            }
            
            if (it->_f_priority._dirty){
                fields.push_back(std::string("priority"));
                row.push_back(toSQLString(it->_priority()));
            }
            
            if (it->_f_word_tracker._dirty){
                fields.push_back(std::string("word_tracker"));
                row.push_back(toSQLString(it->_word_tracker()));
            }
            
            if (it->_f_difficulty._dirty){
                fields.push_back(std::string("difficulty"));
                row.push_back(toSQLString(it->_difficulty()));
            }
            
            if (it->_f_head_or_tail._dirty){
                fields.push_back(std::string("head_or_tail"));
                row.push_back(toSQLString(it->_head_or_tail()));
            }
            
            if (it->_f_avg_search_volume._dirty){
                fields.push_back(std::string("avg_search_volume"));
                row.push_back(toSQLString(it->_avg_search_volume()));
            }
            
            if (it->_f_last_month_search_volume._dirty){
                fields.push_back(std::string("last_month_search_volume"));
                row.push_back(toSQLString(it->_last_month_search_volume()));
            }
            
            if (it->_f_market_share._dirty){
                fields.push_back(std::string("market_share"));
                row.push_back(toSQLString(it->_market_share()));
            }
            
            if (it->_f_competition_scale._dirty){
                fields.push_back(std::string("competition_scale"));
                row.push_back(toSQLString(it->_competition_scale()));
            }
            
            if (it->_f_is_ranked._dirty){
                fields.push_back(std::string("is_ranked"));
                row.push_back(toSQLString(it->_is_ranked()));
            }
            
            if (it->_f_traffic._dirty){
                fields.push_back(std::string("traffic"));
                row.push_back(toSQLString(it->_traffic()));
            }
            
            if (it->_f_goal_completions._dirty){
                fields.push_back(std::string("goal_completions"));
                row.push_back(toSQLString(it->_goal_completions()));
            }
            
            if (it->_f_conversion_rate._dirty){
                fields.push_back(std::string("conversion_rate"));
                row.push_back(toSQLString(it->_conversion_rate()));
            }
            
            if (it->_f_suggestion_text._dirty){
                fields.push_back(std::string("suggestion_text"));
                row.push_back(toSQLString(it->_suggestion_text()));
            }
            
            if (it->_f_tracked._dirty){
                fields.push_back(std::string("tracked"));
                row.push_back(toSQLString(it->_tracked()));
            }
            
            if (it->_f_variation_type._dirty){
                fields.push_back(std::string("variation_type"));
                row.push_back(toSQLString(it->_variation_type()));
            }
            
            if (it->_f_source._dirty){
                fields.push_back(std::string("source"));
                row.push_back(toSQLString(it->_source()));
            }
            
            if (it->_f_main_ranking._dirty){
                fields.push_back(std::string("main_ranking"));
                row.push_back(toSQLString(it->_main_ranking()));
            }
            
            if (it->_f_main_competition._dirty){
                fields.push_back(std::string("main_competition"));
                row.push_back(toSQLString(it->_main_competition()));
            }
            
            if (it->_f_refresh_google_suggest_date._dirty){
                fields.push_back(std::string("refresh_google_suggest_date"));
                row.push_back(toSQLString(it->_refresh_google_suggest_date()));
            }
            
            if (it->_f_deleted_at._dirty){
                fields.push_back(std::string("deleted_at"));
                row.push_back(toSQLString(it->_deleted_at()));
            }
            
            if (it->_f_got_rank._dirty){
                fields.push_back(std::string("got_rank"));
                row.push_back(toSQLString(it->_got_rank()));
            }
            
            if (it->_f_is_instanting._dirty){
                fields.push_back(std::string("is_instanting"));
                row.push_back(toSQLString(it->_is_instanting()));
            }
            
            if (it->_f_instant_suggest_score._dirty){
                fields.push_back(std::string("instant_suggest_score"));
                row.push_back(toSQLString(it->_instant_suggest_score()));
            }
            
            if (it->_f_instant_suggest_score_updated_at._dirty){
                fields.push_back(std::string("instant_suggest_score_updated_at"));
                row.push_back(toSQLString(it->_instant_suggest_score_updated_at()));
            }
            
            if (it->_f_keyword_basket_id._dirty){
                fields.push_back(std::string("keyword_basket_id"));
                row.push_back(toSQLString(it->_keyword_basket_id()));
            }
            
            if (it->_f_source_note._dirty){
                fields.push_back(std::string("source_note"));
                row.push_back(toSQLString(it->_source_note()));
            }
            
            if (it->_f_yandex_volume._dirty){
                fields.push_back(std::string("yandex_volume"));
                row.push_back(toSQLString(it->_yandex_volume()));
            }
            
            if (it->_f_yandex_competition._dirty){
                fields.push_back(std::string("yandex_competition"));
                row.push_back(toSQLString(it->_yandex_competition()));
            }
            
            if (it->_f_analytic_got_traffic._dirty){
                fields.push_back(std::string("analytic_got_traffic"));
                row.push_back(toSQLString(it->_analytic_got_traffic()));
            }
            
            if (it->_f_analytic_end_traffic_date._dirty){
                fields.push_back(std::string("analytic_end_traffic_date"));
                row.push_back(toSQLString(it->_analytic_end_traffic_date()));
            }
            
            if (it->_f_analytic_start_process._dirty){
                fields.push_back(std::string("analytic_start_process"));
                row.push_back(toSQLString(it->_analytic_start_process()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("search_keywords",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_SEARCHKEYWORD
