Let's begin with an example:

class CMyClass: public ccRegKeyBinder<CMyClass,true,true> {
    DWORD   m_dwQueueSize;
    DWORD   m_dwErrorAfinity;
    public:
    
    // Binding map
    BEGIN_REGBIND_MAP2(HKLM_CURRENT_USER,_TEXT("SOFTWARE\\MyComany\\MyProduct"))
        REGBIND_ENTRY_DWORD2(_TEXT("QueueSize"),m_dwQueueSize,64)
        REGBIND_ENTRY_DWORD2(_TEXT("ErrorAfinity"),m_dwErrorAfinity,2)
    END_REGBIND_MAP()
    
    // Your members ...
};

Using that code CMyClass memebrs specified in the map will be initialized
automatically from the registry. If the registry settings are not found 
then default values will be used instead. At the end during destruction 
members will be saved back.

Well this example is not appropriate if many instances of the class will 
try to load/save settings in the same place. Instead non-static variables 
can be used in the bind map.

DESCRIPTION
===========

As seen above Registry binder is a template class that works with a macros 
defining the bindings. In the ccRegKey.h file two classes are defined:
 - ccRegKey Simple registry access class that can be used withot binder too
 - ccRegKeyBinder that uses the first class to implement the bindings
 
ccRegKeyBinder template arguments
---------------------------------

template <class T,bool bAuto = false,bool bAutoSave = false>
class _CC_CLASS_ATTRIBUTES ccRegKeyBinder

 - T is your class derived from the binder.
 - bAuto - auto read the values from the registry on class creation
 - bAutoSave - auto save the values to the registry on class destruction
 
The class must have REGBIND map defined in a public part of its definition. 
There are two map types:

 - BEGIN_REGBIND_MAP() - without arguments
 - BEGIN_REGBIND_MAP2(hkBRanch,szPath) - with arguments specifying the 
    location. Arguments can be class members (access rights are not 
    important).
    
Comments: First form is not useful in case of enabled auto read or auto save.
It is useful only if you are going to initiate the read/write registry 
operations using the ccRegKeyBinder class members:

 - bool RestoreRegistryValues(HKEY hkRoot = NULL,LPCTSTR szKey = NULL)
 - bool StoreRegistryValues(HKEY hkRoot = NULL,LPCTSTR szKey = NULL)
 
 In the both members parameters are:
 1 - HKEY of a registry branch or a parent key hanlde
 2 - string containing registry key path
 
In case of map without arguments you must not rely on the default arguments.
If not supplied - operation will fail returning false. If you are using
BEGIN_REGBIND_MAP2 macro you can call them without arguments and variables
(constat or not constant) specified in the macro will be used.

IMPORTANT: Class does not use locks itself. If you need specific locking you 
will need to not enable the auto read/write ability and call above members 
within block that is guarded using some synchronization method for example
critical section.

All other macros have two forms without and with default values. They must
appear between BEGIN_REGBIND_MAP macro and END_REGBIND_MAP() macro. Bindable 
types are: DWORD, string and CLSID:

 - REGBIND_ENTRY_DWORD(registry_value_name,member_variable_name)
 - REGBIND_ENTRY_DWORD2(registry_value_name,member_variable_name,default_value)

Binds a DWORD member variable. As in the all other macros registry_value_name
can be another member variable or global variable/constant.

 - REGBIND_ENTRY_STRING(registry_value_name,member_variable_name,buff_size)
 - REGBIND_ENTRY_STRING2(registry_value_name,member_variable_name,buff_size,default_value)
 
Binds a string member variable defined for example as TCHAR m_varname[buff_size].
Here the buff_size is important - it must match the defined size.

 - REGBIND_ENTRY_STRINGPTR(registry_value_name,member_variable_name)
 - REGBIND_ENTRY_STRINGPTR2(registry_value_name,member_variable_name,default_value)
 
This is more flexible than the previous macro but can be danger if not used with
care. Member variable must be of LPTSTR type. Macro defines code that allocates 
memory as needed using the global new operator. In case of auto read buffer will be
allocated but if auto write is not enabled buffer will not be freed! If you are
using the class without autowrite you will need to include in the destructor code
that deletes the buffer (delete [] m_myvariable;). If auto read is not used you will
need to init the string pointer to null in the class constructor manually in order to 
prevent wrong attempts of the macro generated code to delete it. If you afraid of this
use this macro inly in case of auto save/read enabled both.

 - REGBIND_ENTRY_CLSID(registry_value_name,member_variable_name)
 - REGBIND_ENTRY_CLSID2(registry_value_name,member_variable_name,default_clsid)
 
These macros expect string representation of the CLSID in the registry in {...} 
form. 

NOTES: Default values for the first forms of the macros (without default_value parameter)
are 0 for DWORD, empty string for strings and CLSID_NULL for CLSID.


Michael Elfial
newObjects 2001