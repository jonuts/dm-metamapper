#ifndef O_DRIVEBACKLOG
#define O_DRIVEBACKLOG

#include <map>
#include <string>
#include "dmmm_utils.hpp"
#include "dmmm_dbface.h"
#include "dmmm_identifiers.hpp"
#include "dmmm_fields.hpp"
#include "dmmm_comparators.hpp"



namespace DMMM {

class O_DriveBackLog{
public:

    O_DriveBackLog() {}

O_DriveBackLog(const I_DriveBackLog& id) 
        : _f_id(id)
        {}


    const Field<I_DriveBackLog>::Base& _id() const { 
        return _f_id._base; 
    }
    Field<I_DriveBackLog>::Base& _id() { 
        _f_id._dirty = true; 
        return _f_id._base; 
    }
    const F_Datetime::Base& _start() const { 
        return _f_start._base; 
    }
    F_Datetime::Base& _start() { 
        _f_start._dirty = true; 
        return _f_start._base; 
    }
    const F_Datetime::Base& _end() const { 
        return _f_end._base; 
    }
    F_Datetime::Base& _end() { 
        _f_end._dirty = true; 
        return _f_end._base; 
    }
    const F_String::Base& _command() const { 
        return _f_command._base; 
    }
    F_String::Base& _command() { 
        _f_command._dirty = true; 
        return _f_command._base; 
    }
    const F_Integer::Base& _model_id() const { 
        return _f_model_id._base; 
    }
    F_Integer::Base& _model_id() { 
        _f_model_id._dirty = true; 
        return _f_model_id._base; 
    }
    const F_String::Base& _param() const { 
        return _f_param._base; 
    }
    F_String::Base& _param() { 
        _f_param._dirty = true; 
        return _f_param._base; 
    }
    const F_String::Base& _log_file_name() const { 
        return _f_log_file_name._base; 
    }
    F_String::Base& _log_file_name() { 
        _f_log_file_name._dirty = true; 
        return _f_log_file_name._base; 
    }
    const F_Integer::Base& _pid() const { 
        return _f_pid._base; 
    }
    F_Integer::Base& _pid() { 
        _f_pid._dirty = true; 
        return _f_pid._base; 
    }

    bool update(){
        std::map<std::string, std::string> field2Val;
        if (_f_id._dirty)
            field2Val["id"] = 
                toSQLString(_f_id._base);
        if (_f_start._dirty)
            field2Val["start"] = 
                toSQLString(_f_start._base);
        if (_f_end._dirty)
            field2Val["end"] = 
                toSQLString(_f_end._base);
        if (_f_command._dirty)
            field2Val["command"] = 
                toSQLString(_f_command._base);
        if (_f_model_id._dirty)
            field2Val["model_id"] = 
                toSQLString(_f_model_id._base);
        if (_f_param._dirty)
            field2Val["param"] = 
                toSQLString(_f_param._base);
        if (_f_log_file_name._dirty)
            field2Val["log_file_name"] = 
                toSQLString(_f_log_file_name._base);
        if (_f_pid._dirty)
            field2Val["pid"] = 
                toSQLString(_f_pid._base);
        std::string where =
            "id=" + toSQLString(_f_id._base);
        if (DBFace::instance()->update("drive_back_logs", 
                                       field2Val, where))
        {
            _f_id._dirty = false;
            _f_start._dirty = false;
            _f_end._dirty = false;
            _f_command._dirty = false;
            _f_model_id._dirty = false;
            _f_param._dirty = false;
            _f_log_file_name._dirty = false;
            _f_pid._dirty = false;
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
        if (_f_start._dirty)
            field2Val["start"] = 
                toSQLString(_f_start._base);
        if (_f_end._dirty)
            field2Val["end"] = 
                toSQLString(_f_end._base);
        if (_f_command._dirty)
            field2Val["command"] = 
                toSQLString(_f_command._base);
        if (_f_model_id._dirty)
            field2Val["model_id"] = 
                toSQLString(_f_model_id._base);
        if (_f_param._dirty)
            field2Val["param"] = 
                toSQLString(_f_param._base);
        if (_f_log_file_name._dirty)
            field2Val["log_file_name"] = 
                toSQLString(_f_log_file_name._base);
        if (_f_pid._dirty)
            field2Val["pid"] = 
                toSQLString(_f_pid._base);
        
        if (DBFace::instance()->
                insert("drive_back_logs", field2Val,
                       _f_id._base.serialization()))
        {
            _f_id._dirty = false;
            _f_start._dirty = false;
            _f_end._dirty = false;
            _f_command._dirty = false;
            _f_model_id._dirty = false;
            _f_param._dirty = false;
            _f_log_file_name._dirty = false;
            _f_pid._dirty = false;
            return true;
        }
        else
            return false;
                                   
    }
private:
    Field<I_DriveBackLog> _f_id;
    F_Datetime _f_start;
    F_Datetime _f_end;
    F_String _f_command;
    F_Integer _f_model_id;
    F_String _f_param;
    F_String _f_log_file_name;
    F_Integer _f_pid;

    friend class T_DriveBackLog;
};

} //namespace DMMM
#endif //O_DRIVEBACKLOG
