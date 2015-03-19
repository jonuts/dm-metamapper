
#ifndef T_PAGE_NONHTML
#define T_PAGE_NONHTML
#include "O_Page_NonHtml.hpp"

namespace DMMM {

class T_Page_NonHtml{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_NonHtml() 
    {
        _tables.push_back("non_htmls");
    }
    T_Page_NonHtml(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("non_htmls");
    }

 

    T_Page_NonHtml(const I_Account& parentId)
    {
        _tables.push_back("non_htmls");
        
        _constraint._cond = "(non_htmls.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_NonHtml(const I_Page& parentId)
    {
        _tables.push_back("non_htmls");
        
        _constraint._cond = "(non_htmls.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "non_htmls.id";
        }
        std::string _field;
        typedef T_Page_NonHtml::Condition ConditionType;
        typedef Field<I_Page_NonHtml>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "non_htmls.page_id";
        }
        std::string _field;
        typedef T_Page_NonHtml::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "non_htmls.account_id";
        }
        std::string _field;
        typedef T_Page_NonHtml::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_num_flash{
        E_num_flash() 
        {  
            _field = "non_htmls.num_flash";
        }
        std::string _field;
        typedef T_Page_NonHtml::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_num_flash _num_flash(){ 
        return E_num_flash();
    }
    struct E_num_javascript{
        E_num_javascript() 
        {  
            _field = "non_htmls.num_javascript";
        }
        std::string _field;
        typedef T_Page_NonHtml::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_num_javascript _num_javascript(){ 
        return E_num_javascript();
    }
    struct E_deleted{
        E_deleted() 
        {  
            _field = "non_htmls.deleted";
        }
        std::string _field;
        typedef T_Page_NonHtml::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_deleted _deleted(){ 
        return E_deleted();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("page_id");
        ret.push_back("account_id");
        ret.push_back("num_flash");
        ret.push_back("num_javascript");
        ret.push_back("deleted");
        return ret;
    }

    std::vector<O_Page_NonHtml> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_NonHtml> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_NonHtml>::Base>(res[i]["id"]);
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_num_flash._base =
                UTILS::fromString<F_Integer::Base>(res[i]["num_flash"]);
            ret[i]._f_num_javascript._base =
                UTILS::fromString<F_Integer::Base>(res[i]["num_javascript"]);
            ret[i]._f_deleted._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["deleted"]);
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


    std::vector<O_Page_NonHtml> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_NonHtml> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_NonHtml> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_NonHtml, bool> select(const I_Page_NonHtml& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_NonHtml, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_NonHtml> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_NonHtml(), false);
    }

    std::pair<O_Page_NonHtml, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_NonHtml>::const_iterator begin,
                         std::vector<O_Page_NonHtml>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("num_flash"));
        
        fields.push_back(std::string("num_javascript"));
        
        fields.push_back(std::string("deleted"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_NonHtml& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._num_flash()));
            
            row.push_back(toSQLString(r._num_javascript()));
            
            row.push_back(toSQLString(r._deleted()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("non_htmls",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_NonHtml>::const_iterator begin,
                           std::vector<O_Page_NonHtml>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_NonHtml>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_num_flash._dirty){
                fields.push_back(std::string("num_flash"));
                row.push_back(toSQLString(it->_num_flash()));
            }
            
            if (it->_f_num_javascript._dirty){
                fields.push_back(std::string("num_javascript"));
                row.push_back(toSQLString(it->_num_javascript()));
            }
            
            if (it->_f_deleted._dirty){
                fields.push_back(std::string("deleted"));
                row.push_back(toSQLString(it->_deleted()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("non_htmls",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_NONHTML
