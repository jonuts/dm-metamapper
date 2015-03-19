#ifndef O_PAGE
#define O_PAGE

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_Issue.hpp"
#include "T_SearchKeyword.hpp"
#include "T_MirrorPage.hpp"

enum EnumPagePROTOCOL { PAGE_PROTOCOL_HTTP = 1, PAGE_PROTOCOL_HTTPS = 2 };


namespace DMMM {

class O_Page{
public:

    O_Page() {}
    O_Page(const I_Account& parent_id) 
        : _f_account_id(parent_id)
        {}
    O_Page(const I_PageClass& parent_id) 
        : _f_page_class_id(parent_id)
        {}
    O_Page(const I_Language& parent_id) 
        : _f_language_id(parent_id)
        {}

O_Page(const I_Page& id) 
        : _f_id(id)
        {}


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

    std::vector<O_SearchKeyword> _search_keywords() const
    {
        T_SearchKeyword table;
        return table.select(table._search_keyword_id() == _id());   
    }
    std::vector<O_SearchKeyword> 
    _search_keyword_id(const T_SearchKeyword::Condition& c) const
    {
        T_SearchKeyword table(c);
        return table.select(table._search_keyword_id() == _id());   
    }

    std::vector<O_MirrorPage> _mirror_pages() const
    {
        T_MirrorPage table;
        return table.select(table._page_id() == _id());   
    }
    std::vector<O_MirrorPage> 
    _page_id(const T_MirrorPage::Condition& c) const
    {
        T_MirrorPage table(c);
        return table.select(table._page_id() == _id());   
    }

    const Field<I_page_class_id>::Base& _page_class_id() const { 
        return _f_page_class_id._base; 
    }
    Field<I_page_class_id>::Base& _page_class_id() { 
        _f_page_class_id._dirty = true; 
        return _f_page_class_id._base; 
    }
    const Field<I_Page>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Page>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _url() const { 
        return _f_url._base; 
    }
    F_String::Base& _url() { 
        _f_url._dirty = true; 
        return _f_url._base; 
    }
    const F_Float::Base& _above_rank() const { 
        return _f_above_rank._base; 
    }
    F_Float::Base& _above_rank() { 
        _f_above_rank._dirty = true; 
        return _f_above_rank._base; 
    }
    const F_Text::Base& _page_title() const { 
        return _f_page_title._base; 
    }
    F_Text::Base& _page_title() { 
        _f_page_title._dirty = true; 
        return _f_page_title._base; 
    }
    const F_Text::Base& _meta_description() const { 
        return _f_meta_description._base; 
    }
    F_Text::Base& _meta_description() { 
        _f_meta_description._dirty = true; 
        return _f_meta_description._base; 
    }
    const F_Text::Base& _meta_keywords() const { 
        return _f_meta_keywords._base; 
    }
    F_Text::Base& _meta_keywords() { 
        _f_meta_keywords._dirty = true; 
        return _f_meta_keywords._base; 
    }
    const F_Float::Base& _page_rank() const { 
        return _f_page_rank._base; 
    }
    F_Float::Base& _page_rank() { 
        _f_page_rank._dirty = true; 
        return _f_page_rank._base; 
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
    const Field<I_account_id>::Base& _account_id() const { 
        return _f_account_id._base; 
    }
    Field<I_account_id>::Base& _account_id() { 
        _f_account_id._dirty = true; 
        return _f_account_id._base; 
    }
    const F_Integer::Base& _depth() const { 
        return _f_depth._base; 
    }
    F_Integer::Base& _depth() { 
        _f_depth._dirty = true; 
        return _f_depth._base; 
    }
    const F_Integer::Base& _hashkey() const { 
        return _f_hashkey._base; 
    }
    F_Integer::Base& _hashkey() { 
        _f_hashkey._dirty = true; 
        return _f_hashkey._base; 
    }
    const F_Datetime::Base& _last_updated() const { 
        return _f_last_updated._base; 
    }
    F_Datetime::Base& _last_updated() { 
        _f_last_updated._dirty = true; 
        return _f_last_updated._base; 
    }
    const F_Datetime::Base& _last_mirrored() const { 
        return _f_last_mirrored._base; 
    }
    F_Datetime::Base& _last_mirrored() { 
        _f_last_mirrored._dirty = true; 
        return _f_last_mirrored._base; 
    }
    const F_Integer::Base& _score() const { 
        return _f_score._base; 
    }
    F_Integer::Base& _score() { 
        _f_score._dirty = true; 
        return _f_score._base; 
    }
    const F_Integer::Base& _priority() const { 
        return _f_priority._base; 
    }
    F_Integer::Base& _priority() { 
        _f_priority._dirty = true; 
        return _f_priority._base; 
    }
    const F_Float::Base& _impact() const { 
        return _f_impact._base; 
    }
    F_Float::Base& _impact() { 
        _f_impact._dirty = true; 
        return _f_impact._base; 
    }
    const F_Integer::Base& _class_picked_by_user() const { 
        return _f_class_picked_by_user._base; 
    }
    F_Integer::Base& _class_picked_by_user() { 
        _f_class_picked_by_user._dirty = true; 
        return _f_class_picked_by_user._base; 
    }
    const F_Text::Base& _unique_content() const { 
        return _f_unique_content._base; 
    }
    F_Text::Base& _unique_content() { 
        _f_unique_content._dirty = true; 
        return _f_unique_content._base; 
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
    const F_Integer::Base& _ever_found_backlinks() const { 
        return _f_ever_found_backlinks._base; 
    }
    F_Integer::Base& _ever_found_backlinks() { 
        _f_ever_found_backlinks._dirty = true; 
        return _f_ever_found_backlinks._base; 
    }
    const F_Integer::Base& _traffic() const { 
        return _f_traffic._base; 
    }
    F_Integer::Base& _traffic() { 
        _f_traffic._dirty = true; 
        return _f_traffic._base; 
    }
    const F_Integer::Base& _goal_completions() const { 
        return _f_goal_completions._base; 
    }
    F_Integer::Base& _goal_completions() { 
        _f_goal_completions._dirty = true; 
        return _f_goal_completions._base; 
    }
    const F_Integer::Base& _conversion_rate() const { 
        return _f_conversion_rate._base; 
    }
    F_Integer::Base& _conversion_rate() { 
        _f_conversion_rate._dirty = true; 
        return _f_conversion_rate._base; 
    }
    const F_Integer::Base& _classifier_needs_hint() const { 
        return _f_classifier_needs_hint._base; 
    }
    F_Integer::Base& _classifier_needs_hint() { 
        _f_classifier_needs_hint._dirty = true; 
        return _f_classifier_needs_hint._base; 
    }
    const F_Integer::Base& _page_id() const { 
        return _f_page_id._base; 
    }
    F_Integer::Base& _page_id() { 
        _f_page_id._dirty = true; 
        return _f_page_id._base; 
    }
    const F_Integer::Base& _page_score() const { 
        return _f_page_score._base; 
    }
    F_Integer::Base& _page_score() { 
        _f_page_score._dirty = true; 
        return _f_page_score._base; 
    }
    const F_Integer::Base& _is_duplicate() const { 
        return _f_is_duplicate._base; 
    }
    F_Integer::Base& _is_duplicate() { 
        _f_is_duplicate._dirty = true; 
        return _f_is_duplicate._base; 
    }
    const F_Integer::Base& _mirrored() const { 
        return _f_mirrored._base; 
    }
    F_Integer::Base& _mirrored() { 
        _f_mirrored._dirty = true; 
        return _f_mirrored._base; 
    }
    const F_Integer::Base& _number_of_bolds() const { 
        return _f_number_of_bolds._base; 
    }
    F_Integer::Base& _number_of_bolds() { 
        _f_number_of_bolds._dirty = true; 
        return _f_number_of_bolds._base; 
    }
    const F_Integer::Base& _number_of_italics() const { 
        return _f_number_of_italics._base; 
    }
    F_Integer::Base& _number_of_italics() { 
        _f_number_of_italics._dirty = true; 
        return _f_number_of_italics._base; 
    }
    const F_Integer::Base& _number_of_images() const { 
        return _f_number_of_images._base; 
    }
    F_Integer::Base& _number_of_images() { 
        _f_number_of_images._dirty = true; 
        return _f_number_of_images._base; 
    }
    const F_Integer::Base& _number_of_outbound_links() const { 
        return _f_number_of_outbound_links._base; 
    }
    F_Integer::Base& _number_of_outbound_links() { 
        _f_number_of_outbound_links._dirty = true; 
        return _f_number_of_outbound_links._base; 
    }
    const F_Integer::Base& _number_of_inbound_links() const { 
        return _f_number_of_inbound_links._base; 
    }
    F_Integer::Base& _number_of_inbound_links() { 
        _f_number_of_inbound_links._dirty = true; 
        return _f_number_of_inbound_links._base; 
    }
    const F_Integer::Base& _number_of_backlinks() const { 
        return _f_number_of_backlinks._base; 
    }
    F_Integer::Base& _number_of_backlinks() { 
        _f_number_of_backlinks._dirty = true; 
        return _f_number_of_backlinks._base; 
    }
    const F_Integer::Base& _number_of_h1s() const { 
        return _f_number_of_h1s._base; 
    }
    F_Integer::Base& _number_of_h1s() { 
        _f_number_of_h1s._dirty = true; 
        return _f_number_of_h1s._base; 
    }
    const F_Integer::Base& _number_of_h2s() const { 
        return _f_number_of_h2s._base; 
    }
    F_Integer::Base& _number_of_h2s() { 
        _f_number_of_h2s._dirty = true; 
        return _f_number_of_h2s._base; 
    }
    const F_Integer::Base& _number_of_h3s() const { 
        return _f_number_of_h3s._base; 
    }
    F_Integer::Base& _number_of_h3s() { 
        _f_number_of_h3s._dirty = true; 
        return _f_number_of_h3s._base; 
    }
    const F_String::Base& _old_pc_name() const { 
        return _f_old_pc_name._base; 
    }
    F_String::Base& _old_pc_name() { 
        _f_old_pc_name._dirty = true; 
        return _f_old_pc_name._base; 
    }
    const F_Integer::Base& _alt_tag_percentage() const { 
        return _f_alt_tag_percentage._base; 
    }
    F_Integer::Base& _alt_tag_percentage() { 
        _f_alt_tag_percentage._dirty = true; 
        return _f_alt_tag_percentage._base; 
    }
    const F_String::Base& _subdomain() const { 
        return _f_subdomain._base; 
    }
    F_String::Base& _subdomain() { 
        _f_subdomain._dirty = true; 
        return _f_subdomain._base; 
    }
    const Field<EnumPagePROTOCOL>::Base& _protocol() const { 
        return _f_protocol._base; 
    }
    Field<EnumPagePROTOCOL>::Base& _protocol() { 
        _f_protocol._dirty = true; 
        return _f_protocol._base; 
    }
    const F_Integer::Base& _number_of_duplicates() const { 
        return _f_number_of_duplicates._base; 
    }
    F_Integer::Base& _number_of_duplicates() { 
        _f_number_of_duplicates._dirty = true; 
        return _f_number_of_duplicates._base; 
    }
    const F_Integer::Base& _number_of_variants() const { 
        return _f_number_of_variants._base; 
    }
    F_Integer::Base& _number_of_variants() { 
        _f_number_of_variants._dirty = true; 
        return _f_number_of_variants._base; 
    }
    const Field<I_language_id>::Base& _language_id() const { 
        return _f_language_id._base; 
    }
    Field<I_language_id>::Base& _language_id() { 
        _f_language_id._dirty = true; 
        return _f_language_id._base; 
    }
    const F_Datetime::Base& _pr_updated_at() const { 
        return _f_pr_updated_at._base; 
    }
    F_Datetime::Base& _pr_updated_at() { 
        _f_pr_updated_at._dirty = true; 
        return _f_pr_updated_at._base; 
    }
    const F_Integer::Base& _unique_content_count() const { 
        return _f_unique_content_count._base; 
    }
    F_Integer::Base& _unique_content_count() { 
        _f_unique_content_count._dirty = true; 
        return _f_unique_content_count._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_class_id._dirty)
            field2Val["page_class_id"] = 
                toSQLString(_f_page_class_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_above_rank._dirty)
            field2Val["above_rank"] = 
                toSQLString(_f_above_rank._base);
        if (_f_page_title._dirty)
            field2Val["page_title"] = 
                toSQLString(_f_page_title._base);
        if (_f_meta_description._dirty)
            field2Val["meta_description"] = 
                toSQLString(_f_meta_description._base);
        if (_f_meta_keywords._dirty)
            field2Val["meta_keywords"] = 
                toSQLString(_f_meta_keywords._base);
        if (_f_page_rank._dirty)
            field2Val["page_rank"] = 
                toSQLString(_f_page_rank._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_depth._dirty)
            field2Val["depth"] = 
                toSQLString(_f_depth._base);
        if (_f_hashkey._dirty)
            field2Val["hashkey"] = 
                toSQLString(_f_hashkey._base);
        if (_f_last_updated._dirty)
            field2Val["last_updated"] = 
                toSQLString(_f_last_updated._base);
        if (_f_last_mirrored._dirty)
            field2Val["last_mirrored"] = 
                toSQLString(_f_last_mirrored._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        if (_f_class_picked_by_user._dirty)
            field2Val["class_picked_by_user"] = 
                toSQLString(_f_class_picked_by_user._base);
        if (_f_unique_content._dirty)
            field2Val["unique_content"] = 
                toSQLString(_f_unique_content._base);
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
        if (_f_ever_found_backlinks._dirty)
            field2Val["ever_found_backlinks"] = 
                toSQLString(_f_ever_found_backlinks._base);
        if (_f_traffic._dirty)
            field2Val["traffic"] = 
                toSQLString(_f_traffic._base);
        if (_f_goal_completions._dirty)
            field2Val["goal_completions"] = 
                toSQLString(_f_goal_completions._base);
        if (_f_conversion_rate._dirty)
            field2Val["conversion_rate"] = 
                toSQLString(_f_conversion_rate._base);
        if (_f_classifier_needs_hint._dirty)
            field2Val["classifier_needs_hint"] = 
                toSQLString(_f_classifier_needs_hint._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_page_score._dirty)
            field2Val["page_score"] = 
                toSQLString(_f_page_score._base);
        if (_f_is_duplicate._dirty)
            field2Val["is_duplicate"] = 
                toSQLString(_f_is_duplicate._base);
        if (_f_mirrored._dirty)
            field2Val["mirrored"] = 
                toSQLString(_f_mirrored._base);
        if (_f_number_of_bolds._dirty)
            field2Val["number_of_bolds"] = 
                toSQLString(_f_number_of_bolds._base);
        if (_f_number_of_italics._dirty)
            field2Val["number_of_italics"] = 
                toSQLString(_f_number_of_italics._base);
        if (_f_number_of_images._dirty)
            field2Val["number_of_images"] = 
                toSQLString(_f_number_of_images._base);
        if (_f_number_of_outbound_links._dirty)
            field2Val["number_of_outbound_links"] = 
                toSQLString(_f_number_of_outbound_links._base);
        if (_f_number_of_inbound_links._dirty)
            field2Val["number_of_inbound_links"] = 
                toSQLString(_f_number_of_inbound_links._base);
        if (_f_number_of_backlinks._dirty)
            field2Val["number_of_backlinks"] = 
                toSQLString(_f_number_of_backlinks._base);
        if (_f_number_of_h1s._dirty)
            field2Val["number_of_h1s"] = 
                toSQLString(_f_number_of_h1s._base);
        if (_f_number_of_h2s._dirty)
            field2Val["number_of_h2s"] = 
                toSQLString(_f_number_of_h2s._base);
        if (_f_number_of_h3s._dirty)
            field2Val["number_of_h3s"] = 
                toSQLString(_f_number_of_h3s._base);
        if (_f_old_pc_name._dirty)
            field2Val["old_pc_name"] = 
                toSQLString(_f_old_pc_name._base);
        if (_f_alt_tag_percentage._dirty)
            field2Val["alt_tag_percentage"] = 
                toSQLString(_f_alt_tag_percentage._base);
        if (_f_subdomain._dirty)
            field2Val["subdomain"] = 
                toSQLString(_f_subdomain._base);
        if (_f_protocol._dirty)
            field2Val["protocol"] = 
                toSQLString(_f_protocol._base);
        if (_f_number_of_duplicates._dirty)
            field2Val["number_of_duplicates"] = 
                toSQLString(_f_number_of_duplicates._base);
        if (_f_number_of_variants._dirty)
            field2Val["number_of_variants"] = 
                toSQLString(_f_number_of_variants._base);
        if (_f_language_id._dirty)
            field2Val["language_id"] = 
                toSQLString(_f_language_id._base);
        if (_f_pr_updated_at._dirty)
            field2Val["pr_updated_at"] = 
                toSQLString(_f_pr_updated_at._base);
        if (_f_unique_content_count._dirty)
            field2Val["unique_content_count"] = 
                toSQLString(_f_unique_content_count._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("pages", 
                                       field2Val, where))
        {
            _f_page_class_id._dirty = false;
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_above_rank._dirty = false;
            _f_page_title._dirty = false;
            _f_meta_description._dirty = false;
            _f_meta_keywords._dirty = false;
            _f_page_rank._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_account_id._dirty = false;
            _f_depth._dirty = false;
            _f_hashkey._dirty = false;
            _f_last_updated._dirty = false;
            _f_last_mirrored._dirty = false;
            _f_score._dirty = false;
            _f_priority._dirty = false;
            _f_impact._dirty = false;
            _f_class_picked_by_user._dirty = false;
            _f_unique_content._dirty = false;
            _f_page_titles_score._dirty = false;
            _f_metas_score._dirty = false;
            _f_links_score._dirty = false;
            _f_page_headers_score._dirty = false;
            _f_images_score._dirty = false;
            _f_emphases_score._dirty = false;
            _f_url_score._dirty = false;
            _f_ever_found_backlinks._dirty = false;
            _f_traffic._dirty = false;
            _f_goal_completions._dirty = false;
            _f_conversion_rate._dirty = false;
            _f_classifier_needs_hint._dirty = false;
            _f_page_id._dirty = false;
            _f_page_score._dirty = false;
            _f_is_duplicate._dirty = false;
            _f_mirrored._dirty = false;
            _f_number_of_bolds._dirty = false;
            _f_number_of_italics._dirty = false;
            _f_number_of_images._dirty = false;
            _f_number_of_outbound_links._dirty = false;
            _f_number_of_inbound_links._dirty = false;
            _f_number_of_backlinks._dirty = false;
            _f_number_of_h1s._dirty = false;
            _f_number_of_h2s._dirty = false;
            _f_number_of_h3s._dirty = false;
            _f_old_pc_name._dirty = false;
            _f_alt_tag_percentage._dirty = false;
            _f_subdomain._dirty = false;
            _f_protocol._dirty = false;
            _f_number_of_duplicates._dirty = false;
            _f_number_of_variants._dirty = false;
            _f_language_id._dirty = false;
            _f_pr_updated_at._dirty = false;
            _f_unique_content_count._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_page_class_id._dirty)
            field2Val["page_class_id"] = 
                toSQLString(_f_page_class_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_above_rank._dirty)
            field2Val["above_rank"] = 
                toSQLString(_f_above_rank._base);
        if (_f_page_title._dirty)
            field2Val["page_title"] = 
                toSQLString(_f_page_title._base);
        if (_f_meta_description._dirty)
            field2Val["meta_description"] = 
                toSQLString(_f_meta_description._base);
        if (_f_meta_keywords._dirty)
            field2Val["meta_keywords"] = 
                toSQLString(_f_meta_keywords._base);
        if (_f_page_rank._dirty)
            field2Val["page_rank"] = 
                toSQLString(_f_page_rank._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_account_id._dirty)
            field2Val["account_id"] = 
                toSQLString(_f_account_id._base);
        if (_f_depth._dirty)
            field2Val["depth"] = 
                toSQLString(_f_depth._base);
        if (_f_hashkey._dirty)
            field2Val["hashkey"] = 
                toSQLString(_f_hashkey._base);
        if (_f_last_updated._dirty)
            field2Val["last_updated"] = 
                toSQLString(_f_last_updated._base);
        if (_f_last_mirrored._dirty)
            field2Val["last_mirrored"] = 
                toSQLString(_f_last_mirrored._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_priority._dirty)
            field2Val["priority"] = 
                toSQLString(_f_priority._base);
        if (_f_impact._dirty)
            field2Val["impact"] = 
                toSQLString(_f_impact._base);
        if (_f_class_picked_by_user._dirty)
            field2Val["class_picked_by_user"] = 
                toSQLString(_f_class_picked_by_user._base);
        if (_f_unique_content._dirty)
            field2Val["unique_content"] = 
                toSQLString(_f_unique_content._base);
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
        if (_f_ever_found_backlinks._dirty)
            field2Val["ever_found_backlinks"] = 
                toSQLString(_f_ever_found_backlinks._base);
        if (_f_traffic._dirty)
            field2Val["traffic"] = 
                toSQLString(_f_traffic._base);
        if (_f_goal_completions._dirty)
            field2Val["goal_completions"] = 
                toSQLString(_f_goal_completions._base);
        if (_f_conversion_rate._dirty)
            field2Val["conversion_rate"] = 
                toSQLString(_f_conversion_rate._base);
        if (_f_classifier_needs_hint._dirty)
            field2Val["classifier_needs_hint"] = 
                toSQLString(_f_classifier_needs_hint._base);
        if (_f_page_id._dirty)
            field2Val["page_id"] = 
                toSQLString(_f_page_id._base);
        if (_f_page_score._dirty)
            field2Val["page_score"] = 
                toSQLString(_f_page_score._base);
        if (_f_is_duplicate._dirty)
            field2Val["is_duplicate"] = 
                toSQLString(_f_is_duplicate._base);
        if (_f_mirrored._dirty)
            field2Val["mirrored"] = 
                toSQLString(_f_mirrored._base);
        if (_f_number_of_bolds._dirty)
            field2Val["number_of_bolds"] = 
                toSQLString(_f_number_of_bolds._base);
        if (_f_number_of_italics._dirty)
            field2Val["number_of_italics"] = 
                toSQLString(_f_number_of_italics._base);
        if (_f_number_of_images._dirty)
            field2Val["number_of_images"] = 
                toSQLString(_f_number_of_images._base);
        if (_f_number_of_outbound_links._dirty)
            field2Val["number_of_outbound_links"] = 
                toSQLString(_f_number_of_outbound_links._base);
        if (_f_number_of_inbound_links._dirty)
            field2Val["number_of_inbound_links"] = 
                toSQLString(_f_number_of_inbound_links._base);
        if (_f_number_of_backlinks._dirty)
            field2Val["number_of_backlinks"] = 
                toSQLString(_f_number_of_backlinks._base);
        if (_f_number_of_h1s._dirty)
            field2Val["number_of_h1s"] = 
                toSQLString(_f_number_of_h1s._base);
        if (_f_number_of_h2s._dirty)
            field2Val["number_of_h2s"] = 
                toSQLString(_f_number_of_h2s._base);
        if (_f_number_of_h3s._dirty)
            field2Val["number_of_h3s"] = 
                toSQLString(_f_number_of_h3s._base);
        if (_f_old_pc_name._dirty)
            field2Val["old_pc_name"] = 
                toSQLString(_f_old_pc_name._base);
        if (_f_alt_tag_percentage._dirty)
            field2Val["alt_tag_percentage"] = 
                toSQLString(_f_alt_tag_percentage._base);
        if (_f_subdomain._dirty)
            field2Val["subdomain"] = 
                toSQLString(_f_subdomain._base);
        if (_f_protocol._dirty)
            field2Val["protocol"] = 
                toSQLString(_f_protocol._base);
        if (_f_number_of_duplicates._dirty)
            field2Val["number_of_duplicates"] = 
                toSQLString(_f_number_of_duplicates._base);
        if (_f_number_of_variants._dirty)
            field2Val["number_of_variants"] = 
                toSQLString(_f_number_of_variants._base);
        if (_f_language_id._dirty)
            field2Val["language_id"] = 
                toSQLString(_f_language_id._base);
        if (_f_pr_updated_at._dirty)
            field2Val["pr_updated_at"] = 
                toSQLString(_f_pr_updated_at._base);
        if (_f_unique_content_count._dirty)
            field2Val["unique_content_count"] = 
                toSQLString(_f_unique_content_count._base);
        
        if (DBFace::instance()->
                insert("pages", field2Val,
                       _f_id._base.serialization()))
        {
            _f_page_class_id._dirty = false;
            _f_id._dirty = false;
            _f_url._dirty = false;
            _f_above_rank._dirty = false;
            _f_page_title._dirty = false;
            _f_meta_description._dirty = false;
            _f_meta_keywords._dirty = false;
            _f_page_rank._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_account_id._dirty = false;
            _f_depth._dirty = false;
            _f_hashkey._dirty = false;
            _f_last_updated._dirty = false;
            _f_last_mirrored._dirty = false;
            _f_score._dirty = false;
            _f_priority._dirty = false;
            _f_impact._dirty = false;
            _f_class_picked_by_user._dirty = false;
            _f_unique_content._dirty = false;
            _f_page_titles_score._dirty = false;
            _f_metas_score._dirty = false;
            _f_links_score._dirty = false;
            _f_page_headers_score._dirty = false;
            _f_images_score._dirty = false;
            _f_emphases_score._dirty = false;
            _f_url_score._dirty = false;
            _f_ever_found_backlinks._dirty = false;
            _f_traffic._dirty = false;
            _f_goal_completions._dirty = false;
            _f_conversion_rate._dirty = false;
            _f_classifier_needs_hint._dirty = false;
            _f_page_id._dirty = false;
            _f_page_score._dirty = false;
            _f_is_duplicate._dirty = false;
            _f_mirrored._dirty = false;
            _f_number_of_bolds._dirty = false;
            _f_number_of_italics._dirty = false;
            _f_number_of_images._dirty = false;
            _f_number_of_outbound_links._dirty = false;
            _f_number_of_inbound_links._dirty = false;
            _f_number_of_backlinks._dirty = false;
            _f_number_of_h1s._dirty = false;
            _f_number_of_h2s._dirty = false;
            _f_number_of_h3s._dirty = false;
            _f_old_pc_name._dirty = false;
            _f_alt_tag_percentage._dirty = false;
            _f_subdomain._dirty = false;
            _f_protocol._dirty = false;
            _f_number_of_duplicates._dirty = false;
            _f_number_of_variants._dirty = false;
            _f_language_id._dirty = false;
            _f_pr_updated_at._dirty = false;
            _f_unique_content_count._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_page_class_id> _f_page_class_id;
    Field<I_Page> _f_id;
    F_String _f_url;
    F_Float _f_above_rank;
    F_Text _f_page_title;
    F_Text _f_meta_description;
    F_Text _f_meta_keywords;
    F_Float _f_page_rank;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;
    Field<I_account_id> _f_account_id;
    F_Integer _f_depth;
    F_Integer _f_hashkey;
    F_Datetime _f_last_updated;
    F_Datetime _f_last_mirrored;
    F_Integer _f_score;
    F_Integer _f_priority;
    F_Float _f_impact;
    F_Integer _f_class_picked_by_user;
    F_Text _f_unique_content;
    F_Integer _f_page_titles_score;
    F_Integer _f_metas_score;
    F_Integer _f_links_score;
    F_Integer _f_page_headers_score;
    F_Integer _f_images_score;
    F_Integer _f_emphases_score;
    F_Integer _f_url_score;
    F_Integer _f_ever_found_backlinks;
    F_Integer _f_traffic;
    F_Integer _f_goal_completions;
    F_Integer _f_conversion_rate;
    F_Integer _f_classifier_needs_hint;
    F_Integer _f_page_id;
    F_Integer _f_page_score;
    F_Integer _f_is_duplicate;
    F_Integer _f_mirrored;
    F_Integer _f_number_of_bolds;
    F_Integer _f_number_of_italics;
    F_Integer _f_number_of_images;
    F_Integer _f_number_of_outbound_links;
    F_Integer _f_number_of_inbound_links;
    F_Integer _f_number_of_backlinks;
    F_Integer _f_number_of_h1s;
    F_Integer _f_number_of_h2s;
    F_Integer _f_number_of_h3s;
    F_String _f_old_pc_name;
    F_Integer _f_alt_tag_percentage;
    F_String _f_subdomain;
    Field<EnumPagePROTOCOL> _f_protocol;
    F_Integer _f_number_of_duplicates;
    F_Integer _f_number_of_variants;
    Field<I_language_id> _f_language_id;
    F_Datetime _f_pr_updated_at;
    F_Integer _f_unique_content_count;

    friend class T_Page;
};

} //namespace DMMM
#endif //O_PAGE
