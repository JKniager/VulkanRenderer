#ifndef VULKANRENDERERRORHANDLING_H
#define VULKANRENDERERRORHANDLING_H

#include <vulkan/vulkan.h>

#include <exception>
#include <string>
#include <sstream>

void throwError(std::string msg, VkResult err_code = VK_SUCCESS);

#endif // VULKANRENDERERRORHANDLING_H
