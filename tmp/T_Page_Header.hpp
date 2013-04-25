
#ifndef T_PAGE_HEADER
#define T_PAGE_HEADER
#include "O_Page_Header.hpp"

namespace DMMM {

class T_Page_Header{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_Header() 
    {
        _tables.push_back("page_headers");
    }
    T_Page_Header(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("page_headers");
    }

 

    T_Page_Header(const I_Account& parentId)
    {
        _tables.push_back("page_headers");
        
        _constraint._cond = "(page_headers.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_Header(const I_Page& parentId)
    {
        _tables.push_back("page_headers");
        
        _constraint._cond = "(page_headers.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "page_headers.id";
        }
        std::string _field;
        typedef T_Page_Header::Condition ConditionType;
        typedef Field<I_Page_Header>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_h_type{
        E_h_type() 
        {  
            _field = "page_headers.h_type";
        }
        std::string _field;
        typedef T_Page_Header::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_h_type _h_type(){ 
        return E_h_type();
    }
    struct E_text{
        E_text() 
        {  
            _field = "page_headers.text";
        }
        std::string _field;
        typedef T_Page_Header::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_text _text(){ 
        return E_text();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "page_headers.page_id";
        }
        std::string _field;
        typedef T_Page_Header::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "page_headers.account_id";
        }
        std::string _field;
        typedef T_Page_Header::Condition ConditionType;
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
        ret.push_back("h_type");
        ret.push_back("text");
        ret.push_back("page_id");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_Page_Header> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_Header> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_Header>::Base>(res[i]["id"]);
            ret[i]._f_h_type._base =
                UTILS::fromString<F_Integer::Base>(res[i]["h_type"]);
            ret[i]._f_text._base =
                UTILS::fromString<F_String::Base>(res[i]["text"]);
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


    std::vector<O_Page_Header> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_Header> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_Header> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_Header, bool> select(const I_Page_Header& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_Header, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_Header> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_Header(), false);
    }

    std::pair<O_Page_Header, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_Header>::const_iterator begin,
                         std::vector<O_Page_Header>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("h_type"));
        
        fields.push_back(std::string("text"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_Header& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._h_type()));
            
            row.push_back(toSQLString(r._text()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("page_headers",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_Header>::const_iterator begin,
                           std::vector<O_Page_Header>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_Header>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_h_type._dirty){
                fields.push_back(std::string("h_type"));
                row.push_back(toSQLString(it->_h_type()));
            }
            
            if (it->_f_text._dirty){
                fields.push_back(std::string("text"));
                row.push_back(toSQLString(it->_text()));
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
            ret = DBFace::instance()->insert("page_headers",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_HEADER
