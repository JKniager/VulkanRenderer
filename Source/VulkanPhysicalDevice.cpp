#include <VulkanPhysicalDevice.h>

#include <vector>
#include <cstdlib>

void* VulkanPhysicalDevice::getStructureFromChain(VkStructureType sType)
{
    if (sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR)
    {
        return this->property_chain;
    }

    for (VkStructureHeader* n = static_cast<VkStructureHeader*>(this->property_chain->pNext); n != nullptr; n = static_cast<VkStructureHeader*>(n->pNext))
    {
        if (sType == n->sType)
        {
            return n;
        }
    }

    return nullptr;
}

VulkanPhysicalDevice::~VulkanPhysicalDevice()
{
    void* last_n = this->property_chain;
    for (VkStructureHeader* n = static_cast<VkStructureHeader*>(this->property_chain->pNext); n != nullptr; n = static_cast<VkStructureHeader*>(n->pNext))
    {
        free(last_n);
        last_n = n;
    }

    free(last_n);
}
