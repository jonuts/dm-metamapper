#ifndef O_HISTORICALSCORE
#define O_HISTORICALSCORE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_HistoricalScore{
public:

    O_HistoricalScore() {}
    O_HistoricalScore(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}

O_HistoricalScore(const I_HistoricalScore& id) 
        : _f_id(id)
        {}


    const Field<I_HistoricalScore>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_HistoricalScore>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Integer::Base& _score() const { 
        return _f_score._base; 
    }
    F_Integer::Base& _score() { 
        _f_score._dirty = true; 
        return _f_score._base; 
    }
    const F_Datetime::Base& _created_at() const { 
        return _f_created_at._base; 
    }
    F_Datetime::Base& _created_at() { 
        _f_created_at._dirty = true; 
        return _f_created_at._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("historical_scores", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_score._dirty = false;
            _f_created_at._dirty = false;
            _f_account_id._dirty = false;
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
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("historical_scores", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_score._dirty = false;
            _f_created_at._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_HistoricalScore> _f_id;
    F_Integer _f_score;
    F_Datetime _f_created_at;
    Field<I_account_id> _f_account_id;

    friend class T_HistoricalScore;
};

} //namespace DMMM
#endif //O_HISTORICALSCORE
