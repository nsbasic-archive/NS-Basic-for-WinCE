Build notes
~~~~~~~~~~~

The CE2.11/CE3 vor EVC3, CE.NET 4.x project for EVC 4 and MSVC 6.0
 project are present in the same directory. They both work with the
same source files and they also share some intermediate files.

WARNING!!! Use "Rebuild All" first time you compile for certain 
platform! Do not compile for another platform until you are finished 
with it, because otherwise some intermediate files may remain from 
the other build and cause compile time and link time errors.

The official DLL outputs go into the BIN directory where 
subdirectories for the different platforms/processors are created.

The project files are:
VC6: Desk.dsp
EVC4: CE4.VCP
EVC3: EVC.VCP
The workspace files are:
VC6: Desk.dsw
EVC4: CE4.VCW
EVC3: EVC.VCW

Required C++ libraries
~~~~~~~~~~~~~~~~~~~~~~

The projects use:
1. Microsoft ATL3.0 or later
2. newObjects TPoolLibrary

1 is provided with MSVC and EVC. 2 is supplied with the sources in 
separate archive. If you want a newer version of the latter please 
contact me or check my WEB site. TPoolLibrary stands for Type Pool 
Library (I know it is a bit stupid name but ... well doesn't matter :)).
It is ATL compatible and even follows the same patterns as ATL. It 
can be used without ATL, but this does not concern this project.

To minimize the efforts use the TPoolLibrary this way:
Create a directory somewhere or use a directory already containing
your custom libraries. Unpack the TPoolLibrary archive there - it will
create a subdirectory named TPoolLibrary. In EVC/MSVC options add
include path pointing to the base directory. For example if the library
is here:
C:\myincludes\TPoolLibrary
Add
C:\myincludes
to the VC include paths - all the references in the sources are like 
this one:
#include <TPoolLibrary\xxxxxx.h>

Alternatively you can add it as additional include path in the project
to all the configurations.

If you add functionality to the project consider the TPoolLibrary
equivalents to the ATL packing classes. For example ccBSTR, ccEXCEPINFO,
ccVariant, ccSafeArray, ccBuffer etc. They offer a bit more convenient 
features than the ATL equivalents and some of them do not have such. 
Correct usage minimizes the error handling code drastically and offers 
convenient ways to avoid potentially dangerous memory allocation/
deallocation mistakes with much less effort.


TESTED platforms
~~~~~~~~~~~~~~~~

The source is designed to function only with native UNICODE support,
it will not compile nor work properly in multibyte (ANSI) builds.
All the project configurations are preserved in the project files (VC6)
in order to minimize the work if a need for multibyte version arises,
but it will need some changes in the code in order to buid correctly.

Desktop VC6.0: Use Unicode Release MinDependency or Unicode Debug.

CE EVC 4.0: Only the PPC 2003 targets are configured, but the source
will compile for any CE.NET target if you configure it (e.g. non-
PocketPC CE.NET targets). To do so install the corresponding SDK and
add configuration for the target. Make sure you include
ceshell.lib in the linker options.

CE EVC 3.0: A separate configuration is created for each platform.
The configurations are named this way:
<PLATFROM_NAME>_<PROCESSOR>_Release
For example the ARM Pocket PC configuration is named:
PPC_ARM_Release
When compiling make sure you use the correct configuration. Each is
configured to output the DLL in a directory under the BIN subdirectory.
For example PPC_ARM_Release outputs in BIN/PPC/ARM.
Again make sure ceshell.lib is in the list of additional libraries
passed to the linker.

You should not need to list the other libraries used by the project,
because the linker considers them default. However, if because of
some EVC configuration problem you receive linker errors stating
that some symbols are not resolved - check which API functions are
listed, find the corresponding library and add it to the linker input.

DEF file warinings. EVC3 and EVC4 will issue a few linker warnings 
like this one:

exported symbol 'DllCanUnloadNow' should not be assigned an ordinal

They are absolutely harmless and can be eliminated by creating
separate .def file for the CE projects. I decided that having these
warnings is more convenient than having separate .def file for the 
different platforms. So, just ignore them.

OUTPUTS
~~~~~~~

Note that EVC configuration by default uses configurations based
on the processor type and the same configuration is used for all the
device types! This means that if you compile for MS Smartphone the
output will replace any existing PPC 2003 DLL. At the time this
project was build there was no need of multiple binaries for all the
device types and no special configuration to the EVC project was done.
If you need to build for multiple device types I strongly recommend
to create new configurations - one for each device, name them properly
and define separate output locations for the linker. This may sound 
like a bit of excess work, but believe me it may save a lot of trouble
caused by messing the DLL-s for the different devices. After all, the
amount of different DLL may reach about 30 if all the CE versions and
processors are to be targetted!

CE5 and above support
~~~~~~~~~~~~~~~~~~~~~

No project for MSVS2005 is created, but the source should compile
without problems in it. Actually there is no need of such builds
unless some CE5 specific features are added to the project. The
DLL-s build for CE4 will work fine on CE5 with the added benefit
- support for all the WinCE versions from 4.0 with the same binary
files.

MS Smarthone
~~~~~~~~~~~~

The project will build for smartphone 2003 and later, but you can use 
the PPC2003 DLL as well. If you want to minimize the number of different 
binaries available for the users, you can provide the same DLL 
(PPC2003 version) for the both platforms.

Some minor features may not work as expected on MS Smartphone. For 
instance the Tray class will have no useful functionality on MS 
Smartphone 2003. However, the features in question are not typically
considered in MS Smartphone projects and no special attention is needed,
nor they will cause any harm if used - they will just do nothing.


April 2006
Michael Palazov - Elfial
michael@newobjects.com
