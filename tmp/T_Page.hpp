
#ifndef T_PAGE
#define T_PAGE
#include "O_Page.hpp"

namespace DMMM {

class T_Page{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Page() 
    {
        _tables.push_back("pages");
    }
    T_Page(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("pages");
    }

 

    T_Page(const I_Account& parentId)
    {
        _tables.push_back("pages");
        
        _constraint._cond = "(pages.account_id = " + parentId.to_s() + ")";
    } 
 

    T_Page(const I_PageClass& parentId)
    {
        _tables.push_back("pages");
        
        _constraint._cond = "(pages.page_class_id = " + parentId.to_s() + ")";
    } 
 

    T_Page(const I_Language& parentId)
    {
        _tables.push_back("pages");
        
        _constraint._cond = "(pages.language_id = " + parentId.to_s() + ")";
    } 
    
    struct E_page_class_id{
        E_page_class_id() 
        {  
            _field = "pages.page_class_id";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef Field<I_page_class_id>::Base ComparerType;
    };

    static E_page_class_id _page_class_id(){ 
        return E_page_class_id();
    }
    struct E_id{
        E_id() 
        {  
            _field = "pages.id";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef Field<I_Page>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_url{
        E_url() 
        {  
            _field = "pages.url";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_url _url(){ 
        return E_url();
    }
    struct E_above_rank{
        E_above_rank() 
        {  
            _field = "pages.above_rank";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_above_rank _above_rank(){ 
        return E_above_rank();
    }
    struct E_page_title{
        E_page_title() 
        {  
            _field = "pages.page_title";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_page_title _page_title(){ 
        return E_page_title();
    }
    struct E_meta_description{
        E_meta_description() 
        {  
            _field = "pages.meta_description";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_meta_description _meta_description(){ 
        return E_meta_description();
    }
    struct E_meta_keywords{
        E_meta_keywords() 
        {  
            _field = "pages.meta_keywords";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_meta_keywords _meta_keywords(){ 
        return E_meta_keywords();
    }
    struct E_page_rank{
        E_page_rank() 
        {  
            _field = "pages.page_rank";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_page_rank _page_rank(){ 
        return E_page_rank();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "pages.created_at";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "pages.updated_at";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "pages.account_id";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef Field<I_account_id>::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_depth{
        E_depth() 
        {  
            _field = "pages.depth";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_depth _depth(){ 
        return E_depth();
    }
    struct E_hashkey{
        E_hashkey() 
        {  
            _field = "pages.hashkey";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_hashkey _hashkey(){ 
        return E_hashkey();
    }
    struct E_last_updated{
        E_last_updated() 
        {  
            _field = "pages.last_updated";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_last_updated _last_updated(){ 
        return E_last_updated();
    }
    struct E_last_mirrored{
        E_last_mirrored() 
        {  
            _field = "pages.last_mirrored";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_last_mirrored _last_mirrored(){ 
        return E_last_mirrored();
    }
    struct E_score{
        E_score() 
        {  
            _field = "pages.score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_score _score(){ 
        return E_score();
    }
    struct E_priority{
        E_priority() 
        {  
            _field = "pages.priority";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_priority _priority(){ 
        return E_priority();
    }
    struct E_impact{
        E_impact() 
        {  
            _field = "pages.impact";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Float::Base ComparerType;
    };

    static E_impact _impact(){ 
        return E_impact();
    }
    struct E_class_picked_by_user{
        E_class_picked_by_user() 
        {  
            _field = "pages.class_picked_by_user";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_class_picked_by_user _class_picked_by_user(){ 
        return E_class_picked_by_user();
    }
    struct E_unique_content{
        E_unique_content() 
        {  
            _field = "pages.unique_content";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_unique_content _unique_content(){ 
        return E_unique_content();
    }
    struct E_page_titles_score{
        E_page_titles_score() 
        {  
            _field = "pages.page_titles_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_page_titles_score _page_titles_score(){ 
        return E_page_titles_score();
    }
    struct E_metas_score{
        E_metas_score() 
        {  
            _field = "pages.metas_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_metas_score _metas_score(){ 
        return E_metas_score();
    }
    struct E_links_score{
        E_links_score() 
        {  
            _field = "pages.links_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_links_score _links_score(){ 
        return E_links_score();
    }
    struct E_page_headers_score{
        E_page_headers_score() 
        {  
            _field = "pages.page_headers_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_page_headers_score _page_headers_score(){ 
        return E_page_headers_score();
    }
    struct E_images_score{
        E_images_score() 
        {  
            _field = "pages.images_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_images_score _images_score(){ 
        return E_images_score();
    }
    struct E_emphases_score{
        E_emphases_score() 
        {  
            _field = "pages.emphases_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_emphases_score _emphases_score(){ 
        return E_emphases_score();
    }
    struct E_url_score{
        E_url_score() 
        {  
            _field = "pages.url_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_url_score _url_score(){ 
        return E_url_score();
    }
    struct E_ever_found_backlinks{
        E_ever_found_backlinks() 
        {  
            _field = "pages.ever_found_backlinks";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_ever_found_backlinks _ever_found_backlinks(){ 
        return E_ever_found_backlinks();
    }
    struct E_traffic{
        E_traffic() 
        {  
            _field = "pages.traffic";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_traffic _traffic(){ 
        return E_traffic();
    }
    struct E_goal_completions{
        E_goal_completions() 
        {  
            _field = "pages.goal_completions";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_goal_completions _goal_completions(){ 
        return E_goal_completions();
    }
    struct E_conversion_rate{
        E_conversion_rate() 
        {  
            _field = "pages.conversion_rate";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_conversion_rate _conversion_rate(){ 
        return E_conversion_rate();
    }
    struct E_classifier_needs_hint{
        E_classifier_needs_hint() 
        {  
            _field = "pages.classifier_needs_hint";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_classifier_needs_hint _classifier_needs_hint(){ 
        return E_classifier_needs_hint();
    }
    struct E_page_id{
        E_page_id() 
        {  
            _field = "pages.page_id";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_page_id _page_id(){ 
        return E_page_id();
    }
    struct E_page_score{
        E_page_score() 
        {  
            _field = "pages.page_score";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_page_score _page_score(){ 
        return E_page_score();
    }
    struct E_is_duplicate{
        E_is_duplicate() 
        {  
            _field = "pages.is_duplicate";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_duplicate _is_duplicate(){ 
        return E_is_duplicate();
    }
    struct E_mirrored{
        E_mirrored() 
        {  
            _field = "pages.mirrored";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_mirrored _mirrored(){ 
        return E_mirrored();
    }
    struct E_number_of_bolds{
        E_number_of_bolds() 
        {  
            _field = "pages.number_of_bolds";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_bolds _number_of_bolds(){ 
        return E_number_of_bolds();
    }
    struct E_number_of_italics{
        E_number_of_italics() 
        {  
            _field = "pages.number_of_italics";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_italics _number_of_italics(){ 
        return E_number_of_italics();
    }
    struct E_number_of_images{
        E_number_of_images() 
        {  
            _field = "pages.number_of_images";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_images _number_of_images(){ 
        return E_number_of_images();
    }
    struct E_number_of_outbound_links{
        E_number_of_outbound_links() 
        {  
            _field = "pages.number_of_outbound_links";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_outbound_links _number_of_outbound_links(){ 
        return E_number_of_outbound_links();
    }
    struct E_number_of_inbound_links{
        E_number_of_inbound_links() 
        {  
            _field = "pages.number_of_inbound_links";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_inbound_links _number_of_inbound_links(){ 
        return E_number_of_inbound_links();
    }
    struct E_number_of_backlinks{
        E_number_of_backlinks() 
        {  
            _field = "pages.number_of_backlinks";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_backlinks _number_of_backlinks(){ 
        return E_number_of_backlinks();
    }
    struct E_number_of_h1s{
        E_number_of_h1s() 
        {  
            _field = "pages.number_of_h1s";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_h1s _number_of_h1s(){ 
        return E_number_of_h1s();
    }
    struct E_number_of_h2s{
        E_number_of_h2s() 
        {  
            _field = "pages.number_of_h2s";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_h2s _number_of_h2s(){ 
        return E_number_of_h2s();
    }
    struct E_number_of_h3s{
        E_number_of_h3s() 
        {  
            _field = "pages.number_of_h3s";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_h3s _number_of_h3s(){ 
        return E_number_of_h3s();
    }
    struct E_old_pc_name{
        E_old_pc_name() 
        {  
            _field = "pages.old_pc_name";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_old_pc_name _old_pc_name(){ 
        return E_old_pc_name();
    }
    struct E_alt_tag_percentage{
        E_alt_tag_percentage() 
        {  
            _field = "pages.alt_tag_percentage";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_alt_tag_percentage _alt_tag_percentage(){ 
        return E_alt_tag_percentage();
    }
    struct E_subdomain{
        E_subdomain() 
        {  
            _field = "pages.subdomain";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_subdomain _subdomain(){ 
        return E_subdomain();
    }
    struct E_protocol{
        E_protocol() 
        {  
            _field = "pages.protocol";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef Field<EnumPagePROTOCOL>::Base ComparerType;
    };

    static E_protocol _protocol(){ 
        return E_protocol();
    }
    struct E_number_of_duplicates{
        E_number_of_duplicates() 
        {  
            _field = "pages.number_of_duplicates";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_duplicates _number_of_duplicates(){ 
        return E_number_of_duplicates();
    }
    struct E_number_of_variants{
        E_number_of_variants() 
        {  
            _field = "pages.number_of_variants";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_number_of_variants _number_of_variants(){ 
        return E_number_of_variants();
    }
    struct E_language_id{
        E_language_id() 
        {  
            _field = "pages.language_id";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef Field<I_language_id>::Base ComparerType;
    };

    static E_language_id _language_id(){ 
        return E_language_id();
    }
    struct E_pr_updated_at{
        E_pr_updated_at() 
        {  
            _field = "pages.pr_updated_at";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_pr_updated_at _pr_updated_at(){ 
        return E_pr_updated_at();
    }
    struct E_unique_content_count{
        E_unique_content_count() 
        {  
            _field = "pages.unique_content_count";
        }
        std::string _field;
        typedef T_Page::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_unique_content_count _unique_content_count(){ 
        return E_unique_content_count();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("page_class_id");
        ret.push_back("id");
        ret.push_back("url");
        ret.push_back("above_rank");
        ret.push_back("page_title");
        ret.push_back("meta_description");
        ret.push_back("meta_keywords");
        ret.push_back("page_rank");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("account_id");
        ret.push_back("depth");
        ret.push_back("hashkey");
        ret.push_back("last_updated");
        ret.push_back("last_mirrored");
        ret.push_back("score");
        ret.push_back("priority");
        ret.push_back("impact");
        ret.push_back("class_picked_by_user");
        ret.push_back("unique_content");
        ret.push_back("page_titles_score");
        ret.push_back("metas_score");
        ret.push_back("links_score");
        ret.push_back("page_headers_score");
        ret.push_back("images_score");
        ret.push_back("emphases_score");
        ret.push_back("url_score");
        ret.push_back("ever_found_backlinks");
        ret.push_back("traffic");
        ret.push_back("goal_completions");
        ret.push_back("conversion_rate");
        ret.push_back("classifier_needs_hint");
        ret.push_back("page_id");
        ret.push_back("page_score");
        ret.push_back("is_duplicate");
        ret.push_back("mirrored");
        ret.push_back("number_of_bolds");
        ret.push_back("number_of_italics");
        ret.push_back("number_of_images");
        ret.push_back("number_of_outbound_links");
        ret.push_back("number_of_inbound_links");
        ret.push_back("number_of_backlinks");
        ret.push_back("number_of_h1s");
        ret.push_back("number_of_h2s");
        ret.push_back("number_of_h3s");
        ret.push_back("old_pc_name");
        ret.push_back("alt_tag_percentage");
        ret.push_back("subdomain");
        ret.push_back("protocol");
        ret.push_back("number_of_duplicates");
        ret.push_back("number_of_variants");
        ret.push_back("language_id");
        ret.push_back("pr_updated_at");
        ret.push_back("unique_content_count");
        return ret;
    }

    std::vector<O_Page> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Page> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_page_class_id._base =
                UTILS::fromString<Field<I_page_class_id>::Base>(res[i]["page_class_id"]);
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Page>::Base>(res[i]["id"]);
            ret[i]._f_url._base =
                UTILS::fromString<F_String::Base>(res[i]["url"]);
            ret[i]._f_above_rank._base =
                UTILS::fromString<F_Float::Base>(res[i]["above_rank"]);
            ret[i]._f_page_title._base =
                UTILS::fromString<F_Text::Base>(res[i]["page_title"]);
            ret[i]._f_meta_description._base =
                UTILS::fromString<F_Text::Base>(res[i]["meta_description"]);
            ret[i]._f_meta_keywords._base =
                UTILS::fromString<F_Text::Base>(res[i]["meta_keywords"]);
            ret[i]._f_page_rank._base =
                UTILS::fromString<F_Float::Base>(res[i]["page_rank"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<Field<I_account_id>::Base>(res[i]["account_id"]);
            ret[i]._f_depth._base =
                UTILS::fromString<F_Integer::Base>(res[i]["depth"]);
            ret[i]._f_hashkey._base =
                UTILS::fromString<F_Integer::Base>(res[i]["hashkey"]);
            ret[i]._f_last_updated._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["last_updated"]);
            ret[i]._f_last_mirrored._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["last_mirrored"]);
            ret[i]._f_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["score"]);
            ret[i]._f_priority._base =
                UTILS::fromString<F_Integer::Base>(res[i]["priority"]);
            ret[i]._f_impact._base =
                UTILS::fromString<F_Float::Base>(res[i]["impact"]);
            ret[i]._f_class_picked_by_user._base =
                UTILS::fromString<F_Integer::Base>(res[i]["class_picked_by_user"]);
            ret[i]._f_unique_content._base =
                UTILS::fromString<F_Text::Base>(res[i]["unique_content"]);
            ret[i]._f_page_titles_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["page_titles_score"]);
            ret[i]._f_metas_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["metas_score"]);
            ret[i]._f_links_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["links_score"]);
            ret[i]._f_page_headers_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["page_headers_score"]);
            ret[i]._f_images_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["images_score"]);
            ret[i]._f_emphases_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["emphases_score"]);
            ret[i]._f_url_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["url_score"]);
            ret[i]._f_ever_found_backlinks._base =
                UTILS::fromString<F_Integer::Base>(res[i]["ever_found_backlinks"]);
            ret[i]._f_traffic._base =
                UTILS::fromString<F_Integer::Base>(res[i]["traffic"]);
            ret[i]._f_goal_completions._base =
                UTILS::fromString<F_Integer::Base>(res[i]["goal_completions"]);
            ret[i]._f_conversion_rate._base =
                UTILS::fromString<F_Integer::Base>(res[i]["conversion_rate"]);
            ret[i]._f_classifier_needs_hint._base =
                UTILS::fromString<F_Integer::Base>(res[i]["classifier_needs_hint"]);
            ret[i]._f_page_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["page_id"]);
            ret[i]._f_page_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["page_score"]);
            ret[i]._f_is_duplicate._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_duplicate"]);
            ret[i]._f_mirrored._base =
                UTILS::fromString<F_Integer::Base>(res[i]["mirrored"]);
            ret[i]._f_number_of_bolds._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_bolds"]);
            ret[i]._f_number_of_italics._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_italics"]);
            ret[i]._f_number_of_images._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_images"]);
            ret[i]._f_number_of_outbound_links._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_outbound_links"]);
            ret[i]._f_number_of_inbound_links._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_inbound_links"]);
            ret[i]._f_number_of_backlinks._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_backlinks"]);
            ret[i]._f_number_of_h1s._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_h1s"]);
            ret[i]._f_number_of_h2s._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_h2s"]);
            ret[i]._f_number_of_h3s._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_h3s"]);
            ret[i]._f_old_pc_name._base =
                UTILS::fromString<F_String::Base>(res[i]["old_pc_name"]);
            ret[i]._f_alt_tag_percentage._base =
                UTILS::fromString<F_Integer::Base>(res[i]["alt_tag_percentage"]);
            ret[i]._f_subdomain._base =
                UTILS::fromString<F_String::Base>(res[i]["subdomain"]);
            ret[i]._f_protocol._base =
                (Field<EnumPagePROTOCOL>::Base)UTILS::fromString<size_t>(res[i]["protocol"]);
            ret[i]._f_number_of_duplicates._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_duplicates"]);
            ret[i]._f_number_of_variants._base =
                UTILS::fromString<F_Integer::Base>(res[i]["number_of_variants"]);
            ret[i]._f_language_id._base =
                UTILS::fromString<Field<I_language_id>::Base>(res[i]["language_id"]);
            ret[i]._f_pr_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["pr_updated_at"]);
            ret[i]._f_unique_content_count._base =
                UTILS::fromString<F_Integer::Base>(res[i]["unique_content_count"]);
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


    std::vector<O_Page> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Page> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Page> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Page, bool> select(const I_Page& id){
        return first(E_id() == id);
    }

    std::pair<O_Page, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Page> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Page(), false);
    }

    std::pair<O_Page, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Page>::const_iterator begin,
                         std::vector<O_Page>::const_iterator end)
    {
	std::vector<std::string> fields;
        
        fields.push_back(std::string("page_class_id"));
                
        fields.push_back(std::string("url"));
        
        fields.push_back(std::string("above_rank"));
        
        fields.push_back(std::string("page_title"));
        
        fields.push_back(std::string("meta_description"));
        
        fields.push_back(std::string("meta_keywords"));
        
        fields.push_back(std::string("page_rank"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("depth"));
        
        fields.push_back(std::string("hashkey"));
        
        fields.push_back(std::string("last_updated"));
        
        fields.push_back(std::string("last_mirrored"));
        
        fields.push_back(std::string("score"));
        
        fields.push_back(std::string("priority"));
        
        fields.push_back(std::string("impact"));
        
        fields.push_back(std::string("class_picked_by_user"));
        
        fields.push_back(std::string("unique_content"));
        
        fields.push_back(std::string("page_titles_score"));
        
        fields.push_back(std::string("metas_score"));
        
        fields.push_back(std::string("links_score"));
        
        fields.push_back(std::string("page_headers_score"));
        
        fields.push_back(std::string("images_score"));
        
        fields.push_back(std::string("emphases_score"));
        
        fields.push_back(std::string("url_score"));
        
        fields.push_back(std::string("ever_found_backlinks"));
        
        fields.push_back(std::string("traffic"));
        
        fields.push_back(std::string("goal_completions"));
        
        fields.push_back(std::string("conversion_rate"));
        
        fields.push_back(std::string("classifier_needs_hint"));
        
        fields.push_back(std::string("page_id"));
        
        fields.push_back(std::string("page_score"));
        
        fields.push_back(std::string("is_duplicate"));
        
        fields.push_back(std::string("mirrored"));
        
        fields.push_back(std::string("number_of_bolds"));
        
        fields.push_back(std::string("number_of_italics"));
        
        fields.push_back(std::string("number_of_images"));
        
        fields.push_back(std::string("number_of_outbound_links"));
        
        fields.push_back(std::string("number_of_inbound_links"));
        
        fields.push_back(std::string("number_of_backlinks"));
        
        fields.push_back(std::string("number_of_h1s"));
        
        fields.push_back(std::string("number_of_h2s"));
        
        fields.push_back(std::string("number_of_h3s"));
        
        fields.push_back(std::string("old_pc_name"));
        
        fields.push_back(std::string("alt_tag_percentage"));
        
        fields.push_back(std::string("subdomain"));
        
        fields.push_back(std::string("protocol"));
        
        fields.push_back(std::string("number_of_duplicates"));
        
        fields.push_back(std::string("number_of_variants"));
        
        fields.push_back(std::string("language_id"));
        
        fields.push_back(std::string("pr_updated_at"));
        
        fields.push_back(std::string("unique_content_count"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Page& r = *begin;
	    std::vector<std::string> row;
            
            row.push_back(toSQLString(r._page_class_id()));
                        
            row.push_back(toSQLString(r._url()));
            
            row.push_back(toSQLString(r._above_rank()));
            
            row.push_back(toSQLString(r._page_title()));
            
            row.push_back(toSQLString(r._meta_description()));
            
            row.push_back(toSQLString(r._meta_keywords()));
            
            row.push_back(toSQLString(r._page_rank()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._depth()));
            
            row.push_back(toSQLString(r._hashkey()));
            
            row.push_back(toSQLString(r._last_updated()));
            
            row.push_back(toSQLString(r._last_mirrored()));
            
            row.push_back(toSQLString(r._score()));
            
            row.push_back(toSQLString(r._priority()));
            
            row.push_back(toSQLString(r._impact()));
            
            row.push_back(toSQLString(r._class_picked_by_user()));
            
            row.push_back(toSQLString(r._unique_content()));
            
            row.push_back(toSQLString(r._page_titles_score()));
            
            row.push_back(toSQLString(r._metas_score()));
            
            row.push_back(toSQLString(r._links_score()));
            
            row.push_back(toSQLString(r._page_headers_score()));
            
            row.push_back(toSQLString(r._images_score()));
            
            row.push_back(toSQLString(r._emphases_score()));
            
            row.push_back(toSQLString(r._url_score()));
            
            row.push_back(toSQLString(r._ever_found_backlinks()));
            
            row.push_back(toSQLString(r._traffic()));
            
            row.push_back(toSQLString(r._goal_completions()));
            
            row.push_back(toSQLString(r._conversion_rate()));
            
            row.push_back(toSQLString(r._classifier_needs_hint()));
            
            row.push_back(toSQLString(r._page_id()));
            
            row.push_back(toSQLString(r._page_score()));
            
            row.push_back(toSQLString(r._is_duplicate()));
            
            row.push_back(toSQLString(r._mirrored()));
            
            row.push_back(toSQLString(r._number_of_bolds()));
            
            row.push_back(toSQLString(r._number_of_italics()));
            
            row.push_back(toSQLString(r._number_of_images()));
            
            row.push_back(toSQLString(r._number_of_outbound_links()));
            
            row.push_back(toSQLString(r._number_of_inbound_links()));
            
            row.push_back(toSQLString(r._number_of_backlinks()));
            
            row.push_back(toSQLString(r._number_of_h1s()));
            
            row.push_back(toSQLString(r._number_of_h2s()));
            
            row.push_back(toSQLString(r._number_of_h3s()));
            
            row.push_back(toSQLString(r._old_pc_name()));
            
            row.push_back(toSQLString(r._alt_tag_percentage()));
            
            row.push_back(toSQLString(r._subdomain()));
            
            row.push_back(toSQLString(r._protocol()));
            
            row.push_back(toSQLString(r._number_of_duplicates()));
            
            row.push_back(toSQLString(r._number_of_variants()));
            
            row.push_back(toSQLString(r._language_id()));
            
            row.push_back(toSQLString(r._pr_updated_at()));
            
            row.push_back(toSQLString(r._unique_content_count()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("pages",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Page>::const_iterator begin,
                           std::vector<O_Page>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Page>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
            
            if (it->_f_page_class_id._dirty){
                fields.push_back(std::string("page_class_id"));
                row.push_back(toSQLString(it->_page_class_id()));
            }
                        
            if (it->_f_url._dirty){
                fields.push_back(std::string("url"));
                row.push_back(toSQLString(it->_url()));
            }
            
            if (it->_f_above_rank._dirty){
                fields.push_back(std::string("above_rank"));
                row.push_back(toSQLString(it->_above_rank()));
            }
            
            if (it->_f_page_title._dirty){
                fields.push_back(std::string("page_title"));
                row.push_back(toSQLString(it->_page_title()));
            }
            
            if (it->_f_meta_description._dirty){
                fields.push_back(std::string("meta_description"));
                row.push_back(toSQLString(it->_meta_description()));
            }
            
            if (it->_f_meta_keywords._dirty){
                fields.push_back(std::string("meta_keywords"));
                row.push_back(toSQLString(it->_meta_keywords()));
            }
            
            if (it->_f_page_rank._dirty){
                fields.push_back(std::string("page_rank"));
                row.push_back(toSQLString(it->_page_rank()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_depth._dirty){
                fields.push_back(std::string("depth"));
                row.push_back(toSQLString(it->_depth()));
            }
            
            if (it->_f_hashkey._dirty){
                fields.push_back(std::string("hashkey"));
                row.push_back(toSQLString(it->_hashkey()));
            }
            
            if (it->_f_last_updated._dirty){
                fields.push_back(std::string("last_updated"));
                row.push_back(toSQLString(it->_last_updated()));
            }
            
            if (it->_f_last_mirrored._dirty){
                fields.push_back(std::string("last_mirrored"));
                row.push_back(toSQLString(it->_last_mirrored()));
            }
            
            if (it->_f_score._dirty){
                fields.push_back(std::string("score"));
                row.push_back(toSQLString(it->_score()));
            }
            
            if (it->_f_priority._dirty){
                fields.push_back(std::string("priority"));
                row.push_back(toSQLString(it->_priority()));
            }
            
            if (it->_f_impact._dirty){
                fields.push_back(std::string("impact"));
                row.push_back(toSQLString(it->_impact()));
            }
            
            if (it->_f_class_picked_by_user._dirty){
                fields.push_back(std::string("class_picked_by_user"));
                row.push_back(toSQLString(it->_class_picked_by_user()));
            }
            
            if (it->_f_unique_content._dirty){
                fields.push_back(std::string("unique_content"));
                row.push_back(toSQLString(it->_unique_content()));
            }
            
            if (it->_f_page_titles_score._dirty){
                fields.push_back(std::string("page_titles_score"));
                row.push_back(toSQLString(it->_page_titles_score()));
            }
            
            if (it->_f_metas_score._dirty){
                fields.push_back(std::string("metas_score"));
                row.push_back(toSQLString(it->_metas_score()));
            }
            
            if (it->_f_links_score._dirty){
                fields.push_back(std::string("links_score"));
                row.push_back(toSQLString(it->_links_score()));
            }
            
            if (it->_f_page_headers_score._dirty){
                fields.push_back(std::string("page_headers_score"));
                row.push_back(toSQLString(it->_page_headers_score()));
            }
            
            if (it->_f_images_score._dirty){
                fields.push_back(std::string("images_score"));
                row.push_back(toSQLString(it->_images_score()));
            }
            
            if (it->_f_emphases_score._dirty){
                fields.push_back(std::string("emphases_score"));
                row.push_back(toSQLString(it->_emphases_score()));
            }
            
            if (it->_f_url_score._dirty){
                fields.push_back(std::string("url_score"));
                row.push_back(toSQLString(it->_url_score()));
            }
            
            if (it->_f_ever_found_backlinks._dirty){
                fields.push_back(std::string("ever_found_backlinks"));
                row.push_back(toSQLString(it->_ever_found_backlinks()));
            }
            
            if (it->_f_traffic._dirty){
                fields.push_back(std::string("traffic"));
                row.push_back(toSQLString(it->_traffic()));
            }
            
            if (it->_f_goal_completions._dirty){
                fields.push_back(std::string("goal_completions"));
                row.push_back(toSQLString(it->_goal_completions()));
            }
            
            if (it->_f_conversion_rate._dirty){
                fields.push_back(std::string("conversion_rate"));
                row.push_back(toSQLString(it->_conversion_rate()));
            }
            
            if (it->_f_classifier_needs_hint._dirty){
                fields.push_back(std::string("classifier_needs_hint"));
                row.push_back(toSQLString(it->_classifier_needs_hint()));
            }
            
            if (it->_f_page_id._dirty){
                fields.push_back(std::string("page_id"));
                row.push_back(toSQLString(it->_page_id()));
            }
            
            if (it->_f_page_score._dirty){
                fields.push_back(std::string("page_score"));
                row.push_back(toSQLString(it->_page_score()));
            }
            
            if (it->_f_is_duplicate._dirty){
                fields.push_back(std::string("is_duplicate"));
                row.push_back(toSQLString(it->_is_duplicate()));
            }
            
            if (it->_f_mirrored._dirty){
                fields.push_back(std::string("mirrored"));
                row.push_back(toSQLString(it->_mirrored()));
            }
            
            if (it->_f_number_of_bolds._dirty){
                fields.push_back(std::string("number_of_bolds"));
                row.push_back(toSQLString(it->_number_of_bolds()));
            }
            
            if (it->_f_number_of_italics._dirty){
                fields.push_back(std::string("number_of_italics"));
                row.push_back(toSQLString(it->_number_of_italics()));
            }
            
            if (it->_f_number_of_images._dirty){
                fields.push_back(std::string("number_of_images"));
                row.push_back(toSQLString(it->_number_of_images()));
            }
            
            if (it->_f_number_of_outbound_links._dirty){
                fields.push_back(std::string("number_of_outbound_links"));
                row.push_back(toSQLString(it->_number_of_outbound_links()));
            }
            
            if (it->_f_number_of_inbound_links._dirty){
                fields.push_back(std::string("number_of_inbound_links"));
                row.push_back(toSQLString(it->_number_of_inbound_links()));
            }
            
            if (it->_f_number_of_backlinks._dirty){
                fields.push_back(std::string("number_of_backlinks"));
                row.push_back(toSQLString(it->_number_of_backlinks()));
            }
            
            if (it->_f_number_of_h1s._dirty){
                fields.push_back(std::string("number_of_h1s"));
                row.push_back(toSQLString(it->_number_of_h1s()));
            }
            
            if (it->_f_number_of_h2s._dirty){
                fields.push_back(std::string("number_of_h2s"));
                row.push_back(toSQLString(it->_number_of_h2s()));
            }
            
            if (it->_f_number_of_h3s._dirty){
                fields.push_back(std::string("number_of_h3s"));
                row.push_back(toSQLString(it->_number_of_h3s()));
            }
            
            if (it->_f_old_pc_name._dirty){
                fields.push_back(std::string("old_pc_name"));
                row.push_back(toSQLString(it->_old_pc_name()));
            }
            
            if (it->_f_alt_tag_percentage._dirty){
                fields.push_back(std::string("alt_tag_percentage"));
                row.push_back(toSQLString(it->_alt_tag_percentage()));
            }
            
            if (it->_f_subdomain._dirty){
                fields.push_back(std::string("subdomain"));
                row.push_back(toSQLString(it->_subdomain()));
            }
            
            if (it->_f_protocol._dirty){
                fields.push_back(std::string("protocol"));
                row.push_back(toSQLString(it->_protocol()));
            }
            
            if (it->_f_number_of_duplicates._dirty){
                fields.push_back(std::string("number_of_duplicates"));
                row.push_back(toSQLString(it->_number_of_duplicates()));
            }
            
            if (it->_f_number_of_variants._dirty){
                fields.push_back(std::string("number_of_variants"));
                row.push_back(toSQLString(it->_number_of_variants()));
            }
            
            if (it->_f_language_id._dirty){
                fields.push_back(std::string("language_id"));
                row.push_back(toSQLString(it->_language_id()));
            }
            
            if (it->_f_pr_updated_at._dirty){
                fields.push_back(std::string("pr_updated_at"));
                row.push_back(toSQLString(it->_pr_updated_at()));
            }
            
            if (it->_f_unique_content_count._dirty){
                fields.push_back(std::string("unique_content_count"));
                row.push_back(toSQLString(it->_unique_content_count()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("pages",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_PAGE
