#ifndef MEMORYEXCEPTION_H
#define MEMORYEXCEPTION_H

#include <exception>
#include <string>

class MemoryException : public std::exception {
	public:
		explicit MemoryException(const std::string& message)
			: msg_(message) {}

		const char* what() const noexcept override {
			return msg_.c_str();
		}
	private:
		std::string msg_; // 存储错误信息

};

#endif
