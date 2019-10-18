#ifndef VULKANINSTANCE_H
#define VULKANINSTANCE_H

#include <vulkan/vulkan.h>

#include <vector>
#include <cstring>

bool checkInstanceLayersAvailable(std::vector<char *>& layer_names, std::vector<char *>& missing_layers);
bool checkInstanceExtensionsAvailable(std::vector<char *>& extension_names, std::vector<char *>& missing_extensions, const char* layer_name = nullptr);

class VulkanInstance
{
    public:
        VulkanInstance(const void* pNext, VkApplicationInfo* pAppInfo, uint32_t enabledLayerCount = 0, const char* const* ppEnabledLayerNames = nullptr, uint32_t enabledExtensionCount = 0, const char* const* ppEnabledExtensionNames = nullptr);

        inline VkInstance getInstance() { return inst; }

        ~VulkanInstance()
        {
            vkDestroyInstance(inst, nullptr);
            inst = VK_NULL_HANDLE;
        }

    private:
        VkInstance inst = VK_NULL_HANDLE;
        VkResult last_err = VK_SUCCESS;
};

#endif // VULKANINSTANCE_H
