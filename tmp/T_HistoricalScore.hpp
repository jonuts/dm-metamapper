
#ifndef T_HISTORICALSCORE
#define T_HISTORICALSCORE
#include "O_HistoricalScore.hpp"

namespace DMMM {

class T_HistoricalScore{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_HistoricalScore() 
    {
        _tables.push_back("historical_scores");
    }
    T_HistoricalScore(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("historical_scores");
    }

 

    T_HistoricalScore(const I_Account& parentId)
    {
        _tables.push_back("historical_scores");
        
        _constraint._cond = "(historical_scores.account_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "historical_scores.id";
        }
        std::string _field;
        typedef T_HistoricalScore::Condition ConditionType;
        typedef Field<I_HistoricalScore>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_score{
        E_score() 
        {  
            _field = "historical_scores.score";
        }
        std::string _field;
        typedef T_HistoricalScore::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_score _score(){ 
        return E_score();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "historical_scores.created_at";
        }
        std::string _field;
        typedef T_HistoricalScore::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "historical_scores.account_id";
        }
        std::string _field;
        typedef T_HistoricalScore::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("score");
        ret.push_back("created_at");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_HistoricalScore> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_HistoricalScore> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_HistoricalScore>::Base>(res[i]["id"]);
            ret[i]._f_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["score"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
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


    std::vector<O_HistoricalScore> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_HistoricalScore> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_HistoricalScore> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_HistoricalScore, bool> select(const I_HistoricalScore& id){
        return first(E_id() == id);
    }

    std::pair<O_HistoricalScore, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_HistoricalScore> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_HistoricalScore(), false);
    }

    std::pair<O_HistoricalScore, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_HistoricalScore>::const_iterator begin,
                         std::vector<O_HistoricalScore>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("score"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_HistoricalScore& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._score()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("historical_scores",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_HistoricalScore>::const_iterator begin,
                           std::vector<O_HistoricalScore>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_HistoricalScore>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_score._dirty){
                fields.push_back(std::string("score"));
                row.push_back(toSQLString(it->_score()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("historical_scores",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_HISTORICALSCORE
