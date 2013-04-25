
#ifndef T_DRIVEBACKLOG
#define T_DRIVEBACKLOG
#include "O_DriveBackLog.hpp"

namespace DMMM {

class T_DriveBackLog{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_DriveBackLog() 
    {
        _tables.push_back("drive_back_logs");
    }
    T_DriveBackLog(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("drive_back_logs");
    }

    
    
    struct E_id{
        E_id() 
        {  
            _field = "drive_back_logs.id";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef Field<I_DriveBackLog>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_start{
        E_start() 
        {  
            _field = "drive_back_logs.start";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_start _start(){ 
        return E_start();
    }
    struct E_end{
        E_end() 
        {  
            _field = "drive_back_logs.end";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_end _end(){ 
        return E_end();
    }
    struct E_command{
        E_command() 
        {  
            _field = "drive_back_logs.command";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_command _command(){ 
        return E_command();
    }
    struct E_model_id{
        E_model_id() 
        {  
            _field = "drive_back_logs.model_id";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_model_id _model_id(){ 
        return E_model_id();
    }
    struct E_param{
        E_param() 
        {  
            _field = "drive_back_logs.param";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_param _param(){ 
        return E_param();
    }
    struct E_log_file_name{
        E_log_file_name() 
        {  
            _field = "drive_back_logs.log_file_name";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_log_file_name _log_file_name(){ 
        return E_log_file_name();
    }
    struct E_pid{
        E_pid() 
        {  
            _field = "drive_back_logs.pid";
        }
        std::string _field;
        typedef T_DriveBackLog::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_pid _pid(){ 
        return E_pid();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("start");
        ret.push_back("end");
        ret.push_back("command");
        ret.push_back("model_id");
        ret.push_back("param");
        ret.push_back("log_file_name");
        ret.push_back("pid");
        return ret;
    }

    std::vector<O_DriveBackLog> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_DriveBackLog> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_DriveBackLog>::Base>(res[i]["id"]);
            ret[i]._f_start._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["start"]);
            ret[i]._f_end._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["end"]);
            ret[i]._f_command._base =
                UTILS::fromString<F_String::Base>(res[i]["command"]);
            ret[i]._f_model_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["model_id"]);
            ret[i]._f_param._base =
                UTILS::fromString<F_String::Base>(res[i]["param"]);
            ret[i]._f_log_file_name._base =
                UTILS::fromString<F_String::Base>(res[i]["log_file_name"]);
            ret[i]._f_pid._base =
                UTILS::fromString<F_Integer::Base>(res[i]["pid"]);
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


    std::vector<O_DriveBackLog> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_DriveBackLog> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_DriveBackLog> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_DriveBackLog, bool> select(const I_DriveBackLog& id){
        return first(E_id() == id);
    }

    std::pair<O_DriveBackLog, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_DriveBackLog> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_DriveBackLog(), false);
    }

    std::pair<O_DriveBackLog, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_DriveBackLog>::const_iterator begin,
                         std::vector<O_DriveBackLog>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("start"));
        
        fields.push_back(std::string("end"));
        
        fields.push_back(std::string("command"));
        
        fields.push_back(std::string("model_id"));
        
        fields.push_back(std::string("param"));
        
        fields.push_back(std::string("log_file_name"));
        
        fields.push_back(std::string("pid"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_DriveBackLog& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._start()));
            
            row.push_back(toSQLString(r._end()));
            
            row.push_back(toSQLString(r._command()));
            
            row.push_back(toSQLString(r._model_id()));
            
            row.push_back(toSQLString(r._param()));
            
            row.push_back(toSQLString(r._log_file_name()));
            
            row.push_back(toSQLString(r._pid()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("drive_back_logs",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_DriveBackLog>::const_iterator begin,
                           std::vector<O_DriveBackLog>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_DriveBackLog>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_start._dirty){
                fields.push_back(std::string("start"));
                row.push_back(toSQLString(it->_start()));
            }
            
            if (it->_f_end._dirty){
                fields.push_back(std::string("end"));
                row.push_back(toSQLString(it->_end()));
            }
            
            if (it->_f_command._dirty){
                fields.push_back(std::string("command"));
                row.push_back(toSQLString(it->_command()));
            }
            
            if (it->_f_model_id._dirty){
                fields.push_back(std::string("model_id"));
                row.push_back(toSQLString(it->_model_id()));
            }
            
            if (it->_f_param._dirty){
                fields.push_back(std::string("param"));
                row.push_back(toSQLString(it->_param()));
            }
            
            if (it->_f_log_file_name._dirty){
                fields.push_back(std::string("log_file_name"));
                row.push_back(toSQLString(it->_log_file_name()));
            }
            
            if (it->_f_pid._dirty){
                fields.push_back(std::string("pid"));
                row.push_back(toSQLString(it->_pid()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("drive_back_logs",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_DRIVEBACKLOG
