#ifndef O_ISSUE
#define O_ISSUE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_PageClass.hpp"
#include "T_Page.hpp"
#include "T_Account.hpp"



namespace DMMM {

class O_Issue{
public:

    O_Issue() {}

O_Issue(const I_Issue& id) 
        : _f_id(id)
        {}


    std::vector<O_PageClass> _page_classes() const
    {
        T_PageClass table;
        return table.select(table._page_class_id() == _id());   
    }
    std::vector<O_PageClass> 
    _page_class_id(const T_PageClass::Condition& c) const
    {
        T_PageClass table(c);
        return table.select(table._page_class_id() == _id());   
    }

    std::vector<O_Page> _pages() const
    {
        T_Page table;
        return table.select(table._page_id() == _id());   
    }
    std::vector<O_Page> 
    _page_id(const T_Page::Condition& c) const
    {
        T_Page table(c);
        return table.select(table._page_id() == _id());   
    }

    std::vector<O_Account> _accounts() const
    {
        T_Account table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Account> 
    _account_id(const T_Account::Condition& c) const
    {
        T_Account table(c);
        return table.select(table._account_id() == _id());   
    }

    const Field<I_Issue>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Issue>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _element() const { 
        return _f_element._base; 
    }
    F_String::Base& _element() { 
        _f_element._dirty = true; 
        return _f_element._base; 
    }
    const F_String::Base& _test() const { 
        return _f_test._base; 
    }
    F_String::Base& _test() { 
        _f_test._dirty = true; 
        return _f_test._base; 
    }
    const F_Float::Base& _impact() const { 
        return _f_impact._base; 
    }
    F_Float::Base& _impact() { 
        _f_impact._dirty = true; 
        return _f_impact._base; 
    }
    const F_Text::Base& _good_message() const { 
        return _f_good_message._base; 
    }
    F_Text::Base& _good_message() { 
        _f_good_message._dirty = true; 
        return _f_good_message._base; 
    }
    const F_Text::Base& _bad_message() const { 
        return _f_bad_message._base; 
    }
    F_Text::Base& _bad_message() { 
        _f_bad_message._dirty = true; 
        return _f_bad_message._base; 
    }
    const F_Text::Base& _solution() const { 
        return _f_solution._base; 
    }
    F_Text::Base& _solution() { 
        _f_solution._dirty = true; 
        return _f_solution._base; 
    }
    const F_Text::Base& _report_syntax() const { 
        return _f_report_syntax._base; 
    }
    F_Text::Base& _report_syntax() { 
        _f_report_syntax._dirty = true; 
        return _f_report_syntax._base; 
    }
    const F_String::Base& _category() const { 
        return _f_category._base; 
    }
    F_String::Base& _category() { 
        _f_category._dirty = true; 
        return _f_category._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_element._dirty)
            field2Val["element"] = 
                toSQLString(_f_element._base);
        if (_f_test._dirty)
            field2Val["test"] = 
                toSQLString(_f_test._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        if (_f_good_message._dirty)
            field2Val["good_message"] = 
                toSQLString(_f_good_message._base);
        if (_f_bad_message._dirty)
            field2Val["bad_message"] = 
                toSQLString(_f_bad_message._base);
        if (_f_solution._dirty)
            field2Val["solution"] = 
                toSQLString(_f_solution._base);
        if (_f_report_syntax._dirty)
            field2Val["report_syntax"] = 
                toSQLString(_f_report_syntax._base);
        if (_f_category._dirty)
            field2Val["category"] = 
                toSQLString(_f_category._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("issues", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_element._dirty = false;
            _f_test._dirty = false;
            _f_impact._dirty = false;
            _f_good_message._dirty = false;
            _f_bad_message._dirty = false;
            _f_solution._dirty = false;
            _f_report_syntax._dirty = false;
            _f_category._dirty = false;
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
        if (_f_element._dirty)
            field2Val["element"] = 
                toSQLString(_f_element._base);
        if (_f_test._dirty)
            field2Val["test"] = 
                toSQLString(_f_test._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        if (_f_good_message._dirty)
            field2Val["good_message"] = 
                toSQLString(_f_good_message._base);
        if (_f_bad_message._dirty)
            field2Val["bad_message"] = 
                toSQLString(_f_bad_message._base);
        if (_f_solution._dirty)
            field2Val["solution"] = 
                toSQLString(_f_solution._base);
        if (_f_report_syntax._dirty)
            field2Val["report_syntax"] = 
                toSQLString(_f_report_syntax._base);
        if (_f_category._dirty)
            field2Val["category"] = 
                toSQLString(_f_category._base);
        
        if (DBFace::instance()->
                insert("issues", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_element._dirty = false;
            _f_test._dirty = false;
            _f_impact._dirty = false;
            _f_good_message._dirty = false;
            _f_bad_message._dirty = false;
            _f_solution._dirty = false;
            _f_report_syntax._dirty = false;
            _f_category._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_Issue> _f_id;
    F_String _f_element;
    F_String _f_test;
    F_Float _f_impact;
    F_Text _f_good_message;
    F_Text _f_bad_message;
    F_Text _f_solution;
    F_Text _f_report_syntax;
    F_String _f_category;

    friend class T_Issue;
};

} //namespace DMMM
#endif //O_ISSUE
