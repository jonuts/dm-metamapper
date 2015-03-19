#ifndef O_ENGINERANK
#define O_ENGINERANK

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_EngineRank{
public:

    O_EngineRank() {}
    O_EngineRank(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_EngineRank(const I_SearchEngine& parent_id) 
        : _f_search_engine_id(parent_id)
        {}
    O_EngineRank(const I_SearchKeyword& parent_id) 
        : _f_search_keyword_id(parent_id)
        {}

O_EngineRank(const I_EngineRank& id) 
        : _f_id(id)
        {}


    const Field<I_EngineRank>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_EngineRank>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Datetime::Base& _created_at() const { 
        return _f_created_at._base; 
    }
    F_Datetime::Base& _created_at() { 
        _f_created_at._dirty = true; 
        return _f_created_at._base; 
    }
    const F_Integer::Base& _baseline_ranking() const { 
        return _f_baseline_ranking._base; 
    }
    F_Integer::Base& _baseline_ranking() { 
        _f_baseline_ranking._dirty = true; 
        return _f_baseline_ranking._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const Field<I_search_keyword_id>::Base& _search_keyword_id() const { 
        return _f_search_keyword_id._base; 
    }
    Field<I_search_keyword_id>::Base& _search_keyword_id() { 
        _f_search_keyword_id._dirty = true; 
        return _f_search_keyword_id._base; 
    }
    const Field<I_search_engine_id>::Base& _search_engine_id() const { 
        return _f_search_engine_id._base; 
    }
    Field<I_search_engine_id>::Base& _search_engine_id() { 
        _f_search_engine_id._dirty = true; 
        return _f_search_engine_id._base; 
    }
    const F_Boolean::Base& _tracked() const { 
        return _f_tracked._base; 
    }
    F_Boolean::Base& _tracked() { 
        _f_tracked._dirty = true; 
        return _f_tracked._base; 
    }
    const F_Datetime::Base& _updated_at() const { 
        return _f_updated_at._base; 
    }
    F_Datetime::Base& _updated_at() { 
        _f_updated_at._dirty = true; 
        return _f_updated_at._base; 
    }
    const F_Integer::Base& _current_ranking() const { 
        return _f_current_ranking._base; 
    }
    F_Integer::Base& _current_ranking() { 
        _f_current_ranking._dirty = true; 
        return _f_current_ranking._base; 
    }
    const F_Integer::Base& _change_from_last() const { 
        return _f_change_from_last._base; 
    }
    F_Integer::Base& _change_from_last() { 
        _f_change_from_last._dirty = true; 
        return _f_change_from_last._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_baseline_ranking._dirty)
            field2Val["baseline_ranking"] = 
                toSQLString(_f_baseline_ranking._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_search_engine_id._dirty)
            field2Val["search_engine_id"] = 
                toSQLString(_f_search_engine_id._base);
        if (_f_tracked._dirty)
            field2Val["tracked"] = 
                toSQLString(_f_tracked._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_current_ranking._dirty)
            field2Val["current_ranking"] = 
                toSQLString(_f_current_ranking._base);
        if (_f_change_from_last._dirty)
            field2Val["change_from_last"] = 
                toSQLString(_f_change_from_last._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("search_engine_search_keywords", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_created_at._dirty = false;
            _f_baseline_ranking._dirty = false;
            _f_account_id._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_search_engine_id._dirty = false;
            _f_tracked._dirty = false;
            _f_updated_at._dirty = false;
            _f_current_ranking._dirty = false;
            _f_change_from_last._dirty = false;
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
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_baseline_ranking._dirty)
            field2Val["baseline_ranking"] = 
                toSQLString(_f_baseline_ranking._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_search_engine_id._dirty)
            field2Val["search_engine_id"] = 
                toSQLString(_f_search_engine_id._base);
        if (_f_tracked._dirty)
            field2Val["tracked"] = 
                toSQLString(_f_tracked._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_current_ranking._dirty)
            field2Val["current_ranking"] = 
                toSQLString(_f_current_ranking._base);
        if (_f_change_from_last._dirty)
            field2Val["change_from_last"] = 
                toSQLString(_f_change_from_last._base);
        
        if (DBFace::instance()->
                insert("search_engine_search_keywords", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_created_at._dirty = false;
            _f_baseline_ranking._dirty = false;
            _f_account_id._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_search_engine_id._dirty = false;
            _f_tracked._dirty = false;
            _f_updated_at._dirty = false;
            _f_current_ranking._dirty = false;
            _f_change_from_last._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_EngineRank> _f_id;
    F_Datetime _f_created_at;
    F_Integer _f_baseline_ranking;
    Field<I_account_id> _f_account_id;
    Field<I_search_keyword_id> _f_search_keyword_id;
    Field<I_search_engine_id> _f_search_engine_id;
    F_Boolean _f_tracked;
    F_Datetime _f_updated_at;
    F_Integer _f_current_ranking;
    F_Integer _f_change_from_last;

    friend class T_EngineRank;
};

} //namespace DMMM
#endif //O_ENGINERANK
