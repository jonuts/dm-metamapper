#ifndef O_ACCOUNT
#define O_ACCOUNT

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"
#include "T_Issue.hpp"
#include "T_Page.hpp"
#include "T_Competition.hpp"
#include "T_HistoricalScore.hpp"
#include "T_MirrorPage.hpp"
#include "T_SearchKeyword.hpp"
#include "T_Subdomain.hpp"
#include "T_Page_Backlink.hpp"
#include "T_Page_Canonical.hpp"
#include "T_Page_Duplicate.hpp"
#include "T_Page_Emphasis.hpp"
#include "T_Page_HttpError.hpp"
#include "T_Page_Image.hpp"
#include "T_Page_Keyword.hpp"
#include "T_Page_Link.hpp"
#include "T_Page_NonHtml.hpp"
#include "T_Page_Header.hpp"
#include "T_Page_Redirect.hpp"
#include "T_IssuePage.hpp"
#include "T_IssuePageClass.hpp"
#include "T_PageSearchKeyword.hpp"
#include "T_SearchCompetition.hpp"
#include "T_KeywordGroup.hpp"

enum EnumAccountGOOGLE_LOCALE { ACCOUNT_GOOGLE_LOCALE_COM = 1, ACCOUNT_GOOGLE_LOCALE_CO_UK = 2, ACCOUNT_GOOGLE_LOCALE_COM_AU = 3, ACCOUNT_GOOGLE_LOCALE_CA = 4, ACCOUNT_GOOGLE_LOCALE_COM_MY = 5, ACCOUNT_GOOGLE_LOCALE_FR = 6, ACCOUNT_GOOGLE_LOCALE_DE = 7, ACCOUNT_GOOGLE_LOCALE_RU = 8, ACCOUNT_GOOGLE_LOCALE_CH = 9, ACCOUNT_GOOGLE_LOCALE_COM_UA = 10, ACCOUNT_GOOGLE_LOCALE_COM_HK = 11, ACCOUNT_GOOGLE_LOCALE_CZ = 12, ACCOUNT_GOOGLE_LOCALE_IT = 13, ACCOUNT_GOOGLE_LOCALE_COM_SA = 14, ACCOUNT_GOOGLE_LOCALE_COM_BR = 15, ACCOUNT_GOOGLE_LOCALE_CO_IL = 16, ACCOUNT_GOOGLE_LOCALE_NL = 17, ACCOUNT_GOOGLE_LOCALE_COM_MX = 18, ACCOUNT_GOOGLE_LOCALE_DK = 19, ACCOUNT_GOOGLE_LOCALE_AD = 20, ACCOUNT_GOOGLE_LOCALE_AE = 21, ACCOUNT_GOOGLE_LOCALE_AM = 22, ACCOUNT_GOOGLE_LOCALE_AS = 23, ACCOUNT_GOOGLE_LOCALE_AT = 24, ACCOUNT_GOOGLE_LOCALE_AZ = 25, ACCOUNT_GOOGLE_LOCALE_BA = 26, ACCOUNT_GOOGLE_LOCALE_BE = 27, ACCOUNT_GOOGLE_LOCALE_BF = 28, ACCOUNT_GOOGLE_LOCALE_BG = 29, ACCOUNT_GOOGLE_LOCALE_BI = 30, ACCOUNT_GOOGLE_LOCALE_BJ = 31, ACCOUNT_GOOGLE_LOCALE_BS = 32, ACCOUNT_GOOGLE_LOCALE_BY = 33, ACCOUNT_GOOGLE_LOCALE_CAT = 34, ACCOUNT_GOOGLE_LOCALE_CD = 35, ACCOUNT_GOOGLE_LOCALE_CF = 36, ACCOUNT_GOOGLE_LOCALE_CG = 37, ACCOUNT_GOOGLE_LOCALE_CI = 38, ACCOUNT_GOOGLE_LOCALE_CL = 39, ACCOUNT_GOOGLE_LOCALE_CM = 40, ACCOUNT_GOOGLE_LOCALE_CO_AO = 41, ACCOUNT_GOOGLE_LOCALE_CO_BW = 42, ACCOUNT_GOOGLE_LOCALE_CO_CK = 43, ACCOUNT_GOOGLE_LOCALE_CO_CR = 44, ACCOUNT_GOOGLE_LOCALE_CO_ID = 45, ACCOUNT_GOOGLE_LOCALE_CO_IN = 46, ACCOUNT_GOOGLE_LOCALE_CO_JP = 47, ACCOUNT_GOOGLE_LOCALE_CO_KE = 48, ACCOUNT_GOOGLE_LOCALE_CO_KR = 49, ACCOUNT_GOOGLE_LOCALE_CO_LS = 50, ACCOUNT_GOOGLE_LOCALE_CO_MA = 51, ACCOUNT_GOOGLE_LOCALE_CO_MZ = 52, ACCOUNT_GOOGLE_LOCALE_CO_NZ = 53, ACCOUNT_GOOGLE_LOCALE_CO_TH = 54, ACCOUNT_GOOGLE_LOCALE_CO_TZ = 55, ACCOUNT_GOOGLE_LOCALE_CO_UG = 56, ACCOUNT_GOOGLE_LOCALE_CO_UZ = 57, ACCOUNT_GOOGLE_LOCALE_CO_VE = 58, ACCOUNT_GOOGLE_LOCALE_CO_VI = 59, ACCOUNT_GOOGLE_LOCALE_CO_ZA = 60, ACCOUNT_GOOGLE_LOCALE_CO_ZM = 61, ACCOUNT_GOOGLE_LOCALE_CO_ZW = 62, ACCOUNT_GOOGLE_LOCALE_COM_AF = 63, ACCOUNT_GOOGLE_LOCALE_COM_AG = 64, ACCOUNT_GOOGLE_LOCALE_COM_AI = 65, ACCOUNT_GOOGLE_LOCALE_COM_AR = 66, ACCOUNT_GOOGLE_LOCALE_COM_BD = 67, ACCOUNT_GOOGLE_LOCALE_COM_BH = 68, ACCOUNT_GOOGLE_LOCALE_COM_BN = 69, ACCOUNT_GOOGLE_LOCALE_COM_BO = 70, ACCOUNT_GOOGLE_LOCALE_COM_BZ = 71, ACCOUNT_GOOGLE_LOCALE_COM_CO = 72, ACCOUNT_GOOGLE_LOCALE_COM_CU = 73, ACCOUNT_GOOGLE_LOCALE_COM_CY = 74, ACCOUNT_GOOGLE_LOCALE_COM_DO = 75, ACCOUNT_GOOGLE_LOCALE_COM_EC = 76, ACCOUNT_GOOGLE_LOCALE_COM_EG = 77, ACCOUNT_GOOGLE_LOCALE_COM_ET = 78, ACCOUNT_GOOGLE_LOCALE_COM_FJ = 79, ACCOUNT_GOOGLE_LOCALE_COM_GH = 80, ACCOUNT_GOOGLE_LOCALE_COM_GI = 81, ACCOUNT_GOOGLE_LOCALE_COM_GT = 82, ACCOUNT_GOOGLE_LOCALE_COM_JM = 83, ACCOUNT_GOOGLE_LOCALE_COM_KH = 84, ACCOUNT_GOOGLE_LOCALE_COM_KW = 85, ACCOUNT_GOOGLE_LOCALE_COM_LB = 86, ACCOUNT_GOOGLE_LOCALE_COM_LY = 87, ACCOUNT_GOOGLE_LOCALE_COM_MT = 88, ACCOUNT_GOOGLE_LOCALE_COM_NA = 89, ACCOUNT_GOOGLE_LOCALE_COM_NF = 90, ACCOUNT_GOOGLE_LOCALE_COM_NG = 91, ACCOUNT_GOOGLE_LOCALE_COM_NI = 92, ACCOUNT_GOOGLE_LOCALE_COM_NP = 93, ACCOUNT_GOOGLE_LOCALE_COM_OM = 94, ACCOUNT_GOOGLE_LOCALE_COM_PA = 95, ACCOUNT_GOOGLE_LOCALE_COM_PE = 96, ACCOUNT_GOOGLE_LOCALE_COM_PH = 97, ACCOUNT_GOOGLE_LOCALE_COM_PK = 98, ACCOUNT_GOOGLE_LOCALE_COM_PR = 99, ACCOUNT_GOOGLE_LOCALE_COM_PY = 100, ACCOUNT_GOOGLE_LOCALE_COM_QA = 101, ACCOUNT_GOOGLE_LOCALE_COM_SB = 102, ACCOUNT_GOOGLE_LOCALE_COM_SG = 103, ACCOUNT_GOOGLE_LOCALE_COM_SL = 104, ACCOUNT_GOOGLE_LOCALE_COM_SV = 105, ACCOUNT_GOOGLE_LOCALE_COM_TJ = 106, ACCOUNT_GOOGLE_LOCALE_COM_TR = 107, ACCOUNT_GOOGLE_LOCALE_COM_TW = 108, ACCOUNT_GOOGLE_LOCALE_COM_UY = 109, ACCOUNT_GOOGLE_LOCALE_COM_VC = 110, ACCOUNT_GOOGLE_LOCALE_COM_VN = 111, ACCOUNT_GOOGLE_LOCALE_CV = 112, ACCOUNT_GOOGLE_LOCALE_DJ = 113, ACCOUNT_GOOGLE_LOCALE_DM = 114, ACCOUNT_GOOGLE_LOCALE_DZ = 115, ACCOUNT_GOOGLE_LOCALE_EE = 116, ACCOUNT_GOOGLE_LOCALE_ES = 117, ACCOUNT_GOOGLE_LOCALE_FI = 118, ACCOUNT_GOOGLE_LOCALE_FM = 119, ACCOUNT_GOOGLE_LOCALE_GA = 120, ACCOUNT_GOOGLE_LOCALE_GE = 121, ACCOUNT_GOOGLE_LOCALE_GG = 122, ACCOUNT_GOOGLE_LOCALE_GL = 123, ACCOUNT_GOOGLE_LOCALE_GM = 124, ACCOUNT_GOOGLE_LOCALE_GP = 125, ACCOUNT_GOOGLE_LOCALE_GR = 126, ACCOUNT_GOOGLE_LOCALE_GY = 127, ACCOUNT_GOOGLE_LOCALE_HN = 128, ACCOUNT_GOOGLE_LOCALE_HR = 129, ACCOUNT_GOOGLE_LOCALE_HT = 130, ACCOUNT_GOOGLE_LOCALE_HU = 131, ACCOUNT_GOOGLE_LOCALE_IE = 132, ACCOUNT_GOOGLE_LOCALE_IM = 133, ACCOUNT_GOOGLE_LOCALE_IQ = 134, ACCOUNT_GOOGLE_LOCALE_IS = 135, ACCOUNT_GOOGLE_LOCALE_JE = 136, ACCOUNT_GOOGLE_LOCALE_JO = 137, ACCOUNT_GOOGLE_LOCALE_KG = 138, ACCOUNT_GOOGLE_LOCALE_KI = 139, ACCOUNT_GOOGLE_LOCALE_KZ = 140, ACCOUNT_GOOGLE_LOCALE_LA = 141, ACCOUNT_GOOGLE_LOCALE_LI = 142, ACCOUNT_GOOGLE_LOCALE_LK = 143, ACCOUNT_GOOGLE_LOCALE_LT = 144, ACCOUNT_GOOGLE_LOCALE_LU = 145, ACCOUNT_GOOGLE_LOCALE_LV = 146, ACCOUNT_GOOGLE_LOCALE_MD = 147, ACCOUNT_GOOGLE_LOCALE_ME = 148, ACCOUNT_GOOGLE_LOCALE_MG = 149, ACCOUNT_GOOGLE_LOCALE_MK = 150, ACCOUNT_GOOGLE_LOCALE_ML = 151, ACCOUNT_GOOGLE_LOCALE_MN = 152, ACCOUNT_GOOGLE_LOCALE_MS = 153, ACCOUNT_GOOGLE_LOCALE_MU = 154, ACCOUNT_GOOGLE_LOCALE_MV = 155, ACCOUNT_GOOGLE_LOCALE_MW = 156, ACCOUNT_GOOGLE_LOCALE_NE = 157, ACCOUNT_GOOGLE_LOCALE_NO = 158, ACCOUNT_GOOGLE_LOCALE_NR = 159, ACCOUNT_GOOGLE_LOCALE_NU = 160, ACCOUNT_GOOGLE_LOCALE_PL = 161, ACCOUNT_GOOGLE_LOCALE_PN = 162, ACCOUNT_GOOGLE_LOCALE_PS = 163, ACCOUNT_GOOGLE_LOCALE_PT = 164, ACCOUNT_GOOGLE_LOCALE_RO = 165, ACCOUNT_GOOGLE_LOCALE_RS = 166, ACCOUNT_GOOGLE_LOCALE_RW = 167, ACCOUNT_GOOGLE_LOCALE_SC = 168, ACCOUNT_GOOGLE_LOCALE_SE = 169, ACCOUNT_GOOGLE_LOCALE_SH = 170, ACCOUNT_GOOGLE_LOCALE_SI = 171, ACCOUNT_GOOGLE_LOCALE_SK = 172, ACCOUNT_GOOGLE_LOCALE_SM = 173, ACCOUNT_GOOGLE_LOCALE_SN = 174, ACCOUNT_GOOGLE_LOCALE_SO = 175, ACCOUNT_GOOGLE_LOCALE_ST = 176, ACCOUNT_GOOGLE_LOCALE_TD = 177, ACCOUNT_GOOGLE_LOCALE_TG = 178, ACCOUNT_GOOGLE_LOCALE_TK = 179, ACCOUNT_GOOGLE_LOCALE_TL = 180, ACCOUNT_GOOGLE_LOCALE_TM = 181, ACCOUNT_GOOGLE_LOCALE_TN = 182, ACCOUNT_GOOGLE_LOCALE_TO = 183, ACCOUNT_GOOGLE_LOCALE_TT = 184, ACCOUNT_GOOGLE_LOCALE_VG = 185, ACCOUNT_GOOGLE_LOCALE_VU = 186, ACCOUNT_GOOGLE_LOCALE_WS = 187 };
enum EnumAccountCRAWLER_NAME { ACCOUNT_CRAWLER_NAME_GOOGLEBOT = 1, ACCOUNT_CRAWLER_NAME_DRIVEBOT = 2, ACCOUNT_CRAWLER_NAME_WEBBROWSER = 3 };
enum EnumAccountSUBDOMAIN_OPTION { ACCOUNT_SUBDOMAIN_OPTION_ALL = 1, ACCOUNT_SUBDOMAIN_OPTION_NONE = 2, ACCOUNT_SUBDOMAIN_OPTION_SOME = 3 };
enum EnumAccountDEFAULT_PROTOCOL { ACCOUNT_DEFAULT_PROTOCOL_HTTP = 1, ACCOUNT_DEFAULT_PROTOCOL_HTTPS = 2 };


namespace DMMM {

class O_Account{
public:

    O_Account() {}
    O_Account(const I_Organization& parent_id) 
        : _f_organization_id(parent_id)
        {}
    O_Account(const I_AccountType& parent_id) 
        : _f_account_type_id(parent_id)
        {}

O_Account(const I_Account& id) 
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

    std::vector<O_Page> _pages() const
    {
        T_Page table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page> 
    _account_id(const T_Page::Condition& c) const
    {
        T_Page table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Competition> _competitions() const
    {
        T_Competition table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Competition> 
    _account_id(const T_Competition::Condition& c) const
    {
        T_Competition table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_HistoricalScore> _historical_scores() const
    {
        T_HistoricalScore table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_HistoricalScore> 
    _account_id(const T_HistoricalScore::Condition& c) const
    {
        T_HistoricalScore table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_MirrorPage> _mirror_pages() const
    {
        T_MirrorPage table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_MirrorPage> 
    _account_id(const T_MirrorPage::Condition& c) const
    {
        T_MirrorPage table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_SearchKeyword> _search_keywords() const
    {
        T_SearchKeyword table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_SearchKeyword> 
    _account_id(const T_SearchKeyword::Condition& c) const
    {
        T_SearchKeyword table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Subdomain> _subdomains() const
    {
        T_Subdomain table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Subdomain> 
    _account_id(const T_Subdomain::Condition& c) const
    {
        T_Subdomain table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Backlink> _backlinks() const
    {
        T_Page_Backlink table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Backlink> 
    _account_id(const T_Page_Backlink::Condition& c) const
    {
        T_Page_Backlink table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Canonical> _canonicals() const
    {
        T_Page_Canonical table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Canonical> 
    _account_id(const T_Page_Canonical::Condition& c) const
    {
        T_Page_Canonical table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Duplicate> _duplicates() const
    {
        T_Page_Duplicate table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Duplicate> 
    _account_id(const T_Page_Duplicate::Condition& c) const
    {
        T_Page_Duplicate table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Emphasis> _emphases() const
    {
        T_Page_Emphasis table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Emphasis> 
    _account_id(const T_Page_Emphasis::Condition& c) const
    {
        T_Page_Emphasis table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_HttpError> _http_errors() const
    {
        T_Page_HttpError table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_HttpError> 
    _account_id(const T_Page_HttpError::Condition& c) const
    {
        T_Page_HttpError table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Image> _images() const
    {
        T_Page_Image table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Image> 
    _account_id(const T_Page_Image::Condition& c) const
    {
        T_Page_Image table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Keyword> _keywords() const
    {
        T_Page_Keyword table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Keyword> 
    _account_id(const T_Page_Keyword::Condition& c) const
    {
        T_Page_Keyword table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Link> _links() const
    {
        T_Page_Link table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Link> 
    _account_id(const T_Page_Link::Condition& c) const
    {
        T_Page_Link table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_NonHtml> _non_htmls() const
    {
        T_Page_NonHtml table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_NonHtml> 
    _account_id(const T_Page_NonHtml::Condition& c) const
    {
        T_Page_NonHtml table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Header> _page_headers() const
    {
        T_Page_Header table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Header> 
    _account_id(const T_Page_Header::Condition& c) const
    {
        T_Page_Header table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_Page_Redirect> _redirects() const
    {
        T_Page_Redirect table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_Page_Redirect> 
    _account_id(const T_Page_Redirect::Condition& c) const
    {
        T_Page_Redirect table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_IssuePage> _issue_pages() const
    {
        T_IssuePage table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_IssuePage> 
    _account_id(const T_IssuePage::Condition& c) const
    {
        T_IssuePage table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_IssuePageClass> _issue_page_classes() const
    {
        T_IssuePageClass table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_IssuePageClass> 
    _account_id(const T_IssuePageClass::Condition& c) const
    {
        T_IssuePageClass table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_PageSearchKeyword> _page_search_keywords() const
    {
        T_PageSearchKeyword table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_PageSearchKeyword> 
    _account_id(const T_PageSearchKeyword::Condition& c) const
    {
        T_PageSearchKeyword table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_SearchCompetition> _search_competitions() const
    {
        T_SearchCompetition table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_SearchCompetition> 
    _account_id(const T_SearchCompetition::Condition& c) const
    {
        T_SearchCompetition table(c);
        return table.select(table._account_id() == _id());   
    }

    std::vector<O_KeywordGroup> _keyword_groups() const
    {
        T_KeywordGroup table;
        return table.select(table._account_id() == _id());   
    }
    std::vector<O_KeywordGroup> 
    _account_id(const T_KeywordGroup::Condition& c) const
    {
        T_KeywordGroup table(c);
        return table.select(table._account_id() == _id());   
    }

    const F_Integer::Base& _user_id() const { 
        return _f_user_id._base; 
    }
    F_Integer::Base& _user_id() { 
        _f_user_id._dirty = true; 
        return _f_user_id._base; 
    }
    const Field<I_Account>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_Account>::Base& _id() { 
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
    const F_String::Base& _site_category() const { 
        return _f_site_category._base; 
    }
    F_String::Base& _site_category() { 
        _f_site_category._dirty = true; 
        return _f_site_category._base; 
    }
    const F_String::Base& _url() const { 
        return _f_url._base; 
    }
    F_String::Base& _url() { 
        _f_url._dirty = true; 
        return _f_url._base; 
    }
    const F_Datetime::Base& _mirrored_at() const { 
        return _f_mirrored_at._base; 
    }
    F_Datetime::Base& _mirrored_at() { 
        _f_mirrored_at._dirty = true; 
        return _f_mirrored_at._base; 
    }
    const F_Datetime::Base& _analyzed_at() const { 
        return _f_analyzed_at._base; 
    }
    F_Datetime::Base& _analyzed_at() { 
        _f_analyzed_at._dirty = true; 
        return _f_analyzed_at._base; 
    }
    const F_Integer::Base& _is_mirroring() const { 
        return _f_is_mirroring._base; 
    }
    F_Integer::Base& _is_mirroring() { 
        _f_is_mirroring._dirty = true; 
        return _f_is_mirroring._base; 
    }
    const F_Integer::Base& _is_parsing() const { 
        return _f_is_parsing._base; 
    }
    F_Integer::Base& _is_parsing() { 
        _f_is_parsing._dirty = true; 
        return _f_is_parsing._base; 
    }
    const F_Integer::Base& _is_keywording() const { 
        return _f_is_keywording._base; 
    }
    F_Integer::Base& _is_keywording() { 
        _f_is_keywording._dirty = true; 
        return _f_is_keywording._base; 
    }
    const F_Integer::Base& _is_ranking() const { 
        return _f_is_ranking._base; 
    }
    F_Integer::Base& _is_ranking() { 
        _f_is_ranking._dirty = true; 
        return _f_is_ranking._base; 
    }
    const F_Integer::Base& _is_classifying() const { 
        return _f_is_classifying._base; 
    }
    F_Integer::Base& _is_classifying() { 
        _f_is_classifying._dirty = true; 
        return _f_is_classifying._base; 
    }
    const F_Integer::Base& _is_scoring() const { 
        return _f_is_scoring._base; 
    }
    F_Integer::Base& _is_scoring() { 
        _f_is_scoring._dirty = true; 
        return _f_is_scoring._base; 
    }
    const F_Integer::Base& _is_google_suggesting() const { 
        return _f_is_google_suggesting._base; 
    }
    F_Integer::Base& _is_google_suggesting() { 
        _f_is_google_suggesting._dirty = true; 
        return _f_is_google_suggesting._base; 
    }
    const F_Integer::Base& _is_analyticsing() const { 
        return _f_is_analyticsing._base; 
    }
    F_Integer::Base& _is_analyticsing() { 
        _f_is_analyticsing._dirty = true; 
        return _f_is_analyticsing._base; 
    }
    const F_Integer::Base& _has_mirror() const { 
        return _f_has_mirror._base; 
    }
    F_Integer::Base& _has_mirror() { 
        _f_has_mirror._dirty = true; 
        return _f_has_mirror._base; 
    }
    const F_Integer::Base& _analyzed() const { 
        return _f_analyzed._base; 
    }
    F_Integer::Base& _analyzed() { 
        _f_analyzed._dirty = true; 
        return _f_analyzed._base; 
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
    const F_Integer::Base& _mirror_percent() const { 
        return _f_mirror_percent._base; 
    }
    F_Integer::Base& _mirror_percent() { 
        _f_mirror_percent._dirty = true; 
        return _f_mirror_percent._base; 
    }
    const F_Integer::Base& _scoring_percent() const { 
        return _f_scoring_percent._base; 
    }
    F_Integer::Base& _scoring_percent() { 
        _f_scoring_percent._dirty = true; 
        return _f_scoring_percent._base; 
    }
    const F_Integer::Base& _ranking_percent() const { 
        return _f_ranking_percent._base; 
    }
    F_Integer::Base& _ranking_percent() { 
        _f_ranking_percent._dirty = true; 
        return _f_ranking_percent._base; 
    }
    const F_String::Base& _last_page_mirrored() const { 
        return _f_last_page_mirrored._base; 
    }
    F_String::Base& _last_page_mirrored() { 
        _f_last_page_mirrored._dirty = true; 
        return _f_last_page_mirrored._base; 
    }
    const F_String::Base& _last_page_classified() const { 
        return _f_last_page_classified._base; 
    }
    F_String::Base& _last_page_classified() { 
        _f_last_page_classified._dirty = true; 
        return _f_last_page_classified._base; 
    }
    const F_Integer::Base& _score() const { 
        return _f_score._base; 
    }
    F_Integer::Base& _score() { 
        _f_score._dirty = true; 
        return _f_score._base; 
    }
    const F_String::Base& _ga_username() const { 
        return _f_ga_username._base; 
    }
    F_String::Base& _ga_username() { 
        _f_ga_username._dirty = true; 
        return _f_ga_username._base; 
    }
    const F_String::Base& _ga_password() const { 
        return _f_ga_password._base; 
    }
    F_String::Base& _ga_password() { 
        _f_ga_password._dirty = true; 
        return _f_ga_password._base; 
    }
    const F_Integer::Base& _google_indexed_pages() const { 
        return _f_google_indexed_pages._base; 
    }
    F_Integer::Base& _google_indexed_pages() { 
        _f_google_indexed_pages._dirty = true; 
        return _f_google_indexed_pages._base; 
    }
    const F_Text::Base& _classifier_feedback() const { 
        return _f_classifier_feedback._base; 
    }
    F_Text::Base& _classifier_feedback() { 
        _f_classifier_feedback._dirty = true; 
        return _f_classifier_feedback._base; 
    }
    const F_Datetime::Base& _deleted_at() const { 
        return _f_deleted_at._base; 
    }
    F_Datetime::Base& _deleted_at() { 
        _f_deleted_at._dirty = true; 
        return _f_deleted_at._base; 
    }
    const F_Integer::Base& _using_score_view_advanced_search() const { 
        return _f_using_score_view_advanced_search._base; 
    }
    F_Integer::Base& _using_score_view_advanced_search() { 
        _f_using_score_view_advanced_search._dirty = true; 
        return _f_using_score_view_advanced_search._base; 
    }
    const F_Text::Base& _frozen_tag_list() const { 
        return _f_frozen_tag_list._base; 
    }
    F_Text::Base& _frozen_tag_list() { 
        _f_frozen_tag_list._dirty = true; 
        return _f_frozen_tag_list._base; 
    }
    const F_String::Base& _logo_file_name() const { 
        return _f_logo_file_name._base; 
    }
    F_String::Base& _logo_file_name() { 
        _f_logo_file_name._dirty = true; 
        return _f_logo_file_name._base; 
    }
    const F_String::Base& _logo_content_type() const { 
        return _f_logo_content_type._base; 
    }
    F_String::Base& _logo_content_type() { 
        _f_logo_content_type._dirty = true; 
        return _f_logo_content_type._base; 
    }
    const F_Integer::Base& _logo_file_size() const { 
        return _f_logo_file_size._base; 
    }
    F_Integer::Base& _logo_file_size() { 
        _f_logo_file_size._dirty = true; 
        return _f_logo_file_size._base; 
    }
    const F_Datetime::Base& _logo_updated_at() const { 
        return _f_logo_updated_at._base; 
    }
    F_Datetime::Base& _logo_updated_at() { 
        _f_logo_updated_at._dirty = true; 
        return _f_logo_updated_at._base; 
    }
    const F_Text::Base& _spider_entry_page() const { 
        return _f_spider_entry_page._base; 
    }
    F_Text::Base& _spider_entry_page() { 
        _f_spider_entry_page._dirty = true; 
        return _f_spider_entry_page._base; 
    }
    const F_String::Base& _ga_account_id() const { 
        return _f_ga_account_id._base; 
    }
    F_String::Base& _ga_account_id() { 
        _f_ga_account_id._dirty = true; 
        return _f_ga_account_id._base; 
    }
    const F_Integer::Base& _reload_classifier() const { 
        return _f_reload_classifier._base; 
    }
    F_Integer::Base& _reload_classifier() { 
        _f_reload_classifier._dirty = true; 
        return _f_reload_classifier._base; 
    }
    const F_Text::Base& _mirror_exclusions() const { 
        return _f_mirror_exclusions._base; 
    }
    F_Text::Base& _mirror_exclusions() { 
        _f_mirror_exclusions._dirty = true; 
        return _f_mirror_exclusions._base; 
    }
    const F_Integer::Base& _max_pages_mirrored() const { 
        return _f_max_pages_mirrored._base; 
    }
    F_Integer::Base& _max_pages_mirrored() { 
        _f_max_pages_mirrored._dirty = true; 
        return _f_max_pages_mirrored._base; 
    }
    const F_Integer::Base& _crawl_delay() const { 
        return _f_crawl_delay._base; 
    }
    F_Integer::Base& _crawl_delay() { 
        _f_crawl_delay._dirty = true; 
        return _f_crawl_delay._base; 
    }
    const Field<EnumAccountGOOGLE_LOCALE>::Base& _google_locale() const { 
        return _f_google_locale._base; 
    }
    Field<EnumAccountGOOGLE_LOCALE>::Base& _google_locale() { 
        _f_google_locale._dirty = true; 
        return _f_google_locale._base; 
    }
    const Field<EnumAccountCRAWLER_NAME>::Base& _crawler_name() const { 
        return _f_crawler_name._base; 
    }
    Field<EnumAccountCRAWLER_NAME>::Base& _crawler_name() { 
        _f_crawler_name._dirty = true; 
        return _f_crawler_name._base; 
    }
    const F_Text::Base& _mirror_inclusions() const { 
        return _f_mirror_inclusions._base; 
    }
    F_Text::Base& _mirror_inclusions() { 
        _f_mirror_inclusions._dirty = true; 
        return _f_mirror_inclusions._base; 
    }
    const F_Integer::Base& _kw_limit() const { 
        return _f_kw_limit._base; 
    }
    F_Integer::Base& _kw_limit() { 
        _f_kw_limit._dirty = true; 
        return _f_kw_limit._base; 
    }
    const F_Integer::Base& _has_ga_credentials() const { 
        return _f_has_ga_credentials._base; 
    }
    F_Integer::Base& _has_ga_credentials() { 
        _f_has_ga_credentials._dirty = true; 
        return _f_has_ga_credentials._base; 
    }
    const F_Text::Base& _ga_profiles() const { 
        return _f_ga_profiles._base; 
    }
    F_Text::Base& _ga_profiles() { 
        _f_ga_profiles._dirty = true; 
        return _f_ga_profiles._base; 
    }
    const F_Text::Base& _ga_profile() const { 
        return _f_ga_profile._base; 
    }
    F_Text::Base& _ga_profile() { 
        _f_ga_profile._dirty = true; 
        return _f_ga_profile._base; 
    }
    const F_Datetime::Base& _last_mirror_activity() const { 
        return _f_last_mirror_activity._base; 
    }
    F_Datetime::Base& _last_mirror_activity() { 
        _f_last_mirror_activity._dirty = true; 
        return _f_last_mirror_activity._base; 
    }
    const F_Boolean::Base& _follow_robots_txt() const { 
        return _f_follow_robots_txt._base; 
    }
    F_Boolean::Base& _follow_robots_txt() { 
        _f_follow_robots_txt._dirty = true; 
        return _f_follow_robots_txt._base; 
    }
    const F_Boolean::Base& _has_robots_txt() const { 
        return _f_has_robots_txt._base; 
    }
    F_Boolean::Base& _has_robots_txt() { 
        _f_has_robots_txt._dirty = true; 
        return _f_has_robots_txt._base; 
    }
    const F_Boolean::Base& _has_sitemap() const { 
        return _f_has_sitemap._base; 
    }
    F_Boolean::Base& _has_sitemap() { 
        _f_has_sitemap._dirty = true; 
        return _f_has_sitemap._base; 
    }
    const F_Boolean::Base& _sitemap_in_robots() const { 
        return _f_sitemap_in_robots._base; 
    }
    F_Boolean::Base& _sitemap_in_robots() { 
        _f_sitemap_in_robots._dirty = true; 
        return _f_sitemap_in_robots._base; 
    }
    const F_Boolean::Base& _all_subdomains() const { 
        return _f_all_subdomains._base; 
    }
    F_Boolean::Base& _all_subdomains() { 
        _f_all_subdomains._dirty = true; 
        return _f_all_subdomains._base; 
    }
    const F_Boolean::Base& _has_baidu() const { 
        return _f_has_baidu._base; 
    }
    F_Boolean::Base& _has_baidu() { 
        _f_has_baidu._dirty = true; 
        return _f_has_baidu._base; 
    }
    const F_Boolean::Base& _has_yandex() const { 
        return _f_has_yandex._base; 
    }
    F_Boolean::Base& _has_yandex() { 
        _f_has_yandex._dirty = true; 
        return _f_has_yandex._base; 
    }
    const F_Integer::Base& _account_type() const { 
        return _f_account_type._base; 
    }
    F_Integer::Base& _account_type() { 
        _f_account_type._dirty = true; 
        return _f_account_type._base; 
    }
    const Field<I_account_type_id>::Base& _account_type_id() const { 
        return _f_account_type_id._base; 
    }
    Field<I_account_type_id>::Base& _account_type_id() { 
        _f_account_type_id._dirty = true; 
        return _f_account_type_id._base; 
    }
    const F_Boolean::Base& _has_yandex_ru() const { 
        return _f_has_yandex_ru._base; 
    }
    F_Boolean::Base& _has_yandex_ru() { 
        _f_has_yandex_ru._dirty = true; 
        return _f_has_yandex_ru._base; 
    }
    const F_Boolean::Base& _has_yandex_ua() const { 
        return _f_has_yandex_ua._base; 
    }
    F_Boolean::Base& _has_yandex_ua() { 
        _f_has_yandex_ua._dirty = true; 
        return _f_has_yandex_ua._base; 
    }
    const Field<EnumAccountSUBDOMAIN_OPTION>::Base& _subdomain_option() const { 
        return _f_subdomain_option._base; 
    }
    Field<EnumAccountSUBDOMAIN_OPTION>::Base& _subdomain_option() { 
        _f_subdomain_option._dirty = true; 
        return _f_subdomain_option._base; 
    }
    const F_Integer::Base& _setup_step() const { 
        return _f_setup_step._base; 
    }
    F_Integer::Base& _setup_step() { 
        _f_setup_step._dirty = true; 
        return _f_setup_step._base; 
    }
    const F_Integer::Base& _mirroring_threads() const { 
        return _f_mirroring_threads._base; 
    }
    F_Integer::Base& _mirroring_threads() { 
        _f_mirroring_threads._dirty = true; 
        return _f_mirroring_threads._base; 
    }
    const Field<EnumAccountDEFAULT_PROTOCOL>::Base& _default_protocol() const { 
        return _f_default_protocol._base; 
    }
    Field<EnumAccountDEFAULT_PROTOCOL>::Base& _default_protocol() { 
        _f_default_protocol._dirty = true; 
        return _f_default_protocol._base; 
    }
    const F_Boolean::Base& _score_keywords_in_urls() const { 
        return _f_score_keywords_in_urls._base; 
    }
    F_Boolean::Base& _score_keywords_in_urls() { 
        _f_score_keywords_in_urls._dirty = true; 
        return _f_score_keywords_in_urls._base; 
    }
    const F_Boolean::Base& _score_content_in_urls() const { 
        return _f_score_content_in_urls._base; 
    }
    F_Boolean::Base& _score_content_in_urls() { 
        _f_score_content_in_urls._dirty = true; 
        return _f_score_content_in_urls._base; 
    }
    const F_Boolean::Base& _score_existing_titles() const { 
        return _f_score_existing_titles._base; 
    }
    F_Boolean::Base& _score_existing_titles() { 
        _f_score_existing_titles._dirty = true; 
        return _f_score_existing_titles._base; 
    }
    const F_Boolean::Base& _score_unique_titles() const { 
        return _f_score_unique_titles._base; 
    }
    F_Boolean::Base& _score_unique_titles() { 
        _f_score_unique_titles._dirty = true; 
        return _f_score_unique_titles._base; 
    }
    const F_Boolean::Base& _score_keywords_in_titles() const { 
        return _f_score_keywords_in_titles._base; 
    }
    F_Boolean::Base& _score_keywords_in_titles() { 
        _f_score_keywords_in_titles._dirty = true; 
        return _f_score_keywords_in_titles._base; 
    }
    const F_Boolean::Base& _score_content_in_titles() const { 
        return _f_score_content_in_titles._base; 
    }
    F_Boolean::Base& _score_content_in_titles() { 
        _f_score_content_in_titles._dirty = true; 
        return _f_score_content_in_titles._base; 
    }
    const F_Boolean::Base& _score_outbound_links() const { 
        return _f_score_outbound_links._base; 
    }
    F_Boolean::Base& _score_outbound_links() { 
        _f_score_outbound_links._dirty = true; 
        return _f_score_outbound_links._base; 
    }
    const F_Boolean::Base& _score_unique_content() const { 
        return _f_score_unique_content._base; 
    }
    F_Boolean::Base& _score_unique_content() { 
        _f_score_unique_content._dirty = true; 
        return _f_score_unique_content._base; 
    }
    const F_Boolean::Base& _score_existing_meta_description() const { 
        return _f_score_existing_meta_description._base; 
    }
    F_Boolean::Base& _score_existing_meta_description() { 
        _f_score_existing_meta_description._dirty = true; 
        return _f_score_existing_meta_description._base; 
    }
    const F_Boolean::Base& _score_unique_meta_description() const { 
        return _f_score_unique_meta_description._base; 
    }
    F_Boolean::Base& _score_unique_meta_description() { 
        _f_score_unique_meta_description._dirty = true; 
        return _f_score_unique_meta_description._base; 
    }
    const F_Boolean::Base& _score_keywords_in_meta_description() const { 
        return _f_score_keywords_in_meta_description._base; 
    }
    F_Boolean::Base& _score_keywords_in_meta_description() { 
        _f_score_keywords_in_meta_description._dirty = true; 
        return _f_score_keywords_in_meta_description._base; 
    }
    const F_Boolean::Base& _score_content_in_meta_description() const { 
        return _f_score_content_in_meta_description._base; 
    }
    F_Boolean::Base& _score_content_in_meta_description() { 
        _f_score_content_in_meta_description._dirty = true; 
        return _f_score_content_in_meta_description._base; 
    }
    const F_Boolean::Base& _score_overused_meta_description() const { 
        return _f_score_overused_meta_description._base; 
    }
    F_Boolean::Base& _score_overused_meta_description() { 
        _f_score_overused_meta_description._dirty = true; 
        return _f_score_overused_meta_description._base; 
    }
    const F_Boolean::Base& _score_existing_meta_keywords() const { 
        return _f_score_existing_meta_keywords._base; 
    }
    F_Boolean::Base& _score_existing_meta_keywords() { 
        _f_score_existing_meta_keywords._dirty = true; 
        return _f_score_existing_meta_keywords._base; 
    }
    const F_Boolean::Base& _score_unique_meta_keywords() const { 
        return _f_score_unique_meta_keywords._base; 
    }
    F_Boolean::Base& _score_unique_meta_keywords() { 
        _f_score_unique_meta_keywords._dirty = true; 
        return _f_score_unique_meta_keywords._base; 
    }
    const F_Boolean::Base& _score_misused_meta_keywords() const { 
        return _f_score_misused_meta_keywords._base; 
    }
    F_Boolean::Base& _score_misused_meta_keywords() { 
        _f_score_misused_meta_keywords._dirty = true; 
        return _f_score_misused_meta_keywords._base; 
    }
    const F_Boolean::Base& _score_overused_meta_keywords() const { 
        return _f_score_overused_meta_keywords._base; 
    }
    F_Boolean::Base& _score_overused_meta_keywords() { 
        _f_score_overused_meta_keywords._dirty = true; 
        return _f_score_overused_meta_keywords._base; 
    }
    const F_Boolean::Base& _score_existing_headers() const { 
        return _f_score_existing_headers._base; 
    }
    F_Boolean::Base& _score_existing_headers() { 
        _f_score_existing_headers._dirty = true; 
        return _f_score_existing_headers._base; 
    }
    const F_Boolean::Base& _score_overused_headers() const { 
        return _f_score_overused_headers._base; 
    }
    F_Boolean::Base& _score_overused_headers() { 
        _f_score_overused_headers._dirty = true; 
        return _f_score_overused_headers._base; 
    }
    const F_Boolean::Base& _score_keywords_in_headers() const { 
        return _f_score_keywords_in_headers._base; 
    }
    F_Boolean::Base& _score_keywords_in_headers() { 
        _f_score_keywords_in_headers._dirty = true; 
        return _f_score_keywords_in_headers._base; 
    }
    const F_Boolean::Base& _score_existing_h1() const { 
        return _f_score_existing_h1._base; 
    }
    F_Boolean::Base& _score_existing_h1() { 
        _f_score_existing_h1._dirty = true; 
        return _f_score_existing_h1._base; 
    }
    const F_Boolean::Base& _score_images() const { 
        return _f_score_images._base; 
    }
    F_Boolean::Base& _score_images() { 
        _f_score_images._dirty = true; 
        return _f_score_images._base; 
    }
    const F_Boolean::Base& _score_existing_emphasis() const { 
        return _f_score_existing_emphasis._base; 
    }
    F_Boolean::Base& _score_existing_emphasis() { 
        _f_score_existing_emphasis._dirty = true; 
        return _f_score_existing_emphasis._base; 
    }
    const F_Boolean::Base& _score_keywords_in_emphasis() const { 
        return _f_score_keywords_in_emphasis._base; 
    }
    F_Boolean::Base& _score_keywords_in_emphasis() { 
        _f_score_keywords_in_emphasis._dirty = true; 
        return _f_score_keywords_in_emphasis._base; 
    }
    const F_Boolean::Base& _score_overused_emphasis() const { 
        return _f_score_overused_emphasis._base; 
    }
    F_Boolean::Base& _score_overused_emphasis() { 
        _f_score_overused_emphasis._dirty = true; 
        return _f_score_overused_emphasis._base; 
    }
    const F_String::Base& _base_url() const { 
        return _f_base_url._base; 
    }
    F_String::Base& _base_url() { 
        _f_base_url._dirty = true; 
        return _f_base_url._base; 
    }
    const F_Text::Base& _follow_links() const { 
        return _f_follow_links._base; 
    }
    F_Text::Base& _follow_links() { 
        _f_follow_links._dirty = true; 
        return _f_follow_links._base; 
    }
    const F_Text::Base& _nofollow_links() const { 
        return _f_nofollow_links._base; 
    }
    F_Text::Base& _nofollow_links() { 
        _f_nofollow_links._dirty = true; 
        return _f_nofollow_links._base; 
    }
    const F_Boolean::Base& _has_mail_ru() const { 
        return _f_has_mail_ru._base; 
    }
    F_Boolean::Base& _has_mail_ru() { 
        _f_has_mail_ru._dirty = true; 
        return _f_has_mail_ru._base; 
    }
    const Field<I_organization_id>::Base& _organization_id() const { 
        return _f_organization_id._base; 
    }
    Field<I_organization_id>::Base& _organization_id() { 
        _f_organization_id._dirty = true; 
        return _f_organization_id._base; 
    }
    const F_Boolean::Base& _ignore_crawl_delay() const { 
        return _f_ignore_crawl_delay._base; 
    }
    F_Boolean::Base& _ignore_crawl_delay() { 
        _f_ignore_crawl_delay._dirty = true; 
        return _f_ignore_crawl_delay._base; 
    }
    const F_Boolean::Base& _follow_all() const { 
        return _f_follow_all._base; 
    }
    F_Boolean::Base& _follow_all() { 
        _f_follow_all._dirty = true; 
        return _f_follow_all._base; 
    }
    const F_Boolean::Base& _use_follow_links() const { 
        return _f_use_follow_links._base; 
    }
    F_Boolean::Base& _use_follow_links() { 
        _f_use_follow_links._dirty = true; 
        return _f_use_follow_links._base; 
    }
    const F_Boolean::Base& _use_nofollow_links() const { 
        return _f_use_nofollow_links._base; 
    }
    F_Boolean::Base& _use_nofollow_links() { 
        _f_use_nofollow_links._dirty = true; 
        return _f_use_nofollow_links._base; 
    }
    const F_Boolean::Base& _mirror_all() const { 
        return _f_mirror_all._base; 
    }
    F_Boolean::Base& _mirror_all() { 
        _f_mirror_all._dirty = true; 
        return _f_mirror_all._base; 
    }
    const F_Boolean::Base& _use_mirror_include() const { 
        return _f_use_mirror_include._base; 
    }
    F_Boolean::Base& _use_mirror_include() { 
        _f_use_mirror_include._dirty = true; 
        return _f_use_mirror_include._base; 
    }
    const F_Boolean::Base& _use_mirror_exclude() const { 
        return _f_use_mirror_exclude._base; 
    }
    F_Boolean::Base& _use_mirror_exclude() { 
        _f_use_mirror_exclude._dirty = true; 
        return _f_use_mirror_exclude._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_user_id._dirty)
            field2Val["user_id"] = 
                toSQLString(_f_user_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_site_category._dirty)
            field2Val["site_category"] = 
                toSQLString(_f_site_category._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_mirrored_at._dirty)
            field2Val["mirrored_at"] = 
                toSQLString(_f_mirrored_at._base);
        if (_f_analyzed_at._dirty)
            field2Val["analyzed_at"] = 
                toSQLString(_f_analyzed_at._base);
        if (_f_is_mirroring._dirty)
            field2Val["is_mirroring"] = 
                toSQLString(_f_is_mirroring._base);
        if (_f_is_parsing._dirty)
            field2Val["is_parsing"] = 
                toSQLString(_f_is_parsing._base);
        if (_f_is_keywording._dirty)
            field2Val["is_keywording"] = 
                toSQLString(_f_is_keywording._base);
        if (_f_is_ranking._dirty)
            field2Val["is_ranking"] = 
                toSQLString(_f_is_ranking._base);
        if (_f_is_classifying._dirty)
            field2Val["is_classifying"] = 
                toSQLString(_f_is_classifying._base);
        if (_f_is_scoring._dirty)
            field2Val["is_scoring"] = 
                toSQLString(_f_is_scoring._base);
        if (_f_is_google_suggesting._dirty)
            field2Val["is_google_suggesting"] = 
                toSQLString(_f_is_google_suggesting._base);
        if (_f_is_analyticsing._dirty)
            field2Val["is_analyticsing"] = 
                toSQLString(_f_is_analyticsing._base);
        if (_f_has_mirror._dirty)
            field2Val["has_mirror"] = 
                toSQLString(_f_has_mirror._base);
        if (_f_analyzed._dirty)
            field2Val["analyzed"] = 
                toSQLString(_f_analyzed._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_mirror_percent._dirty)
            field2Val["mirror_percent"] = 
                toSQLString(_f_mirror_percent._base);
        if (_f_scoring_percent._dirty)
            field2Val["scoring_percent"] = 
                toSQLString(_f_scoring_percent._base);
        if (_f_ranking_percent._dirty)
            field2Val["ranking_percent"] = 
                toSQLString(_f_ranking_percent._base);
        if (_f_last_page_mirrored._dirty)
            field2Val["last_page_mirrored"] = 
                toSQLString(_f_last_page_mirrored._base);
        if (_f_last_page_classified._dirty)
            field2Val["last_page_classified"] = 
                toSQLString(_f_last_page_classified._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_ga_username._dirty)
            field2Val["ga_username"] = 
                toSQLString(_f_ga_username._base);
        if (_f_ga_password._dirty)
            field2Val["ga_password"] = 
                toSQLString(_f_ga_password._base);
        if (_f_google_indexed_pages._dirty)
            field2Val["google_indexed_pages"] = 
                toSQLString(_f_google_indexed_pages._base);
        if (_f_classifier_feedback._dirty)
            field2Val["classifier_feedback"] = 
                toSQLString(_f_classifier_feedback._base);
        if (_f_deleted_at._dirty)
            field2Val["deleted_at"] = 
                toSQLString(_f_deleted_at._base);
        if (_f_using_score_view_advanced_search._dirty)
            field2Val["using_score_view_advanced_search"] = 
                toSQLString(_f_using_score_view_advanced_search._base);
        if (_f_frozen_tag_list._dirty)
            field2Val["frozen_tag_list"] = 
                toSQLString(_f_frozen_tag_list._base);
        if (_f_logo_file_name._dirty)
            field2Val["logo_file_name"] = 
                toSQLString(_f_logo_file_name._base);
        if (_f_logo_content_type._dirty)
            field2Val["logo_content_type"] = 
                toSQLString(_f_logo_content_type._base);
        if (_f_logo_file_size._dirty)
            field2Val["logo_file_size"] = 
                toSQLString(_f_logo_file_size._base);
        if (_f_logo_updated_at._dirty)
            field2Val["logo_updated_at"] = 
                toSQLString(_f_logo_updated_at._base);
        if (_f_spider_entry_page._dirty)
            field2Val["spider_entry_page"] = 
                toSQLString(_f_spider_entry_page._base);
        if (_f_ga_account_id._dirty)
            field2Val["ga_account_id"] = 
                toSQLString(_f_ga_account_id._base);
        if (_f_reload_classifier._dirty)
            field2Val["reload_classifier"] = 
                toSQLString(_f_reload_classifier._base);
        if (_f_mirror_exclusions._dirty)
            field2Val["mirror_exclusions"] = 
                toSQLString(_f_mirror_exclusions._base);
        if (_f_max_pages_mirrored._dirty)
            field2Val["max_pages_mirrored"] = 
                toSQLString(_f_max_pages_mirrored._base);
        if (_f_crawl_delay._dirty)
            field2Val["crawl_delay"] = 
                toSQLString(_f_crawl_delay._base);
        if (_f_google_locale._dirty)
            field2Val["google_locale"] = 
                toSQLString(_f_google_locale._base);
        if (_f_crawler_name._dirty)
            field2Val["crawler_name"] = 
                toSQLString(_f_crawler_name._base);
        if (_f_mirror_inclusions._dirty)
            field2Val["mirror_inclusions"] = 
                toSQLString(_f_mirror_inclusions._base);
        if (_f_kw_limit._dirty)
            field2Val["kw_limit"] = 
                toSQLString(_f_kw_limit._base);
        if (_f_has_ga_credentials._dirty)
            field2Val["has_ga_credentials"] = 
                toSQLString(_f_has_ga_credentials._base);
        if (_f_ga_profiles._dirty)
            field2Val["ga_profiles"] = 
                toSQLString(_f_ga_profiles._base);
        if (_f_ga_profile._dirty)
            field2Val["ga_profile"] = 
                toSQLString(_f_ga_profile._base);
        if (_f_last_mirror_activity._dirty)
            field2Val["last_mirror_activity"] = 
                toSQLString(_f_last_mirror_activity._base);
        if (_f_follow_robots_txt._dirty)
            field2Val["follow_robots_txt"] = 
                toSQLString(_f_follow_robots_txt._base);
        if (_f_has_robots_txt._dirty)
            field2Val["has_robots_txt"] = 
                toSQLString(_f_has_robots_txt._base);
        if (_f_has_sitemap._dirty)
            field2Val["has_sitemap"] = 
                toSQLString(_f_has_sitemap._base);
        if (_f_sitemap_in_robots._dirty)
            field2Val["sitemap_in_robots"] = 
                toSQLString(_f_sitemap_in_robots._base);
        if (_f_all_subdomains._dirty)
            field2Val["all_subdomains"] = 
                toSQLString(_f_all_subdomains._base);
        if (_f_has_baidu._dirty)
            field2Val["has_baidu"] = 
                toSQLString(_f_has_baidu._base);
        if (_f_has_yandex._dirty)
            field2Val["has_yandex"] = 
                toSQLString(_f_has_yandex._base);
        if (_f_account_type._dirty)
            field2Val["account_type"] = 
                toSQLString(_f_account_type._base);
        if (_f_account_type_id._dirty)
            field2Val["account_type_id"] = 
                toSQLString(_f_account_type_id._base);
        if (_f_has_yandex_ru._dirty)
            field2Val["has_yandex_ru"] = 
                toSQLString(_f_has_yandex_ru._base);
        if (_f_has_yandex_ua._dirty)
            field2Val["has_yandex_ua"] = 
                toSQLString(_f_has_yandex_ua._base);
        if (_f_subdomain_option._dirty)
            field2Val["subdomain_option"] = 
                toSQLString(_f_subdomain_option._base);
        if (_f_setup_step._dirty)
            field2Val["setup_step"] = 
                toSQLString(_f_setup_step._base);
        if (_f_mirroring_threads._dirty)
            field2Val["mirroring_threads"] = 
                toSQLString(_f_mirroring_threads._base);
        if (_f_default_protocol._dirty)
            field2Val["default_protocol"] = 
                toSQLString(_f_default_protocol._base);
        if (_f_score_keywords_in_urls._dirty)
            field2Val["score_keywords_in_urls"] = 
                toSQLString(_f_score_keywords_in_urls._base);
        if (_f_score_content_in_urls._dirty)
            field2Val["score_content_in_urls"] = 
                toSQLString(_f_score_content_in_urls._base);
        if (_f_score_existing_titles._dirty)
            field2Val["score_existing_titles"] = 
                toSQLString(_f_score_existing_titles._base);
        if (_f_score_unique_titles._dirty)
            field2Val["score_unique_titles"] = 
                toSQLString(_f_score_unique_titles._base);
        if (_f_score_keywords_in_titles._dirty)
            field2Val["score_keywords_in_titles"] = 
                toSQLString(_f_score_keywords_in_titles._base);
        if (_f_score_content_in_titles._dirty)
            field2Val["score_content_in_titles"] = 
                toSQLString(_f_score_content_in_titles._base);
        if (_f_score_outbound_links._dirty)
            field2Val["score_outbound_links"] = 
                toSQLString(_f_score_outbound_links._base);
        if (_f_score_unique_content._dirty)
            field2Val["score_unique_content"] = 
                toSQLString(_f_score_unique_content._base);
        if (_f_score_existing_meta_description._dirty)
            field2Val["score_existing_meta_description"] = 
                toSQLString(_f_score_existing_meta_description._base);
        if (_f_score_unique_meta_description._dirty)
            field2Val["score_unique_meta_description"] = 
                toSQLString(_f_score_unique_meta_description._base);
        if (_f_score_keywords_in_meta_description._dirty)
            field2Val["score_keywords_in_meta_description"] = 
                toSQLString(_f_score_keywords_in_meta_description._base);
        if (_f_score_content_in_meta_description._dirty)
            field2Val["score_content_in_meta_description"] = 
                toSQLString(_f_score_content_in_meta_description._base);
        if (_f_score_overused_meta_description._dirty)
            field2Val["score_overused_meta_description"] = 
                toSQLString(_f_score_overused_meta_description._base);
        if (_f_score_existing_meta_keywords._dirty)
            field2Val["score_existing_meta_keywords"] = 
                toSQLString(_f_score_existing_meta_keywords._base);
        if (_f_score_unique_meta_keywords._dirty)
            field2Val["score_unique_meta_keywords"] = 
                toSQLString(_f_score_unique_meta_keywords._base);
        if (_f_score_misused_meta_keywords._dirty)
            field2Val["score_misused_meta_keywords"] = 
                toSQLString(_f_score_misused_meta_keywords._base);
        if (_f_score_overused_meta_keywords._dirty)
            field2Val["score_overused_meta_keywords"] = 
                toSQLString(_f_score_overused_meta_keywords._base);
        if (_f_score_existing_headers._dirty)
            field2Val["score_existing_headers"] = 
                toSQLString(_f_score_existing_headers._base);
        if (_f_score_overused_headers._dirty)
            field2Val["score_overused_headers"] = 
                toSQLString(_f_score_overused_headers._base);
        if (_f_score_keywords_in_headers._dirty)
            field2Val["score_keywords_in_headers"] = 
                toSQLString(_f_score_keywords_in_headers._base);
        if (_f_score_existing_h1._dirty)
            field2Val["score_existing_h1"] = 
                toSQLString(_f_score_existing_h1._base);
        if (_f_score_images._dirty)
            field2Val["score_images"] = 
                toSQLString(_f_score_images._base);
        if (_f_score_existing_emphasis._dirty)
            field2Val["score_existing_emphasis"] = 
                toSQLString(_f_score_existing_emphasis._base);
        if (_f_score_keywords_in_emphasis._dirty)
            field2Val["score_keywords_in_emphasis"] = 
                toSQLString(_f_score_keywords_in_emphasis._base);
        if (_f_score_overused_emphasis._dirty)
            field2Val["score_overused_emphasis"] = 
                toSQLString(_f_score_overused_emphasis._base);
        if (_f_base_url._dirty)
            field2Val["base_url"] = 
                toSQLString(_f_base_url._base);
        if (_f_follow_links._dirty)
            field2Val["follow_links"] = 
                toSQLString(_f_follow_links._base);
        if (_f_nofollow_links._dirty)
            field2Val["nofollow_links"] = 
                toSQLString(_f_nofollow_links._base);
        if (_f_has_mail_ru._dirty)
            field2Val["has_mail_ru"] = 
                toSQLString(_f_has_mail_ru._base);
        if (_f_organization_id._dirty)
            field2Val["organization_id"] = 
                toSQLString(_f_organization_id._base);
        if (_f_ignore_crawl_delay._dirty)
            field2Val["ignore_crawl_delay"] = 
                toSQLString(_f_ignore_crawl_delay._base);
        if (_f_follow_all._dirty)
            field2Val["follow_all"] = 
                toSQLString(_f_follow_all._base);
        if (_f_use_follow_links._dirty)
            field2Val["use_follow_links"] = 
                toSQLString(_f_use_follow_links._base);
        if (_f_use_nofollow_links._dirty)
            field2Val["use_nofollow_links"] = 
                toSQLString(_f_use_nofollow_links._base);
        if (_f_mirror_all._dirty)
            field2Val["mirror_all"] = 
                toSQLString(_f_mirror_all._base);
        if (_f_use_mirror_include._dirty)
            field2Val["use_mirror_include"] = 
                toSQLString(_f_use_mirror_include._base);
        if (_f_use_mirror_exclude._dirty)
            field2Val["use_mirror_exclude"] = 
                toSQLString(_f_use_mirror_exclude._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("accounts", 
                                       field2Val, where))
        {
            _f_user_id._dirty = false;
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_site_category._dirty = false;
            _f_url._dirty = false;
            _f_mirrored_at._dirty = false;
            _f_analyzed_at._dirty = false;
            _f_is_mirroring._dirty = false;
            _f_is_parsing._dirty = false;
            _f_is_keywording._dirty = false;
            _f_is_ranking._dirty = false;
            _f_is_classifying._dirty = false;
            _f_is_scoring._dirty = false;
            _f_is_google_suggesting._dirty = false;
            _f_is_analyticsing._dirty = false;
            _f_has_mirror._dirty = false;
            _f_analyzed._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_mirror_percent._dirty = false;
            _f_scoring_percent._dirty = false;
            _f_ranking_percent._dirty = false;
            _f_last_page_mirrored._dirty = false;
            _f_last_page_classified._dirty = false;
            _f_score._dirty = false;
            _f_ga_username._dirty = false;
            _f_ga_password._dirty = false;
            _f_google_indexed_pages._dirty = false;
            _f_classifier_feedback._dirty = false;
            _f_deleted_at._dirty = false;
            _f_using_score_view_advanced_search._dirty = false;
            _f_frozen_tag_list._dirty = false;
            _f_logo_file_name._dirty = false;
            _f_logo_content_type._dirty = false;
            _f_logo_file_size._dirty = false;
            _f_logo_updated_at._dirty = false;
            _f_spider_entry_page._dirty = false;
            _f_ga_account_id._dirty = false;
            _f_reload_classifier._dirty = false;
            _f_mirror_exclusions._dirty = false;
            _f_max_pages_mirrored._dirty = false;
            _f_crawl_delay._dirty = false;
            _f_google_locale._dirty = false;
            _f_crawler_name._dirty = false;
            _f_mirror_inclusions._dirty = false;
            _f_kw_limit._dirty = false;
            _f_has_ga_credentials._dirty = false;
            _f_ga_profiles._dirty = false;
            _f_ga_profile._dirty = false;
            _f_last_mirror_activity._dirty = false;
            _f_follow_robots_txt._dirty = false;
            _f_has_robots_txt._dirty = false;
            _f_has_sitemap._dirty = false;
            _f_sitemap_in_robots._dirty = false;
            _f_all_subdomains._dirty = false;
            _f_has_baidu._dirty = false;
            _f_has_yandex._dirty = false;
            _f_account_type._dirty = false;
            _f_account_type_id._dirty = false;
            _f_has_yandex_ru._dirty = false;
            _f_has_yandex_ua._dirty = false;
            _f_subdomain_option._dirty = false;
            _f_setup_step._dirty = false;
            _f_mirroring_threads._dirty = false;
            _f_default_protocol._dirty = false;
            _f_score_keywords_in_urls._dirty = false;
            _f_score_content_in_urls._dirty = false;
            _f_score_existing_titles._dirty = false;
            _f_score_unique_titles._dirty = false;
            _f_score_keywords_in_titles._dirty = false;
            _f_score_content_in_titles._dirty = false;
            _f_score_outbound_links._dirty = false;
            _f_score_unique_content._dirty = false;
            _f_score_existing_meta_description._dirty = false;
            _f_score_unique_meta_description._dirty = false;
            _f_score_keywords_in_meta_description._dirty = false;
            _f_score_content_in_meta_description._dirty = false;
            _f_score_overused_meta_description._dirty = false;
            _f_score_existing_meta_keywords._dirty = false;
            _f_score_unique_meta_keywords._dirty = false;
            _f_score_misused_meta_keywords._dirty = false;
            _f_score_overused_meta_keywords._dirty = false;
            _f_score_existing_headers._dirty = false;
            _f_score_overused_headers._dirty = false;
            _f_score_keywords_in_headers._dirty = false;
            _f_score_existing_h1._dirty = false;
            _f_score_images._dirty = false;
            _f_score_existing_emphasis._dirty = false;
            _f_score_keywords_in_emphasis._dirty = false;
            _f_score_overused_emphasis._dirty = false;
            _f_base_url._dirty = false;
            _f_follow_links._dirty = false;
            _f_nofollow_links._dirty = false;
            _f_has_mail_ru._dirty = false;
            _f_organization_id._dirty = false;
            _f_ignore_crawl_delay._dirty = false;
            _f_follow_all._dirty = false;
            _f_use_follow_links._dirty = false;
            _f_use_nofollow_links._dirty = false;
            _f_mirror_all._dirty = false;
            _f_use_mirror_include._dirty = false;
            _f_use_mirror_exclude._dirty = false;
            return true;
        }
        else
            return false;
    }

    bool insert(){
        std::map<std::string, std::string> field2Val;
        if (_f_user_id._dirty)
            field2Val["user_id"] = 
                toSQLString(_f_user_id._base);
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_site_category._dirty)
            field2Val["site_category"] = 
                toSQLString(_f_site_category._base);
        if (_f_url._dirty)
            field2Val["url"] = 
                toSQLString(_f_url._base);
        if (_f_mirrored_at._dirty)
            field2Val["mirrored_at"] = 
                toSQLString(_f_mirrored_at._base);
        if (_f_analyzed_at._dirty)
            field2Val["analyzed_at"] = 
                toSQLString(_f_analyzed_at._base);
        if (_f_is_mirroring._dirty)
            field2Val["is_mirroring"] = 
                toSQLString(_f_is_mirroring._base);
        if (_f_is_parsing._dirty)
            field2Val["is_parsing"] = 
                toSQLString(_f_is_parsing._base);
        if (_f_is_keywording._dirty)
            field2Val["is_keywording"] = 
                toSQLString(_f_is_keywording._base);
        if (_f_is_ranking._dirty)
            field2Val["is_ranking"] = 
                toSQLString(_f_is_ranking._base);
        if (_f_is_classifying._dirty)
            field2Val["is_classifying"] = 
                toSQLString(_f_is_classifying._base);
        if (_f_is_scoring._dirty)
            field2Val["is_scoring"] = 
                toSQLString(_f_is_scoring._base);
        if (_f_is_google_suggesting._dirty)
            field2Val["is_google_suggesting"] = 
                toSQLString(_f_is_google_suggesting._base);
        if (_f_is_analyticsing._dirty)
            field2Val["is_analyticsing"] = 
                toSQLString(_f_is_analyticsing._base);
        if (_f_has_mirror._dirty)
            field2Val["has_mirror"] = 
                toSQLString(_f_has_mirror._base);
        if (_f_analyzed._dirty)
            field2Val["analyzed"] = 
                toSQLString(_f_analyzed._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_mirror_percent._dirty)
            field2Val["mirror_percent"] = 
                toSQLString(_f_mirror_percent._base);
        if (_f_scoring_percent._dirty)
            field2Val["scoring_percent"] = 
                toSQLString(_f_scoring_percent._base);
        if (_f_ranking_percent._dirty)
            field2Val["ranking_percent"] = 
                toSQLString(_f_ranking_percent._base);
        if (_f_last_page_mirrored._dirty)
            field2Val["last_page_mirrored"] = 
                toSQLString(_f_last_page_mirrored._base);
        if (_f_last_page_classified._dirty)
            field2Val["last_page_classified"] = 
                toSQLString(_f_last_page_classified._base);
        if (_f_score._dirty)
            field2Val["score"] = 
                toSQLString(_f_score._base);
        if (_f_ga_username._dirty)
            field2Val["ga_username"] = 
                toSQLString(_f_ga_username._base);
        if (_f_ga_password._dirty)
            field2Val["ga_password"] = 
                toSQLString(_f_ga_password._base);
        if (_f_google_indexed_pages._dirty)
            field2Val["google_indexed_pages"] = 
                toSQLString(_f_google_indexed_pages._base);
        if (_f_classifier_feedback._dirty)
            field2Val["classifier_feedback"] = 
                toSQLString(_f_classifier_feedback._base);
        if (_f_deleted_at._dirty)
            field2Val["deleted_at"] = 
                toSQLString(_f_deleted_at._base);
        if (_f_using_score_view_advanced_search._dirty)
            field2Val["using_score_view_advanced_search"] = 
                toSQLString(_f_using_score_view_advanced_search._base);
        if (_f_frozen_tag_list._dirty)
            field2Val["frozen_tag_list"] = 
                toSQLString(_f_frozen_tag_list._base);
        if (_f_logo_file_name._dirty)
            field2Val["logo_file_name"] = 
                toSQLString(_f_logo_file_name._base);
        if (_f_logo_content_type._dirty)
            field2Val["logo_content_type"] = 
                toSQLString(_f_logo_content_type._base);
        if (_f_logo_file_size._dirty)
            field2Val["logo_file_size"] = 
                toSQLString(_f_logo_file_size._base);
        if (_f_logo_updated_at._dirty)
            field2Val["logo_updated_at"] = 
                toSQLString(_f_logo_updated_at._base);
        if (_f_spider_entry_page._dirty)
            field2Val["spider_entry_page"] = 
                toSQLString(_f_spider_entry_page._base);
        if (_f_ga_account_id._dirty)
            field2Val["ga_account_id"] = 
                toSQLString(_f_ga_account_id._base);
        if (_f_reload_classifier._dirty)
            field2Val["reload_classifier"] = 
                toSQLString(_f_reload_classifier._base);
        if (_f_mirror_exclusions._dirty)
            field2Val["mirror_exclusions"] = 
                toSQLString(_f_mirror_exclusions._base);
        if (_f_max_pages_mirrored._dirty)
            field2Val["max_pages_mirrored"] = 
                toSQLString(_f_max_pages_mirrored._base);
        if (_f_crawl_delay._dirty)
            field2Val["crawl_delay"] = 
                toSQLString(_f_crawl_delay._base);
        if (_f_google_locale._dirty)
            field2Val["google_locale"] = 
                toSQLString(_f_google_locale._base);
        if (_f_crawler_name._dirty)
            field2Val["crawler_name"] = 
                toSQLString(_f_crawler_name._base);
        if (_f_mirror_inclusions._dirty)
            field2Val["mirror_inclusions"] = 
                toSQLString(_f_mirror_inclusions._base);
        if (_f_kw_limit._dirty)
            field2Val["kw_limit"] = 
                toSQLString(_f_kw_limit._base);
        if (_f_has_ga_credentials._dirty)
            field2Val["has_ga_credentials"] = 
                toSQLString(_f_has_ga_credentials._base);
        if (_f_ga_profiles._dirty)
            field2Val["ga_profiles"] = 
                toSQLString(_f_ga_profiles._base);
        if (_f_ga_profile._dirty)
            field2Val["ga_profile"] = 
                toSQLString(_f_ga_profile._base);
        if (_f_last_mirror_activity._dirty)
            field2Val["last_mirror_activity"] = 
                toSQLString(_f_last_mirror_activity._base);
        if (_f_follow_robots_txt._dirty)
            field2Val["follow_robots_txt"] = 
                toSQLString(_f_follow_robots_txt._base);
        if (_f_has_robots_txt._dirty)
            field2Val["has_robots_txt"] = 
                toSQLString(_f_has_robots_txt._base);
        if (_f_has_sitemap._dirty)
            field2Val["has_sitemap"] = 
                toSQLString(_f_has_sitemap._base);
        if (_f_sitemap_in_robots._dirty)
            field2Val["sitemap_in_robots"] = 
                toSQLString(_f_sitemap_in_robots._base);
        if (_f_all_subdomains._dirty)
            field2Val["all_subdomains"] = 
                toSQLString(_f_all_subdomains._base);
        if (_f_has_baidu._dirty)
            field2Val["has_baidu"] = 
                toSQLString(_f_has_baidu._base);
        if (_f_has_yandex._dirty)
            field2Val["has_yandex"] = 
                toSQLString(_f_has_yandex._base);
        if (_f_account_type._dirty)
            field2Val["account_type"] = 
                toSQLString(_f_account_type._base);
        if (_f_account_type_id._dirty)
            field2Val["account_type_id"] = 
                toSQLString(_f_account_type_id._base);
        if (_f_has_yandex_ru._dirty)
            field2Val["has_yandex_ru"] = 
                toSQLString(_f_has_yandex_ru._base);
        if (_f_has_yandex_ua._dirty)
            field2Val["has_yandex_ua"] = 
                toSQLString(_f_has_yandex_ua._base);
        if (_f_subdomain_option._dirty)
            field2Val["subdomain_option"] = 
                toSQLString(_f_subdomain_option._base);
        if (_f_setup_step._dirty)
            field2Val["setup_step"] = 
                toSQLString(_f_setup_step._base);
        if (_f_mirroring_threads._dirty)
            field2Val["mirroring_threads"] = 
                toSQLString(_f_mirroring_threads._base);
        if (_f_default_protocol._dirty)
            field2Val["default_protocol"] = 
                toSQLString(_f_default_protocol._base);
        if (_f_score_keywords_in_urls._dirty)
            field2Val["score_keywords_in_urls"] = 
                toSQLString(_f_score_keywords_in_urls._base);
        if (_f_score_content_in_urls._dirty)
            field2Val["score_content_in_urls"] = 
                toSQLString(_f_score_content_in_urls._base);
        if (_f_score_existing_titles._dirty)
            field2Val["score_existing_titles"] = 
                toSQLString(_f_score_existing_titles._base);
        if (_f_score_unique_titles._dirty)
            field2Val["score_unique_titles"] = 
                toSQLString(_f_score_unique_titles._base);
        if (_f_score_keywords_in_titles._dirty)
            field2Val["score_keywords_in_titles"] = 
                toSQLString(_f_score_keywords_in_titles._base);
        if (_f_score_content_in_titles._dirty)
            field2Val["score_content_in_titles"] = 
                toSQLString(_f_score_content_in_titles._base);
        if (_f_score_outbound_links._dirty)
            field2Val["score_outbound_links"] = 
                toSQLString(_f_score_outbound_links._base);
        if (_f_score_unique_content._dirty)
            field2Val["score_unique_content"] = 
                toSQLString(_f_score_unique_content._base);
        if (_f_score_existing_meta_description._dirty)
            field2Val["score_existing_meta_description"] = 
                toSQLString(_f_score_existing_meta_description._base);
        if (_f_score_unique_meta_description._dirty)
            field2Val["score_unique_meta_description"] = 
                toSQLString(_f_score_unique_meta_description._base);
        if (_f_score_keywords_in_meta_description._dirty)
            field2Val["score_keywords_in_meta_description"] = 
                toSQLString(_f_score_keywords_in_meta_description._base);
        if (_f_score_content_in_meta_description._dirty)
            field2Val["score_content_in_meta_description"] = 
                toSQLString(_f_score_content_in_meta_description._base);
        if (_f_score_overused_meta_description._dirty)
            field2Val["score_overused_meta_description"] = 
                toSQLString(_f_score_overused_meta_description._base);
        if (_f_score_existing_meta_keywords._dirty)
            field2Val["score_existing_meta_keywords"] = 
                toSQLString(_f_score_existing_meta_keywords._base);
        if (_f_score_unique_meta_keywords._dirty)
            field2Val["score_unique_meta_keywords"] = 
                toSQLString(_f_score_unique_meta_keywords._base);
        if (_f_score_misused_meta_keywords._dirty)
            field2Val["score_misused_meta_keywords"] = 
                toSQLString(_f_score_misused_meta_keywords._base);
        if (_f_score_overused_meta_keywords._dirty)
            field2Val["score_overused_meta_keywords"] = 
                toSQLString(_f_score_overused_meta_keywords._base);
        if (_f_score_existing_headers._dirty)
            field2Val["score_existing_headers"] = 
                toSQLString(_f_score_existing_headers._base);
        if (_f_score_overused_headers._dirty)
            field2Val["score_overused_headers"] = 
                toSQLString(_f_score_overused_headers._base);
        if (_f_score_keywords_in_headers._dirty)
            field2Val["score_keywords_in_headers"] = 
                toSQLString(_f_score_keywords_in_headers._base);
        if (_f_score_existing_h1._dirty)
            field2Val["score_existing_h1"] = 
                toSQLString(_f_score_existing_h1._base);
        if (_f_score_images._dirty)
            field2Val["score_images"] = 
                toSQLString(_f_score_images._base);
        if (_f_score_existing_emphasis._dirty)
            field2Val["score_existing_emphasis"] = 
                toSQLString(_f_score_existing_emphasis._base);
        if (_f_score_keywords_in_emphasis._dirty)
            field2Val["score_keywords_in_emphasis"] = 
                toSQLString(_f_score_keywords_in_emphasis._base);
        if (_f_score_overused_emphasis._dirty)
            field2Val["score_overused_emphasis"] = 
                toSQLString(_f_score_overused_emphasis._base);
        if (_f_base_url._dirty)
            field2Val["base_url"] = 
                toSQLString(_f_base_url._base);
        if (_f_follow_links._dirty)
            field2Val["follow_links"] = 
                toSQLString(_f_follow_links._base);
        if (_f_nofollow_links._dirty)
            field2Val["nofollow_links"] = 
                toSQLString(_f_nofollow_links._base);
        if (_f_has_mail_ru._dirty)
            field2Val["has_mail_ru"] = 
                toSQLString(_f_has_mail_ru._base);
        if (_f_organization_id._dirty)
            field2Val["organization_id"] = 
                toSQLString(_f_organization_id._base);
        if (_f_ignore_crawl_delay._dirty)
            field2Val["ignore_crawl_delay"] = 
                toSQLString(_f_ignore_crawl_delay._base);
        if (_f_follow_all._dirty)
            field2Val["follow_all"] = 
                toSQLString(_f_follow_all._base);
        if (_f_use_follow_links._dirty)
            field2Val["use_follow_links"] = 
                toSQLString(_f_use_follow_links._base);
        if (_f_use_nofollow_links._dirty)
            field2Val["use_nofollow_links"] = 
                toSQLString(_f_use_nofollow_links._base);
        if (_f_mirror_all._dirty)
            field2Val["mirror_all"] = 
                toSQLString(_f_mirror_all._base);
        if (_f_use_mirror_include._dirty)
            field2Val["use_mirror_include"] = 
                toSQLString(_f_use_mirror_include._base);
        if (_f_use_mirror_exclude._dirty)
            field2Val["use_mirror_exclude"] = 
                toSQLString(_f_use_mirror_exclude._base);
        
        if (DBFace::instance()->
                insert("accounts", field2Val,
                       _f_id._base.serialization()))
        {
            _f_user_id._dirty = false;
            _f_id._dirty = false;
            _f_name._dirty = false;
            _f_site_category._dirty = false;
            _f_url._dirty = false;
            _f_mirrored_at._dirty = false;
            _f_analyzed_at._dirty = false;
            _f_is_mirroring._dirty = false;
            _f_is_parsing._dirty = false;
            _f_is_keywording._dirty = false;
            _f_is_ranking._dirty = false;
            _f_is_classifying._dirty = false;
            _f_is_scoring._dirty = false;
            _f_is_google_suggesting._dirty = false;
            _f_is_analyticsing._dirty = false;
            _f_has_mirror._dirty = false;
            _f_analyzed._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_mirror_percent._dirty = false;
            _f_scoring_percent._dirty = false;
            _f_ranking_percent._dirty = false;
            _f_last_page_mirrored._dirty = false;
            _f_last_page_classified._dirty = false;
            _f_score._dirty = false;
            _f_ga_username._dirty = false;
            _f_ga_password._dirty = false;
            _f_google_indexed_pages._dirty = false;
            _f_classifier_feedback._dirty = false;
            _f_deleted_at._dirty = false;
            _f_using_score_view_advanced_search._dirty = false;
            _f_frozen_tag_list._dirty = false;
            _f_logo_file_name._dirty = false;
            _f_logo_content_type._dirty = false;
            _f_logo_file_size._dirty = false;
            _f_logo_updated_at._dirty = false;
            _f_spider_entry_page._dirty = false;
            _f_ga_account_id._dirty = false;
            _f_reload_classifier._dirty = false;
            _f_mirror_exclusions._dirty = false;
            _f_max_pages_mirrored._dirty = false;
            _f_crawl_delay._dirty = false;
            _f_google_locale._dirty = false;
            _f_crawler_name._dirty = false;
            _f_mirror_inclusions._dirty = false;
            _f_kw_limit._dirty = false;
            _f_has_ga_credentials._dirty = false;
            _f_ga_profiles._dirty = false;
            _f_ga_profile._dirty = false;
            _f_last_mirror_activity._dirty = false;
            _f_follow_robots_txt._dirty = false;
            _f_has_robots_txt._dirty = false;
            _f_has_sitemap._dirty = false;
            _f_sitemap_in_robots._dirty = false;
            _f_all_subdomains._dirty = false;
            _f_has_baidu._dirty = false;
            _f_has_yandex._dirty = false;
            _f_account_type._dirty = false;
            _f_account_type_id._dirty = false;
            _f_has_yandex_ru._dirty = false;
            _f_has_yandex_ua._dirty = false;
            _f_subdomain_option._dirty = false;
            _f_setup_step._dirty = false;
            _f_mirroring_threads._dirty = false;
            _f_default_protocol._dirty = false;
            _f_score_keywords_in_urls._dirty = false;
            _f_score_content_in_urls._dirty = false;
            _f_score_existing_titles._dirty = false;
            _f_score_unique_titles._dirty = false;
            _f_score_keywords_in_titles._dirty = false;
            _f_score_content_in_titles._dirty = false;
            _f_score_outbound_links._dirty = false;
            _f_score_unique_content._dirty = false;
            _f_score_existing_meta_description._dirty = false;
            _f_score_unique_meta_description._dirty = false;
            _f_score_keywords_in_meta_description._dirty = false;
            _f_score_content_in_meta_description._dirty = false;
            _f_score_overused_meta_description._dirty = false;
            _f_score_existing_meta_keywords._dirty = false;
            _f_score_unique_meta_keywords._dirty = false;
            _f_score_misused_meta_keywords._dirty = false;
            _f_score_overused_meta_keywords._dirty = false;
            _f_score_existing_headers._dirty = false;
            _f_score_overused_headers._dirty = false;
            _f_score_keywords_in_headers._dirty = false;
            _f_score_existing_h1._dirty = false;
            _f_score_images._dirty = false;
            _f_score_existing_emphasis._dirty = false;
            _f_score_keywords_in_emphasis._dirty = false;
            _f_score_overused_emphasis._dirty = false;
            _f_base_url._dirty = false;
            _f_follow_links._dirty = false;
            _f_nofollow_links._dirty = false;
            _f_has_mail_ru._dirty = false;
            _f_organization_id._dirty = false;
            _f_ignore_crawl_delay._dirty = false;
            _f_follow_all._dirty = false;
            _f_use_follow_links._dirty = false;
            _f_use_nofollow_links._dirty = false;
            _f_mirror_all._dirty = false;
            _f_use_mirror_include._dirty = false;
            _f_use_mirror_exclude._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    F_Integer _f_user_id;
    Field<I_Account> _f_id;
    F_String _f_name;
    F_String _f_site_category;
    F_String _f_url;
    F_Datetime _f_mirrored_at;
    F_Datetime _f_analyzed_at;
    F_Integer _f_is_mirroring;
    F_Integer _f_is_parsing;
    F_Integer _f_is_keywording;
    F_Integer _f_is_ranking;
    F_Integer _f_is_classifying;
    F_Integer _f_is_scoring;
    F_Integer _f_is_google_suggesting;
    F_Integer _f_is_analyticsing;
    F_Integer _f_has_mirror;
    F_Integer _f_analyzed;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;
    F_Integer _f_mirror_percent;
    F_Integer _f_scoring_percent;
    F_Integer _f_ranking_percent;
    F_String _f_last_page_mirrored;
    F_String _f_last_page_classified;
    F_Integer _f_score;
    F_String _f_ga_username;
    F_String _f_ga_password;
    F_Integer _f_google_indexed_pages;
    F_Text _f_classifier_feedback;
    F_Datetime _f_deleted_at;
    F_Integer _f_using_score_view_advanced_search;
    F_Text _f_frozen_tag_list;
    F_String _f_logo_file_name;
    F_String _f_logo_content_type;
    F_Integer _f_logo_file_size;
    F_Datetime _f_logo_updated_at;
    F_Text _f_spider_entry_page;
    F_String _f_ga_account_id;
    F_Integer _f_reload_classifier;
    F_Text _f_mirror_exclusions;
    F_Integer _f_max_pages_mirrored;
    F_Integer _f_crawl_delay;
    Field<EnumAccountGOOGLE_LOCALE> _f_google_locale;
    Field<EnumAccountCRAWLER_NAME> _f_crawler_name;
    F_Text _f_mirror_inclusions;
    F_Integer _f_kw_limit;
    F_Integer _f_has_ga_credentials;
    F_Text _f_ga_profiles;
    F_Text _f_ga_profile;
    F_Datetime _f_last_mirror_activity;
    F_Boolean _f_follow_robots_txt;
    F_Boolean _f_has_robots_txt;
    F_Boolean _f_has_sitemap;
    F_Boolean _f_sitemap_in_robots;
    F_Boolean _f_all_subdomains;
    F_Boolean _f_has_baidu;
    F_Boolean _f_has_yandex;
    F_Integer _f_account_type;
    Field<I_account_type_id> _f_account_type_id;
    F_Boolean _f_has_yandex_ru;
    F_Boolean _f_has_yandex_ua;
    Field<EnumAccountSUBDOMAIN_OPTION> _f_subdomain_option;
    F_Integer _f_setup_step;
    F_Integer _f_mirroring_threads;
    Field<EnumAccountDEFAULT_PROTOCOL> _f_default_protocol;
    F_Boolean _f_score_keywords_in_urls;
    F_Boolean _f_score_content_in_urls;
    F_Boolean _f_score_existing_titles;
    F_Boolean _f_score_unique_titles;
    F_Boolean _f_score_keywords_in_titles;
    F_Boolean _f_score_content_in_titles;
    F_Boolean _f_score_outbound_links;
    F_Boolean _f_score_unique_content;
    F_Boolean _f_score_existing_meta_description;
    F_Boolean _f_score_unique_meta_description;
    F_Boolean _f_score_keywords_in_meta_description;
    F_Boolean _f_score_content_in_meta_description;
    F_Boolean _f_score_overused_meta_description;
    F_Boolean _f_score_existing_meta_keywords;
    F_Boolean _f_score_unique_meta_keywords;
    F_Boolean _f_score_misused_meta_keywords;
    F_Boolean _f_score_overused_meta_keywords;
    F_Boolean _f_score_existing_headers;
    F_Boolean _f_score_overused_headers;
    F_Boolean _f_score_keywords_in_headers;
    F_Boolean _f_score_existing_h1;
    F_Boolean _f_score_images;
    F_Boolean _f_score_existing_emphasis;
    F_Boolean _f_score_keywords_in_emphasis;
    F_Boolean _f_score_overused_emphasis;
    F_String _f_base_url;
    F_Text _f_follow_links;
    F_Text _f_nofollow_links;
    F_Boolean _f_has_mail_ru;
    Field<I_organization_id> _f_organization_id;
    F_Boolean _f_ignore_crawl_delay;
    F_Boolean _f_follow_all;
    F_Boolean _f_use_follow_links;
    F_Boolean _f_use_nofollow_links;
    F_Boolean _f_mirror_all;
    F_Boolean _f_use_mirror_include;
    F_Boolean _f_use_mirror_exclude;

    friend class T_Account;
};

} //namespace DMMM
#endif //O_ACCOUNT
