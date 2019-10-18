#include <cstdlib>
#include <iostream>

#include <VulkanRenderer.h>

int main()
{
    VulkanRenderer renderer("Test App", VK_MAKE_VERSION(0,1,0));

    std::cout << "Running Vulkan version " << renderer.getInstanceVersion() << std::endl;

    return EXIT_SUCCESS;
}
