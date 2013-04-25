#ifndef O_PAGESEARCHKEYWORD
#define O_PAGESEARCHKEYWORD

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_MissingElement.hpp"



namespace DMMM {

class O_PageSearchKeyword{
public:

    O_PageSearchKeyword() {}
    O_PageSearchKeyword(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_PageSearchKeyword(const I_Page& parent_id) 
        : _f_page_id(parent_id)
        {}
    O_PageSearchKeyword(const I_SearchKeyword& parent_id) 
        : _f_search_keyword_id(parent_id)
        {}

O_PageSearchKeyword(const I_PageSearchKeyword& id) 
        : _f_id(id)
        {}


    std::vector<O_MissingElement> _missing_elements() const
    {
        T_MissingElement table;
        return table.select(table._page_search_keyword_id() == _id());   
    }
    std::vector<O_MissingElement> 
    _page_search_keyword_id(const T_MissingElement::Condition& c) const
    {
        T_MissingElement table(c);
        return table.select(table._page_search_keyword_id() == _id());   
    }

    const Field<I_page_id>::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    Field<I_page_id>::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const Field<I_search_keyword_id>::Base& _search_keyword_id() const { 
        return _f_search_keyword_id._base; 
    }
    Field<I_search_keyword_id>::Base& _search_keyword_id() { 
        _f_search_keyword_id._dirty = true; 
        return _f_search_keyword_id._base; 
    }
    const Field<I_PageSearchKeyword>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_PageSearchKeyword>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Integer::Base& _current_rank() const { 
        return _f_current_rank._base; 
    }
    F_Integer::Base& _current_rank() { 
        _f_current_rank._dirty = true; 
        return _f_current_rank._base; 
    }
    const F_Integer::Base& _target_rank() const { 
        return _f_target_rank._base; 
    }
    F_Integer::Base& _target_rank() { 
        _f_target_rank._dirty = true; 
        return _f_target_rank._base; 
    }
    const F_Datetime::Base& _deleted_at() const { 
        return _f_deleted_at._base; 
    }
    F_Datetime::Base& _deleted_at() { 
        _f_deleted_at._dirty = true; 
        return _f_deleted_at._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_Boolean::Base& _set_by_user() const { 
        return _f_set_by_user._base; 
    }
    F_Boolean::Base& _set_by_user() { 
        _f_set_by_user._dirty = true; 
        return _f_set_by_user._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_current_rank._dirty)
            field2Val["current_rank"] = 
                toSQLString(_f_current_rank._base);
        if (_f_target_rank._dirty)
            field2Val["target_rank"] = 
                toSQLString(_f_target_rank._base);
        if (_f_deleted_at._dirty)
            field2Val["deleted_at"] = 
                toSQLString(_f_deleted_at._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_set_by_user._dirty)
            field2Val["set_by_user"] = 
                toSQLString(_f_set_by_user._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("page_search_keywords", 
                                       field2Val, where))
        {
            _f_page_id._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_id._dirty = false;
            _f_current_rank._dirty = false;
            _f_target_rank._dirty = false;
            _f_deleted_at._dirty = false;
            _f_account_id._dirty = false;
            _f_set_by_user._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_search_keyword_id._dirty)
            field2Val["search_keyword_id"] = 
                toSQLString(_f_search_keyword_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_current_rank._dirty)
            field2Val["current_rank"] = 
                toSQLString(_f_current_rank._base);
        if (_f_target_rank._dirty)
            field2Val["target_rank"] = 
                toSQLString(_f_target_rank._base);
        if (_f_deleted_at._dirty)
            field2Val["deleted_at"] = 
                toSQLString(_f_deleted_at._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_set_by_user._dirty)
            field2Val["set_by_user"] = 
                toSQLString(_f_set_by_user._base);
        
        if (DBFace::instance()->
                insert("page_search_keywords", field2Val,
                       _f_id._base.serialization()))
        {
            _f_page_id._dirty = false;
            _f_search_keyword_id._dirty = false;
            _f_id._dirty = false;
            _f_current_rank._dirty = false;
            _f_target_rank._dirty = false;
            _f_deleted_at._dirty = false;
            _f_account_id._dirty = false;
            _f_set_by_user._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_page_id> _f_page_id;
    Field<I_search_keyword_id> _f_search_keyword_id;
    Field<I_PageSearchKeyword> _f_id;
    F_Integer _f_current_rank;
    F_Integer _f_target_rank;
    F_Datetime _f_deleted_at;
    Field<I_account_id> _f_account_id;
    F_Boolean _f_set_by_user;

    friend class T_PageSearchKeyword;
};

} //namespace DMMM
#endif //O_PAGESEARCHKEYWORD
