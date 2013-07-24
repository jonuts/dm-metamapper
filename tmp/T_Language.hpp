
#ifndef T_LANGUAGE
#define T_LANGUAGE
#include "O_Language.hpp"

namespace DMMM {

class T_Language{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Language() 
    {
        _tables.push_back("languages");
    }
    T_Language(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("languages");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "languages.id";
        }
        std::string _field;
        typedef T_Language::Condition ConditionType;
        typedef Field<I_Language>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "languages.name";
        }
        std::string _field;
        typedef T_Language::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        return ret;
    }

    std::vector<O_Language> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Language> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Language>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
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


    std::vector<O_Language> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Language> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Language> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Language, bool> select(const I_Language& id){
        return first(E_id() == id);
    }

    std::pair<O_Language, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Language> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Language(), false);
    }

    std::pair<O_Language, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Language>::const_iterator begin,
                         std::vector<O_Language>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Language& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("languages",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Language>::const_iterator begin,
                           std::vector<O_Language>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Language>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("languages",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_LANGUAGE
