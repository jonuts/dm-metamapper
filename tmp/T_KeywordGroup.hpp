
#ifndef T_KEYWORDGROUP
#define T_KEYWORDGROUP
#include "O_KeywordGroup.hpp"

namespace DMMM {

class T_KeywordGroup{
public:

    struct Condition{
        bool nil() const { return _cond.size() == 0; }
        std::string _cond;
    };

    T_KeywordGroup() 
    {
        _tables.push_back("keyword_groups");
    }
    T_KeywordGroup(const Condition& c) 
        : _constraint(c)
    {
        _tables.push_back("keyword_groups");
    }

    
    struct E_id{
        E_id() 
        {  
            _field = "keyword_groups.id";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef Field<I_KeywordGroup>::Base ComparerType;
    };

    static E_id _id(){ 
        return E_id();
    }
    struct E_name{
        E_name() 
        {  
            _field = "keyword_groups.name";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_name _name(){ 
        return E_name();
    }
    struct E_account_id{
        E_account_id() 
        {  
            _field = "keyword_groups.account_id";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_Integer::Base ComparerType;
    };

    static E_account_id _account_id(){ 
        return E_account_id();
    }
    struct E_created_at{
        E_created_at() 
        {  
            _field = "keyword_groups.created_at";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_created_at _created_at(){ 
        return E_created_at();
    }
    struct E_updated_at{
        E_updated_at() 
        {  
            _field = "keyword_groups.updated_at";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_Datetime::Base ComparerType;
    };

    static E_updated_at _updated_at(){ 
        return E_updated_at();
    }
    struct E_csv_file{
        E_csv_file() 
        {  
            _field = "keyword_groups.csv_file";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_String::Base ComparerType;
    };

    static E_csv_file _csv_file(){ 
        return E_csv_file();
    }
    struct E_from_file{
        E_from_file() 
        {  
            _field = "keyword_groups.from_file";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_Boolean::Base ComparerType;
    };

    static E_from_file _from_file(){ 
        return E_from_file();
    }
    struct E_manual_list{
        E_manual_list() 
        {  
            _field = "keyword_groups.manual_list";
        }
        std::string _field;
        typedef T_KeywordGroup::Condition ConditionType;
        typedef F_Text::Base ComparerType;
    };

    static E_manual_list _manual_list(){ 
        return E_manual_list();
    }
    

    std::vector<std::string> getFields()
    {
        std::vector<std::string> ret;
        ret.clear();
        ret.push_back("id");
        ret.push_back("name");
        ret.push_back("account_id");
        ret.push_back("created_at");
        ret.push_back("updated_at");
        ret.push_back("csv_file");
        ret.push_back("from_file");
        ret.push_back("manual_list");
        return ret;
    }

    std::vector<O_KeywordGroup> 
    select(const Condition& c, const std::string& additional)
    {
        std::vector<O_KeywordGroup> ret;
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<std::string> fields = getFields();
        QueryRes res;
        DBFace::instance()->select(_tables, fields, c1._cond, 
                                   additional, res);
        ret.resize(res.size());
        for(size_t i = 0; i < res.size(); ++i){
            ret[i]._f_id._base =
                UTILS::fromString<Field<I_KeywordGroup>::Base>(res[i]["id"]);
            ret[i]._f_name._base =
                UTILS::fromString<F_String::Base>(res[i]["name"]);
            ret[i]._f_account_id._base =
                UTILS::fromString<F_Integer::Base>(res[i]["account_id"]);
            ret[i]._f_created_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["created_at"]);
            ret[i]._f_updated_at._base =
                UTILS::fromString<F_Datetime::Base>(res[i]["updated_at"]);
            ret[i]._f_csv_file._base =
                UTILS::fromString<F_String::Base>(res[i]["csv_file"]);
            ret[i]._f_from_file._base =
                UTILS::fromString<F_Boolean::Base>(res[i]["from_file"]);
            ret[i]._f_manual_list._base =
                UTILS::fromString<F_Text::Base>(res[i]["manual_list"]);
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


    std::vector<O_KeywordGroup> select(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        return select(c1, "");
    }

    std::vector<O_KeywordGroup> 
    select(const std::string& additional)
    {
        return select(_constraint, additional);
    }

    std::vector<O_KeywordGroup> select()
    {
        return select(_constraint, "");
    }

    std::pair<O_KeywordGroup, bool> select(const I_KeywordGroup& id){
        return first(E_id() == id);
    }

    std::pair<O_KeywordGroup, bool> first(const Condition& c)
    {
        Condition c1 = _constraint.nil() ? c : _constraint && c;
        std::vector<O_KeywordGroup> r = select(c, "limit 1");
        if(r.size() > 0)
            return std::make_pair(r[0], true);
        else
            return std::make_pair(O_KeywordGroup(), false);
    }

    std::pair<O_KeywordGroup, bool> first(){
        return first(_constraint);
    }

    bool insertAllFields(std::vector<O_KeywordGroup>::const_iterator begin,
                         std::vector<O_KeywordGroup>::const_iterator end)
    {
	std::vector<std::string> fields;
                
        fields.push_back(std::string("name"));
        
        fields.push_back(std::string("account_id"));
        
        fields.push_back(std::string("created_at"));
        
        fields.push_back(std::string("updated_at"));
        
        fields.push_back(std::string("csv_file"));
        
        fields.push_back(std::string("from_file"));
        
        fields.push_back(std::string("manual_list"));
	std::vector<std::vector<std::string> > rows;
	for (; begin != end; ++begin){
	    const O_KeywordGroup& r = *begin;
	    std::vector<std::string> row;
                        
            row.push_back(toSQLString(r._name()));
            
            row.push_back(toSQLString(r._account_id()));
            
            row.push_back(toSQLString(r._created_at()));
            
            row.push_back(toSQLString(r._updated_at()));
            
            row.push_back(toSQLString(r._csv_file()));
            
            row.push_back(toSQLString(r._from_file()));
            
            row.push_back(toSQLString(r._manual_list()));
	    rows.push_back(row);
	}
        return DBFace::instance()->insert("keyword_groups",
					  fields, rows);
    }

    bool insertDirtyFields(std::vector<O_KeywordGroup>::const_iterator begin,
                           std::vector<O_KeywordGroup>::const_iterator end)
    {
        if (begin == end)
            return true;
        FieldsToRows fields2Rows;
	for (std::vector<O_KeywordGroup>::const_iterator it = begin; 
             it != end; ++it)
        {
            std::vector<std::string> fields;
            std::vector<std::string> row;
                        
            if (it->_f_name._dirty){
                fields.push_back(std::string("name"));
                row.push_back(toSQLString(it->_name()));
            }
            
            if (it->_f_account_id._dirty){
                fields.push_back(std::string("account_id"));
                row.push_back(toSQLString(it->_account_id()));
            }
            
            if (it->_f_created_at._dirty){
                fields.push_back(std::string("created_at"));
                row.push_back(toSQLString(it->_created_at()));
            }
            
            if (it->_f_updated_at._dirty){
                fields.push_back(std::string("updated_at"));
                row.push_back(toSQLString(it->_updated_at()));
            }
            
            if (it->_f_csv_file._dirty){
                fields.push_back(std::string("csv_file"));
                row.push_back(toSQLString(it->_csv_file()));
            }
            
            if (it->_f_from_file._dirty){
                fields.push_back(std::string("from_file"));
                row.push_back(toSQLString(it->_from_file()));
            }
            
            if (it->_f_manual_list._dirty){
                fields.push_back(std::string("manual_list"));
                row.push_back(toSQLString(it->_manual_list()));
            }
            fields2Rows[fields].push_back(row);
	}
        bool ret = true;
        for (FieldsToRows::const_iterator it = fields2Rows.begin();
             it != fields2Rows.end(); ++it)
        {
            ret = DBFace::instance()->insert("keyword_groups",
                                             it->first, it->second) && ret;
        }
        return ret;
    }


    Condition                 _constraint;    
    std::vector<std::string>  _tables;
};

} //namespace DMMM
#endif //T_KEYWORDGROUP
