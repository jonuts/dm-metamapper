
#ifndef T_PAGE_REDIRECT
#define T_PAGE_REDIRECT
#include "O_Page_Redirect.hpp"

namespace DMMM {

class T_Page_Redirect{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_Redirect() 
    {
        _tables.push_back("redirects");
    }
    T_Page_Redirect(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("redirects");
    }

 

    T_Page_Redirect(const I_Account& parentId)
    {
        _tables.push_back("redirects");
        
        _constraint._cond = "(redirects.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_Redirect(const I_Page& parentId)
    {
        _tables.push_back("redirects");
        
        _constraint._cond = "(redirects.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_page_id{
        E_page_id() 
        {  
            _field = "redirects.page_id";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_id{
        E_id() 
        {  
            _field = "redirects.id";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef Field<I_Page_Redirect>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_from_url{
        E_from_url() 
        {  
            _field = "redirects.from_url";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_from_url _from_url(){ 
        return E_from_url();
    }
    struct E_to_url{
        E_to_url() 
        {  
            _field = "redirects.to_url";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_to_url _to_url(){ 
        return E_to_url();
    }
    struct E_anchor{
        E_anchor() 
        {  
            _field = "redirects.anchor";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_anchor _anchor(){ 
        return E_anchor();
    }
    struct E_code{
        E_code() 
        {  
            _field = "redirects.code";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_code _code(){ 
        return E_code();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "redirects.account_id";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_linking_page_url{
        E_linking_page_url() 
        {  
            _field = "redirects.linking_page_url";
        }
        std::string _field;
        typedef T_Page_Redirect::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_linking_page_url _linking_page_url(){ 
        return E_linking_page_url();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("page_id");
        ret.push_back("id");
        ret.push_back("from_url");
        ret.push_back("to_url");
        ret.push_back("anchor");
        ret.push_back("code");
        ret.push_back("account_id");
        ret.push_back("linking_page_url");
        return ret;
    }

    std::vector<O_Page_Redirect> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_Redirect> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_Redirect>::Base>(res[i]["id"]);
            ret[i]._f_from_url._base =
                UTILS::fromString<F_String::Base>(res[i]["from_url"]);
            ret[i]._f_to_url._base =
                UTILS::fromString<F_String::Base>(res[i]["to_url"]);
            ret[i]._f_anchor._base =
                UTILS::fromString<F_Text::Base>(res[i]["anchor"]);
            ret[i]._f_code._base =
                UTILS::fromString<F_Integer::Base>(res[i]["code"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_linking_page_url._base =
                UTILS::fromString<F_String::Base>(res[i]["linking_page_url"]);
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


    std::vector<O_Page_Redirect> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_Redirect> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_Redirect> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_Redirect, bool> select(const I_Page_Redirect& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_Redirect, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_Redirect> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_Redirect(), false);
    }

    std::pair<O_Page_Redirect, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_Redirect>::const_iterator begin,
                         std::vector<O_Page_Redirect>::const_iterator end)
    {
	std::vector<std::string> fields;
        
        fields.push_back(std::string("page_id"));
                
        fields.push_back(std::string("from_url"));
        
        fields.push_back(std::string("to_url"));
        
        fields.push_back(std::string("anchor"));
        
        fields.push_back(std::string("code"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("linking_page_url"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_Redirect& r = *begin;
	    std::vector<std::string> row;
            
            row.push_back(toSQLString(r._page_id()));
                        
            row.push_back(toSQLString(r._from_url()));
            
            row.push_back(toSQLString(r._to_url()));
            
            row.push_back(toSQLString(r._anchor()));
            
            row.push_back(toSQLString(r._code()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._linking_page_url()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("redirects",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_Redirect>::const_iterator begin,
                           std::vector<O_Page_Redirect>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_Redirect>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
                        
            if (it->_f_from_url._dirty){
                fields.push_back(std::string("from_url"));
                row.push_back(toSQLString(it->_from_url()));
            }
            
            if (it->_f_to_url._dirty){
                fields.push_back(std::string("to_url"));
                row.push_back(toSQLString(it->_to_url()));
            }
            
            if (it->_f_anchor._dirty){
                fields.push_back(std::string("anchor"));
                row.push_back(toSQLString(it->_anchor()));
            }
            
            if (it->_f_code._dirty){
                fields.push_back(std::string("code"));
                row.push_back(toSQLString(it->_code()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_linking_page_url._dirty){
                fields.push_back(std::string("linking_page_url"));
                row.push_back(toSQLString(it->_linking_page_url()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("redirects",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_REDIRECT
