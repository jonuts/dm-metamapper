
#ifndef T_MIRRORPAGE
#define T_MIRRORPAGE
#include "O_MirrorPage.hpp"

namespace DMMM {

class T_MirrorPage{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_MirrorPage() 
    {
        _tables.push_back("mirror_pages");
    }
    T_MirrorPage(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("mirror_pages");
    }

 

    T_MirrorPage(const I_Account& parentId)
    {
        _tables.push_back("mirror_pages");
        
        _constraint._cond = "(mirror_pages.account_id = " + parentId.to_s() + ")";
    } 
 

    T_MirrorPage(const I_Page& parentId)
    {
        _tables.push_back("mirror_pages");
        
        _constraint._cond = "(mirror_pages.page_id = " + parentId.to_s() + ")";
    } 
 

    T_MirrorPage(const I_SearchKeyword& parentId)
    {
        _tables.push_back("mirror_pages");
        
        _constraint._cond = "(mirror_pages.search_keyword_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "mirror_pages.id";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef Field<I_MirrorPage>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "mirror_pages.account_id";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_url{
        E_url() 
        {  
            _field = "mirror_pages.url";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_url _url(){ 
        return E_url();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "mirror_pages.page_id";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef Field<I_page_id>::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_search_keyword_id{
        E_search_keyword_id() 
        {  
            _field = "mirror_pages.search_keyword_id";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef Field<I_search_keyword_id>::Base ComparerType;
    };

    static E_search_keyword_id _search_keyword_id(){ 
        return E_search_keyword_id();
    }
    struct E_source{
        E_source() 
        {  
            _field = "mirror_pages.source";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef Field<EnumMirrorPageSOURCE>::Base ComparerType;
    };

    static E_source _source(){ 
        return E_source();
    }
    struct E_score{
        E_score() 
        {  
            _field = "mirror_pages.score";
        }
        std::string _field;
        typedef T_MirrorPage::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_score _score(){ 
        return E_score();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("account_id");
        ret.push_back("url");
        ret.push_back("page_id");
        ret.push_back("search_keyword_id");
        ret.push_back("source");
        ret.push_back("score");
        return ret;
    }

    std::vector<O_MirrorPage> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_MirrorPage> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_MirrorPage>::Base>(res[i]["id"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_url._base =
                UTILS::fromString<F_String::Base>(res[i]["url"]);
            ret[i]._f_page_id._base =
                UTILS::fromString<Field<I_page_id>::Base>(res[i]["page_id"]);
            ret[i]._f_search_keyword_id._base =
                UTILS::fromString<Field<I_search_keyword_id>::Base>(res[i]["search_keyword_id"]);
            ret[i]._f_source._base =
                (Field<EnumMirrorPageSOURCE>::Base)UTILS::fromString<size_t>(res[i]["source"]);
            ret[i]._f_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["score"]);
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


    std::vector<O_MirrorPage> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_MirrorPage> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_MirrorPage> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_MirrorPage, bool> select(const I_MirrorPage& id){
        return first(E_id() == id);
    }

    std::pair<O_MirrorPage, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_MirrorPage> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_MirrorPage(), false);
    }

    std::pair<O_MirrorPage, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_MirrorPage>::const_iterator begin,
                         std::vector<O_MirrorPage>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("url"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("search_keyword_id"));
        
        fields.push_back(std::string("source"));
        
        fields.push_back(std::string("score"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_MirrorPage& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._url()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._search_keyword_id()));
            
            row.push_back(toSQLString(r._source()));
            
            row.push_back(toSQLString(r._score()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("mirror_pages",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_MirrorPage>::const_iterator begin,
                           std::vector<O_MirrorPage>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_MirrorPage>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_url._dirty){
                fields.push_back(std::string("url"));
                row.push_back(toSQLString(it->_url()));
            }
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
            
            if (it->_f_search_keyword_id._dirty){
                fields.push_back(std::string("search_keyword_id"));
                row.push_back(toSQLString(it->_search_keyword_id()));
            }
            
            if (it->_f_source._dirty){
                fields.push_back(std::string("source"));
                row.push_back(toSQLString(it->_source()));
            }
            
            if (it->_f_score._dirty){
                fields.push_back(std::string("score"));
                row.push_back(toSQLString(it->_score()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("mirror_pages",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_MIRRORPAGE
