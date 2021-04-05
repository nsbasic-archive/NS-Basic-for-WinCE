

ccVariant::operator ccBSTR () {
    ccBSTR  bstr;
    if (IsOmitted()) return bstr;
    HRESULT hr = ChangeType(VT_BSTR);
    if (!FAILED(hr)) bstr = bstrVal;
    return bstr;
}