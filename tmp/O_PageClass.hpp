#ifndef O_PAGECLASS
#define O_PAGECLASS

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_Page.hpp"
#include "T_Issue.hpp"



namespace DMMM {

class O_PageClass{
public:

    O_PageClass() {}
    O_PageClass(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}

O_PageClass(const I_PageClass& id) 
        : _f_id(id)
        {}


    std::vector<O_Page> _pages() const
    {
        T_Page table;
        return table.select(table._page_class_id() == _id());   
    }
    std::vector<O_Page> 
    _page_class_id(const T_Page::Condition& c) const
    {
        T_Page table(c);
        return table.select(table._page_class_id() == _id());   
    }

    std::vector<O_Issue> _issues() const
    {
        T_Issue table;
        return table.select(table._issue_id() == _id());   
    }
    std::vector<O_Issue> 
    _issue_id(const T_Issue::Condition& c) const
    {
        T_Issue table(c);
        return table.select(table._issue_id() == _id());   
    }

    const Field<I_PageClass>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_PageClass>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _name() const { 
        return _f_name._base; 
    }
    F_String::Base& _name() { 
        _f_name._dirty = true; 
        return _f_name._base; 
    }
    const F_Float::Base& _above_rank() const { 
        return _f_above_rank._base; 
    }
    F_Float::Base& _above_rank() { 
        _f_above_rank._dirty = true; 
        return _f_above_rank._base; 
    }
    const F_Integer::Base& _score() const { 
        return _f_score._base; 
    }
    F_Integer::Base& _score() { 
        _f_score._dirty = true; 
        return _f_score._base; 
    }
    const F_Integer::Base& _page_titles_score() const { 
        return _f_page_titles_score._base; 
    }
    F_Integer::Base& _page_titles_score() { 
        _f_page_titles_score._dirty = true; 
        return _f_page_titles_score._base; 
    }
    const F_Integer::Base& _metas_score() const { 
        return _f_metas_score._base; 
    }
    F_Integer::Base& _metas_score() { 
        _f_metas_score._dirty = true; 
        return _f_metas_score._base; 
    }
    const F_Integer::Base& _links_score() const { 
        return _f_links_score._base; 
    }
    F_Integer::Base& _links_score() { 
        _f_links_score._dirty = true; 
        return _f_links_score._base; 
    }
    const F_Integer::Base& _page_headers_score() const { 
        return _f_page_headers_score._base; 
    }
    F_Integer::Base& _page_headers_score() { 
        _f_page_headers_score._dirty = true; 
        return _f_page_headers_score._base; 
    }
    const F_Integer::Base& _images_score() const { 
        return _f_images_score._base; 
    }
    F_Integer::Base& _images_score() { 
        _f_images_score._dirty = true; 
        return _f_images_score._base; 
    }
    const F_Integer::Base& _emphases_score() const { 
        return _f_emphases_score._base; 
    }
    F_Integer::Base& _emphases_score() { 
        _f_emphases_score._dirty = true; 
        return _f_emphases_score._base; 
    }
    const F_Integer::Base& _url_score() const { 
        return _f_url_score._base; 
    }
    F_Integer::Base& _url_score() { 
        _f_url_score._dirty = true; 
        return _f_url_score._base; 
    }
    const F_Integer::Base& _priority() const { 
        return _f_priority._base; 
    }
    F_Integer::Base& _priority() { 
        _f_priority._dirty = true; 
        return _f_priority._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_above_rank._dirty)
            field2Val["above_rank"] = 
                toSQLString(_f_above_rank._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_page_titles_score._dirty)
            field2Val["page_titles_score"] = 
                toSQLString(_f_page_titles_score._base);
        if (_f_metas_score._dirty)
            field2Val["metas_score"] = 
                toSQLString(_f_metas_score._base);
        if (_f_links_score._dirty)
            field2Val["links_score"] = 
                toSQLString(_f_links_score._base);
        if (_f_page_headers_score._dirty)
            field2Val["page_headers_score"] = 
                toSQLString(_f_page_headers_score._base);
        if (_f_images_score._dirty)
            field2Val["images_score"] = 
                toSQLString(_f_images_score._base);
        if (_f_emphases_score._dirty)
            field2Val["emphases_score"] = 
                toSQLString(_f_emphases_score._base);
        if (_f_url_score._dirty)
            field2Val["url_score"] = 
                toSQLString(_f_url_score._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("page_classes", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_above_rank._dirty = false;
            _f_score._dirty = false;
            _f_page_titles_score._dirty = false;
            _f_metas_score._dirty = false;
            _f_links_score._dirty = false;
            _f_page_headers_score._dirty = false;
            _f_images_score._dirty = false;
            _f_emphases_score._dirty = false;
            _f_url_score._dirty = false;
            _f_priority._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_above_rank._dirty)
            field2Val["above_rank"] = 
                toSQLString(_f_above_rank._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_page_titles_score._dirty)
            field2Val["page_titles_score"] = 
                toSQLString(_f_page_titles_score._base);
        if (_f_metas_score._dirty)
            field2Val["metas_score"] = 
                toSQLString(_f_metas_score._base);
        if (_f_links_score._dirty)
            field2Val["links_score"] = 
                toSQLString(_f_links_score._base);
        if (_f_page_headers_score._dirty)
            field2Val["page_headers_score"] = 
                toSQLString(_f_page_headers_score._base);
        if (_f_images_score._dirty)
            field2Val["images_score"] = 
                toSQLString(_f_images_score._base);
        if (_f_emphases_score._dirty)
            field2Val["emphases_score"] = 
                toSQLString(_f_emphases_score._base);
        if (_f_url_score._dirty)
            field2Val["url_score"] = 
                toSQLString(_f_url_score._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        
        if (DBFace::instance()->
                insert("page_classes", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_above_rank._dirty = false;
            _f_score._dirty = false;
            _f_page_titles_score._dirty = false;
            _f_metas_score._dirty = false;
            _f_links_score._dirty = false;
            _f_page_headers_score._dirty = false;
            _f_images_score._dirty = false;
            _f_emphases_score._dirty = false;
            _f_url_score._dirty = false;
            _f_priority._dirty = false;
            _f_account_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_PageClass> _f_id;
    F_String _f_name;
    F_Float _f_above_rank;
    F_Integer _f_score;
    F_Integer _f_page_titles_score;
    F_Integer _f_metas_score;
    F_Integer _f_links_score;
    F_Integer _f_page_headers_score;
    F_Integer _f_images_score;
    F_Integer _f_emphases_score;
    F_Integer _f_url_score;
    F_Integer _f_priority;
    Field<I_account_id> _f_account_id;

    friend class T_PageClass;
};

} //namespace DMMM
#endif //O_PAGECLASS
