#pragma once
#include "dylib.hpp"
#include <Windows.h>
#include <iostream>
using namespace std;

dylib GetNTDLL() {
	dylib lib_ntdll("C:\\Windows\\System32", "ntdll");
	return lib_ntdll;
}