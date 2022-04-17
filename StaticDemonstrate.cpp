// Demonstrate the use of static variable and method in class

#include <iostream>
using namespace std;
class Tree {
    private: 
        // static member varibale, which is independent from Object
        // cannot initilized inside class
        //static int objectCount = 0;     // would not work
        static int objectCount;    
    public:      
        // increase static count
        Tree() {
            // of course we can not initilized static varibale here since it will repeated asign everytime class is called
            objectCount++;
        }
        // define function as static so that we can called without an object, but as class
        // <className>::<stat_Method>() instead of <objectName>.<staticMethod>()
        // both way will work. Refer to the calling in main function
        static int getObjectCount() {
            return objectCount;
        }
};

// initilized object outside of class definition. Format is: <returnType> <className>::<stat_varibale_name> = <value>;
int Tree::objectCount = 0;

int main()
{
    // can be called before we hava any object
    cout << "Init object count is: " << Tree::getObjectCount() << endl;
    Tree oak, elm, pine;
    
    //2 way to call staticMethod
    cout << "Object count is: " << Tree::getObjectCount() << endl;
    cout << "Object count is: " << elm.getObjectCount() << endl;
    return 0;
}
