
#ifndef T_MISSINGELEMENT
#define T_MISSINGELEMENT
#include "O_MissingElement.hpp"

namespace DMMM {

class T_MissingElement{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_MissingElement() 
    {
        _tables.push_back("missing_elements");
    }
    T_MissingElement(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("missing_elements");
    }

 

    T_MissingElement(const I_Account& parentId)
    {
        _tables.push_back("missing_elements");
        
        _constraint._cond = "(missing_elements.account_id = " + parentId.to_s() + ")";
    } 
 

    T_MissingElement(const I_PageSearchKeyword& parentId)
    {
        _tables.push_back("missing_elements");
        
        _constraint._cond = "(missing_elements.page_search_keyword_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "missing_elements.id";
        }
        std::string _field;
        typedef T_MissingElement::Condition ConditionType;
        typedef Field<I_MissingElement>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_element{
        E_element() 
        {  
            _field = "missing_elements.element";
        }
        std::string _field;
        typedef T_MissingElement::Condition ConditionType;
        typedef Field<EnumMissingElementELEMENT>::Base ComparerType;
    };

    static E_element _element(){ 
        return E_element();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "missing_elements.account_id";
        }
        std::string _field;
        typedef T_MissingElement::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_page_search_keyword_id{
        E_page_search_keyword_id() 
        {  
            _field = "missing_elements.page_search_keyword_id";
        }
        std::string _field;
        typedef T_MissingElement::Condition ConditionType;
        typedef Field<I_page_search_keyword_id>::Base ComparerType;
    };

    static E_page_search_keyword_id _page_search_keyword_id(){ 
        return E_page_search_keyword_id();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("element");
        ret.push_back("account_id");
        ret.push_back("page_search_keyword_id");
        return ret;
    }

    std::vector<O_MissingElement> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_MissingElement> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_MissingElement>::Base>(res[i]["id"]);
            ret[i]._f_element._base =
                (Field<EnumMissingElementELEMENT>::Base)UTILS::fromString<size_t>(res[i]["element"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_page_search_keyword_id._base =
                UTILS::fromString<Field<I_page_search_keyword_id>::Base>(res[i]["page_search_keyword_id"]);
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


    std::vector<O_MissingElement> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_MissingElement> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_MissingElement> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_MissingElement, bool> select(const I_MissingElement& id){
        return first(E_id() == id);
    }

    std::pair<O_MissingElement, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_MissingElement> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_MissingElement(), false);
    }

    std::pair<O_MissingElement, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_MissingElement>::const_iterator begin,
                         std::vector<O_MissingElement>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("element"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("page_search_keyword_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_MissingElement& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._element()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._page_search_keyword_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("missing_elements",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_MissingElement>::const_iterator begin,
                           std::vector<O_MissingElement>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_MissingElement>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_element._dirty){
                fields.push_back(std::string("element"));
                row.push_back(toSQLString(it->_element()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_page_search_keyword_id._dirty){
                fields.push_back(std::string("page_search_keyword_id"));
                row.push_back(toSQLString(it->_page_search_keyword_id()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("missing_elements",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_MISSINGELEMENT
