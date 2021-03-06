#pragma once

#include <memory>
#include <string_view>
#include <vector>

class VirtualFilesystem {
public:
	VirtualFilesystem();
	~VirtualFilesystem();

	VirtualFilesystem(const VirtualFilesystem&) = delete;
	VirtualFilesystem(VirtualFilesystem&&) = delete;
	VirtualFilesystem& operator=(const VirtualFilesystem&) = delete;
	VirtualFilesystem& operator=(VirtualFilesystem&&) = delete;

	void MountFolder(std::string_view path, std::int64_t priority);

	struct FileInfo {
		void* Data{ nullptr };
		int _member_1{ 0 };
		int DataSize{ 0 };
		int AllocationSize{ 0 };
		int _member_4{ 0 };
	};
	FileInfo* LoadFile(const char* path, void* (*allocator)(std::size_t) = nullptr);

private:
	struct VfsMount;
	std::vector<VfsMount> mMounts;
};