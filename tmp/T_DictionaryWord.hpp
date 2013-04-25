
#ifndef T_DICTIONARYWORD
#define T_DICTIONARYWORD
#include "O_DictionaryWord.hpp"

namespace DMMM {

class T_DictionaryWord{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_DictionaryWord() 
    {
        _tables.push_back("dictionary_words");
    }
    T_DictionaryWord(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("dictionary_words");
    }

 

    T_DictionaryWord(const I_Language& parentId)
    {
        _tables.push_back("dictionary_words");
        
        _constraint._cond = "(dictionary_words.language_id = " + parentId.to_s() + ")";
    } 
    
    
    struct E_id{
        E_id() 
        {  
            _field = "dictionary_words.id";
        }
        std::string _field;
        typedef T_DictionaryWord::Condition ConditionType;
        typedef Field<I_DictionaryWord>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_text{
        E_text() 
        {  
            _field = "dictionary_words.text";
        }
        std::string _field;
        typedef T_DictionaryWord::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_text _text(){ 
        return E_text();
    }
    struct E_frequency{
        E_frequency() 
        {  
            _field = "dictionary_words.frequency";
        }
        std::string _field;
        typedef T_DictionaryWord::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_frequency _frequency(){ 
        return E_frequency();
    }
    struct E_language_id{
        E_language_id() 
        {  
            _field = "dictionary_words.language_id";
        }
        std::string _field;
        typedef T_DictionaryWord::Condition ConditionType;
        typedef Field<I_language_id>::Base ComparerType;
    };

    static E_language_id _language_id(){ 
        return E_language_id();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("text");
        ret.push_back("frequency");
        ret.push_back("language_id");
        return ret;
    }

    std::vector<O_DictionaryWord> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_DictionaryWord> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_DictionaryWord>::Base>(res[i]["id"]);
            ret[i]._f_text._base =
                UTILS::fromString<F_String::Base>(res[i]["text"]);
            ret[i]._f_frequency._base =
                UTILS::fromString<F_Float::Base>(res[i]["frequency"]);
            ret[i]._f_language_id._base =
                UTILS::fromString<Field<I_language_id>::Base>(res[i]["language_id"]);
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


    std::vector<O_DictionaryWord> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_DictionaryWord> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_DictionaryWord> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_DictionaryWord, bool> select(const I_DictionaryWord& id){
        return first(E_id() == id);
    }

    std::pair<O_DictionaryWord, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_DictionaryWord> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_DictionaryWord(), false);
    }

    std::pair<O_DictionaryWord, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_DictionaryWord>::const_iterator begin,
                         std::vector<O_DictionaryWord>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("text"));
        
        fields.push_back(std::string("frequency"));
        
        fields.push_back(std::string("language_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_DictionaryWord& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._text()));
            
            row.push_back(toSQLString(r._frequency()));
            
            row.push_back(toSQLString(r._language_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("dictionary_words",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_DictionaryWord>::const_iterator begin,
                           std::vector<O_DictionaryWord>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_DictionaryWord>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_text._dirty){
                fields.push_back(std::string("text"));
                row.push_back(toSQLString(it->_text()));
            }
            
            if (it->_f_frequency._dirty){
                fields.push_back(std::string("frequency"));
                row.push_back(toSQLString(it->_frequency()));
            }
            
            if (it->_f_language_id._dirty){
                fields.push_back(std::string("language_id"));
                row.push_back(toSQLString(it->_language_id()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("dictionary_words",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_DICTIONARYWORD
