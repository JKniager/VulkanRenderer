#ifndef VULKANRENDERER_H
#define VULKANRENDERER_H

#include <VulkanRenderErrorHandling.h>
#include <VulkanInstance.h>

class VulkanRenderer
{
public:
    VulkanRenderer(const char* application_name, uint32_t application_version);

    void CreateInstance(VkApplicationInfo* app_info);
    uint32_t getInstanceVersion()
    {
        uint32_t version = 0;
        vkEnumerateInstanceVersion(&version);
        return version;
    };

    ~VulkanRenderer()
    {
        delete inst;
    }

private:
    VulkanInstance* inst = nullptr;
};

#endif //VULKANRENDERER_H
