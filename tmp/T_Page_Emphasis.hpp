
#ifndef T_PAGE_EMPHASIS
#define T_PAGE_EMPHASIS
#include "O_Page_Emphasis.hpp"

namespace DMMM {

class T_Page_Emphasis{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_Emphasis() 
    {
        _tables.push_back("emphases");
    }
    T_Page_Emphasis(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("emphases");
    }

 

    T_Page_Emphasis(const I_Account& parentId)
    {
        _tables.push_back("emphases");
        
        _constraint._cond = "(emphases.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_Emphasis(const I_Page& parentId)
    {
        _tables.push_back("emphases");
        
        _constraint._cond = "(emphases.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "emphases.id";
        }
        std::string _field;
        typedef T_Page_Emphasis::Condition ConditionType;
        typedef Field<I_Page_Emphasis>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_text{
        E_text() 
        {  
            _field = "emphases.text";
        }
        std::string _field;
        typedef T_Page_Emphasis::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_text _text(){ 
        return E_text();
    }
    struct E_em_type{
        E_em_type() 
        {  
            _field = "emphases.em_type";
        }
        std::string _field;
        typedef T_Page_Emphasis::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_em_type _em_type(){ 
        return E_em_type();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "emphases.page_id";
        }
        std::string _field;
        typedef T_Page_Emphasis::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "emphases.account_id";
        }
        std::string _field;
        typedef T_Page_Emphasis::Condition ConditionType;
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
        ret.push_back("text");
        ret.push_back("em_type");
        ret.push_back("page_id");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_Page_Emphasis> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_Emphasis> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_Emphasis>::Base>(res[i]["id"]);
            ret[i]._f_text._base =
                UTILS::fromString<F_Text::Base>(res[i]["text"]);
            ret[i]._f_em_type._base =
                UTILS::fromString<F_String::Base>(res[i]["em_type"]);
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


    std::vector<O_Page_Emphasis> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_Emphasis> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_Emphasis> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_Emphasis, bool> select(const I_Page_Emphasis& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_Emphasis, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_Emphasis> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_Emphasis(), false);
    }

    std::pair<O_Page_Emphasis, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_Emphasis>::const_iterator begin,
                         std::vector<O_Page_Emphasis>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("text"));
        
        fields.push_back(std::string("em_type"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_Emphasis& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._text()));
            
            row.push_back(toSQLString(r._em_type()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("emphases",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_Emphasis>::const_iterator begin,
                           std::vector<O_Page_Emphasis>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_Emphasis>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_text._dirty){
                fields.push_back(std::string("text"));
                row.push_back(toSQLString(it->_text()));
            }
            
            if (it->_f_em_type._dirty){
                fields.push_back(std::string("em_type"));
                row.push_back(toSQLString(it->_em_type()));
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
            ret = DBFace::instance()->insert("emphases",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_EMPHASIS
