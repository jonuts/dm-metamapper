
#ifndef T_KEYWORDEXCLUSION
#define T_KEYWORDEXCLUSION
#include "O_KeywordExclusion.hpp"

namespace DMMM {

class T_KeywordExclusion{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_KeywordExclusion() 
    {
        _tables.push_back("keyword_exclusions");
    }
    T_KeywordExclusion(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("keyword_exclusions");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "keyword_exclusions.id";
        }
        std::string _field;
        typedef T_KeywordExclusion::Condition ConditionType;
        typedef Field<I_KeywordExclusion>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_text{
        E_text() 
        {  
            _field = "keyword_exclusions.text";
        }
        std::string _field;
        typedef T_KeywordExclusion::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_text _text(){ 
        return E_text();
    }
    struct E_exclusion_type{
        E_exclusion_type() 
        {  
            _field = "keyword_exclusions.exclusion_type";
        }
        std::string _field;
        typedef T_KeywordExclusion::Condition ConditionType;
        typedef Field<EnumKeywordExclusionEXCLUSION_TYPE>::Base ComparerType;
    };

    static E_exclusion_type _exclusion_type(){ 
        return E_exclusion_type();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("text");
        ret.push_back("exclusion_type");
        return ret;
    }

    std::vector<O_KeywordExclusion> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_KeywordExclusion> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_KeywordExclusion>::Base>(res[i]["id"]);
            ret[i]._f_text._base =
                UTILS::fromString<F_String::Base>(res[i]["text"]);
            ret[i]._f_exclusion_type._base =
                (Field<EnumKeywordExclusionEXCLUSION_TYPE>::Base)UTILS::fromString<size_t>(res[i]["exclusion_type"]);
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


    std::vector<O_KeywordExclusion> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_KeywordExclusion> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_KeywordExclusion> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_KeywordExclusion, bool> select(const I_KeywordExclusion& id){
        return first(E_id() == id);
    }

    std::pair<O_KeywordExclusion, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_KeywordExclusion> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_KeywordExclusion(), false);
    }

    std::pair<O_KeywordExclusion, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_KeywordExclusion>::const_iterator begin,
                         std::vector<O_KeywordExclusion>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("text"));
        
        fields.push_back(std::string("exclusion_type"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_KeywordExclusion& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._text()));
            
            row.push_back(toSQLString(r._exclusion_type()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("keyword_exclusions",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_KeywordExclusion>::const_iterator begin,
                           std::vector<O_KeywordExclusion>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_KeywordExclusion>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_text._dirty){
                fields.push_back(std::string("text"));
                row.push_back(toSQLString(it->_text()));
            }
            
            if (it->_f_exclusion_type._dirty){
                fields.push_back(std::string("exclusion_type"));
                row.push_back(toSQLString(it->_exclusion_type()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("keyword_exclusions",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_KEYWORDEXCLUSION
