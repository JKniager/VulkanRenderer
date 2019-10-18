#include <VulkanInstance.h>
#include <VulkanRenderErrorHandling.h>

VulkanInstance::VulkanInstance(const void* pNext, VkApplicationInfo* pAppInfo, uint32_t enabledLayerCount, const char* const* ppEnabledLayerNames, uint32_t enabledExtensionCount, const char* const* ppEnabledExtensionNames)
{
    VkInstanceCreateInfo vk_inst = {};
    vk_inst.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    vk_inst.pNext = pNext;
    vk_inst.flags = 0;
    vk_inst.pApplicationInfo = pAppInfo;
    vk_inst.enabledLayerCount = enabledLayerCount;
    vk_inst.ppEnabledLayerNames = ppEnabledLayerNames;
    vk_inst.enabledExtensionCount = enabledExtensionCount;
    vk_inst.ppEnabledExtensionNames = ppEnabledExtensionNames;

    this->last_err = vkCreateInstance(&vk_inst, nullptr, &this->inst);
    if (this->last_err != VK_SUCCESS)
    {
        throwError("Failed to create VkInstance!", this->last_err);
    }
}

bool  checkInstanceLayersAvailable(std::vector<char *>& layer_names, std::vector<char *>& missing_layers)
{
    bool all_layers_found = true;
    uint32_t layer_count = 0;
    vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
    std::vector<VkLayerProperties> layer_props(layer_count);
    vkEnumerateInstanceLayerProperties(&layer_count, layer_props.data());

    for (char* ln : layer_names)
    {
        bool layer_found = false;
        for (VkLayerProperties& lp : layer_props)
        {
            if (strncmp(lp.layerName, ln, VK_MAX_EXTENSION_NAME_SIZE) == 0)
            {
                layer_found = true;
                break;
            }
        }
        if (!layer_found)
        {
            all_layers_found = false;
            missing_layers.push_back(ln);
        }
    }

    return all_layers_found;
}

bool checkInstanceExtensionsAvailable(std::vector<char *>& extension_names, std::vector<char *>& missing_extensions, const char* layer_name)
{
    bool all_extensions_found = true;
    uint32_t extension_count = 0;
    vkEnumerateInstanceExtensionProperties(layer_name, &extension_count, nullptr);
    std::vector<VkExtensionProperties> extension_props(extension_count);
    vkEnumerateInstanceExtensionProperties(layer_name, &extension_count, extension_props.data());

    for (char* en : extension_names)
    {
        bool extension_found = false;
        for (VkExtensionProperties& ep : extension_props)
        {
            if (strncmp(ep.extensionName, en, VK_MAX_EXTENSION_NAME_SIZE) == 0)
            {
                extension_found = true;
                break;
            }
        }
        if (!extension_found)
        {
            all_extensions_found = false;
            missing_extensions.push_back(en);
        }
    }

    return all_extensions_found;
}
