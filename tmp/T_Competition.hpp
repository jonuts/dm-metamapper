
#ifndef T_COMPETITION
#define T_COMPETITION
#include "O_Competition.hpp"

namespace DMMM {

class T_Competition{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Competition() 
    {
        _tables.push_back("competitions");
    }
    T_Competition(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("competitions");
    }

 

    T_Competition(const I_Account& parentId)
    {
        _tables.push_back("competitions");
        
        _constraint._cond = "(competitions.account_id = " + parentId.to_s() + ")";
    } 
    
    
    struct E_id{
        E_id() 
        {  
            _field = "competitions.id";
        }
        std::string _field;
        typedef T_Competition::Condition ConditionType;
        typedef Field<I_Competition>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_url{
        E_url() 
        {  
            _field = "competitions.url";
        }
        std::string _field;
        typedef T_Competition::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_url _url(){ 
        return E_url();
    }
    struct E_average_ranking{
        E_average_ranking() 
        {  
            _field = "competitions.average_ranking";
        }
        std::string _field;
        typedef T_Competition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_average_ranking _average_ranking(){ 
        return E_average_ranking();
    }
    struct E_number_of_kws{
        E_number_of_kws() 
        {  
            _field = "competitions.number_of_kws";
        }
        std::string _field;
        typedef T_Competition::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_kws _number_of_kws(){ 
        return E_number_of_kws();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "competitions.account_id";
        }
        std::string _field;
        typedef T_Competition::Condition ConditionType;
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
        ret.push_back("url");
        ret.push_back("average_ranking");
        ret.push_back("number_of_kws");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_Competition> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Competition> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Competition>::Base>(res[i]["id"]);
            ret[i]._f_url._base =
                UTILS::fromString<F_String::Base>(res[i]["url"]);
            ret[i]._f_average_ranking._base =
                UTILS::fromString<F_Integer::Base>(res[i]["average_ranking"]);
            ret[i]._f_number_of_kws._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_kws"]);
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


    std::vector<O_Competition> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Competition> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Competition> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Competition, bool> select(const I_Competition& id){
        return first(E_id() == id);
    }

    std::pair<O_Competition, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Competition> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Competition(), false);
    }

    std::pair<O_Competition, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Competition>::const_iterator begin,
                         std::vector<O_Competition>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("url"));
        
        fields.push_back(std::string("average_ranking"));
        
        fields.push_back(std::string("number_of_kws"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Competition& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._url()));
            
            row.push_back(toSQLString(r._average_ranking()));
            
            row.push_back(toSQLString(r._number_of_kws()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("competitions",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Competition>::const_iterator begin,
                           std::vector<O_Competition>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Competition>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_url._dirty){
                fields.push_back(std::string("url"));
                row.push_back(toSQLString(it->_url()));
            }
            
            if (it->_f_average_ranking._dirty){
                fields.push_back(std::string("average_ranking"));
                row.push_back(toSQLString(it->_average_ranking()));
            }
            
            if (it->_f_number_of_kws._dirty){
                fields.push_back(std::string("number_of_kws"));
                row.push_back(toSQLString(it->_number_of_kws()));
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
            ret = DBFace::instance()->insert("competitions",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_COMPETITION
