#ifndef VULKANPHYSICALDEVICE_H
#define VULKANPHYSICALDEVICE_H

#include <vulkan/vulkan.h>

typedef struct VkStructureHeader
{
    VkStructureType sType;
    void* pNext;
} VkStructureHeader;

class VulkanPhysicalDevice
{
public:
    VulkanPhysicalDevice(VkPhysicalDevice physical_device, VkPhysicalDeviceProperties2KHR* property_chain) : physical_device(physical_device), property_chain(property_chain) {}
    void* getStructureFromChain(VkStructureType sType);
    ~VulkanPhysicalDevice();

private:
    VkPhysicalDevice physical_device = VK_NULL_HANDLE;
    VkPhysicalDeviceProperties2KHR* property_chain = nullptr;
};

#endif //VULKANPHYSICALDEVICE_H
