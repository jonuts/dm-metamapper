
#ifndef T_TRACKEDBACKLINK
#define T_TRACKEDBACKLINK
#include "O_TrackedBacklink.hpp"

namespace DMMM {

class T_TrackedBacklink{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_TrackedBacklink() 
    {
        _tables.push_back("tracked_backlinks");
    }
    T_TrackedBacklink(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("tracked_backlinks");
    }

 

    T_TrackedBacklink(const I_Account& parentId)
    {
        _tables.push_back("tracked_backlinks");
        
        _constraint._cond = "(tracked_backlinks.account_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "tracked_backlinks.id";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef Field<I_TrackedBacklink>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_domain{
        E_domain() 
        {  
            _field = "tracked_backlinks.domain";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_domain _domain(){ 
        return E_domain();
    }
    struct E_page{
        E_page() 
        {  
            _field = "tracked_backlinks.page";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_page _page(){ 
        return E_page();
    }
    struct E_target_page{
        E_target_page() 
        {  
            _field = "tracked_backlinks.target_page";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_target_page _target_page(){ 
        return E_target_page();
    }
    struct E_anchor{
        E_anchor() 
        {  
            _field = "tracked_backlinks.anchor";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_anchor _anchor(){ 
        return E_anchor();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "tracked_backlinks.created_at";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "tracked_backlinks.updated_at";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_status{
        E_status() 
        {  
            _field = "tracked_backlinks.status";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_status _status(){ 
        return E_status();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "tracked_backlinks.account_id";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_is_placement{
        E_is_placement() 
        {  
            _field = "tracked_backlinks.is_placement";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_is_placement _is_placement(){ 
        return E_is_placement();
    }
    struct E_nofollow{
        E_nofollow() 
        {  
            _field = "tracked_backlinks.nofollow";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_nofollow _nofollow(){ 
        return E_nofollow();
    }
    struct E_sitewide{
        E_sitewide() 
        {  
            _field = "tracked_backlinks.sitewide";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_sitewide _sitewide(){ 
        return E_sitewide();
    }
    struct E_deep{
        E_deep() 
        {  
            _field = "tracked_backlinks.deep";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_deep _deep(){ 
        return E_deep();
    }
    struct E_link_number{
        E_link_number() 
        {  
            _field = "tracked_backlinks.link_number";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_link_number _link_number(){ 
        return E_link_number();
    }
    struct E_links_on_page{
        E_links_on_page() 
        {  
            _field = "tracked_backlinks.links_on_page";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_links_on_page _links_on_page(){ 
        return E_links_on_page();
    }
    struct E_relevance{
        E_relevance() 
        {  
            _field = "tracked_backlinks.relevance";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_relevance _relevance(){ 
        return E_relevance();
    }
    struct E_ip{
        E_ip() 
        {  
            _field = "tracked_backlinks.ip";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_ip _ip(){ 
        return E_ip();
    }
    struct E_not_canonical{
        E_not_canonical() 
        {  
            _field = "tracked_backlinks.not_canonical";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_not_canonical _not_canonical(){ 
        return E_not_canonical();
    }
    struct E_image{
        E_image() 
        {  
            _field = "tracked_backlinks.image";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_image _image(){ 
        return E_image();
    }
    struct E_keyword_anchor{
        E_keyword_anchor() 
        {  
            _field = "tracked_backlinks.keyword_anchor";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_keyword_anchor _keyword_anchor(){ 
        return E_keyword_anchor();
    }
    struct E_duplicates{
        E_duplicates() 
        {  
            _field = "tracked_backlinks.duplicates";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_duplicates _duplicates(){ 
        return E_duplicates();
    }
    struct E_anchor_reps{
        E_anchor_reps() 
        {  
            _field = "tracked_backlinks.anchor_reps";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_anchor_reps _anchor_reps(){ 
        return E_anchor_reps();
    }
    struct E_num_from_source{
        E_num_from_source() 
        {  
            _field = "tracked_backlinks.num_from_source";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_num_from_source _num_from_source(){ 
        return E_num_from_source();
    }
    struct E_spammyness{
        E_spammyness() 
        {  
            _field = "tracked_backlinks.spammyness";
        }
        std::string _field;
        typedef T_TrackedBacklink::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_spammyness _spammyness(){ 
        return E_spammyness();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("domain");
        ret.push_back("page");
        ret.push_back("target_page");
        ret.push_back("anchor");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("status");
        ret.push_back("account_id");
        ret.push_back("is_placement");
        ret.push_back("nofollow");
        ret.push_back("sitewide");
        ret.push_back("deep");
        ret.push_back("link_number");
        ret.push_back("links_on_page");
        ret.push_back("relevance");
        ret.push_back("ip");
        ret.push_back("not_canonical");
        ret.push_back("image");
        ret.push_back("keyword_anchor");
        ret.push_back("duplicates");
        ret.push_back("anchor_reps");
        ret.push_back("num_from_source");
        ret.push_back("spammyness");
        return ret;
    }

    std::vector<O_TrackedBacklink> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_TrackedBacklink> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_TrackedBacklink>::Base>(res[i]["id"]);
            ret[i]._f_domain._base =
                UTILS::fromString<F_String::Base>(res[i]["domain"]);
            ret[i]._f_page._base =
                UTILS::fromString<F_String::Base>(res[i]["page"]);
            ret[i]._f_target_page._base =
                UTILS::fromString<F_String::Base>(res[i]["target_page"]);
            ret[i]._f_anchor._base =
                UTILS::fromString<F_String::Base>(res[i]["anchor"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_status._base =
                UTILS::fromString<F_String::Base>(res[i]["status"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_is_placement._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["is_placement"]);
            ret[i]._f_nofollow._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["nofollow"]);
            ret[i]._f_sitewide._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["sitewide"]);
            ret[i]._f_deep._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["deep"]);
            ret[i]._f_link_number._base =
                UTILS::fromString<F_Integer::Base>(res[i]["link_number"]);
            ret[i]._f_links_on_page._base =
                UTILS::fromString<F_Integer::Base>(res[i]["links_on_page"]);
            ret[i]._f_relevance._base =
                UTILS::fromString<F_Integer::Base>(res[i]["relevance"]);
            ret[i]._f_ip._base =
                UTILS::fromString<F_String::Base>(res[i]["ip"]);
            ret[i]._f_not_canonical._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["not_canonical"]);
            ret[i]._f_image._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["image"]);
            ret[i]._f_keyword_anchor._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["keyword_anchor"]);
            ret[i]._f_duplicates._base =
                UTILS::fromString<F_Integer::Base>(res[i]["duplicates"]);
            ret[i]._f_anchor_reps._base =
                UTILS::fromString<F_Integer::Base>(res[i]["anchor_reps"]);
            ret[i]._f_num_from_source._base =
                UTILS::fromString<F_Integer::Base>(res[i]["num_from_source"]);
            ret[i]._f_spammyness._base =
                UTILS::fromString<F_Integer::Base>(res[i]["spammyness"]);
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


    std::vector<O_TrackedBacklink> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_TrackedBacklink> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_TrackedBacklink> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_TrackedBacklink, bool> select(const I_TrackedBacklink& id){
        return first(E_id() == id);
    }

    std::pair<O_TrackedBacklink, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_TrackedBacklink> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_TrackedBacklink(), false);
    }

    std::pair<O_TrackedBacklink, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_TrackedBacklink>::const_iterator begin,
                         std::vector<O_TrackedBacklink>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("domain"));
        
        fields.push_back(std::string("page"));
        
        fields.push_back(std::string("target_page"));
        
        fields.push_back(std::string("anchor"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("status"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("is_placement"));
        
        fields.push_back(std::string("nofollow"));
        
        fields.push_back(std::string("sitewide"));
        
        fields.push_back(std::string("deep"));
        
        fields.push_back(std::string("link_number"));
        
        fields.push_back(std::string("links_on_page"));
        
        fields.push_back(std::string("relevance"));
        
        fields.push_back(std::string("ip"));
        
        fields.push_back(std::string("not_canonical"));
        
        fields.push_back(std::string("image"));
        
        fields.push_back(std::string("keyword_anchor"));
        
        fields.push_back(std::string("duplicates"));
        
        fields.push_back(std::string("anchor_reps"));
        
        fields.push_back(std::string("num_from_source"));
        
        fields.push_back(std::string("spammyness"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_TrackedBacklink& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._domain()));
            
            row.push_back(toSQLString(r._page()));
            
            row.push_back(toSQLString(r._target_page()));
            
            row.push_back(toSQLString(r._anchor()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._status()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._is_placement()));
            
            row.push_back(toSQLString(r._nofollow()));
            
            row.push_back(toSQLString(r._sitewide()));
            
            row.push_back(toSQLString(r._deep()));
            
            row.push_back(toSQLString(r._link_number()));
            
            row.push_back(toSQLString(r._links_on_page()));
            
            row.push_back(toSQLString(r._relevance()));
            
            row.push_back(toSQLString(r._ip()));
            
            row.push_back(toSQLString(r._not_canonical()));
            
            row.push_back(toSQLString(r._image()));
            
            row.push_back(toSQLString(r._keyword_anchor()));
            
            row.push_back(toSQLString(r._duplicates()));
            
            row.push_back(toSQLString(r._anchor_reps()));
            
            row.push_back(toSQLString(r._num_from_source()));
            
            row.push_back(toSQLString(r._spammyness()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("tracked_backlinks",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_TrackedBacklink>::const_iterator begin,
                           std::vector<O_TrackedBacklink>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_TrackedBacklink>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_domain._dirty){
                fields.push_back(std::string("domain"));
                row.push_back(toSQLString(it->_domain()));
            }
            
            if (it->_f_page._dirty){
                fields.push_back(std::string("page"));
                row.push_back(toSQLString(it->_page()));
            }
            
            if (it->_f_target_page._dirty){
                fields.push_back(std::string("target_page"));
                row.push_back(toSQLString(it->_target_page()));
            }
            
            if (it->_f_anchor._dirty){
                fields.push_back(std::string("anchor"));
                row.push_back(toSQLString(it->_anchor()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_status._dirty){
                fields.push_back(std::string("status"));
                row.push_back(toSQLString(it->_status()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_is_placement._dirty){
                fields.push_back(std::string("is_placement"));
                row.push_back(toSQLString(it->_is_placement()));
            }
            
            if (it->_f_nofollow._dirty){
                fields.push_back(std::string("nofollow"));
                row.push_back(toSQLString(it->_nofollow()));
            }
            
            if (it->_f_sitewide._dirty){
                fields.push_back(std::string("sitewide"));
                row.push_back(toSQLString(it->_sitewide()));
            }
            
            if (it->_f_deep._dirty){
                fields.push_back(std::string("deep"));
                row.push_back(toSQLString(it->_deep()));
            }
            
            if (it->_f_link_number._dirty){
                fields.push_back(std::string("link_number"));
                row.push_back(toSQLString(it->_link_number()));
            }
            
            if (it->_f_links_on_page._dirty){
                fields.push_back(std::string("links_on_page"));
                row.push_back(toSQLString(it->_links_on_page()));
            }
            
            if (it->_f_relevance._dirty){
                fields.push_back(std::string("relevance"));
                row.push_back(toSQLString(it->_relevance()));
            }
            
            if (it->_f_ip._dirty){
                fields.push_back(std::string("ip"));
                row.push_back(toSQLString(it->_ip()));
            }
            
            if (it->_f_not_canonical._dirty){
                fields.push_back(std::string("not_canonical"));
                row.push_back(toSQLString(it->_not_canonical()));
            }
            
            if (it->_f_image._dirty){
                fields.push_back(std::string("image"));
                row.push_back(toSQLString(it->_image()));
            }
            
            if (it->_f_keyword_anchor._dirty){
                fields.push_back(std::string("keyword_anchor"));
                row.push_back(toSQLString(it->_keyword_anchor()));
            }
            
            if (it->_f_duplicates._dirty){
                fields.push_back(std::string("duplicates"));
                row.push_back(toSQLString(it->_duplicates()));
            }
            
            if (it->_f_anchor_reps._dirty){
                fields.push_back(std::string("anchor_reps"));
                row.push_back(toSQLString(it->_anchor_reps()));
            }
            
            if (it->_f_num_from_source._dirty){
                fields.push_back(std::string("num_from_source"));
                row.push_back(toSQLString(it->_num_from_source()));
            }
            
            if (it->_f_spammyness._dirty){
                fields.push_back(std::string("spammyness"));
                row.push_back(toSQLString(it->_spammyness()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("tracked_backlinks",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_TRACKEDBACKLINK
