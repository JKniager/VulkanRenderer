#include <VulkanRenderer.h>

VulkanRenderer::VulkanRenderer(const char* application_name, uint32_t application_version)
{
    VkApplicationInfo app_info = {};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pNext = nullptr;
    app_info.pApplicationName = application_name;
    app_info.applicationVersion = application_version;
    app_info.pEngineName = "Vulkan Renderer";
    app_info.engineVersion = VK_MAKE_VERSION(0,1,0);
    app_info.apiVersion = VK_API_VERSION_1_1;
    
    CreateInstance(&app_info);
}

void VulkanRenderer::CreateInstance(VkApplicationInfo* app_info)
{
    this->inst = new VulkanInstance(nullptr, app_info);
}
