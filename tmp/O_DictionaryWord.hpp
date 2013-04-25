#ifndef O_DICTIONARYWORD
#define O_DICTIONARYWORD

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_DictionaryWord{
public:

    O_DictionaryWord() {}
    O_DictionaryWord(const I_Language& parent_id) 
        : _f_language_id(parent_id)
        {}

O_DictionaryWord(const I_DictionaryWord& id) 
        : _f_id(id)
        {}


    const Field<I_DictionaryWord>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_DictionaryWord>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _text() const { 
        return _f_text._base; 
    }
    F_String::Base& _text() { 
        _f_text._dirty = true; 
        return _f_text._base; 
    }
    const F_Float::Base& _frequency() const { 
        return _f_frequency._base; 
    }
    F_Float::Base& _frequency() { 
        _f_frequency._dirty = true; 
        return _f_frequency._base; 
    }
    const Field<I_language_id>::Base& _language_id() const { 
        return _f_language_id._base; 
    }
    Field<I_language_id>::Base& _language_id() { 
        _f_language_id._dirty = true; 
        return _f_language_id._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_frequency._dirty)
            field2Val["frequency"] = 
                toSQLString(_f_frequency._base);
        if (_f_language_id._dirty)
            field2Val["language_id"] = 
                toSQLString(_f_language_id._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("dictionary_words", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_text._dirty = false;
            _f_frequency._dirty = false;
            _f_language_id._dirty = false;
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
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_frequency._dirty)
            field2Val["frequency"] = 
                toSQLString(_f_frequency._base);
        if (_f_language_id._dirty)
            field2Val["language_id"] = 
                toSQLString(_f_language_id._base);
        
        if (DBFace::instance()->
                insert("dictionary_words", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_text._dirty = false;
            _f_frequency._dirty = false;
            _f_language_id._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_DictionaryWord> _f_id;
    F_String _f_text;
    F_Float _f_frequency;
    Field<I_language_id> _f_language_id;

    friend class T_DictionaryWord;
};

} //namespace DMMM
#endif //O_DICTIONARYWORD
