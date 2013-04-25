
#ifndef T_USER
#define T_USER
#include "O_User.hpp"

namespace DMMM {

class T_User{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_User() 
    {
        _tables.push_back("users");
    }
    T_User(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("users");
    }

 

    T_User(const I_Organization& parentId)
    {
        _tables.push_back("users");
        
        _constraint._cond = "(users.organization_id = " + parentId.to_s() + ")";
    } 
    
    struct E_id{
        E_id() 
        {  
            _field = "users.id";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef Field<I_User>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_login{
        E_login() 
        {  
            _field = "users.login";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_login _login(){ 
        return E_login();
    }
    struct E_email{
        E_email() 
        {  
            _field = "users.email";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_email _email(){ 
        return E_email();
    }
    struct E_name{
        E_name() 
        {  
            _field = "users.name";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_current_account{
        E_current_account() 
        {  
            _field = "users.current_account";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_current_account _current_account(){ 
        return E_current_account();
    }
    struct E_account_limit{
        E_account_limit() 
        {  
            _field = "users.account_limit";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_account_limit _account_limit(){ 
        return E_account_limit();
    }
    struct E_pagination_rows{
        E_pagination_rows() 
        {  
            _field = "users.pagination_rows";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_pagination_rows _pagination_rows(){ 
        return E_pagination_rows();
    }
    struct E_is_admin{
        E_is_admin() 
        {  
            _field = "users.is_admin";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_is_admin _is_admin(){ 
        return E_is_admin();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "users.created_at";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "users.updated_at";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_crypted_password{
        E_crypted_password() 
        {  
            _field = "users.crypted_password";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_crypted_password _crypted_password(){ 
        return E_crypted_password();
    }
    struct E_salt{
        E_salt() 
        {  
            _field = "users.salt";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_salt _salt(){ 
        return E_salt();
    }
    struct E_tech_writer{
        E_tech_writer() 
        {  
            _field = "users.tech_writer";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_tech_writer _tech_writer(){ 
        return E_tech_writer();
    }
    struct E_pages_per_account{
        E_pages_per_account() 
        {  
            _field = "users.pages_per_account";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_pages_per_account _pages_per_account(){ 
        return E_pages_per_account();
    }
    struct E_user_type{
        E_user_type() 
        {  
            _field = "users.user_type";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_user_type _user_type(){ 
        return E_user_type();
    }
    struct E_counter_total_actions{
        E_counter_total_actions() 
        {  
            _field = "users.counter_total_actions";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_counter_total_actions _counter_total_actions(){ 
        return E_counter_total_actions();
    }
    struct E_counter_actions_week{
        E_counter_actions_week() 
        {  
            _field = "users.counter_actions_week";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_counter_actions_week _counter_actions_week(){ 
        return E_counter_actions_week();
    }
    struct E_counter_actions_four_week{
        E_counter_actions_four_week() 
        {  
            _field = "users.counter_actions_four_week";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_counter_actions_four_week _counter_actions_four_week(){ 
        return E_counter_actions_four_week();
    }
    struct E_api_key{
        E_api_key() 
        {  
            _field = "users.api_key";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_api_key _api_key(){ 
        return E_api_key();
    }
    struct E_api_enabled{
        E_api_enabled() 
        {  
            _field = "users.api_enabled";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_api_enabled _api_enabled(){ 
        return E_api_enabled();
    }
    struct E_organization_admin{
        E_organization_admin() 
        {  
            _field = "users.organization_admin";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_organization_admin _organization_admin(){ 
        return E_organization_admin();
    }
    struct E_organization_id{
        E_organization_id() 
        {  
            _field = "users.organization_id";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef Field<I_organization_id>::Base ComparerType;
    };

    static E_organization_id _organization_id(){ 
        return E_organization_id();
    }
    struct E_surname{
        E_surname() 
        {  
            _field = "users.surname";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_surname _surname(){ 
        return E_surname();
    }
    struct E_encrypted_password{
        E_encrypted_password() 
        {  
            _field = "users.encrypted_password";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_encrypted_password _encrypted_password(){ 
        return E_encrypted_password();
    }
    struct E_reset_password_token{
        E_reset_password_token() 
        {  
            _field = "users.reset_password_token";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_reset_password_token _reset_password_token(){ 
        return E_reset_password_token();
    }
    struct E_reset_password_sent_at{
        E_reset_password_sent_at() 
        {  
            _field = "users.reset_password_sent_at";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_reset_password_sent_at _reset_password_sent_at(){ 
        return E_reset_password_sent_at();
    }
    struct E_remember_created_at{
        E_remember_created_at() 
        {  
            _field = "users.remember_created_at";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_remember_created_at _remember_created_at(){ 
        return E_remember_created_at();
    }
    struct E_sign_in_count{
        E_sign_in_count() 
        {  
            _field = "users.sign_in_count";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_sign_in_count _sign_in_count(){ 
        return E_sign_in_count();
    }
    struct E_current_sign_in_at{
        E_current_sign_in_at() 
        {  
            _field = "users.current_sign_in_at";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_current_sign_in_at _current_sign_in_at(){ 
        return E_current_sign_in_at();
    }
    struct E_last_sign_in_at{
        E_last_sign_in_at() 
        {  
            _field = "users.last_sign_in_at";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_last_sign_in_at _last_sign_in_at(){ 
        return E_last_sign_in_at();
    }
    struct E_current_sign_in_ip{
        E_current_sign_in_ip() 
        {  
            _field = "users.current_sign_in_ip";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_current_sign_in_ip _current_sign_in_ip(){ 
        return E_current_sign_in_ip();
    }
    struct E_last_sign_in_ip{
        E_last_sign_in_ip() 
        {  
            _field = "users.last_sign_in_ip";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_last_sign_in_ip _last_sign_in_ip(){ 
        return E_last_sign_in_ip();
    }
    struct E_job_title{
        E_job_title() 
        {  
            _field = "users.job_title";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_job_title _job_title(){ 
        return E_job_title();
    }
    struct E_phone{
        E_phone() 
        {  
            _field = "users.phone";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_phone _phone(){ 
        return E_phone();
    }
    struct E_skype_name{
        E_skype_name() 
        {  
            _field = "users.skype_name";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_skype_name _skype_name(){ 
        return E_skype_name();
    }
    struct E_twitter_name{
        E_twitter_name() 
        {  
            _field = "users.twitter_name";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_twitter_name _twitter_name(){ 
        return E_twitter_name();
    }
    struct E_active{
        E_active() 
        {  
            _field = "users.active";
        }
        std::string _field;
        typedef T_User::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_active _active(){ 
        return E_active();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("login");
        ret.push_back("email");
        ret.push_back("name");
        ret.push_back("current_account");
        ret.push_back("account_limit");
        ret.push_back("pagination_rows");
        ret.push_back("is_admin");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("crypted_password");
        ret.push_back("salt");
        ret.push_back("tech_writer");
        ret.push_back("pages_per_account");
        ret.push_back("user_type");
        ret.push_back("counter_total_actions");
        ret.push_back("counter_actions_week");
        ret.push_back("counter_actions_four_week");
        ret.push_back("api_key");
        ret.push_back("api_enabled");
        ret.push_back("organization_admin");
        ret.push_back("organization_id");
        ret.push_back("surname");
        ret.push_back("encrypted_password");
        ret.push_back("reset_password_token");
        ret.push_back("reset_password_sent_at");
        ret.push_back("remember_created_at");
        ret.push_back("sign_in_count");
        ret.push_back("current_sign_in_at");
        ret.push_back("last_sign_in_at");
        ret.push_back("current_sign_in_ip");
        ret.push_back("last_sign_in_ip");
        ret.push_back("job_title");
        ret.push_back("phone");
        ret.push_back("skype_name");
        ret.push_back("twitter_name");
        ret.push_back("active");
        return ret;
    }

    std::vector<O_User> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_User> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_User>::Base>(res[i]["id"]);
            ret[i]._f_login._base =
                UTILS::fromString<F_String::Base>(res[i]["login"]);
            ret[i]._f_email._base =
                UTILS::fromString<F_String::Base>(res[i]["email"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_current_account._base =
                UTILS::fromString<F_Integer::Base>(res[i]["current_account"]);
            ret[i]._f_account_limit._base =
                UTILS::fromString<F_Integer::Base>(res[i]["account_limit"]);
            ret[i]._f_pagination_rows._base =
                UTILS::fromString<F_Integer::Base>(res[i]["pagination_rows"]);
            ret[i]._f_is_admin._base =
                UTILS::fromString<F_Integer::Base>(res[i]["is_admin"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_crypted_password._base =
                UTILS::fromString<F_String::Base>(res[i]["crypted_password"]);
            ret[i]._f_salt._base =
                UTILS::fromString<F_String::Base>(res[i]["salt"]);
            ret[i]._f_tech_writer._base =
                UTILS::fromString<F_Integer::Base>(res[i]["tech_writer"]);
            ret[i]._f_pages_per_account._base =
                UTILS::fromString<F_Integer::Base>(res[i]["pages_per_account"]);
            ret[i]._f_user_type._base =
                UTILS::fromString<F_Integer::Base>(res[i]["user_type"]);
            ret[i]._f_counter_total_actions._base =
                UTILS::fromString<F_Integer::Base>(res[i]["counter_total_actions"]);
            ret[i]._f_counter_actions_week._base =
                UTILS::fromString<F_Integer::Base>(res[i]["counter_actions_week"]);
            ret[i]._f_counter_actions_four_week._base =
                UTILS::fromString<F_Integer::Base>(res[i]["counter_actions_four_week"]);
            ret[i]._f_api_key._base =
                UTILS::fromString<F_String::Base>(res[i]["api_key"]);
            ret[i]._f_api_enabled._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["api_enabled"]);
            ret[i]._f_organization_admin._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["organization_admin"]);
            ret[i]._f_organization_id._base =
                UTILS::fromString<Field<I_organization_id>::Base>(res[i]["organization_id"]);
            ret[i]._f_surname._base =
                UTILS::fromString<F_String::Base>(res[i]["surname"]);
            ret[i]._f_encrypted_password._base =
                UTILS::fromString<F_String::Base>(res[i]["encrypted_password"]);
            ret[i]._f_reset_password_token._base =
                UTILS::fromString<F_String::Base>(res[i]["reset_password_token"]);
            ret[i]._f_reset_password_sent_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["reset_password_sent_at"]);
            ret[i]._f_remember_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["remember_created_at"]);
            ret[i]._f_sign_in_count._base =
                UTILS::fromString<F_Integer::Base>(res[i]["sign_in_count"]);
            ret[i]._f_current_sign_in_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["current_sign_in_at"]);
            ret[i]._f_last_sign_in_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["last_sign_in_at"]);
            ret[i]._f_current_sign_in_ip._base =
                UTILS::fromString<F_String::Base>(res[i]["current_sign_in_ip"]);
            ret[i]._f_last_sign_in_ip._base =
                UTILS::fromString<F_String::Base>(res[i]["last_sign_in_ip"]);
            ret[i]._f_job_title._base =
                UTILS::fromString<F_String::Base>(res[i]["job_title"]);
            ret[i]._f_phone._base =
                UTILS::fromString<F_String::Base>(res[i]["phone"]);
            ret[i]._f_skype_name._base =
                UTILS::fromString<F_String::Base>(res[i]["skype_name"]);
            ret[i]._f_twitter_name._base =
                UTILS::fromString<F_String::Base>(res[i]["twitter_name"]);
            ret[i]._f_active._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["active"]);
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


    std::vector<O_User> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_User> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_User> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_User, bool> select(const I_User& id){
        return first(E_id() == id);
    }

    std::pair<O_User, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_User> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_User(), false);
    }

    std::pair<O_User, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_User>::const_iterator begin,
                         std::vector<O_User>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("login"));
        
        fields.push_back(std::string("email"));
        
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("current_account"));
        
        fields.push_back(std::string("account_limit"));
        
        fields.push_back(std::string("pagination_rows"));
        
        fields.push_back(std::string("is_admin"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("crypted_password"));
        
        fields.push_back(std::string("salt"));
        
        fields.push_back(std::string("tech_writer"));
        
        fields.push_back(std::string("pages_per_account"));
        
        fields.push_back(std::string("user_type"));
        
        fields.push_back(std::string("counter_total_actions"));
        
        fields.push_back(std::string("counter_actions_week"));
        
        fields.push_back(std::string("counter_actions_four_week"));
        
        fields.push_back(std::string("api_key"));
        
        fields.push_back(std::string("api_enabled"));
        
        fields.push_back(std::string("organization_admin"));
        
        fields.push_back(std::string("organization_id"));
        
        fields.push_back(std::string("surname"));
        
        fields.push_back(std::string("encrypted_password"));
        
        fields.push_back(std::string("reset_password_token"));
        
        fields.push_back(std::string("reset_password_sent_at"));
        
        fields.push_back(std::string("remember_created_at"));
        
        fields.push_back(std::string("sign_in_count"));
        
        fields.push_back(std::string("current_sign_in_at"));
        
        fields.push_back(std::string("last_sign_in_at"));
        
        fields.push_back(std::string("current_sign_in_ip"));
        
        fields.push_back(std::string("last_sign_in_ip"));
        
        fields.push_back(std::string("job_title"));
        
        fields.push_back(std::string("phone"));
        
        fields.push_back(std::string("skype_name"));
        
        fields.push_back(std::string("twitter_name"));
        
        fields.push_back(std::string("active"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_User& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._login()));
            
            row.push_back(toSQLString(r._email()));
            
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._current_account()));
            
            row.push_back(toSQLString(r._account_limit()));
            
            row.push_back(toSQLString(r._pagination_rows()));
            
            row.push_back(toSQLString(r._is_admin()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._crypted_password()));
            
            row.push_back(toSQLString(r._salt()));
            
            row.push_back(toSQLString(r._tech_writer()));
            
            row.push_back(toSQLString(r._pages_per_account()));
            
            row.push_back(toSQLString(r._user_type()));
            
            row.push_back(toSQLString(r._counter_total_actions()));
            
            row.push_back(toSQLString(r._counter_actions_week()));
            
            row.push_back(toSQLString(r._counter_actions_four_week()));
            
            row.push_back(toSQLString(r._api_key()));
            
            row.push_back(toSQLString(r._api_enabled()));
            
            row.push_back(toSQLString(r._organization_admin()));
            
            row.push_back(toSQLString(r._organization_id()));
            
            row.push_back(toSQLString(r._surname()));
            
            row.push_back(toSQLString(r._encrypted_password()));
            
            row.push_back(toSQLString(r._reset_password_token()));
            
            row.push_back(toSQLString(r._reset_password_sent_at()));
            
            row.push_back(toSQLString(r._remember_created_at()));
            
            row.push_back(toSQLString(r._sign_in_count()));
            
            row.push_back(toSQLString(r._current_sign_in_at()));
            
            row.push_back(toSQLString(r._last_sign_in_at()));
            
            row.push_back(toSQLString(r._current_sign_in_ip()));
            
            row.push_back(toSQLString(r._last_sign_in_ip()));
            
            row.push_back(toSQLString(r._job_title()));
            
            row.push_back(toSQLString(r._phone()));
            
            row.push_back(toSQLString(r._skype_name()));
            
            row.push_back(toSQLString(r._twitter_name()));
            
            row.push_back(toSQLString(r._active()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("users",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_User>::const_iterator begin,
                           std::vector<O_User>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_User>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_login._dirty){
                fields.push_back(std::string("login"));
                row.push_back(toSQLString(it->_login()));
            }
            
            if (it->_f_email._dirty){
                fields.push_back(std::string("email"));
                row.push_back(toSQLString(it->_email()));
            }
            
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_current_account._dirty){
                fields.push_back(std::string("current_account"));
                row.push_back(toSQLString(it->_current_account()));
            }
            
            if (it->_f_account_limit._dirty){
                fields.push_back(std::string("account_limit"));
                row.push_back(toSQLString(it->_account_limit()));
            }
            
            if (it->_f_pagination_rows._dirty){
                fields.push_back(std::string("pagination_rows"));
                row.push_back(toSQLString(it->_pagination_rows()));
            }
            
            if (it->_f_is_admin._dirty){
                fields.push_back(std::string("is_admin"));
                row.push_back(toSQLString(it->_is_admin()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_crypted_password._dirty){
                fields.push_back(std::string("crypted_password"));
                row.push_back(toSQLString(it->_crypted_password()));
            }
            
            if (it->_f_salt._dirty){
                fields.push_back(std::string("salt"));
                row.push_back(toSQLString(it->_salt()));
            }
            
            if (it->_f_tech_writer._dirty){
                fields.push_back(std::string("tech_writer"));
                row.push_back(toSQLString(it->_tech_writer()));
            }
            
            if (it->_f_pages_per_account._dirty){
                fields.push_back(std::string("pages_per_account"));
                row.push_back(toSQLString(it->_pages_per_account()));
            }
            
            if (it->_f_user_type._dirty){
                fields.push_back(std::string("user_type"));
                row.push_back(toSQLString(it->_user_type()));
            }
            
            if (it->_f_counter_total_actions._dirty){
                fields.push_back(std::string("counter_total_actions"));
                row.push_back(toSQLString(it->_counter_total_actions()));
            }
            
            if (it->_f_counter_actions_week._dirty){
                fields.push_back(std::string("counter_actions_week"));
                row.push_back(toSQLString(it->_counter_actions_week()));
            }
            
            if (it->_f_counter_actions_four_week._dirty){
                fields.push_back(std::string("counter_actions_four_week"));
                row.push_back(toSQLString(it->_counter_actions_four_week()));
            }
            
            if (it->_f_api_key._dirty){
                fields.push_back(std::string("api_key"));
                row.push_back(toSQLString(it->_api_key()));
            }
            
            if (it->_f_api_enabled._dirty){
                fields.push_back(std::string("api_enabled"));
                row.push_back(toSQLString(it->_api_enabled()));
            }
            
            if (it->_f_organization_admin._dirty){
                fields.push_back(std::string("organization_admin"));
                row.push_back(toSQLString(it->_organization_admin()));
            }
            
            if (it->_f_organization_id._dirty){
                fields.push_back(std::string("organization_id"));
                row.push_back(toSQLString(it->_organization_id()));
            }
            
            if (it->_f_surname._dirty){
                fields.push_back(std::string("surname"));
                row.push_back(toSQLString(it->_surname()));
            }
            
            if (it->_f_encrypted_password._dirty){
                fields.push_back(std::string("encrypted_password"));
                row.push_back(toSQLString(it->_encrypted_password()));
            }
            
            if (it->_f_reset_password_token._dirty){
                fields.push_back(std::string("reset_password_token"));
                row.push_back(toSQLString(it->_reset_password_token()));
            }
            
            if (it->_f_reset_password_sent_at._dirty){
                fields.push_back(std::string("reset_password_sent_at"));
                row.push_back(toSQLString(it->_reset_password_sent_at()));
            }
            
            if (it->_f_remember_created_at._dirty){
                fields.push_back(std::string("remember_created_at"));
                row.push_back(toSQLString(it->_remember_created_at()));
            }
            
            if (it->_f_sign_in_count._dirty){
                fields.push_back(std::string("sign_in_count"));
                row.push_back(toSQLString(it->_sign_in_count()));
            }
            
            if (it->_f_current_sign_in_at._dirty){
                fields.push_back(std::string("current_sign_in_at"));
                row.push_back(toSQLString(it->_current_sign_in_at()));
            }
            
            if (it->_f_last_sign_in_at._dirty){
                fields.push_back(std::string("last_sign_in_at"));
                row.push_back(toSQLString(it->_last_sign_in_at()));
            }
            
            if (it->_f_current_sign_in_ip._dirty){
                fields.push_back(std::string("current_sign_in_ip"));
                row.push_back(toSQLString(it->_current_sign_in_ip()));
            }
            
            if (it->_f_last_sign_in_ip._dirty){
                fields.push_back(std::string("last_sign_in_ip"));
                row.push_back(toSQLString(it->_last_sign_in_ip()));
            }
            
            if (it->_f_job_title._dirty){
                fields.push_back(std::string("job_title"));
                row.push_back(toSQLString(it->_job_title()));
            }
            
            if (it->_f_phone._dirty){
                fields.push_back(std::string("phone"));
                row.push_back(toSQLString(it->_phone()));
            }
            
            if (it->_f_skype_name._dirty){
                fields.push_back(std::string("skype_name"));
                row.push_back(toSQLString(it->_skype_name()));
            }
            
            if (it->_f_twitter_name._dirty){
                fields.push_back(std::string("twitter_name"));
                row.push_back(toSQLString(it->_twitter_name()));
            }
            
            if (it->_f_active._dirty){
                fields.push_back(std::string("active"));
                row.push_back(toSQLString(it->_active()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("users",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_USER
