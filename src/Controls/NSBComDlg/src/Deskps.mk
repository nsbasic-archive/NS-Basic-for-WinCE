
Deskps.dll: dlldata.obj Desk_p.obj Desk_i.obj
	link /dll /out:Deskps.dll /def:Deskps.def /entry:DllMain dlldata.obj Desk_p.obj Desk_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Deskps.dll
	@del Deskps.lib
	@del Deskps.exp
	@del dlldata.obj
	@del Desk_p.obj
	@del Desk_i.obj
