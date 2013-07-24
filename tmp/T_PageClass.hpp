
#ifndef T_PAGECLASS
#define T_PAGECLASS
#include "O_PageClass.hpp"

namespace DMMM {

class T_PageClass{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_PageClass() 
    {
        _tables.push_back("page_classes");
    }
    T_PageClass(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("page_classes");
    }

 

    T_PageClass(const I_Account& parentId)
    {
        _tables.push_back("page_classes");
        
        _constraint._cond = "(page_classes.account_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "page_classes.id";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef Field<I_PageClass>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "page_classes.name";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_above_rank{
        E_above_rank() 
        {  
            _field = "page_classes.above_rank";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_above_rank _above_rank(){ 
        return E_above_rank();
    }
    struct E_score{
        E_score() 
        {  
            _field = "page_classes.score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_score _score(){ 
        return E_score();
    }
    struct E_page_titles_score{
        E_page_titles_score() 
        {  
            _field = "page_classes.page_titles_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_page_titles_score _page_titles_score(){ 
        return E_page_titles_score();
    }
    struct E_metas_score{
        E_metas_score() 
        {  
            _field = "page_classes.metas_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_metas_score _metas_score(){ 
        return E_metas_score();
    }
    struct E_links_score{
        E_links_score() 
        {  
            _field = "page_classes.links_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_links_score _links_score(){ 
        return E_links_score();
    }
    struct E_page_headers_score{
        E_page_headers_score() 
        {  
            _field = "page_classes.page_headers_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_page_headers_score _page_headers_score(){ 
        return E_page_headers_score();
    }
    struct E_images_score{
        E_images_score() 
        {  
            _field = "page_classes.images_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_images_score _images_score(){ 
        return E_images_score();
    }
    struct E_emphases_score{
        E_emphases_score() 
        {  
            _field = "page_classes.emphases_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_emphases_score _emphases_score(){ 
        return E_emphases_score();
    }
    struct E_url_score{
        E_url_score() 
        {  
            _field = "page_classes.url_score";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_url_score _url_score(){ 
        return E_url_score();
    }
    struct E_priority{
        E_priority() 
        {  
            _field = "page_classes.priority";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_priority _priority(){ 
        return E_priority();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "page_classes.account_id";
        }
        std::string _field;
        typedef T_PageClass::Condition ConditionType;
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
        ret.push_back("name");
        ret.push_back("above_rank");
        ret.push_back("score");
        ret.push_back("page_titles_score");
        ret.push_back("metas_score");
        ret.push_back("links_score");
        ret.push_back("page_headers_score");
        ret.push_back("images_score");
        ret.push_back("emphases_score");
        ret.push_back("url_score");
        ret.push_back("priority");
        ret.push_back("account_id");
        return ret;
    }

    std::vector<O_PageClass> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_PageClass> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_PageClass>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_above_rank._base =
                UTILS::fromString<F_Float::Base>(res[i]["above_rank"]);
            ret[i]._f_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["score"]);
            ret[i]._f_page_titles_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["page_titles_score"]);
            ret[i]._f_metas_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["metas_score"]);
            ret[i]._f_links_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["links_score"]);
            ret[i]._f_page_headers_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["page_headers_score"]);
            ret[i]._f_images_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["images_score"]);
            ret[i]._f_emphases_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["emphases_score"]);
            ret[i]._f_url_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["url_score"]);
            ret[i]._f_priority._base =
                UTILS::fromString<F_Integer::Base>(res[i]["priority"]);
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


    std::vector<O_PageClass> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_PageClass> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_PageClass> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_PageClass, bool> select(const I_PageClass& id){
        return first(E_id() == id);
    }

    std::pair<O_PageClass, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_PageClass> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_PageClass(), false);
    }

    std::pair<O_PageClass, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_PageClass>::const_iterator begin,
                         std::vector<O_PageClass>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("above_rank"));
        
        fields.push_back(std::string("score"));
        
        fields.push_back(std::string("page_titles_score"));
        
        fields.push_back(std::string("metas_score"));
        
        fields.push_back(std::string("links_score"));
        
        fields.push_back(std::string("page_headers_score"));
        
        fields.push_back(std::string("images_score"));
        
        fields.push_back(std::string("emphases_score"));
        
        fields.push_back(std::string("url_score"));
        
        fields.push_back(std::string("priority"));
        
        fields.push_back(std::string("account_id"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_PageClass& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._above_rank()));
            
            row.push_back(toSQLString(r._score()));
            
            row.push_back(toSQLString(r._page_titles_score()));
            
            row.push_back(toSQLString(r._metas_score()));
            
            row.push_back(toSQLString(r._links_score()));
            
            row.push_back(toSQLString(r._page_headers_score()));
            
            row.push_back(toSQLString(r._images_score()));
            
            row.push_back(toSQLString(r._emphases_score()));
            
            row.push_back(toSQLString(r._url_score()));
            
            row.push_back(toSQLString(r._priority()));
            
            row.push_back(toSQLString(r._account_id()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("page_classes",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_PageClass>::const_iterator begin,
                           std::vector<O_PageClass>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_PageClass>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_above_rank._dirty){
                fields.push_back(std::string("above_rank"));
                row.push_back(toSQLString(it->_above_rank()));
            }
            
            if (it->_f_score._dirty){
                fields.push_back(std::string("score"));
                row.push_back(toSQLString(it->_score()));
            }
            
            if (it->_f_page_titles_score._dirty){
                fields.push_back(std::string("page_titles_score"));
                row.push_back(toSQLString(it->_page_titles_score()));
            }
            
            if (it->_f_metas_score._dirty){
                fields.push_back(std::string("metas_score"));
                row.push_back(toSQLString(it->_metas_score()));
            }
            
            if (it->_f_links_score._dirty){
                fields.push_back(std::string("links_score"));
                row.push_back(toSQLString(it->_links_score()));
            }
            
            if (it->_f_page_headers_score._dirty){
                fields.push_back(std::string("page_headers_score"));
                row.push_back(toSQLString(it->_page_headers_score()));
            }
            
            if (it->_f_images_score._dirty){
                fields.push_back(std::string("images_score"));
                row.push_back(toSQLString(it->_images_score()));
            }
            
            if (it->_f_emphases_score._dirty){
                fields.push_back(std::string("emphases_score"));
                row.push_back(toSQLString(it->_emphases_score()));
            }
            
            if (it->_f_url_score._dirty){
                fields.push_back(std::string("url_score"));
                row.push_back(toSQLString(it->_url_score()));
            }
            
            if (it->_f_priority._dirty){
                fields.push_back(std::string("priority"));
                row.push_back(toSQLString(it->_priority()));
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
            ret = DBFace::instance()->insert("page_classes",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGECLASS
