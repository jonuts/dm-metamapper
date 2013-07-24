#ifndef O_TRACKEDBACKLINK
#define O_TRACKEDBACKLINK

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_TrackedBacklink{
public:

    O_TrackedBacklink() {}
    O_TrackedBacklink(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}

O_TrackedBacklink(const I_TrackedBacklink& id) 
        : _f_id(id)
        {}


    const Field<I_TrackedBacklink>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_TrackedBacklink>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _domain() const { 
        return _f_domain._base; 
    }
    F_String::Base& _domain() { 
        _f_domain._dirty = true; 
        return _f_domain._base; 
    }
    const F_String::Base& _page() const { 
        return _f_page._base; 
    }
    F_String::Base& _page() { 
        _f_page._dirty = true; 
        return _f_page._base; 
    }
    const F_String::Base& _target_page() const { 
        return _f_target_page._base; 
    }
    F_String::Base& _target_page() { 
        _f_target_page._dirty = true; 
        return _f_target_page._base; 
    }
    const F_String::Base& _anchor() const { 
        return _f_anchor._base; 
    }
    F_String::Base& _anchor() { 
        _f_anchor._dirty = true; 
        return _f_anchor._base; 
    }
    const F_Datetime::Base& _created_at() const { 
        return _f_created_at._base; 
    }
    F_Datetime::Base& _created_at() { 
        _f_created_at._dirty = true; 
        return _f_created_at._base; 
    }
    const F_Datetime::Base& _updated_at() const { 
        return _f_updated_at._base; 
    }
    F_Datetime::Base& _updated_at() { 
        _f_updated_at._dirty = true; 
        return _f_updated_at._base; 
    }
    const F_String::Base& _status() const { 
        return _f_status._base; 
    }
    F_String::Base& _status() { 
        _f_status._dirty = true; 
        return _f_status._base; 
    }
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_Boolean::Base& _is_placement() const { 
        return _f_is_placement._base; 
    }
    F_Boolean::Base& _is_placement() { 
        _f_is_placement._dirty = true; 
        return _f_is_placement._base; 
    }
    const F_Boolean::Base& _nofollow() const { 
        return _f_nofollow._base; 
    }
    F_Boolean::Base& _nofollow() { 
        _f_nofollow._dirty = true; 
        return _f_nofollow._base; 
    }
    const F_Boolean::Base& _sitewide() const { 
        return _f_sitewide._base; 
    }
    F_Boolean::Base& _sitewide() { 
        _f_sitewide._dirty = true; 
        return _f_sitewide._base; 
    }
    const F_Boolean::Base& _deep() const { 
        return _f_deep._base; 
    }
    F_Boolean::Base& _deep() { 
        _f_deep._dirty = true; 
        return _f_deep._base; 
    }
    const F_Integer::Base& _link_number() const { 
        return _f_link_number._base; 
    }
    F_Integer::Base& _link_number() { 
        _f_link_number._dirty = true; 
        return _f_link_number._base; 
    }
    const F_Integer::Base& _links_on_page() const { 
        return _f_links_on_page._base; 
    }
    F_Integer::Base& _links_on_page() { 
        _f_links_on_page._dirty = true; 
        return _f_links_on_page._base; 
    }
    const F_Integer::Base& _relevance() const { 
        return _f_relevance._base; 
    }
    F_Integer::Base& _relevance() { 
        _f_relevance._dirty = true; 
        return _f_relevance._base; 
    }
    const F_String::Base& _ip() const { 
        return _f_ip._base; 
    }
    F_String::Base& _ip() { 
        _f_ip._dirty = true; 
        return _f_ip._base; 
    }
    const F_Boolean::Base& _not_canonical() const { 
        return _f_not_canonical._base; 
    }
    F_Boolean::Base& _not_canonical() { 
        _f_not_canonical._dirty = true; 
        return _f_not_canonical._base; 
    }
    const F_Boolean::Base& _image() const { 
        return _f_image._base; 
    }
    F_Boolean::Base& _image() { 
        _f_image._dirty = true; 
        return _f_image._base; 
    }
    const F_Boolean::Base& _keyword_anchor() const { 
        return _f_keyword_anchor._base; 
    }
    F_Boolean::Base& _keyword_anchor() { 
        _f_keyword_anchor._dirty = true; 
        return _f_keyword_anchor._base; 
    }
    const F_Integer::Base& _duplicates() const { 
        return _f_duplicates._base; 
    }
    F_Integer::Base& _duplicates() { 
        _f_duplicates._dirty = true; 
        return _f_duplicates._base; 
    }
    const F_Integer::Base& _anchor_reps() const { 
        return _f_anchor_reps._base; 
    }
    F_Integer::Base& _anchor_reps() { 
        _f_anchor_reps._dirty = true; 
        return _f_anchor_reps._base; 
    }
    const F_Integer::Base& _num_from_source() const { 
        return _f_num_from_source._base; 
    }
    F_Integer::Base& _num_from_source() { 
        _f_num_from_source._dirty = true; 
        return _f_num_from_source._base; 
    }
    const F_Integer::Base& _spammyness() const { 
        return _f_spammyness._base; 
    }
    F_Integer::Base& _spammyness() { 
        _f_spammyness._dirty = true; 
        return _f_spammyness._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_domain._dirty)
            field2Val["domain"] = 
                toSQLString(_f_domain._base);
        if (_f_page._dirty)
            field2Val["page"] = 
                toSQLString(_f_page._base);
        if (_f_target_page._dirty)
            field2Val["target_page"] = 
                toSQLString(_f_target_page._base);
        if (_f_anchor._dirty)
            field2Val["anchor"] = 
                toSQLString(_f_anchor._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_status._dirty)
            field2Val["status"] = 
                toSQLString(_f_status._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_is_placement._dirty)
            field2Val["is_placement"] = 
                toSQLString(_f_is_placement._base);
        if (_f_nofollow._dirty)
            field2Val["nofollow"] = 
                toSQLString(_f_nofollow._base);
        if (_f_sitewide._dirty)
            field2Val["sitewide"] = 
                toSQLString(_f_sitewide._base);
        if (_f_deep._dirty)
            field2Val["deep"] = 
                toSQLString(_f_deep._base);
        if (_f_link_number._dirty)
            field2Val["link_number"] = 
                toSQLString(_f_link_number._base);
        if (_f_links_on_page._dirty)
            field2Val["links_on_page"] = 
                toSQLString(_f_links_on_page._base);
        if (_f_relevance._dirty)
            field2Val["relevance"] = 
                toSQLString(_f_relevance._base);
        if (_f_ip._dirty)
            field2Val["ip"] = 
                toSQLString(_f_ip._base);
        if (_f_not_canonical._dirty)
            field2Val["not_canonical"] = 
                toSQLString(_f_not_canonical._base);
        if (_f_image._dirty)
            field2Val["image"] = 
                toSQLString(_f_image._base);
        if (_f_keyword_anchor._dirty)
            field2Val["keyword_anchor"] = 
                toSQLString(_f_keyword_anchor._base);
        if (_f_duplicates._dirty)
            field2Val["duplicates"] = 
                toSQLString(_f_duplicates._base);
        if (_f_anchor_reps._dirty)
            field2Val["anchor_reps"] = 
                toSQLString(_f_anchor_reps._base);
        if (_f_num_from_source._dirty)
            field2Val["num_from_source"] = 
                toSQLString(_f_num_from_source._base);
        if (_f_spammyness._dirty)
            field2Val["spammyness"] = 
                toSQLString(_f_spammyness._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("tracked_backlinks", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_domain._dirty = false;
            _f_page._dirty = false;
            _f_target_page._dirty = false;
            _f_anchor._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_status._dirty = false;
            _f_account_id._dirty = false;
            _f_is_placement._dirty = false;
            _f_nofollow._dirty = false;
            _f_sitewide._dirty = false;
            _f_deep._dirty = false;
            _f_link_number._dirty = false;
            _f_links_on_page._dirty = false;
            _f_relevance._dirty = false;
            _f_ip._dirty = false;
            _f_not_canonical._dirty = false;
            _f_image._dirty = false;
            _f_keyword_anchor._dirty = false;
            _f_duplicates._dirty = false;
            _f_anchor_reps._dirty = false;
            _f_num_from_source._dirty = false;
            _f_spammyness._dirty = false;
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
        if (_f_domain._dirty)
            field2Val["domain"] = 
                toSQLString(_f_domain._base);
        if (_f_page._dirty)
            field2Val["page"] = 
                toSQLString(_f_page._base);
        if (_f_target_page._dirty)
            field2Val["target_page"] = 
                toSQLString(_f_target_page._base);
        if (_f_anchor._dirty)
            field2Val["anchor"] = 
                toSQLString(_f_anchor._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_status._dirty)
            field2Val["status"] = 
                toSQLString(_f_status._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_is_placement._dirty)
            field2Val["is_placement"] = 
                toSQLString(_f_is_placement._base);
        if (_f_nofollow._dirty)
            field2Val["nofollow"] = 
                toSQLString(_f_nofollow._base);
        if (_f_sitewide._dirty)
            field2Val["sitewide"] = 
                toSQLString(_f_sitewide._base);
        if (_f_deep._dirty)
            field2Val["deep"] = 
                toSQLString(_f_deep._base);
        if (_f_link_number._dirty)
            field2Val["link_number"] = 
                toSQLString(_f_link_number._base);
        if (_f_links_on_page._dirty)
            field2Val["links_on_page"] = 
                toSQLString(_f_links_on_page._base);
        if (_f_relevance._dirty)
            field2Val["relevance"] = 
                toSQLString(_f_relevance._base);
        if (_f_ip._dirty)
            field2Val["ip"] = 
                toSQLString(_f_ip._base);
        if (_f_not_canonical._dirty)
            field2Val["not_canonical"] = 
                toSQLString(_f_not_canonical._base);
        if (_f_image._dirty)
            field2Val["image"] = 
                toSQLString(_f_image._base);
        if (_f_keyword_anchor._dirty)
            field2Val["keyword_anchor"] = 
                toSQLString(_f_keyword_anchor._base);
        if (_f_duplicates._dirty)
            field2Val["duplicates"] = 
                toSQLString(_f_duplicates._base);
        if (_f_anchor_reps._dirty)
            field2Val["anchor_reps"] = 
                toSQLString(_f_anchor_reps._base);
        if (_f_num_from_source._dirty)
            field2Val["num_from_source"] = 
                toSQLString(_f_num_from_source._base);
        if (_f_spammyness._dirty)
            field2Val["spammyness"] = 
                toSQLString(_f_spammyness._base);
        
        if (DBFace::instance()->
                insert("tracked_backlinks", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_domain._dirty = false;
            _f_page._dirty = false;
            _f_target_page._dirty = false;
            _f_anchor._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_status._dirty = false;
            _f_account_id._dirty = false;
            _f_is_placement._dirty = false;
            _f_nofollow._dirty = false;
            _f_sitewide._dirty = false;
            _f_deep._dirty = false;
            _f_link_number._dirty = false;
            _f_links_on_page._dirty = false;
            _f_relevance._dirty = false;
            _f_ip._dirty = false;
            _f_not_canonical._dirty = false;
            _f_image._dirty = false;
            _f_keyword_anchor._dirty = false;
            _f_duplicates._dirty = false;
            _f_anchor_reps._dirty = false;
            _f_num_from_source._dirty = false;
            _f_spammyness._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_TrackedBacklink> _f_id;
    F_String _f_domain;
    F_String _f_page;
    F_String _f_target_page;
    F_String _f_anchor;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;
    F_String _f_status;
    Field<I_account_id> _f_account_id;
    F_Boolean _f_is_placement;
    F_Boolean _f_nofollow;
    F_Boolean _f_sitewide;
    F_Boolean _f_deep;
    F_Integer _f_link_number;
    F_Integer _f_links_on_page;
    F_Integer _f_relevance;
    F_String _f_ip;
    F_Boolean _f_not_canonical;
    F_Boolean _f_image;
    F_Boolean _f_keyword_anchor;
    F_Integer _f_duplicates;
    F_Integer _f_anchor_reps;
    F_Integer _f_num_from_source;
    F_Integer _f_spammyness;

    friend class T_TrackedBacklink;
};

} //namespace DMMM
#endif //O_TRACKEDBACKLINK
