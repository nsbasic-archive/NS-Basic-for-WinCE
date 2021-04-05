#include <TPoolLibrary/safearrayhelper.h>

// Type of the array alements
template <class T>
class ccSafeArray {
public:
    SAFEARRAY*  psa;

    ccSafeArray();
    ccSafeArray(SAFEARRAY* psaInit);
    ccSafeArray(ccSafeArray& sa);
    ~ccSafeArray();

    HRESULT __cdecl Create(unsigned int cDims,...);     // Dimensions and UINT cElements for each dimension
    HRESULT __cdecl Create2(unsigned int cDims,...);    // Dimensions and LONG LBound, LONG UBound pairs



};

