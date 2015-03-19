
#ifndef T_ACCOUNT
#define T_ACCOUNT
#include "O_Account.hpp"

namespace DMMM {

class T_Account{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_Account() 
    {
        _tables.push_back("accounts");
    }
    T_Account(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("accounts");
    }

 

    T_Account(const I_Organization& parentId)
    {
        _tables.push_back("accounts");
        
        _constraint._cond = "(accounts.organization_id = " + parentId.to_s() + ")";
    } 
 

    T_Account(const I_AccountType& parentId)
    {
        _tables.push_back("accounts");
        
        _constraint._cond = "(accounts.account_type_id = " + parentId.to_s() + ")";
    } 
    
    
    struct E_user_id{
        E_user_id() 
        {  
            _field = "accounts.user_id";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_user_id _user_id(){ 
        return E_user_id();
    }
    struct E_id{
        E_id() 
        {  
            _field = "accounts.id";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<I_Account>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "accounts.name";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_site_category{
        E_site_category() 
        {  
            _field = "accounts.site_category";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_site_category _site_category(){ 
        return E_site_category();
    }
    struct E_url{
        E_url() 
        {  
            _field = "accounts.url";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_url _url(){ 
        return E_url();
    }
    struct E_mirrored_at{
        E_mirrored_at() 
        {  
            _field = "accounts.mirrored_at";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_mirrored_at _mirrored_at(){ 
        return E_mirrored_at();
    }
    struct E_analyzed_at{
        E_analyzed_at() 
        {  
            _field = "accounts.analyzed_at";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_analyzed_at _analyzed_at(){ 
        return E_analyzed_at();
    }
    struct E_is_mirroring{
        E_is_mirroring() 
        {  
            _field = "accounts.is_mirroring";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_mirroring _is_mirroring(){ 
        return E_is_mirroring();
    }
    struct E_is_parsing{
        E_is_parsing() 
        {  
            _field = "accounts.is_parsing";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_parsing _is_parsing(){ 
        return E_is_parsing();
    }
    struct E_is_keywording{
        E_is_keywording() 
        {  
            _field = "accounts.is_keywording";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_keywording _is_keywording(){ 
        return E_is_keywording();
    }
    struct E_is_ranking{
        E_is_ranking() 
        {  
            _field = "accounts.is_ranking";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_ranking _is_ranking(){ 
        return E_is_ranking();
    }
    struct E_is_classifying{
        E_is_classifying() 
        {  
            _field = "accounts.is_classifying";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_classifying _is_classifying(){ 
        return E_is_classifying();
    }
    struct E_is_scoring{
        E_is_scoring() 
        {  
            _field = "accounts.is_scoring";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_scoring _is_scoring(){ 
        return E_is_scoring();
    }
    struct E_is_google_suggesting{
        E_is_google_suggesting() 
        {  
            _field = "accounts.is_google_suggesting";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_google_suggesting _is_google_suggesting(){ 
        return E_is_google_suggesting();
    }
    struct E_is_analyticsing{
        E_is_analyticsing() 
        {  
            _field = "accounts.is_analyticsing";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_analyticsing _is_analyticsing(){ 
        return E_is_analyticsing();
    }
    struct E_has_mirror{
        E_has_mirror() 
        {  
            _field = "accounts.has_mirror";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_has_mirror _has_mirror(){ 
        return E_has_mirror();
    }
    struct E_analyzed{
        E_analyzed() 
        {  
            _field = "accounts.analyzed";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_analyzed _analyzed(){ 
        return E_analyzed();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "accounts.created_at";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "accounts.updated_at";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_mirror_percent{
        E_mirror_percent() 
        {  
            _field = "accounts.mirror_percent";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_mirror_percent _mirror_percent(){ 
        return E_mirror_percent();
    }
    struct E_scoring_percent{
        E_scoring_percent() 
        {  
            _field = "accounts.scoring_percent";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_scoring_percent _scoring_percent(){ 
        return E_scoring_percent();
    }
    struct E_ranking_percent{
        E_ranking_percent() 
        {  
            _field = "accounts.ranking_percent";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_ranking_percent _ranking_percent(){ 
        return E_ranking_percent();
    }
    struct E_last_page_mirrored{
        E_last_page_mirrored() 
        {  
            _field = "accounts.last_page_mirrored";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_last_page_mirrored _last_page_mirrored(){ 
        return E_last_page_mirrored();
    }
    struct E_last_page_classified{
        E_last_page_classified() 
        {  
            _field = "accounts.last_page_classified";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_last_page_classified _last_page_classified(){ 
        return E_last_page_classified();
    }
    struct E_score{
        E_score() 
        {  
            _field = "accounts.score";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_score _score(){ 
        return E_score();
    }
    struct E_ga_username{
        E_ga_username() 
        {  
            _field = "accounts.ga_username";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_ga_username _ga_username(){ 
        return E_ga_username();
    }
    struct E_ga_password{
        E_ga_password() 
        {  
            _field = "accounts.ga_password";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_ga_password _ga_password(){ 
        return E_ga_password();
    }
    struct E_google_indexed_pages{
        E_google_indexed_pages() 
        {  
            _field = "accounts.google_indexed_pages";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_google_indexed_pages _google_indexed_pages(){ 
        return E_google_indexed_pages();
    }
    struct E_classifier_feedback{
        E_classifier_feedback() 
        {  
            _field = "accounts.classifier_feedback";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_classifier_feedback _classifier_feedback(){ 
        return E_classifier_feedback();
    }
    struct E_deleted_at{
        E_deleted_at() 
        {  
            _field = "accounts.deleted_at";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_deleted_at _deleted_at(){ 
        return E_deleted_at();
    }
    struct E_using_score_view_advanced_search{
        E_using_score_view_advanced_search() 
        {  
            _field = "accounts.using_score_view_advanced_search";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_using_score_view_advanced_search _using_score_view_advanced_search(){ 
        return E_using_score_view_advanced_search();
    }
    struct E_frozen_tag_list{
        E_frozen_tag_list() 
        {  
            _field = "accounts.frozen_tag_list";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_frozen_tag_list _frozen_tag_list(){ 
        return E_frozen_tag_list();
    }
    struct E_logo_file_name{
        E_logo_file_name() 
        {  
            _field = "accounts.logo_file_name";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_logo_file_name _logo_file_name(){ 
        return E_logo_file_name();
    }
    struct E_logo_content_type{
        E_logo_content_type() 
        {  
            _field = "accounts.logo_content_type";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_logo_content_type _logo_content_type(){ 
        return E_logo_content_type();
    }
    struct E_logo_file_size{
        E_logo_file_size() 
        {  
            _field = "accounts.logo_file_size";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_logo_file_size _logo_file_size(){ 
        return E_logo_file_size();
    }
    struct E_logo_updated_at{
        E_logo_updated_at() 
        {  
            _field = "accounts.logo_updated_at";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_logo_updated_at _logo_updated_at(){ 
        return E_logo_updated_at();
    }
    struct E_spider_entry_page{
        E_spider_entry_page() 
        {  
            _field = "accounts.spider_entry_page";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_spider_entry_page _spider_entry_page(){ 
        return E_spider_entry_page();
    }
    struct E_ga_account_id{
        E_ga_account_id() 
        {  
            _field = "accounts.ga_account_id";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_ga_account_id _ga_account_id(){ 
        return E_ga_account_id();
    }
    struct E_reload_classifier{
        E_reload_classifier() 
        {  
            _field = "accounts.reload_classifier";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_reload_classifier _reload_classifier(){ 
        return E_reload_classifier();
    }
    struct E_mirror_exclusions{
        E_mirror_exclusions() 
        {  
            _field = "accounts.mirror_exclusions";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_mirror_exclusions _mirror_exclusions(){ 
        return E_mirror_exclusions();
    }
    struct E_max_pages_mirrored{
        E_max_pages_mirrored() 
        {  
            _field = "accounts.max_pages_mirrored";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_max_pages_mirrored _max_pages_mirrored(){ 
        return E_max_pages_mirrored();
    }
    struct E_crawl_delay{
        E_crawl_delay() 
        {  
            _field = "accounts.crawl_delay";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_crawl_delay _crawl_delay(){ 
        return E_crawl_delay();
    }
    struct E_google_locale{
        E_google_locale() 
        {  
            _field = "accounts.google_locale";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<EnumAccountGOOGLE_LOCALE>::Base ComparerType;
    };

    static E_google_locale _google_locale(){ 
        return E_google_locale();
    }
    struct E_crawler_name{
        E_crawler_name() 
        {  
            _field = "accounts.crawler_name";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<EnumAccountCRAWLER_NAME>::Base ComparerType;
    };

    static E_crawler_name _crawler_name(){ 
        return E_crawler_name();
    }
    struct E_mirror_inclusions{
        E_mirror_inclusions() 
        {  
            _field = "accounts.mirror_inclusions";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_mirror_inclusions _mirror_inclusions(){ 
        return E_mirror_inclusions();
    }
    struct E_kw_limit{
        E_kw_limit() 
        {  
            _field = "accounts.kw_limit";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_kw_limit _kw_limit(){ 
        return E_kw_limit();
    }
    struct E_has_ga_credentials{
        E_has_ga_credentials() 
        {  
            _field = "accounts.has_ga_credentials";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_has_ga_credentials _has_ga_credentials(){ 
        return E_has_ga_credentials();
    }
    struct E_ga_profiles{
        E_ga_profiles() 
        {  
            _field = "accounts.ga_profiles";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_ga_profiles _ga_profiles(){ 
        return E_ga_profiles();
    }
    struct E_ga_profile{
        E_ga_profile() 
        {  
            _field = "accounts.ga_profile";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_ga_profile _ga_profile(){ 
        return E_ga_profile();
    }
    struct E_last_mirror_activity{
        E_last_mirror_activity() 
        {  
            _field = "accounts.last_mirror_activity";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_last_mirror_activity _last_mirror_activity(){ 
        return E_last_mirror_activity();
    }
    struct E_follow_robots_txt{
        E_follow_robots_txt() 
        {  
            _field = "accounts.follow_robots_txt";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_follow_robots_txt _follow_robots_txt(){ 
        return E_follow_robots_txt();
    }
    struct E_has_robots_txt{
        E_has_robots_txt() 
        {  
            _field = "accounts.has_robots_txt";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_robots_txt _has_robots_txt(){ 
        return E_has_robots_txt();
    }
    struct E_has_sitemap{
        E_has_sitemap() 
        {  
            _field = "accounts.has_sitemap";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_sitemap _has_sitemap(){ 
        return E_has_sitemap();
    }
    struct E_sitemap_in_robots{
        E_sitemap_in_robots() 
        {  
            _field = "accounts.sitemap_in_robots";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_sitemap_in_robots _sitemap_in_robots(){ 
        return E_sitemap_in_robots();
    }
    struct E_all_subdomains{
        E_all_subdomains() 
        {  
            _field = "accounts.all_subdomains";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_all_subdomains _all_subdomains(){ 
        return E_all_subdomains();
    }
    struct E_has_baidu{
        E_has_baidu() 
        {  
            _field = "accounts.has_baidu";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_baidu _has_baidu(){ 
        return E_has_baidu();
    }
    struct E_has_yandex{
        E_has_yandex() 
        {  
            _field = "accounts.has_yandex";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_yandex _has_yandex(){ 
        return E_has_yandex();
    }
    struct E_account_type{
        E_account_type() 
        {  
            _field = "accounts.account_type";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_account_type _account_type(){ 
        return E_account_type();
    }
    struct E_account_type_id{
        E_account_type_id() 
        {  
            _field = "accounts.account_type_id";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<I_account_type_id>::Base ComparerType;
    };

    static E_account_type_id _account_type_id(){ 
        return E_account_type_id();
    }
    struct E_has_yandex_ru{
        E_has_yandex_ru() 
        {  
            _field = "accounts.has_yandex_ru";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_yandex_ru _has_yandex_ru(){ 
        return E_has_yandex_ru();
    }
    struct E_has_yandex_ua{
        E_has_yandex_ua() 
        {  
            _field = "accounts.has_yandex_ua";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_yandex_ua _has_yandex_ua(){ 
        return E_has_yandex_ua();
    }
    struct E_subdomain_option{
        E_subdomain_option() 
        {  
            _field = "accounts.subdomain_option";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<EnumAccountSUBDOMAIN_OPTION>::Base ComparerType;
    };

    static E_subdomain_option _subdomain_option(){ 
        return E_subdomain_option();
    }
    struct E_setup_step{
        E_setup_step() 
        {  
            _field = "accounts.setup_step";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_setup_step _setup_step(){ 
        return E_setup_step();
    }
    struct E_mirroring_threads{
        E_mirroring_threads() 
        {  
            _field = "accounts.mirroring_threads";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_mirroring_threads _mirroring_threads(){ 
        return E_mirroring_threads();
    }
    struct E_default_protocol{
        E_default_protocol() 
        {  
            _field = "accounts.default_protocol";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<EnumAccountDEFAULT_PROTOCOL>::Base ComparerType;
    };

    static E_default_protocol _default_protocol(){ 
        return E_default_protocol();
    }
    struct E_score_keywords_in_urls{
        E_score_keywords_in_urls() 
        {  
            _field = "accounts.score_keywords_in_urls";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_keywords_in_urls _score_keywords_in_urls(){ 
        return E_score_keywords_in_urls();
    }
    struct E_score_content_in_urls{
        E_score_content_in_urls() 
        {  
            _field = "accounts.score_content_in_urls";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_content_in_urls _score_content_in_urls(){ 
        return E_score_content_in_urls();
    }
    struct E_score_existing_titles{
        E_score_existing_titles() 
        {  
            _field = "accounts.score_existing_titles";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_existing_titles _score_existing_titles(){ 
        return E_score_existing_titles();
    }
    struct E_score_unique_titles{
        E_score_unique_titles() 
        {  
            _field = "accounts.score_unique_titles";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_unique_titles _score_unique_titles(){ 
        return E_score_unique_titles();
    }
    struct E_score_keywords_in_titles{
        E_score_keywords_in_titles() 
        {  
            _field = "accounts.score_keywords_in_titles";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_keywords_in_titles _score_keywords_in_titles(){ 
        return E_score_keywords_in_titles();
    }
    struct E_score_content_in_titles{
        E_score_content_in_titles() 
        {  
            _field = "accounts.score_content_in_titles";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_content_in_titles _score_content_in_titles(){ 
        return E_score_content_in_titles();
    }
    struct E_score_outbound_links{
        E_score_outbound_links() 
        {  
            _field = "accounts.score_outbound_links";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_outbound_links _score_outbound_links(){ 
        return E_score_outbound_links();
    }
    struct E_score_unique_content{
        E_score_unique_content() 
        {  
            _field = "accounts.score_unique_content";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_unique_content _score_unique_content(){ 
        return E_score_unique_content();
    }
    struct E_score_existing_meta_description{
        E_score_existing_meta_description() 
        {  
            _field = "accounts.score_existing_meta_description";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_existing_meta_description _score_existing_meta_description(){ 
        return E_score_existing_meta_description();
    }
    struct E_score_unique_meta_description{
        E_score_unique_meta_description() 
        {  
            _field = "accounts.score_unique_meta_description";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_unique_meta_description _score_unique_meta_description(){ 
        return E_score_unique_meta_description();
    }
    struct E_score_keywords_in_meta_description{
        E_score_keywords_in_meta_description() 
        {  
            _field = "accounts.score_keywords_in_meta_description";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_keywords_in_meta_description _score_keywords_in_meta_description(){ 
        return E_score_keywords_in_meta_description();
    }
    struct E_score_content_in_meta_description{
        E_score_content_in_meta_description() 
        {  
            _field = "accounts.score_content_in_meta_description";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_content_in_meta_description _score_content_in_meta_description(){ 
        return E_score_content_in_meta_description();
    }
    struct E_score_overused_meta_description{
        E_score_overused_meta_description() 
        {  
            _field = "accounts.score_overused_meta_description";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_overused_meta_description _score_overused_meta_description(){ 
        return E_score_overused_meta_description();
    }
    struct E_score_existing_meta_keywords{
        E_score_existing_meta_keywords() 
        {  
            _field = "accounts.score_existing_meta_keywords";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_existing_meta_keywords _score_existing_meta_keywords(){ 
        return E_score_existing_meta_keywords();
    }
    struct E_score_unique_meta_keywords{
        E_score_unique_meta_keywords() 
        {  
            _field = "accounts.score_unique_meta_keywords";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_unique_meta_keywords _score_unique_meta_keywords(){ 
        return E_score_unique_meta_keywords();
    }
    struct E_score_misused_meta_keywords{
        E_score_misused_meta_keywords() 
        {  
            _field = "accounts.score_misused_meta_keywords";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_misused_meta_keywords _score_misused_meta_keywords(){ 
        return E_score_misused_meta_keywords();
    }
    struct E_score_overused_meta_keywords{
        E_score_overused_meta_keywords() 
        {  
            _field = "accounts.score_overused_meta_keywords";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_overused_meta_keywords _score_overused_meta_keywords(){ 
        return E_score_overused_meta_keywords();
    }
    struct E_score_existing_headers{
        E_score_existing_headers() 
        {  
            _field = "accounts.score_existing_headers";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_existing_headers _score_existing_headers(){ 
        return E_score_existing_headers();
    }
    struct E_score_overused_headers{
        E_score_overused_headers() 
        {  
            _field = "accounts.score_overused_headers";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_overused_headers _score_overused_headers(){ 
        return E_score_overused_headers();
    }
    struct E_score_keywords_in_headers{
        E_score_keywords_in_headers() 
        {  
            _field = "accounts.score_keywords_in_headers";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_keywords_in_headers _score_keywords_in_headers(){ 
        return E_score_keywords_in_headers();
    }
    struct E_score_existing_h1{
        E_score_existing_h1() 
        {  
            _field = "accounts.score_existing_h1";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_existing_h1 _score_existing_h1(){ 
        return E_score_existing_h1();
    }
    struct E_score_images{
        E_score_images() 
        {  
            _field = "accounts.score_images";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_images _score_images(){ 
        return E_score_images();
    }
    struct E_score_existing_emphasis{
        E_score_existing_emphasis() 
        {  
            _field = "accounts.score_existing_emphasis";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_existing_emphasis _score_existing_emphasis(){ 
        return E_score_existing_emphasis();
    }
    struct E_score_keywords_in_emphasis{
        E_score_keywords_in_emphasis() 
        {  
            _field = "accounts.score_keywords_in_emphasis";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_keywords_in_emphasis _score_keywords_in_emphasis(){ 
        return E_score_keywords_in_emphasis();
    }
    struct E_score_overused_emphasis{
        E_score_overused_emphasis() 
        {  
            _field = "accounts.score_overused_emphasis";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_score_overused_emphasis _score_overused_emphasis(){ 
        return E_score_overused_emphasis();
    }
    struct E_base_url{
        E_base_url() 
        {  
            _field = "accounts.base_url";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_base_url _base_url(){ 
        return E_base_url();
    }
    struct E_follow_links{
        E_follow_links() 
        {  
            _field = "accounts.follow_links";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_follow_links _follow_links(){ 
        return E_follow_links();
    }
    struct E_nofollow_links{
        E_nofollow_links() 
        {  
            _field = "accounts.nofollow_links";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_nofollow_links _nofollow_links(){ 
        return E_nofollow_links();
    }
    struct E_has_mail_ru{
        E_has_mail_ru() 
        {  
            _field = "accounts.has_mail_ru";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_has_mail_ru _has_mail_ru(){ 
        return E_has_mail_ru();
    }
    struct E_organization_id{
        E_organization_id() 
        {  
            _field = "accounts.organization_id";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef Field<I_organization_id>::Base ComparerType;
    };

    static E_organization_id _organization_id(){ 
        return E_organization_id();
    }
    struct E_ignore_crawl_delay{
        E_ignore_crawl_delay() 
        {  
            _field = "accounts.ignore_crawl_delay";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_ignore_crawl_delay _ignore_crawl_delay(){ 
        return E_ignore_crawl_delay();
    }
    struct E_follow_all{
        E_follow_all() 
        {  
            _field = "accounts.follow_all";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_follow_all _follow_all(){ 
        return E_follow_all();
    }
    struct E_use_follow_links{
        E_use_follow_links() 
        {  
            _field = "accounts.use_follow_links";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_use_follow_links _use_follow_links(){ 
        return E_use_follow_links();
    }
    struct E_use_nofollow_links{
        E_use_nofollow_links() 
        {  
            _field = "accounts.use_nofollow_links";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_use_nofollow_links _use_nofollow_links(){ 
        return E_use_nofollow_links();
    }
    struct E_mirror_all{
        E_mirror_all() 
        {  
            _field = "accounts.mirror_all";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_mirror_all _mirror_all(){ 
        return E_mirror_all();
    }
    struct E_use_mirror_include{
        E_use_mirror_include() 
        {  
            _field = "accounts.use_mirror_include";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_use_mirror_include _use_mirror_include(){ 
        return E_use_mirror_include();
    }
    struct E_use_mirror_exclude{
        E_use_mirror_exclude() 
        {  
            _field = "accounts.use_mirror_exclude";
        }
        std::string _field;
        typedef T_Account::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_use_mirror_exclude _use_mirror_exclude(){ 
        return E_use_mirror_exclude();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("user_id");
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("site_category");
        ret.push_back("url");
        ret.push_back("mirrored_at");
        ret.push_back("analyzed_at");
        ret.push_back("is_mirroring");
        ret.push_back("is_parsing");
        ret.push_back("is_keywording");
        ret.push_back("is_ranking");
        ret.push_back("is_classifying");
        ret.push_back("is_scoring");
        ret.push_back("is_google_suggesting");
        ret.push_back("is_analyticsing");
        ret.push_back("has_mirror");
        ret.push_back("analyzed");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("mirror_percent");
        ret.push_back("scoring_percent");
        ret.push_back("ranking_percent");
        ret.push_back("last_page_mirrored");
        ret.push_back("last_page_classified");
        ret.push_back("score");
        ret.push_back("ga_username");
        ret.push_back("ga_password");
        ret.push_back("google_indexed_pages");
        ret.push_back("classifier_feedback");
        ret.push_back("deleted_at");
        ret.push_back("using_score_view_advanced_search");
        ret.push_back("frozen_tag_list");
        ret.push_back("logo_file_name");
        ret.push_back("logo_content_type");
        ret.push_back("logo_file_size");
        ret.push_back("logo_updated_at");
        ret.push_back("spider_entry_page");
        ret.push_back("ga_account_id");
        ret.push_back("reload_classifier");
        ret.push_back("mirror_exclusions");
        ret.push_back("max_pages_mirrored");
        ret.push_back("crawl_delay");
        ret.push_back("google_locale");
        ret.push_back("crawler_name");
        ret.push_back("mirror_inclusions");
        ret.push_back("kw_limit");
        ret.push_back("has_ga_credentials");
        ret.push_back("ga_profiles");
        ret.push_back("ga_profile");
        ret.push_back("last_mirror_activity");
        ret.push_back("follow_robots_txt");
        ret.push_back("has_robots_txt");
        ret.push_back("has_sitemap");
        ret.push_back("sitemap_in_robots");
        ret.push_back("all_subdomains");
        ret.push_back("has_baidu");
        ret.push_back("has_yandex");
        ret.push_back("account_type");
        ret.push_back("account_type_id");
        ret.push_back("has_yandex_ru");
        ret.push_back("has_yandex_ua");
        ret.push_back("subdomain_option");
        ret.push_back("setup_step");
        ret.push_back("mirroring_threads");
        ret.push_back("default_protocol");
        ret.push_back("score_keywords_in_urls");
        ret.push_back("score_content_in_urls");
        ret.push_back("score_existing_titles");
        ret.push_back("score_unique_titles");
        ret.push_back("score_keywords_in_titles");
        ret.push_back("score_content_in_titles");
        ret.push_back("score_outbound_links");
        ret.push_back("score_unique_content");
        ret.push_back("score_existing_meta_description");
        ret.push_back("score_unique_meta_description");
        ret.push_back("score_keywords_in_meta_description");
        ret.push_back("score_content_in_meta_description");
        ret.push_back("score_overused_meta_description");
        ret.push_back("score_existing_meta_keywords");
        ret.push_back("score_unique_meta_keywords");
        ret.push_back("score_misused_meta_keywords");
        ret.push_back("score_overused_meta_keywords");
        ret.push_back("score_existing_headers");
        ret.push_back("score_overused_headers");
        ret.push_back("score_keywords_in_headers");
        ret.push_back("score_existing_h1");
        ret.push_back("score_images");
        ret.push_back("score_existing_emphasis");
        ret.push_back("score_keywords_in_emphasis");
        ret.push_back("score_overused_emphasis");
        ret.push_back("base_url");
        ret.push_back("follow_links");
        ret.push_back("nofollow_links");
        ret.push_back("has_mail_ru");
        ret.push_back("organization_id");
        ret.push_back("ignore_crawl_delay");
        ret.push_back("follow_all");
        ret.push_back("use_follow_links");
        ret.push_back("use_nofollow_links");
        ret.push_back("mirror_all");
        ret.push_back("use_mirror_include");
        ret.push_back("use_mirror_exclude");
        return ret;
    }

    std::vector<O_Account> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_Account> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_user_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["user_id"]);
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_Account>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_site_category._base =
                UTILS::fromString<F_String::Base>(res[i]["site_category"]);
            ret[i]._f_url._base =
                UTILS::fromString<F_String::Base>(res[i]["url"]);
            ret[i]._f_mirrored_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["mirrored_at"]);
            ret[i]._f_analyzed_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["analyzed_at"]);
            ret[i]._f_is_mirroring._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_mirroring"]);
            ret[i]._f_is_parsing._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_parsing"]);
            ret[i]._f_is_keywording._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_keywording"]);
            ret[i]._f_is_ranking._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_ranking"]);
            ret[i]._f_is_classifying._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_classifying"]);
            ret[i]._f_is_scoring._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_scoring"]);
            ret[i]._f_is_google_suggesting._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_google_suggesting"]);
            ret[i]._f_is_analyticsing._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_analyticsing"]);
            ret[i]._f_has_mirror._base =
                UTILS::fromString<F_Integer::Base>(res[i]["has_mirror"]);
            ret[i]._f_analyzed._base =
                UTILS::fromString<F_Integer::Base>(res[i]["analyzed"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_mirror_percent._base =
                UTILS::fromString<F_Integer::Base>(res[i]["mirror_percent"]);
            ret[i]._f_scoring_percent._base =
                UTILS::fromString<F_Integer::Base>(res[i]["scoring_percent"]);
            ret[i]._f_ranking_percent._base =
                UTILS::fromString<F_Integer::Base>(res[i]["ranking_percent"]);
            ret[i]._f_last_page_mirrored._base =
                UTILS::fromString<F_String::Base>(res[i]["last_page_mirrored"]);
            ret[i]._f_last_page_classified._base =
                UTILS::fromString<F_String::Base>(res[i]["last_page_classified"]);
            ret[i]._f_score._base =
                UTILS::fromString<F_Integer::Base>(res[i]["score"]);
            ret[i]._f_ga_username._base =
                UTILS::fromString<F_String::Base>(res[i]["ga_username"]);
            ret[i]._f_ga_password._base =
                UTILS::fromString<F_String::Base>(res[i]["ga_password"]);
            ret[i]._f_google_indexed_pages._base =
                UTILS::fromString<F_Integer::Base>(res[i]["google_indexed_pages"]);
            ret[i]._f_classifier_feedback._base =
                UTILS::fromString<F_Text::Base>(res[i]["classifier_feedback"]);
            ret[i]._f_deleted_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["deleted_at"]);
            ret[i]._f_using_score_view_advanced_search._base =
                UTILS::fromString<F_Integer::Base>(res[i]["using_score_view_advanced_search"]);
            ret[i]._f_frozen_tag_list._base =
                UTILS::fromString<F_Text::Base>(res[i]["frozen_tag_list"]);
            ret[i]._f_logo_file_name._base =
                UTILS::fromString<F_String::Base>(res[i]["logo_file_name"]);
            ret[i]._f_logo_content_type._base =
                UTILS::fromString<F_String::Base>(res[i]["logo_content_type"]);
            ret[i]._f_logo_file_size._base =
                UTILS::fromString<F_Integer::Base>(res[i]["logo_file_size"]);
            ret[i]._f_logo_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["logo_updated_at"]);
            ret[i]._f_spider_entry_page._base =
                UTILS::fromString<F_Text::Base>(res[i]["spider_entry_page"]);
            ret[i]._f_ga_account_id._base =
                UTILS::fromString<F_String::Base>(res[i]["ga_account_id"]);
            ret[i]._f_reload_classifier._base =
                UTILS::fromString<F_Integer::Base>(res[i]["reload_classifier"]);
            ret[i]._f_mirror_exclusions._base =
                UTILS::fromString<F_Text::Base>(res[i]["mirror_exclusions"]);
            ret[i]._f_max_pages_mirrored._base =
                UTILS::fromString<F_Integer::Base>(res[i]["max_pages_mirrored"]);
            ret[i]._f_crawl_delay._base =
                UTILS::fromString<F_Integer::Base>(res[i]["crawl_delay"]);
            ret[i]._f_google_locale._base =
                (Field<EnumAccountGOOGLE_LOCALE>::Base)UTILS::fromString<size_t>(res[i]["google_locale"]);
            ret[i]._f_crawler_name._base =
                (Field<EnumAccountCRAWLER_NAME>::Base)UTILS::fromString<size_t>(res[i]["crawler_name"]);
            ret[i]._f_mirror_inclusions._base =
                UTILS::fromString<F_Text::Base>(res[i]["mirror_inclusions"]);
            ret[i]._f_kw_limit._base =
                UTILS::fromString<F_Integer::Base>(res[i]["kw_limit"]);
            ret[i]._f_has_ga_credentials._base =
                UTILS::fromString<F_Integer::Base>(res[i]["has_ga_credentials"]);
            ret[i]._f_ga_profiles._base =
                UTILS::fromString<F_Text::Base>(res[i]["ga_profiles"]);
            ret[i]._f_ga_profile._base =
                UTILS::fromString<F_Text::Base>(res[i]["ga_profile"]);
            ret[i]._f_last_mirror_activity._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["last_mirror_activity"]);
            ret[i]._f_follow_robots_txt._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["follow_robots_txt"]);
            ret[i]._f_has_robots_txt._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_robots_txt"]);
            ret[i]._f_has_sitemap._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_sitemap"]);
            ret[i]._f_sitemap_in_robots._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["sitemap_in_robots"]);
            ret[i]._f_all_subdomains._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["all_subdomains"]);
            ret[i]._f_has_baidu._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_baidu"]);
            ret[i]._f_has_yandex._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_yandex"]);
            ret[i]._f_account_type._base =
                UTILS::fromString<F_Integer::Base>(res[i]["account_type"]);
            ret[i]._f_account_type_id._base =
                UTILS::fromString<Field<I_account_type_id>::Base>(res[i]["account_type_id"]);
            ret[i]._f_has_yandex_ru._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_yandex_ru"]);
            ret[i]._f_has_yandex_ua._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_yandex_ua"]);
            ret[i]._f_subdomain_option._base =
                (Field<EnumAccountSUBDOMAIN_OPTION>::Base)UTILS::fromString<size_t>(res[i]["subdomain_option"]);
            ret[i]._f_setup_step._base =
                UTILS::fromString<F_Integer::Base>(res[i]["setup_step"]);
            ret[i]._f_mirroring_threads._base =
                UTILS::fromString<F_Integer::Base>(res[i]["mirroring_threads"]);
            ret[i]._f_default_protocol._base =
                (Field<EnumAccountDEFAULT_PROTOCOL>::Base)UTILS::fromString<size_t>(res[i]["default_protocol"]);
            ret[i]._f_score_keywords_in_urls._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_keywords_in_urls"]);
            ret[i]._f_score_content_in_urls._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_content_in_urls"]);
            ret[i]._f_score_existing_titles._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_existing_titles"]);
            ret[i]._f_score_unique_titles._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_unique_titles"]);
            ret[i]._f_score_keywords_in_titles._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_keywords_in_titles"]);
            ret[i]._f_score_content_in_titles._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_content_in_titles"]);
            ret[i]._f_score_outbound_links._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_outbound_links"]);
            ret[i]._f_score_unique_content._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_unique_content"]);
            ret[i]._f_score_existing_meta_description._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_existing_meta_description"]);
            ret[i]._f_score_unique_meta_description._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_unique_meta_description"]);
            ret[i]._f_score_keywords_in_meta_description._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_keywords_in_meta_description"]);
            ret[i]._f_score_content_in_meta_description._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_content_in_meta_description"]);
            ret[i]._f_score_overused_meta_description._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_overused_meta_description"]);
            ret[i]._f_score_existing_meta_keywords._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_existing_meta_keywords"]);
            ret[i]._f_score_unique_meta_keywords._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_unique_meta_keywords"]);
            ret[i]._f_score_misused_meta_keywords._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_misused_meta_keywords"]);
            ret[i]._f_score_overused_meta_keywords._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_overused_meta_keywords"]);
            ret[i]._f_score_existing_headers._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_existing_headers"]);
            ret[i]._f_score_overused_headers._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_overused_headers"]);
            ret[i]._f_score_keywords_in_headers._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_keywords_in_headers"]);
            ret[i]._f_score_existing_h1._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_existing_h1"]);
            ret[i]._f_score_images._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_images"]);
            ret[i]._f_score_existing_emphasis._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_existing_emphasis"]);
            ret[i]._f_score_keywords_in_emphasis._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_keywords_in_emphasis"]);
            ret[i]._f_score_overused_emphasis._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["score_overused_emphasis"]);
            ret[i]._f_base_url._base =
                UTILS::fromString<F_String::Base>(res[i]["base_url"]);
            ret[i]._f_follow_links._base =
                UTILS::fromString<F_Text::Base>(res[i]["follow_links"]);
            ret[i]._f_nofollow_links._base =
                UTILS::fromString<F_Text::Base>(res[i]["nofollow_links"]);
            ret[i]._f_has_mail_ru._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["has_mail_ru"]);
            ret[i]._f_organization_id._base =
                UTILS::fromString<Field<I_organization_id>::Base>(res[i]["organization_id"]);
            ret[i]._f_ignore_crawl_delay._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["ignore_crawl_delay"]);
            ret[i]._f_follow_all._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["follow_all"]);
            ret[i]._f_use_follow_links._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["use_follow_links"]);
            ret[i]._f_use_nofollow_links._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["use_nofollow_links"]);
            ret[i]._f_mirror_all._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["mirror_all"]);
            ret[i]._f_use_mirror_include._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["use_mirror_include"]);
            ret[i]._f_use_mirror_exclude._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["use_mirror_exclude"]);
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


    std::vector<O_Account> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_Account> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_Account> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_Account, bool> select(const I_Account& id){
        return first(E_id() == id);
    }

    std::pair<O_Account, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_Account> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_Account(), false);
    }

    std::pair<O_Account, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_Account>::const_iterator begin,
                         std::vector<O_Account>::const_iterator end)
    {
	std::vector<std::string> fields;
        
        fields.push_back(std::string("user_id"));
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("site_category"));
        
        fields.push_back(std::string("url"));
        
        fields.push_back(std::string("mirrored_at"));
        
        fields.push_back(std::string("analyzed_at"));
        
        fields.push_back(std::string("is_mirroring"));
        
        fields.push_back(std::string("is_parsing"));
        
        fields.push_back(std::string("is_keywording"));
        
        fields.push_back(std::string("is_ranking"));
        
        fields.push_back(std::string("is_classifying"));
        
        fields.push_back(std::string("is_scoring"));
        
        fields.push_back(std::string("is_google_suggesting"));
        
        fields.push_back(std::string("is_analyticsing"));
        
        fields.push_back(std::string("has_mirror"));
        
        fields.push_back(std::string("analyzed"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("mirror_percent"));
        
        fields.push_back(std::string("scoring_percent"));
        
        fields.push_back(std::string("ranking_percent"));
        
        fields.push_back(std::string("last_page_mirrored"));
        
        fields.push_back(std::string("last_page_classified"));
        
        fields.push_back(std::string("score"));
        
        fields.push_back(std::string("ga_username"));
        
        fields.push_back(std::string("ga_password"));
        
        fields.push_back(std::string("google_indexed_pages"));
        
        fields.push_back(std::string("classifier_feedback"));
        
        fields.push_back(std::string("deleted_at"));
        
        fields.push_back(std::string("using_score_view_advanced_search"));
        
        fields.push_back(std::string("frozen_tag_list"));
        
        fields.push_back(std::string("logo_file_name"));
        
        fields.push_back(std::string("logo_content_type"));
        
        fields.push_back(std::string("logo_file_size"));
        
        fields.push_back(std::string("logo_updated_at"));
        
        fields.push_back(std::string("spider_entry_page"));
        
        fields.push_back(std::string("ga_account_id"));
        
        fields.push_back(std::string("reload_classifier"));
        
        fields.push_back(std::string("mirror_exclusions"));
        
        fields.push_back(std::string("max_pages_mirrored"));
        
        fields.push_back(std::string("crawl_delay"));
        
        fields.push_back(std::string("google_locale"));
        
        fields.push_back(std::string("crawler_name"));
        
        fields.push_back(std::string("mirror_inclusions"));
        
        fields.push_back(std::string("kw_limit"));
        
        fields.push_back(std::string("has_ga_credentials"));
        
        fields.push_back(std::string("ga_profiles"));
        
        fields.push_back(std::string("ga_profile"));
        
        fields.push_back(std::string("last_mirror_activity"));
        
        fields.push_back(std::string("follow_robots_txt"));
        
        fields.push_back(std::string("has_robots_txt"));
        
        fields.push_back(std::string("has_sitemap"));
        
        fields.push_back(std::string("sitemap_in_robots"));
        
        fields.push_back(std::string("all_subdomains"));
        
        fields.push_back(std::string("has_baidu"));
        
        fields.push_back(std::string("has_yandex"));
        
        fields.push_back(std::string("account_type"));
        
        fields.push_back(std::string("account_type_id"));
        
        fields.push_back(std::string("has_yandex_ru"));
        
        fields.push_back(std::string("has_yandex_ua"));
        
        fields.push_back(std::string("subdomain_option"));
        
        fields.push_back(std::string("setup_step"));
        
        fields.push_back(std::string("mirroring_threads"));
        
        fields.push_back(std::string("default_protocol"));
        
        fields.push_back(std::string("score_keywords_in_urls"));
        
        fields.push_back(std::string("score_content_in_urls"));
        
        fields.push_back(std::string("score_existing_titles"));
        
        fields.push_back(std::string("score_unique_titles"));
        
        fields.push_back(std::string("score_keywords_in_titles"));
        
        fields.push_back(std::string("score_content_in_titles"));
        
        fields.push_back(std::string("score_outbound_links"));
        
        fields.push_back(std::string("score_unique_content"));
        
        fields.push_back(std::string("score_existing_meta_description"));
        
        fields.push_back(std::string("score_unique_meta_description"));
        
        fields.push_back(std::string("score_keywords_in_meta_description"));
        
        fields.push_back(std::string("score_content_in_meta_description"));
        
        fields.push_back(std::string("score_overused_meta_description"));
        
        fields.push_back(std::string("score_existing_meta_keywords"));
        
        fields.push_back(std::string("score_unique_meta_keywords"));
        
        fields.push_back(std::string("score_misused_meta_keywords"));
        
        fields.push_back(std::string("score_overused_meta_keywords"));
        
        fields.push_back(std::string("score_existing_headers"));
        
        fields.push_back(std::string("score_overused_headers"));
        
        fields.push_back(std::string("score_keywords_in_headers"));
        
        fields.push_back(std::string("score_existing_h1"));
        
        fields.push_back(std::string("score_images"));
        
        fields.push_back(std::string("score_existing_emphasis"));
        
        fields.push_back(std::string("score_keywords_in_emphasis"));
        
        fields.push_back(std::string("score_overused_emphasis"));
        
        fields.push_back(std::string("base_url"));
        
        fields.push_back(std::string("follow_links"));
        
        fields.push_back(std::string("nofollow_links"));
        
        fields.push_back(std::string("has_mail_ru"));
        
        fields.push_back(std::string("organization_id"));
        
        fields.push_back(std::string("ignore_crawl_delay"));
        
        fields.push_back(std::string("follow_all"));
        
        fields.push_back(std::string("use_follow_links"));
        
        fields.push_back(std::string("use_nofollow_links"));
        
        fields.push_back(std::string("mirror_all"));
        
        fields.push_back(std::string("use_mirror_include"));
        
        fields.push_back(std::string("use_mirror_exclude"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_Account& r = *begin;
	    std::vector<std::string> row;
            
            row.push_back(toSQLString(r._user_id()));
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._site_category()));
            
            row.push_back(toSQLString(r._url()));
            
            row.push_back(toSQLString(r._mirrored_at()));
            
            row.push_back(toSQLString(r._analyzed_at()));
            
            row.push_back(toSQLString(r._is_mirroring()));
            
            row.push_back(toSQLString(r._is_parsing()));
            
            row.push_back(toSQLString(r._is_keywording()));
            
            row.push_back(toSQLString(r._is_ranking()));
            
            row.push_back(toSQLString(r._is_classifying()));
            
            row.push_back(toSQLString(r._is_scoring()));
            
            row.push_back(toSQLString(r._is_google_suggesting()));
            
            row.push_back(toSQLString(r._is_analyticsing()));
            
            row.push_back(toSQLString(r._has_mirror()));
            
            row.push_back(toSQLString(r._analyzed()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._mirror_percent()));
            
            row.push_back(toSQLString(r._scoring_percent()));
            
            row.push_back(toSQLString(r._ranking_percent()));
            
            row.push_back(toSQLString(r._last_page_mirrored()));
            
            row.push_back(toSQLString(r._last_page_classified()));
            
            row.push_back(toSQLString(r._score()));
            
            row.push_back(toSQLString(r._ga_username()));
            
            row.push_back(toSQLString(r._ga_password()));
            
            row.push_back(toSQLString(r._google_indexed_pages()));
            
            row.push_back(toSQLString(r._classifier_feedback()));
            
            row.push_back(toSQLString(r._deleted_at()));
            
            row.push_back(toSQLString(r._using_score_view_advanced_search()));
            
            row.push_back(toSQLString(r._frozen_tag_list()));
            
            row.push_back(toSQLString(r._logo_file_name()));
            
            row.push_back(toSQLString(r._logo_content_type()));
            
            row.push_back(toSQLString(r._logo_file_size()));
            
            row.push_back(toSQLString(r._logo_updated_at()));
            
            row.push_back(toSQLString(r._spider_entry_page()));
            
            row.push_back(toSQLString(r._ga_account_id()));
            
            row.push_back(toSQLString(r._reload_classifier()));
            
            row.push_back(toSQLString(r._mirror_exclusions()));
            
            row.push_back(toSQLString(r._max_pages_mirrored()));
            
            row.push_back(toSQLString(r._crawl_delay()));
            
            row.push_back(toSQLString(r._google_locale()));
            
            row.push_back(toSQLString(r._crawler_name()));
            
            row.push_back(toSQLString(r._mirror_inclusions()));
            
            row.push_back(toSQLString(r._kw_limit()));
            
            row.push_back(toSQLString(r._has_ga_credentials()));
            
            row.push_back(toSQLString(r._ga_profiles()));
            
            row.push_back(toSQLString(r._ga_profile()));
            
            row.push_back(toSQLString(r._last_mirror_activity()));
            
            row.push_back(toSQLString(r._follow_robots_txt()));
            
            row.push_back(toSQLString(r._has_robots_txt()));
            
            row.push_back(toSQLString(r._has_sitemap()));
            
            row.push_back(toSQLString(r._sitemap_in_robots()));
            
            row.push_back(toSQLString(r._all_subdomains()));
            
            row.push_back(toSQLString(r._has_baidu()));
            
            row.push_back(toSQLString(r._has_yandex()));
            
            row.push_back(toSQLString(r._account_type()));
            
            row.push_back(toSQLString(r._account_type_id()));
            
            row.push_back(toSQLString(r._has_yandex_ru()));
            
            row.push_back(toSQLString(r._has_yandex_ua()));
            
            row.push_back(toSQLString(r._subdomain_option()));
            
            row.push_back(toSQLString(r._setup_step()));
            
            row.push_back(toSQLString(r._mirroring_threads()));
            
            row.push_back(toSQLString(r._default_protocol()));
            
            row.push_back(toSQLString(r._score_keywords_in_urls()));
            
            row.push_back(toSQLString(r._score_content_in_urls()));
            
            row.push_back(toSQLString(r._score_existing_titles()));
            
            row.push_back(toSQLString(r._score_unique_titles()));
            
            row.push_back(toSQLString(r._score_keywords_in_titles()));
            
            row.push_back(toSQLString(r._score_content_in_titles()));
            
            row.push_back(toSQLString(r._score_outbound_links()));
            
            row.push_back(toSQLString(r._score_unique_content()));
            
            row.push_back(toSQLString(r._score_existing_meta_description()));
            
            row.push_back(toSQLString(r._score_unique_meta_description()));
            
            row.push_back(toSQLString(r._score_keywords_in_meta_description()));
            
            row.push_back(toSQLString(r._score_content_in_meta_description()));
            
            row.push_back(toSQLString(r._score_overused_meta_description()));
            
            row.push_back(toSQLString(r._score_existing_meta_keywords()));
            
            row.push_back(toSQLString(r._score_unique_meta_keywords()));
            
            row.push_back(toSQLString(r._score_misused_meta_keywords()));
            
            row.push_back(toSQLString(r._score_overused_meta_keywords()));
            
            row.push_back(toSQLString(r._score_existing_headers()));
            
            row.push_back(toSQLString(r._score_overused_headers()));
            
            row.push_back(toSQLString(r._score_keywords_in_headers()));
            
            row.push_back(toSQLString(r._score_existing_h1()));
            
            row.push_back(toSQLString(r._score_images()));
            
            row.push_back(toSQLString(r._score_existing_emphasis()));
            
            row.push_back(toSQLString(r._score_keywords_in_emphasis()));
            
            row.push_back(toSQLString(r._score_overused_emphasis()));
            
            row.push_back(toSQLString(r._base_url()));
            
            row.push_back(toSQLString(r._follow_links()));
            
            row.push_back(toSQLString(r._nofollow_links()));
            
            row.push_back(toSQLString(r._has_mail_ru()));
            
            row.push_back(toSQLString(r._organization_id()));
            
            row.push_back(toSQLString(r._ignore_crawl_delay()));
            
            row.push_back(toSQLString(r._follow_all()));
            
            row.push_back(toSQLString(r._use_follow_links()));
            
            row.push_back(toSQLString(r._use_nofollow_links()));
            
            row.push_back(toSQLString(r._mirror_all()));
            
            row.push_back(toSQLString(r._use_mirror_include()));
            
            row.push_back(toSQLString(r._use_mirror_exclude()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("accounts",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_Account>::const_iterator begin,
                           std::vector<O_Account>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_Account>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
            
            if (it->_f_user_id._dirty){
                fields.push_back(std::string("user_id"));
                row.push_back(toSQLString(it->_user_id()));
            }
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_site_category._dirty){
                fields.push_back(std::string("site_category"));
                row.push_back(toSQLString(it->_site_category()));
            }
            
            if (it->_f_url._dirty){
                fields.push_back(std::string("url"));
                row.push_back(toSQLString(it->_url()));
            }
            
            if (it->_f_mirrored_at._dirty){
                fields.push_back(std::string("mirrored_at"));
                row.push_back(toSQLString(it->_mirrored_at()));
            }
            
            if (it->_f_analyzed_at._dirty){
                fields.push_back(std::string("analyzed_at"));
                row.push_back(toSQLString(it->_analyzed_at()));
            }
            
            if (it->_f_is_mirroring._dirty){
                fields.push_back(std::string("is_mirroring"));
                row.push_back(toSQLString(it->_is_mirroring()));
            }
            
            if (it->_f_is_parsing._dirty){
                fields.push_back(std::string("is_parsing"));
                row.push_back(toSQLString(it->_is_parsing()));
            }
            
            if (it->_f_is_keywording._dirty){
                fields.push_back(std::string("is_keywording"));
                row.push_back(toSQLString(it->_is_keywording()));
            }
            
            if (it->_f_is_ranking._dirty){
                fields.push_back(std::string("is_ranking"));
                row.push_back(toSQLString(it->_is_ranking()));
            }
            
            if (it->_f_is_classifying._dirty){
                fields.push_back(std::string("is_classifying"));
                row.push_back(toSQLString(it->_is_classifying()));
            }
            
            if (it->_f_is_scoring._dirty){
                fields.push_back(std::string("is_scoring"));
                row.push_back(toSQLString(it->_is_scoring()));
            }
            
            if (it->_f_is_google_suggesting._dirty){
                fields.push_back(std::string("is_google_suggesting"));
                row.push_back(toSQLString(it->_is_google_suggesting()));
            }
            
            if (it->_f_is_analyticsing._dirty){
                fields.push_back(std::string("is_analyticsing"));
                row.push_back(toSQLString(it->_is_analyticsing()));
            }
            
            if (it->_f_has_mirror._dirty){
                fields.push_back(std::string("has_mirror"));
                row.push_back(toSQLString(it->_has_mirror()));
            }
            
            if (it->_f_analyzed._dirty){
                fields.push_back(std::string("analyzed"));
                row.push_back(toSQLString(it->_analyzed()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_mirror_percent._dirty){
                fields.push_back(std::string("mirror_percent"));
                row.push_back(toSQLString(it->_mirror_percent()));
            }
            
            if (it->_f_scoring_percent._dirty){
                fields.push_back(std::string("scoring_percent"));
                row.push_back(toSQLString(it->_scoring_percent()));
            }
            
            if (it->_f_ranking_percent._dirty){
                fields.push_back(std::string("ranking_percent"));
                row.push_back(toSQLString(it->_ranking_percent()));
            }
            
            if (it->_f_last_page_mirrored._dirty){
                fields.push_back(std::string("last_page_mirrored"));
                row.push_back(toSQLString(it->_last_page_mirrored()));
            }
            
            if (it->_f_last_page_classified._dirty){
                fields.push_back(std::string("last_page_classified"));
                row.push_back(toSQLString(it->_last_page_classified()));
            }
            
            if (it->_f_score._dirty){
                fields.push_back(std::string("score"));
                row.push_back(toSQLString(it->_score()));
            }
            
            if (it->_f_ga_username._dirty){
                fields.push_back(std::string("ga_username"));
                row.push_back(toSQLString(it->_ga_username()));
            }
            
            if (it->_f_ga_password._dirty){
                fields.push_back(std::string("ga_password"));
                row.push_back(toSQLString(it->_ga_password()));
            }
            
            if (it->_f_google_indexed_pages._dirty){
                fields.push_back(std::string("google_indexed_pages"));
                row.push_back(toSQLString(it->_google_indexed_pages()));
            }
            
            if (it->_f_classifier_feedback._dirty){
                fields.push_back(std::string("classifier_feedback"));
                row.push_back(toSQLString(it->_classifier_feedback()));
            }
            
            if (it->_f_deleted_at._dirty){
                fields.push_back(std::string("deleted_at"));
                row.push_back(toSQLString(it->_deleted_at()));
            }
            
            if (it->_f_using_score_view_advanced_search._dirty){
                fields.push_back(std::string("using_score_view_advanced_search"));
                row.push_back(toSQLString(it->_using_score_view_advanced_search()));
            }
            
            if (it->_f_frozen_tag_list._dirty){
                fields.push_back(std::string("frozen_tag_list"));
                row.push_back(toSQLString(it->_frozen_tag_list()));
            }
            
            if (it->_f_logo_file_name._dirty){
                fields.push_back(std::string("logo_file_name"));
                row.push_back(toSQLString(it->_logo_file_name()));
            }
            
            if (it->_f_logo_content_type._dirty){
                fields.push_back(std::string("logo_content_type"));
                row.push_back(toSQLString(it->_logo_content_type()));
            }
            
            if (it->_f_logo_file_size._dirty){
                fields.push_back(std::string("logo_file_size"));
                row.push_back(toSQLString(it->_logo_file_size()));
            }
            
            if (it->_f_logo_updated_at._dirty){
                fields.push_back(std::string("logo_updated_at"));
                row.push_back(toSQLString(it->_logo_updated_at()));
            }
            
            if (it->_f_spider_entry_page._dirty){
                fields.push_back(std::string("spider_entry_page"));
                row.push_back(toSQLString(it->_spider_entry_page()));
            }
            
            if (it->_f_ga_account_id._dirty){
                fields.push_back(std::string("ga_account_id"));
                row.push_back(toSQLString(it->_ga_account_id()));
            }
            
            if (it->_f_reload_classifier._dirty){
                fields.push_back(std::string("reload_classifier"));
                row.push_back(toSQLString(it->_reload_classifier()));
            }
            
            if (it->_f_mirror_exclusions._dirty){
                fields.push_back(std::string("mirror_exclusions"));
                row.push_back(toSQLString(it->_mirror_exclusions()));
            }
            
            if (it->_f_max_pages_mirrored._dirty){
                fields.push_back(std::string("max_pages_mirrored"));
                row.push_back(toSQLString(it->_max_pages_mirrored()));
            }
            
            if (it->_f_crawl_delay._dirty){
                fields.push_back(std::string("crawl_delay"));
                row.push_back(toSQLString(it->_crawl_delay()));
            }
            
            if (it->_f_google_locale._dirty){
                fields.push_back(std::string("google_locale"));
                row.push_back(toSQLString(it->_google_locale()));
            }
            
            if (it->_f_crawler_name._dirty){
                fields.push_back(std::string("crawler_name"));
                row.push_back(toSQLString(it->_crawler_name()));
            }
            
            if (it->_f_mirror_inclusions._dirty){
                fields.push_back(std::string("mirror_inclusions"));
                row.push_back(toSQLString(it->_mirror_inclusions()));
            }
            
            if (it->_f_kw_limit._dirty){
                fields.push_back(std::string("kw_limit"));
                row.push_back(toSQLString(it->_kw_limit()));
            }
            
            if (it->_f_has_ga_credentials._dirty){
                fields.push_back(std::string("has_ga_credentials"));
                row.push_back(toSQLString(it->_has_ga_credentials()));
            }
            
            if (it->_f_ga_profiles._dirty){
                fields.push_back(std::string("ga_profiles"));
                row.push_back(toSQLString(it->_ga_profiles()));
            }
            
            if (it->_f_ga_profile._dirty){
                fields.push_back(std::string("ga_profile"));
                row.push_back(toSQLString(it->_ga_profile()));
            }
            
            if (it->_f_last_mirror_activity._dirty){
                fields.push_back(std::string("last_mirror_activity"));
                row.push_back(toSQLString(it->_last_mirror_activity()));
            }
            
            if (it->_f_follow_robots_txt._dirty){
                fields.push_back(std::string("follow_robots_txt"));
                row.push_back(toSQLString(it->_follow_robots_txt()));
            }
            
            if (it->_f_has_robots_txt._dirty){
                fields.push_back(std::string("has_robots_txt"));
                row.push_back(toSQLString(it->_has_robots_txt()));
            }
            
            if (it->_f_has_sitemap._dirty){
                fields.push_back(std::string("has_sitemap"));
                row.push_back(toSQLString(it->_has_sitemap()));
            }
            
            if (it->_f_sitemap_in_robots._dirty){
                fields.push_back(std::string("sitemap_in_robots"));
                row.push_back(toSQLString(it->_sitemap_in_robots()));
            }
            
            if (it->_f_all_subdomains._dirty){
                fields.push_back(std::string("all_subdomains"));
                row.push_back(toSQLString(it->_all_subdomains()));
            }
            
            if (it->_f_has_baidu._dirty){
                fields.push_back(std::string("has_baidu"));
                row.push_back(toSQLString(it->_has_baidu()));
            }
            
            if (it->_f_has_yandex._dirty){
                fields.push_back(std::string("has_yandex"));
                row.push_back(toSQLString(it->_has_yandex()));
            }
            
            if (it->_f_account_type._dirty){
                fields.push_back(std::string("account_type"));
                row.push_back(toSQLString(it->_account_type()));
            }
            
            if (it->_f_account_type_id._dirty){
                fields.push_back(std::string("account_type_id"));
                row.push_back(toSQLString(it->_account_type_id()));
            }
            
            if (it->_f_has_yandex_ru._dirty){
                fields.push_back(std::string("has_yandex_ru"));
                row.push_back(toSQLString(it->_has_yandex_ru()));
            }
            
            if (it->_f_has_yandex_ua._dirty){
                fields.push_back(std::string("has_yandex_ua"));
                row.push_back(toSQLString(it->_has_yandex_ua()));
            }
            
            if (it->_f_subdomain_option._dirty){
                fields.push_back(std::string("subdomain_option"));
                row.push_back(toSQLString(it->_subdomain_option()));
            }
            
            if (it->_f_setup_step._dirty){
                fields.push_back(std::string("setup_step"));
                row.push_back(toSQLString(it->_setup_step()));
            }
            
            if (it->_f_mirroring_threads._dirty){
                fields.push_back(std::string("mirroring_threads"));
                row.push_back(toSQLString(it->_mirroring_threads()));
            }
            
            if (it->_f_default_protocol._dirty){
                fields.push_back(std::string("default_protocol"));
                row.push_back(toSQLString(it->_default_protocol()));
            }
            
            if (it->_f_score_keywords_in_urls._dirty){
                fields.push_back(std::string("score_keywords_in_urls"));
                row.push_back(toSQLString(it->_score_keywords_in_urls()));
            }
            
            if (it->_f_score_content_in_urls._dirty){
                fields.push_back(std::string("score_content_in_urls"));
                row.push_back(toSQLString(it->_score_content_in_urls()));
            }
            
            if (it->_f_score_existing_titles._dirty){
                fields.push_back(std::string("score_existing_titles"));
                row.push_back(toSQLString(it->_score_existing_titles()));
            }
            
            if (it->_f_score_unique_titles._dirty){
                fields.push_back(std::string("score_unique_titles"));
                row.push_back(toSQLString(it->_score_unique_titles()));
            }
            
            if (it->_f_score_keywords_in_titles._dirty){
                fields.push_back(std::string("score_keywords_in_titles"));
                row.push_back(toSQLString(it->_score_keywords_in_titles()));
            }
            
            if (it->_f_score_content_in_titles._dirty){
                fields.push_back(std::string("score_content_in_titles"));
                row.push_back(toSQLString(it->_score_content_in_titles()));
            }
            
            if (it->_f_score_outbound_links._dirty){
                fields.push_back(std::string("score_outbound_links"));
                row.push_back(toSQLString(it->_score_outbound_links()));
            }
            
            if (it->_f_score_unique_content._dirty){
                fields.push_back(std::string("score_unique_content"));
                row.push_back(toSQLString(it->_score_unique_content()));
            }
            
            if (it->_f_score_existing_meta_description._dirty){
                fields.push_back(std::string("score_existing_meta_description"));
                row.push_back(toSQLString(it->_score_existing_meta_description()));
            }
            
            if (it->_f_score_unique_meta_description._dirty){
                fields.push_back(std::string("score_unique_meta_description"));
                row.push_back(toSQLString(it->_score_unique_meta_description()));
            }
            
            if (it->_f_score_keywords_in_meta_description._dirty){
                fields.push_back(std::string("score_keywords_in_meta_description"));
                row.push_back(toSQLString(it->_score_keywords_in_meta_description()));
            }
            
            if (it->_f_score_content_in_meta_description._dirty){
                fields.push_back(std::string("score_content_in_meta_description"));
                row.push_back(toSQLString(it->_score_content_in_meta_description()));
            }
            
            if (it->_f_score_overused_meta_description._dirty){
                fields.push_back(std::string("score_overused_meta_description"));
                row.push_back(toSQLString(it->_score_overused_meta_description()));
            }
            
            if (it->_f_score_existing_meta_keywords._dirty){
                fields.push_back(std::string("score_existing_meta_keywords"));
                row.push_back(toSQLString(it->_score_existing_meta_keywords()));
            }
            
            if (it->_f_score_unique_meta_keywords._dirty){
                fields.push_back(std::string("score_unique_meta_keywords"));
                row.push_back(toSQLString(it->_score_unique_meta_keywords()));
            }
            
            if (it->_f_score_misused_meta_keywords._dirty){
                fields.push_back(std::string("score_misused_meta_keywords"));
                row.push_back(toSQLString(it->_score_misused_meta_keywords()));
            }
            
            if (it->_f_score_overused_meta_keywords._dirty){
                fields.push_back(std::string("score_overused_meta_keywords"));
                row.push_back(toSQLString(it->_score_overused_meta_keywords()));
            }
            
            if (it->_f_score_existing_headers._dirty){
                fields.push_back(std::string("score_existing_headers"));
                row.push_back(toSQLString(it->_score_existing_headers()));
            }
            
            if (it->_f_score_overused_headers._dirty){
                fields.push_back(std::string("score_overused_headers"));
                row.push_back(toSQLString(it->_score_overused_headers()));
            }
            
            if (it->_f_score_keywords_in_headers._dirty){
                fields.push_back(std::string("score_keywords_in_headers"));
                row.push_back(toSQLString(it->_score_keywords_in_headers()));
            }
            
            if (it->_f_score_existing_h1._dirty){
                fields.push_back(std::string("score_existing_h1"));
                row.push_back(toSQLString(it->_score_existing_h1()));
            }
            
            if (it->_f_score_images._dirty){
                fields.push_back(std::string("score_images"));
                row.push_back(toSQLString(it->_score_images()));
            }
            
            if (it->_f_score_existing_emphasis._dirty){
                fields.push_back(std::string("score_existing_emphasis"));
                row.push_back(toSQLString(it->_score_existing_emphasis()));
            }
            
            if (it->_f_score_keywords_in_emphasis._dirty){
                fields.push_back(std::string("score_keywords_in_emphasis"));
                row.push_back(toSQLString(it->_score_keywords_in_emphasis()));
            }
            
            if (it->_f_score_overused_emphasis._dirty){
                fields.push_back(std::string("score_overused_emphasis"));
                row.push_back(toSQLString(it->_score_overused_emphasis()));
            }
            
            if (it->_f_base_url._dirty){
                fields.push_back(std::string("base_url"));
                row.push_back(toSQLString(it->_base_url()));
            }
            
            if (it->_f_follow_links._dirty){
                fields.push_back(std::string("follow_links"));
                row.push_back(toSQLString(it->_follow_links()));
            }
            
            if (it->_f_nofollow_links._dirty){
                fields.push_back(std::string("nofollow_links"));
                row.push_back(toSQLString(it->_nofollow_links()));
            }
            
            if (it->_f_has_mail_ru._dirty){
                fields.push_back(std::string("has_mail_ru"));
                row.push_back(toSQLString(it->_has_mail_ru()));
            }
            
            if (it->_f_organization_id._dirty){
                fields.push_back(std::string("organization_id"));
                row.push_back(toSQLString(it->_organization_id()));
            }
            
            if (it->_f_ignore_crawl_delay._dirty){
                fields.push_back(std::string("ignore_crawl_delay"));
                row.push_back(toSQLString(it->_ignore_crawl_delay()));
            }
            
            if (it->_f_follow_all._dirty){
                fields.push_back(std::string("follow_all"));
                row.push_back(toSQLString(it->_follow_all()));
            }
            
            if (it->_f_use_follow_links._dirty){
                fields.push_back(std::string("use_follow_links"));
                row.push_back(toSQLString(it->_use_follow_links()));
            }
            
            if (it->_f_use_nofollow_links._dirty){
                fields.push_back(std::string("use_nofollow_links"));
                row.push_back(toSQLString(it->_use_nofollow_links()));
            }
            
            if (it->_f_mirror_all._dirty){
                fields.push_back(std::string("mirror_all"));
                row.push_back(toSQLString(it->_mirror_all()));
            }
            
            if (it->_f_use_mirror_include._dirty){
                fields.push_back(std::string("use_mirror_include"));
                row.push_back(toSQLString(it->_use_mirror_include()));
            }
            
            if (it->_f_use_mirror_exclude._dirty){
                fields.push_back(std::string("use_mirror_exclude"));
                row.push_back(toSQLString(it->_use_mirror_exclude()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("accounts",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_ACCOUNT
