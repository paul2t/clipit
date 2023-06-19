@echo off

IF NOT EXIST build mkdir build
pushd build

call cl -nologo -O2 ..\clipit.cpp

popd
