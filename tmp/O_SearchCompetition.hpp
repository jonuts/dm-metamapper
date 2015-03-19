#ifndef O_SEARCHCOMPETITION
#define O_SEARCHCOMPETITION

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_SearchCompetition{
public:

    O_SearchCompetition() {}
    O_SearchCompetition(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_SearchCompetition(const I_SearchKeyword& parent_id) 
        : _f_search_keyword_id(parent_id)
        {}
    O_SearchCompetition(const I_Competition& parent_id) 
        : _f_competition_id(parent_id)
        {}

O_SearchCompetition(const I_SearchCompetition& id) 
        : _f_id(id)
        {}


    const Field<I_SearchCompetition>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_SearchCompetition>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _url() const { 
        return _f_url._base; 
    }
    F_String::Base& _url() { 
        _f_url._dirty = true; 
        return _f_url._base; 
    }
    const F_Integer::Base& _rank() const { 
        return _f_rank._base; 
    }
    F_Integer::Base& _rank() { 
        _f_rank._dirty = true; 
        return _f_rank._base; 
    }
    const F_Integer::Base& _pr() const { 
        return _f_pr._base; 
    }
    F_Integer::Base& _pr() { 
        _f_pr._dirty = true; 
        return _f_pr._base; 
    }
    const F_Integer::Base& _relevance() const { 
        return _f_relevance._base; 
    }
    F_Integer::Base& _relevance() { 
        _f_relevance._dirty = true; 
        return _f_relevance._base; 
    }
    const F_Datetime::Base& _created_at() const { 
        return _f_created_at._base; 
    }
    F_Datetime::Base& _created_at() { 
        _f_created_at._dirty = true; 
        return _f_created_at._base; 
    }
    const F_Integer::Base& _search_engine_id() const { 
        return _f_search_engine_id._base; 
    }
    F_Integer::Base& _search_engine_id() { 
        _f_search_engine_id._dirty = true; 
        return _f_search_engine_id._base; 
    }
    const F_Integer::Base& _tracked_keyword_id() const { 
        return _f_tracked_keyword_id._base; 
    }
    F_Integer::Base& _tracked_keyword_id() { 
        _f_tracked_keyword_id._dirty = true; 
        return _f_tracked_keyword_id._base; 
    }
    const F_Integer::Base& _in_url() const { 
        return _f_in_url._base; 
    }
    F_Integer::Base& _in_url() { 
        _f_in_url._dirty = true; 
        return _f_in_url._base; 
    }
    const F_Integer::Base& _in_title() const { 
        return _f_in_title._base; 
    }
    F_Integer::Base& _in_title() { 
        _f_in_title._dirty = true; 
        return _f_in_title._base; 
    }
    const F_Integer::Base& _in_meta_desc() const { 
        return _f_in_meta_desc._base; 
    }
    F_Integer::Base& _in_meta_desc() { 
        _f_in_meta_desc._dirty = true; 
        return _f_in_meta_desc._base; 
    }
    const F_Integer::Base& _in_meta_kws() const { 
        return _f_in_meta_kws._base; 
    }
    F_Integer::Base& _in_meta_kws() { 
        _f_in_meta_kws._dirty = true; 
        return _f_in_meta_kws._base; 
    }
    const F_Integer::Base& _in_backlink() const { 
        return _f_in_backlink._base; 
    }
    F_Integer::Base& _in_backlink() { 
        _f_in_backlink._dirty = true; 
        return _f_in_backlink._base; 
    }
    const F_Integer::Base& _in_h1() const { 
        return _f_in_h1._base; 
    }
    F_Integer::Base& _in_h1() { 
        _f_in_h1._dirty = true; 
        return _f_in_h1._base; 
    }
    const F_Integer::Base& _in_h2() const { 
        return _f_in_h2._base; 
    }
    F_Integer::Base& _in_h2() { 
        _f_in_h2._dirty = true; 
        return _f_in_h2._base; 
    }
    const F_Integer::Base& _in_h3() const { 
        return _f_in_h3._base; 
    }
    F_Integer::Base& _in_h3() { 
        _f_in_h3._dirty = true; 
        return _f_in_h3._base; 
    }
    const F_Integer::Base& _in_body() const { 
        return _f_in_body._base; 
    }
    F_Integer::Base& _in_body() { 
        _f_in_body._dirty = true; 
        return _f_in_body._base; 
    }
    const F_Integer::Base& _in_domain() const { 
        return _f_in_domain._base; 
    }
    F_Integer::Base& _in_domain() { 
        _f_in_domain._dirty = true; 
        return _f_in_domain._base; 
    }
    const Field<I_search_keyword_id>::Base& _search_keyword_id() const { 
        return _f_search_keyword_id._base; 
    }
    Field<I_search_keyword_id>::Base& _search_keyword_id() { 
        _f_search_keyword_id._dirty = true; 
        return _f_search_keyword_id._base; 
    }
    const Field<I_competition_id>::Base& _competition_id() const { 
        return _f_competition_id._base; 
    }
    Field<I_competition_id>::Base& _competition_id() { 
        _f_competition_id._dirty = true; 
        return _f_competition_id._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_Integer::Base& _in_link() const { 
        return _f_in_link._base; 
    }
    F_Integer::Base& _in_link() { 
        _f_in_link._dirty = true; 
        return _f_in_link._base; 
    }
    const F_Integer::Base& _in_alt() const { 
        return _f_in_alt._base; 
    }
    F_Integer::Base& _in_alt() { 
        _f_in_alt._dirty = true; 
        return _f_in_alt._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_rank._dirty)
            field2Val["rank"] = 
                toSQLString(_f_rank._base);
        if (_f_pr._dirty)
            field2Val["pr"] = 
                toSQLString(_f_pr._base);
        if (_f_relevance._dirty)
            field2Val["relevance"] = 
                toSQLString(_f_relevance._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_search_engine_id._dirty)
            field2Val["search_engine_id"] = 
                toSQLString(_f_search_engine_id._base);
        if (_f_tracked_keyword_id._dirty)
            field2Val["tracked_keyword_id"] = 
                toSQLString(_f_tracked_keyword_id._base);
        if (_f_in_url._dirty)
            field2Val["in_url"] = 
                toSQLString(_f_in_url._base);
        if (_f_in_title._dirty)
            field2Val["in_title"] = 
                toSQLString(_f_in_title._base);
        if (_f_in_meta_desc._dirty)
            field2Val["in_meta_desc"] = 
                toSQLString(_f_in_meta_desc._base);
        if (_f_in_meta_kws._dirty)
            field2Val["in_meta_kws"] = 
                toSQLString(_f_in_meta_kws._base);
        if (_f_in_backlink._dirty)
            field2Val["in_backlink"] = 
                toSQLString(_f_in_backlink._base);
        if (_f_in_h1._dirty)
            field2Val["in_h1"] = 
                toSQLString(_f_in_h1._base);
        if (_f_in_h2._dirty)
            field2Val["in_h2"] = 
                toSQLString(_f_in_h2._base);
        if (_f_in_h3._dirty)
            field2Val["in_h3"] = 
                toSQLString(_f_in_h3._base);
        if (_f_in_body._dirty)
            field2Val["in_body"] = 
                toSQLString(_f_in_body._base);
        if (_f_in_domain._dirty)
            field2Val["in_domain"] = 
                toSQLString(_f_in_domain._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_competition_id._dirty)
            field2Val["competition_id"] = 
                toSQLString(_f_competition_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_in_link._dirty)
            field2Val["in_link"] = 
                toSQLString(_f_in_link._base);
        if (_f_in_alt._dirty)
            field2Val["in_alt"] = 
                toSQLString(_f_in_alt._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("search_competitions", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_rank._dirty = false;
            _f_pr._dirty = false;
            _f_relevance._dirty = false;
            _f_created_at._dirty = false;
            _f_search_engine_id._dirty = false;
            _f_tracked_keyword_id._dirty = false;
            _f_in_url._dirty = false;
            _f_in_title._dirty = false;
            _f_in_meta_desc._dirty = false;
            _f_in_meta_kws._dirty = false;
            _f_in_backlink._dirty = false;
            _f_in_h1._dirty = false;
            _f_in_h2._dirty = false;
            _f_in_h3._dirty = false;
            _f_in_body._dirty = false;
            _f_in_domain._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_competition_id._dirty = false;
            _f_account_id._dirty = false;
            _f_in_link._dirty = false;
            _f_in_alt._dirty = false;
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
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_rank._dirty)
            field2Val["rank"] = 
                toSQLString(_f_rank._base);
        if (_f_pr._dirty)
            field2Val["pr"] = 
                toSQLString(_f_pr._base);
        if (_f_relevance._dirty)
            field2Val["relevance"] = 
                toSQLString(_f_relevance._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_search_engine_id._dirty)
            field2Val["search_engine_id"] = 
                toSQLString(_f_search_engine_id._base);
        if (_f_tracked_keyword_id._dirty)
            field2Val["tracked_keyword_id"] = 
                toSQLString(_f_tracked_keyword_id._base);
        if (_f_in_url._dirty)
            field2Val["in_url"] = 
                toSQLString(_f_in_url._base);
        if (_f_in_title._dirty)
            field2Val["in_title"] = 
                toSQLString(_f_in_title._base);
        if (_f_in_meta_desc._dirty)
            field2Val["in_meta_desc"] = 
                toSQLString(_f_in_meta_desc._base);
        if (_f_in_meta_kws._dirty)
            field2Val["in_meta_kws"] = 
                toSQLString(_f_in_meta_kws._base);
        if (_f_in_backlink._dirty)
            field2Val["in_backlink"] = 
                toSQLString(_f_in_backlink._base);
        if (_f_in_h1._dirty)
            field2Val["in_h1"] = 
                toSQLString(_f_in_h1._base);
        if (_f_in_h2._dirty)
            field2Val["in_h2"] = 
                toSQLString(_f_in_h2._base);
        if (_f_in_h3._dirty)
            field2Val["in_h3"] = 
                toSQLString(_f_in_h3._base);
        if (_f_in_body._dirty)
            field2Val["in_body"] = 
                toSQLString(_f_in_body._base);
        if (_f_in_domain._dirty)
            field2Val["in_domain"] = 
                toSQLString(_f_in_domain._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_competition_id._dirty)
            field2Val["competition_id"] = 
                toSQLString(_f_competition_id._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_in_link._dirty)
            field2Val["in_link"] = 
                toSQLString(_f_in_link._base);
        if (_f_in_alt._dirty)
            field2Val["in_alt"] = 
                toSQLString(_f_in_alt._base);
        
        if (DBFace::instance()->
                insert("search_competitions", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_rank._dirty = false;
            _f_pr._dirty = false;
            _f_relevance._dirty = false;
            _f_created_at._dirty = false;
            _f_search_engine_id._dirty = false;
            _f_tracked_keyword_id._dirty = false;
            _f_in_url._dirty = false;
            _f_in_title._dirty = false;
            _f_in_meta_desc._dirty = false;
            _f_in_meta_kws._dirty = false;
            _f_in_backlink._dirty = false;
            _f_in_h1._dirty = false;
            _f_in_h2._dirty = false;
            _f_in_h3._dirty = false;
            _f_in_body._dirty = false;
            _f_in_domain._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_competition_id._dirty = false;
            _f_account_id._dirty = false;
            _f_in_link._dirty = false;
            _f_in_alt._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_SearchCompetition> _f_id;
    F_String _f_url;
    F_Integer _f_rank;
    F_Integer _f_pr;
    F_Integer _f_relevance;
    F_Datetime _f_created_at;
    F_Integer _f_search_engine_id;
    F_Integer _f_tracked_keyword_id;
    F_Integer _f_in_url;
    F_Integer _f_in_title;
    F_Integer _f_in_meta_desc;
    F_Integer _f_in_meta_kws;
    F_Integer _f_in_backlink;
    F_Integer _f_in_h1;
    F_Integer _f_in_h2;
    F_Integer _f_in_h3;
    F_Integer _f_in_body;
    F_Integer _f_in_domain;
    Field<I_search_keyword_id> _f_search_keyword_id;
    Field<I_competition_id> _f_competition_id;
    Field<I_account_id> _f_account_id;
    F_Integer _f_in_link;
    F_Integer _f_in_alt;

    friend class T_SearchCompetition;
};

} //namespace DMMM
#endif //O_SEARCHCOMPETITION
