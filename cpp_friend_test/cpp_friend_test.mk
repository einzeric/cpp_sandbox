##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cpp_friend_test
ConfigurationName      :=Debug
WorkspacePath          :=D:/coding_project/cpp_sandbox
ProjectPath            :=D:/coding_project/cpp_sandbox/cpp_friend_test
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=MSI
Date                   :=12/08/2021
CodeLitePath           :="D:/Program Files/coding/CodeLite"
LinkerName             :=D:/toolshed/msys2/mingw64/bin/g++.exe
SharedObjectLinkerName :=D:/toolshed/msys2/mingw64/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="cpp_friend_test.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/toolshed/msys2/mingw64/bin/windres.exe
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
AR       := D:/toolshed/msys2/mingw64/bin/ar.exe rcu
CXX      := D:/toolshed/msys2/mingw64/bin/g++.exe
CC       := D:/toolshed/msys2/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/toolshed/msys2/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\coding\CodeLite
Objects0=$(IntermediateDirectory)/ClassA.cpp$(ObjectSuffix) $(IntermediateDirectory)/ClassB.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ClassA.cpp$(ObjectSuffix): ClassA.cpp $(IntermediateDirectory)/ClassA.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/coding_project/cpp_sandbox/cpp_friend_test/ClassA.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ClassA.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ClassA.cpp$(DependSuffix): ClassA.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ClassA.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ClassA.cpp$(DependSuffix) -MM ClassA.cpp

$(IntermediateDirectory)/ClassA.cpp$(PreprocessSuffix): ClassA.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ClassA.cpp$(PreprocessSuffix) ClassA.cpp

$(IntermediateDirectory)/ClassB.cpp$(ObjectSuffix): ClassB.cpp $(IntermediateDirectory)/ClassB.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/coding_project/cpp_sandbox/cpp_friend_test/ClassB.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ClassB.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ClassB.cpp$(DependSuffix): ClassB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ClassB.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ClassB.cpp$(DependSuffix) -MM ClassB.cpp

$(IntermediateDirectory)/ClassB.cpp$(PreprocessSuffix): ClassB.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ClassB.cpp$(PreprocessSuffix) ClassB.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/coding_project/cpp_sandbox/cpp_friend_test/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


