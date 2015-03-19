
#ifndef T_ISSUE
#define T_ISSUE
#include "O_Issue.hpp"

namespace DMMM {

class T_Issue{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Issue() 
    {
        _tables.push_back("issues");
    }
    T_Issue(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("issues");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "issues.id";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef Field<I_Issue>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_element{
        E_element() 
        {  
            _field = "issues.element";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_element _element(){ 
        return E_element();
    }
    struct E_test{
        E_test() 
        {  
            _field = "issues.test";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_test _test(){ 
        return E_test();
    }
    struct E_impact{
        E_impact() 
        {  
            _field = "issues.impact";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_impact _impact(){ 
        return E_impact();
    }
    struct E_good_message{
        E_good_message() 
        {  
            _field = "issues.good_message";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_good_message _good_message(){ 
        return E_good_message();
    }
    struct E_bad_message{
        E_bad_message() 
        {  
            _field = "issues.bad_message";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_bad_message _bad_message(){ 
        return E_bad_message();
    }
    struct E_solution{
        E_solution() 
        {  
            _field = "issues.solution";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_solution _solution(){ 
        return E_solution();
    }
    struct E_report_syntax{
        E_report_syntax() 
        {  
            _field = "issues.report_syntax";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_report_syntax _report_syntax(){ 
        return E_report_syntax();
    }
    struct E_category{
        E_category() 
        {  
            _field = "issues.category";
        }
        std::string _field;
        typedef T_Issue::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_category _category(){ 
        return E_category();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("element");
        ret.push_back("test");
        ret.push_back("impact");
        ret.push_back("good_message");
        ret.push_back("bad_message");
        ret.push_back("solution");
        ret.push_back("report_syntax");
        ret.push_back("category");
        return ret;
    }

    std::vector<O_Issue> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Issue> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Issue>::Base>(res[i]["id"]);
            ret[i]._f_element._base =
                UTILS::fromString<F_String::Base>(res[i]["element"]);
            ret[i]._f_test._base =
                UTILS::fromString<F_String::Base>(res[i]["test"]);
            ret[i]._f_impact._base =
                UTILS::fromString<F_Float::Base>(res[i]["impact"]);
            ret[i]._f_good_message._base =
                UTILS::fromString<F_Text::Base>(res[i]["good_message"]);
            ret[i]._f_bad_message._base =
                UTILS::fromString<F_Text::Base>(res[i]["bad_message"]);
            ret[i]._f_solution._base =
                UTILS::fromString<F_Text::Base>(res[i]["solution"]);
            ret[i]._f_report_syntax._base =
                UTILS::fromString<F_Text::Base>(res[i]["report_syntax"]);
            ret[i]._f_category._base =
                UTILS::fromString<F_String::Base>(res[i]["category"]);
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


    std::vector<O_Issue> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Issue> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Issue> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Issue, bool> select(const I_Issue& id){
        return first(E_id() == id);
    }

    std::pair<O_Issue, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Issue> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Issue(), false);
    }

    std::pair<O_Issue, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Issue>::const_iterator begin,
                         std::vector<O_Issue>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("element"));
        
        fields.push_back(std::string("test"));
        
        fields.push_back(std::string("impact"));
        
        fields.push_back(std::string("good_message"));
        
        fields.push_back(std::string("bad_message"));
        
        fields.push_back(std::string("solution"));
        
        fields.push_back(std::string("report_syntax"));
        
        fields.push_back(std::string("category"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Issue& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._element()));
            
            row.push_back(toSQLString(r._test()));
            
            row.push_back(toSQLString(r._impact()));
            
            row.push_back(toSQLString(r._good_message()));
            
            row.push_back(toSQLString(r._bad_message()));
            
            row.push_back(toSQLString(r._solution()));
            
            row.push_back(toSQLString(r._report_syntax()));
            
            row.push_back(toSQLString(r._category()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("issues",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Issue>::const_iterator begin,
                           std::vector<O_Issue>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Issue>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_element._dirty){
                fields.push_back(std::string("element"));
                row.push_back(toSQLString(it->_element()));
            }
            
            if (it->_f_test._dirty){
                fields.push_back(std::string("test"));
                row.push_back(toSQLString(it->_test()));
            }
            
            if (it->_f_impact._dirty){
                fields.push_back(std::string("impact"));
                row.push_back(toSQLString(it->_impact()));
            }
            
            if (it->_f_good_message._dirty){
                fields.push_back(std::string("good_message"));
                row.push_back(toSQLString(it->_good_message()));
            }
            
            if (it->_f_bad_message._dirty){
                fields.push_back(std::string("bad_message"));
                row.push_back(toSQLString(it->_bad_message()));
            }
            
            if (it->_f_solution._dirty){
                fields.push_back(std::string("solution"));
                row.push_back(toSQLString(it->_solution()));
            }
            
            if (it->_f_report_syntax._dirty){
                fields.push_back(std::string("report_syntax"));
                row.push_back(toSQLString(it->_report_syntax()));
            }
            
            if (it->_f_category._dirty){
                fields.push_back(std::string("category"));
                row.push_back(toSQLString(it->_category()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("issues",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ISSUE
