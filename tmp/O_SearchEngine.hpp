#ifndef O_SEARCHENGINE
#define O_SEARCHENGINE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_SearchEngine{
public:

    O_SearchEngine() {}

O_SearchEngine(const I_SearchEngine& id) 
        : _f_id(id)
        {}


    const Field<I_SearchEngine>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_SearchEngine>::Base& _id() { 
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

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("search_engines", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
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
        
        if (DBFace::instance()->
                insert("search_engines", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_name._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_SearchEngine> _f_id;
    F_String _f_name;

    friend class T_SearchEngine;
};

} //namespace DMMM
#endif //O_SEARCHENGINE
