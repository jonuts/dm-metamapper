
#ifndef T_PAGE_KEYWORD
#define T_PAGE_KEYWORD
#include "O_Page_Keyword.hpp"

namespace DMMM {

class T_Page_Keyword{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_Keyword() 
    {
        _tables.push_back("keywords");
    }
    T_Page_Keyword(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("keywords");
    }

 

    T_Page_Keyword(const I_Account& parentId)
    {
        _tables.push_back("keywords");
        
        _constraint._cond = "(keywords.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_Keyword(const I_Page& parentId)
    {
        _tables.push_back("keywords");
        
        _constraint._cond = "(keywords.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "keywords.id";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef Field<I_Page_Keyword>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_size{
        E_size() 
        {  
            _field = "keywords.size";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_size _size(){ 
        return E_size();
    }
    struct E_text{
        E_text() 
        {  
            _field = "keywords.text";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_text _text(){ 
        return E_text();
    }
    struct E_frequency{
        E_frequency() 
        {  
            _field = "keywords.frequency";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_frequency _frequency(){ 
        return E_frequency();
    }
    struct E_relevance{
        E_relevance() 
        {  
            _field = "keywords.relevance";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_relevance _relevance(){ 
        return E_relevance();
    }
    struct E_position{
        E_position() 
        {  
            _field = "keywords.position";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef Field<EnumPage_KeywordPOSITION>::Base ComparerType;
    };

    static E_position _position(){ 
        return E_position();
    }
    struct E_directory{
        E_directory() 
        {  
            _field = "keywords.directory";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_directory _directory(){ 
        return E_directory();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "keywords.page_id";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "keywords.account_id";
        }
        std::string _field;
        typedef T_Page_Keyword::Condition ConditionType;
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
        ret.push_back("size");
        ret.push_back("text");
        ret.push_back("frequency");
        ret.push_back("relevance");
        ret.push_back("position");
        ret.push_back("directory");
        ret.push_back("page_id");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_Page_Keyword> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_Keyword> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_Keyword>::Base>(res[i]["id"]);
            ret[i]._f_size._base =
                UTILS::fromString<F_Integer::Base>(res[i]["size"]);
            ret[i]._f_text._base =
                UTILS::fromString<F_String::Base>(res[i]["text"]);
            ret[i]._f_frequency._base =
                UTILS::fromString<F_Integer::Base>(res[i]["frequency"]);
            ret[i]._f_relevance._base =
                UTILS::fromString<F_Integer::Base>(res[i]["relevance"]);
            ret[i]._f_position._base =
                (Field<EnumPage_KeywordPOSITION>::Base)UTILS::fromString<size_t>(res[i]["position"]);
            ret[i]._f_directory._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["directory"]);
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
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


    std::vector<O_Page_Keyword> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_Keyword> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_Keyword> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_Keyword, bool> select(const I_Page_Keyword& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_Keyword, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_Keyword> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_Keyword(), false);
    }

    std::pair<O_Page_Keyword, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_Keyword>::const_iterator begin,
                         std::vector<O_Page_Keyword>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("size"));
        
        fields.push_back(std::string("text"));
        
        fields.push_back(std::string("frequency"));
        
        fields.push_back(std::string("relevance"));
        
        fields.push_back(std::string("position"));
        
        fields.push_back(std::string("directory"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_Keyword& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._size()));
            
            row.push_back(toSQLString(r._text()));
            
            row.push_back(toSQLString(r._frequency()));
            
            row.push_back(toSQLString(r._relevance()));
            
            row.push_back(toSQLString(r._position()));
            
            row.push_back(toSQLString(r._directory()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("keywords",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_Keyword>::const_iterator begin,
                           std::vector<O_Page_Keyword>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_Keyword>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_size._dirty){
                fields.push_back(std::string("size"));
                row.push_back(toSQLString(it->_size()));
            }
            
            if (it->_f_text._dirty){
                fields.push_back(std::string("text"));
                row.push_back(toSQLString(it->_text()));
            }
            
            if (it->_f_frequency._dirty){
                fields.push_back(std::string("frequency"));
                row.push_back(toSQLString(it->_frequency()));
            }
            
            if (it->_f_relevance._dirty){
                fields.push_back(std::string("relevance"));
                row.push_back(toSQLString(it->_relevance()));
            }
            
            if (it->_f_position._dirty){
                fields.push_back(std::string("position"));
                row.push_back(toSQLString(it->_position()));
            }
            
            if (it->_f_directory._dirty){
                fields.push_back(std::string("directory"));
                row.push_back(toSQLString(it->_directory()));
            }
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
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
            ret = DBFace::instance()->insert("keywords",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_KEYWORD
