//
// File.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once

#ifndef _File_h_
#define _File_h_
#include "object_parser.h"

#include <fstream>
#include <vector>

namespace engine {
	class File {
	public:
		File(const char* file_name) : file_name_(file_name) {}
		File(const File&) = delete;
		File(File&& other) {
			if (this != &other) {
				if (file_name_) file_name_ = nullptr;
				file_name_ = other.file_name_;
				other.file_name_ = nullptr;
			}
		}
		
		File& operator=(const File&) = delete;
		File& operator=(File&& other) {
			if (this != &other) {
				if (file_name_) file_name_ = nullptr;
				file_name_ = other.file_name_;
				other.file_name_ = nullptr;
			}
			return *this;
		}

		
		std::vector<std::shared_ptr<engine::Object>> Load();
		void Save(std::vector<std::shared_ptr<engine::Object>> objects);
	private:
		const char* file_name_;
	};
}

#endif