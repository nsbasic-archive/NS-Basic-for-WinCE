#ifndef _DYNDISPIMPL_H_
#define _DYNDISPIMPL_H_

// Required includes
//#include 

template <class T>
class ccDynamicDispImpl: 
    public IDispatch
{
    public:
        /*
        virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID* ppvObj) {
            T*  pThis = (T*)this;
            return pThis->QueryInterface(REFIID riid, LPVOID* ppvObj);
        }
        virtual ULONG STDMETHODCALLTYPE AddRef() {
            return T::QueryInterface(REFIID riid, LPVOID* ppvObj);
        }
        */
        virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, DISPID* rgDispIg) {

        }
};


#endif // _DYNDISPIMPL_H_