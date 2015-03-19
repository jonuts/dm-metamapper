
#ifndef T_PAGE_LINK
#define T_PAGE_LINK
#include "O_Page_Link.hpp"

namespace DMMM {

class T_Page_Link{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_Link() 
    {
        _tables.push_back("links");
    }
    T_Page_Link(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("links");
    }

 

    T_Page_Link(const I_Account& parentId)
    {
        _tables.push_back("links");
        
        _constraint._cond = "(links.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_Link(const I_Page& parentId)
    {
        _tables.push_back("links");
        
        _constraint._cond = "(links.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "links.id";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef Field<I_Page_Link>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_text{
        E_text() 
        {  
            _field = "links.text";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_text _text(){ 
        return E_text();
    }
    struct E_href{
        E_href() 
        {  
            _field = "links.href";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_href _href(){ 
        return E_href();
    }
    struct E_nofollow{
        E_nofollow() 
        {  
            _field = "links.nofollow";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_nofollow _nofollow(){ 
        return E_nofollow();
    }
    struct E_relevant_text{
        E_relevant_text() 
        {  
            _field = "links.relevant_text";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_relevant_text _relevant_text(){ 
        return E_relevant_text();
    }
    struct E_is_image{
        E_is_image() 
        {  
            _field = "links.is_image";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_is_image _is_image(){ 
        return E_is_image();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "links.page_id";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "links.account_id";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_target_page_id{
        E_target_page_id() 
        {  
            _field = "links.target_page_id";
        }
        std::string _field;
        typedef T_Page_Link::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_target_page_id _target_page_id(){ 
        return E_target_page_id();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("text");
        ret.push_back("href");
        ret.push_back("nofollow");
        ret.push_back("relevant_text");
        ret.push_back("is_image");
        ret.push_back("page_id");
        ret.push_back("account_id");
        ret.push_back("target_page_id");
        return ret;
    }

    std::vector<O_Page_Link> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_Link> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_Link>::Base>(res[i]["id"]);
            ret[i]._f_text._base =
                UTILS::fromString<F_String::Base>(res[i]["text"]);
            ret[i]._f_href._base =
                UTILS::fromString<F_String::Base>(res[i]["href"]);
            ret[i]._f_nofollow._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["nofollow"]);
            ret[i]._f_relevant_text._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["relevant_text"]);
            ret[i]._f_is_image._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["is_image"]);
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_target_page_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["target_page_id"]);
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


    std::vector<O_Page_Link> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_Link> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_Link> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_Link, bool> select(const I_Page_Link& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_Link, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_Link> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_Link(), false);
    }

    std::pair<O_Page_Link, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_Link>::const_iterator begin,
                         std::vector<O_Page_Link>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("text"));
        
        fields.push_back(std::string("href"));
        
        fields.push_back(std::string("nofollow"));
        
        fields.push_back(std::string("relevant_text"));
        
        fields.push_back(std::string("is_image"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("target_page_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_Link& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._text()));
            
            row.push_back(toSQLString(r._href()));
            
            row.push_back(toSQLString(r._nofollow()));
            
            row.push_back(toSQLString(r._relevant_text()));
            
            row.push_back(toSQLString(r._is_image()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._target_page_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("links",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_Link>::const_iterator begin,
                           std::vector<O_Page_Link>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_Link>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_text._dirty){
                fields.push_back(std::string("text"));
                row.push_back(toSQLString(it->_text()));
            }
            
            if (it->_f_href._dirty){
                fields.push_back(std::string("href"));
                row.push_back(toSQLString(it->_href()));
            }
            
            if (it->_f_nofollow._dirty){
                fields.push_back(std::string("nofollow"));
                row.push_back(toSQLString(it->_nofollow()));
            }
            
            if (it->_f_relevant_text._dirty){
                fields.push_back(std::string("relevant_text"));
                row.push_back(toSQLString(it->_relevant_text()));
            }
            
            if (it->_f_is_image._dirty){
                fields.push_back(std::string("is_image"));
                row.push_back(toSQLString(it->_is_image()));
            }
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_target_page_id._dirty){
                fields.push_back(std::string("target_page_id"));
                row.push_back(toSQLString(it->_target_page_id()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("links",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_LINK
