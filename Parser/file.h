//
// File.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once

#ifndef _File_h_
#define _File_h_
#include "object_parser.h"

#include <fstream>
#include <vector>
namespace SDL {
	class File {
	public:
		File(const char* file_name) : file(std::fstream(file_name)) {}
		~File() {
			file.close();
		}
		
		std::vector<SDL::Object*> Load();
		//void Save(std::vector<SDL::Object*> objects);
	private:
		std::fstream file;
	};
}

#endif