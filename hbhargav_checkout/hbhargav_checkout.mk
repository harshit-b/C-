##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=hbhargav_checkout
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/hbhar/Documents/Documents
ProjectPath            :=C:/Users/hbhar/Documents/Documents/hbhargav_checkout
IntermediateDirectory  :=../build-$(ConfigurationName)/hbhargav_checkout
OutDir                 :=../build-$(ConfigurationName)/hbhargav_checkout
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=hbhar
Date                   :=04/10/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/hbhargav_checkout/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/hbhargav_checkout/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\hbhargav_checkout" mkdir "..\build-$(ConfigurationName)\hbhargav_checkout"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\hbhargav_checkout" mkdir "..\build-$(ConfigurationName)\hbhargav_checkout"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/hbhargav_checkout/.d:
	@if not exist "..\build-$(ConfigurationName)\hbhargav_checkout" mkdir "..\build-$(ConfigurationName)\hbhargav_checkout"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/hbhargav_checkout/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/hbhargav_checkout/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/hbhar/Documents/Documents/hbhargav_checkout/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/hbhargav_checkout/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/hbhargav_checkout/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/hbhargav_checkout/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/hbhargav_checkout/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/hbhargav_checkout/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/hbhargav_checkout//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


