
ComCtlps.dll: dlldata.obj ComCtl_p.obj ComCtl_i.obj
	link /dll /out:ComCtlps.dll /def:ComCtlps.def /entry:DllMain dlldata.obj ComCtl_p.obj ComCtl_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ComCtlps.dll
	@del ComCtlps.lib
	@del ComCtlps.exp
	@del dlldata.obj
	@del ComCtl_p.obj
	@del ComCtl_i.obj
