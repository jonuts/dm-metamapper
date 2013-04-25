#ifndef O_USER
#define O_USER

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_User{
public:

    O_User() {}
    O_User(const I_Organization& parent_id) 
        : _f_organization_id(parent_id)
        {}

O_User(const I_User& id) 
        : _f_id(id)
        {}


    const Field<I_User>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_User>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_String::Base& _login() const { 
        return _f_login._base; 
    }
    F_String::Base& _login() { 
        _f_login._dirty = true; 
        return _f_login._base; 
    }
    const F_String::Base& _email() const { 
        return _f_email._base; 
    }
    F_String::Base& _email() { 
        _f_email._dirty = true; 
        return _f_email._base; 
    }
    const F_String::Base& _name() const { 
        return _f_name._base; 
    }
    F_String::Base& _name() { 
        _f_name._dirty = true; 
        return _f_name._base; 
    }
    const F_Integer::Base& _current_account() const { 
        return _f_current_account._base; 
    }
    F_Integer::Base& _current_account() { 
        _f_current_account._dirty = true; 
        return _f_current_account._base; 
    }
    const F_Integer::Base& _account_limit() const { 
        return _f_account_limit._base; 
    }
    F_Integer::Base& _account_limit() { 
        _f_account_limit._dirty = true; 
        return _f_account_limit._base; 
    }
    const F_Integer::Base& _pagination_rows() const { 
        return _f_pagination_rows._base; 
    }
    F_Integer::Base& _pagination_rows() { 
        _f_pagination_rows._dirty = true; 
        return _f_pagination_rows._base; 
    }
    const F_Integer::Base& _is_admin() const { 
        return _f_is_admin._base; 
    }
    F_Integer::Base& _is_admin() { 
        _f_is_admin._dirty = true; 
        return _f_is_admin._base; 
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
    const F_String::Base& _crypted_password() const { 
        return _f_crypted_password._base; 
    }
    F_String::Base& _crypted_password() { 
        _f_crypted_password._dirty = true; 
        return _f_crypted_password._base; 
    }
    const F_String::Base& _salt() const { 
        return _f_salt._base; 
    }
    F_String::Base& _salt() { 
        _f_salt._dirty = true; 
        return _f_salt._base; 
    }
    const F_Integer::Base& _tech_writer() const { 
        return _f_tech_writer._base; 
    }
    F_Integer::Base& _tech_writer() { 
        _f_tech_writer._dirty = true; 
        return _f_tech_writer._base; 
    }
    const F_Integer::Base& _pages_per_account() const { 
        return _f_pages_per_account._base; 
    }
    F_Integer::Base& _pages_per_account() { 
        _f_pages_per_account._dirty = true; 
        return _f_pages_per_account._base; 
    }
    const F_Integer::Base& _user_type() const { 
        return _f_user_type._base; 
    }
    F_Integer::Base& _user_type() { 
        _f_user_type._dirty = true; 
        return _f_user_type._base; 
    }
    const F_Integer::Base& _counter_total_actions() const { 
        return _f_counter_total_actions._base; 
    }
    F_Integer::Base& _counter_total_actions() { 
        _f_counter_total_actions._dirty = true; 
        return _f_counter_total_actions._base; 
    }
    const F_Integer::Base& _counter_actions_week() const { 
        return _f_counter_actions_week._base; 
    }
    F_Integer::Base& _counter_actions_week() { 
        _f_counter_actions_week._dirty = true; 
        return _f_counter_actions_week._base; 
    }
    const F_Integer::Base& _counter_actions_four_week() const { 
        return _f_counter_actions_four_week._base; 
    }
    F_Integer::Base& _counter_actions_four_week() { 
        _f_counter_actions_four_week._dirty = true; 
        return _f_counter_actions_four_week._base; 
    }
    const F_String::Base& _api_key() const { 
        return _f_api_key._base; 
    }
    F_String::Base& _api_key() { 
        _f_api_key._dirty = true; 
        return _f_api_key._base; 
    }
    const F_Boolean::Base& _api_enabled() const { 
        return _f_api_enabled._base; 
    }
    F_Boolean::Base& _api_enabled() { 
        _f_api_enabled._dirty = true; 
        return _f_api_enabled._base; 
    }
    const F_Boolean::Base& _organization_admin() const { 
        return _f_organization_admin._base; 
    }
    F_Boolean::Base& _organization_admin() { 
        _f_organization_admin._dirty = true; 
        return _f_organization_admin._base; 
    }
    const Field<I_organization_id>::Base& _organization_id() const { 
        return _f_organization_id._base; 
    }
    Field<I_organization_id>::Base& _organization_id() { 
        _f_organization_id._dirty = true; 
        return _f_organization_id._base; 
    }
    const F_String::Base& _surname() const { 
        return _f_surname._base; 
    }
    F_String::Base& _surname() { 
        _f_surname._dirty = true; 
        return _f_surname._base; 
    }
    const F_String::Base& _encrypted_password() const { 
        return _f_encrypted_password._base; 
    }
    F_String::Base& _encrypted_password() { 
        _f_encrypted_password._dirty = true; 
        return _f_encrypted_password._base; 
    }
    const F_String::Base& _reset_password_token() const { 
        return _f_reset_password_token._base; 
    }
    F_String::Base& _reset_password_token() { 
        _f_reset_password_token._dirty = true; 
        return _f_reset_password_token._base; 
    }
    const F_Datetime::Base& _reset_password_sent_at() const { 
        return _f_reset_password_sent_at._base; 
    }
    F_Datetime::Base& _reset_password_sent_at() { 
        _f_reset_password_sent_at._dirty = true; 
        return _f_reset_password_sent_at._base; 
    }
    const F_Datetime::Base& _remember_created_at() const { 
        return _f_remember_created_at._base; 
    }
    F_Datetime::Base& _remember_created_at() { 
        _f_remember_created_at._dirty = true; 
        return _f_remember_created_at._base; 
    }
    const F_Integer::Base& _sign_in_count() const { 
        return _f_sign_in_count._base; 
    }
    F_Integer::Base& _sign_in_count() { 
        _f_sign_in_count._dirty = true; 
        return _f_sign_in_count._base; 
    }
    const F_Datetime::Base& _current_sign_in_at() const { 
        return _f_current_sign_in_at._base; 
    }
    F_Datetime::Base& _current_sign_in_at() { 
        _f_current_sign_in_at._dirty = true; 
        return _f_current_sign_in_at._base; 
    }
    const F_Datetime::Base& _last_sign_in_at() const { 
        return _f_last_sign_in_at._base; 
    }
    F_Datetime::Base& _last_sign_in_at() { 
        _f_last_sign_in_at._dirty = true; 
        return _f_last_sign_in_at._base; 
    }
    const F_String::Base& _current_sign_in_ip() const { 
        return _f_current_sign_in_ip._base; 
    }
    F_String::Base& _current_sign_in_ip() { 
        _f_current_sign_in_ip._dirty = true; 
        return _f_current_sign_in_ip._base; 
    }
    const F_String::Base& _last_sign_in_ip() const { 
        return _f_last_sign_in_ip._base; 
    }
    F_String::Base& _last_sign_in_ip() { 
        _f_last_sign_in_ip._dirty = true; 
        return _f_last_sign_in_ip._base; 
    }
    const F_String::Base& _job_title() const { 
        return _f_job_title._base; 
    }
    F_String::Base& _job_title() { 
        _f_job_title._dirty = true; 
        return _f_job_title._base; 
    }
    const F_String::Base& _phone() const { 
        return _f_phone._base; 
    }
    F_String::Base& _phone() { 
        _f_phone._dirty = true; 
        return _f_phone._base; 
    }
    const F_String::Base& _skype_name() const { 
        return _f_skype_name._base; 
    }
    F_String::Base& _skype_name() { 
        _f_skype_name._dirty = true; 
        return _f_skype_name._base; 
    }
    const F_String::Base& _twitter_name() const { 
        return _f_twitter_name._base; 
    }
    F_String::Base& _twitter_name() { 
        _f_twitter_name._dirty = true; 
        return _f_twitter_name._base; 
    }
    const F_Boolean::Base& _active() const { 
        return _f_active._base; 
    }
    F_Boolean::Base& _active() { 
        _f_active._dirty = true; 
        return _f_active._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_login._dirty)
            field2Val["login"] = 
                toSQLString(_f_login._base);
        if (_f_email._dirty)
            field2Val["email"] = 
                toSQLString(_f_email._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_current_account._dirty)
            field2Val["current_account"] = 
                toSQLString(_f_current_account._base);
        if (_f_account_limit._dirty)
            field2Val["account_limit"] = 
                toSQLString(_f_account_limit._base);
        if (_f_pagination_rows._dirty)
            field2Val["pagination_rows"] = 
                toSQLString(_f_pagination_rows._base);
        if (_f_is_admin._dirty)
            field2Val["is_admin"] = 
                toSQLString(_f_is_admin._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_crypted_password._dirty)
            field2Val["crypted_password"] = 
                toSQLString(_f_crypted_password._base);
        if (_f_salt._dirty)
            field2Val["salt"] = 
                toSQLString(_f_salt._base);
        if (_f_tech_writer._dirty)
            field2Val["tech_writer"] = 
                toSQLString(_f_tech_writer._base);
        if (_f_pages_per_account._dirty)
            field2Val["pages_per_account"] = 
                toSQLString(_f_pages_per_account._base);
        if (_f_user_type._dirty)
            field2Val["user_type"] = 
                toSQLString(_f_user_type._base);
        if (_f_counter_total_actions._dirty)
            field2Val["counter_total_actions"] = 
                toSQLString(_f_counter_total_actions._base);
        if (_f_counter_actions_week._dirty)
            field2Val["counter_actions_week"] = 
                toSQLString(_f_counter_actions_week._base);
        if (_f_counter_actions_four_week._dirty)
            field2Val["counter_actions_four_week"] = 
                toSQLString(_f_counter_actions_four_week._base);
        if (_f_api_key._dirty)
            field2Val["api_key"] = 
                toSQLString(_f_api_key._base);
        if (_f_api_enabled._dirty)
            field2Val["api_enabled"] = 
                toSQLString(_f_api_enabled._base);
        if (_f_organization_admin._dirty)
            field2Val["organization_admin"] = 
                toSQLString(_f_organization_admin._base);
        if (_f_organization_id._dirty)
            field2Val["organization_id"] = 
                toSQLString(_f_organization_id._base);
        if (_f_surname._dirty)
            field2Val["surname"] = 
                toSQLString(_f_surname._base);
        if (_f_encrypted_password._dirty)
            field2Val["encrypted_password"] = 
                toSQLString(_f_encrypted_password._base);
        if (_f_reset_password_token._dirty)
            field2Val["reset_password_token"] = 
                toSQLString(_f_reset_password_token._base);
        if (_f_reset_password_sent_at._dirty)
            field2Val["reset_password_sent_at"] = 
                toSQLString(_f_reset_password_sent_at._base);
        if (_f_remember_created_at._dirty)
            field2Val["remember_created_at"] = 
                toSQLString(_f_remember_created_at._base);
        if (_f_sign_in_count._dirty)
            field2Val["sign_in_count"] = 
                toSQLString(_f_sign_in_count._base);
        if (_f_current_sign_in_at._dirty)
            field2Val["current_sign_in_at"] = 
                toSQLString(_f_current_sign_in_at._base);
        if (_f_last_sign_in_at._dirty)
            field2Val["last_sign_in_at"] = 
                toSQLString(_f_last_sign_in_at._base);
        if (_f_current_sign_in_ip._dirty)
            field2Val["current_sign_in_ip"] = 
                toSQLString(_f_current_sign_in_ip._base);
        if (_f_last_sign_in_ip._dirty)
            field2Val["last_sign_in_ip"] = 
                toSQLString(_f_last_sign_in_ip._base);
        if (_f_job_title._dirty)
            field2Val["job_title"] = 
                toSQLString(_f_job_title._base);
        if (_f_phone._dirty)
            field2Val["phone"] = 
                toSQLString(_f_phone._base);
        if (_f_skype_name._dirty)
            field2Val["skype_name"] = 
                toSQLString(_f_skype_name._base);
        if (_f_twitter_name._dirty)
            field2Val["twitter_name"] = 
                toSQLString(_f_twitter_name._base);
        if (_f_active._dirty)
            field2Val["active"] = 
                toSQLString(_f_active._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("users", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_login._dirty = false;
            _f_email._dirty = false;
            _f_name._dirty = false;
            _f_current_account._dirty = false;
            _f_account_limit._dirty = false;
            _f_pagination_rows._dirty = false;
            _f_is_admin._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_crypted_password._dirty = false;
            _f_salt._dirty = false;
            _f_tech_writer._dirty = false;
            _f_pages_per_account._dirty = false;
            _f_user_type._dirty = false;
            _f_counter_total_actions._dirty = false;
            _f_counter_actions_week._dirty = false;
            _f_counter_actions_four_week._dirty = false;
            _f_api_key._dirty = false;
            _f_api_enabled._dirty = false;
            _f_organization_admin._dirty = false;
            _f_organization_id._dirty = false;
            _f_surname._dirty = false;
            _f_encrypted_password._dirty = false;
            _f_reset_password_token._dirty = false;
            _f_reset_password_sent_at._dirty = false;
            _f_remember_created_at._dirty = false;
            _f_sign_in_count._dirty = false;
            _f_current_sign_in_at._dirty = false;
            _f_last_sign_in_at._dirty = false;
            _f_current_sign_in_ip._dirty = false;
            _f_last_sign_in_ip._dirty = false;
            _f_job_title._dirty = false;
            _f_phone._dirty = false;
            _f_skype_name._dirty = false;
            _f_twitter_name._dirty = false;
            _f_active._dirty = false;
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
        if (_f_login._dirty)
            field2Val["login"] = 
                toSQLString(_f_login._base);
        if (_f_email._dirty)
            field2Val["email"] = 
                toSQLString(_f_email._base);
        if (_f_name._dirty)
            field2Val["name"] = 
                toSQLString(_f_name._base);
        if (_f_current_account._dirty)
            field2Val["current_account"] = 
                toSQLString(_f_current_account._base);
        if (_f_account_limit._dirty)
            field2Val["account_limit"] = 
                toSQLString(_f_account_limit._base);
        if (_f_pagination_rows._dirty)
            field2Val["pagination_rows"] = 
                toSQLString(_f_pagination_rows._base);
        if (_f_is_admin._dirty)
            field2Val["is_admin"] = 
                toSQLString(_f_is_admin._base);
        if (_f_created_at._dirty)
            field2Val["created_at"] = 
                toSQLString(_f_created_at._base);
        if (_f_updated_at._dirty)
            field2Val["updated_at"] = 
                toSQLString(_f_updated_at._base);
        if (_f_crypted_password._dirty)
            field2Val["crypted_password"] = 
                toSQLString(_f_crypted_password._base);
        if (_f_salt._dirty)
            field2Val["salt"] = 
                toSQLString(_f_salt._base);
        if (_f_tech_writer._dirty)
            field2Val["tech_writer"] = 
                toSQLString(_f_tech_writer._base);
        if (_f_pages_per_account._dirty)
            field2Val["pages_per_account"] = 
                toSQLString(_f_pages_per_account._base);
        if (_f_user_type._dirty)
            field2Val["user_type"] = 
                toSQLString(_f_user_type._base);
        if (_f_counter_total_actions._dirty)
            field2Val["counter_total_actions"] = 
                toSQLString(_f_counter_total_actions._base);
        if (_f_counter_actions_week._dirty)
            field2Val["counter_actions_week"] = 
                toSQLString(_f_counter_actions_week._base);
        if (_f_counter_actions_four_week._dirty)
            field2Val["counter_actions_four_week"] = 
                toSQLString(_f_counter_actions_four_week._base);
        if (_f_api_key._dirty)
            field2Val["api_key"] = 
                toSQLString(_f_api_key._base);
        if (_f_api_enabled._dirty)
            field2Val["api_enabled"] = 
                toSQLString(_f_api_enabled._base);
        if (_f_organization_admin._dirty)
            field2Val["organization_admin"] = 
                toSQLString(_f_organization_admin._base);
        if (_f_organization_id._dirty)
            field2Val["organization_id"] = 
                toSQLString(_f_organization_id._base);
        if (_f_surname._dirty)
            field2Val["surname"] = 
                toSQLString(_f_surname._base);
        if (_f_encrypted_password._dirty)
            field2Val["encrypted_password"] = 
                toSQLString(_f_encrypted_password._base);
        if (_f_reset_password_token._dirty)
            field2Val["reset_password_token"] = 
                toSQLString(_f_reset_password_token._base);
        if (_f_reset_password_sent_at._dirty)
            field2Val["reset_password_sent_at"] = 
                toSQLString(_f_reset_password_sent_at._base);
        if (_f_remember_created_at._dirty)
            field2Val["remember_created_at"] = 
                toSQLString(_f_remember_created_at._base);
        if (_f_sign_in_count._dirty)
            field2Val["sign_in_count"] = 
                toSQLString(_f_sign_in_count._base);
        if (_f_current_sign_in_at._dirty)
            field2Val["current_sign_in_at"] = 
                toSQLString(_f_current_sign_in_at._base);
        if (_f_last_sign_in_at._dirty)
            field2Val["last_sign_in_at"] = 
                toSQLString(_f_last_sign_in_at._base);
        if (_f_current_sign_in_ip._dirty)
            field2Val["current_sign_in_ip"] = 
                toSQLString(_f_current_sign_in_ip._base);
        if (_f_last_sign_in_ip._dirty)
            field2Val["last_sign_in_ip"] = 
                toSQLString(_f_last_sign_in_ip._base);
        if (_f_job_title._dirty)
            field2Val["job_title"] = 
                toSQLString(_f_job_title._base);
        if (_f_phone._dirty)
            field2Val["phone"] = 
                toSQLString(_f_phone._base);
        if (_f_skype_name._dirty)
            field2Val["skype_name"] = 
                toSQLString(_f_skype_name._base);
        if (_f_twitter_name._dirty)
            field2Val["twitter_name"] = 
                toSQLString(_f_twitter_name._base);
        if (_f_active._dirty)
            field2Val["active"] = 
                toSQLString(_f_active._base);
        
        if (DBFace::instance()->
                insert("users", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_login._dirty = false;
            _f_email._dirty = false;
            _f_name._dirty = false;
            _f_current_account._dirty = false;
            _f_account_limit._dirty = false;
            _f_pagination_rows._dirty = false;
            _f_is_admin._dirty = false;
            _f_created_at._dirty = false;
            _f_updated_at._dirty = false;
            _f_crypted_password._dirty = false;
            _f_salt._dirty = false;
            _f_tech_writer._dirty = false;
            _f_pages_per_account._dirty = false;
            _f_user_type._dirty = false;
            _f_counter_total_actions._dirty = false;
            _f_counter_actions_week._dirty = false;
            _f_counter_actions_four_week._dirty = false;
            _f_api_key._dirty = false;
            _f_api_enabled._dirty = false;
            _f_organization_admin._dirty = false;
            _f_organization_id._dirty = false;
            _f_surname._dirty = false;
            _f_encrypted_password._dirty = false;
            _f_reset_password_token._dirty = false;
            _f_reset_password_sent_at._dirty = false;
            _f_remember_created_at._dirty = false;
            _f_sign_in_count._dirty = false;
            _f_current_sign_in_at._dirty = false;
            _f_last_sign_in_at._dirty = false;
            _f_current_sign_in_ip._dirty = false;
            _f_last_sign_in_ip._dirty = false;
            _f_job_title._dirty = false;
            _f_phone._dirty = false;
            _f_skype_name._dirty = false;
            _f_twitter_name._dirty = false;
            _f_active._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_User> _f_id;
    F_String _f_login;
    F_String _f_email;
    F_String _f_name;
    F_Integer _f_current_account;
    F_Integer _f_account_limit;
    F_Integer _f_pagination_rows;
    F_Integer _f_is_admin;
    F_Datetime _f_created_at;
    F_Datetime _f_updated_at;
    F_String _f_crypted_password;
    F_String _f_salt;
    F_Integer _f_tech_writer;
    F_Integer _f_pages_per_account;
    F_Integer _f_user_type;
    F_Integer _f_counter_total_actions;
    F_Integer _f_counter_actions_week;
    F_Integer _f_counter_actions_four_week;
    F_String _f_api_key;
    F_Boolean _f_api_enabled;
    F_Boolean _f_organization_admin;
    Field<I_organization_id> _f_organization_id;
    F_String _f_surname;
    F_String _f_encrypted_password;
    F_String _f_reset_password_token;
    F_Datetime _f_reset_password_sent_at;
    F_Datetime _f_remember_created_at;
    F_Integer _f_sign_in_count;
    F_Datetime _f_current_sign_in_at;
    F_Datetime _f_last_sign_in_at;
    F_String _f_current_sign_in_ip;
    F_String _f_last_sign_in_ip;
    F_String _f_job_title;
    F_String _f_phone;
    F_String _f_skype_name;
    F_String _f_twitter_name;
    F_Boolean _f_active;

    friend class T_User;
};

} //namespace DMMM
#endif //O_USER
