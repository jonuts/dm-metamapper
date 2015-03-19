#ifndef O_KEYWORDEXCLUSION
#define O_KEYWORDEXCLUSION

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"

enum EnumKeywordExclusionEXCLUSION_TYPE { KEYWORDEXCLUSION_EXCLUSION_TYPE_WHOLE_KEYWORD = 1, KEYWORDEXCLUSION_EXCLUSION_TYPE_PART_OF_KEYWORD = 2, KEYWORDEXCLUSION_EXCLUSION_TYPE_COMPLETE_PART_OF_KEYWORD = 3 };


namespace DMMM {

class O_KeywordExclusion{
public:

    O_KeywordExclusion() {}

O_KeywordExclusion(const I_KeywordExclusion& id) 
        : _f_id(id)
        {}


    const Field<I_KeywordExclusion>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_KeywordExclusion>::Base& _id() { 
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
    const Field<EnumKeywordExclusionEXCLUSION_TYPE>::Base& _exclusion_type() const { 
        return _f_exclusion_type._base; 
    }
    Field<EnumKeywordExclusionEXCLUSION_TYPE>::Base& _exclusion_type() { 
        _f_exclusion_type._dirty = true; 
        return _f_exclusion_type._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_text._dirty)
            field2Val["text"] = 
                toSQLString(_f_text._base);
        if (_f_exclusion_type._dirty)
            field2Val["exclusion_type"] = 
                toSQLString(_f_exclusion_type._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("keyword_exclusions", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_text._dirty = false;
            _f_exclusion_type._dirty = false;
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
        if (_f_exclusion_type._dirty)
            field2Val["exclusion_type"] = 
                toSQLString(_f_exclusion_type._base);
        
        if (DBFace::instance()->
                insert("keyword_exclusions", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_text._dirty = false;
            _f_exclusion_type._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_KeywordExclusion> _f_id;
    F_String _f_text;
    Field<EnumKeywordExclusionEXCLUSION_TYPE> _f_exclusion_type;

    friend class T_KeywordExclusion;
};

} //namespace DMMM
#endif //O_KEYWORDEXCLUSION
