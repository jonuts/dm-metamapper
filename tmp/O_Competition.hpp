#ifndef O_COMPETITION
#define O_COMPETITION

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_SearchCompetition.hpp"



namespace DMMM {

class O_Competition{
public:

    O_Competition() {}
    O_Competition(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}

O_Competition(const I_Competition& id) 
        : _f_id(id)
        {}


    std::vector<O_SearchCompetition> _search_competitions() const
    {
        T_SearchCompetition table;
        return table.select(table._competition_id() == _id());   
    }
    std::vector<O_SearchCompetition> 
    _competition_id(const T_SearchCompetition::Condition& c) const
    {
        T_SearchCompetition table(c);
        return table.select(table._competition_id() == _id());   
    }

    const Field<I_Competition>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Competition>::Base& _id() { 
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
    const F_Integer::Base& _average_ranking() const { 
        return _f_average_ranking._base; 
    }
    F_Integer::Base& _average_ranking() { 
        _f_average_ranking._dirty = true; 
        return _f_average_ranking._base; 
    }
    const F_Integer::Base& _number_of_kws() const { 
        return _f_number_of_kws._base; 
    }
    F_Integer::Base& _number_of_kws() { 
        _f_number_of_kws._dirty = true; 
        return _f_number_of_kws._base; 
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
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_average_ranking._dirty)
            field2Val["average_ranking"] = 
                toSQLString(_f_average_ranking._base);
        if (_f_number_of_kws._dirty)
            field2Val["number_of_kws"] = 
                toSQLString(_f_number_of_kws._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("competitions", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_average_ranking._dirty = false;
            _f_number_of_kws._dirty = false;
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
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_average_ranking._dirty)
            field2Val["average_ranking"] = 
                toSQLString(_f_average_ranking._base);
        if (_f_number_of_kws._dirty)
            field2Val["number_of_kws"] = 
                toSQLString(_f_number_of_kws._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("competitions", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_average_ranking._dirty = false;
            _f_number_of_kws._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Competition> _f_id;
    F_String _f_url;
    F_Integer _f_average_ranking;
    F_Integer _f_number_of_kws;
    Field<I_account_id> _f_account_id;

    friend class T_Competition;
};

} //namespace DMMM
#endif //O_COMPETITION
