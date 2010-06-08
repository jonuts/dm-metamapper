#include <vector>
#include "dmmm_dbface.h"
#include "T_User.hpp"
#include "T_Dog.hpp"
#include "T_LittleFlea.hpp"

using namespace std;
using namespace DMMM;

int main(int argc, char* argv[])
{
    string host("localhost");
    string user("root");
    string database("dmmm");
    string password("");
    DBFace dbFace(database, host, user, password);

    T_Dog d;
    T_User u;
    d.erase();
    u.erase();

    O_User u1;
    u1._name() = "omer";
    u1._balance() = 5.3;
    u1._weight() = 10;
    u1.insert();
    
    O_Dog d1;
    d1._user_id() = u1._id();
    d1._name() = "spot";
    d1._stinks() = true;
    d1.insert();

    d1 = d.select(d1._id()).first;

    O_Dog d2(u1);
    d2._name() = "rover";
    d2._stinks() = false;
    d2.insert();

    O_User u2;
    u2._name() = "jonah";
    u2.insert();

    O_Dog d3(u2._id());
    d3._name() = "rover";
    d3._stinks() = false;
    d3.insert();

    O_LittleFlea f1(d3);
    f1.insert();
    
    vector<O_Dog> dogs;
    d.select((d._stinks() == false) && (d._name() %= "\%over"), dogs);
    for(size_t i = 0; i < dogs.size(); ++i){
	dogs[i]._name() = string("good_") + dogs[i]._name();
	dogs[i].update();
	cout << dogs[i]._name() 
	     << " belongs to " << dogs[i].user().first._name() 
	     << endl;
    }


    T_User uconst(u._name() == "omer");
    T_Dog dconst(uconst);
    dogs.clear();
    dconst.select(d._stinks() == true, dogs);
    cout << dogs.size() << " dogs meet criterion" << endl;
    dconst.erase();

    d.erase(d._user_id() == u2._id());

    return 0;
}
