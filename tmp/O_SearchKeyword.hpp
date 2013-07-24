#ifndef O_SEARCHKEYWORD
#define O_SEARCHKEYWORD

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_Page.hpp"

enum EnumSearchKeywordSOURCE { SEARCHKEYWORD_SOURCE_GOOGLE_KEYWORD_TOOL = 1, SEARCHKEYWORD_SOURCE_SITE = 2, SEARCHKEYWORD_SOURCE_GOOGLE_ANALYTICS = 3, SEARCHKEYWORD_SOURCE_USER = 4, SEARCHKEYWORD_SOURCE_API = 5, SEARCHKEYWORD_SOURCE_INSTANT = 6, SEARCHKEYWORD_SOURCE_PAGE_NAV = 7, SEARCHKEYWORD_SOURCE_COMPETITOR = 8, SEARCHKEYWORD_SOURCE_ADWORDS_SITE = 9 };


namespace DMMM {

class O_SearchKeyword{
public:

    O_SearchKeyword() {}
    O_SearchKeyword(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}

O_SearchKeyword(const I_SearchKeyword& id) 
        : _f_id(id)
        {}


    std::vector<O_Page> _pages() const
    {
        T_Page table;
        return table.select(table._page_id() == _id());   
    }
    std::vector<O_Page> 
    _page_id(const T_Page::Condition& c) const
    {
        T_Page table(c);
        return table.select(table._page_id() == _id());   
    }

    const Field<I_SearchKeyword>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_SearchKeyword>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _name() const { 
        return _f_name._base; 
    }
    F_String::Base& _name() { 
        _f_name._dirty = true; 
        return _f_name._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_Float::Base& _score() const { 
        return _f_score._base; 
    }
    F_Float::Base& _score() { 
        _f_score._dirty = true; 
        return _f_score._base; 
    }
    const F_String::Base& _priority() const { 
        return _f_priority._base; 
    }
    F_String::Base& _priority() { 
        _f_priority._dirty = true; 
        return _f_priority._base; 
    }
    const F_Integer::Base& _word_tracker() const { 
        return _f_word_tracker._base; 
    }
    F_Integer::Base& _word_tracker() { 
        _f_word_tracker._dirty = true; 
        return _f_word_tracker._base; 
    }
    const F_Integer::Base& _difficulty() const { 
        return _f_difficulty._base; 
    }
    F_Integer::Base& _difficulty() { 
        _f_difficulty._dirty = true; 
        return _f_difficulty._base; 
    }
    const F_String::Base& _head_or_tail() const { 
        return _f_head_or_tail._base; 
    }
    F_String::Base& _head_or_tail() { 
        _f_head_or_tail._dirty = true; 
        return _f_head_or_tail._base; 
    }
    const F_Integer::Base& _avg_search_volume() const { 
        return _f_avg_search_volume._base; 
    }
    F_Integer::Base& _avg_search_volume() { 
        _f_avg_search_volume._dirty = true; 
        return _f_avg_search_volume._base; 
    }
    const F_Integer::Base& _last_month_search_volume() const { 
        return _f_last_month_search_volume._base; 
    }
    F_Integer::Base& _last_month_search_volume() { 
        _f_last_month_search_volume._dirty = true; 
        return _f_last_month_search_volume._base; 
    }
    const F_Integer::Base& _market_share() const { 
        return _f_market_share._base; 
    }
    F_Integer::Base& _market_share() { 
        _f_market_share._dirty = true; 
        return _f_market_share._base; 
    }
    const F_Integer::Base& _competition_scale() const { 
        return _f_competition_scale._base; 
    }
    F_Integer::Base& _competition_scale() { 
        _f_competition_scale._dirty = true; 
        return _f_competition_scale._base; 
    }
    const F_Integer::Base& _is_ranked() const { 
        return _f_is_ranked._base; 
    }
    F_Integer::Base& _is_ranked() { 
        _f_is_ranked._dirty = true; 
        return _f_is_ranked._base; 
    }
    const F_Integer::Base& _traffic() const { 
        return _f_traffic._base; 
    }
    F_Integer::Base& _traffic() { 
        _f_traffic._dirty = true; 
        return _f_traffic._base; 
    }
    const F_Integer::Base& _goal_completions() const { 
        return _f_goal_completions._base; 
    }
    F_Integer::Base& _goal_completions() { 
        _f_goal_completions._dirty = true; 
        return _f_goal_completions._base; 
    }
    const F_Integer::Base& _conversion_rate() const { 
        return _f_conversion_rate._base; 
    }
    F_Integer::Base& _conversion_rate() { 
        _f_conversion_rate._dirty = true; 
        return _f_conversion_rate._base; 
    }
    const F_String::Base& _suggestion_text() const { 
        return _f_suggestion_text._base; 
    }
    F_String::Base& _suggestion_text() { 
        _f_suggestion_text._dirty = true; 
        return _f_suggestion_text._base; 
    }
    const F_Integer::Base& _tracked() const { 
        return _f_tracked._base; 
    }
    F_Integer::Base& _tracked() { 
        _f_tracked._dirty = true; 
        return _f_tracked._base; 
    }
    const F_String::Base& _variation_type() const { 
        return _f_variation_type._base; 
    }
    F_String::Base& _variation_type() { 
        _f_variation_type._dirty = true; 
        return _f_variation_type._base; 
    }
    const Field<EnumSearchKeywordSOURCE>::Base& _source() const { 
        return _f_source._base; 
    }
    Field<EnumSearchKeywordSOURCE>::Base& _source() { 
        _f_source._dirty = true; 
        return _f_source._base; 
    }
    const F_Integer::Base& _main_ranking() const { 
        return _f_main_ranking._base; 
    }
    F_Integer::Base& _main_ranking() { 
        _f_main_ranking._dirty = true; 
        return _f_main_ranking._base; 
    }
    const F_Integer::Base& _main_competition() const { 
        return _f_main_competition._base; 
    }
    F_Integer::Base& _main_competition() { 
        _f_main_competition._dirty = true; 
        return _f_main_competition._base; 
    }
    const F_Datetime::Base& _refresh_google_suggest_date() const { 
        return _f_refresh_google_suggest_date._base; 
    }
    F_Datetime::Base& _refresh_google_suggest_date() { 
        _f_refresh_google_suggest_date._dirty = true; 
        return _f_refresh_google_suggest_date._base; 
    }
    const F_Datetime::Base& _deleted_at() const { 
        return _f_deleted_at._base; 
    }
    F_Datetime::Base& _deleted_at() { 
        _f_deleted_at._dirty = true; 
        return _f_deleted_at._base; 
    }
    const F_Integer::Base& _got_rank() const { 
        return _f_got_rank._base; 
    }
    F_Integer::Base& _got_rank() { 
        _f_got_rank._dirty = true; 
        return _f_got_rank._base; 
    }
    const F_Boolean::Base& _is_instanting() const { 
        return _f_is_instanting._base; 
    }
    F_Boolean::Base& _is_instanting() { 
        _f_is_instanting._dirty = true; 
        return _f_is_instanting._base; 
    }
    const F_Integer::Base& _instant_suggest_score() const { 
        return _f_instant_suggest_score._base; 
    }
    F_Integer::Base& _instant_suggest_score() { 
        _f_instant_suggest_score._dirty = true; 
        return _f_instant_suggest_score._base; 
    }
    const F_Datetime::Base& _instant_suggest_score_updated_at() const { 
        return _f_instant_suggest_score_updated_at._base; 
    }
    F_Datetime::Base& _instant_suggest_score_updated_at() { 
        _f_instant_suggest_score_updated_at._dirty = true; 
        return _f_instant_suggest_score_updated_at._base; 
    }
    const F_Integer::Base& _keyword_basket_id() const { 
        return _f_keyword_basket_id._base; 
    }
    F_Integer::Base& _keyword_basket_id() { 
        _f_keyword_basket_id._dirty = true; 
        return _f_keyword_basket_id._base; 
    }
    const F_Text::Base& _source_note() const { 
        return _f_source_note._base; 
    }
    F_Text::Base& _source_note() { 
        _f_source_note._dirty = true; 
        return _f_source_note._base; 
    }
    const F_Integer::Base& _yandex_volume() const { 
        return _f_yandex_volume._base; 
    }
    F_Integer::Base& _yandex_volume() { 
        _f_yandex_volume._dirty = true; 
        return _f_yandex_volume._base; 
    }
    const F_Integer::Base& _yandex_competition() const { 
        return _f_yandex_competition._base; 
    }
    F_Integer::Base& _yandex_competition() { 
        _f_yandex_competition._dirty = true; 
        return _f_yandex_competition._base; 
    }
    const F_Integer::Base& _analytic_got_traffic() const { 
        return _f_analytic_got_traffic._base; 
    }
    F_Integer::Base& _analytic_got_traffic() { 
        _f_analytic_got_traffic._dirty = true; 
        return _f_analytic_got_traffic._base; 
    }
    const F_Date::Base& _analytic_end_traffic_date() const { 
        return _f_analytic_end_traffic_date._base; 
    }
    F_Date::Base& _analytic_end_traffic_date() { 
        _f_analytic_end_traffic_date._dirty = true; 
        return _f_analytic_end_traffic_date._base; 
    }
    const F_Datetime::Base& _analytic_start_process() const { 
        return _f_analytic_start_process._base; 
    }
    F_Datetime::Base& _analytic_start_process() { 
        _f_analytic_start_process._dirty = true; 
        return _f_analytic_start_process._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        if (_f_word_tracker._dirty)
            field2Val["word_tracker"] = 
                toSQLString(_f_word_tracker._base);
        if (_f_difficulty._dirty)
            field2Val["difficulty"] = 
                toSQLString(_f_difficulty._base);
        if (_f_head_or_tail._dirty)
            field2Val["head_or_tail"] = 
                toSQLString(_f_head_or_tail._base);
        if (_f_avg_search_volume._dirty)
            field2Val["avg_search_volume"] = 
                toSQLString(_f_avg_search_volume._base);
        if (_f_last_month_search_volume._dirty)
            field2Val["last_month_search_volume"] = 
                toSQLString(_f_last_month_search_volume._base);
        if (_f_market_share._dirty)
            field2Val["market_share"] = 
                toSQLString(_f_market_share._base);
        if (_f_competition_scale._dirty)
            field2Val["competition_scale"] = 
                toSQLString(_f_competition_scale._base);
        if (_f_is_ranked._dirty)
            field2Val["is_ranked"] = 
                toSQLString(_f_is_ranked._base);
        if (_f_traffic._dirty)
            field2Val["traffic"] = 
                toSQLString(_f_traffic._base);
        if (_f_goal_completions._dirty)
            field2Val["goal_completions"] = 
                toSQLString(_f_goal_completions._base);
        if (_f_conversion_rate._dirty)
            field2Val["conversion_rate"] = 
                toSQLString(_f_conversion_rate._base);
        if (_f_suggestion_text._dirty)
            field2Val["suggestion_text"] = 
                toSQLString(_f_suggestion_text._base);
        if (_f_tracked._dirty)
            field2Val["tracked"] = 
                toSQLString(_f_tracked._base);
        if (_f_variation_type._dirty)
            field2Val["variation_type"] = 
                toSQLString(_f_variation_type._base);
        if (_f_source._dirty)
            field2Val["source"] = 
                toSQLString(_f_source._base);
        if (_f_main_ranking._dirty)
            field2Val["main_ranking"] = 
                toSQLString(_f_main_ranking._base);
        if (_f_main_competition._dirty)
            field2Val["main_competition"] = 
                toSQLString(_f_main_competition._base);
        if (_f_refresh_google_suggest_date._dirty)
            field2Val["refresh_google_suggest_date"] = 
                toSQLString(_f_refresh_google_suggest_date._base);
        if (_f_deleted_at._dirty)
            field2Val["deleted_at"] = 
                toSQLString(_f_deleted_at._base);
        if (_f_got_rank._dirty)
            field2Val["got_rank"] = 
                toSQLString(_f_got_rank._base);
        if (_f_is_instanting._dirty)
            field2Val["is_instanting"] = 
                toSQLString(_f_is_instanting._base);
        if (_f_instant_suggest_score._dirty)
            field2Val["instant_suggest_score"] = 
                toSQLString(_f_instant_suggest_score._base);
        if (_f_instant_suggest_score_updated_at._dirty)
            field2Val["instant_suggest_score_updated_at"] = 
                toSQLString(_f_instant_suggest_score_updated_at._base);
        if (_f_keyword_basket_id._dirty)
            field2Val["keyword_basket_id"] = 
                toSQLString(_f_keyword_basket_id._base);
        if (_f_source_note._dirty)
            field2Val["source_note"] = 
                toSQLString(_f_source_note._base);
        if (_f_yandex_volume._dirty)
            field2Val["yandex_volume"] = 
                toSQLString(_f_yandex_volume._base);
        if (_f_yandex_competition._dirty)
            field2Val["yandex_competition"] = 
                toSQLString(_f_yandex_competition._base);
        if (_f_analytic_got_traffic._dirty)
            field2Val["analytic_got_traffic"] = 
                toSQLString(_f_analytic_got_traffic._base);
        if (_f_analytic_end_traffic_date._dirty)
            field2Val["analytic_end_traffic_date"] = 
                toSQLString(_f_analytic_end_traffic_date._base);
        if (_f_analytic_start_process._dirty)
            field2Val["analytic_start_process"] = 
                toSQLString(_f_analytic_start_process._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("search_keywords", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_account_id._dirty = false;
            _f_score._dirty = false;
            _f_priority._dirty = false;
            _f_word_tracker._dirty = false;
            _f_difficulty._dirty = false;
            _f_head_or_tail._dirty = false;
            _f_avg_search_volume._dirty = false;
            _f_last_month_search_volume._dirty = false;
            _f_market_share._dirty = false;
            _f_competition_scale._dirty = false;
            _f_is_ranked._dirty = false;
            _f_traffic._dirty = false;
            _f_goal_completions._dirty = false;
            _f_conversion_rate._dirty = false;
            _f_suggestion_text._dirty = false;
            _f_tracked._dirty = false;
            _f_variation_type._dirty = false;
            _f_source._dirty = false;
            _f_main_ranking._dirty = false;
            _f_main_competition._dirty = false;
            _f_refresh_google_suggest_date._dirty = false;
            _f_deleted_at._dirty = false;
            _f_got_rank._dirty = false;
            _f_is_instanting._dirty = false;
            _f_instant_suggest_score._dirty = false;
            _f_instant_suggest_score_updated_at._dirty = false;
            _f_keyword_basket_id._dirty = false;
            _f_source_note._dirty = false;
            _f_yandex_volume._dirty = false;
            _f_yandex_competition._dirty = false;
            _f_analytic_got_traffic._dirty = false;
            _f_analytic_end_traffic_date._dirty = false;
            _f_analytic_start_process._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        if (_f_word_tracker._dirty)
            field2Val["word_tracker"] = 
                toSQLString(_f_word_tracker._base);
        if (_f_difficulty._dirty)
            field2Val["difficulty"] = 
                toSQLString(_f_difficulty._base);
        if (_f_head_or_tail._dirty)
            field2Val["head_or_tail"] = 
                toSQLString(_f_head_or_tail._base);
        if (_f_avg_search_volume._dirty)
            field2Val["avg_search_volume"] = 
                toSQLString(_f_avg_search_volume._base);
        if (_f_last_month_search_volume._dirty)
            field2Val["last_month_search_volume"] = 
                toSQLString(_f_last_month_search_volume._base);
        if (_f_market_share._dirty)
            field2Val["market_share"] = 
                toSQLString(_f_market_share._base);
        if (_f_competition_scale._dirty)
            field2Val["competition_scale"] = 
                toSQLString(_f_competition_scale._base);
        if (_f_is_ranked._dirty)
            field2Val["is_ranked"] = 
                toSQLString(_f_is_ranked._base);
        if (_f_traffic._dirty)
            field2Val["traffic"] = 
                toSQLString(_f_traffic._base);
        if (_f_goal_completions._dirty)
            field2Val["goal_completions"] = 
                toSQLString(_f_goal_completions._base);
        if (_f_conversion_rate._dirty)
            field2Val["conversion_rate"] = 
                toSQLString(_f_conversion_rate._base);
        if (_f_suggestion_text._dirty)
            field2Val["suggestion_text"] = 
                toSQLString(_f_suggestion_text._base);
        if (_f_tracked._dirty)
            field2Val["tracked"] = 
                toSQLString(_f_tracked._base);
        if (_f_variation_type._dirty)
            field2Val["variation_type"] = 
                toSQLString(_f_variation_type._base);
        if (_f_source._dirty)
            field2Val["source"] = 
                toSQLString(_f_source._base);
        if (_f_main_ranking._dirty)
            field2Val["main_ranking"] = 
                toSQLString(_f_main_ranking._base);
        if (_f_main_competition._dirty)
            field2Val["main_competition"] = 
                toSQLString(_f_main_competition._base);
        if (_f_refresh_google_suggest_date._dirty)
            field2Val["refresh_google_suggest_date"] = 
                toSQLString(_f_refresh_google_suggest_date._base);
        if (_f_deleted_at._dirty)
            field2Val["deleted_at"] = 
                toSQLString(_f_deleted_at._base);
        if (_f_got_rank._dirty)
            field2Val["got_rank"] = 
                toSQLString(_f_got_rank._base);
        if (_f_is_instanting._dirty)
            field2Val["is_instanting"] = 
                toSQLString(_f_is_instanting._base);
        if (_f_instant_suggest_score._dirty)
            field2Val["instant_suggest_score"] = 
                toSQLString(_f_instant_suggest_score._base);
        if (_f_instant_suggest_score_updated_at._dirty)
            field2Val["instant_suggest_score_updated_at"] = 
                toSQLString(_f_instant_suggest_score_updated_at._base);
        if (_f_keyword_basket_id._dirty)
            field2Val["keyword_basket_id"] = 
                toSQLString(_f_keyword_basket_id._base);
        if (_f_source_note._dirty)
            field2Val["source_note"] = 
                toSQLString(_f_source_note._base);
        if (_f_yandex_volume._dirty)
            field2Val["yandex_volume"] = 
                toSQLString(_f_yandex_volume._base);
        if (_f_yandex_competition._dirty)
            field2Val["yandex_competition"] = 
                toSQLString(_f_yandex_competition._base);
        if (_f_analytic_got_traffic._dirty)
            field2Val["analytic_got_traffic"] = 
                toSQLString(_f_analytic_got_traffic._base);
        if (_f_analytic_end_traffic_date._dirty)
            field2Val["analytic_end_traffic_date"] = 
                toSQLString(_f_analytic_end_traffic_date._base);
        if (_f_analytic_start_process._dirty)
            field2Val["analytic_start_process"] = 
                toSQLString(_f_analytic_start_process._base);
        
        if (DBFace::instance()->
                insert("search_keywords", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_account_id._dirty = false;
            _f_score._dirty = false;
            _f_priority._dirty = false;
            _f_word_tracker._dirty = false;
            _f_difficulty._dirty = false;
            _f_head_or_tail._dirty = false;
            _f_avg_search_volume._dirty = false;
            _f_last_month_search_volume._dirty = false;
            _f_market_share._dirty = false;
            _f_competition_scale._dirty = false;
            _f_is_ranked._dirty = false;
            _f_traffic._dirty = false;
            _f_goal_completions._dirty = false;
            _f_conversion_rate._dirty = false;
            _f_suggestion_text._dirty = false;
            _f_tracked._dirty = false;
            _f_variation_type._dirty = false;
            _f_source._dirty = false;
            _f_main_ranking._dirty = false;
            _f_main_competition._dirty = false;
            _f_refresh_google_suggest_date._dirty = false;
            _f_deleted_at._dirty = false;
            _f_got_rank._dirty = false;
            _f_is_instanting._dirty = false;
            _f_instant_suggest_score._dirty = false;
            _f_instant_suggest_score_updated_at._dirty = false;
            _f_keyword_basket_id._dirty = false;
            _f_source_note._dirty = false;
            _f_yandex_volume._dirty = false;
            _f_yandex_competition._dirty = false;
            _f_analytic_got_traffic._dirty = false;
            _f_analytic_end_traffic_date._dirty = false;
            _f_analytic_start_process._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_SearchKeyword> _f_id;
    F_String _f_name;
    Field<I_account_id> _f_account_id;
    F_Float _f_score;
    F_String _f_priority;
    F_Integer _f_word_tracker;
    F_Integer _f_difficulty;
    F_String _f_head_or_tail;
    F_Integer _f_avg_search_volume;
    F_Integer _f_last_month_search_volume;
    F_Integer _f_market_share;
    F_Integer _f_competition_scale;
    F_Integer _f_is_ranked;
    F_Integer _f_traffic;
    F_Integer _f_goal_completions;
    F_Integer _f_conversion_rate;
    F_String _f_suggestion_text;
    F_Integer _f_tracked;
    F_String _f_variation_type;
    Field<EnumSearchKeywordSOURCE> _f_source;
    F_Integer _f_main_ranking;
    F_Integer _f_main_competition;
    F_Datetime _f_refresh_google_suggest_date;
    F_Datetime _f_deleted_at;
    F_Integer _f_got_rank;
    F_Boolean _f_is_instanting;
    F_Integer _f_instant_suggest_score;
    F_Datetime _f_instant_suggest_score_updated_at;
    F_Integer _f_keyword_basket_id;
    F_Text _f_source_note;
    F_Integer _f_yandex_volume;
    F_Integer _f_yandex_competition;
    F_Integer _f_analytic_got_traffic;
    F_Date _f_analytic_end_traffic_date;
    F_Datetime _f_analytic_start_process;

    friend class T_SearchKeyword;
};

} //namespace DMMM
#endif //O_SEARCHKEYWORD
