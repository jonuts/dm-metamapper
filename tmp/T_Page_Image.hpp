
#ifndef T_PAGE_IMAGE
#define T_PAGE_IMAGE
#include "O_Page_Image.hpp"

namespace DMMM {

class T_Page_Image{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page_Image() 
    {
        _tables.push_back("images");
    }
    T_Page_Image(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("images");
    }

 

    T_Page_Image(const I_Account& parentId)
    {
        _tables.push_back("images");
        
        _constraint._cond = "(images.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page_Image(const I_Page& parentId)
    {
        _tables.push_back("images");
        
        _constraint._cond = "(images.page_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "images.id";
        }
        std::string _field;
        typedef T_Page_Image::Condition ConditionType;
        typedef Field<I_Page_Image>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_title{
        E_title() 
        {  
            _field = "images.title";
        }
        std::string _field;
        typedef T_Page_Image::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_title _title(){ 
        return E_title();
    }
    struct E_src{
        E_src() 
        {  
            _field = "images.src";
        }
        std::string _field;
        typedef T_Page_Image::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_src _src(){ 
        return E_src();
    }
    struct E_alt{
        E_alt() 
        {  
            _field = "images.alt";
        }
        std::string _field;
        typedef T_Page_Image::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_alt _alt(){ 
        return E_alt();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "images.page_id";
        }
        std::string _field;
        typedef T_Page_Image::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "images.account_id";
        }
        std::string _field;
        typedef T_Page_Image::Condition ConditionType;
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
        ret.push_back("title");
        ret.push_back("src");
        ret.push_back("alt");
        ret.push_back("page_id");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_Page_Image> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page_Image> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page_Image>::Base>(res[i]["id"]);
            ret[i]._f_title._base =
                UTILS::fromString<F_String::Base>(res[i]["title"]);
            ret[i]._f_src._base =
                UTILS::fromString<F_String::Base>(res[i]["src"]);
            ret[i]._f_alt._base =
                UTILS::fromString<F_String::Base>(res[i]["alt"]);
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


    std::vector<O_Page_Image> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page_Image> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page_Image> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page_Image, bool> select(const I_Page_Image& id){
        return first(E_id() == id);
    }

    std::pair<O_Page_Image, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page_Image> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page_Image(), false);
    }

    std::pair<O_Page_Image, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page_Image>::const_iterator begin,
                         std::vector<O_Page_Image>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("title"));
        
        fields.push_back(std::string("src"));
        
        fields.push_back(std::string("alt"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page_Image& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._title()));
            
            row.push_back(toSQLString(r._src()));
            
            row.push_back(toSQLString(r._alt()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("images",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page_Image>::const_iterator begin,
                           std::vector<O_Page_Image>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page_Image>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_title._dirty){
                fields.push_back(std::string("title"));
                row.push_back(toSQLString(it->_title()));
            }
            
            if (it->_f_src._dirty){
                fields.push_back(std::string("src"));
                row.push_back(toSQLString(it->_src()));
            }
            
            if (it->_f_alt._dirty){
                fields.push_back(std::string("alt"));
                row.push_back(toSQLString(it->_alt()));
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
            ret = DBFace::instance()->insert("images",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE_IMAGE
