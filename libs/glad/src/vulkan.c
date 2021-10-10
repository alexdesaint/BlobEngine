#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/vulkan.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

#ifdef __cplusplus
extern "C" {
#endif



int GLAD_VK_VERSION_1_0 = 0;
int GLAD_VK_VERSION_1_1 = 0;
int GLAD_VK_VERSION_1_2 = 0;
int GLAD_VK_EXT_4444_formats = 0;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
int GLAD_VK_EXT_acquire_xlib_display = 0;
#endif
int GLAD_VK_EXT_astc_decode_mode = 0;
int GLAD_VK_EXT_blend_operation_advanced = 0;
int GLAD_VK_EXT_buffer_device_address = 0;
int GLAD_VK_EXT_calibrated_timestamps = 0;
int GLAD_VK_EXT_conditional_rendering = 0;
int GLAD_VK_EXT_conservative_rasterization = 0;
int GLAD_VK_EXT_custom_border_color = 0;
int GLAD_VK_EXT_debug_marker = 0;
int GLAD_VK_EXT_debug_report = 0;
int GLAD_VK_EXT_debug_utils = 0;
int GLAD_VK_EXT_depth_clip_enable = 0;
int GLAD_VK_EXT_depth_range_unrestricted = 0;
int GLAD_VK_EXT_descriptor_indexing = 0;
int GLAD_VK_EXT_direct_mode_display = 0;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
int GLAD_VK_EXT_directfb_surface = 0;
#endif
int GLAD_VK_EXT_discard_rectangles = 0;
int GLAD_VK_EXT_display_control = 0;
int GLAD_VK_EXT_display_surface_counter = 0;
int GLAD_VK_EXT_extended_dynamic_state = 0;
int GLAD_VK_EXT_external_memory_dma_buf = 0;
int GLAD_VK_EXT_external_memory_host = 0;
int GLAD_VK_EXT_filter_cubic = 0;
int GLAD_VK_EXT_fragment_density_map = 0;
int GLAD_VK_EXT_fragment_density_map2 = 0;
int GLAD_VK_EXT_fragment_shader_interlock = 0;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_EXT_full_screen_exclusive = 0;
#endif
int GLAD_VK_EXT_global_priority = 0;
int GLAD_VK_EXT_hdr_metadata = 0;
int GLAD_VK_EXT_headless_surface = 0;
int GLAD_VK_EXT_host_query_reset = 0;
int GLAD_VK_EXT_image_drm_format_modifier = 0;
int GLAD_VK_EXT_image_robustness = 0;
int GLAD_VK_EXT_index_type_uint8 = 0;
int GLAD_VK_EXT_inline_uniform_block = 0;
int GLAD_VK_EXT_line_rasterization = 0;
int GLAD_VK_EXT_memory_budget = 0;
int GLAD_VK_EXT_memory_priority = 0;
#if defined(VK_USE_PLATFORM_METAL_EXT)
int GLAD_VK_EXT_metal_surface = 0;
#endif
int GLAD_VK_EXT_pci_bus_info = 0;
int GLAD_VK_EXT_pipeline_creation_cache_control = 0;
int GLAD_VK_EXT_pipeline_creation_feedback = 0;
int GLAD_VK_EXT_post_depth_coverage = 0;
int GLAD_VK_EXT_private_data = 0;
int GLAD_VK_EXT_queue_family_foreign = 0;
int GLAD_VK_EXT_robustness2 = 0;
int GLAD_VK_EXT_sample_locations = 0;
int GLAD_VK_EXT_sampler_filter_minmax = 0;
int GLAD_VK_EXT_scalar_block_layout = 0;
int GLAD_VK_EXT_separate_stencil_usage = 0;
int GLAD_VK_EXT_shader_atomic_float = 0;
int GLAD_VK_EXT_shader_demote_to_helper_invocation = 0;
int GLAD_VK_EXT_shader_stencil_export = 0;
int GLAD_VK_EXT_shader_subgroup_ballot = 0;
int GLAD_VK_EXT_shader_subgroup_vote = 0;
int GLAD_VK_EXT_shader_viewport_index_layer = 0;
int GLAD_VK_EXT_subgroup_size_control = 0;
int GLAD_VK_EXT_swapchain_colorspace = 0;
int GLAD_VK_EXT_texel_buffer_alignment = 0;
int GLAD_VK_EXT_texture_compression_astc_hdr = 0;
int GLAD_VK_EXT_tooling_info = 0;
int GLAD_VK_EXT_transform_feedback = 0;
int GLAD_VK_EXT_validation_cache = 0;
int GLAD_VK_EXT_validation_features = 0;
int GLAD_VK_EXT_validation_flags = 0;
int GLAD_VK_EXT_vertex_attribute_divisor = 0;
int GLAD_VK_EXT_ycbcr_image_arrays = 0;
int GLAD_VK_KHR_16bit_storage = 0;
int GLAD_VK_KHR_8bit_storage = 0;
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
int GLAD_VK_KHR_android_surface = 0;
#endif
int GLAD_VK_KHR_bind_memory2 = 0;
int GLAD_VK_KHR_buffer_device_address = 0;
int GLAD_VK_KHR_create_renderpass2 = 0;
int GLAD_VK_KHR_dedicated_allocation = 0;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
int GLAD_VK_KHR_deferred_host_operations = 0;
#endif
int GLAD_VK_KHR_depth_stencil_resolve = 0;
int GLAD_VK_KHR_descriptor_update_template = 0;
int GLAD_VK_KHR_device_group = 0;
int GLAD_VK_KHR_device_group_creation = 0;
int GLAD_VK_KHR_display = 0;
int GLAD_VK_KHR_display_swapchain = 0;
int GLAD_VK_KHR_draw_indirect_count = 0;
int GLAD_VK_KHR_driver_properties = 0;
int GLAD_VK_KHR_external_fence = 0;
int GLAD_VK_KHR_external_fence_capabilities = 0;
int GLAD_VK_KHR_external_fence_fd = 0;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_KHR_external_fence_win32 = 0;
#endif
int GLAD_VK_KHR_external_memory = 0;
int GLAD_VK_KHR_external_memory_capabilities = 0;
int GLAD_VK_KHR_external_memory_fd = 0;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_KHR_external_memory_win32 = 0;
#endif
int GLAD_VK_KHR_external_semaphore = 0;
int GLAD_VK_KHR_external_semaphore_capabilities = 0;
int GLAD_VK_KHR_external_semaphore_fd = 0;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_KHR_external_semaphore_win32 = 0;
#endif
int GLAD_VK_KHR_get_display_properties2 = 0;
int GLAD_VK_KHR_get_memory_requirements2 = 0;
int GLAD_VK_KHR_get_physical_device_properties2 = 0;
int GLAD_VK_KHR_get_surface_capabilities2 = 0;
int GLAD_VK_KHR_image_format_list = 0;
int GLAD_VK_KHR_imageless_framebuffer = 0;
int GLAD_VK_KHR_incremental_present = 0;
int GLAD_VK_KHR_maintenance1 = 0;
int GLAD_VK_KHR_maintenance2 = 0;
int GLAD_VK_KHR_maintenance3 = 0;
int GLAD_VK_KHR_multiview = 0;
int GLAD_VK_KHR_performance_query = 0;
int GLAD_VK_KHR_pipeline_executable_properties = 0;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
int GLAD_VK_KHR_pipeline_library = 0;
#endif
int GLAD_VK_KHR_push_descriptor = 0;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
int GLAD_VK_KHR_ray_tracing = 0;
#endif
int GLAD_VK_KHR_relaxed_block_layout = 0;
int GLAD_VK_KHR_sampler_mirror_clamp_to_edge = 0;
int GLAD_VK_KHR_sampler_ycbcr_conversion = 0;
int GLAD_VK_KHR_separate_depth_stencil_layouts = 0;
int GLAD_VK_KHR_shader_atomic_int64 = 0;
int GLAD_VK_KHR_shader_clock = 0;
int GLAD_VK_KHR_shader_draw_parameters = 0;
int GLAD_VK_KHR_shader_float16_int8 = 0;
int GLAD_VK_KHR_shader_float_controls = 0;
int GLAD_VK_KHR_shader_non_semantic_info = 0;
int GLAD_VK_KHR_shader_subgroup_extended_types = 0;
int GLAD_VK_KHR_shared_presentable_image = 0;
int GLAD_VK_KHR_spirv_1_4 = 0;
int GLAD_VK_KHR_storage_buffer_storage_class = 0;
int GLAD_VK_KHR_surface = 0;
int GLAD_VK_KHR_surface_protected_capabilities = 0;
int GLAD_VK_KHR_swapchain = 0;
int GLAD_VK_KHR_swapchain_mutable_format = 0;
int GLAD_VK_KHR_timeline_semaphore = 0;
int GLAD_VK_KHR_uniform_buffer_standard_layout = 0;
int GLAD_VK_KHR_variable_pointers = 0;
int GLAD_VK_KHR_vulkan_memory_model = 0;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
int GLAD_VK_KHR_wayland_surface = 0;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_KHR_win32_keyed_mutex = 0;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
int GLAD_VK_KHR_win32_surface = 0;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
int GLAD_VK_KHR_xcb_surface = 0;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
int GLAD_VK_KHR_xlib_surface = 0;
#endif


static void _pre_call_vulkan_callback_default(const char *name, GLADapiproc apiproc, int len_args, ...) {
    (void) name;
    (void) apiproc;
    (void) len_args;
}
static void _post_call_vulkan_callback_default(void *ret, const char *name, GLADapiproc apiproc, int len_args, ...) {
    (void) ret;
    (void) name;
    (void) apiproc;
    (void) len_args;
}

static GLADprecallback _pre_call_vulkan_callback = _pre_call_vulkan_callback_default;
void gladSetVulkanPreCallback(GLADprecallback cb) {
    _pre_call_vulkan_callback = cb;
}
static GLADpostcallback _post_call_vulkan_callback = _post_call_vulkan_callback_default;
void gladSetVulkanPostCallback(GLADpostcallback cb) {
    _post_call_vulkan_callback = cb;
}

#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkAcquireFullScreenExclusiveModeEXT glad_vkAcquireFullScreenExclusiveModeEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAcquireFullScreenExclusiveModeEXT", (GLADapiproc) glad_vkAcquireFullScreenExclusiveModeEXT, 2, device, swapchain);
    ret = glad_vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
    _post_call_vulkan_callback((void*) &ret, "vkAcquireFullScreenExclusiveModeEXT", (GLADapiproc) glad_vkAcquireFullScreenExclusiveModeEXT, 2, device, swapchain);
    return ret;
}
PFN_vkAcquireFullScreenExclusiveModeEXT glad_debug_vkAcquireFullScreenExclusiveModeEXT = glad_debug_impl_vkAcquireFullScreenExclusiveModeEXT;
#endif
PFN_vkAcquireNextImage2KHR glad_vkAcquireNextImage2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR * pAcquireInfo, uint32_t * pImageIndex) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAcquireNextImage2KHR", (GLADapiproc) glad_vkAcquireNextImage2KHR, 3, device, pAcquireInfo, pImageIndex);
    ret = glad_vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    _post_call_vulkan_callback((void*) &ret, "vkAcquireNextImage2KHR", (GLADapiproc) glad_vkAcquireNextImage2KHR, 3, device, pAcquireInfo, pImageIndex);
    return ret;
}
PFN_vkAcquireNextImage2KHR glad_debug_vkAcquireNextImage2KHR = glad_debug_impl_vkAcquireNextImage2KHR;
PFN_vkAcquireNextImageKHR glad_vkAcquireNextImageKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t * pImageIndex) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAcquireNextImageKHR", (GLADapiproc) glad_vkAcquireNextImageKHR, 6, device, swapchain, timeout, semaphore, fence, pImageIndex);
    ret = glad_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    _post_call_vulkan_callback((void*) &ret, "vkAcquireNextImageKHR", (GLADapiproc) glad_vkAcquireNextImageKHR, 6, device, swapchain, timeout, semaphore, fence, pImageIndex);
    return ret;
}
PFN_vkAcquireNextImageKHR glad_debug_vkAcquireNextImageKHR = glad_debug_impl_vkAcquireNextImageKHR;
PFN_vkAcquireProfilingLockKHR glad_vkAcquireProfilingLockKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR * pInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAcquireProfilingLockKHR", (GLADapiproc) glad_vkAcquireProfilingLockKHR, 2, device, pInfo);
    ret = glad_vkAcquireProfilingLockKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkAcquireProfilingLockKHR", (GLADapiproc) glad_vkAcquireProfilingLockKHR, 2, device, pInfo);
    return ret;
}
PFN_vkAcquireProfilingLockKHR glad_debug_vkAcquireProfilingLockKHR = glad_debug_impl_vkAcquireProfilingLockKHR;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
PFN_vkAcquireXlibDisplayEXT glad_vkAcquireXlibDisplayEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display * dpy, VkDisplayKHR display) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAcquireXlibDisplayEXT", (GLADapiproc) glad_vkAcquireXlibDisplayEXT, 3, physicalDevice, dpy, display);
    ret = glad_vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
    _post_call_vulkan_callback((void*) &ret, "vkAcquireXlibDisplayEXT", (GLADapiproc) glad_vkAcquireXlibDisplayEXT, 3, physicalDevice, dpy, display);
    return ret;
}
PFN_vkAcquireXlibDisplayEXT glad_debug_vkAcquireXlibDisplayEXT = glad_debug_impl_vkAcquireXlibDisplayEXT;
#endif
PFN_vkAllocateCommandBuffers glad_vkAllocateCommandBuffers = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo * pAllocateInfo, VkCommandBuffer * pCommandBuffers) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAllocateCommandBuffers", (GLADapiproc) glad_vkAllocateCommandBuffers, 3, device, pAllocateInfo, pCommandBuffers);
    ret = glad_vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    _post_call_vulkan_callback((void*) &ret, "vkAllocateCommandBuffers", (GLADapiproc) glad_vkAllocateCommandBuffers, 3, device, pAllocateInfo, pCommandBuffers);
    return ret;
}
PFN_vkAllocateCommandBuffers glad_debug_vkAllocateCommandBuffers = glad_debug_impl_vkAllocateCommandBuffers;
PFN_vkAllocateDescriptorSets glad_vkAllocateDescriptorSets = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo * pAllocateInfo, VkDescriptorSet * pDescriptorSets) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAllocateDescriptorSets", (GLADapiproc) glad_vkAllocateDescriptorSets, 3, device, pAllocateInfo, pDescriptorSets);
    ret = glad_vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    _post_call_vulkan_callback((void*) &ret, "vkAllocateDescriptorSets", (GLADapiproc) glad_vkAllocateDescriptorSets, 3, device, pAllocateInfo, pDescriptorSets);
    return ret;
}
PFN_vkAllocateDescriptorSets glad_debug_vkAllocateDescriptorSets = glad_debug_impl_vkAllocateDescriptorSets;
PFN_vkAllocateMemory glad_vkAllocateMemory = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo * pAllocateInfo, const VkAllocationCallbacks * pAllocator, VkDeviceMemory * pMemory) {
    VkResult ret;
    _pre_call_vulkan_callback("vkAllocateMemory", (GLADapiproc) glad_vkAllocateMemory, 4, device, pAllocateInfo, pAllocator, pMemory);
    ret = glad_vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    _post_call_vulkan_callback((void*) &ret, "vkAllocateMemory", (GLADapiproc) glad_vkAllocateMemory, 4, device, pAllocateInfo, pAllocator, pMemory);
    return ret;
}
PFN_vkAllocateMemory glad_debug_vkAllocateMemory = glad_debug_impl_vkAllocateMemory;
PFN_vkBeginCommandBuffer glad_vkBeginCommandBuffer = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo * pBeginInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBeginCommandBuffer", (GLADapiproc) glad_vkBeginCommandBuffer, 2, commandBuffer, pBeginInfo);
    ret = glad_vkBeginCommandBuffer(commandBuffer, pBeginInfo);
    _post_call_vulkan_callback((void*) &ret, "vkBeginCommandBuffer", (GLADapiproc) glad_vkBeginCommandBuffer, 2, commandBuffer, pBeginInfo);
    return ret;
}
PFN_vkBeginCommandBuffer glad_debug_vkBeginCommandBuffer = glad_debug_impl_vkBeginCommandBuffer;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkBindAccelerationStructureMemoryKHR glad_vkBindAccelerationStructureMemoryKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindAccelerationStructureMemoryKHR(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoKHR * pBindInfos) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindAccelerationStructureMemoryKHR", (GLADapiproc) glad_vkBindAccelerationStructureMemoryKHR, 3, device, bindInfoCount, pBindInfos);
    ret = glad_vkBindAccelerationStructureMemoryKHR(device, bindInfoCount, pBindInfos);
    _post_call_vulkan_callback((void*) &ret, "vkBindAccelerationStructureMemoryKHR", (GLADapiproc) glad_vkBindAccelerationStructureMemoryKHR, 3, device, bindInfoCount, pBindInfos);
    return ret;
}
PFN_vkBindAccelerationStructureMemoryKHR glad_debug_vkBindAccelerationStructureMemoryKHR = glad_debug_impl_vkBindAccelerationStructureMemoryKHR;
#endif
PFN_vkBindBufferMemory glad_vkBindBufferMemory = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindBufferMemory", (GLADapiproc) glad_vkBindBufferMemory, 4, device, buffer, memory, memoryOffset);
    ret = glad_vkBindBufferMemory(device, buffer, memory, memoryOffset);
    _post_call_vulkan_callback((void*) &ret, "vkBindBufferMemory", (GLADapiproc) glad_vkBindBufferMemory, 4, device, buffer, memory, memoryOffset);
    return ret;
}
PFN_vkBindBufferMemory glad_debug_vkBindBufferMemory = glad_debug_impl_vkBindBufferMemory;
PFN_vkBindBufferMemory2 glad_vkBindBufferMemory2 = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo * pBindInfos) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindBufferMemory2", (GLADapiproc) glad_vkBindBufferMemory2, 3, device, bindInfoCount, pBindInfos);
    ret = glad_vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
    _post_call_vulkan_callback((void*) &ret, "vkBindBufferMemory2", (GLADapiproc) glad_vkBindBufferMemory2, 3, device, bindInfoCount, pBindInfos);
    return ret;
}
PFN_vkBindBufferMemory2 glad_debug_vkBindBufferMemory2 = glad_debug_impl_vkBindBufferMemory2;
PFN_vkBindBufferMemory2KHR glad_vkBindBufferMemory2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo * pBindInfos) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindBufferMemory2KHR", (GLADapiproc) glad_vkBindBufferMemory2KHR, 3, device, bindInfoCount, pBindInfos);
    ret = glad_vkBindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
    _post_call_vulkan_callback((void*) &ret, "vkBindBufferMemory2KHR", (GLADapiproc) glad_vkBindBufferMemory2KHR, 3, device, bindInfoCount, pBindInfos);
    return ret;
}
PFN_vkBindBufferMemory2KHR glad_debug_vkBindBufferMemory2KHR = glad_debug_impl_vkBindBufferMemory2KHR;
PFN_vkBindImageMemory glad_vkBindImageMemory = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindImageMemory", (GLADapiproc) glad_vkBindImageMemory, 4, device, image, memory, memoryOffset);
    ret = glad_vkBindImageMemory(device, image, memory, memoryOffset);
    _post_call_vulkan_callback((void*) &ret, "vkBindImageMemory", (GLADapiproc) glad_vkBindImageMemory, 4, device, image, memory, memoryOffset);
    return ret;
}
PFN_vkBindImageMemory glad_debug_vkBindImageMemory = glad_debug_impl_vkBindImageMemory;
PFN_vkBindImageMemory2 glad_vkBindImageMemory2 = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo * pBindInfos) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindImageMemory2", (GLADapiproc) glad_vkBindImageMemory2, 3, device, bindInfoCount, pBindInfos);
    ret = glad_vkBindImageMemory2(device, bindInfoCount, pBindInfos);
    _post_call_vulkan_callback((void*) &ret, "vkBindImageMemory2", (GLADapiproc) glad_vkBindImageMemory2, 3, device, bindInfoCount, pBindInfos);
    return ret;
}
PFN_vkBindImageMemory2 glad_debug_vkBindImageMemory2 = glad_debug_impl_vkBindImageMemory2;
PFN_vkBindImageMemory2KHR glad_vkBindImageMemory2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo * pBindInfos) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBindImageMemory2KHR", (GLADapiproc) glad_vkBindImageMemory2KHR, 3, device, bindInfoCount, pBindInfos);
    ret = glad_vkBindImageMemory2KHR(device, bindInfoCount, pBindInfos);
    _post_call_vulkan_callback((void*) &ret, "vkBindImageMemory2KHR", (GLADapiproc) glad_vkBindImageMemory2KHR, 3, device, bindInfoCount, pBindInfos);
    return ret;
}
PFN_vkBindImageMemory2KHR glad_debug_vkBindImageMemory2KHR = glad_debug_impl_vkBindImageMemory2KHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkBuildAccelerationStructureKHR glad_vkBuildAccelerationStructureKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkBuildAccelerationStructureKHR(VkDevice device, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR * pInfos, const VkAccelerationStructureBuildOffsetInfoKHR * const* ppOffsetInfos) {
    VkResult ret;
    _pre_call_vulkan_callback("vkBuildAccelerationStructureKHR", (GLADapiproc) glad_vkBuildAccelerationStructureKHR, 4, device, infoCount, pInfos, ppOffsetInfos);
    ret = glad_vkBuildAccelerationStructureKHR(device, infoCount, pInfos, ppOffsetInfos);
    _post_call_vulkan_callback((void*) &ret, "vkBuildAccelerationStructureKHR", (GLADapiproc) glad_vkBuildAccelerationStructureKHR, 4, device, infoCount, pInfos, ppOffsetInfos);
    return ret;
}
PFN_vkBuildAccelerationStructureKHR glad_debug_vkBuildAccelerationStructureKHR = glad_debug_impl_vkBuildAccelerationStructureKHR;
#endif
PFN_vkCmdBeginConditionalRenderingEXT glad_vkCmdBeginConditionalRenderingEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT * pConditionalRenderingBegin) {
    _pre_call_vulkan_callback("vkCmdBeginConditionalRenderingEXT", (GLADapiproc) glad_vkCmdBeginConditionalRenderingEXT, 2, commandBuffer, pConditionalRenderingBegin);
    glad_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    _post_call_vulkan_callback(NULL, "vkCmdBeginConditionalRenderingEXT", (GLADapiproc) glad_vkCmdBeginConditionalRenderingEXT, 2, commandBuffer, pConditionalRenderingBegin);
    
}
PFN_vkCmdBeginConditionalRenderingEXT glad_debug_vkCmdBeginConditionalRenderingEXT = glad_debug_impl_vkCmdBeginConditionalRenderingEXT;
PFN_vkCmdBeginDebugUtilsLabelEXT glad_vkCmdBeginDebugUtilsLabelEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT * pLabelInfo) {
    _pre_call_vulkan_callback("vkCmdBeginDebugUtilsLabelEXT", (GLADapiproc) glad_vkCmdBeginDebugUtilsLabelEXT, 2, commandBuffer, pLabelInfo);
    glad_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    _post_call_vulkan_callback(NULL, "vkCmdBeginDebugUtilsLabelEXT", (GLADapiproc) glad_vkCmdBeginDebugUtilsLabelEXT, 2, commandBuffer, pLabelInfo);
    
}
PFN_vkCmdBeginDebugUtilsLabelEXT glad_debug_vkCmdBeginDebugUtilsLabelEXT = glad_debug_impl_vkCmdBeginDebugUtilsLabelEXT;
PFN_vkCmdBeginQuery glad_vkCmdBeginQuery = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) {
    _pre_call_vulkan_callback("vkCmdBeginQuery", (GLADapiproc) glad_vkCmdBeginQuery, 4, commandBuffer, queryPool, query, flags);
    glad_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    _post_call_vulkan_callback(NULL, "vkCmdBeginQuery", (GLADapiproc) glad_vkCmdBeginQuery, 4, commandBuffer, queryPool, query, flags);
    
}
PFN_vkCmdBeginQuery glad_debug_vkCmdBeginQuery = glad_debug_impl_vkCmdBeginQuery;
PFN_vkCmdBeginQueryIndexedEXT glad_vkCmdBeginQueryIndexedEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {
    _pre_call_vulkan_callback("vkCmdBeginQueryIndexedEXT", (GLADapiproc) glad_vkCmdBeginQueryIndexedEXT, 5, commandBuffer, queryPool, query, flags, index);
    glad_vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
    _post_call_vulkan_callback(NULL, "vkCmdBeginQueryIndexedEXT", (GLADapiproc) glad_vkCmdBeginQueryIndexedEXT, 5, commandBuffer, queryPool, query, flags, index);
    
}
PFN_vkCmdBeginQueryIndexedEXT glad_debug_vkCmdBeginQueryIndexedEXT = glad_debug_impl_vkCmdBeginQueryIndexedEXT;
PFN_vkCmdBeginRenderPass glad_vkCmdBeginRenderPass = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo * pRenderPassBegin, VkSubpassContents contents) {
    _pre_call_vulkan_callback("vkCmdBeginRenderPass", (GLADapiproc) glad_vkCmdBeginRenderPass, 3, commandBuffer, pRenderPassBegin, contents);
    glad_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    _post_call_vulkan_callback(NULL, "vkCmdBeginRenderPass", (GLADapiproc) glad_vkCmdBeginRenderPass, 3, commandBuffer, pRenderPassBegin, contents);
    
}
PFN_vkCmdBeginRenderPass glad_debug_vkCmdBeginRenderPass = glad_debug_impl_vkCmdBeginRenderPass;
PFN_vkCmdBeginRenderPass2 glad_vkCmdBeginRenderPass2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo * pRenderPassBegin, const VkSubpassBeginInfo * pSubpassBeginInfo) {
    _pre_call_vulkan_callback("vkCmdBeginRenderPass2", (GLADapiproc) glad_vkCmdBeginRenderPass2, 3, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    glad_vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    _post_call_vulkan_callback(NULL, "vkCmdBeginRenderPass2", (GLADapiproc) glad_vkCmdBeginRenderPass2, 3, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    
}
PFN_vkCmdBeginRenderPass2 glad_debug_vkCmdBeginRenderPass2 = glad_debug_impl_vkCmdBeginRenderPass2;
PFN_vkCmdBeginRenderPass2KHR glad_vkCmdBeginRenderPass2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo * pRenderPassBegin, const VkSubpassBeginInfo * pSubpassBeginInfo) {
    _pre_call_vulkan_callback("vkCmdBeginRenderPass2KHR", (GLADapiproc) glad_vkCmdBeginRenderPass2KHR, 3, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    glad_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    _post_call_vulkan_callback(NULL, "vkCmdBeginRenderPass2KHR", (GLADapiproc) glad_vkCmdBeginRenderPass2KHR, 3, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    
}
PFN_vkCmdBeginRenderPass2KHR glad_debug_vkCmdBeginRenderPass2KHR = glad_debug_impl_vkCmdBeginRenderPass2KHR;
PFN_vkCmdBeginTransformFeedbackEXT glad_vkCmdBeginTransformFeedbackEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer * pCounterBuffers, const VkDeviceSize * pCounterBufferOffsets) {
    _pre_call_vulkan_callback("vkCmdBeginTransformFeedbackEXT", (GLADapiproc) glad_vkCmdBeginTransformFeedbackEXT, 5, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    glad_vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    _post_call_vulkan_callback(NULL, "vkCmdBeginTransformFeedbackEXT", (GLADapiproc) glad_vkCmdBeginTransformFeedbackEXT, 5, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    
}
PFN_vkCmdBeginTransformFeedbackEXT glad_debug_vkCmdBeginTransformFeedbackEXT = glad_debug_impl_vkCmdBeginTransformFeedbackEXT;
PFN_vkCmdBindDescriptorSets glad_vkCmdBindDescriptorSets = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet * pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t * pDynamicOffsets) {
    _pre_call_vulkan_callback("vkCmdBindDescriptorSets", (GLADapiproc) glad_vkCmdBindDescriptorSets, 8, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    glad_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    _post_call_vulkan_callback(NULL, "vkCmdBindDescriptorSets", (GLADapiproc) glad_vkCmdBindDescriptorSets, 8, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    
}
PFN_vkCmdBindDescriptorSets glad_debug_vkCmdBindDescriptorSets = glad_debug_impl_vkCmdBindDescriptorSets;
PFN_vkCmdBindIndexBuffer glad_vkCmdBindIndexBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
    _pre_call_vulkan_callback("vkCmdBindIndexBuffer", (GLADapiproc) glad_vkCmdBindIndexBuffer, 4, commandBuffer, buffer, offset, indexType);
    glad_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    _post_call_vulkan_callback(NULL, "vkCmdBindIndexBuffer", (GLADapiproc) glad_vkCmdBindIndexBuffer, 4, commandBuffer, buffer, offset, indexType);
    
}
PFN_vkCmdBindIndexBuffer glad_debug_vkCmdBindIndexBuffer = glad_debug_impl_vkCmdBindIndexBuffer;
PFN_vkCmdBindPipeline glad_vkCmdBindPipeline = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    _pre_call_vulkan_callback("vkCmdBindPipeline", (GLADapiproc) glad_vkCmdBindPipeline, 3, commandBuffer, pipelineBindPoint, pipeline);
    glad_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    _post_call_vulkan_callback(NULL, "vkCmdBindPipeline", (GLADapiproc) glad_vkCmdBindPipeline, 3, commandBuffer, pipelineBindPoint, pipeline);
    
}
PFN_vkCmdBindPipeline glad_debug_vkCmdBindPipeline = glad_debug_impl_vkCmdBindPipeline;
PFN_vkCmdBindTransformFeedbackBuffersEXT glad_vkCmdBindTransformFeedbackBuffersEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer * pBuffers, const VkDeviceSize * pOffsets, const VkDeviceSize * pSizes) {
    _pre_call_vulkan_callback("vkCmdBindTransformFeedbackBuffersEXT", (GLADapiproc) glad_vkCmdBindTransformFeedbackBuffersEXT, 6, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    glad_vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    _post_call_vulkan_callback(NULL, "vkCmdBindTransformFeedbackBuffersEXT", (GLADapiproc) glad_vkCmdBindTransformFeedbackBuffersEXT, 6, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
    
}
PFN_vkCmdBindTransformFeedbackBuffersEXT glad_debug_vkCmdBindTransformFeedbackBuffersEXT = glad_debug_impl_vkCmdBindTransformFeedbackBuffersEXT;
PFN_vkCmdBindVertexBuffers glad_vkCmdBindVertexBuffers = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer * pBuffers, const VkDeviceSize * pOffsets) {
    _pre_call_vulkan_callback("vkCmdBindVertexBuffers", (GLADapiproc) glad_vkCmdBindVertexBuffers, 5, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    glad_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    _post_call_vulkan_callback(NULL, "vkCmdBindVertexBuffers", (GLADapiproc) glad_vkCmdBindVertexBuffers, 5, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    
}
PFN_vkCmdBindVertexBuffers glad_debug_vkCmdBindVertexBuffers = glad_debug_impl_vkCmdBindVertexBuffers;
PFN_vkCmdBindVertexBuffers2EXT glad_vkCmdBindVertexBuffers2EXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer * pBuffers, const VkDeviceSize * pOffsets, const VkDeviceSize * pSizes, const VkDeviceSize * pStrides) {
    _pre_call_vulkan_callback("vkCmdBindVertexBuffers2EXT", (GLADapiproc) glad_vkCmdBindVertexBuffers2EXT, 7, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    glad_vkCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    _post_call_vulkan_callback(NULL, "vkCmdBindVertexBuffers2EXT", (GLADapiproc) glad_vkCmdBindVertexBuffers2EXT, 7, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
    
}
PFN_vkCmdBindVertexBuffers2EXT glad_debug_vkCmdBindVertexBuffers2EXT = glad_debug_impl_vkCmdBindVertexBuffers2EXT;
PFN_vkCmdBlitImage glad_vkCmdBlitImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit * pRegions, VkFilter filter) {
    _pre_call_vulkan_callback("vkCmdBlitImage", (GLADapiproc) glad_vkCmdBlitImage, 8, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    glad_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    _post_call_vulkan_callback(NULL, "vkCmdBlitImage", (GLADapiproc) glad_vkCmdBlitImage, 8, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    
}
PFN_vkCmdBlitImage glad_debug_vkCmdBlitImage = glad_debug_impl_vkCmdBlitImage;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdBuildAccelerationStructureIndirectKHR glad_vkCmdBuildAccelerationStructureIndirectKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBuildAccelerationStructureIndirectKHR(VkCommandBuffer commandBuffer, const VkAccelerationStructureBuildGeometryInfoKHR * pInfo, VkBuffer indirectBuffer, VkDeviceSize indirectOffset, uint32_t indirectStride) {
    _pre_call_vulkan_callback("vkCmdBuildAccelerationStructureIndirectKHR", (GLADapiproc) glad_vkCmdBuildAccelerationStructureIndirectKHR, 5, commandBuffer, pInfo, indirectBuffer, indirectOffset, indirectStride);
    glad_vkCmdBuildAccelerationStructureIndirectKHR(commandBuffer, pInfo, indirectBuffer, indirectOffset, indirectStride);
    _post_call_vulkan_callback(NULL, "vkCmdBuildAccelerationStructureIndirectKHR", (GLADapiproc) glad_vkCmdBuildAccelerationStructureIndirectKHR, 5, commandBuffer, pInfo, indirectBuffer, indirectOffset, indirectStride);
    
}
PFN_vkCmdBuildAccelerationStructureIndirectKHR glad_debug_vkCmdBuildAccelerationStructureIndirectKHR = glad_debug_impl_vkCmdBuildAccelerationStructureIndirectKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdBuildAccelerationStructureKHR glad_vkCmdBuildAccelerationStructureKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdBuildAccelerationStructureKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR * pInfos, const VkAccelerationStructureBuildOffsetInfoKHR * const* ppOffsetInfos) {
    _pre_call_vulkan_callback("vkCmdBuildAccelerationStructureKHR", (GLADapiproc) glad_vkCmdBuildAccelerationStructureKHR, 4, commandBuffer, infoCount, pInfos, ppOffsetInfos);
    glad_vkCmdBuildAccelerationStructureKHR(commandBuffer, infoCount, pInfos, ppOffsetInfos);
    _post_call_vulkan_callback(NULL, "vkCmdBuildAccelerationStructureKHR", (GLADapiproc) glad_vkCmdBuildAccelerationStructureKHR, 4, commandBuffer, infoCount, pInfos, ppOffsetInfos);
    
}
PFN_vkCmdBuildAccelerationStructureKHR glad_debug_vkCmdBuildAccelerationStructureKHR = glad_debug_impl_vkCmdBuildAccelerationStructureKHR;
#endif
PFN_vkCmdClearAttachments glad_vkCmdClearAttachments = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment * pAttachments, uint32_t rectCount, const VkClearRect * pRects) {
    _pre_call_vulkan_callback("vkCmdClearAttachments", (GLADapiproc) glad_vkCmdClearAttachments, 5, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    glad_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    _post_call_vulkan_callback(NULL, "vkCmdClearAttachments", (GLADapiproc) glad_vkCmdClearAttachments, 5, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    
}
PFN_vkCmdClearAttachments glad_debug_vkCmdClearAttachments = glad_debug_impl_vkCmdClearAttachments;
PFN_vkCmdClearColorImage glad_vkCmdClearColorImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue * pColor, uint32_t rangeCount, const VkImageSubresourceRange * pRanges) {
    _pre_call_vulkan_callback("vkCmdClearColorImage", (GLADapiproc) glad_vkCmdClearColorImage, 6, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    glad_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    _post_call_vulkan_callback(NULL, "vkCmdClearColorImage", (GLADapiproc) glad_vkCmdClearColorImage, 6, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    
}
PFN_vkCmdClearColorImage glad_debug_vkCmdClearColorImage = glad_debug_impl_vkCmdClearColorImage;
PFN_vkCmdClearDepthStencilImage glad_vkCmdClearDepthStencilImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue * pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange * pRanges) {
    _pre_call_vulkan_callback("vkCmdClearDepthStencilImage", (GLADapiproc) glad_vkCmdClearDepthStencilImage, 6, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    glad_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    _post_call_vulkan_callback(NULL, "vkCmdClearDepthStencilImage", (GLADapiproc) glad_vkCmdClearDepthStencilImage, 6, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    
}
PFN_vkCmdClearDepthStencilImage glad_debug_vkCmdClearDepthStencilImage = glad_debug_impl_vkCmdClearDepthStencilImage;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdCopyAccelerationStructureKHR glad_vkCmdCopyAccelerationStructureKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR * pInfo) {
    _pre_call_vulkan_callback("vkCmdCopyAccelerationStructureKHR", (GLADapiproc) glad_vkCmdCopyAccelerationStructureKHR, 2, commandBuffer, pInfo);
    glad_vkCmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
    _post_call_vulkan_callback(NULL, "vkCmdCopyAccelerationStructureKHR", (GLADapiproc) glad_vkCmdCopyAccelerationStructureKHR, 2, commandBuffer, pInfo);
    
}
PFN_vkCmdCopyAccelerationStructureKHR glad_debug_vkCmdCopyAccelerationStructureKHR = glad_debug_impl_vkCmdCopyAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdCopyAccelerationStructureToMemoryKHR glad_vkCmdCopyAccelerationStructureToMemoryKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR * pInfo) {
    _pre_call_vulkan_callback("vkCmdCopyAccelerationStructureToMemoryKHR", (GLADapiproc) glad_vkCmdCopyAccelerationStructureToMemoryKHR, 2, commandBuffer, pInfo);
    glad_vkCmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
    _post_call_vulkan_callback(NULL, "vkCmdCopyAccelerationStructureToMemoryKHR", (GLADapiproc) glad_vkCmdCopyAccelerationStructureToMemoryKHR, 2, commandBuffer, pInfo);
    
}
PFN_vkCmdCopyAccelerationStructureToMemoryKHR glad_debug_vkCmdCopyAccelerationStructureToMemoryKHR = glad_debug_impl_vkCmdCopyAccelerationStructureToMemoryKHR;
#endif
PFN_vkCmdCopyBuffer glad_vkCmdCopyBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy * pRegions) {
    _pre_call_vulkan_callback("vkCmdCopyBuffer", (GLADapiproc) glad_vkCmdCopyBuffer, 5, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    glad_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    _post_call_vulkan_callback(NULL, "vkCmdCopyBuffer", (GLADapiproc) glad_vkCmdCopyBuffer, 5, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    
}
PFN_vkCmdCopyBuffer glad_debug_vkCmdCopyBuffer = glad_debug_impl_vkCmdCopyBuffer;
PFN_vkCmdCopyBufferToImage glad_vkCmdCopyBufferToImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy * pRegions) {
    _pre_call_vulkan_callback("vkCmdCopyBufferToImage", (GLADapiproc) glad_vkCmdCopyBufferToImage, 6, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    glad_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    _post_call_vulkan_callback(NULL, "vkCmdCopyBufferToImage", (GLADapiproc) glad_vkCmdCopyBufferToImage, 6, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    
}
PFN_vkCmdCopyBufferToImage glad_debug_vkCmdCopyBufferToImage = glad_debug_impl_vkCmdCopyBufferToImage;
PFN_vkCmdCopyImage glad_vkCmdCopyImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy * pRegions) {
    _pre_call_vulkan_callback("vkCmdCopyImage", (GLADapiproc) glad_vkCmdCopyImage, 7, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    glad_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    _post_call_vulkan_callback(NULL, "vkCmdCopyImage", (GLADapiproc) glad_vkCmdCopyImage, 7, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    
}
PFN_vkCmdCopyImage glad_debug_vkCmdCopyImage = glad_debug_impl_vkCmdCopyImage;
PFN_vkCmdCopyImageToBuffer glad_vkCmdCopyImageToBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy * pRegions) {
    _pre_call_vulkan_callback("vkCmdCopyImageToBuffer", (GLADapiproc) glad_vkCmdCopyImageToBuffer, 6, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    glad_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    _post_call_vulkan_callback(NULL, "vkCmdCopyImageToBuffer", (GLADapiproc) glad_vkCmdCopyImageToBuffer, 6, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    
}
PFN_vkCmdCopyImageToBuffer glad_debug_vkCmdCopyImageToBuffer = glad_debug_impl_vkCmdCopyImageToBuffer;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdCopyMemoryToAccelerationStructureKHR glad_vkCmdCopyMemoryToAccelerationStructureKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR * pInfo) {
    _pre_call_vulkan_callback("vkCmdCopyMemoryToAccelerationStructureKHR", (GLADapiproc) glad_vkCmdCopyMemoryToAccelerationStructureKHR, 2, commandBuffer, pInfo);
    glad_vkCmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
    _post_call_vulkan_callback(NULL, "vkCmdCopyMemoryToAccelerationStructureKHR", (GLADapiproc) glad_vkCmdCopyMemoryToAccelerationStructureKHR, 2, commandBuffer, pInfo);
    
}
PFN_vkCmdCopyMemoryToAccelerationStructureKHR glad_debug_vkCmdCopyMemoryToAccelerationStructureKHR = glad_debug_impl_vkCmdCopyMemoryToAccelerationStructureKHR;
#endif
PFN_vkCmdCopyQueryPoolResults glad_vkCmdCopyQueryPoolResults = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    _pre_call_vulkan_callback("vkCmdCopyQueryPoolResults", (GLADapiproc) glad_vkCmdCopyQueryPoolResults, 8, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    glad_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    _post_call_vulkan_callback(NULL, "vkCmdCopyQueryPoolResults", (GLADapiproc) glad_vkCmdCopyQueryPoolResults, 8, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    
}
PFN_vkCmdCopyQueryPoolResults glad_debug_vkCmdCopyQueryPoolResults = glad_debug_impl_vkCmdCopyQueryPoolResults;
PFN_vkCmdDebugMarkerBeginEXT glad_vkCmdDebugMarkerBeginEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT * pMarkerInfo) {
    _pre_call_vulkan_callback("vkCmdDebugMarkerBeginEXT", (GLADapiproc) glad_vkCmdDebugMarkerBeginEXT, 2, commandBuffer, pMarkerInfo);
    glad_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    _post_call_vulkan_callback(NULL, "vkCmdDebugMarkerBeginEXT", (GLADapiproc) glad_vkCmdDebugMarkerBeginEXT, 2, commandBuffer, pMarkerInfo);
    
}
PFN_vkCmdDebugMarkerBeginEXT glad_debug_vkCmdDebugMarkerBeginEXT = glad_debug_impl_vkCmdDebugMarkerBeginEXT;
PFN_vkCmdDebugMarkerEndEXT glad_vkCmdDebugMarkerEndEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    _pre_call_vulkan_callback("vkCmdDebugMarkerEndEXT", (GLADapiproc) glad_vkCmdDebugMarkerEndEXT, 1, commandBuffer);
    glad_vkCmdDebugMarkerEndEXT(commandBuffer);
    _post_call_vulkan_callback(NULL, "vkCmdDebugMarkerEndEXT", (GLADapiproc) glad_vkCmdDebugMarkerEndEXT, 1, commandBuffer);
    
}
PFN_vkCmdDebugMarkerEndEXT glad_debug_vkCmdDebugMarkerEndEXT = glad_debug_impl_vkCmdDebugMarkerEndEXT;
PFN_vkCmdDebugMarkerInsertEXT glad_vkCmdDebugMarkerInsertEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT * pMarkerInfo) {
    _pre_call_vulkan_callback("vkCmdDebugMarkerInsertEXT", (GLADapiproc) glad_vkCmdDebugMarkerInsertEXT, 2, commandBuffer, pMarkerInfo);
    glad_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    _post_call_vulkan_callback(NULL, "vkCmdDebugMarkerInsertEXT", (GLADapiproc) glad_vkCmdDebugMarkerInsertEXT, 2, commandBuffer, pMarkerInfo);
    
}
PFN_vkCmdDebugMarkerInsertEXT glad_debug_vkCmdDebugMarkerInsertEXT = glad_debug_impl_vkCmdDebugMarkerInsertEXT;
PFN_vkCmdDispatch glad_vkCmdDispatch = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    _pre_call_vulkan_callback("vkCmdDispatch", (GLADapiproc) glad_vkCmdDispatch, 4, commandBuffer, groupCountX, groupCountY, groupCountZ);
    glad_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    _post_call_vulkan_callback(NULL, "vkCmdDispatch", (GLADapiproc) glad_vkCmdDispatch, 4, commandBuffer, groupCountX, groupCountY, groupCountZ);
    
}
PFN_vkCmdDispatch glad_debug_vkCmdDispatch = glad_debug_impl_vkCmdDispatch;
PFN_vkCmdDispatchBase glad_vkCmdDispatchBase = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    _pre_call_vulkan_callback("vkCmdDispatchBase", (GLADapiproc) glad_vkCmdDispatchBase, 7, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    glad_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    _post_call_vulkan_callback(NULL, "vkCmdDispatchBase", (GLADapiproc) glad_vkCmdDispatchBase, 7, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    
}
PFN_vkCmdDispatchBase glad_debug_vkCmdDispatchBase = glad_debug_impl_vkCmdDispatchBase;
PFN_vkCmdDispatchBaseKHR glad_vkCmdDispatchBaseKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    _pre_call_vulkan_callback("vkCmdDispatchBaseKHR", (GLADapiproc) glad_vkCmdDispatchBaseKHR, 7, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    glad_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    _post_call_vulkan_callback(NULL, "vkCmdDispatchBaseKHR", (GLADapiproc) glad_vkCmdDispatchBaseKHR, 7, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    
}
PFN_vkCmdDispatchBaseKHR glad_debug_vkCmdDispatchBaseKHR = glad_debug_impl_vkCmdDispatchBaseKHR;
PFN_vkCmdDispatchIndirect glad_vkCmdDispatchIndirect = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    _pre_call_vulkan_callback("vkCmdDispatchIndirect", (GLADapiproc) glad_vkCmdDispatchIndirect, 3, commandBuffer, buffer, offset);
    glad_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    _post_call_vulkan_callback(NULL, "vkCmdDispatchIndirect", (GLADapiproc) glad_vkCmdDispatchIndirect, 3, commandBuffer, buffer, offset);
    
}
PFN_vkCmdDispatchIndirect glad_debug_vkCmdDispatchIndirect = glad_debug_impl_vkCmdDispatchIndirect;
PFN_vkCmdDraw glad_vkCmdDraw = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
    _pre_call_vulkan_callback("vkCmdDraw", (GLADapiproc) glad_vkCmdDraw, 5, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    glad_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    _post_call_vulkan_callback(NULL, "vkCmdDraw", (GLADapiproc) glad_vkCmdDraw, 5, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    
}
PFN_vkCmdDraw glad_debug_vkCmdDraw = glad_debug_impl_vkCmdDraw;
PFN_vkCmdDrawIndexed glad_vkCmdDrawIndexed = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    _pre_call_vulkan_callback("vkCmdDrawIndexed", (GLADapiproc) glad_vkCmdDrawIndexed, 6, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    glad_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndexed", (GLADapiproc) glad_vkCmdDrawIndexed, 6, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    
}
PFN_vkCmdDrawIndexed glad_debug_vkCmdDrawIndexed = glad_debug_impl_vkCmdDrawIndexed;
PFN_vkCmdDrawIndexedIndirect glad_vkCmdDrawIndexedIndirect = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    _pre_call_vulkan_callback("vkCmdDrawIndexedIndirect", (GLADapiproc) glad_vkCmdDrawIndexedIndirect, 5, commandBuffer, buffer, offset, drawCount, stride);
    glad_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndexedIndirect", (GLADapiproc) glad_vkCmdDrawIndexedIndirect, 5, commandBuffer, buffer, offset, drawCount, stride);
    
}
PFN_vkCmdDrawIndexedIndirect glad_debug_vkCmdDrawIndexedIndirect = glad_debug_impl_vkCmdDrawIndexedIndirect;
PFN_vkCmdDrawIndexedIndirectCount glad_vkCmdDrawIndexedIndirectCount = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    _pre_call_vulkan_callback("vkCmdDrawIndexedIndirectCount", (GLADapiproc) glad_vkCmdDrawIndexedIndirectCount, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    glad_vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndexedIndirectCount", (GLADapiproc) glad_vkCmdDrawIndexedIndirectCount, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
}
PFN_vkCmdDrawIndexedIndirectCount glad_debug_vkCmdDrawIndexedIndirectCount = glad_debug_impl_vkCmdDrawIndexedIndirectCount;
PFN_vkCmdDrawIndexedIndirectCountKHR glad_vkCmdDrawIndexedIndirectCountKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    _pre_call_vulkan_callback("vkCmdDrawIndexedIndirectCountKHR", (GLADapiproc) glad_vkCmdDrawIndexedIndirectCountKHR, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    glad_vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndexedIndirectCountKHR", (GLADapiproc) glad_vkCmdDrawIndexedIndirectCountKHR, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
}
PFN_vkCmdDrawIndexedIndirectCountKHR glad_debug_vkCmdDrawIndexedIndirectCountKHR = glad_debug_impl_vkCmdDrawIndexedIndirectCountKHR;
PFN_vkCmdDrawIndirect glad_vkCmdDrawIndirect = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    _pre_call_vulkan_callback("vkCmdDrawIndirect", (GLADapiproc) glad_vkCmdDrawIndirect, 5, commandBuffer, buffer, offset, drawCount, stride);
    glad_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndirect", (GLADapiproc) glad_vkCmdDrawIndirect, 5, commandBuffer, buffer, offset, drawCount, stride);
    
}
PFN_vkCmdDrawIndirect glad_debug_vkCmdDrawIndirect = glad_debug_impl_vkCmdDrawIndirect;
PFN_vkCmdDrawIndirectByteCountEXT glad_vkCmdDrawIndirectByteCountEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
    _pre_call_vulkan_callback("vkCmdDrawIndirectByteCountEXT", (GLADapiproc) glad_vkCmdDrawIndirectByteCountEXT, 7, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    glad_vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndirectByteCountEXT", (GLADapiproc) glad_vkCmdDrawIndirectByteCountEXT, 7, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
    
}
PFN_vkCmdDrawIndirectByteCountEXT glad_debug_vkCmdDrawIndirectByteCountEXT = glad_debug_impl_vkCmdDrawIndirectByteCountEXT;
PFN_vkCmdDrawIndirectCount glad_vkCmdDrawIndirectCount = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    _pre_call_vulkan_callback("vkCmdDrawIndirectCount", (GLADapiproc) glad_vkCmdDrawIndirectCount, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    glad_vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndirectCount", (GLADapiproc) glad_vkCmdDrawIndirectCount, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
}
PFN_vkCmdDrawIndirectCount glad_debug_vkCmdDrawIndirectCount = glad_debug_impl_vkCmdDrawIndirectCount;
PFN_vkCmdDrawIndirectCountKHR glad_vkCmdDrawIndirectCountKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    _pre_call_vulkan_callback("vkCmdDrawIndirectCountKHR", (GLADapiproc) glad_vkCmdDrawIndirectCountKHR, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    glad_vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    _post_call_vulkan_callback(NULL, "vkCmdDrawIndirectCountKHR", (GLADapiproc) glad_vkCmdDrawIndirectCountKHR, 7, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    
}
PFN_vkCmdDrawIndirectCountKHR glad_debug_vkCmdDrawIndirectCountKHR = glad_debug_impl_vkCmdDrawIndirectCountKHR;
PFN_vkCmdEndConditionalRenderingEXT glad_vkCmdEndConditionalRenderingEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    _pre_call_vulkan_callback("vkCmdEndConditionalRenderingEXT", (GLADapiproc) glad_vkCmdEndConditionalRenderingEXT, 1, commandBuffer);
    glad_vkCmdEndConditionalRenderingEXT(commandBuffer);
    _post_call_vulkan_callback(NULL, "vkCmdEndConditionalRenderingEXT", (GLADapiproc) glad_vkCmdEndConditionalRenderingEXT, 1, commandBuffer);
    
}
PFN_vkCmdEndConditionalRenderingEXT glad_debug_vkCmdEndConditionalRenderingEXT = glad_debug_impl_vkCmdEndConditionalRenderingEXT;
PFN_vkCmdEndDebugUtilsLabelEXT glad_vkCmdEndDebugUtilsLabelEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    _pre_call_vulkan_callback("vkCmdEndDebugUtilsLabelEXT", (GLADapiproc) glad_vkCmdEndDebugUtilsLabelEXT, 1, commandBuffer);
    glad_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    _post_call_vulkan_callback(NULL, "vkCmdEndDebugUtilsLabelEXT", (GLADapiproc) glad_vkCmdEndDebugUtilsLabelEXT, 1, commandBuffer);
    
}
PFN_vkCmdEndDebugUtilsLabelEXT glad_debug_vkCmdEndDebugUtilsLabelEXT = glad_debug_impl_vkCmdEndDebugUtilsLabelEXT;
PFN_vkCmdEndQuery glad_vkCmdEndQuery = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    _pre_call_vulkan_callback("vkCmdEndQuery", (GLADapiproc) glad_vkCmdEndQuery, 3, commandBuffer, queryPool, query);
    glad_vkCmdEndQuery(commandBuffer, queryPool, query);
    _post_call_vulkan_callback(NULL, "vkCmdEndQuery", (GLADapiproc) glad_vkCmdEndQuery, 3, commandBuffer, queryPool, query);
    
}
PFN_vkCmdEndQuery glad_debug_vkCmdEndQuery = glad_debug_impl_vkCmdEndQuery;
PFN_vkCmdEndQueryIndexedEXT glad_vkCmdEndQueryIndexedEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) {
    _pre_call_vulkan_callback("vkCmdEndQueryIndexedEXT", (GLADapiproc) glad_vkCmdEndQueryIndexedEXT, 4, commandBuffer, queryPool, query, index);
    glad_vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
    _post_call_vulkan_callback(NULL, "vkCmdEndQueryIndexedEXT", (GLADapiproc) glad_vkCmdEndQueryIndexedEXT, 4, commandBuffer, queryPool, query, index);
    
}
PFN_vkCmdEndQueryIndexedEXT glad_debug_vkCmdEndQueryIndexedEXT = glad_debug_impl_vkCmdEndQueryIndexedEXT;
PFN_vkCmdEndRenderPass glad_vkCmdEndRenderPass = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    _pre_call_vulkan_callback("vkCmdEndRenderPass", (GLADapiproc) glad_vkCmdEndRenderPass, 1, commandBuffer);
    glad_vkCmdEndRenderPass(commandBuffer);
    _post_call_vulkan_callback(NULL, "vkCmdEndRenderPass", (GLADapiproc) glad_vkCmdEndRenderPass, 1, commandBuffer);
    
}
PFN_vkCmdEndRenderPass glad_debug_vkCmdEndRenderPass = glad_debug_impl_vkCmdEndRenderPass;
PFN_vkCmdEndRenderPass2 glad_vkCmdEndRenderPass2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo * pSubpassEndInfo) {
    _pre_call_vulkan_callback("vkCmdEndRenderPass2", (GLADapiproc) glad_vkCmdEndRenderPass2, 2, commandBuffer, pSubpassEndInfo);
    glad_vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
    _post_call_vulkan_callback(NULL, "vkCmdEndRenderPass2", (GLADapiproc) glad_vkCmdEndRenderPass2, 2, commandBuffer, pSubpassEndInfo);
    
}
PFN_vkCmdEndRenderPass2 glad_debug_vkCmdEndRenderPass2 = glad_debug_impl_vkCmdEndRenderPass2;
PFN_vkCmdEndRenderPass2KHR glad_vkCmdEndRenderPass2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo * pSubpassEndInfo) {
    _pre_call_vulkan_callback("vkCmdEndRenderPass2KHR", (GLADapiproc) glad_vkCmdEndRenderPass2KHR, 2, commandBuffer, pSubpassEndInfo);
    glad_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    _post_call_vulkan_callback(NULL, "vkCmdEndRenderPass2KHR", (GLADapiproc) glad_vkCmdEndRenderPass2KHR, 2, commandBuffer, pSubpassEndInfo);
    
}
PFN_vkCmdEndRenderPass2KHR glad_debug_vkCmdEndRenderPass2KHR = glad_debug_impl_vkCmdEndRenderPass2KHR;
PFN_vkCmdEndTransformFeedbackEXT glad_vkCmdEndTransformFeedbackEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer * pCounterBuffers, const VkDeviceSize * pCounterBufferOffsets) {
    _pre_call_vulkan_callback("vkCmdEndTransformFeedbackEXT", (GLADapiproc) glad_vkCmdEndTransformFeedbackEXT, 5, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    glad_vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    _post_call_vulkan_callback(NULL, "vkCmdEndTransformFeedbackEXT", (GLADapiproc) glad_vkCmdEndTransformFeedbackEXT, 5, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
    
}
PFN_vkCmdEndTransformFeedbackEXT glad_debug_vkCmdEndTransformFeedbackEXT = glad_debug_impl_vkCmdEndTransformFeedbackEXT;
PFN_vkCmdExecuteCommands glad_vkCmdExecuteCommands = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer * pCommandBuffers) {
    _pre_call_vulkan_callback("vkCmdExecuteCommands", (GLADapiproc) glad_vkCmdExecuteCommands, 3, commandBuffer, commandBufferCount, pCommandBuffers);
    glad_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    _post_call_vulkan_callback(NULL, "vkCmdExecuteCommands", (GLADapiproc) glad_vkCmdExecuteCommands, 3, commandBuffer, commandBufferCount, pCommandBuffers);
    
}
PFN_vkCmdExecuteCommands glad_debug_vkCmdExecuteCommands = glad_debug_impl_vkCmdExecuteCommands;
PFN_vkCmdFillBuffer glad_vkCmdFillBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
    _pre_call_vulkan_callback("vkCmdFillBuffer", (GLADapiproc) glad_vkCmdFillBuffer, 5, commandBuffer, dstBuffer, dstOffset, size, data);
    glad_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    _post_call_vulkan_callback(NULL, "vkCmdFillBuffer", (GLADapiproc) glad_vkCmdFillBuffer, 5, commandBuffer, dstBuffer, dstOffset, size, data);
    
}
PFN_vkCmdFillBuffer glad_debug_vkCmdFillBuffer = glad_debug_impl_vkCmdFillBuffer;
PFN_vkCmdInsertDebugUtilsLabelEXT glad_vkCmdInsertDebugUtilsLabelEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT * pLabelInfo) {
    _pre_call_vulkan_callback("vkCmdInsertDebugUtilsLabelEXT", (GLADapiproc) glad_vkCmdInsertDebugUtilsLabelEXT, 2, commandBuffer, pLabelInfo);
    glad_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    _post_call_vulkan_callback(NULL, "vkCmdInsertDebugUtilsLabelEXT", (GLADapiproc) glad_vkCmdInsertDebugUtilsLabelEXT, 2, commandBuffer, pLabelInfo);
    
}
PFN_vkCmdInsertDebugUtilsLabelEXT glad_debug_vkCmdInsertDebugUtilsLabelEXT = glad_debug_impl_vkCmdInsertDebugUtilsLabelEXT;
PFN_vkCmdNextSubpass glad_vkCmdNextSubpass = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    _pre_call_vulkan_callback("vkCmdNextSubpass", (GLADapiproc) glad_vkCmdNextSubpass, 2, commandBuffer, contents);
    glad_vkCmdNextSubpass(commandBuffer, contents);
    _post_call_vulkan_callback(NULL, "vkCmdNextSubpass", (GLADapiproc) glad_vkCmdNextSubpass, 2, commandBuffer, contents);
    
}
PFN_vkCmdNextSubpass glad_debug_vkCmdNextSubpass = glad_debug_impl_vkCmdNextSubpass;
PFN_vkCmdNextSubpass2 glad_vkCmdNextSubpass2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo * pSubpassBeginInfo, const VkSubpassEndInfo * pSubpassEndInfo) {
    _pre_call_vulkan_callback("vkCmdNextSubpass2", (GLADapiproc) glad_vkCmdNextSubpass2, 3, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    glad_vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    _post_call_vulkan_callback(NULL, "vkCmdNextSubpass2", (GLADapiproc) glad_vkCmdNextSubpass2, 3, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    
}
PFN_vkCmdNextSubpass2 glad_debug_vkCmdNextSubpass2 = glad_debug_impl_vkCmdNextSubpass2;
PFN_vkCmdNextSubpass2KHR glad_vkCmdNextSubpass2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo * pSubpassBeginInfo, const VkSubpassEndInfo * pSubpassEndInfo) {
    _pre_call_vulkan_callback("vkCmdNextSubpass2KHR", (GLADapiproc) glad_vkCmdNextSubpass2KHR, 3, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    glad_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    _post_call_vulkan_callback(NULL, "vkCmdNextSubpass2KHR", (GLADapiproc) glad_vkCmdNextSubpass2KHR, 3, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    
}
PFN_vkCmdNextSubpass2KHR glad_debug_vkCmdNextSubpass2KHR = glad_debug_impl_vkCmdNextSubpass2KHR;
PFN_vkCmdPipelineBarrier glad_vkCmdPipelineBarrier = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier * pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier * pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier * pImageMemoryBarriers) {
    _pre_call_vulkan_callback("vkCmdPipelineBarrier", (GLADapiproc) glad_vkCmdPipelineBarrier, 10, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    glad_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    _post_call_vulkan_callback(NULL, "vkCmdPipelineBarrier", (GLADapiproc) glad_vkCmdPipelineBarrier, 10, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    
}
PFN_vkCmdPipelineBarrier glad_debug_vkCmdPipelineBarrier = glad_debug_impl_vkCmdPipelineBarrier;
PFN_vkCmdPushConstants glad_vkCmdPushConstants = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void * pValues) {
    _pre_call_vulkan_callback("vkCmdPushConstants", (GLADapiproc) glad_vkCmdPushConstants, 6, commandBuffer, layout, stageFlags, offset, size, pValues);
    glad_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    _post_call_vulkan_callback(NULL, "vkCmdPushConstants", (GLADapiproc) glad_vkCmdPushConstants, 6, commandBuffer, layout, stageFlags, offset, size, pValues);
    
}
PFN_vkCmdPushConstants glad_debug_vkCmdPushConstants = glad_debug_impl_vkCmdPushConstants;
PFN_vkCmdPushDescriptorSetKHR glad_vkCmdPushDescriptorSetKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet * pDescriptorWrites) {
    _pre_call_vulkan_callback("vkCmdPushDescriptorSetKHR", (GLADapiproc) glad_vkCmdPushDescriptorSetKHR, 6, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    glad_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    _post_call_vulkan_callback(NULL, "vkCmdPushDescriptorSetKHR", (GLADapiproc) glad_vkCmdPushDescriptorSetKHR, 6, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    
}
PFN_vkCmdPushDescriptorSetKHR glad_debug_vkCmdPushDescriptorSetKHR = glad_debug_impl_vkCmdPushDescriptorSetKHR;
PFN_vkCmdPushDescriptorSetWithTemplateKHR glad_vkCmdPushDescriptorSetWithTemplateKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void * pData) {
    _pre_call_vulkan_callback("vkCmdPushDescriptorSetWithTemplateKHR", (GLADapiproc) glad_vkCmdPushDescriptorSetWithTemplateKHR, 5, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    glad_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    _post_call_vulkan_callback(NULL, "vkCmdPushDescriptorSetWithTemplateKHR", (GLADapiproc) glad_vkCmdPushDescriptorSetWithTemplateKHR, 5, commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    
}
PFN_vkCmdPushDescriptorSetWithTemplateKHR glad_debug_vkCmdPushDescriptorSetWithTemplateKHR = glad_debug_impl_vkCmdPushDescriptorSetWithTemplateKHR;
PFN_vkCmdResetEvent glad_vkCmdResetEvent = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    _pre_call_vulkan_callback("vkCmdResetEvent", (GLADapiproc) glad_vkCmdResetEvent, 3, commandBuffer, event, stageMask);
    glad_vkCmdResetEvent(commandBuffer, event, stageMask);
    _post_call_vulkan_callback(NULL, "vkCmdResetEvent", (GLADapiproc) glad_vkCmdResetEvent, 3, commandBuffer, event, stageMask);
    
}
PFN_vkCmdResetEvent glad_debug_vkCmdResetEvent = glad_debug_impl_vkCmdResetEvent;
PFN_vkCmdResetQueryPool glad_vkCmdResetQueryPool = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    _pre_call_vulkan_callback("vkCmdResetQueryPool", (GLADapiproc) glad_vkCmdResetQueryPool, 4, commandBuffer, queryPool, firstQuery, queryCount);
    glad_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    _post_call_vulkan_callback(NULL, "vkCmdResetQueryPool", (GLADapiproc) glad_vkCmdResetQueryPool, 4, commandBuffer, queryPool, firstQuery, queryCount);
    
}
PFN_vkCmdResetQueryPool glad_debug_vkCmdResetQueryPool = glad_debug_impl_vkCmdResetQueryPool;
PFN_vkCmdResolveImage glad_vkCmdResolveImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve * pRegions) {
    _pre_call_vulkan_callback("vkCmdResolveImage", (GLADapiproc) glad_vkCmdResolveImage, 7, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    glad_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    _post_call_vulkan_callback(NULL, "vkCmdResolveImage", (GLADapiproc) glad_vkCmdResolveImage, 7, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    
}
PFN_vkCmdResolveImage glad_debug_vkCmdResolveImage = glad_debug_impl_vkCmdResolveImage;
PFN_vkCmdSetBlendConstants glad_vkCmdSetBlendConstants = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants [4]) {
    _pre_call_vulkan_callback("vkCmdSetBlendConstants", (GLADapiproc) glad_vkCmdSetBlendConstants, 2, commandBuffer, blendConstants);
    glad_vkCmdSetBlendConstants(commandBuffer, blendConstants);
    _post_call_vulkan_callback(NULL, "vkCmdSetBlendConstants", (GLADapiproc) glad_vkCmdSetBlendConstants, 2, commandBuffer, blendConstants);
    
}
PFN_vkCmdSetBlendConstants glad_debug_vkCmdSetBlendConstants = glad_debug_impl_vkCmdSetBlendConstants;
PFN_vkCmdSetCullModeEXT glad_vkCmdSetCullModeEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    _pre_call_vulkan_callback("vkCmdSetCullModeEXT", (GLADapiproc) glad_vkCmdSetCullModeEXT, 2, commandBuffer, cullMode);
    glad_vkCmdSetCullModeEXT(commandBuffer, cullMode);
    _post_call_vulkan_callback(NULL, "vkCmdSetCullModeEXT", (GLADapiproc) glad_vkCmdSetCullModeEXT, 2, commandBuffer, cullMode);
    
}
PFN_vkCmdSetCullModeEXT glad_debug_vkCmdSetCullModeEXT = glad_debug_impl_vkCmdSetCullModeEXT;
PFN_vkCmdSetDepthBias glad_vkCmdSetDepthBias = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) {
    _pre_call_vulkan_callback("vkCmdSetDepthBias", (GLADapiproc) glad_vkCmdSetDepthBias, 4, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    glad_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    _post_call_vulkan_callback(NULL, "vkCmdSetDepthBias", (GLADapiproc) glad_vkCmdSetDepthBias, 4, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    
}
PFN_vkCmdSetDepthBias glad_debug_vkCmdSetDepthBias = glad_debug_impl_vkCmdSetDepthBias;
PFN_vkCmdSetDepthBounds glad_vkCmdSetDepthBounds = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    _pre_call_vulkan_callback("vkCmdSetDepthBounds", (GLADapiproc) glad_vkCmdSetDepthBounds, 3, commandBuffer, minDepthBounds, maxDepthBounds);
    glad_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    _post_call_vulkan_callback(NULL, "vkCmdSetDepthBounds", (GLADapiproc) glad_vkCmdSetDepthBounds, 3, commandBuffer, minDepthBounds, maxDepthBounds);
    
}
PFN_vkCmdSetDepthBounds glad_debug_vkCmdSetDepthBounds = glad_debug_impl_vkCmdSetDepthBounds;
PFN_vkCmdSetDepthBoundsTestEnableEXT glad_vkCmdSetDepthBoundsTestEnableEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    _pre_call_vulkan_callback("vkCmdSetDepthBoundsTestEnableEXT", (GLADapiproc) glad_vkCmdSetDepthBoundsTestEnableEXT, 2, commandBuffer, depthBoundsTestEnable);
    glad_vkCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
    _post_call_vulkan_callback(NULL, "vkCmdSetDepthBoundsTestEnableEXT", (GLADapiproc) glad_vkCmdSetDepthBoundsTestEnableEXT, 2, commandBuffer, depthBoundsTestEnable);
    
}
PFN_vkCmdSetDepthBoundsTestEnableEXT glad_debug_vkCmdSetDepthBoundsTestEnableEXT = glad_debug_impl_vkCmdSetDepthBoundsTestEnableEXT;
PFN_vkCmdSetDepthCompareOpEXT glad_vkCmdSetDepthCompareOpEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    _pre_call_vulkan_callback("vkCmdSetDepthCompareOpEXT", (GLADapiproc) glad_vkCmdSetDepthCompareOpEXT, 2, commandBuffer, depthCompareOp);
    glad_vkCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
    _post_call_vulkan_callback(NULL, "vkCmdSetDepthCompareOpEXT", (GLADapiproc) glad_vkCmdSetDepthCompareOpEXT, 2, commandBuffer, depthCompareOp);
    
}
PFN_vkCmdSetDepthCompareOpEXT glad_debug_vkCmdSetDepthCompareOpEXT = glad_debug_impl_vkCmdSetDepthCompareOpEXT;
PFN_vkCmdSetDepthTestEnableEXT glad_vkCmdSetDepthTestEnableEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    _pre_call_vulkan_callback("vkCmdSetDepthTestEnableEXT", (GLADapiproc) glad_vkCmdSetDepthTestEnableEXT, 2, commandBuffer, depthTestEnable);
    glad_vkCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
    _post_call_vulkan_callback(NULL, "vkCmdSetDepthTestEnableEXT", (GLADapiproc) glad_vkCmdSetDepthTestEnableEXT, 2, commandBuffer, depthTestEnable);
    
}
PFN_vkCmdSetDepthTestEnableEXT glad_debug_vkCmdSetDepthTestEnableEXT = glad_debug_impl_vkCmdSetDepthTestEnableEXT;
PFN_vkCmdSetDepthWriteEnableEXT glad_vkCmdSetDepthWriteEnableEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    _pre_call_vulkan_callback("vkCmdSetDepthWriteEnableEXT", (GLADapiproc) glad_vkCmdSetDepthWriteEnableEXT, 2, commandBuffer, depthWriteEnable);
    glad_vkCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
    _post_call_vulkan_callback(NULL, "vkCmdSetDepthWriteEnableEXT", (GLADapiproc) glad_vkCmdSetDepthWriteEnableEXT, 2, commandBuffer, depthWriteEnable);
    
}
PFN_vkCmdSetDepthWriteEnableEXT glad_debug_vkCmdSetDepthWriteEnableEXT = glad_debug_impl_vkCmdSetDepthWriteEnableEXT;
PFN_vkCmdSetDeviceMask glad_vkCmdSetDeviceMask = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    _pre_call_vulkan_callback("vkCmdSetDeviceMask", (GLADapiproc) glad_vkCmdSetDeviceMask, 2, commandBuffer, deviceMask);
    glad_vkCmdSetDeviceMask(commandBuffer, deviceMask);
    _post_call_vulkan_callback(NULL, "vkCmdSetDeviceMask", (GLADapiproc) glad_vkCmdSetDeviceMask, 2, commandBuffer, deviceMask);
    
}
PFN_vkCmdSetDeviceMask glad_debug_vkCmdSetDeviceMask = glad_debug_impl_vkCmdSetDeviceMask;
PFN_vkCmdSetDeviceMaskKHR glad_vkCmdSetDeviceMaskKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    _pre_call_vulkan_callback("vkCmdSetDeviceMaskKHR", (GLADapiproc) glad_vkCmdSetDeviceMaskKHR, 2, commandBuffer, deviceMask);
    glad_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    _post_call_vulkan_callback(NULL, "vkCmdSetDeviceMaskKHR", (GLADapiproc) glad_vkCmdSetDeviceMaskKHR, 2, commandBuffer, deviceMask);
    
}
PFN_vkCmdSetDeviceMaskKHR glad_debug_vkCmdSetDeviceMaskKHR = glad_debug_impl_vkCmdSetDeviceMaskKHR;
PFN_vkCmdSetDiscardRectangleEXT glad_vkCmdSetDiscardRectangleEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D * pDiscardRectangles) {
    _pre_call_vulkan_callback("vkCmdSetDiscardRectangleEXT", (GLADapiproc) glad_vkCmdSetDiscardRectangleEXT, 4, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    glad_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    _post_call_vulkan_callback(NULL, "vkCmdSetDiscardRectangleEXT", (GLADapiproc) glad_vkCmdSetDiscardRectangleEXT, 4, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    
}
PFN_vkCmdSetDiscardRectangleEXT glad_debug_vkCmdSetDiscardRectangleEXT = glad_debug_impl_vkCmdSetDiscardRectangleEXT;
PFN_vkCmdSetEvent glad_vkCmdSetEvent = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    _pre_call_vulkan_callback("vkCmdSetEvent", (GLADapiproc) glad_vkCmdSetEvent, 3, commandBuffer, event, stageMask);
    glad_vkCmdSetEvent(commandBuffer, event, stageMask);
    _post_call_vulkan_callback(NULL, "vkCmdSetEvent", (GLADapiproc) glad_vkCmdSetEvent, 3, commandBuffer, event, stageMask);
    
}
PFN_vkCmdSetEvent glad_debug_vkCmdSetEvent = glad_debug_impl_vkCmdSetEvent;
PFN_vkCmdSetFrontFaceEXT glad_vkCmdSetFrontFaceEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    _pre_call_vulkan_callback("vkCmdSetFrontFaceEXT", (GLADapiproc) glad_vkCmdSetFrontFaceEXT, 2, commandBuffer, frontFace);
    glad_vkCmdSetFrontFaceEXT(commandBuffer, frontFace);
    _post_call_vulkan_callback(NULL, "vkCmdSetFrontFaceEXT", (GLADapiproc) glad_vkCmdSetFrontFaceEXT, 2, commandBuffer, frontFace);
    
}
PFN_vkCmdSetFrontFaceEXT glad_debug_vkCmdSetFrontFaceEXT = glad_debug_impl_vkCmdSetFrontFaceEXT;
PFN_vkCmdSetLineStippleEXT glad_vkCmdSetLineStippleEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    _pre_call_vulkan_callback("vkCmdSetLineStippleEXT", (GLADapiproc) glad_vkCmdSetLineStippleEXT, 3, commandBuffer, lineStippleFactor, lineStipplePattern);
    glad_vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
    _post_call_vulkan_callback(NULL, "vkCmdSetLineStippleEXT", (GLADapiproc) glad_vkCmdSetLineStippleEXT, 3, commandBuffer, lineStippleFactor, lineStipplePattern);
    
}
PFN_vkCmdSetLineStippleEXT glad_debug_vkCmdSetLineStippleEXT = glad_debug_impl_vkCmdSetLineStippleEXT;
PFN_vkCmdSetLineWidth glad_vkCmdSetLineWidth = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    _pre_call_vulkan_callback("vkCmdSetLineWidth", (GLADapiproc) glad_vkCmdSetLineWidth, 2, commandBuffer, lineWidth);
    glad_vkCmdSetLineWidth(commandBuffer, lineWidth);
    _post_call_vulkan_callback(NULL, "vkCmdSetLineWidth", (GLADapiproc) glad_vkCmdSetLineWidth, 2, commandBuffer, lineWidth);
    
}
PFN_vkCmdSetLineWidth glad_debug_vkCmdSetLineWidth = glad_debug_impl_vkCmdSetLineWidth;
PFN_vkCmdSetPrimitiveTopologyEXT glad_vkCmdSetPrimitiveTopologyEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    _pre_call_vulkan_callback("vkCmdSetPrimitiveTopologyEXT", (GLADapiproc) glad_vkCmdSetPrimitiveTopologyEXT, 2, commandBuffer, primitiveTopology);
    glad_vkCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
    _post_call_vulkan_callback(NULL, "vkCmdSetPrimitiveTopologyEXT", (GLADapiproc) glad_vkCmdSetPrimitiveTopologyEXT, 2, commandBuffer, primitiveTopology);
    
}
PFN_vkCmdSetPrimitiveTopologyEXT glad_debug_vkCmdSetPrimitiveTopologyEXT = glad_debug_impl_vkCmdSetPrimitiveTopologyEXT;
PFN_vkCmdSetSampleLocationsEXT glad_vkCmdSetSampleLocationsEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT * pSampleLocationsInfo) {
    _pre_call_vulkan_callback("vkCmdSetSampleLocationsEXT", (GLADapiproc) glad_vkCmdSetSampleLocationsEXT, 2, commandBuffer, pSampleLocationsInfo);
    glad_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    _post_call_vulkan_callback(NULL, "vkCmdSetSampleLocationsEXT", (GLADapiproc) glad_vkCmdSetSampleLocationsEXT, 2, commandBuffer, pSampleLocationsInfo);
    
}
PFN_vkCmdSetSampleLocationsEXT glad_debug_vkCmdSetSampleLocationsEXT = glad_debug_impl_vkCmdSetSampleLocationsEXT;
PFN_vkCmdSetScissor glad_vkCmdSetScissor = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D * pScissors) {
    _pre_call_vulkan_callback("vkCmdSetScissor", (GLADapiproc) glad_vkCmdSetScissor, 4, commandBuffer, firstScissor, scissorCount, pScissors);
    glad_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    _post_call_vulkan_callback(NULL, "vkCmdSetScissor", (GLADapiproc) glad_vkCmdSetScissor, 4, commandBuffer, firstScissor, scissorCount, pScissors);
    
}
PFN_vkCmdSetScissor glad_debug_vkCmdSetScissor = glad_debug_impl_vkCmdSetScissor;
PFN_vkCmdSetScissorWithCountEXT glad_vkCmdSetScissorWithCountEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D * pScissors) {
    _pre_call_vulkan_callback("vkCmdSetScissorWithCountEXT", (GLADapiproc) glad_vkCmdSetScissorWithCountEXT, 3, commandBuffer, scissorCount, pScissors);
    glad_vkCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
    _post_call_vulkan_callback(NULL, "vkCmdSetScissorWithCountEXT", (GLADapiproc) glad_vkCmdSetScissorWithCountEXT, 3, commandBuffer, scissorCount, pScissors);
    
}
PFN_vkCmdSetScissorWithCountEXT glad_debug_vkCmdSetScissorWithCountEXT = glad_debug_impl_vkCmdSetScissorWithCountEXT;
PFN_vkCmdSetStencilCompareMask glad_vkCmdSetStencilCompareMask = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) {
    _pre_call_vulkan_callback("vkCmdSetStencilCompareMask", (GLADapiproc) glad_vkCmdSetStencilCompareMask, 3, commandBuffer, faceMask, compareMask);
    glad_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    _post_call_vulkan_callback(NULL, "vkCmdSetStencilCompareMask", (GLADapiproc) glad_vkCmdSetStencilCompareMask, 3, commandBuffer, faceMask, compareMask);
    
}
PFN_vkCmdSetStencilCompareMask glad_debug_vkCmdSetStencilCompareMask = glad_debug_impl_vkCmdSetStencilCompareMask;
PFN_vkCmdSetStencilOpEXT glad_vkCmdSetStencilOpEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    _pre_call_vulkan_callback("vkCmdSetStencilOpEXT", (GLADapiproc) glad_vkCmdSetStencilOpEXT, 6, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    glad_vkCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    _post_call_vulkan_callback(NULL, "vkCmdSetStencilOpEXT", (GLADapiproc) glad_vkCmdSetStencilOpEXT, 6, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
    
}
PFN_vkCmdSetStencilOpEXT glad_debug_vkCmdSetStencilOpEXT = glad_debug_impl_vkCmdSetStencilOpEXT;
PFN_vkCmdSetStencilReference glad_vkCmdSetStencilReference = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
    _pre_call_vulkan_callback("vkCmdSetStencilReference", (GLADapiproc) glad_vkCmdSetStencilReference, 3, commandBuffer, faceMask, reference);
    glad_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    _post_call_vulkan_callback(NULL, "vkCmdSetStencilReference", (GLADapiproc) glad_vkCmdSetStencilReference, 3, commandBuffer, faceMask, reference);
    
}
PFN_vkCmdSetStencilReference glad_debug_vkCmdSetStencilReference = glad_debug_impl_vkCmdSetStencilReference;
PFN_vkCmdSetStencilTestEnableEXT glad_vkCmdSetStencilTestEnableEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    _pre_call_vulkan_callback("vkCmdSetStencilTestEnableEXT", (GLADapiproc) glad_vkCmdSetStencilTestEnableEXT, 2, commandBuffer, stencilTestEnable);
    glad_vkCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
    _post_call_vulkan_callback(NULL, "vkCmdSetStencilTestEnableEXT", (GLADapiproc) glad_vkCmdSetStencilTestEnableEXT, 2, commandBuffer, stencilTestEnable);
    
}
PFN_vkCmdSetStencilTestEnableEXT glad_debug_vkCmdSetStencilTestEnableEXT = glad_debug_impl_vkCmdSetStencilTestEnableEXT;
PFN_vkCmdSetStencilWriteMask glad_vkCmdSetStencilWriteMask = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
    _pre_call_vulkan_callback("vkCmdSetStencilWriteMask", (GLADapiproc) glad_vkCmdSetStencilWriteMask, 3, commandBuffer, faceMask, writeMask);
    glad_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    _post_call_vulkan_callback(NULL, "vkCmdSetStencilWriteMask", (GLADapiproc) glad_vkCmdSetStencilWriteMask, 3, commandBuffer, faceMask, writeMask);
    
}
PFN_vkCmdSetStencilWriteMask glad_debug_vkCmdSetStencilWriteMask = glad_debug_impl_vkCmdSetStencilWriteMask;
PFN_vkCmdSetViewport glad_vkCmdSetViewport = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport * pViewports) {
    _pre_call_vulkan_callback("vkCmdSetViewport", (GLADapiproc) glad_vkCmdSetViewport, 4, commandBuffer, firstViewport, viewportCount, pViewports);
    glad_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    _post_call_vulkan_callback(NULL, "vkCmdSetViewport", (GLADapiproc) glad_vkCmdSetViewport, 4, commandBuffer, firstViewport, viewportCount, pViewports);
    
}
PFN_vkCmdSetViewport glad_debug_vkCmdSetViewport = glad_debug_impl_vkCmdSetViewport;
PFN_vkCmdSetViewportWithCountEXT glad_vkCmdSetViewportWithCountEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport * pViewports) {
    _pre_call_vulkan_callback("vkCmdSetViewportWithCountEXT", (GLADapiproc) glad_vkCmdSetViewportWithCountEXT, 3, commandBuffer, viewportCount, pViewports);
    glad_vkCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
    _post_call_vulkan_callback(NULL, "vkCmdSetViewportWithCountEXT", (GLADapiproc) glad_vkCmdSetViewportWithCountEXT, 3, commandBuffer, viewportCount, pViewports);
    
}
PFN_vkCmdSetViewportWithCountEXT glad_debug_vkCmdSetViewportWithCountEXT = glad_debug_impl_vkCmdSetViewportWithCountEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdTraceRaysIndirectKHR glad_vkCmdTraceRaysIndirectKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedBufferRegionKHR * pRaygenShaderBindingTable, const VkStridedBufferRegionKHR * pMissShaderBindingTable, const VkStridedBufferRegionKHR * pHitShaderBindingTable, const VkStridedBufferRegionKHR * pCallableShaderBindingTable, VkBuffer buffer, VkDeviceSize offset) {
    _pre_call_vulkan_callback("vkCmdTraceRaysIndirectKHR", (GLADapiproc) glad_vkCmdTraceRaysIndirectKHR, 7, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer, offset);
    glad_vkCmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer, offset);
    _post_call_vulkan_callback(NULL, "vkCmdTraceRaysIndirectKHR", (GLADapiproc) glad_vkCmdTraceRaysIndirectKHR, 7, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, buffer, offset);
    
}
PFN_vkCmdTraceRaysIndirectKHR glad_debug_vkCmdTraceRaysIndirectKHR = glad_debug_impl_vkCmdTraceRaysIndirectKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdTraceRaysKHR glad_vkCmdTraceRaysKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedBufferRegionKHR * pRaygenShaderBindingTable, const VkStridedBufferRegionKHR * pMissShaderBindingTable, const VkStridedBufferRegionKHR * pHitShaderBindingTable, const VkStridedBufferRegionKHR * pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) {
    _pre_call_vulkan_callback("vkCmdTraceRaysKHR", (GLADapiproc) glad_vkCmdTraceRaysKHR, 8, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    glad_vkCmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    _post_call_vulkan_callback(NULL, "vkCmdTraceRaysKHR", (GLADapiproc) glad_vkCmdTraceRaysKHR, 8, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    
}
PFN_vkCmdTraceRaysKHR glad_debug_vkCmdTraceRaysKHR = glad_debug_impl_vkCmdTraceRaysKHR;
#endif
PFN_vkCmdUpdateBuffer glad_vkCmdUpdateBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void * pData) {
    _pre_call_vulkan_callback("vkCmdUpdateBuffer", (GLADapiproc) glad_vkCmdUpdateBuffer, 5, commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    glad_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    _post_call_vulkan_callback(NULL, "vkCmdUpdateBuffer", (GLADapiproc) glad_vkCmdUpdateBuffer, 5, commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    
}
PFN_vkCmdUpdateBuffer glad_debug_vkCmdUpdateBuffer = glad_debug_impl_vkCmdUpdateBuffer;
PFN_vkCmdWaitEvents glad_vkCmdWaitEvents = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent * pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier * pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier * pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier * pImageMemoryBarriers) {
    _pre_call_vulkan_callback("vkCmdWaitEvents", (GLADapiproc) glad_vkCmdWaitEvents, 11, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    glad_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    _post_call_vulkan_callback(NULL, "vkCmdWaitEvents", (GLADapiproc) glad_vkCmdWaitEvents, 11, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    
}
PFN_vkCmdWaitEvents glad_debug_vkCmdWaitEvents = glad_debug_impl_vkCmdWaitEvents;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCmdWriteAccelerationStructuresPropertiesKHR glad_vkCmdWriteAccelerationStructuresPropertiesKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR * pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    _pre_call_vulkan_callback("vkCmdWriteAccelerationStructuresPropertiesKHR", (GLADapiproc) glad_vkCmdWriteAccelerationStructuresPropertiesKHR, 6, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    glad_vkCmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    _post_call_vulkan_callback(NULL, "vkCmdWriteAccelerationStructuresPropertiesKHR", (GLADapiproc) glad_vkCmdWriteAccelerationStructuresPropertiesKHR, 6, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    
}
PFN_vkCmdWriteAccelerationStructuresPropertiesKHR glad_debug_vkCmdWriteAccelerationStructuresPropertiesKHR = glad_debug_impl_vkCmdWriteAccelerationStructuresPropertiesKHR;
#endif
PFN_vkCmdWriteTimestamp glad_vkCmdWriteTimestamp = NULL;
static void GLAD_API_PTR glad_debug_impl_vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) {
    _pre_call_vulkan_callback("vkCmdWriteTimestamp", (GLADapiproc) glad_vkCmdWriteTimestamp, 4, commandBuffer, pipelineStage, queryPool, query);
    glad_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    _post_call_vulkan_callback(NULL, "vkCmdWriteTimestamp", (GLADapiproc) glad_vkCmdWriteTimestamp, 4, commandBuffer, pipelineStage, queryPool, query);
    
}
PFN_vkCmdWriteTimestamp glad_debug_vkCmdWriteTimestamp = glad_debug_impl_vkCmdWriteTimestamp;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCopyAccelerationStructureKHR glad_vkCopyAccelerationStructureKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCopyAccelerationStructureKHR(VkDevice device, const VkCopyAccelerationStructureInfoKHR * pInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCopyAccelerationStructureKHR", (GLADapiproc) glad_vkCopyAccelerationStructureKHR, 2, device, pInfo);
    ret = glad_vkCopyAccelerationStructureKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkCopyAccelerationStructureKHR", (GLADapiproc) glad_vkCopyAccelerationStructureKHR, 2, device, pInfo);
    return ret;
}
PFN_vkCopyAccelerationStructureKHR glad_debug_vkCopyAccelerationStructureKHR = glad_debug_impl_vkCopyAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCopyAccelerationStructureToMemoryKHR glad_vkCopyAccelerationStructureToMemoryKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCopyAccelerationStructureToMemoryKHR(VkDevice device, const VkCopyAccelerationStructureToMemoryInfoKHR * pInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCopyAccelerationStructureToMemoryKHR", (GLADapiproc) glad_vkCopyAccelerationStructureToMemoryKHR, 2, device, pInfo);
    ret = glad_vkCopyAccelerationStructureToMemoryKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkCopyAccelerationStructureToMemoryKHR", (GLADapiproc) glad_vkCopyAccelerationStructureToMemoryKHR, 2, device, pInfo);
    return ret;
}
PFN_vkCopyAccelerationStructureToMemoryKHR glad_debug_vkCopyAccelerationStructureToMemoryKHR = glad_debug_impl_vkCopyAccelerationStructureToMemoryKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCopyMemoryToAccelerationStructureKHR glad_vkCopyMemoryToAccelerationStructureKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCopyMemoryToAccelerationStructureKHR(VkDevice device, const VkCopyMemoryToAccelerationStructureInfoKHR * pInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCopyMemoryToAccelerationStructureKHR", (GLADapiproc) glad_vkCopyMemoryToAccelerationStructureKHR, 2, device, pInfo);
    ret = glad_vkCopyMemoryToAccelerationStructureKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkCopyMemoryToAccelerationStructureKHR", (GLADapiproc) glad_vkCopyMemoryToAccelerationStructureKHR, 2, device, pInfo);
    return ret;
}
PFN_vkCopyMemoryToAccelerationStructureKHR glad_debug_vkCopyMemoryToAccelerationStructureKHR = glad_debug_impl_vkCopyMemoryToAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCreateAccelerationStructureKHR glad_vkCreateAccelerationStructureKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkAccelerationStructureKHR * pAccelerationStructure) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateAccelerationStructureKHR", (GLADapiproc) glad_vkCreateAccelerationStructureKHR, 4, device, pCreateInfo, pAllocator, pAccelerationStructure);
    ret = glad_vkCreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    _post_call_vulkan_callback((void*) &ret, "vkCreateAccelerationStructureKHR", (GLADapiproc) glad_vkCreateAccelerationStructureKHR, 4, device, pCreateInfo, pAllocator, pAccelerationStructure);
    return ret;
}
PFN_vkCreateAccelerationStructureKHR glad_debug_vkCreateAccelerationStructureKHR = glad_debug_impl_vkCreateAccelerationStructureKHR;
#endif
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
PFN_vkCreateAndroidSurfaceKHR glad_vkCreateAndroidSurfaceKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateAndroidSurfaceKHR", (GLADapiproc) glad_vkCreateAndroidSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateAndroidSurfaceKHR", (GLADapiproc) glad_vkCreateAndroidSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateAndroidSurfaceKHR glad_debug_vkCreateAndroidSurfaceKHR = glad_debug_impl_vkCreateAndroidSurfaceKHR;
#endif
PFN_vkCreateBuffer glad_vkCreateBuffer = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateBuffer(VkDevice device, const VkBufferCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkBuffer * pBuffer) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateBuffer", (GLADapiproc) glad_vkCreateBuffer, 4, device, pCreateInfo, pAllocator, pBuffer);
    ret = glad_vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    _post_call_vulkan_callback((void*) &ret, "vkCreateBuffer", (GLADapiproc) glad_vkCreateBuffer, 4, device, pCreateInfo, pAllocator, pBuffer);
    return ret;
}
PFN_vkCreateBuffer glad_debug_vkCreateBuffer = glad_debug_impl_vkCreateBuffer;
PFN_vkCreateBufferView glad_vkCreateBufferView = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkBufferView * pView) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateBufferView", (GLADapiproc) glad_vkCreateBufferView, 4, device, pCreateInfo, pAllocator, pView);
    ret = glad_vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
    _post_call_vulkan_callback((void*) &ret, "vkCreateBufferView", (GLADapiproc) glad_vkCreateBufferView, 4, device, pCreateInfo, pAllocator, pView);
    return ret;
}
PFN_vkCreateBufferView glad_debug_vkCreateBufferView = glad_debug_impl_vkCreateBufferView;
PFN_vkCreateCommandPool glad_vkCreateCommandPool = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkCommandPool * pCommandPool) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateCommandPool", (GLADapiproc) glad_vkCreateCommandPool, 4, device, pCreateInfo, pAllocator, pCommandPool);
    ret = glad_vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    _post_call_vulkan_callback((void*) &ret, "vkCreateCommandPool", (GLADapiproc) glad_vkCreateCommandPool, 4, device, pCreateInfo, pAllocator, pCommandPool);
    return ret;
}
PFN_vkCreateCommandPool glad_debug_vkCreateCommandPool = glad_debug_impl_vkCreateCommandPool;
PFN_vkCreateComputePipelines glad_vkCreateComputePipelines = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkPipeline * pPipelines) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateComputePipelines", (GLADapiproc) glad_vkCreateComputePipelines, 6, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    ret = glad_vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    _post_call_vulkan_callback((void*) &ret, "vkCreateComputePipelines", (GLADapiproc) glad_vkCreateComputePipelines, 6, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return ret;
}
PFN_vkCreateComputePipelines glad_debug_vkCreateComputePipelines = glad_debug_impl_vkCreateComputePipelines;
PFN_vkCreateDebugReportCallbackEXT glad_vkCreateDebugReportCallbackEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugReportCallbackEXT * pCallback) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDebugReportCallbackEXT", (GLADapiproc) glad_vkCreateDebugReportCallbackEXT, 4, instance, pCreateInfo, pAllocator, pCallback);
    ret = glad_vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDebugReportCallbackEXT", (GLADapiproc) glad_vkCreateDebugReportCallbackEXT, 4, instance, pCreateInfo, pAllocator, pCallback);
    return ret;
}
PFN_vkCreateDebugReportCallbackEXT glad_debug_vkCreateDebugReportCallbackEXT = glad_debug_impl_vkCreateDebugReportCallbackEXT;
PFN_vkCreateDebugUtilsMessengerEXT glad_vkCreateDebugUtilsMessengerEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugUtilsMessengerEXT * pMessenger) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDebugUtilsMessengerEXT", (GLADapiproc) glad_vkCreateDebugUtilsMessengerEXT, 4, instance, pCreateInfo, pAllocator, pMessenger);
    ret = glad_vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDebugUtilsMessengerEXT", (GLADapiproc) glad_vkCreateDebugUtilsMessengerEXT, 4, instance, pCreateInfo, pAllocator, pMessenger);
    return ret;
}
PFN_vkCreateDebugUtilsMessengerEXT glad_debug_vkCreateDebugUtilsMessengerEXT = glad_debug_impl_vkCreateDebugUtilsMessengerEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCreateDeferredOperationKHR glad_vkCreateDeferredOperationKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks * pAllocator, VkDeferredOperationKHR * pDeferredOperation) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDeferredOperationKHR", (GLADapiproc) glad_vkCreateDeferredOperationKHR, 3, device, pAllocator, pDeferredOperation);
    ret = glad_vkCreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDeferredOperationKHR", (GLADapiproc) glad_vkCreateDeferredOperationKHR, 3, device, pAllocator, pDeferredOperation);
    return ret;
}
PFN_vkCreateDeferredOperationKHR glad_debug_vkCreateDeferredOperationKHR = glad_debug_impl_vkCreateDeferredOperationKHR;
#endif
PFN_vkCreateDescriptorPool glad_vkCreateDescriptorPool = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorPool * pDescriptorPool) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDescriptorPool", (GLADapiproc) glad_vkCreateDescriptorPool, 4, device, pCreateInfo, pAllocator, pDescriptorPool);
    ret = glad_vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDescriptorPool", (GLADapiproc) glad_vkCreateDescriptorPool, 4, device, pCreateInfo, pAllocator, pDescriptorPool);
    return ret;
}
PFN_vkCreateDescriptorPool glad_debug_vkCreateDescriptorPool = glad_debug_impl_vkCreateDescriptorPool;
PFN_vkCreateDescriptorSetLayout glad_vkCreateDescriptorSetLayout = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorSetLayout * pSetLayout) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDescriptorSetLayout", (GLADapiproc) glad_vkCreateDescriptorSetLayout, 4, device, pCreateInfo, pAllocator, pSetLayout);
    ret = glad_vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDescriptorSetLayout", (GLADapiproc) glad_vkCreateDescriptorSetLayout, 4, device, pCreateInfo, pAllocator, pSetLayout);
    return ret;
}
PFN_vkCreateDescriptorSetLayout glad_debug_vkCreateDescriptorSetLayout = glad_debug_impl_vkCreateDescriptorSetLayout;
PFN_vkCreateDescriptorUpdateTemplate glad_vkCreateDescriptorUpdateTemplate = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorUpdateTemplate * pDescriptorUpdateTemplate) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDescriptorUpdateTemplate", (GLADapiproc) glad_vkCreateDescriptorUpdateTemplate, 4, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    ret = glad_vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDescriptorUpdateTemplate", (GLADapiproc) glad_vkCreateDescriptorUpdateTemplate, 4, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return ret;
}
PFN_vkCreateDescriptorUpdateTemplate glad_debug_vkCreateDescriptorUpdateTemplate = glad_debug_impl_vkCreateDescriptorUpdateTemplate;
PFN_vkCreateDescriptorUpdateTemplateKHR glad_vkCreateDescriptorUpdateTemplateKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorUpdateTemplate * pDescriptorUpdateTemplate) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDescriptorUpdateTemplateKHR", (GLADapiproc) glad_vkCreateDescriptorUpdateTemplateKHR, 4, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    ret = glad_vkCreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDescriptorUpdateTemplateKHR", (GLADapiproc) glad_vkCreateDescriptorUpdateTemplateKHR, 4, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return ret;
}
PFN_vkCreateDescriptorUpdateTemplateKHR glad_debug_vkCreateDescriptorUpdateTemplateKHR = glad_debug_impl_vkCreateDescriptorUpdateTemplateKHR;
PFN_vkCreateDevice glad_vkCreateDevice = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDevice * pDevice) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDevice", (GLADapiproc) glad_vkCreateDevice, 4, physicalDevice, pCreateInfo, pAllocator, pDevice);
    ret = glad_vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDevice", (GLADapiproc) glad_vkCreateDevice, 4, physicalDevice, pCreateInfo, pAllocator, pDevice);
    return ret;
}
PFN_vkCreateDevice glad_debug_vkCreateDevice = glad_debug_impl_vkCreateDevice;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
PFN_vkCreateDirectFBSurfaceEXT glad_vkCreateDirectFBSurfaceEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDirectFBSurfaceEXT", (GLADapiproc) glad_vkCreateDirectFBSurfaceEXT, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDirectFBSurfaceEXT", (GLADapiproc) glad_vkCreateDirectFBSurfaceEXT, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateDirectFBSurfaceEXT glad_debug_vkCreateDirectFBSurfaceEXT = glad_debug_impl_vkCreateDirectFBSurfaceEXT;
#endif
PFN_vkCreateDisplayModeKHR glad_vkCreateDisplayModeKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDisplayModeKHR * pMode) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDisplayModeKHR", (GLADapiproc) glad_vkCreateDisplayModeKHR, 5, physicalDevice, display, pCreateInfo, pAllocator, pMode);
    ret = glad_vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDisplayModeKHR", (GLADapiproc) glad_vkCreateDisplayModeKHR, 5, physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return ret;
}
PFN_vkCreateDisplayModeKHR glad_debug_vkCreateDisplayModeKHR = glad_debug_impl_vkCreateDisplayModeKHR;
PFN_vkCreateDisplayPlaneSurfaceKHR glad_vkCreateDisplayPlaneSurfaceKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateDisplayPlaneSurfaceKHR", (GLADapiproc) glad_vkCreateDisplayPlaneSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateDisplayPlaneSurfaceKHR", (GLADapiproc) glad_vkCreateDisplayPlaneSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateDisplayPlaneSurfaceKHR glad_debug_vkCreateDisplayPlaneSurfaceKHR = glad_debug_impl_vkCreateDisplayPlaneSurfaceKHR;
PFN_vkCreateEvent glad_vkCreateEvent = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateEvent(VkDevice device, const VkEventCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkEvent * pEvent) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateEvent", (GLADapiproc) glad_vkCreateEvent, 4, device, pCreateInfo, pAllocator, pEvent);
    ret = glad_vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    _post_call_vulkan_callback((void*) &ret, "vkCreateEvent", (GLADapiproc) glad_vkCreateEvent, 4, device, pCreateInfo, pAllocator, pEvent);
    return ret;
}
PFN_vkCreateEvent glad_debug_vkCreateEvent = glad_debug_impl_vkCreateEvent;
PFN_vkCreateFence glad_vkCreateFence = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateFence(VkDevice device, const VkFenceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkFence * pFence) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateFence", (GLADapiproc) glad_vkCreateFence, 4, device, pCreateInfo, pAllocator, pFence);
    ret = glad_vkCreateFence(device, pCreateInfo, pAllocator, pFence);
    _post_call_vulkan_callback((void*) &ret, "vkCreateFence", (GLADapiproc) glad_vkCreateFence, 4, device, pCreateInfo, pAllocator, pFence);
    return ret;
}
PFN_vkCreateFence glad_debug_vkCreateFence = glad_debug_impl_vkCreateFence;
PFN_vkCreateFramebuffer glad_vkCreateFramebuffer = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkFramebuffer * pFramebuffer) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateFramebuffer", (GLADapiproc) glad_vkCreateFramebuffer, 4, device, pCreateInfo, pAllocator, pFramebuffer);
    ret = glad_vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    _post_call_vulkan_callback((void*) &ret, "vkCreateFramebuffer", (GLADapiproc) glad_vkCreateFramebuffer, 4, device, pCreateInfo, pAllocator, pFramebuffer);
    return ret;
}
PFN_vkCreateFramebuffer glad_debug_vkCreateFramebuffer = glad_debug_impl_vkCreateFramebuffer;
PFN_vkCreateGraphicsPipelines glad_vkCreateGraphicsPipelines = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkPipeline * pPipelines) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateGraphicsPipelines", (GLADapiproc) glad_vkCreateGraphicsPipelines, 6, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    ret = glad_vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    _post_call_vulkan_callback((void*) &ret, "vkCreateGraphicsPipelines", (GLADapiproc) glad_vkCreateGraphicsPipelines, 6, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return ret;
}
PFN_vkCreateGraphicsPipelines glad_debug_vkCreateGraphicsPipelines = glad_debug_impl_vkCreateGraphicsPipelines;
PFN_vkCreateHeadlessSurfaceEXT glad_vkCreateHeadlessSurfaceEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateHeadlessSurfaceEXT", (GLADapiproc) glad_vkCreateHeadlessSurfaceEXT, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateHeadlessSurfaceEXT", (GLADapiproc) glad_vkCreateHeadlessSurfaceEXT, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateHeadlessSurfaceEXT glad_debug_vkCreateHeadlessSurfaceEXT = glad_debug_impl_vkCreateHeadlessSurfaceEXT;
PFN_vkCreateImage glad_vkCreateImage = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateImage(VkDevice device, const VkImageCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkImage * pImage) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateImage", (GLADapiproc) glad_vkCreateImage, 4, device, pCreateInfo, pAllocator, pImage);
    ret = glad_vkCreateImage(device, pCreateInfo, pAllocator, pImage);
    _post_call_vulkan_callback((void*) &ret, "vkCreateImage", (GLADapiproc) glad_vkCreateImage, 4, device, pCreateInfo, pAllocator, pImage);
    return ret;
}
PFN_vkCreateImage glad_debug_vkCreateImage = glad_debug_impl_vkCreateImage;
PFN_vkCreateImageView glad_vkCreateImageView = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateImageView(VkDevice device, const VkImageViewCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkImageView * pView) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateImageView", (GLADapiproc) glad_vkCreateImageView, 4, device, pCreateInfo, pAllocator, pView);
    ret = glad_vkCreateImageView(device, pCreateInfo, pAllocator, pView);
    _post_call_vulkan_callback((void*) &ret, "vkCreateImageView", (GLADapiproc) glad_vkCreateImageView, 4, device, pCreateInfo, pAllocator, pView);
    return ret;
}
PFN_vkCreateImageView glad_debug_vkCreateImageView = glad_debug_impl_vkCreateImageView;
PFN_vkCreateInstance glad_vkCreateInstance = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateInstance(const VkInstanceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkInstance * pInstance) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateInstance", (GLADapiproc) glad_vkCreateInstance, 3, pCreateInfo, pAllocator, pInstance);
    ret = glad_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    _post_call_vulkan_callback((void*) &ret, "vkCreateInstance", (GLADapiproc) glad_vkCreateInstance, 3, pCreateInfo, pAllocator, pInstance);
    return ret;
}
PFN_vkCreateInstance glad_debug_vkCreateInstance = glad_debug_impl_vkCreateInstance;
#if defined(VK_USE_PLATFORM_METAL_EXT)
PFN_vkCreateMetalSurfaceEXT glad_vkCreateMetalSurfaceEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateMetalSurfaceEXT", (GLADapiproc) glad_vkCreateMetalSurfaceEXT, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateMetalSurfaceEXT", (GLADapiproc) glad_vkCreateMetalSurfaceEXT, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateMetalSurfaceEXT glad_debug_vkCreateMetalSurfaceEXT = glad_debug_impl_vkCreateMetalSurfaceEXT;
#endif
PFN_vkCreatePipelineCache glad_vkCreatePipelineCache = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkPipelineCache * pPipelineCache) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreatePipelineCache", (GLADapiproc) glad_vkCreatePipelineCache, 4, device, pCreateInfo, pAllocator, pPipelineCache);
    ret = glad_vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    _post_call_vulkan_callback((void*) &ret, "vkCreatePipelineCache", (GLADapiproc) glad_vkCreatePipelineCache, 4, device, pCreateInfo, pAllocator, pPipelineCache);
    return ret;
}
PFN_vkCreatePipelineCache glad_debug_vkCreatePipelineCache = glad_debug_impl_vkCreatePipelineCache;
PFN_vkCreatePipelineLayout glad_vkCreatePipelineLayout = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkPipelineLayout * pPipelineLayout) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreatePipelineLayout", (GLADapiproc) glad_vkCreatePipelineLayout, 4, device, pCreateInfo, pAllocator, pPipelineLayout);
    ret = glad_vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    _post_call_vulkan_callback((void*) &ret, "vkCreatePipelineLayout", (GLADapiproc) glad_vkCreatePipelineLayout, 4, device, pCreateInfo, pAllocator, pPipelineLayout);
    return ret;
}
PFN_vkCreatePipelineLayout glad_debug_vkCreatePipelineLayout = glad_debug_impl_vkCreatePipelineLayout;
PFN_vkCreatePrivateDataSlotEXT glad_vkCreatePrivateDataSlotEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkPrivateDataSlotEXT * pPrivateDataSlot) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreatePrivateDataSlotEXT", (GLADapiproc) glad_vkCreatePrivateDataSlotEXT, 4, device, pCreateInfo, pAllocator, pPrivateDataSlot);
    ret = glad_vkCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    _post_call_vulkan_callback((void*) &ret, "vkCreatePrivateDataSlotEXT", (GLADapiproc) glad_vkCreatePrivateDataSlotEXT, 4, device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return ret;
}
PFN_vkCreatePrivateDataSlotEXT glad_debug_vkCreatePrivateDataSlotEXT = glad_debug_impl_vkCreatePrivateDataSlotEXT;
PFN_vkCreateQueryPool glad_vkCreateQueryPool = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkQueryPool * pQueryPool) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateQueryPool", (GLADapiproc) glad_vkCreateQueryPool, 4, device, pCreateInfo, pAllocator, pQueryPool);
    ret = glad_vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    _post_call_vulkan_callback((void*) &ret, "vkCreateQueryPool", (GLADapiproc) glad_vkCreateQueryPool, 4, device, pCreateInfo, pAllocator, pQueryPool);
    return ret;
}
PFN_vkCreateQueryPool glad_debug_vkCreateQueryPool = glad_debug_impl_vkCreateQueryPool;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkCreateRayTracingPipelinesKHR glad_vkCreateRayTracingPipelinesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateRayTracingPipelinesKHR(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkPipeline * pPipelines) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateRayTracingPipelinesKHR", (GLADapiproc) glad_vkCreateRayTracingPipelinesKHR, 6, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    ret = glad_vkCreateRayTracingPipelinesKHR(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    _post_call_vulkan_callback((void*) &ret, "vkCreateRayTracingPipelinesKHR", (GLADapiproc) glad_vkCreateRayTracingPipelinesKHR, 6, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return ret;
}
PFN_vkCreateRayTracingPipelinesKHR glad_debug_vkCreateRayTracingPipelinesKHR = glad_debug_impl_vkCreateRayTracingPipelinesKHR;
#endif
PFN_vkCreateRenderPass glad_vkCreateRenderPass = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkRenderPass * pRenderPass) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateRenderPass", (GLADapiproc) glad_vkCreateRenderPass, 4, device, pCreateInfo, pAllocator, pRenderPass);
    ret = glad_vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    _post_call_vulkan_callback((void*) &ret, "vkCreateRenderPass", (GLADapiproc) glad_vkCreateRenderPass, 4, device, pCreateInfo, pAllocator, pRenderPass);
    return ret;
}
PFN_vkCreateRenderPass glad_debug_vkCreateRenderPass = glad_debug_impl_vkCreateRenderPass;
PFN_vkCreateRenderPass2 glad_vkCreateRenderPass2 = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2 * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkRenderPass * pRenderPass) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateRenderPass2", (GLADapiproc) glad_vkCreateRenderPass2, 4, device, pCreateInfo, pAllocator, pRenderPass);
    ret = glad_vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    _post_call_vulkan_callback((void*) &ret, "vkCreateRenderPass2", (GLADapiproc) glad_vkCreateRenderPass2, 4, device, pCreateInfo, pAllocator, pRenderPass);
    return ret;
}
PFN_vkCreateRenderPass2 glad_debug_vkCreateRenderPass2 = glad_debug_impl_vkCreateRenderPass2;
PFN_vkCreateRenderPass2KHR glad_vkCreateRenderPass2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2 * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkRenderPass * pRenderPass) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateRenderPass2KHR", (GLADapiproc) glad_vkCreateRenderPass2KHR, 4, device, pCreateInfo, pAllocator, pRenderPass);
    ret = glad_vkCreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
    _post_call_vulkan_callback((void*) &ret, "vkCreateRenderPass2KHR", (GLADapiproc) glad_vkCreateRenderPass2KHR, 4, device, pCreateInfo, pAllocator, pRenderPass);
    return ret;
}
PFN_vkCreateRenderPass2KHR glad_debug_vkCreateRenderPass2KHR = glad_debug_impl_vkCreateRenderPass2KHR;
PFN_vkCreateSampler glad_vkCreateSampler = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateSampler(VkDevice device, const VkSamplerCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSampler * pSampler) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateSampler", (GLADapiproc) glad_vkCreateSampler, 4, device, pCreateInfo, pAllocator, pSampler);
    ret = glad_vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    _post_call_vulkan_callback((void*) &ret, "vkCreateSampler", (GLADapiproc) glad_vkCreateSampler, 4, device, pCreateInfo, pAllocator, pSampler);
    return ret;
}
PFN_vkCreateSampler glad_debug_vkCreateSampler = glad_debug_impl_vkCreateSampler;
PFN_vkCreateSamplerYcbcrConversion glad_vkCreateSamplerYcbcrConversion = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSamplerYcbcrConversion * pYcbcrConversion) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateSamplerYcbcrConversion", (GLADapiproc) glad_vkCreateSamplerYcbcrConversion, 4, device, pCreateInfo, pAllocator, pYcbcrConversion);
    ret = glad_vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    _post_call_vulkan_callback((void*) &ret, "vkCreateSamplerYcbcrConversion", (GLADapiproc) glad_vkCreateSamplerYcbcrConversion, 4, device, pCreateInfo, pAllocator, pYcbcrConversion);
    return ret;
}
PFN_vkCreateSamplerYcbcrConversion glad_debug_vkCreateSamplerYcbcrConversion = glad_debug_impl_vkCreateSamplerYcbcrConversion;
PFN_vkCreateSamplerYcbcrConversionKHR glad_vkCreateSamplerYcbcrConversionKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSamplerYcbcrConversion * pYcbcrConversion) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateSamplerYcbcrConversionKHR", (GLADapiproc) glad_vkCreateSamplerYcbcrConversionKHR, 4, device, pCreateInfo, pAllocator, pYcbcrConversion);
    ret = glad_vkCreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
    _post_call_vulkan_callback((void*) &ret, "vkCreateSamplerYcbcrConversionKHR", (GLADapiproc) glad_vkCreateSamplerYcbcrConversionKHR, 4, device, pCreateInfo, pAllocator, pYcbcrConversion);
    return ret;
}
PFN_vkCreateSamplerYcbcrConversionKHR glad_debug_vkCreateSamplerYcbcrConversionKHR = glad_debug_impl_vkCreateSamplerYcbcrConversionKHR;
PFN_vkCreateSemaphore glad_vkCreateSemaphore = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSemaphore * pSemaphore) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateSemaphore", (GLADapiproc) glad_vkCreateSemaphore, 4, device, pCreateInfo, pAllocator, pSemaphore);
    ret = glad_vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    _post_call_vulkan_callback((void*) &ret, "vkCreateSemaphore", (GLADapiproc) glad_vkCreateSemaphore, 4, device, pCreateInfo, pAllocator, pSemaphore);
    return ret;
}
PFN_vkCreateSemaphore glad_debug_vkCreateSemaphore = glad_debug_impl_vkCreateSemaphore;
PFN_vkCreateShaderModule glad_vkCreateShaderModule = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkShaderModule * pShaderModule) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateShaderModule", (GLADapiproc) glad_vkCreateShaderModule, 4, device, pCreateInfo, pAllocator, pShaderModule);
    ret = glad_vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    _post_call_vulkan_callback((void*) &ret, "vkCreateShaderModule", (GLADapiproc) glad_vkCreateShaderModule, 4, device, pCreateInfo, pAllocator, pShaderModule);
    return ret;
}
PFN_vkCreateShaderModule glad_debug_vkCreateShaderModule = glad_debug_impl_vkCreateShaderModule;
PFN_vkCreateSharedSwapchainsKHR glad_vkCreateSharedSwapchainsKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkSwapchainKHR * pSwapchains) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateSharedSwapchainsKHR", (GLADapiproc) glad_vkCreateSharedSwapchainsKHR, 5, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    ret = glad_vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    _post_call_vulkan_callback((void*) &ret, "vkCreateSharedSwapchainsKHR", (GLADapiproc) glad_vkCreateSharedSwapchainsKHR, 5, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return ret;
}
PFN_vkCreateSharedSwapchainsKHR glad_debug_vkCreateSharedSwapchainsKHR = glad_debug_impl_vkCreateSharedSwapchainsKHR;
PFN_vkCreateSwapchainKHR glad_vkCreateSwapchainKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSwapchainKHR * pSwapchain) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateSwapchainKHR", (GLADapiproc) glad_vkCreateSwapchainKHR, 4, device, pCreateInfo, pAllocator, pSwapchain);
    ret = glad_vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    _post_call_vulkan_callback((void*) &ret, "vkCreateSwapchainKHR", (GLADapiproc) glad_vkCreateSwapchainKHR, 4, device, pCreateInfo, pAllocator, pSwapchain);
    return ret;
}
PFN_vkCreateSwapchainKHR glad_debug_vkCreateSwapchainKHR = glad_debug_impl_vkCreateSwapchainKHR;
PFN_vkCreateValidationCacheEXT glad_vkCreateValidationCacheEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkValidationCacheEXT * pValidationCache) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateValidationCacheEXT", (GLADapiproc) glad_vkCreateValidationCacheEXT, 4, device, pCreateInfo, pAllocator, pValidationCache);
    ret = glad_vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    _post_call_vulkan_callback((void*) &ret, "vkCreateValidationCacheEXT", (GLADapiproc) glad_vkCreateValidationCacheEXT, 4, device, pCreateInfo, pAllocator, pValidationCache);
    return ret;
}
PFN_vkCreateValidationCacheEXT glad_debug_vkCreateValidationCacheEXT = glad_debug_impl_vkCreateValidationCacheEXT;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
PFN_vkCreateWaylandSurfaceKHR glad_vkCreateWaylandSurfaceKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateWaylandSurfaceKHR", (GLADapiproc) glad_vkCreateWaylandSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateWaylandSurfaceKHR", (GLADapiproc) glad_vkCreateWaylandSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateWaylandSurfaceKHR glad_debug_vkCreateWaylandSurfaceKHR = glad_debug_impl_vkCreateWaylandSurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkCreateWin32SurfaceKHR glad_vkCreateWin32SurfaceKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateWin32SurfaceKHR", (GLADapiproc) glad_vkCreateWin32SurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateWin32SurfaceKHR", (GLADapiproc) glad_vkCreateWin32SurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateWin32SurfaceKHR glad_debug_vkCreateWin32SurfaceKHR = glad_debug_impl_vkCreateWin32SurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
PFN_vkCreateXcbSurfaceKHR glad_vkCreateXcbSurfaceKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateXcbSurfaceKHR", (GLADapiproc) glad_vkCreateXcbSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateXcbSurfaceKHR", (GLADapiproc) glad_vkCreateXcbSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateXcbSurfaceKHR glad_debug_vkCreateXcbSurfaceKHR = glad_debug_impl_vkCreateXcbSurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
PFN_vkCreateXlibSurfaceKHR glad_vkCreateXlibSurfaceKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
    VkResult ret;
    _pre_call_vulkan_callback("vkCreateXlibSurfaceKHR", (GLADapiproc) glad_vkCreateXlibSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    ret = glad_vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    _post_call_vulkan_callback((void*) &ret, "vkCreateXlibSurfaceKHR", (GLADapiproc) glad_vkCreateXlibSurfaceKHR, 4, instance, pCreateInfo, pAllocator, pSurface);
    return ret;
}
PFN_vkCreateXlibSurfaceKHR glad_debug_vkCreateXlibSurfaceKHR = glad_debug_impl_vkCreateXlibSurfaceKHR;
#endif
PFN_vkDebugMarkerSetObjectNameEXT glad_vkDebugMarkerSetObjectNameEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT * pNameInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkDebugMarkerSetObjectNameEXT", (GLADapiproc) glad_vkDebugMarkerSetObjectNameEXT, 2, device, pNameInfo);
    ret = glad_vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
    _post_call_vulkan_callback((void*) &ret, "vkDebugMarkerSetObjectNameEXT", (GLADapiproc) glad_vkDebugMarkerSetObjectNameEXT, 2, device, pNameInfo);
    return ret;
}
PFN_vkDebugMarkerSetObjectNameEXT glad_debug_vkDebugMarkerSetObjectNameEXT = glad_debug_impl_vkDebugMarkerSetObjectNameEXT;
PFN_vkDebugMarkerSetObjectTagEXT glad_vkDebugMarkerSetObjectTagEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT * pTagInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkDebugMarkerSetObjectTagEXT", (GLADapiproc) glad_vkDebugMarkerSetObjectTagEXT, 2, device, pTagInfo);
    ret = glad_vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
    _post_call_vulkan_callback((void*) &ret, "vkDebugMarkerSetObjectTagEXT", (GLADapiproc) glad_vkDebugMarkerSetObjectTagEXT, 2, device, pTagInfo);
    return ret;
}
PFN_vkDebugMarkerSetObjectTagEXT glad_debug_vkDebugMarkerSetObjectTagEXT = glad_debug_impl_vkDebugMarkerSetObjectTagEXT;
PFN_vkDebugReportMessageEXT glad_vkDebugReportMessageEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char * pLayerPrefix, const char * pMessage) {
    _pre_call_vulkan_callback("vkDebugReportMessageEXT", (GLADapiproc) glad_vkDebugReportMessageEXT, 8, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    glad_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    _post_call_vulkan_callback(NULL, "vkDebugReportMessageEXT", (GLADapiproc) glad_vkDebugReportMessageEXT, 8, instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    
}
PFN_vkDebugReportMessageEXT glad_debug_vkDebugReportMessageEXT = glad_debug_impl_vkDebugReportMessageEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkDeferredOperationJoinKHR glad_vkDeferredOperationJoinKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) {
    VkResult ret;
    _pre_call_vulkan_callback("vkDeferredOperationJoinKHR", (GLADapiproc) glad_vkDeferredOperationJoinKHR, 2, device, operation);
    ret = glad_vkDeferredOperationJoinKHR(device, operation);
    _post_call_vulkan_callback((void*) &ret, "vkDeferredOperationJoinKHR", (GLADapiproc) glad_vkDeferredOperationJoinKHR, 2, device, operation);
    return ret;
}
PFN_vkDeferredOperationJoinKHR glad_debug_vkDeferredOperationJoinKHR = glad_debug_impl_vkDeferredOperationJoinKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkDestroyAccelerationStructureKHR glad_vkDestroyAccelerationStructureKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyAccelerationStructureKHR", (GLADapiproc) glad_vkDestroyAccelerationStructureKHR, 3, device, accelerationStructure, pAllocator);
    glad_vkDestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyAccelerationStructureKHR", (GLADapiproc) glad_vkDestroyAccelerationStructureKHR, 3, device, accelerationStructure, pAllocator);
    
}
PFN_vkDestroyAccelerationStructureKHR glad_debug_vkDestroyAccelerationStructureKHR = glad_debug_impl_vkDestroyAccelerationStructureKHR;
#endif
PFN_vkDestroyBuffer glad_vkDestroyBuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyBuffer", (GLADapiproc) glad_vkDestroyBuffer, 3, device, buffer, pAllocator);
    glad_vkDestroyBuffer(device, buffer, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyBuffer", (GLADapiproc) glad_vkDestroyBuffer, 3, device, buffer, pAllocator);
    
}
PFN_vkDestroyBuffer glad_debug_vkDestroyBuffer = glad_debug_impl_vkDestroyBuffer;
PFN_vkDestroyBufferView glad_vkDestroyBufferView = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyBufferView", (GLADapiproc) glad_vkDestroyBufferView, 3, device, bufferView, pAllocator);
    glad_vkDestroyBufferView(device, bufferView, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyBufferView", (GLADapiproc) glad_vkDestroyBufferView, 3, device, bufferView, pAllocator);
    
}
PFN_vkDestroyBufferView glad_debug_vkDestroyBufferView = glad_debug_impl_vkDestroyBufferView;
PFN_vkDestroyCommandPool glad_vkDestroyCommandPool = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyCommandPool", (GLADapiproc) glad_vkDestroyCommandPool, 3, device, commandPool, pAllocator);
    glad_vkDestroyCommandPool(device, commandPool, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyCommandPool", (GLADapiproc) glad_vkDestroyCommandPool, 3, device, commandPool, pAllocator);
    
}
PFN_vkDestroyCommandPool glad_debug_vkDestroyCommandPool = glad_debug_impl_vkDestroyCommandPool;
PFN_vkDestroyDebugReportCallbackEXT glad_vkDestroyDebugReportCallbackEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDebugReportCallbackEXT", (GLADapiproc) glad_vkDestroyDebugReportCallbackEXT, 3, instance, callback, pAllocator);
    glad_vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDebugReportCallbackEXT", (GLADapiproc) glad_vkDestroyDebugReportCallbackEXT, 3, instance, callback, pAllocator);
    
}
PFN_vkDestroyDebugReportCallbackEXT glad_debug_vkDestroyDebugReportCallbackEXT = glad_debug_impl_vkDestroyDebugReportCallbackEXT;
PFN_vkDestroyDebugUtilsMessengerEXT glad_vkDestroyDebugUtilsMessengerEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDebugUtilsMessengerEXT", (GLADapiproc) glad_vkDestroyDebugUtilsMessengerEXT, 3, instance, messenger, pAllocator);
    glad_vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDebugUtilsMessengerEXT", (GLADapiproc) glad_vkDestroyDebugUtilsMessengerEXT, 3, instance, messenger, pAllocator);
    
}
PFN_vkDestroyDebugUtilsMessengerEXT glad_debug_vkDestroyDebugUtilsMessengerEXT = glad_debug_impl_vkDestroyDebugUtilsMessengerEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkDestroyDeferredOperationKHR glad_vkDestroyDeferredOperationKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDeferredOperationKHR", (GLADapiproc) glad_vkDestroyDeferredOperationKHR, 3, device, operation, pAllocator);
    glad_vkDestroyDeferredOperationKHR(device, operation, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDeferredOperationKHR", (GLADapiproc) glad_vkDestroyDeferredOperationKHR, 3, device, operation, pAllocator);
    
}
PFN_vkDestroyDeferredOperationKHR glad_debug_vkDestroyDeferredOperationKHR = glad_debug_impl_vkDestroyDeferredOperationKHR;
#endif
PFN_vkDestroyDescriptorPool glad_vkDestroyDescriptorPool = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDescriptorPool", (GLADapiproc) glad_vkDestroyDescriptorPool, 3, device, descriptorPool, pAllocator);
    glad_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDescriptorPool", (GLADapiproc) glad_vkDestroyDescriptorPool, 3, device, descriptorPool, pAllocator);
    
}
PFN_vkDestroyDescriptorPool glad_debug_vkDestroyDescriptorPool = glad_debug_impl_vkDestroyDescriptorPool;
PFN_vkDestroyDescriptorSetLayout glad_vkDestroyDescriptorSetLayout = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDescriptorSetLayout", (GLADapiproc) glad_vkDestroyDescriptorSetLayout, 3, device, descriptorSetLayout, pAllocator);
    glad_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDescriptorSetLayout", (GLADapiproc) glad_vkDestroyDescriptorSetLayout, 3, device, descriptorSetLayout, pAllocator);
    
}
PFN_vkDestroyDescriptorSetLayout glad_debug_vkDestroyDescriptorSetLayout = glad_debug_impl_vkDestroyDescriptorSetLayout;
PFN_vkDestroyDescriptorUpdateTemplate glad_vkDestroyDescriptorUpdateTemplate = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDescriptorUpdateTemplate", (GLADapiproc) glad_vkDestroyDescriptorUpdateTemplate, 3, device, descriptorUpdateTemplate, pAllocator);
    glad_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDescriptorUpdateTemplate", (GLADapiproc) glad_vkDestroyDescriptorUpdateTemplate, 3, device, descriptorUpdateTemplate, pAllocator);
    
}
PFN_vkDestroyDescriptorUpdateTemplate glad_debug_vkDestroyDescriptorUpdateTemplate = glad_debug_impl_vkDestroyDescriptorUpdateTemplate;
PFN_vkDestroyDescriptorUpdateTemplateKHR glad_vkDestroyDescriptorUpdateTemplateKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDescriptorUpdateTemplateKHR", (GLADapiproc) glad_vkDestroyDescriptorUpdateTemplateKHR, 3, device, descriptorUpdateTemplate, pAllocator);
    glad_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDescriptorUpdateTemplateKHR", (GLADapiproc) glad_vkDestroyDescriptorUpdateTemplateKHR, 3, device, descriptorUpdateTemplate, pAllocator);
    
}
PFN_vkDestroyDescriptorUpdateTemplateKHR glad_debug_vkDestroyDescriptorUpdateTemplateKHR = glad_debug_impl_vkDestroyDescriptorUpdateTemplateKHR;
PFN_vkDestroyDevice glad_vkDestroyDevice = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyDevice(VkDevice device, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyDevice", (GLADapiproc) glad_vkDestroyDevice, 2, device, pAllocator);
    glad_vkDestroyDevice(device, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyDevice", (GLADapiproc) glad_vkDestroyDevice, 2, device, pAllocator);
    
}
PFN_vkDestroyDevice glad_debug_vkDestroyDevice = glad_debug_impl_vkDestroyDevice;
PFN_vkDestroyEvent glad_vkDestroyEvent = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyEvent", (GLADapiproc) glad_vkDestroyEvent, 3, device, event, pAllocator);
    glad_vkDestroyEvent(device, event, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyEvent", (GLADapiproc) glad_vkDestroyEvent, 3, device, event, pAllocator);
    
}
PFN_vkDestroyEvent glad_debug_vkDestroyEvent = glad_debug_impl_vkDestroyEvent;
PFN_vkDestroyFence glad_vkDestroyFence = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyFence", (GLADapiproc) glad_vkDestroyFence, 3, device, fence, pAllocator);
    glad_vkDestroyFence(device, fence, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyFence", (GLADapiproc) glad_vkDestroyFence, 3, device, fence, pAllocator);
    
}
PFN_vkDestroyFence glad_debug_vkDestroyFence = glad_debug_impl_vkDestroyFence;
PFN_vkDestroyFramebuffer glad_vkDestroyFramebuffer = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyFramebuffer", (GLADapiproc) glad_vkDestroyFramebuffer, 3, device, framebuffer, pAllocator);
    glad_vkDestroyFramebuffer(device, framebuffer, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyFramebuffer", (GLADapiproc) glad_vkDestroyFramebuffer, 3, device, framebuffer, pAllocator);
    
}
PFN_vkDestroyFramebuffer glad_debug_vkDestroyFramebuffer = glad_debug_impl_vkDestroyFramebuffer;
PFN_vkDestroyImage glad_vkDestroyImage = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyImage", (GLADapiproc) glad_vkDestroyImage, 3, device, image, pAllocator);
    glad_vkDestroyImage(device, image, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyImage", (GLADapiproc) glad_vkDestroyImage, 3, device, image, pAllocator);
    
}
PFN_vkDestroyImage glad_debug_vkDestroyImage = glad_debug_impl_vkDestroyImage;
PFN_vkDestroyImageView glad_vkDestroyImageView = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyImageView", (GLADapiproc) glad_vkDestroyImageView, 3, device, imageView, pAllocator);
    glad_vkDestroyImageView(device, imageView, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyImageView", (GLADapiproc) glad_vkDestroyImageView, 3, device, imageView, pAllocator);
    
}
PFN_vkDestroyImageView glad_debug_vkDestroyImageView = glad_debug_impl_vkDestroyImageView;
PFN_vkDestroyInstance glad_vkDestroyInstance = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyInstance", (GLADapiproc) glad_vkDestroyInstance, 2, instance, pAllocator);
    glad_vkDestroyInstance(instance, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyInstance", (GLADapiproc) glad_vkDestroyInstance, 2, instance, pAllocator);
    
}
PFN_vkDestroyInstance glad_debug_vkDestroyInstance = glad_debug_impl_vkDestroyInstance;
PFN_vkDestroyPipeline glad_vkDestroyPipeline = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyPipeline", (GLADapiproc) glad_vkDestroyPipeline, 3, device, pipeline, pAllocator);
    glad_vkDestroyPipeline(device, pipeline, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyPipeline", (GLADapiproc) glad_vkDestroyPipeline, 3, device, pipeline, pAllocator);
    
}
PFN_vkDestroyPipeline glad_debug_vkDestroyPipeline = glad_debug_impl_vkDestroyPipeline;
PFN_vkDestroyPipelineCache glad_vkDestroyPipelineCache = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyPipelineCache", (GLADapiproc) glad_vkDestroyPipelineCache, 3, device, pipelineCache, pAllocator);
    glad_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyPipelineCache", (GLADapiproc) glad_vkDestroyPipelineCache, 3, device, pipelineCache, pAllocator);
    
}
PFN_vkDestroyPipelineCache glad_debug_vkDestroyPipelineCache = glad_debug_impl_vkDestroyPipelineCache;
PFN_vkDestroyPipelineLayout glad_vkDestroyPipelineLayout = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyPipelineLayout", (GLADapiproc) glad_vkDestroyPipelineLayout, 3, device, pipelineLayout, pAllocator);
    glad_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyPipelineLayout", (GLADapiproc) glad_vkDestroyPipelineLayout, 3, device, pipelineLayout, pAllocator);
    
}
PFN_vkDestroyPipelineLayout glad_debug_vkDestroyPipelineLayout = glad_debug_impl_vkDestroyPipelineLayout;
PFN_vkDestroyPrivateDataSlotEXT glad_vkDestroyPrivateDataSlotEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyPrivateDataSlotEXT", (GLADapiproc) glad_vkDestroyPrivateDataSlotEXT, 3, device, privateDataSlot, pAllocator);
    glad_vkDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyPrivateDataSlotEXT", (GLADapiproc) glad_vkDestroyPrivateDataSlotEXT, 3, device, privateDataSlot, pAllocator);
    
}
PFN_vkDestroyPrivateDataSlotEXT glad_debug_vkDestroyPrivateDataSlotEXT = glad_debug_impl_vkDestroyPrivateDataSlotEXT;
PFN_vkDestroyQueryPool glad_vkDestroyQueryPool = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyQueryPool", (GLADapiproc) glad_vkDestroyQueryPool, 3, device, queryPool, pAllocator);
    glad_vkDestroyQueryPool(device, queryPool, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyQueryPool", (GLADapiproc) glad_vkDestroyQueryPool, 3, device, queryPool, pAllocator);
    
}
PFN_vkDestroyQueryPool glad_debug_vkDestroyQueryPool = glad_debug_impl_vkDestroyQueryPool;
PFN_vkDestroyRenderPass glad_vkDestroyRenderPass = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyRenderPass", (GLADapiproc) glad_vkDestroyRenderPass, 3, device, renderPass, pAllocator);
    glad_vkDestroyRenderPass(device, renderPass, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyRenderPass", (GLADapiproc) glad_vkDestroyRenderPass, 3, device, renderPass, pAllocator);
    
}
PFN_vkDestroyRenderPass glad_debug_vkDestroyRenderPass = glad_debug_impl_vkDestroyRenderPass;
PFN_vkDestroySampler glad_vkDestroySampler = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroySampler", (GLADapiproc) glad_vkDestroySampler, 3, device, sampler, pAllocator);
    glad_vkDestroySampler(device, sampler, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroySampler", (GLADapiproc) glad_vkDestroySampler, 3, device, sampler, pAllocator);
    
}
PFN_vkDestroySampler glad_debug_vkDestroySampler = glad_debug_impl_vkDestroySampler;
PFN_vkDestroySamplerYcbcrConversion glad_vkDestroySamplerYcbcrConversion = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroySamplerYcbcrConversion", (GLADapiproc) glad_vkDestroySamplerYcbcrConversion, 3, device, ycbcrConversion, pAllocator);
    glad_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroySamplerYcbcrConversion", (GLADapiproc) glad_vkDestroySamplerYcbcrConversion, 3, device, ycbcrConversion, pAllocator);
    
}
PFN_vkDestroySamplerYcbcrConversion glad_debug_vkDestroySamplerYcbcrConversion = glad_debug_impl_vkDestroySamplerYcbcrConversion;
PFN_vkDestroySamplerYcbcrConversionKHR glad_vkDestroySamplerYcbcrConversionKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroySamplerYcbcrConversionKHR", (GLADapiproc) glad_vkDestroySamplerYcbcrConversionKHR, 3, device, ycbcrConversion, pAllocator);
    glad_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroySamplerYcbcrConversionKHR", (GLADapiproc) glad_vkDestroySamplerYcbcrConversionKHR, 3, device, ycbcrConversion, pAllocator);
    
}
PFN_vkDestroySamplerYcbcrConversionKHR glad_debug_vkDestroySamplerYcbcrConversionKHR = glad_debug_impl_vkDestroySamplerYcbcrConversionKHR;
PFN_vkDestroySemaphore glad_vkDestroySemaphore = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroySemaphore", (GLADapiproc) glad_vkDestroySemaphore, 3, device, semaphore, pAllocator);
    glad_vkDestroySemaphore(device, semaphore, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroySemaphore", (GLADapiproc) glad_vkDestroySemaphore, 3, device, semaphore, pAllocator);
    
}
PFN_vkDestroySemaphore glad_debug_vkDestroySemaphore = glad_debug_impl_vkDestroySemaphore;
PFN_vkDestroyShaderModule glad_vkDestroyShaderModule = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyShaderModule", (GLADapiproc) glad_vkDestroyShaderModule, 3, device, shaderModule, pAllocator);
    glad_vkDestroyShaderModule(device, shaderModule, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyShaderModule", (GLADapiproc) glad_vkDestroyShaderModule, 3, device, shaderModule, pAllocator);
    
}
PFN_vkDestroyShaderModule glad_debug_vkDestroyShaderModule = glad_debug_impl_vkDestroyShaderModule;
PFN_vkDestroySurfaceKHR glad_vkDestroySurfaceKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroySurfaceKHR", (GLADapiproc) glad_vkDestroySurfaceKHR, 3, instance, surface, pAllocator);
    glad_vkDestroySurfaceKHR(instance, surface, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroySurfaceKHR", (GLADapiproc) glad_vkDestroySurfaceKHR, 3, instance, surface, pAllocator);
    
}
PFN_vkDestroySurfaceKHR glad_debug_vkDestroySurfaceKHR = glad_debug_impl_vkDestroySurfaceKHR;
PFN_vkDestroySwapchainKHR glad_vkDestroySwapchainKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroySwapchainKHR", (GLADapiproc) glad_vkDestroySwapchainKHR, 3, device, swapchain, pAllocator);
    glad_vkDestroySwapchainKHR(device, swapchain, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroySwapchainKHR", (GLADapiproc) glad_vkDestroySwapchainKHR, 3, device, swapchain, pAllocator);
    
}
PFN_vkDestroySwapchainKHR glad_debug_vkDestroySwapchainKHR = glad_debug_impl_vkDestroySwapchainKHR;
PFN_vkDestroyValidationCacheEXT glad_vkDestroyValidationCacheEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkDestroyValidationCacheEXT", (GLADapiproc) glad_vkDestroyValidationCacheEXT, 3, device, validationCache, pAllocator);
    glad_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    _post_call_vulkan_callback(NULL, "vkDestroyValidationCacheEXT", (GLADapiproc) glad_vkDestroyValidationCacheEXT, 3, device, validationCache, pAllocator);
    
}
PFN_vkDestroyValidationCacheEXT glad_debug_vkDestroyValidationCacheEXT = glad_debug_impl_vkDestroyValidationCacheEXT;
PFN_vkDeviceWaitIdle glad_vkDeviceWaitIdle = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkDeviceWaitIdle(VkDevice device) {
    VkResult ret;
    _pre_call_vulkan_callback("vkDeviceWaitIdle", (GLADapiproc) glad_vkDeviceWaitIdle, 1, device);
    ret = glad_vkDeviceWaitIdle(device);
    _post_call_vulkan_callback((void*) &ret, "vkDeviceWaitIdle", (GLADapiproc) glad_vkDeviceWaitIdle, 1, device);
    return ret;
}
PFN_vkDeviceWaitIdle glad_debug_vkDeviceWaitIdle = glad_debug_impl_vkDeviceWaitIdle;
PFN_vkDisplayPowerControlEXT glad_vkDisplayPowerControlEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT * pDisplayPowerInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkDisplayPowerControlEXT", (GLADapiproc) glad_vkDisplayPowerControlEXT, 3, device, display, pDisplayPowerInfo);
    ret = glad_vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    _post_call_vulkan_callback((void*) &ret, "vkDisplayPowerControlEXT", (GLADapiproc) glad_vkDisplayPowerControlEXT, 3, device, display, pDisplayPowerInfo);
    return ret;
}
PFN_vkDisplayPowerControlEXT glad_debug_vkDisplayPowerControlEXT = glad_debug_impl_vkDisplayPowerControlEXT;
PFN_vkEndCommandBuffer glad_vkEndCommandBuffer = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEndCommandBuffer(VkCommandBuffer commandBuffer) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEndCommandBuffer", (GLADapiproc) glad_vkEndCommandBuffer, 1, commandBuffer);
    ret = glad_vkEndCommandBuffer(commandBuffer);
    _post_call_vulkan_callback((void*) &ret, "vkEndCommandBuffer", (GLADapiproc) glad_vkEndCommandBuffer, 1, commandBuffer);
    return ret;
}
PFN_vkEndCommandBuffer glad_debug_vkEndCommandBuffer = glad_debug_impl_vkEndCommandBuffer;
PFN_vkEnumerateDeviceExtensionProperties glad_vkEnumerateDeviceExtensionProperties = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char * pLayerName, uint32_t * pPropertyCount, VkExtensionProperties * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumerateDeviceExtensionProperties", (GLADapiproc) glad_vkEnumerateDeviceExtensionProperties, 4, physicalDevice, pLayerName, pPropertyCount, pProperties);
    ret = glad_vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkEnumerateDeviceExtensionProperties", (GLADapiproc) glad_vkEnumerateDeviceExtensionProperties, 4, physicalDevice, pLayerName, pPropertyCount, pProperties);
    return ret;
}
PFN_vkEnumerateDeviceExtensionProperties glad_debug_vkEnumerateDeviceExtensionProperties = glad_debug_impl_vkEnumerateDeviceExtensionProperties;
PFN_vkEnumerateDeviceLayerProperties glad_vkEnumerateDeviceLayerProperties = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkLayerProperties * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumerateDeviceLayerProperties", (GLADapiproc) glad_vkEnumerateDeviceLayerProperties, 3, physicalDevice, pPropertyCount, pProperties);
    ret = glad_vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkEnumerateDeviceLayerProperties", (GLADapiproc) glad_vkEnumerateDeviceLayerProperties, 3, physicalDevice, pPropertyCount, pProperties);
    return ret;
}
PFN_vkEnumerateDeviceLayerProperties glad_debug_vkEnumerateDeviceLayerProperties = glad_debug_impl_vkEnumerateDeviceLayerProperties;
PFN_vkEnumerateInstanceExtensionProperties glad_vkEnumerateInstanceExtensionProperties = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumerateInstanceExtensionProperties(const char * pLayerName, uint32_t * pPropertyCount, VkExtensionProperties * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumerateInstanceExtensionProperties", (GLADapiproc) glad_vkEnumerateInstanceExtensionProperties, 3, pLayerName, pPropertyCount, pProperties);
    ret = glad_vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkEnumerateInstanceExtensionProperties", (GLADapiproc) glad_vkEnumerateInstanceExtensionProperties, 3, pLayerName, pPropertyCount, pProperties);
    return ret;
}
PFN_vkEnumerateInstanceExtensionProperties glad_debug_vkEnumerateInstanceExtensionProperties = glad_debug_impl_vkEnumerateInstanceExtensionProperties;
PFN_vkEnumerateInstanceLayerProperties glad_vkEnumerateInstanceLayerProperties = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumerateInstanceLayerProperties(uint32_t * pPropertyCount, VkLayerProperties * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumerateInstanceLayerProperties", (GLADapiproc) glad_vkEnumerateInstanceLayerProperties, 2, pPropertyCount, pProperties);
    ret = glad_vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkEnumerateInstanceLayerProperties", (GLADapiproc) glad_vkEnumerateInstanceLayerProperties, 2, pPropertyCount, pProperties);
    return ret;
}
PFN_vkEnumerateInstanceLayerProperties glad_debug_vkEnumerateInstanceLayerProperties = glad_debug_impl_vkEnumerateInstanceLayerProperties;
PFN_vkEnumerateInstanceVersion glad_vkEnumerateInstanceVersion = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumerateInstanceVersion(uint32_t * pApiVersion) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumerateInstanceVersion", (GLADapiproc) glad_vkEnumerateInstanceVersion, 1, pApiVersion);
    ret = glad_vkEnumerateInstanceVersion(pApiVersion);
    _post_call_vulkan_callback((void*) &ret, "vkEnumerateInstanceVersion", (GLADapiproc) glad_vkEnumerateInstanceVersion, 1, pApiVersion);
    return ret;
}
PFN_vkEnumerateInstanceVersion glad_debug_vkEnumerateInstanceVersion = glad_debug_impl_vkEnumerateInstanceVersion;
PFN_vkEnumeratePhysicalDeviceGroups glad_vkEnumeratePhysicalDeviceGroups = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t * pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties * pPhysicalDeviceGroupProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumeratePhysicalDeviceGroups", (GLADapiproc) glad_vkEnumeratePhysicalDeviceGroups, 3, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    ret = glad_vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    _post_call_vulkan_callback((void*) &ret, "vkEnumeratePhysicalDeviceGroups", (GLADapiproc) glad_vkEnumeratePhysicalDeviceGroups, 3, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return ret;
}
PFN_vkEnumeratePhysicalDeviceGroups glad_debug_vkEnumeratePhysicalDeviceGroups = glad_debug_impl_vkEnumeratePhysicalDeviceGroups;
PFN_vkEnumeratePhysicalDeviceGroupsKHR glad_vkEnumeratePhysicalDeviceGroupsKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t * pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties * pPhysicalDeviceGroupProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumeratePhysicalDeviceGroupsKHR", (GLADapiproc) glad_vkEnumeratePhysicalDeviceGroupsKHR, 3, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    ret = glad_vkEnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    _post_call_vulkan_callback((void*) &ret, "vkEnumeratePhysicalDeviceGroupsKHR", (GLADapiproc) glad_vkEnumeratePhysicalDeviceGroupsKHR, 3, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return ret;
}
PFN_vkEnumeratePhysicalDeviceGroupsKHR glad_debug_vkEnumeratePhysicalDeviceGroupsKHR = glad_debug_impl_vkEnumeratePhysicalDeviceGroupsKHR;
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t * pCounterCount, VkPerformanceCounterKHR * pCounters, VkPerformanceCounterDescriptionKHR * pCounterDescriptions) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", (GLADapiproc) glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, 5, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    ret = glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    _post_call_vulkan_callback((void*) &ret, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR", (GLADapiproc) glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR, 5, physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return ret;
}
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR glad_debug_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = glad_debug_impl_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
PFN_vkEnumeratePhysicalDevices glad_vkEnumeratePhysicalDevices = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkEnumeratePhysicalDevices(VkInstance instance, uint32_t * pPhysicalDeviceCount, VkPhysicalDevice * pPhysicalDevices) {
    VkResult ret;
    _pre_call_vulkan_callback("vkEnumeratePhysicalDevices", (GLADapiproc) glad_vkEnumeratePhysicalDevices, 3, instance, pPhysicalDeviceCount, pPhysicalDevices);
    ret = glad_vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    _post_call_vulkan_callback((void*) &ret, "vkEnumeratePhysicalDevices", (GLADapiproc) glad_vkEnumeratePhysicalDevices, 3, instance, pPhysicalDeviceCount, pPhysicalDevices);
    return ret;
}
PFN_vkEnumeratePhysicalDevices glad_debug_vkEnumeratePhysicalDevices = glad_debug_impl_vkEnumeratePhysicalDevices;
PFN_vkFlushMappedMemoryRanges glad_vkFlushMappedMemoryRanges = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange * pMemoryRanges) {
    VkResult ret;
    _pre_call_vulkan_callback("vkFlushMappedMemoryRanges", (GLADapiproc) glad_vkFlushMappedMemoryRanges, 3, device, memoryRangeCount, pMemoryRanges);
    ret = glad_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    _post_call_vulkan_callback((void*) &ret, "vkFlushMappedMemoryRanges", (GLADapiproc) glad_vkFlushMappedMemoryRanges, 3, device, memoryRangeCount, pMemoryRanges);
    return ret;
}
PFN_vkFlushMappedMemoryRanges glad_debug_vkFlushMappedMemoryRanges = glad_debug_impl_vkFlushMappedMemoryRanges;
PFN_vkFreeCommandBuffers glad_vkFreeCommandBuffers = NULL;
static void GLAD_API_PTR glad_debug_impl_vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer * pCommandBuffers) {
    _pre_call_vulkan_callback("vkFreeCommandBuffers", (GLADapiproc) glad_vkFreeCommandBuffers, 4, device, commandPool, commandBufferCount, pCommandBuffers);
    glad_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    _post_call_vulkan_callback(NULL, "vkFreeCommandBuffers", (GLADapiproc) glad_vkFreeCommandBuffers, 4, device, commandPool, commandBufferCount, pCommandBuffers);
    
}
PFN_vkFreeCommandBuffers glad_debug_vkFreeCommandBuffers = glad_debug_impl_vkFreeCommandBuffers;
PFN_vkFreeDescriptorSets glad_vkFreeDescriptorSets = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet * pDescriptorSets) {
    VkResult ret;
    _pre_call_vulkan_callback("vkFreeDescriptorSets", (GLADapiproc) glad_vkFreeDescriptorSets, 4, device, descriptorPool, descriptorSetCount, pDescriptorSets);
    ret = glad_vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    _post_call_vulkan_callback((void*) &ret, "vkFreeDescriptorSets", (GLADapiproc) glad_vkFreeDescriptorSets, 4, device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return ret;
}
PFN_vkFreeDescriptorSets glad_debug_vkFreeDescriptorSets = glad_debug_impl_vkFreeDescriptorSets;
PFN_vkFreeMemory glad_vkFreeMemory = NULL;
static void GLAD_API_PTR glad_debug_impl_vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks * pAllocator) {
    _pre_call_vulkan_callback("vkFreeMemory", (GLADapiproc) glad_vkFreeMemory, 3, device, memory, pAllocator);
    glad_vkFreeMemory(device, memory, pAllocator);
    _post_call_vulkan_callback(NULL, "vkFreeMemory", (GLADapiproc) glad_vkFreeMemory, 3, device, memory, pAllocator);
    
}
PFN_vkFreeMemory glad_debug_vkFreeMemory = glad_debug_impl_vkFreeMemory;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetAccelerationStructureDeviceAddressKHR glad_vkGetAccelerationStructureDeviceAddressKHR = NULL;
static VkDeviceAddress GLAD_API_PTR glad_debug_impl_vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR * pInfo) {
    VkDeviceAddress ret;
    _pre_call_vulkan_callback("vkGetAccelerationStructureDeviceAddressKHR", (GLADapiproc) glad_vkGetAccelerationStructureDeviceAddressKHR, 2, device, pInfo);
    ret = glad_vkGetAccelerationStructureDeviceAddressKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetAccelerationStructureDeviceAddressKHR", (GLADapiproc) glad_vkGetAccelerationStructureDeviceAddressKHR, 2, device, pInfo);
    return ret;
}
PFN_vkGetAccelerationStructureDeviceAddressKHR glad_debug_vkGetAccelerationStructureDeviceAddressKHR = glad_debug_impl_vkGetAccelerationStructureDeviceAddressKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetAccelerationStructureMemoryRequirementsKHR glad_vkGetAccelerationStructureMemoryRequirementsKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetAccelerationStructureMemoryRequirementsKHR(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoKHR * pInfo, VkMemoryRequirements2 * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetAccelerationStructureMemoryRequirementsKHR", (GLADapiproc) glad_vkGetAccelerationStructureMemoryRequirementsKHR, 3, device, pInfo, pMemoryRequirements);
    glad_vkGetAccelerationStructureMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetAccelerationStructureMemoryRequirementsKHR", (GLADapiproc) glad_vkGetAccelerationStructureMemoryRequirementsKHR, 3, device, pInfo, pMemoryRequirements);
    
}
PFN_vkGetAccelerationStructureMemoryRequirementsKHR glad_debug_vkGetAccelerationStructureMemoryRequirementsKHR = glad_debug_impl_vkGetAccelerationStructureMemoryRequirementsKHR;
#endif
PFN_vkGetBufferDeviceAddress glad_vkGetBufferDeviceAddress = NULL;
static VkDeviceAddress GLAD_API_PTR glad_debug_impl_vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo * pInfo) {
    VkDeviceAddress ret;
    _pre_call_vulkan_callback("vkGetBufferDeviceAddress", (GLADapiproc) glad_vkGetBufferDeviceAddress, 2, device, pInfo);
    ret = glad_vkGetBufferDeviceAddress(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetBufferDeviceAddress", (GLADapiproc) glad_vkGetBufferDeviceAddress, 2, device, pInfo);
    return ret;
}
PFN_vkGetBufferDeviceAddress glad_debug_vkGetBufferDeviceAddress = glad_debug_impl_vkGetBufferDeviceAddress;
PFN_vkGetBufferDeviceAddressEXT glad_vkGetBufferDeviceAddressEXT = NULL;
static VkDeviceAddress GLAD_API_PTR glad_debug_impl_vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo * pInfo) {
    VkDeviceAddress ret;
    _pre_call_vulkan_callback("vkGetBufferDeviceAddressEXT", (GLADapiproc) glad_vkGetBufferDeviceAddressEXT, 2, device, pInfo);
    ret = glad_vkGetBufferDeviceAddressEXT(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetBufferDeviceAddressEXT", (GLADapiproc) glad_vkGetBufferDeviceAddressEXT, 2, device, pInfo);
    return ret;
}
PFN_vkGetBufferDeviceAddressEXT glad_debug_vkGetBufferDeviceAddressEXT = glad_debug_impl_vkGetBufferDeviceAddressEXT;
PFN_vkGetBufferDeviceAddressKHR glad_vkGetBufferDeviceAddressKHR = NULL;
static VkDeviceAddress GLAD_API_PTR glad_debug_impl_vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo * pInfo) {
    VkDeviceAddress ret;
    _pre_call_vulkan_callback("vkGetBufferDeviceAddressKHR", (GLADapiproc) glad_vkGetBufferDeviceAddressKHR, 2, device, pInfo);
    ret = glad_vkGetBufferDeviceAddressKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetBufferDeviceAddressKHR", (GLADapiproc) glad_vkGetBufferDeviceAddressKHR, 2, device, pInfo);
    return ret;
}
PFN_vkGetBufferDeviceAddressKHR glad_debug_vkGetBufferDeviceAddressKHR = glad_debug_impl_vkGetBufferDeviceAddressKHR;
PFN_vkGetBufferMemoryRequirements glad_vkGetBufferMemoryRequirements = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetBufferMemoryRequirements", (GLADapiproc) glad_vkGetBufferMemoryRequirements, 3, device, buffer, pMemoryRequirements);
    glad_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetBufferMemoryRequirements", (GLADapiproc) glad_vkGetBufferMemoryRequirements, 3, device, buffer, pMemoryRequirements);
    
}
PFN_vkGetBufferMemoryRequirements glad_debug_vkGetBufferMemoryRequirements = glad_debug_impl_vkGetBufferMemoryRequirements;
PFN_vkGetBufferMemoryRequirements2 glad_vkGetBufferMemoryRequirements2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetBufferMemoryRequirements2", (GLADapiproc) glad_vkGetBufferMemoryRequirements2, 3, device, pInfo, pMemoryRequirements);
    glad_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetBufferMemoryRequirements2", (GLADapiproc) glad_vkGetBufferMemoryRequirements2, 3, device, pInfo, pMemoryRequirements);
    
}
PFN_vkGetBufferMemoryRequirements2 glad_debug_vkGetBufferMemoryRequirements2 = glad_debug_impl_vkGetBufferMemoryRequirements2;
PFN_vkGetBufferMemoryRequirements2KHR glad_vkGetBufferMemoryRequirements2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetBufferMemoryRequirements2KHR", (GLADapiproc) glad_vkGetBufferMemoryRequirements2KHR, 3, device, pInfo, pMemoryRequirements);
    glad_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetBufferMemoryRequirements2KHR", (GLADapiproc) glad_vkGetBufferMemoryRequirements2KHR, 3, device, pInfo, pMemoryRequirements);
    
}
PFN_vkGetBufferMemoryRequirements2KHR glad_debug_vkGetBufferMemoryRequirements2KHR = glad_debug_impl_vkGetBufferMemoryRequirements2KHR;
PFN_vkGetBufferOpaqueCaptureAddress glad_vkGetBufferOpaqueCaptureAddress = NULL;
static uint64_t GLAD_API_PTR glad_debug_impl_vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo * pInfo) {
    uint64_t ret;
    _pre_call_vulkan_callback("vkGetBufferOpaqueCaptureAddress", (GLADapiproc) glad_vkGetBufferOpaqueCaptureAddress, 2, device, pInfo);
    ret = glad_vkGetBufferOpaqueCaptureAddress(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetBufferOpaqueCaptureAddress", (GLADapiproc) glad_vkGetBufferOpaqueCaptureAddress, 2, device, pInfo);
    return ret;
}
PFN_vkGetBufferOpaqueCaptureAddress glad_debug_vkGetBufferOpaqueCaptureAddress = glad_debug_impl_vkGetBufferOpaqueCaptureAddress;
PFN_vkGetBufferOpaqueCaptureAddressKHR glad_vkGetBufferOpaqueCaptureAddressKHR = NULL;
static uint64_t GLAD_API_PTR glad_debug_impl_vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo * pInfo) {
    uint64_t ret;
    _pre_call_vulkan_callback("vkGetBufferOpaqueCaptureAddressKHR", (GLADapiproc) glad_vkGetBufferOpaqueCaptureAddressKHR, 2, device, pInfo);
    ret = glad_vkGetBufferOpaqueCaptureAddressKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetBufferOpaqueCaptureAddressKHR", (GLADapiproc) glad_vkGetBufferOpaqueCaptureAddressKHR, 2, device, pInfo);
    return ret;
}
PFN_vkGetBufferOpaqueCaptureAddressKHR glad_debug_vkGetBufferOpaqueCaptureAddressKHR = glad_debug_impl_vkGetBufferOpaqueCaptureAddressKHR;
PFN_vkGetCalibratedTimestampsEXT glad_vkGetCalibratedTimestampsEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT * pTimestampInfos, uint64_t * pTimestamps, uint64_t * pMaxDeviation) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetCalibratedTimestampsEXT", (GLADapiproc) glad_vkGetCalibratedTimestampsEXT, 5, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    ret = glad_vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    _post_call_vulkan_callback((void*) &ret, "vkGetCalibratedTimestampsEXT", (GLADapiproc) glad_vkGetCalibratedTimestampsEXT, 5, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return ret;
}
PFN_vkGetCalibratedTimestampsEXT glad_debug_vkGetCalibratedTimestampsEXT = glad_debug_impl_vkGetCalibratedTimestampsEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetDeferredOperationMaxConcurrencyKHR glad_vkGetDeferredOperationMaxConcurrencyKHR = NULL;
static uint32_t GLAD_API_PTR glad_debug_impl_vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) {
    uint32_t ret;
    _pre_call_vulkan_callback("vkGetDeferredOperationMaxConcurrencyKHR", (GLADapiproc) glad_vkGetDeferredOperationMaxConcurrencyKHR, 2, device, operation);
    ret = glad_vkGetDeferredOperationMaxConcurrencyKHR(device, operation);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeferredOperationMaxConcurrencyKHR", (GLADapiproc) glad_vkGetDeferredOperationMaxConcurrencyKHR, 2, device, operation);
    return ret;
}
PFN_vkGetDeferredOperationMaxConcurrencyKHR glad_debug_vkGetDeferredOperationMaxConcurrencyKHR = glad_debug_impl_vkGetDeferredOperationMaxConcurrencyKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetDeferredOperationResultKHR glad_vkGetDeferredOperationResultKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDeferredOperationResultKHR", (GLADapiproc) glad_vkGetDeferredOperationResultKHR, 2, device, operation);
    ret = glad_vkGetDeferredOperationResultKHR(device, operation);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeferredOperationResultKHR", (GLADapiproc) glad_vkGetDeferredOperationResultKHR, 2, device, operation);
    return ret;
}
PFN_vkGetDeferredOperationResultKHR glad_debug_vkGetDeferredOperationResultKHR = glad_debug_impl_vkGetDeferredOperationResultKHR;
#endif
PFN_vkGetDescriptorSetLayoutSupport glad_vkGetDescriptorSetLayoutSupport = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo * pCreateInfo, VkDescriptorSetLayoutSupport * pSupport) {
    _pre_call_vulkan_callback("vkGetDescriptorSetLayoutSupport", (GLADapiproc) glad_vkGetDescriptorSetLayoutSupport, 3, device, pCreateInfo, pSupport);
    glad_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    _post_call_vulkan_callback(NULL, "vkGetDescriptorSetLayoutSupport", (GLADapiproc) glad_vkGetDescriptorSetLayoutSupport, 3, device, pCreateInfo, pSupport);
    
}
PFN_vkGetDescriptorSetLayoutSupport glad_debug_vkGetDescriptorSetLayoutSupport = glad_debug_impl_vkGetDescriptorSetLayoutSupport;
PFN_vkGetDescriptorSetLayoutSupportKHR glad_vkGetDescriptorSetLayoutSupportKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo * pCreateInfo, VkDescriptorSetLayoutSupport * pSupport) {
    _pre_call_vulkan_callback("vkGetDescriptorSetLayoutSupportKHR", (GLADapiproc) glad_vkGetDescriptorSetLayoutSupportKHR, 3, device, pCreateInfo, pSupport);
    glad_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
    _post_call_vulkan_callback(NULL, "vkGetDescriptorSetLayoutSupportKHR", (GLADapiproc) glad_vkGetDescriptorSetLayoutSupportKHR, 3, device, pCreateInfo, pSupport);
    
}
PFN_vkGetDescriptorSetLayoutSupportKHR glad_debug_vkGetDescriptorSetLayoutSupportKHR = glad_debug_impl_vkGetDescriptorSetLayoutSupportKHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetDeviceAccelerationStructureCompatibilityKHR glad_vkGetDeviceAccelerationStructureCompatibilityKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionKHR * version) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDeviceAccelerationStructureCompatibilityKHR", (GLADapiproc) glad_vkGetDeviceAccelerationStructureCompatibilityKHR, 2, device, version);
    ret = glad_vkGetDeviceAccelerationStructureCompatibilityKHR(device, version);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceAccelerationStructureCompatibilityKHR", (GLADapiproc) glad_vkGetDeviceAccelerationStructureCompatibilityKHR, 2, device, version);
    return ret;
}
PFN_vkGetDeviceAccelerationStructureCompatibilityKHR glad_debug_vkGetDeviceAccelerationStructureCompatibilityKHR = glad_debug_impl_vkGetDeviceAccelerationStructureCompatibilityKHR;
#endif
PFN_vkGetDeviceGroupPeerMemoryFeatures glad_vkGetDeviceGroupPeerMemoryFeatures = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags * pPeerMemoryFeatures) {
    _pre_call_vulkan_callback("vkGetDeviceGroupPeerMemoryFeatures", (GLADapiproc) glad_vkGetDeviceGroupPeerMemoryFeatures, 5, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    glad_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    _post_call_vulkan_callback(NULL, "vkGetDeviceGroupPeerMemoryFeatures", (GLADapiproc) glad_vkGetDeviceGroupPeerMemoryFeatures, 5, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    
}
PFN_vkGetDeviceGroupPeerMemoryFeatures glad_debug_vkGetDeviceGroupPeerMemoryFeatures = glad_debug_impl_vkGetDeviceGroupPeerMemoryFeatures;
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR glad_vkGetDeviceGroupPeerMemoryFeaturesKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags * pPeerMemoryFeatures) {
    _pre_call_vulkan_callback("vkGetDeviceGroupPeerMemoryFeaturesKHR", (GLADapiproc) glad_vkGetDeviceGroupPeerMemoryFeaturesKHR, 5, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    glad_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    _post_call_vulkan_callback(NULL, "vkGetDeviceGroupPeerMemoryFeaturesKHR", (GLADapiproc) glad_vkGetDeviceGroupPeerMemoryFeaturesKHR, 5, device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    
}
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR glad_debug_vkGetDeviceGroupPeerMemoryFeaturesKHR = glad_debug_impl_vkGetDeviceGroupPeerMemoryFeaturesKHR;
PFN_vkGetDeviceGroupPresentCapabilitiesKHR glad_vkGetDeviceGroupPresentCapabilitiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR * pDeviceGroupPresentCapabilities) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDeviceGroupPresentCapabilitiesKHR", (GLADapiproc) glad_vkGetDeviceGroupPresentCapabilitiesKHR, 2, device, pDeviceGroupPresentCapabilities);
    ret = glad_vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceGroupPresentCapabilitiesKHR", (GLADapiproc) glad_vkGetDeviceGroupPresentCapabilitiesKHR, 2, device, pDeviceGroupPresentCapabilities);
    return ret;
}
PFN_vkGetDeviceGroupPresentCapabilitiesKHR glad_debug_vkGetDeviceGroupPresentCapabilitiesKHR = glad_debug_impl_vkGetDeviceGroupPresentCapabilitiesKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetDeviceGroupSurfacePresentModes2EXT glad_vkGetDeviceGroupSurfacePresentModes2EXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR * pModes) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDeviceGroupSurfacePresentModes2EXT", (GLADapiproc) glad_vkGetDeviceGroupSurfacePresentModes2EXT, 3, device, pSurfaceInfo, pModes);
    ret = glad_vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceGroupSurfacePresentModes2EXT", (GLADapiproc) glad_vkGetDeviceGroupSurfacePresentModes2EXT, 3, device, pSurfaceInfo, pModes);
    return ret;
}
PFN_vkGetDeviceGroupSurfacePresentModes2EXT glad_debug_vkGetDeviceGroupSurfacePresentModes2EXT = glad_debug_impl_vkGetDeviceGroupSurfacePresentModes2EXT;
#endif
PFN_vkGetDeviceGroupSurfacePresentModesKHR glad_vkGetDeviceGroupSurfacePresentModesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR * pModes) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDeviceGroupSurfacePresentModesKHR", (GLADapiproc) glad_vkGetDeviceGroupSurfacePresentModesKHR, 3, device, surface, pModes);
    ret = glad_vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceGroupSurfacePresentModesKHR", (GLADapiproc) glad_vkGetDeviceGroupSurfacePresentModesKHR, 3, device, surface, pModes);
    return ret;
}
PFN_vkGetDeviceGroupSurfacePresentModesKHR glad_debug_vkGetDeviceGroupSurfacePresentModesKHR = glad_debug_impl_vkGetDeviceGroupSurfacePresentModesKHR;
PFN_vkGetDeviceMemoryCommitment glad_vkGetDeviceMemoryCommitment = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize * pCommittedMemoryInBytes) {
    _pre_call_vulkan_callback("vkGetDeviceMemoryCommitment", (GLADapiproc) glad_vkGetDeviceMemoryCommitment, 3, device, memory, pCommittedMemoryInBytes);
    glad_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    _post_call_vulkan_callback(NULL, "vkGetDeviceMemoryCommitment", (GLADapiproc) glad_vkGetDeviceMemoryCommitment, 3, device, memory, pCommittedMemoryInBytes);
    
}
PFN_vkGetDeviceMemoryCommitment glad_debug_vkGetDeviceMemoryCommitment = glad_debug_impl_vkGetDeviceMemoryCommitment;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress glad_vkGetDeviceMemoryOpaqueCaptureAddress = NULL;
static uint64_t GLAD_API_PTR glad_debug_impl_vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo * pInfo) {
    uint64_t ret;
    _pre_call_vulkan_callback("vkGetDeviceMemoryOpaqueCaptureAddress", (GLADapiproc) glad_vkGetDeviceMemoryOpaqueCaptureAddress, 2, device, pInfo);
    ret = glad_vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceMemoryOpaqueCaptureAddress", (GLADapiproc) glad_vkGetDeviceMemoryOpaqueCaptureAddress, 2, device, pInfo);
    return ret;
}
PFN_vkGetDeviceMemoryOpaqueCaptureAddress glad_debug_vkGetDeviceMemoryOpaqueCaptureAddress = glad_debug_impl_vkGetDeviceMemoryOpaqueCaptureAddress;
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR = NULL;
static uint64_t GLAD_API_PTR glad_debug_impl_vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo * pInfo) {
    uint64_t ret;
    _pre_call_vulkan_callback("vkGetDeviceMemoryOpaqueCaptureAddressKHR", (GLADapiproc) glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR, 2, device, pInfo);
    ret = glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceMemoryOpaqueCaptureAddressKHR", (GLADapiproc) glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR, 2, device, pInfo);
    return ret;
}
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR glad_debug_vkGetDeviceMemoryOpaqueCaptureAddressKHR = glad_debug_impl_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
PFN_vkGetDeviceProcAddr glad_vkGetDeviceProcAddr = NULL;
static PFN_vkVoidFunction GLAD_API_PTR glad_debug_impl_vkGetDeviceProcAddr(VkDevice device, const char * pName) {
    PFN_vkVoidFunction ret;
    _pre_call_vulkan_callback("vkGetDeviceProcAddr", (GLADapiproc) glad_vkGetDeviceProcAddr, 2, device, pName);
    ret = glad_vkGetDeviceProcAddr(device, pName);
    _post_call_vulkan_callback((void*) &ret, "vkGetDeviceProcAddr", (GLADapiproc) glad_vkGetDeviceProcAddr, 2, device, pName);
    return ret;
}
PFN_vkGetDeviceProcAddr glad_debug_vkGetDeviceProcAddr = glad_debug_impl_vkGetDeviceProcAddr;
PFN_vkGetDeviceQueue glad_vkGetDeviceQueue = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue * pQueue) {
    _pre_call_vulkan_callback("vkGetDeviceQueue", (GLADapiproc) glad_vkGetDeviceQueue, 4, device, queueFamilyIndex, queueIndex, pQueue);
    glad_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    _post_call_vulkan_callback(NULL, "vkGetDeviceQueue", (GLADapiproc) glad_vkGetDeviceQueue, 4, device, queueFamilyIndex, queueIndex, pQueue);
    
}
PFN_vkGetDeviceQueue glad_debug_vkGetDeviceQueue = glad_debug_impl_vkGetDeviceQueue;
PFN_vkGetDeviceQueue2 glad_vkGetDeviceQueue2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2 * pQueueInfo, VkQueue * pQueue) {
    _pre_call_vulkan_callback("vkGetDeviceQueue2", (GLADapiproc) glad_vkGetDeviceQueue2, 3, device, pQueueInfo, pQueue);
    glad_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    _post_call_vulkan_callback(NULL, "vkGetDeviceQueue2", (GLADapiproc) glad_vkGetDeviceQueue2, 3, device, pQueueInfo, pQueue);
    
}
PFN_vkGetDeviceQueue2 glad_debug_vkGetDeviceQueue2 = glad_debug_impl_vkGetDeviceQueue2;
PFN_vkGetDisplayModeProperties2KHR glad_vkGetDisplayModeProperties2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t * pPropertyCount, VkDisplayModeProperties2KHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDisplayModeProperties2KHR", (GLADapiproc) glad_vkGetDisplayModeProperties2KHR, 4, physicalDevice, display, pPropertyCount, pProperties);
    ret = glad_vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetDisplayModeProperties2KHR", (GLADapiproc) glad_vkGetDisplayModeProperties2KHR, 4, physicalDevice, display, pPropertyCount, pProperties);
    return ret;
}
PFN_vkGetDisplayModeProperties2KHR glad_debug_vkGetDisplayModeProperties2KHR = glad_debug_impl_vkGetDisplayModeProperties2KHR;
PFN_vkGetDisplayModePropertiesKHR glad_vkGetDisplayModePropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t * pPropertyCount, VkDisplayModePropertiesKHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDisplayModePropertiesKHR", (GLADapiproc) glad_vkGetDisplayModePropertiesKHR, 4, physicalDevice, display, pPropertyCount, pProperties);
    ret = glad_vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetDisplayModePropertiesKHR", (GLADapiproc) glad_vkGetDisplayModePropertiesKHR, 4, physicalDevice, display, pPropertyCount, pProperties);
    return ret;
}
PFN_vkGetDisplayModePropertiesKHR glad_debug_vkGetDisplayModePropertiesKHR = glad_debug_impl_vkGetDisplayModePropertiesKHR;
PFN_vkGetDisplayPlaneCapabilities2KHR glad_vkGetDisplayPlaneCapabilities2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR * pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR * pCapabilities) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDisplayPlaneCapabilities2KHR", (GLADapiproc) glad_vkGetDisplayPlaneCapabilities2KHR, 3, physicalDevice, pDisplayPlaneInfo, pCapabilities);
    ret = glad_vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    _post_call_vulkan_callback((void*) &ret, "vkGetDisplayPlaneCapabilities2KHR", (GLADapiproc) glad_vkGetDisplayPlaneCapabilities2KHR, 3, physicalDevice, pDisplayPlaneInfo, pCapabilities);
    return ret;
}
PFN_vkGetDisplayPlaneCapabilities2KHR glad_debug_vkGetDisplayPlaneCapabilities2KHR = glad_debug_impl_vkGetDisplayPlaneCapabilities2KHR;
PFN_vkGetDisplayPlaneCapabilitiesKHR glad_vkGetDisplayPlaneCapabilitiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR * pCapabilities) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDisplayPlaneCapabilitiesKHR", (GLADapiproc) glad_vkGetDisplayPlaneCapabilitiesKHR, 4, physicalDevice, mode, planeIndex, pCapabilities);
    ret = glad_vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    _post_call_vulkan_callback((void*) &ret, "vkGetDisplayPlaneCapabilitiesKHR", (GLADapiproc) glad_vkGetDisplayPlaneCapabilitiesKHR, 4, physicalDevice, mode, planeIndex, pCapabilities);
    return ret;
}
PFN_vkGetDisplayPlaneCapabilitiesKHR glad_debug_vkGetDisplayPlaneCapabilitiesKHR = glad_debug_impl_vkGetDisplayPlaneCapabilitiesKHR;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR glad_vkGetDisplayPlaneSupportedDisplaysKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t * pDisplayCount, VkDisplayKHR * pDisplays) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetDisplayPlaneSupportedDisplaysKHR", (GLADapiproc) glad_vkGetDisplayPlaneSupportedDisplaysKHR, 4, physicalDevice, planeIndex, pDisplayCount, pDisplays);
    ret = glad_vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    _post_call_vulkan_callback((void*) &ret, "vkGetDisplayPlaneSupportedDisplaysKHR", (GLADapiproc) glad_vkGetDisplayPlaneSupportedDisplaysKHR, 4, physicalDevice, planeIndex, pDisplayCount, pDisplays);
    return ret;
}
PFN_vkGetDisplayPlaneSupportedDisplaysKHR glad_debug_vkGetDisplayPlaneSupportedDisplaysKHR = glad_debug_impl_vkGetDisplayPlaneSupportedDisplaysKHR;
PFN_vkGetEventStatus glad_vkGetEventStatus = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetEventStatus(VkDevice device, VkEvent event) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetEventStatus", (GLADapiproc) glad_vkGetEventStatus, 2, device, event);
    ret = glad_vkGetEventStatus(device, event);
    _post_call_vulkan_callback((void*) &ret, "vkGetEventStatus", (GLADapiproc) glad_vkGetEventStatus, 2, device, event);
    return ret;
}
PFN_vkGetEventStatus glad_debug_vkGetEventStatus = glad_debug_impl_vkGetEventStatus;
PFN_vkGetFenceFdKHR glad_vkGetFenceFdKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR * pGetFdInfo, int * pFd) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetFenceFdKHR", (GLADapiproc) glad_vkGetFenceFdKHR, 3, device, pGetFdInfo, pFd);
    ret = glad_vkGetFenceFdKHR(device, pGetFdInfo, pFd);
    _post_call_vulkan_callback((void*) &ret, "vkGetFenceFdKHR", (GLADapiproc) glad_vkGetFenceFdKHR, 3, device, pGetFdInfo, pFd);
    return ret;
}
PFN_vkGetFenceFdKHR glad_debug_vkGetFenceFdKHR = glad_debug_impl_vkGetFenceFdKHR;
PFN_vkGetFenceStatus glad_vkGetFenceStatus = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetFenceStatus(VkDevice device, VkFence fence) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetFenceStatus", (GLADapiproc) glad_vkGetFenceStatus, 2, device, fence);
    ret = glad_vkGetFenceStatus(device, fence);
    _post_call_vulkan_callback((void*) &ret, "vkGetFenceStatus", (GLADapiproc) glad_vkGetFenceStatus, 2, device, fence);
    return ret;
}
PFN_vkGetFenceStatus glad_debug_vkGetFenceStatus = glad_debug_impl_vkGetFenceStatus;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetFenceWin32HandleKHR glad_vkGetFenceWin32HandleKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetFenceWin32HandleKHR", (GLADapiproc) glad_vkGetFenceWin32HandleKHR, 3, device, pGetWin32HandleInfo, pHandle);
    ret = glad_vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    _post_call_vulkan_callback((void*) &ret, "vkGetFenceWin32HandleKHR", (GLADapiproc) glad_vkGetFenceWin32HandleKHR, 3, device, pGetWin32HandleInfo, pHandle);
    return ret;
}
PFN_vkGetFenceWin32HandleKHR glad_debug_vkGetFenceWin32HandleKHR = glad_debug_impl_vkGetFenceWin32HandleKHR;
#endif
PFN_vkGetImageDrmFormatModifierPropertiesEXT glad_vkGetImageDrmFormatModifierPropertiesEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetImageDrmFormatModifierPropertiesEXT", (GLADapiproc) glad_vkGetImageDrmFormatModifierPropertiesEXT, 3, device, image, pProperties);
    ret = glad_vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetImageDrmFormatModifierPropertiesEXT", (GLADapiproc) glad_vkGetImageDrmFormatModifierPropertiesEXT, 3, device, image, pProperties);
    return ret;
}
PFN_vkGetImageDrmFormatModifierPropertiesEXT glad_debug_vkGetImageDrmFormatModifierPropertiesEXT = glad_debug_impl_vkGetImageDrmFormatModifierPropertiesEXT;
PFN_vkGetImageMemoryRequirements glad_vkGetImageMemoryRequirements = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetImageMemoryRequirements", (GLADapiproc) glad_vkGetImageMemoryRequirements, 3, device, image, pMemoryRequirements);
    glad_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetImageMemoryRequirements", (GLADapiproc) glad_vkGetImageMemoryRequirements, 3, device, image, pMemoryRequirements);
    
}
PFN_vkGetImageMemoryRequirements glad_debug_vkGetImageMemoryRequirements = glad_debug_impl_vkGetImageMemoryRequirements;
PFN_vkGetImageMemoryRequirements2 glad_vkGetImageMemoryRequirements2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetImageMemoryRequirements2", (GLADapiproc) glad_vkGetImageMemoryRequirements2, 3, device, pInfo, pMemoryRequirements);
    glad_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetImageMemoryRequirements2", (GLADapiproc) glad_vkGetImageMemoryRequirements2, 3, device, pInfo, pMemoryRequirements);
    
}
PFN_vkGetImageMemoryRequirements2 glad_debug_vkGetImageMemoryRequirements2 = glad_debug_impl_vkGetImageMemoryRequirements2;
PFN_vkGetImageMemoryRequirements2KHR glad_vkGetImageMemoryRequirements2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetImageMemoryRequirements2KHR", (GLADapiproc) glad_vkGetImageMemoryRequirements2KHR, 3, device, pInfo, pMemoryRequirements);
    glad_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetImageMemoryRequirements2KHR", (GLADapiproc) glad_vkGetImageMemoryRequirements2KHR, 3, device, pInfo, pMemoryRequirements);
    
}
PFN_vkGetImageMemoryRequirements2KHR glad_debug_vkGetImageMemoryRequirements2KHR = glad_debug_impl_vkGetImageMemoryRequirements2KHR;
PFN_vkGetImageSparseMemoryRequirements glad_vkGetImageSparseMemoryRequirements = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t * pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements * pSparseMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetImageSparseMemoryRequirements", (GLADapiproc) glad_vkGetImageSparseMemoryRequirements, 4, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    glad_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetImageSparseMemoryRequirements", (GLADapiproc) glad_vkGetImageSparseMemoryRequirements, 4, device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
}
PFN_vkGetImageSparseMemoryRequirements glad_debug_vkGetImageSparseMemoryRequirements = glad_debug_impl_vkGetImageSparseMemoryRequirements;
PFN_vkGetImageSparseMemoryRequirements2 glad_vkGetImageSparseMemoryRequirements2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 * pInfo, uint32_t * pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 * pSparseMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetImageSparseMemoryRequirements2", (GLADapiproc) glad_vkGetImageSparseMemoryRequirements2, 4, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    glad_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetImageSparseMemoryRequirements2", (GLADapiproc) glad_vkGetImageSparseMemoryRequirements2, 4, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
}
PFN_vkGetImageSparseMemoryRequirements2 glad_debug_vkGetImageSparseMemoryRequirements2 = glad_debug_impl_vkGetImageSparseMemoryRequirements2;
PFN_vkGetImageSparseMemoryRequirements2KHR glad_vkGetImageSparseMemoryRequirements2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 * pInfo, uint32_t * pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 * pSparseMemoryRequirements) {
    _pre_call_vulkan_callback("vkGetImageSparseMemoryRequirements2KHR", (GLADapiproc) glad_vkGetImageSparseMemoryRequirements2KHR, 4, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    glad_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    _post_call_vulkan_callback(NULL, "vkGetImageSparseMemoryRequirements2KHR", (GLADapiproc) glad_vkGetImageSparseMemoryRequirements2KHR, 4, device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    
}
PFN_vkGetImageSparseMemoryRequirements2KHR glad_debug_vkGetImageSparseMemoryRequirements2KHR = glad_debug_impl_vkGetImageSparseMemoryRequirements2KHR;
PFN_vkGetImageSubresourceLayout glad_vkGetImageSubresourceLayout = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource * pSubresource, VkSubresourceLayout * pLayout) {
    _pre_call_vulkan_callback("vkGetImageSubresourceLayout", (GLADapiproc) glad_vkGetImageSubresourceLayout, 4, device, image, pSubresource, pLayout);
    glad_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    _post_call_vulkan_callback(NULL, "vkGetImageSubresourceLayout", (GLADapiproc) glad_vkGetImageSubresourceLayout, 4, device, image, pSubresource, pLayout);
    
}
PFN_vkGetImageSubresourceLayout glad_debug_vkGetImageSubresourceLayout = glad_debug_impl_vkGetImageSubresourceLayout;
PFN_vkGetInstanceProcAddr glad_vkGetInstanceProcAddr = NULL;
static PFN_vkVoidFunction GLAD_API_PTR glad_debug_impl_vkGetInstanceProcAddr(VkInstance instance, const char * pName) {
    PFN_vkVoidFunction ret;
    _pre_call_vulkan_callback("vkGetInstanceProcAddr", (GLADapiproc) glad_vkGetInstanceProcAddr, 2, instance, pName);
    ret = glad_vkGetInstanceProcAddr(instance, pName);
    _post_call_vulkan_callback((void*) &ret, "vkGetInstanceProcAddr", (GLADapiproc) glad_vkGetInstanceProcAddr, 2, instance, pName);
    return ret;
}
PFN_vkGetInstanceProcAddr glad_debug_vkGetInstanceProcAddr = glad_debug_impl_vkGetInstanceProcAddr;
PFN_vkGetMemoryFdKHR glad_vkGetMemoryFdKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR * pGetFdInfo, int * pFd) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetMemoryFdKHR", (GLADapiproc) glad_vkGetMemoryFdKHR, 3, device, pGetFdInfo, pFd);
    ret = glad_vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
    _post_call_vulkan_callback((void*) &ret, "vkGetMemoryFdKHR", (GLADapiproc) glad_vkGetMemoryFdKHR, 3, device, pGetFdInfo, pFd);
    return ret;
}
PFN_vkGetMemoryFdKHR glad_debug_vkGetMemoryFdKHR = glad_debug_impl_vkGetMemoryFdKHR;
PFN_vkGetMemoryFdPropertiesKHR glad_vkGetMemoryFdPropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR * pMemoryFdProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetMemoryFdPropertiesKHR", (GLADapiproc) glad_vkGetMemoryFdPropertiesKHR, 4, device, handleType, fd, pMemoryFdProperties);
    ret = glad_vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetMemoryFdPropertiesKHR", (GLADapiproc) glad_vkGetMemoryFdPropertiesKHR, 4, device, handleType, fd, pMemoryFdProperties);
    return ret;
}
PFN_vkGetMemoryFdPropertiesKHR glad_debug_vkGetMemoryFdPropertiesKHR = glad_debug_impl_vkGetMemoryFdPropertiesKHR;
PFN_vkGetMemoryHostPointerPropertiesEXT glad_vkGetMemoryHostPointerPropertiesEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void * pHostPointer, VkMemoryHostPointerPropertiesEXT * pMemoryHostPointerProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetMemoryHostPointerPropertiesEXT", (GLADapiproc) glad_vkGetMemoryHostPointerPropertiesEXT, 4, device, handleType, pHostPointer, pMemoryHostPointerProperties);
    ret = glad_vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetMemoryHostPointerPropertiesEXT", (GLADapiproc) glad_vkGetMemoryHostPointerPropertiesEXT, 4, device, handleType, pHostPointer, pMemoryHostPointerProperties);
    return ret;
}
PFN_vkGetMemoryHostPointerPropertiesEXT glad_debug_vkGetMemoryHostPointerPropertiesEXT = glad_debug_impl_vkGetMemoryHostPointerPropertiesEXT;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetMemoryWin32HandleKHR glad_vkGetMemoryWin32HandleKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetMemoryWin32HandleKHR", (GLADapiproc) glad_vkGetMemoryWin32HandleKHR, 3, device, pGetWin32HandleInfo, pHandle);
    ret = glad_vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    _post_call_vulkan_callback((void*) &ret, "vkGetMemoryWin32HandleKHR", (GLADapiproc) glad_vkGetMemoryWin32HandleKHR, 3, device, pGetWin32HandleInfo, pHandle);
    return ret;
}
PFN_vkGetMemoryWin32HandleKHR glad_debug_vkGetMemoryWin32HandleKHR = glad_debug_impl_vkGetMemoryWin32HandleKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetMemoryWin32HandlePropertiesKHR glad_vkGetMemoryWin32HandlePropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR * pMemoryWin32HandleProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetMemoryWin32HandlePropertiesKHR", (GLADapiproc) glad_vkGetMemoryWin32HandlePropertiesKHR, 4, device, handleType, handle, pMemoryWin32HandleProperties);
    ret = glad_vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetMemoryWin32HandlePropertiesKHR", (GLADapiproc) glad_vkGetMemoryWin32HandlePropertiesKHR, 4, device, handleType, handle, pMemoryWin32HandleProperties);
    return ret;
}
PFN_vkGetMemoryWin32HandlePropertiesKHR glad_debug_vkGetMemoryWin32HandlePropertiesKHR = glad_debug_impl_vkGetMemoryWin32HandlePropertiesKHR;
#endif
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT glad_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t * pTimeDomainCount, VkTimeDomainEXT * pTimeDomains) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", (GLADapiproc) glad_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT, 3, physicalDevice, pTimeDomainCount, pTimeDomains);
    ret = glad_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT", (GLADapiproc) glad_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT, 3, physicalDevice, pTimeDomainCount, pTimeDomains);
    return ret;
}
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT glad_debug_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = glad_debug_impl_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT glad_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = NULL;
static VkBool32 GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB * dfb) {
    VkBool32 ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceDirectFBPresentationSupportEXT", (GLADapiproc) glad_vkGetPhysicalDeviceDirectFBPresentationSupportEXT, 3, physicalDevice, queueFamilyIndex, dfb);
    ret = glad_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT", (GLADapiproc) glad_vkGetPhysicalDeviceDirectFBPresentationSupportEXT, 3, physicalDevice, queueFamilyIndex, dfb);
    return ret;
}
PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT glad_debug_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = glad_debug_impl_vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayPlaneProperties2KHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceDisplayPlaneProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR, 3, physicalDevice, pPropertyCount, pProperties);
    ret = glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR, 3, physicalDevice, pPropertyCount, pProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR glad_debug_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayPlanePropertiesKHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR, 3, physicalDevice, pPropertyCount, pProperties);
    ret = glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR, 3, physicalDevice, pPropertyCount, pProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR glad_debug_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
PFN_vkGetPhysicalDeviceDisplayProperties2KHR glad_vkGetPhysicalDeviceDisplayProperties2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayProperties2KHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceDisplayProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayProperties2KHR, 3, physicalDevice, pPropertyCount, pProperties);
    ret = glad_vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceDisplayProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayProperties2KHR, 3, physicalDevice, pPropertyCount, pProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceDisplayProperties2KHR glad_debug_vkGetPhysicalDeviceDisplayProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceDisplayProperties2KHR;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR glad_vkGetPhysicalDeviceDisplayPropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayPropertiesKHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceDisplayPropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayPropertiesKHR, 3, physicalDevice, pPropertyCount, pProperties);
    ret = glad_vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceDisplayPropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceDisplayPropertiesKHR, 3, physicalDevice, pPropertyCount, pProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR glad_debug_vkGetPhysicalDeviceDisplayPropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceDisplayPropertiesKHR;
PFN_vkGetPhysicalDeviceExternalBufferProperties glad_vkGetPhysicalDeviceExternalBufferProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo * pExternalBufferInfo, VkExternalBufferProperties * pExternalBufferProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceExternalBufferProperties", (GLADapiproc) glad_vkGetPhysicalDeviceExternalBufferProperties, 3, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    glad_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceExternalBufferProperties", (GLADapiproc) glad_vkGetPhysicalDeviceExternalBufferProperties, 3, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    
}
PFN_vkGetPhysicalDeviceExternalBufferProperties glad_debug_vkGetPhysicalDeviceExternalBufferProperties = glad_debug_impl_vkGetPhysicalDeviceExternalBufferProperties;
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo * pExternalBufferInfo, VkExternalBufferProperties * pExternalBufferProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceExternalBufferPropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR, 3, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceExternalBufferPropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR, 3, physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    
}
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR glad_debug_vkGetPhysicalDeviceExternalBufferPropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
PFN_vkGetPhysicalDeviceExternalFenceProperties glad_vkGetPhysicalDeviceExternalFenceProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo * pExternalFenceInfo, VkExternalFenceProperties * pExternalFenceProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceExternalFenceProperties", (GLADapiproc) glad_vkGetPhysicalDeviceExternalFenceProperties, 3, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    glad_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceExternalFenceProperties", (GLADapiproc) glad_vkGetPhysicalDeviceExternalFenceProperties, 3, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    
}
PFN_vkGetPhysicalDeviceExternalFenceProperties glad_debug_vkGetPhysicalDeviceExternalFenceProperties = glad_debug_impl_vkGetPhysicalDeviceExternalFenceProperties;
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR glad_vkGetPhysicalDeviceExternalFencePropertiesKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo * pExternalFenceInfo, VkExternalFenceProperties * pExternalFenceProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceExternalFencePropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceExternalFencePropertiesKHR, 3, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    glad_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceExternalFencePropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceExternalFencePropertiesKHR, 3, physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    
}
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR glad_debug_vkGetPhysicalDeviceExternalFencePropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceExternalFencePropertiesKHR;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties glad_vkGetPhysicalDeviceExternalSemaphoreProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo * pExternalSemaphoreInfo, VkExternalSemaphoreProperties * pExternalSemaphoreProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceExternalSemaphoreProperties", (GLADapiproc) glad_vkGetPhysicalDeviceExternalSemaphoreProperties, 3, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    glad_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceExternalSemaphoreProperties", (GLADapiproc) glad_vkGetPhysicalDeviceExternalSemaphoreProperties, 3, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    
}
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties glad_debug_vkGetPhysicalDeviceExternalSemaphoreProperties = glad_debug_impl_vkGetPhysicalDeviceExternalSemaphoreProperties;
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo * pExternalSemaphoreInfo, VkExternalSemaphoreProperties * pExternalSemaphoreProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR, 3, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR, 3, physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    
}
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR glad_debug_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
PFN_vkGetPhysicalDeviceFeatures glad_vkGetPhysicalDeviceFeatures = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures * pFeatures) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceFeatures", (GLADapiproc) glad_vkGetPhysicalDeviceFeatures, 2, physicalDevice, pFeatures);
    glad_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceFeatures", (GLADapiproc) glad_vkGetPhysicalDeviceFeatures, 2, physicalDevice, pFeatures);
    
}
PFN_vkGetPhysicalDeviceFeatures glad_debug_vkGetPhysicalDeviceFeatures = glad_debug_impl_vkGetPhysicalDeviceFeatures;
PFN_vkGetPhysicalDeviceFeatures2 glad_vkGetPhysicalDeviceFeatures2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2 * pFeatures) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceFeatures2", (GLADapiproc) glad_vkGetPhysicalDeviceFeatures2, 2, physicalDevice, pFeatures);
    glad_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceFeatures2", (GLADapiproc) glad_vkGetPhysicalDeviceFeatures2, 2, physicalDevice, pFeatures);
    
}
PFN_vkGetPhysicalDeviceFeatures2 glad_debug_vkGetPhysicalDeviceFeatures2 = glad_debug_impl_vkGetPhysicalDeviceFeatures2;
PFN_vkGetPhysicalDeviceFeatures2KHR glad_vkGetPhysicalDeviceFeatures2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2 * pFeatures) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceFeatures2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceFeatures2KHR, 2, physicalDevice, pFeatures);
    glad_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceFeatures2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceFeatures2KHR, 2, physicalDevice, pFeatures);
    
}
PFN_vkGetPhysicalDeviceFeatures2KHR glad_debug_vkGetPhysicalDeviceFeatures2KHR = glad_debug_impl_vkGetPhysicalDeviceFeatures2KHR;
PFN_vkGetPhysicalDeviceFormatProperties glad_vkGetPhysicalDeviceFormatProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties * pFormatProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceFormatProperties", (GLADapiproc) glad_vkGetPhysicalDeviceFormatProperties, 3, physicalDevice, format, pFormatProperties);
    glad_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceFormatProperties", (GLADapiproc) glad_vkGetPhysicalDeviceFormatProperties, 3, physicalDevice, format, pFormatProperties);
    
}
PFN_vkGetPhysicalDeviceFormatProperties glad_debug_vkGetPhysicalDeviceFormatProperties = glad_debug_impl_vkGetPhysicalDeviceFormatProperties;
PFN_vkGetPhysicalDeviceFormatProperties2 glad_vkGetPhysicalDeviceFormatProperties2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2 * pFormatProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceFormatProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceFormatProperties2, 3, physicalDevice, format, pFormatProperties);
    glad_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceFormatProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceFormatProperties2, 3, physicalDevice, format, pFormatProperties);
    
}
PFN_vkGetPhysicalDeviceFormatProperties2 glad_debug_vkGetPhysicalDeviceFormatProperties2 = glad_debug_impl_vkGetPhysicalDeviceFormatProperties2;
PFN_vkGetPhysicalDeviceFormatProperties2KHR glad_vkGetPhysicalDeviceFormatProperties2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2 * pFormatProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceFormatProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceFormatProperties2KHR, 3, physicalDevice, format, pFormatProperties);
    glad_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceFormatProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceFormatProperties2KHR, 3, physicalDevice, format, pFormatProperties);
    
}
PFN_vkGetPhysicalDeviceFormatProperties2KHR glad_debug_vkGetPhysicalDeviceFormatProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceFormatProperties2KHR;
PFN_vkGetPhysicalDeviceImageFormatProperties glad_vkGetPhysicalDeviceImageFormatProperties = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties * pImageFormatProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceImageFormatProperties", (GLADapiproc) glad_vkGetPhysicalDeviceImageFormatProperties, 7, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    ret = glad_vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceImageFormatProperties", (GLADapiproc) glad_vkGetPhysicalDeviceImageFormatProperties, 7, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceImageFormatProperties glad_debug_vkGetPhysicalDeviceImageFormatProperties = glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties;
PFN_vkGetPhysicalDeviceImageFormatProperties2 glad_vkGetPhysicalDeviceImageFormatProperties2 = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2 * pImageFormatInfo, VkImageFormatProperties2 * pImageFormatProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceImageFormatProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceImageFormatProperties2, 3, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    ret = glad_vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceImageFormatProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceImageFormatProperties2, 3, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceImageFormatProperties2 glad_debug_vkGetPhysicalDeviceImageFormatProperties2 = glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties2;
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR glad_vkGetPhysicalDeviceImageFormatProperties2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2 * pImageFormatInfo, VkImageFormatProperties2 * pImageFormatProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceImageFormatProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceImageFormatProperties2KHR, 3, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    ret = glad_vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceImageFormatProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceImageFormatProperties2KHR, 3, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR glad_debug_vkGetPhysicalDeviceImageFormatProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties2KHR;
PFN_vkGetPhysicalDeviceMemoryProperties glad_vkGetPhysicalDeviceMemoryProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties * pMemoryProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceMemoryProperties", (GLADapiproc) glad_vkGetPhysicalDeviceMemoryProperties, 2, physicalDevice, pMemoryProperties);
    glad_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceMemoryProperties", (GLADapiproc) glad_vkGetPhysicalDeviceMemoryProperties, 2, physicalDevice, pMemoryProperties);
    
}
PFN_vkGetPhysicalDeviceMemoryProperties glad_debug_vkGetPhysicalDeviceMemoryProperties = glad_debug_impl_vkGetPhysicalDeviceMemoryProperties;
PFN_vkGetPhysicalDeviceMemoryProperties2 glad_vkGetPhysicalDeviceMemoryProperties2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2 * pMemoryProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceMemoryProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceMemoryProperties2, 2, physicalDevice, pMemoryProperties);
    glad_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceMemoryProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceMemoryProperties2, 2, physicalDevice, pMemoryProperties);
    
}
PFN_vkGetPhysicalDeviceMemoryProperties2 glad_debug_vkGetPhysicalDeviceMemoryProperties2 = glad_debug_impl_vkGetPhysicalDeviceMemoryProperties2;
PFN_vkGetPhysicalDeviceMemoryProperties2KHR glad_vkGetPhysicalDeviceMemoryProperties2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2 * pMemoryProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceMemoryProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceMemoryProperties2KHR, 2, physicalDevice, pMemoryProperties);
    glad_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceMemoryProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceMemoryProperties2KHR, 2, physicalDevice, pMemoryProperties);
    
}
PFN_vkGetPhysicalDeviceMemoryProperties2KHR glad_debug_vkGetPhysicalDeviceMemoryProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceMemoryProperties2KHR;
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT glad_vkGetPhysicalDeviceMultisamplePropertiesEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT * pMultisampleProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceMultisamplePropertiesEXT", (GLADapiproc) glad_vkGetPhysicalDeviceMultisamplePropertiesEXT, 3, physicalDevice, samples, pMultisampleProperties);
    glad_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceMultisamplePropertiesEXT", (GLADapiproc) glad_vkGetPhysicalDeviceMultisamplePropertiesEXT, 3, physicalDevice, samples, pMultisampleProperties);
    
}
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT glad_debug_vkGetPhysicalDeviceMultisamplePropertiesEXT = glad_debug_impl_vkGetPhysicalDeviceMultisamplePropertiesEXT;
PFN_vkGetPhysicalDevicePresentRectanglesKHR glad_vkGetPhysicalDevicePresentRectanglesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t * pRectCount, VkRect2D * pRects) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDevicePresentRectanglesKHR", (GLADapiproc) glad_vkGetPhysicalDevicePresentRectanglesKHR, 4, physicalDevice, surface, pRectCount, pRects);
    ret = glad_vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDevicePresentRectanglesKHR", (GLADapiproc) glad_vkGetPhysicalDevicePresentRectanglesKHR, 4, physicalDevice, surface, pRectCount, pRects);
    return ret;
}
PFN_vkGetPhysicalDevicePresentRectanglesKHR glad_debug_vkGetPhysicalDevicePresentRectanglesKHR = glad_debug_impl_vkGetPhysicalDevicePresentRectanglesKHR;
PFN_vkGetPhysicalDeviceProperties glad_vkGetPhysicalDeviceProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties * pProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceProperties", (GLADapiproc) glad_vkGetPhysicalDeviceProperties, 2, physicalDevice, pProperties);
    glad_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceProperties", (GLADapiproc) glad_vkGetPhysicalDeviceProperties, 2, physicalDevice, pProperties);
    
}
PFN_vkGetPhysicalDeviceProperties glad_debug_vkGetPhysicalDeviceProperties = glad_debug_impl_vkGetPhysicalDeviceProperties;
PFN_vkGetPhysicalDeviceProperties2 glad_vkGetPhysicalDeviceProperties2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2 * pProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceProperties2, 2, physicalDevice, pProperties);
    glad_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceProperties2, 2, physicalDevice, pProperties);
    
}
PFN_vkGetPhysicalDeviceProperties2 glad_debug_vkGetPhysicalDeviceProperties2 = glad_debug_impl_vkGetPhysicalDeviceProperties2;
PFN_vkGetPhysicalDeviceProperties2KHR glad_vkGetPhysicalDeviceProperties2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2 * pProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceProperties2KHR, 2, physicalDevice, pProperties);
    glad_vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceProperties2KHR, 2, physicalDevice, pProperties);
    
}
PFN_vkGetPhysicalDeviceProperties2KHR glad_debug_vkGetPhysicalDeviceProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceProperties2KHR;
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR * pPerformanceQueryCreateInfo, uint32_t * pNumPasses) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR, 3, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR, 3, physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
    
}
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR glad_debug_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
PFN_vkGetPhysicalDeviceQueueFamilyProperties glad_vkGetPhysicalDeviceQueueFamilyProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, VkQueueFamilyProperties * pQueueFamilyProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceQueueFamilyProperties", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyProperties, 3, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    glad_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceQueueFamilyProperties", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyProperties, 3, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    
}
PFN_vkGetPhysicalDeviceQueueFamilyProperties glad_debug_vkGetPhysicalDeviceQueueFamilyProperties = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 glad_vkGetPhysicalDeviceQueueFamilyProperties2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, VkQueueFamilyProperties2 * pQueueFamilyProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceQueueFamilyProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyProperties2, 3, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    glad_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceQueueFamilyProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyProperties2, 3, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    
}
PFN_vkGetPhysicalDeviceQueueFamilyProperties2 glad_debug_vkGetPhysicalDeviceQueueFamilyProperties2 = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties2;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, VkQueueFamilyProperties2 * pQueueFamilyProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceQueueFamilyProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR, 3, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceQueueFamilyProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR, 3, physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    
}
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR glad_debug_vkGetPhysicalDeviceQueueFamilyProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties glad_vkGetPhysicalDeviceSparseImageFormatProperties = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t * pPropertyCount, VkSparseImageFormatProperties * pProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSparseImageFormatProperties", (GLADapiproc) glad_vkGetPhysicalDeviceSparseImageFormatProperties, 8, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    glad_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceSparseImageFormatProperties", (GLADapiproc) glad_vkGetPhysicalDeviceSparseImageFormatProperties, 8, physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    
}
PFN_vkGetPhysicalDeviceSparseImageFormatProperties glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties = glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2 * pFormatInfo, uint32_t * pPropertyCount, VkSparseImageFormatProperties2 * pProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSparseImageFormatProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceSparseImageFormatProperties2, 4, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceSparseImageFormatProperties2", (GLADapiproc) glad_vkGetPhysicalDeviceSparseImageFormatProperties2, 4, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    
}
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties2 = glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties2;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2 * pFormatInfo, uint32_t * pPropertyCount, VkSparseImageFormatProperties2 * pProperties) {
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSparseImageFormatProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR, 4, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    _post_call_vulkan_callback(NULL, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR, 4, physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    
}
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT * pSurfaceCapabilities) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfaceCapabilities2EXT", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT, 3, physicalDevice, surface, pSurfaceCapabilities);
    ret = glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfaceCapabilities2EXT", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT, 3, physicalDevice, surface, pSurfaceCapabilities);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT glad_debug_vkGetPhysicalDeviceSurfaceCapabilities2EXT = glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilities2EXT;
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, VkSurfaceCapabilities2KHR * pSurfaceCapabilities) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfaceCapabilities2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR, 3, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    ret = glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfaceCapabilities2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR, 3, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR glad_debug_vkGetPhysicalDeviceSurfaceCapabilities2KHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilities2KHR;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR * pSurfaceCapabilities) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfaceCapabilitiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, 3, physicalDevice, surface, pSurfaceCapabilities);
    ret = glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, 3, physicalDevice, surface, pSurfaceCapabilities);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR glad_debug_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR glad_vkGetPhysicalDeviceSurfaceFormats2KHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, uint32_t * pSurfaceFormatCount, VkSurfaceFormat2KHR * pSurfaceFormats) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfaceFormats2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceFormats2KHR, 4, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    ret = glad_vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfaceFormats2KHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceFormats2KHR, 4, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR glad_debug_vkGetPhysicalDeviceSurfaceFormats2KHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceFormats2KHR;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR glad_vkGetPhysicalDeviceSurfaceFormatsKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t * pSurfaceFormatCount, VkSurfaceFormatKHR * pSurfaceFormats) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfaceFormatsKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceFormatsKHR, 4, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    ret = glad_vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfaceFormatsKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceFormatsKHR, 4, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR glad_debug_vkGetPhysicalDeviceSurfaceFormatsKHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceFormatsKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT glad_vkGetPhysicalDeviceSurfacePresentModes2EXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, uint32_t * pPresentModeCount, VkPresentModeKHR * pPresentModes) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfacePresentModes2EXT", (GLADapiproc) glad_vkGetPhysicalDeviceSurfacePresentModes2EXT, 4, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    ret = glad_vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfacePresentModes2EXT", (GLADapiproc) glad_vkGetPhysicalDeviceSurfacePresentModes2EXT, 4, physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT glad_debug_vkGetPhysicalDeviceSurfacePresentModes2EXT = glad_debug_impl_vkGetPhysicalDeviceSurfacePresentModes2EXT;
#endif
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR glad_vkGetPhysicalDeviceSurfacePresentModesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t * pPresentModeCount, VkPresentModeKHR * pPresentModes) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfacePresentModesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfacePresentModesKHR, 4, physicalDevice, surface, pPresentModeCount, pPresentModes);
    ret = glad_vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfacePresentModesKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfacePresentModesKHR, 4, physicalDevice, surface, pPresentModeCount, pPresentModes);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR glad_debug_vkGetPhysicalDeviceSurfacePresentModesKHR = glad_debug_impl_vkGetPhysicalDeviceSurfacePresentModesKHR;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR glad_vkGetPhysicalDeviceSurfaceSupportKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32 * pSupported) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceSurfaceSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceSupportKHR, 4, physicalDevice, queueFamilyIndex, surface, pSupported);
    ret = glad_vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceSurfaceSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceSurfaceSupportKHR, 4, physicalDevice, queueFamilyIndex, surface, pSupported);
    return ret;
}
PFN_vkGetPhysicalDeviceSurfaceSupportKHR glad_debug_vkGetPhysicalDeviceSurfaceSupportKHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceSupportKHR;
PFN_vkGetPhysicalDeviceToolPropertiesEXT glad_vkGetPhysicalDeviceToolPropertiesEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t * pToolCount, VkPhysicalDeviceToolPropertiesEXT * pToolProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceToolPropertiesEXT", (GLADapiproc) glad_vkGetPhysicalDeviceToolPropertiesEXT, 3, physicalDevice, pToolCount, pToolProperties);
    ret = glad_vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceToolPropertiesEXT", (GLADapiproc) glad_vkGetPhysicalDeviceToolPropertiesEXT, 3, physicalDevice, pToolCount, pToolProperties);
    return ret;
}
PFN_vkGetPhysicalDeviceToolPropertiesEXT glad_debug_vkGetPhysicalDeviceToolPropertiesEXT = glad_debug_impl_vkGetPhysicalDeviceToolPropertiesEXT;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR glad_vkGetPhysicalDeviceWaylandPresentationSupportKHR = NULL;
static VkBool32 GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display * display) {
    VkBool32 ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceWaylandPresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceWaylandPresentationSupportKHR, 3, physicalDevice, queueFamilyIndex, display);
    ret = glad_vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceWaylandPresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceWaylandPresentationSupportKHR, 3, physicalDevice, queueFamilyIndex, display);
    return ret;
}
PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR glad_debug_vkGetPhysicalDeviceWaylandPresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR glad_vkGetPhysicalDeviceWin32PresentationSupportKHR = NULL;
static VkBool32 GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) {
    VkBool32 ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceWin32PresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceWin32PresentationSupportKHR, 2, physicalDevice, queueFamilyIndex);
    ret = glad_vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceWin32PresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceWin32PresentationSupportKHR, 2, physicalDevice, queueFamilyIndex);
    return ret;
}
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR glad_debug_vkGetPhysicalDeviceWin32PresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR glad_vkGetPhysicalDeviceXcbPresentationSupportKHR = NULL;
static VkBool32 GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t * connection, xcb_visualid_t visual_id) {
    VkBool32 ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceXcbPresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceXcbPresentationSupportKHR, 4, physicalDevice, queueFamilyIndex, connection, visual_id);
    ret = glad_vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceXcbPresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceXcbPresentationSupportKHR, 4, physicalDevice, queueFamilyIndex, connection, visual_id);
    return ret;
}
PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR glad_debug_vkGetPhysicalDeviceXcbPresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR glad_vkGetPhysicalDeviceXlibPresentationSupportKHR = NULL;
static VkBool32 GLAD_API_PTR glad_debug_impl_vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display * dpy, VisualID visualID) {
    VkBool32 ret;
    _pre_call_vulkan_callback("vkGetPhysicalDeviceXlibPresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceXlibPresentationSupportKHR, 4, physicalDevice, queueFamilyIndex, dpy, visualID);
    ret = glad_vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    _post_call_vulkan_callback((void*) &ret, "vkGetPhysicalDeviceXlibPresentationSupportKHR", (GLADapiproc) glad_vkGetPhysicalDeviceXlibPresentationSupportKHR, 4, physicalDevice, queueFamilyIndex, dpy, visualID);
    return ret;
}
PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR glad_debug_vkGetPhysicalDeviceXlibPresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif
PFN_vkGetPipelineCacheData glad_vkGetPipelineCacheData = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t * pDataSize, void * pData) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPipelineCacheData", (GLADapiproc) glad_vkGetPipelineCacheData, 4, device, pipelineCache, pDataSize, pData);
    ret = glad_vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    _post_call_vulkan_callback((void*) &ret, "vkGetPipelineCacheData", (GLADapiproc) glad_vkGetPipelineCacheData, 4, device, pipelineCache, pDataSize, pData);
    return ret;
}
PFN_vkGetPipelineCacheData glad_debug_vkGetPipelineCacheData = glad_debug_impl_vkGetPipelineCacheData;
PFN_vkGetPipelineExecutableInternalRepresentationsKHR glad_vkGetPipelineExecutableInternalRepresentationsKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR * pExecutableInfo, uint32_t * pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR * pInternalRepresentations) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPipelineExecutableInternalRepresentationsKHR", (GLADapiproc) glad_vkGetPipelineExecutableInternalRepresentationsKHR, 4, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    ret = glad_vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    _post_call_vulkan_callback((void*) &ret, "vkGetPipelineExecutableInternalRepresentationsKHR", (GLADapiproc) glad_vkGetPipelineExecutableInternalRepresentationsKHR, 4, device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    return ret;
}
PFN_vkGetPipelineExecutableInternalRepresentationsKHR glad_debug_vkGetPipelineExecutableInternalRepresentationsKHR = glad_debug_impl_vkGetPipelineExecutableInternalRepresentationsKHR;
PFN_vkGetPipelineExecutablePropertiesKHR glad_vkGetPipelineExecutablePropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR * pPipelineInfo, uint32_t * pExecutableCount, VkPipelineExecutablePropertiesKHR * pProperties) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPipelineExecutablePropertiesKHR", (GLADapiproc) glad_vkGetPipelineExecutablePropertiesKHR, 4, device, pPipelineInfo, pExecutableCount, pProperties);
    ret = glad_vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    _post_call_vulkan_callback((void*) &ret, "vkGetPipelineExecutablePropertiesKHR", (GLADapiproc) glad_vkGetPipelineExecutablePropertiesKHR, 4, device, pPipelineInfo, pExecutableCount, pProperties);
    return ret;
}
PFN_vkGetPipelineExecutablePropertiesKHR glad_debug_vkGetPipelineExecutablePropertiesKHR = glad_debug_impl_vkGetPipelineExecutablePropertiesKHR;
PFN_vkGetPipelineExecutableStatisticsKHR glad_vkGetPipelineExecutableStatisticsKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR * pExecutableInfo, uint32_t * pStatisticCount, VkPipelineExecutableStatisticKHR * pStatistics) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetPipelineExecutableStatisticsKHR", (GLADapiproc) glad_vkGetPipelineExecutableStatisticsKHR, 4, device, pExecutableInfo, pStatisticCount, pStatistics);
    ret = glad_vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    _post_call_vulkan_callback((void*) &ret, "vkGetPipelineExecutableStatisticsKHR", (GLADapiproc) glad_vkGetPipelineExecutableStatisticsKHR, 4, device, pExecutableInfo, pStatisticCount, pStatistics);
    return ret;
}
PFN_vkGetPipelineExecutableStatisticsKHR glad_debug_vkGetPipelineExecutableStatisticsKHR = glad_debug_impl_vkGetPipelineExecutableStatisticsKHR;
PFN_vkGetPrivateDataEXT glad_vkGetPrivateDataEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t * pData) {
    _pre_call_vulkan_callback("vkGetPrivateDataEXT", (GLADapiproc) glad_vkGetPrivateDataEXT, 5, device, objectType, objectHandle, privateDataSlot, pData);
    glad_vkGetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
    _post_call_vulkan_callback(NULL, "vkGetPrivateDataEXT", (GLADapiproc) glad_vkGetPrivateDataEXT, 5, device, objectType, objectHandle, privateDataSlot, pData);
    
}
PFN_vkGetPrivateDataEXT glad_debug_vkGetPrivateDataEXT = glad_debug_impl_vkGetPrivateDataEXT;
PFN_vkGetQueryPoolResults glad_vkGetQueryPoolResults = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void * pData, VkDeviceSize stride, VkQueryResultFlags flags) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetQueryPoolResults", (GLADapiproc) glad_vkGetQueryPoolResults, 8, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    ret = glad_vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    _post_call_vulkan_callback((void*) &ret, "vkGetQueryPoolResults", (GLADapiproc) glad_vkGetQueryPoolResults, 8, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    return ret;
}
PFN_vkGetQueryPoolResults glad_debug_vkGetQueryPoolResults = glad_debug_impl_vkGetQueryPoolResults;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
PFN_vkGetRandROutputDisplayEXT glad_vkGetRandROutputDisplayEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display * dpy, RROutput rrOutput, VkDisplayKHR * pDisplay) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetRandROutputDisplayEXT", (GLADapiproc) glad_vkGetRandROutputDisplayEXT, 4, physicalDevice, dpy, rrOutput, pDisplay);
    ret = glad_vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    _post_call_vulkan_callback((void*) &ret, "vkGetRandROutputDisplayEXT", (GLADapiproc) glad_vkGetRandROutputDisplayEXT, 4, physicalDevice, dpy, rrOutput, pDisplay);
    return ret;
}
PFN_vkGetRandROutputDisplayEXT glad_debug_vkGetRandROutputDisplayEXT = glad_debug_impl_vkGetRandROutputDisplayEXT;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR glad_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void * pData) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", (GLADapiproc) glad_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR, 6, device, pipeline, firstGroup, groupCount, dataSize, pData);
    ret = glad_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    _post_call_vulkan_callback((void*) &ret, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR", (GLADapiproc) glad_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR, 6, device, pipeline, firstGroup, groupCount, dataSize, pData);
    return ret;
}
PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR glad_debug_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = glad_debug_impl_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkGetRayTracingShaderGroupHandlesKHR glad_vkGetRayTracingShaderGroupHandlesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void * pData) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetRayTracingShaderGroupHandlesKHR", (GLADapiproc) glad_vkGetRayTracingShaderGroupHandlesKHR, 6, device, pipeline, firstGroup, groupCount, dataSize, pData);
    ret = glad_vkGetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    _post_call_vulkan_callback((void*) &ret, "vkGetRayTracingShaderGroupHandlesKHR", (GLADapiproc) glad_vkGetRayTracingShaderGroupHandlesKHR, 6, device, pipeline, firstGroup, groupCount, dataSize, pData);
    return ret;
}
PFN_vkGetRayTracingShaderGroupHandlesKHR glad_debug_vkGetRayTracingShaderGroupHandlesKHR = glad_debug_impl_vkGetRayTracingShaderGroupHandlesKHR;
#endif
PFN_vkGetRenderAreaGranularity glad_vkGetRenderAreaGranularity = NULL;
static void GLAD_API_PTR glad_debug_impl_vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D * pGranularity) {
    _pre_call_vulkan_callback("vkGetRenderAreaGranularity", (GLADapiproc) glad_vkGetRenderAreaGranularity, 3, device, renderPass, pGranularity);
    glad_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    _post_call_vulkan_callback(NULL, "vkGetRenderAreaGranularity", (GLADapiproc) glad_vkGetRenderAreaGranularity, 3, device, renderPass, pGranularity);
    
}
PFN_vkGetRenderAreaGranularity glad_debug_vkGetRenderAreaGranularity = glad_debug_impl_vkGetRenderAreaGranularity;
PFN_vkGetSemaphoreCounterValue glad_vkGetSemaphoreCounterValue = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t * pValue) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSemaphoreCounterValue", (GLADapiproc) glad_vkGetSemaphoreCounterValue, 3, device, semaphore, pValue);
    ret = glad_vkGetSemaphoreCounterValue(device, semaphore, pValue);
    _post_call_vulkan_callback((void*) &ret, "vkGetSemaphoreCounterValue", (GLADapiproc) glad_vkGetSemaphoreCounterValue, 3, device, semaphore, pValue);
    return ret;
}
PFN_vkGetSemaphoreCounterValue glad_debug_vkGetSemaphoreCounterValue = glad_debug_impl_vkGetSemaphoreCounterValue;
PFN_vkGetSemaphoreCounterValueKHR glad_vkGetSemaphoreCounterValueKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t * pValue) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSemaphoreCounterValueKHR", (GLADapiproc) glad_vkGetSemaphoreCounterValueKHR, 3, device, semaphore, pValue);
    ret = glad_vkGetSemaphoreCounterValueKHR(device, semaphore, pValue);
    _post_call_vulkan_callback((void*) &ret, "vkGetSemaphoreCounterValueKHR", (GLADapiproc) glad_vkGetSemaphoreCounterValueKHR, 3, device, semaphore, pValue);
    return ret;
}
PFN_vkGetSemaphoreCounterValueKHR glad_debug_vkGetSemaphoreCounterValueKHR = glad_debug_impl_vkGetSemaphoreCounterValueKHR;
PFN_vkGetSemaphoreFdKHR glad_vkGetSemaphoreFdKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR * pGetFdInfo, int * pFd) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSemaphoreFdKHR", (GLADapiproc) glad_vkGetSemaphoreFdKHR, 3, device, pGetFdInfo, pFd);
    ret = glad_vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    _post_call_vulkan_callback((void*) &ret, "vkGetSemaphoreFdKHR", (GLADapiproc) glad_vkGetSemaphoreFdKHR, 3, device, pGetFdInfo, pFd);
    return ret;
}
PFN_vkGetSemaphoreFdKHR glad_debug_vkGetSemaphoreFdKHR = glad_debug_impl_vkGetSemaphoreFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkGetSemaphoreWin32HandleKHR glad_vkGetSemaphoreWin32HandleKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSemaphoreWin32HandleKHR", (GLADapiproc) glad_vkGetSemaphoreWin32HandleKHR, 3, device, pGetWin32HandleInfo, pHandle);
    ret = glad_vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    _post_call_vulkan_callback((void*) &ret, "vkGetSemaphoreWin32HandleKHR", (GLADapiproc) glad_vkGetSemaphoreWin32HandleKHR, 3, device, pGetWin32HandleInfo, pHandle);
    return ret;
}
PFN_vkGetSemaphoreWin32HandleKHR glad_debug_vkGetSemaphoreWin32HandleKHR = glad_debug_impl_vkGetSemaphoreWin32HandleKHR;
#endif
PFN_vkGetSwapchainCounterEXT glad_vkGetSwapchainCounterEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t * pCounterValue) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSwapchainCounterEXT", (GLADapiproc) glad_vkGetSwapchainCounterEXT, 4, device, swapchain, counter, pCounterValue);
    ret = glad_vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    _post_call_vulkan_callback((void*) &ret, "vkGetSwapchainCounterEXT", (GLADapiproc) glad_vkGetSwapchainCounterEXT, 4, device, swapchain, counter, pCounterValue);
    return ret;
}
PFN_vkGetSwapchainCounterEXT glad_debug_vkGetSwapchainCounterEXT = glad_debug_impl_vkGetSwapchainCounterEXT;
PFN_vkGetSwapchainImagesKHR glad_vkGetSwapchainImagesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t * pSwapchainImageCount, VkImage * pSwapchainImages) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSwapchainImagesKHR", (GLADapiproc) glad_vkGetSwapchainImagesKHR, 4, device, swapchain, pSwapchainImageCount, pSwapchainImages);
    ret = glad_vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    _post_call_vulkan_callback((void*) &ret, "vkGetSwapchainImagesKHR", (GLADapiproc) glad_vkGetSwapchainImagesKHR, 4, device, swapchain, pSwapchainImageCount, pSwapchainImages);
    return ret;
}
PFN_vkGetSwapchainImagesKHR glad_debug_vkGetSwapchainImagesKHR = glad_debug_impl_vkGetSwapchainImagesKHR;
PFN_vkGetSwapchainStatusKHR glad_vkGetSwapchainStatusKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetSwapchainStatusKHR", (GLADapiproc) glad_vkGetSwapchainStatusKHR, 2, device, swapchain);
    ret = glad_vkGetSwapchainStatusKHR(device, swapchain);
    _post_call_vulkan_callback((void*) &ret, "vkGetSwapchainStatusKHR", (GLADapiproc) glad_vkGetSwapchainStatusKHR, 2, device, swapchain);
    return ret;
}
PFN_vkGetSwapchainStatusKHR glad_debug_vkGetSwapchainStatusKHR = glad_debug_impl_vkGetSwapchainStatusKHR;
PFN_vkGetValidationCacheDataEXT glad_vkGetValidationCacheDataEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t * pDataSize, void * pData) {
    VkResult ret;
    _pre_call_vulkan_callback("vkGetValidationCacheDataEXT", (GLADapiproc) glad_vkGetValidationCacheDataEXT, 4, device, validationCache, pDataSize, pData);
    ret = glad_vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    _post_call_vulkan_callback((void*) &ret, "vkGetValidationCacheDataEXT", (GLADapiproc) glad_vkGetValidationCacheDataEXT, 4, device, validationCache, pDataSize, pData);
    return ret;
}
PFN_vkGetValidationCacheDataEXT glad_debug_vkGetValidationCacheDataEXT = glad_debug_impl_vkGetValidationCacheDataEXT;
PFN_vkImportFenceFdKHR glad_vkImportFenceFdKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR * pImportFenceFdInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkImportFenceFdKHR", (GLADapiproc) glad_vkImportFenceFdKHR, 2, device, pImportFenceFdInfo);
    ret = glad_vkImportFenceFdKHR(device, pImportFenceFdInfo);
    _post_call_vulkan_callback((void*) &ret, "vkImportFenceFdKHR", (GLADapiproc) glad_vkImportFenceFdKHR, 2, device, pImportFenceFdInfo);
    return ret;
}
PFN_vkImportFenceFdKHR glad_debug_vkImportFenceFdKHR = glad_debug_impl_vkImportFenceFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkImportFenceWin32HandleKHR glad_vkImportFenceWin32HandleKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR * pImportFenceWin32HandleInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkImportFenceWin32HandleKHR", (GLADapiproc) glad_vkImportFenceWin32HandleKHR, 2, device, pImportFenceWin32HandleInfo);
    ret = glad_vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    _post_call_vulkan_callback((void*) &ret, "vkImportFenceWin32HandleKHR", (GLADapiproc) glad_vkImportFenceWin32HandleKHR, 2, device, pImportFenceWin32HandleInfo);
    return ret;
}
PFN_vkImportFenceWin32HandleKHR glad_debug_vkImportFenceWin32HandleKHR = glad_debug_impl_vkImportFenceWin32HandleKHR;
#endif
PFN_vkImportSemaphoreFdKHR glad_vkImportSemaphoreFdKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR * pImportSemaphoreFdInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkImportSemaphoreFdKHR", (GLADapiproc) glad_vkImportSemaphoreFdKHR, 2, device, pImportSemaphoreFdInfo);
    ret = glad_vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    _post_call_vulkan_callback((void*) &ret, "vkImportSemaphoreFdKHR", (GLADapiproc) glad_vkImportSemaphoreFdKHR, 2, device, pImportSemaphoreFdInfo);
    return ret;
}
PFN_vkImportSemaphoreFdKHR glad_debug_vkImportSemaphoreFdKHR = glad_debug_impl_vkImportSemaphoreFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkImportSemaphoreWin32HandleKHR glad_vkImportSemaphoreWin32HandleKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR * pImportSemaphoreWin32HandleInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkImportSemaphoreWin32HandleKHR", (GLADapiproc) glad_vkImportSemaphoreWin32HandleKHR, 2, device, pImportSemaphoreWin32HandleInfo);
    ret = glad_vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    _post_call_vulkan_callback((void*) &ret, "vkImportSemaphoreWin32HandleKHR", (GLADapiproc) glad_vkImportSemaphoreWin32HandleKHR, 2, device, pImportSemaphoreWin32HandleInfo);
    return ret;
}
PFN_vkImportSemaphoreWin32HandleKHR glad_debug_vkImportSemaphoreWin32HandleKHR = glad_debug_impl_vkImportSemaphoreWin32HandleKHR;
#endif
PFN_vkInvalidateMappedMemoryRanges glad_vkInvalidateMappedMemoryRanges = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange * pMemoryRanges) {
    VkResult ret;
    _pre_call_vulkan_callback("vkInvalidateMappedMemoryRanges", (GLADapiproc) glad_vkInvalidateMappedMemoryRanges, 3, device, memoryRangeCount, pMemoryRanges);
    ret = glad_vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    _post_call_vulkan_callback((void*) &ret, "vkInvalidateMappedMemoryRanges", (GLADapiproc) glad_vkInvalidateMappedMemoryRanges, 3, device, memoryRangeCount, pMemoryRanges);
    return ret;
}
PFN_vkInvalidateMappedMemoryRanges glad_debug_vkInvalidateMappedMemoryRanges = glad_debug_impl_vkInvalidateMappedMemoryRanges;
PFN_vkMapMemory glad_vkMapMemory = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void ** ppData) {
    VkResult ret;
    _pre_call_vulkan_callback("vkMapMemory", (GLADapiproc) glad_vkMapMemory, 6, device, memory, offset, size, flags, ppData);
    ret = glad_vkMapMemory(device, memory, offset, size, flags, ppData);
    _post_call_vulkan_callback((void*) &ret, "vkMapMemory", (GLADapiproc) glad_vkMapMemory, 6, device, memory, offset, size, flags, ppData);
    return ret;
}
PFN_vkMapMemory glad_debug_vkMapMemory = glad_debug_impl_vkMapMemory;
PFN_vkMergePipelineCaches glad_vkMergePipelineCaches = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache * pSrcCaches) {
    VkResult ret;
    _pre_call_vulkan_callback("vkMergePipelineCaches", (GLADapiproc) glad_vkMergePipelineCaches, 4, device, dstCache, srcCacheCount, pSrcCaches);
    ret = glad_vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    _post_call_vulkan_callback((void*) &ret, "vkMergePipelineCaches", (GLADapiproc) glad_vkMergePipelineCaches, 4, device, dstCache, srcCacheCount, pSrcCaches);
    return ret;
}
PFN_vkMergePipelineCaches glad_debug_vkMergePipelineCaches = glad_debug_impl_vkMergePipelineCaches;
PFN_vkMergeValidationCachesEXT glad_vkMergeValidationCachesEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT * pSrcCaches) {
    VkResult ret;
    _pre_call_vulkan_callback("vkMergeValidationCachesEXT", (GLADapiproc) glad_vkMergeValidationCachesEXT, 4, device, dstCache, srcCacheCount, pSrcCaches);
    ret = glad_vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    _post_call_vulkan_callback((void*) &ret, "vkMergeValidationCachesEXT", (GLADapiproc) glad_vkMergeValidationCachesEXT, 4, device, dstCache, srcCacheCount, pSrcCaches);
    return ret;
}
PFN_vkMergeValidationCachesEXT glad_debug_vkMergeValidationCachesEXT = glad_debug_impl_vkMergeValidationCachesEXT;
PFN_vkQueueBeginDebugUtilsLabelEXT glad_vkQueueBeginDebugUtilsLabelEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT * pLabelInfo) {
    _pre_call_vulkan_callback("vkQueueBeginDebugUtilsLabelEXT", (GLADapiproc) glad_vkQueueBeginDebugUtilsLabelEXT, 2, queue, pLabelInfo);
    glad_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    _post_call_vulkan_callback(NULL, "vkQueueBeginDebugUtilsLabelEXT", (GLADapiproc) glad_vkQueueBeginDebugUtilsLabelEXT, 2, queue, pLabelInfo);
    
}
PFN_vkQueueBeginDebugUtilsLabelEXT glad_debug_vkQueueBeginDebugUtilsLabelEXT = glad_debug_impl_vkQueueBeginDebugUtilsLabelEXT;
PFN_vkQueueBindSparse glad_vkQueueBindSparse = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo * pBindInfo, VkFence fence) {
    VkResult ret;
    _pre_call_vulkan_callback("vkQueueBindSparse", (GLADapiproc) glad_vkQueueBindSparse, 4, queue, bindInfoCount, pBindInfo, fence);
    ret = glad_vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    _post_call_vulkan_callback((void*) &ret, "vkQueueBindSparse", (GLADapiproc) glad_vkQueueBindSparse, 4, queue, bindInfoCount, pBindInfo, fence);
    return ret;
}
PFN_vkQueueBindSparse glad_debug_vkQueueBindSparse = glad_debug_impl_vkQueueBindSparse;
PFN_vkQueueEndDebugUtilsLabelEXT glad_vkQueueEndDebugUtilsLabelEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkQueueEndDebugUtilsLabelEXT(VkQueue queue) {
    _pre_call_vulkan_callback("vkQueueEndDebugUtilsLabelEXT", (GLADapiproc) glad_vkQueueEndDebugUtilsLabelEXT, 1, queue);
    glad_vkQueueEndDebugUtilsLabelEXT(queue);
    _post_call_vulkan_callback(NULL, "vkQueueEndDebugUtilsLabelEXT", (GLADapiproc) glad_vkQueueEndDebugUtilsLabelEXT, 1, queue);
    
}
PFN_vkQueueEndDebugUtilsLabelEXT glad_debug_vkQueueEndDebugUtilsLabelEXT = glad_debug_impl_vkQueueEndDebugUtilsLabelEXT;
PFN_vkQueueInsertDebugUtilsLabelEXT glad_vkQueueInsertDebugUtilsLabelEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT * pLabelInfo) {
    _pre_call_vulkan_callback("vkQueueInsertDebugUtilsLabelEXT", (GLADapiproc) glad_vkQueueInsertDebugUtilsLabelEXT, 2, queue, pLabelInfo);
    glad_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    _post_call_vulkan_callback(NULL, "vkQueueInsertDebugUtilsLabelEXT", (GLADapiproc) glad_vkQueueInsertDebugUtilsLabelEXT, 2, queue, pLabelInfo);
    
}
PFN_vkQueueInsertDebugUtilsLabelEXT glad_debug_vkQueueInsertDebugUtilsLabelEXT = glad_debug_impl_vkQueueInsertDebugUtilsLabelEXT;
PFN_vkQueuePresentKHR glad_vkQueuePresentKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR * pPresentInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkQueuePresentKHR", (GLADapiproc) glad_vkQueuePresentKHR, 2, queue, pPresentInfo);
    ret = glad_vkQueuePresentKHR(queue, pPresentInfo);
    _post_call_vulkan_callback((void*) &ret, "vkQueuePresentKHR", (GLADapiproc) glad_vkQueuePresentKHR, 2, queue, pPresentInfo);
    return ret;
}
PFN_vkQueuePresentKHR glad_debug_vkQueuePresentKHR = glad_debug_impl_vkQueuePresentKHR;
PFN_vkQueueSubmit glad_vkQueueSubmit = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo * pSubmits, VkFence fence) {
    VkResult ret;
    _pre_call_vulkan_callback("vkQueueSubmit", (GLADapiproc) glad_vkQueueSubmit, 4, queue, submitCount, pSubmits, fence);
    ret = glad_vkQueueSubmit(queue, submitCount, pSubmits, fence);
    _post_call_vulkan_callback((void*) &ret, "vkQueueSubmit", (GLADapiproc) glad_vkQueueSubmit, 4, queue, submitCount, pSubmits, fence);
    return ret;
}
PFN_vkQueueSubmit glad_debug_vkQueueSubmit = glad_debug_impl_vkQueueSubmit;
PFN_vkQueueWaitIdle glad_vkQueueWaitIdle = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkQueueWaitIdle(VkQueue queue) {
    VkResult ret;
    _pre_call_vulkan_callback("vkQueueWaitIdle", (GLADapiproc) glad_vkQueueWaitIdle, 1, queue);
    ret = glad_vkQueueWaitIdle(queue);
    _post_call_vulkan_callback((void*) &ret, "vkQueueWaitIdle", (GLADapiproc) glad_vkQueueWaitIdle, 1, queue);
    return ret;
}
PFN_vkQueueWaitIdle glad_debug_vkQueueWaitIdle = glad_debug_impl_vkQueueWaitIdle;
PFN_vkRegisterDeviceEventEXT glad_vkRegisterDeviceEventEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT * pDeviceEventInfo, const VkAllocationCallbacks * pAllocator, VkFence * pFence) {
    VkResult ret;
    _pre_call_vulkan_callback("vkRegisterDeviceEventEXT", (GLADapiproc) glad_vkRegisterDeviceEventEXT, 4, device, pDeviceEventInfo, pAllocator, pFence);
    ret = glad_vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    _post_call_vulkan_callback((void*) &ret, "vkRegisterDeviceEventEXT", (GLADapiproc) glad_vkRegisterDeviceEventEXT, 4, device, pDeviceEventInfo, pAllocator, pFence);
    return ret;
}
PFN_vkRegisterDeviceEventEXT glad_debug_vkRegisterDeviceEventEXT = glad_debug_impl_vkRegisterDeviceEventEXT;
PFN_vkRegisterDisplayEventEXT glad_vkRegisterDisplayEventEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT * pDisplayEventInfo, const VkAllocationCallbacks * pAllocator, VkFence * pFence) {
    VkResult ret;
    _pre_call_vulkan_callback("vkRegisterDisplayEventEXT", (GLADapiproc) glad_vkRegisterDisplayEventEXT, 5, device, display, pDisplayEventInfo, pAllocator, pFence);
    ret = glad_vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    _post_call_vulkan_callback((void*) &ret, "vkRegisterDisplayEventEXT", (GLADapiproc) glad_vkRegisterDisplayEventEXT, 5, device, display, pDisplayEventInfo, pAllocator, pFence);
    return ret;
}
PFN_vkRegisterDisplayEventEXT glad_debug_vkRegisterDisplayEventEXT = glad_debug_impl_vkRegisterDisplayEventEXT;
PFN_vkReleaseDisplayEXT glad_vkReleaseDisplayEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    VkResult ret;
    _pre_call_vulkan_callback("vkReleaseDisplayEXT", (GLADapiproc) glad_vkReleaseDisplayEXT, 2, physicalDevice, display);
    ret = glad_vkReleaseDisplayEXT(physicalDevice, display);
    _post_call_vulkan_callback((void*) &ret, "vkReleaseDisplayEXT", (GLADapiproc) glad_vkReleaseDisplayEXT, 2, physicalDevice, display);
    return ret;
}
PFN_vkReleaseDisplayEXT glad_debug_vkReleaseDisplayEXT = glad_debug_impl_vkReleaseDisplayEXT;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
PFN_vkReleaseFullScreenExclusiveModeEXT glad_vkReleaseFullScreenExclusiveModeEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
    VkResult ret;
    _pre_call_vulkan_callback("vkReleaseFullScreenExclusiveModeEXT", (GLADapiproc) glad_vkReleaseFullScreenExclusiveModeEXT, 2, device, swapchain);
    ret = glad_vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
    _post_call_vulkan_callback((void*) &ret, "vkReleaseFullScreenExclusiveModeEXT", (GLADapiproc) glad_vkReleaseFullScreenExclusiveModeEXT, 2, device, swapchain);
    return ret;
}
PFN_vkReleaseFullScreenExclusiveModeEXT glad_debug_vkReleaseFullScreenExclusiveModeEXT = glad_debug_impl_vkReleaseFullScreenExclusiveModeEXT;
#endif
PFN_vkReleaseProfilingLockKHR glad_vkReleaseProfilingLockKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkReleaseProfilingLockKHR(VkDevice device) {
    _pre_call_vulkan_callback("vkReleaseProfilingLockKHR", (GLADapiproc) glad_vkReleaseProfilingLockKHR, 1, device);
    glad_vkReleaseProfilingLockKHR(device);
    _post_call_vulkan_callback(NULL, "vkReleaseProfilingLockKHR", (GLADapiproc) glad_vkReleaseProfilingLockKHR, 1, device);
    
}
PFN_vkReleaseProfilingLockKHR glad_debug_vkReleaseProfilingLockKHR = glad_debug_impl_vkReleaseProfilingLockKHR;
PFN_vkResetCommandBuffer glad_vkResetCommandBuffer = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    VkResult ret;
    _pre_call_vulkan_callback("vkResetCommandBuffer", (GLADapiproc) glad_vkResetCommandBuffer, 2, commandBuffer, flags);
    ret = glad_vkResetCommandBuffer(commandBuffer, flags);
    _post_call_vulkan_callback((void*) &ret, "vkResetCommandBuffer", (GLADapiproc) glad_vkResetCommandBuffer, 2, commandBuffer, flags);
    return ret;
}
PFN_vkResetCommandBuffer glad_debug_vkResetCommandBuffer = glad_debug_impl_vkResetCommandBuffer;
PFN_vkResetCommandPool glad_vkResetCommandPool = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    VkResult ret;
    _pre_call_vulkan_callback("vkResetCommandPool", (GLADapiproc) glad_vkResetCommandPool, 3, device, commandPool, flags);
    ret = glad_vkResetCommandPool(device, commandPool, flags);
    _post_call_vulkan_callback((void*) &ret, "vkResetCommandPool", (GLADapiproc) glad_vkResetCommandPool, 3, device, commandPool, flags);
    return ret;
}
PFN_vkResetCommandPool glad_debug_vkResetCommandPool = glad_debug_impl_vkResetCommandPool;
PFN_vkResetDescriptorPool glad_vkResetDescriptorPool = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) {
    VkResult ret;
    _pre_call_vulkan_callback("vkResetDescriptorPool", (GLADapiproc) glad_vkResetDescriptorPool, 3, device, descriptorPool, flags);
    ret = glad_vkResetDescriptorPool(device, descriptorPool, flags);
    _post_call_vulkan_callback((void*) &ret, "vkResetDescriptorPool", (GLADapiproc) glad_vkResetDescriptorPool, 3, device, descriptorPool, flags);
    return ret;
}
PFN_vkResetDescriptorPool glad_debug_vkResetDescriptorPool = glad_debug_impl_vkResetDescriptorPool;
PFN_vkResetEvent glad_vkResetEvent = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkResetEvent(VkDevice device, VkEvent event) {
    VkResult ret;
    _pre_call_vulkan_callback("vkResetEvent", (GLADapiproc) glad_vkResetEvent, 2, device, event);
    ret = glad_vkResetEvent(device, event);
    _post_call_vulkan_callback((void*) &ret, "vkResetEvent", (GLADapiproc) glad_vkResetEvent, 2, device, event);
    return ret;
}
PFN_vkResetEvent glad_debug_vkResetEvent = glad_debug_impl_vkResetEvent;
PFN_vkResetFences glad_vkResetFences = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence * pFences) {
    VkResult ret;
    _pre_call_vulkan_callback("vkResetFences", (GLADapiproc) glad_vkResetFences, 3, device, fenceCount, pFences);
    ret = glad_vkResetFences(device, fenceCount, pFences);
    _post_call_vulkan_callback((void*) &ret, "vkResetFences", (GLADapiproc) glad_vkResetFences, 3, device, fenceCount, pFences);
    return ret;
}
PFN_vkResetFences glad_debug_vkResetFences = glad_debug_impl_vkResetFences;
PFN_vkResetQueryPool glad_vkResetQueryPool = NULL;
static void GLAD_API_PTR glad_debug_impl_vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    _pre_call_vulkan_callback("vkResetQueryPool", (GLADapiproc) glad_vkResetQueryPool, 4, device, queryPool, firstQuery, queryCount);
    glad_vkResetQueryPool(device, queryPool, firstQuery, queryCount);
    _post_call_vulkan_callback(NULL, "vkResetQueryPool", (GLADapiproc) glad_vkResetQueryPool, 4, device, queryPool, firstQuery, queryCount);
    
}
PFN_vkResetQueryPool glad_debug_vkResetQueryPool = glad_debug_impl_vkResetQueryPool;
PFN_vkResetQueryPoolEXT glad_vkResetQueryPoolEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    _pre_call_vulkan_callback("vkResetQueryPoolEXT", (GLADapiproc) glad_vkResetQueryPoolEXT, 4, device, queryPool, firstQuery, queryCount);
    glad_vkResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
    _post_call_vulkan_callback(NULL, "vkResetQueryPoolEXT", (GLADapiproc) glad_vkResetQueryPoolEXT, 4, device, queryPool, firstQuery, queryCount);
    
}
PFN_vkResetQueryPoolEXT glad_debug_vkResetQueryPoolEXT = glad_debug_impl_vkResetQueryPoolEXT;
PFN_vkSetDebugUtilsObjectNameEXT glad_vkSetDebugUtilsObjectNameEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT * pNameInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkSetDebugUtilsObjectNameEXT", (GLADapiproc) glad_vkSetDebugUtilsObjectNameEXT, 2, device, pNameInfo);
    ret = glad_vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
    _post_call_vulkan_callback((void*) &ret, "vkSetDebugUtilsObjectNameEXT", (GLADapiproc) glad_vkSetDebugUtilsObjectNameEXT, 2, device, pNameInfo);
    return ret;
}
PFN_vkSetDebugUtilsObjectNameEXT glad_debug_vkSetDebugUtilsObjectNameEXT = glad_debug_impl_vkSetDebugUtilsObjectNameEXT;
PFN_vkSetDebugUtilsObjectTagEXT glad_vkSetDebugUtilsObjectTagEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT * pTagInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkSetDebugUtilsObjectTagEXT", (GLADapiproc) glad_vkSetDebugUtilsObjectTagEXT, 2, device, pTagInfo);
    ret = glad_vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
    _post_call_vulkan_callback((void*) &ret, "vkSetDebugUtilsObjectTagEXT", (GLADapiproc) glad_vkSetDebugUtilsObjectTagEXT, 2, device, pTagInfo);
    return ret;
}
PFN_vkSetDebugUtilsObjectTagEXT glad_debug_vkSetDebugUtilsObjectTagEXT = glad_debug_impl_vkSetDebugUtilsObjectTagEXT;
PFN_vkSetEvent glad_vkSetEvent = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkSetEvent(VkDevice device, VkEvent event) {
    VkResult ret;
    _pre_call_vulkan_callback("vkSetEvent", (GLADapiproc) glad_vkSetEvent, 2, device, event);
    ret = glad_vkSetEvent(device, event);
    _post_call_vulkan_callback((void*) &ret, "vkSetEvent", (GLADapiproc) glad_vkSetEvent, 2, device, event);
    return ret;
}
PFN_vkSetEvent glad_debug_vkSetEvent = glad_debug_impl_vkSetEvent;
PFN_vkSetHdrMetadataEXT glad_vkSetHdrMetadataEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR * pSwapchains, const VkHdrMetadataEXT * pMetadata) {
    _pre_call_vulkan_callback("vkSetHdrMetadataEXT", (GLADapiproc) glad_vkSetHdrMetadataEXT, 4, device, swapchainCount, pSwapchains, pMetadata);
    glad_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    _post_call_vulkan_callback(NULL, "vkSetHdrMetadataEXT", (GLADapiproc) glad_vkSetHdrMetadataEXT, 4, device, swapchainCount, pSwapchains, pMetadata);
    
}
PFN_vkSetHdrMetadataEXT glad_debug_vkSetHdrMetadataEXT = glad_debug_impl_vkSetHdrMetadataEXT;
PFN_vkSetPrivateDataEXT glad_vkSetPrivateDataEXT = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data) {
    VkResult ret;
    _pre_call_vulkan_callback("vkSetPrivateDataEXT", (GLADapiproc) glad_vkSetPrivateDataEXT, 5, device, objectType, objectHandle, privateDataSlot, data);
    ret = glad_vkSetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
    _post_call_vulkan_callback((void*) &ret, "vkSetPrivateDataEXT", (GLADapiproc) glad_vkSetPrivateDataEXT, 5, device, objectType, objectHandle, privateDataSlot, data);
    return ret;
}
PFN_vkSetPrivateDataEXT glad_debug_vkSetPrivateDataEXT = glad_debug_impl_vkSetPrivateDataEXT;
PFN_vkSignalSemaphore glad_vkSignalSemaphore = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo * pSignalInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkSignalSemaphore", (GLADapiproc) glad_vkSignalSemaphore, 2, device, pSignalInfo);
    ret = glad_vkSignalSemaphore(device, pSignalInfo);
    _post_call_vulkan_callback((void*) &ret, "vkSignalSemaphore", (GLADapiproc) glad_vkSignalSemaphore, 2, device, pSignalInfo);
    return ret;
}
PFN_vkSignalSemaphore glad_debug_vkSignalSemaphore = glad_debug_impl_vkSignalSemaphore;
PFN_vkSignalSemaphoreKHR glad_vkSignalSemaphoreKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo * pSignalInfo) {
    VkResult ret;
    _pre_call_vulkan_callback("vkSignalSemaphoreKHR", (GLADapiproc) glad_vkSignalSemaphoreKHR, 2, device, pSignalInfo);
    ret = glad_vkSignalSemaphoreKHR(device, pSignalInfo);
    _post_call_vulkan_callback((void*) &ret, "vkSignalSemaphoreKHR", (GLADapiproc) glad_vkSignalSemaphoreKHR, 2, device, pSignalInfo);
    return ret;
}
PFN_vkSignalSemaphoreKHR glad_debug_vkSignalSemaphoreKHR = glad_debug_impl_vkSignalSemaphoreKHR;
PFN_vkSubmitDebugUtilsMessageEXT glad_vkSubmitDebugUtilsMessageEXT = NULL;
static void GLAD_API_PTR glad_debug_impl_vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData) {
    _pre_call_vulkan_callback("vkSubmitDebugUtilsMessageEXT", (GLADapiproc) glad_vkSubmitDebugUtilsMessageEXT, 4, instance, messageSeverity, messageTypes, pCallbackData);
    glad_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    _post_call_vulkan_callback(NULL, "vkSubmitDebugUtilsMessageEXT", (GLADapiproc) glad_vkSubmitDebugUtilsMessageEXT, 4, instance, messageSeverity, messageTypes, pCallbackData);
    
}
PFN_vkSubmitDebugUtilsMessageEXT glad_debug_vkSubmitDebugUtilsMessageEXT = glad_debug_impl_vkSubmitDebugUtilsMessageEXT;
PFN_vkTrimCommandPool glad_vkTrimCommandPool = NULL;
static void GLAD_API_PTR glad_debug_impl_vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
    _pre_call_vulkan_callback("vkTrimCommandPool", (GLADapiproc) glad_vkTrimCommandPool, 3, device, commandPool, flags);
    glad_vkTrimCommandPool(device, commandPool, flags);
    _post_call_vulkan_callback(NULL, "vkTrimCommandPool", (GLADapiproc) glad_vkTrimCommandPool, 3, device, commandPool, flags);
    
}
PFN_vkTrimCommandPool glad_debug_vkTrimCommandPool = glad_debug_impl_vkTrimCommandPool;
PFN_vkTrimCommandPoolKHR glad_vkTrimCommandPoolKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
    _pre_call_vulkan_callback("vkTrimCommandPoolKHR", (GLADapiproc) glad_vkTrimCommandPoolKHR, 3, device, commandPool, flags);
    glad_vkTrimCommandPoolKHR(device, commandPool, flags);
    _post_call_vulkan_callback(NULL, "vkTrimCommandPoolKHR", (GLADapiproc) glad_vkTrimCommandPoolKHR, 3, device, commandPool, flags);
    
}
PFN_vkTrimCommandPoolKHR glad_debug_vkTrimCommandPoolKHR = glad_debug_impl_vkTrimCommandPoolKHR;
PFN_vkUnmapMemory glad_vkUnmapMemory = NULL;
static void GLAD_API_PTR glad_debug_impl_vkUnmapMemory(VkDevice device, VkDeviceMemory memory) {
    _pre_call_vulkan_callback("vkUnmapMemory", (GLADapiproc) glad_vkUnmapMemory, 2, device, memory);
    glad_vkUnmapMemory(device, memory);
    _post_call_vulkan_callback(NULL, "vkUnmapMemory", (GLADapiproc) glad_vkUnmapMemory, 2, device, memory);
    
}
PFN_vkUnmapMemory glad_debug_vkUnmapMemory = glad_debug_impl_vkUnmapMemory;
PFN_vkUpdateDescriptorSetWithTemplate glad_vkUpdateDescriptorSetWithTemplate = NULL;
static void GLAD_API_PTR glad_debug_impl_vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void * pData) {
    _pre_call_vulkan_callback("vkUpdateDescriptorSetWithTemplate", (GLADapiproc) glad_vkUpdateDescriptorSetWithTemplate, 4, device, descriptorSet, descriptorUpdateTemplate, pData);
    glad_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    _post_call_vulkan_callback(NULL, "vkUpdateDescriptorSetWithTemplate", (GLADapiproc) glad_vkUpdateDescriptorSetWithTemplate, 4, device, descriptorSet, descriptorUpdateTemplate, pData);
    
}
PFN_vkUpdateDescriptorSetWithTemplate glad_debug_vkUpdateDescriptorSetWithTemplate = glad_debug_impl_vkUpdateDescriptorSetWithTemplate;
PFN_vkUpdateDescriptorSetWithTemplateKHR glad_vkUpdateDescriptorSetWithTemplateKHR = NULL;
static void GLAD_API_PTR glad_debug_impl_vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void * pData) {
    _pre_call_vulkan_callback("vkUpdateDescriptorSetWithTemplateKHR", (GLADapiproc) glad_vkUpdateDescriptorSetWithTemplateKHR, 4, device, descriptorSet, descriptorUpdateTemplate, pData);
    glad_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    _post_call_vulkan_callback(NULL, "vkUpdateDescriptorSetWithTemplateKHR", (GLADapiproc) glad_vkUpdateDescriptorSetWithTemplateKHR, 4, device, descriptorSet, descriptorUpdateTemplate, pData);
    
}
PFN_vkUpdateDescriptorSetWithTemplateKHR glad_debug_vkUpdateDescriptorSetWithTemplateKHR = glad_debug_impl_vkUpdateDescriptorSetWithTemplateKHR;
PFN_vkUpdateDescriptorSets glad_vkUpdateDescriptorSets = NULL;
static void GLAD_API_PTR glad_debug_impl_vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet * pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet * pDescriptorCopies) {
    _pre_call_vulkan_callback("vkUpdateDescriptorSets", (GLADapiproc) glad_vkUpdateDescriptorSets, 5, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    glad_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    _post_call_vulkan_callback(NULL, "vkUpdateDescriptorSets", (GLADapiproc) glad_vkUpdateDescriptorSets, 5, device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    
}
PFN_vkUpdateDescriptorSets glad_debug_vkUpdateDescriptorSets = glad_debug_impl_vkUpdateDescriptorSets;
PFN_vkWaitForFences glad_vkWaitForFences = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence * pFences, VkBool32 waitAll, uint64_t timeout) {
    VkResult ret;
    _pre_call_vulkan_callback("vkWaitForFences", (GLADapiproc) glad_vkWaitForFences, 5, device, fenceCount, pFences, waitAll, timeout);
    ret = glad_vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    _post_call_vulkan_callback((void*) &ret, "vkWaitForFences", (GLADapiproc) glad_vkWaitForFences, 5, device, fenceCount, pFences, waitAll, timeout);
    return ret;
}
PFN_vkWaitForFences glad_debug_vkWaitForFences = glad_debug_impl_vkWaitForFences;
PFN_vkWaitSemaphores glad_vkWaitSemaphores = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo * pWaitInfo, uint64_t timeout) {
    VkResult ret;
    _pre_call_vulkan_callback("vkWaitSemaphores", (GLADapiproc) glad_vkWaitSemaphores, 3, device, pWaitInfo, timeout);
    ret = glad_vkWaitSemaphores(device, pWaitInfo, timeout);
    _post_call_vulkan_callback((void*) &ret, "vkWaitSemaphores", (GLADapiproc) glad_vkWaitSemaphores, 3, device, pWaitInfo, timeout);
    return ret;
}
PFN_vkWaitSemaphores glad_debug_vkWaitSemaphores = glad_debug_impl_vkWaitSemaphores;
PFN_vkWaitSemaphoresKHR glad_vkWaitSemaphoresKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo * pWaitInfo, uint64_t timeout) {
    VkResult ret;
    _pre_call_vulkan_callback("vkWaitSemaphoresKHR", (GLADapiproc) glad_vkWaitSemaphoresKHR, 3, device, pWaitInfo, timeout);
    ret = glad_vkWaitSemaphoresKHR(device, pWaitInfo, timeout);
    _post_call_vulkan_callback((void*) &ret, "vkWaitSemaphoresKHR", (GLADapiproc) glad_vkWaitSemaphoresKHR, 3, device, pWaitInfo, timeout);
    return ret;
}
PFN_vkWaitSemaphoresKHR glad_debug_vkWaitSemaphoresKHR = glad_debug_impl_vkWaitSemaphoresKHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
PFN_vkWriteAccelerationStructuresPropertiesKHR glad_vkWriteAccelerationStructuresPropertiesKHR = NULL;
static VkResult GLAD_API_PTR glad_debug_impl_vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR * pAccelerationStructures, VkQueryType queryType, size_t dataSize, void * pData, size_t stride) {
    VkResult ret;
    _pre_call_vulkan_callback("vkWriteAccelerationStructuresPropertiesKHR", (GLADapiproc) glad_vkWriteAccelerationStructuresPropertiesKHR, 7, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    ret = glad_vkWriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    _post_call_vulkan_callback((void*) &ret, "vkWriteAccelerationStructuresPropertiesKHR", (GLADapiproc) glad_vkWriteAccelerationStructuresPropertiesKHR, 7, device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    return ret;
}
PFN_vkWriteAccelerationStructuresPropertiesKHR glad_debug_vkWriteAccelerationStructuresPropertiesKHR = glad_debug_impl_vkWriteAccelerationStructuresPropertiesKHR;
#endif


static void glad_vk_load_VK_VERSION_1_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_0) return;
    glad_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers) load(userptr, "vkAllocateCommandBuffers");
    glad_vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets) load(userptr, "vkAllocateDescriptorSets");
    glad_vkAllocateMemory = (PFN_vkAllocateMemory) load(userptr, "vkAllocateMemory");
    glad_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer) load(userptr, "vkBeginCommandBuffer");
    glad_vkBindBufferMemory = (PFN_vkBindBufferMemory) load(userptr, "vkBindBufferMemory");
    glad_vkBindImageMemory = (PFN_vkBindImageMemory) load(userptr, "vkBindImageMemory");
    glad_vkCmdBeginQuery = (PFN_vkCmdBeginQuery) load(userptr, "vkCmdBeginQuery");
    glad_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass) load(userptr, "vkCmdBeginRenderPass");
    glad_vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets) load(userptr, "vkCmdBindDescriptorSets");
    glad_vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer) load(userptr, "vkCmdBindIndexBuffer");
    glad_vkCmdBindPipeline = (PFN_vkCmdBindPipeline) load(userptr, "vkCmdBindPipeline");
    glad_vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers) load(userptr, "vkCmdBindVertexBuffers");
    glad_vkCmdBlitImage = (PFN_vkCmdBlitImage) load(userptr, "vkCmdBlitImage");
    glad_vkCmdClearAttachments = (PFN_vkCmdClearAttachments) load(userptr, "vkCmdClearAttachments");
    glad_vkCmdClearColorImage = (PFN_vkCmdClearColorImage) load(userptr, "vkCmdClearColorImage");
    glad_vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage) load(userptr, "vkCmdClearDepthStencilImage");
    glad_vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer) load(userptr, "vkCmdCopyBuffer");
    glad_vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage) load(userptr, "vkCmdCopyBufferToImage");
    glad_vkCmdCopyImage = (PFN_vkCmdCopyImage) load(userptr, "vkCmdCopyImage");
    glad_vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer) load(userptr, "vkCmdCopyImageToBuffer");
    glad_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults) load(userptr, "vkCmdCopyQueryPoolResults");
    glad_vkCmdDispatch = (PFN_vkCmdDispatch) load(userptr, "vkCmdDispatch");
    glad_vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect) load(userptr, "vkCmdDispatchIndirect");
    glad_vkCmdDraw = (PFN_vkCmdDraw) load(userptr, "vkCmdDraw");
    glad_vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed) load(userptr, "vkCmdDrawIndexed");
    glad_vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect) load(userptr, "vkCmdDrawIndexedIndirect");
    glad_vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect) load(userptr, "vkCmdDrawIndirect");
    glad_vkCmdEndQuery = (PFN_vkCmdEndQuery) load(userptr, "vkCmdEndQuery");
    glad_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass) load(userptr, "vkCmdEndRenderPass");
    glad_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands) load(userptr, "vkCmdExecuteCommands");
    glad_vkCmdFillBuffer = (PFN_vkCmdFillBuffer) load(userptr, "vkCmdFillBuffer");
    glad_vkCmdNextSubpass = (PFN_vkCmdNextSubpass) load(userptr, "vkCmdNextSubpass");
    glad_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier) load(userptr, "vkCmdPipelineBarrier");
    glad_vkCmdPushConstants = (PFN_vkCmdPushConstants) load(userptr, "vkCmdPushConstants");
    glad_vkCmdResetEvent = (PFN_vkCmdResetEvent) load(userptr, "vkCmdResetEvent");
    glad_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool) load(userptr, "vkCmdResetQueryPool");
    glad_vkCmdResolveImage = (PFN_vkCmdResolveImage) load(userptr, "vkCmdResolveImage");
    glad_vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants) load(userptr, "vkCmdSetBlendConstants");
    glad_vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias) load(userptr, "vkCmdSetDepthBias");
    glad_vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds) load(userptr, "vkCmdSetDepthBounds");
    glad_vkCmdSetEvent = (PFN_vkCmdSetEvent) load(userptr, "vkCmdSetEvent");
    glad_vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth) load(userptr, "vkCmdSetLineWidth");
    glad_vkCmdSetScissor = (PFN_vkCmdSetScissor) load(userptr, "vkCmdSetScissor");
    glad_vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask) load(userptr, "vkCmdSetStencilCompareMask");
    glad_vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference) load(userptr, "vkCmdSetStencilReference");
    glad_vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask) load(userptr, "vkCmdSetStencilWriteMask");
    glad_vkCmdSetViewport = (PFN_vkCmdSetViewport) load(userptr, "vkCmdSetViewport");
    glad_vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer) load(userptr, "vkCmdUpdateBuffer");
    glad_vkCmdWaitEvents = (PFN_vkCmdWaitEvents) load(userptr, "vkCmdWaitEvents");
    glad_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp) load(userptr, "vkCmdWriteTimestamp");
    glad_vkCreateBuffer = (PFN_vkCreateBuffer) load(userptr, "vkCreateBuffer");
    glad_vkCreateBufferView = (PFN_vkCreateBufferView) load(userptr, "vkCreateBufferView");
    glad_vkCreateCommandPool = (PFN_vkCreateCommandPool) load(userptr, "vkCreateCommandPool");
    glad_vkCreateComputePipelines = (PFN_vkCreateComputePipelines) load(userptr, "vkCreateComputePipelines");
    glad_vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool) load(userptr, "vkCreateDescriptorPool");
    glad_vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout) load(userptr, "vkCreateDescriptorSetLayout");
    glad_vkCreateDevice = (PFN_vkCreateDevice) load(userptr, "vkCreateDevice");
    glad_vkCreateEvent = (PFN_vkCreateEvent) load(userptr, "vkCreateEvent");
    glad_vkCreateFence = (PFN_vkCreateFence) load(userptr, "vkCreateFence");
    glad_vkCreateFramebuffer = (PFN_vkCreateFramebuffer) load(userptr, "vkCreateFramebuffer");
    glad_vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines) load(userptr, "vkCreateGraphicsPipelines");
    glad_vkCreateImage = (PFN_vkCreateImage) load(userptr, "vkCreateImage");
    glad_vkCreateImageView = (PFN_vkCreateImageView) load(userptr, "vkCreateImageView");
    glad_vkCreateInstance = (PFN_vkCreateInstance) load(userptr, "vkCreateInstance");
    glad_vkCreatePipelineCache = (PFN_vkCreatePipelineCache) load(userptr, "vkCreatePipelineCache");
    glad_vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout) load(userptr, "vkCreatePipelineLayout");
    glad_vkCreateQueryPool = (PFN_vkCreateQueryPool) load(userptr, "vkCreateQueryPool");
    glad_vkCreateRenderPass = (PFN_vkCreateRenderPass) load(userptr, "vkCreateRenderPass");
    glad_vkCreateSampler = (PFN_vkCreateSampler) load(userptr, "vkCreateSampler");
    glad_vkCreateSemaphore = (PFN_vkCreateSemaphore) load(userptr, "vkCreateSemaphore");
    glad_vkCreateShaderModule = (PFN_vkCreateShaderModule) load(userptr, "vkCreateShaderModule");
    glad_vkDestroyBuffer = (PFN_vkDestroyBuffer) load(userptr, "vkDestroyBuffer");
    glad_vkDestroyBufferView = (PFN_vkDestroyBufferView) load(userptr, "vkDestroyBufferView");
    glad_vkDestroyCommandPool = (PFN_vkDestroyCommandPool) load(userptr, "vkDestroyCommandPool");
    glad_vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool) load(userptr, "vkDestroyDescriptorPool");
    glad_vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout) load(userptr, "vkDestroyDescriptorSetLayout");
    glad_vkDestroyDevice = (PFN_vkDestroyDevice) load(userptr, "vkDestroyDevice");
    glad_vkDestroyEvent = (PFN_vkDestroyEvent) load(userptr, "vkDestroyEvent");
    glad_vkDestroyFence = (PFN_vkDestroyFence) load(userptr, "vkDestroyFence");
    glad_vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer) load(userptr, "vkDestroyFramebuffer");
    glad_vkDestroyImage = (PFN_vkDestroyImage) load(userptr, "vkDestroyImage");
    glad_vkDestroyImageView = (PFN_vkDestroyImageView) load(userptr, "vkDestroyImageView");
    glad_vkDestroyInstance = (PFN_vkDestroyInstance) load(userptr, "vkDestroyInstance");
    glad_vkDestroyPipeline = (PFN_vkDestroyPipeline) load(userptr, "vkDestroyPipeline");
    glad_vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache) load(userptr, "vkDestroyPipelineCache");
    glad_vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout) load(userptr, "vkDestroyPipelineLayout");
    glad_vkDestroyQueryPool = (PFN_vkDestroyQueryPool) load(userptr, "vkDestroyQueryPool");
    glad_vkDestroyRenderPass = (PFN_vkDestroyRenderPass) load(userptr, "vkDestroyRenderPass");
    glad_vkDestroySampler = (PFN_vkDestroySampler) load(userptr, "vkDestroySampler");
    glad_vkDestroySemaphore = (PFN_vkDestroySemaphore) load(userptr, "vkDestroySemaphore");
    glad_vkDestroyShaderModule = (PFN_vkDestroyShaderModule) load(userptr, "vkDestroyShaderModule");
    glad_vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle) load(userptr, "vkDeviceWaitIdle");
    glad_vkEndCommandBuffer = (PFN_vkEndCommandBuffer) load(userptr, "vkEndCommandBuffer");
    glad_vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties) load(userptr, "vkEnumerateDeviceExtensionProperties");
    glad_vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties) load(userptr, "vkEnumerateDeviceLayerProperties");
    glad_vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties) load(userptr, "vkEnumerateInstanceExtensionProperties");
    glad_vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties) load(userptr, "vkEnumerateInstanceLayerProperties");
    glad_vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices) load(userptr, "vkEnumeratePhysicalDevices");
    glad_vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges) load(userptr, "vkFlushMappedMemoryRanges");
    glad_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers) load(userptr, "vkFreeCommandBuffers");
    glad_vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets) load(userptr, "vkFreeDescriptorSets");
    glad_vkFreeMemory = (PFN_vkFreeMemory) load(userptr, "vkFreeMemory");
    glad_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements) load(userptr, "vkGetBufferMemoryRequirements");
    glad_vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment) load(userptr, "vkGetDeviceMemoryCommitment");
    glad_vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr) load(userptr, "vkGetDeviceProcAddr");
    glad_vkGetDeviceQueue = (PFN_vkGetDeviceQueue) load(userptr, "vkGetDeviceQueue");
    glad_vkGetEventStatus = (PFN_vkGetEventStatus) load(userptr, "vkGetEventStatus");
    glad_vkGetFenceStatus = (PFN_vkGetFenceStatus) load(userptr, "vkGetFenceStatus");
    glad_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements) load(userptr, "vkGetImageMemoryRequirements");
    glad_vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements) load(userptr, "vkGetImageSparseMemoryRequirements");
    glad_vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout) load(userptr, "vkGetImageSubresourceLayout");
    glad_vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) load(userptr, "vkGetInstanceProcAddr");
    glad_vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures) load(userptr, "vkGetPhysicalDeviceFeatures");
    glad_vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties) load(userptr, "vkGetPhysicalDeviceFormatProperties");
    glad_vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties) load(userptr, "vkGetPhysicalDeviceImageFormatProperties");
    glad_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) load(userptr, "vkGetPhysicalDeviceMemoryProperties");
    glad_vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties) load(userptr, "vkGetPhysicalDeviceProperties");
    glad_vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties");
    glad_vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData) load(userptr, "vkGetPipelineCacheData");
    glad_vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults) load(userptr, "vkGetQueryPoolResults");
    glad_vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity) load(userptr, "vkGetRenderAreaGranularity");
    glad_vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges) load(userptr, "vkInvalidateMappedMemoryRanges");
    glad_vkMapMemory = (PFN_vkMapMemory) load(userptr, "vkMapMemory");
    glad_vkMergePipelineCaches = (PFN_vkMergePipelineCaches) load(userptr, "vkMergePipelineCaches");
    glad_vkQueueBindSparse = (PFN_vkQueueBindSparse) load(userptr, "vkQueueBindSparse");
    glad_vkQueueSubmit = (PFN_vkQueueSubmit) load(userptr, "vkQueueSubmit");
    glad_vkQueueWaitIdle = (PFN_vkQueueWaitIdle) load(userptr, "vkQueueWaitIdle");
    glad_vkResetCommandBuffer = (PFN_vkResetCommandBuffer) load(userptr, "vkResetCommandBuffer");
    glad_vkResetCommandPool = (PFN_vkResetCommandPool) load(userptr, "vkResetCommandPool");
    glad_vkResetDescriptorPool = (PFN_vkResetDescriptorPool) load(userptr, "vkResetDescriptorPool");
    glad_vkResetEvent = (PFN_vkResetEvent) load(userptr, "vkResetEvent");
    glad_vkResetFences = (PFN_vkResetFences) load(userptr, "vkResetFences");
    glad_vkSetEvent = (PFN_vkSetEvent) load(userptr, "vkSetEvent");
    glad_vkUnmapMemory = (PFN_vkUnmapMemory) load(userptr, "vkUnmapMemory");
    glad_vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets) load(userptr, "vkUpdateDescriptorSets");
    glad_vkWaitForFences = (PFN_vkWaitForFences) load(userptr, "vkWaitForFences");
}
static void glad_vk_load_VK_VERSION_1_1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_1) return;
    glad_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2) load(userptr, "vkBindBufferMemory2");
    glad_vkBindImageMemory2 = (PFN_vkBindImageMemory2) load(userptr, "vkBindImageMemory2");
    glad_vkCmdDispatchBase = (PFN_vkCmdDispatchBase) load(userptr, "vkCmdDispatchBase");
    glad_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask) load(userptr, "vkCmdSetDeviceMask");
    glad_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate) load(userptr, "vkCreateDescriptorUpdateTemplate");
    glad_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion) load(userptr, "vkCreateSamplerYcbcrConversion");
    glad_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate) load(userptr, "vkDestroyDescriptorUpdateTemplate");
    glad_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion) load(userptr, "vkDestroySamplerYcbcrConversion");
    glad_vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
    glad_vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups) load(userptr, "vkEnumeratePhysicalDeviceGroups");
    glad_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2) load(userptr, "vkGetBufferMemoryRequirements2");
    glad_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport) load(userptr, "vkGetDescriptorSetLayoutSupport");
    glad_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures) load(userptr, "vkGetDeviceGroupPeerMemoryFeatures");
    glad_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2) load(userptr, "vkGetDeviceQueue2");
    glad_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2) load(userptr, "vkGetImageMemoryRequirements2");
    glad_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2) load(userptr, "vkGetImageSparseMemoryRequirements2");
    glad_vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties) load(userptr, "vkGetPhysicalDeviceExternalBufferProperties");
    glad_vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties) load(userptr, "vkGetPhysicalDeviceExternalFenceProperties");
    glad_vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties) load(userptr, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    glad_vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2) load(userptr, "vkGetPhysicalDeviceFeatures2");
    glad_vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2) load(userptr, "vkGetPhysicalDeviceFormatProperties2");
    glad_vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceImageFormatProperties2");
    glad_vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2) load(userptr, "vkGetPhysicalDeviceMemoryProperties2");
    glad_vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2) load(userptr, "vkGetPhysicalDeviceProperties2");
    glad_vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties2");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    glad_vkTrimCommandPool = (PFN_vkTrimCommandPool) load(userptr, "vkTrimCommandPool");
    glad_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate) load(userptr, "vkUpdateDescriptorSetWithTemplate");
}
static void glad_vk_load_VK_VERSION_1_2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_VERSION_1_2) return;
    glad_vkCmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2) load(userptr, "vkCmdBeginRenderPass2");
    glad_vkCmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount) load(userptr, "vkCmdDrawIndexedIndirectCount");
    glad_vkCmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount) load(userptr, "vkCmdDrawIndirectCount");
    glad_vkCmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2) load(userptr, "vkCmdEndRenderPass2");
    glad_vkCmdNextSubpass2 = (PFN_vkCmdNextSubpass2) load(userptr, "vkCmdNextSubpass2");
    glad_vkCreateRenderPass2 = (PFN_vkCreateRenderPass2) load(userptr, "vkCreateRenderPass2");
    glad_vkGetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress) load(userptr, "vkGetBufferDeviceAddress");
    glad_vkGetBufferOpaqueCaptureAddress = (PFN_vkGetBufferOpaqueCaptureAddress) load(userptr, "vkGetBufferOpaqueCaptureAddress");
    glad_vkGetDeviceMemoryOpaqueCaptureAddress = (PFN_vkGetDeviceMemoryOpaqueCaptureAddress) load(userptr, "vkGetDeviceMemoryOpaqueCaptureAddress");
    glad_vkGetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue) load(userptr, "vkGetSemaphoreCounterValue");
    glad_vkResetQueryPool = (PFN_vkResetQueryPool) load(userptr, "vkResetQueryPool");
    glad_vkSignalSemaphore = (PFN_vkSignalSemaphore) load(userptr, "vkSignalSemaphore");
    glad_vkWaitSemaphores = (PFN_vkWaitSemaphores) load(userptr, "vkWaitSemaphores");
}
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
static void glad_vk_load_VK_EXT_acquire_xlib_display( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_acquire_xlib_display) return;
    glad_vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT) load(userptr, "vkAcquireXlibDisplayEXT");
    glad_vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT) load(userptr, "vkGetRandROutputDisplayEXT");
}
#endif
static void glad_vk_load_VK_EXT_buffer_device_address( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_buffer_device_address) return;
    glad_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT) load(userptr, "vkGetBufferDeviceAddressEXT");
}
static void glad_vk_load_VK_EXT_calibrated_timestamps( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_calibrated_timestamps) return;
    glad_vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT) load(userptr, "vkGetCalibratedTimestampsEXT");
    glad_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT) load(userptr, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
}
static void glad_vk_load_VK_EXT_conditional_rendering( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_conditional_rendering) return;
    glad_vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT) load(userptr, "vkCmdBeginConditionalRenderingEXT");
    glad_vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT) load(userptr, "vkCmdEndConditionalRenderingEXT");
}
static void glad_vk_load_VK_EXT_debug_marker( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_debug_marker) return;
    glad_vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT) load(userptr, "vkCmdDebugMarkerBeginEXT");
    glad_vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT) load(userptr, "vkCmdDebugMarkerEndEXT");
    glad_vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT) load(userptr, "vkCmdDebugMarkerInsertEXT");
    glad_vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT) load(userptr, "vkDebugMarkerSetObjectNameEXT");
    glad_vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT) load(userptr, "vkDebugMarkerSetObjectTagEXT");
}
static void glad_vk_load_VK_EXT_debug_report( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_debug_report) return;
    glad_vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT) load(userptr, "vkCreateDebugReportCallbackEXT");
    glad_vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT) load(userptr, "vkDebugReportMessageEXT");
    glad_vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT) load(userptr, "vkDestroyDebugReportCallbackEXT");
}
static void glad_vk_load_VK_EXT_debug_utils( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_debug_utils) return;
    glad_vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT) load(userptr, "vkCmdBeginDebugUtilsLabelEXT");
    glad_vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT) load(userptr, "vkCmdEndDebugUtilsLabelEXT");
    glad_vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT) load(userptr, "vkCmdInsertDebugUtilsLabelEXT");
    glad_vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT) load(userptr, "vkCreateDebugUtilsMessengerEXT");
    glad_vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT) load(userptr, "vkDestroyDebugUtilsMessengerEXT");
    glad_vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT) load(userptr, "vkQueueBeginDebugUtilsLabelEXT");
    glad_vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT) load(userptr, "vkQueueEndDebugUtilsLabelEXT");
    glad_vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT) load(userptr, "vkQueueInsertDebugUtilsLabelEXT");
    glad_vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT) load(userptr, "vkSetDebugUtilsObjectNameEXT");
    glad_vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT) load(userptr, "vkSetDebugUtilsObjectTagEXT");
    glad_vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT) load(userptr, "vkSubmitDebugUtilsMessageEXT");
}
static void glad_vk_load_VK_EXT_direct_mode_display( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_direct_mode_display) return;
    glad_vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT) load(userptr, "vkReleaseDisplayEXT");
}
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
static void glad_vk_load_VK_EXT_directfb_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_directfb_surface) return;
    glad_vkCreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT) load(userptr, "vkCreateDirectFBSurfaceEXT");
    glad_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT) load(userptr, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
}
#endif
static void glad_vk_load_VK_EXT_discard_rectangles( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_discard_rectangles) return;
    glad_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT) load(userptr, "vkCmdSetDiscardRectangleEXT");
}
static void glad_vk_load_VK_EXT_display_control( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_display_control) return;
    glad_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT) load(userptr, "vkDisplayPowerControlEXT");
    glad_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT) load(userptr, "vkGetSwapchainCounterEXT");
    glad_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT) load(userptr, "vkRegisterDeviceEventEXT");
    glad_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT) load(userptr, "vkRegisterDisplayEventEXT");
}
static void glad_vk_load_VK_EXT_display_surface_counter( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_display_surface_counter) return;
    glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT) load(userptr, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
}
static void glad_vk_load_VK_EXT_extended_dynamic_state( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_extended_dynamic_state) return;
    glad_vkCmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT) load(userptr, "vkCmdBindVertexBuffers2EXT");
    glad_vkCmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT) load(userptr, "vkCmdSetCullModeEXT");
    glad_vkCmdSetDepthBoundsTestEnableEXT = (PFN_vkCmdSetDepthBoundsTestEnableEXT) load(userptr, "vkCmdSetDepthBoundsTestEnableEXT");
    glad_vkCmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT) load(userptr, "vkCmdSetDepthCompareOpEXT");
    glad_vkCmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT) load(userptr, "vkCmdSetDepthTestEnableEXT");
    glad_vkCmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT) load(userptr, "vkCmdSetDepthWriteEnableEXT");
    glad_vkCmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT) load(userptr, "vkCmdSetFrontFaceEXT");
    glad_vkCmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT) load(userptr, "vkCmdSetPrimitiveTopologyEXT");
    glad_vkCmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT) load(userptr, "vkCmdSetScissorWithCountEXT");
    glad_vkCmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT) load(userptr, "vkCmdSetStencilOpEXT");
    glad_vkCmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT) load(userptr, "vkCmdSetStencilTestEnableEXT");
    glad_vkCmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT) load(userptr, "vkCmdSetViewportWithCountEXT");
}
static void glad_vk_load_VK_EXT_external_memory_host( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_external_memory_host) return;
    glad_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT) load(userptr, "vkGetMemoryHostPointerPropertiesEXT");
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
static void glad_vk_load_VK_EXT_full_screen_exclusive( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_full_screen_exclusive) return;
    glad_vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT) load(userptr, "vkAcquireFullScreenExclusiveModeEXT");
    glad_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT) load(userptr, "vkGetDeviceGroupSurfacePresentModes2EXT");
    glad_vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT) load(userptr, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
    glad_vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT) load(userptr, "vkReleaseFullScreenExclusiveModeEXT");
}
#endif
static void glad_vk_load_VK_EXT_hdr_metadata( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_hdr_metadata) return;
    glad_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT) load(userptr, "vkSetHdrMetadataEXT");
}
static void glad_vk_load_VK_EXT_headless_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_headless_surface) return;
    glad_vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT) load(userptr, "vkCreateHeadlessSurfaceEXT");
}
static void glad_vk_load_VK_EXT_host_query_reset( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_host_query_reset) return;
    glad_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT) load(userptr, "vkResetQueryPoolEXT");
}
static void glad_vk_load_VK_EXT_image_drm_format_modifier( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_image_drm_format_modifier) return;
    glad_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT) load(userptr, "vkGetImageDrmFormatModifierPropertiesEXT");
}
static void glad_vk_load_VK_EXT_line_rasterization( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_line_rasterization) return;
    glad_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT) load(userptr, "vkCmdSetLineStippleEXT");
}
#if defined(VK_USE_PLATFORM_METAL_EXT)
static void glad_vk_load_VK_EXT_metal_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_metal_surface) return;
    glad_vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT) load(userptr, "vkCreateMetalSurfaceEXT");
}
#endif
static void glad_vk_load_VK_EXT_private_data( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_private_data) return;
    glad_vkCreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT) load(userptr, "vkCreatePrivateDataSlotEXT");
    glad_vkDestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT) load(userptr, "vkDestroyPrivateDataSlotEXT");
    glad_vkGetPrivateDataEXT = (PFN_vkGetPrivateDataEXT) load(userptr, "vkGetPrivateDataEXT");
    glad_vkSetPrivateDataEXT = (PFN_vkSetPrivateDataEXT) load(userptr, "vkSetPrivateDataEXT");
}
static void glad_vk_load_VK_EXT_sample_locations( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_sample_locations) return;
    glad_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT) load(userptr, "vkCmdSetSampleLocationsEXT");
    glad_vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT) load(userptr, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
}
static void glad_vk_load_VK_EXT_tooling_info( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_tooling_info) return;
    glad_vkGetPhysicalDeviceToolPropertiesEXT = (PFN_vkGetPhysicalDeviceToolPropertiesEXT) load(userptr, "vkGetPhysicalDeviceToolPropertiesEXT");
}
static void glad_vk_load_VK_EXT_transform_feedback( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_transform_feedback) return;
    glad_vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT) load(userptr, "vkCmdBeginQueryIndexedEXT");
    glad_vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT) load(userptr, "vkCmdBeginTransformFeedbackEXT");
    glad_vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT) load(userptr, "vkCmdBindTransformFeedbackBuffersEXT");
    glad_vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT) load(userptr, "vkCmdDrawIndirectByteCountEXT");
    glad_vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT) load(userptr, "vkCmdEndQueryIndexedEXT");
    glad_vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT) load(userptr, "vkCmdEndTransformFeedbackEXT");
}
static void glad_vk_load_VK_EXT_validation_cache( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_EXT_validation_cache) return;
    glad_vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT) load(userptr, "vkCreateValidationCacheEXT");
    glad_vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT) load(userptr, "vkDestroyValidationCacheEXT");
    glad_vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT) load(userptr, "vkGetValidationCacheDataEXT");
    glad_vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT) load(userptr, "vkMergeValidationCachesEXT");
}
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
static void glad_vk_load_VK_KHR_android_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_android_surface) return;
    glad_vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR) load(userptr, "vkCreateAndroidSurfaceKHR");
}
#endif
static void glad_vk_load_VK_KHR_bind_memory2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_bind_memory2) return;
    glad_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR) load(userptr, "vkBindBufferMemory2KHR");
    glad_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR) load(userptr, "vkBindImageMemory2KHR");
}
static void glad_vk_load_VK_KHR_buffer_device_address( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_buffer_device_address) return;
    glad_vkGetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR) load(userptr, "vkGetBufferDeviceAddressKHR");
    glad_vkGetBufferOpaqueCaptureAddressKHR = (PFN_vkGetBufferOpaqueCaptureAddressKHR) load(userptr, "vkGetBufferOpaqueCaptureAddressKHR");
    glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR = (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR) load(userptr, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
}
static void glad_vk_load_VK_KHR_create_renderpass2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_create_renderpass2) return;
    glad_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR) load(userptr, "vkCmdBeginRenderPass2KHR");
    glad_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR) load(userptr, "vkCmdEndRenderPass2KHR");
    glad_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR) load(userptr, "vkCmdNextSubpass2KHR");
    glad_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR) load(userptr, "vkCreateRenderPass2KHR");
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
static void glad_vk_load_VK_KHR_deferred_host_operations( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_deferred_host_operations) return;
    glad_vkCreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR) load(userptr, "vkCreateDeferredOperationKHR");
    glad_vkDeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR) load(userptr, "vkDeferredOperationJoinKHR");
    glad_vkDestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR) load(userptr, "vkDestroyDeferredOperationKHR");
    glad_vkGetDeferredOperationMaxConcurrencyKHR = (PFN_vkGetDeferredOperationMaxConcurrencyKHR) load(userptr, "vkGetDeferredOperationMaxConcurrencyKHR");
    glad_vkGetDeferredOperationResultKHR = (PFN_vkGetDeferredOperationResultKHR) load(userptr, "vkGetDeferredOperationResultKHR");
}
#endif
static void glad_vk_load_VK_KHR_descriptor_update_template( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_descriptor_update_template) return;
    glad_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) load(userptr, "vkCmdPushDescriptorSetWithTemplateKHR");
    glad_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR) load(userptr, "vkCreateDescriptorUpdateTemplateKHR");
    glad_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR) load(userptr, "vkDestroyDescriptorUpdateTemplateKHR");
    glad_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR) load(userptr, "vkUpdateDescriptorSetWithTemplateKHR");
}
static void glad_vk_load_VK_KHR_device_group( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_device_group) return;
    glad_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) load(userptr, "vkAcquireNextImage2KHR");
    glad_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR) load(userptr, "vkCmdDispatchBaseKHR");
    glad_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR) load(userptr, "vkCmdSetDeviceMaskKHR");
    glad_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR) load(userptr, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
    glad_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) load(userptr, "vkGetDeviceGroupPresentCapabilitiesKHR");
    glad_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) load(userptr, "vkGetDeviceGroupSurfacePresentModesKHR");
    glad_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) load(userptr, "vkGetPhysicalDevicePresentRectanglesKHR");
}
static void glad_vk_load_VK_KHR_device_group_creation( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_device_group_creation) return;
    glad_vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR) load(userptr, "vkEnumeratePhysicalDeviceGroupsKHR");
}
static void glad_vk_load_VK_KHR_display( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_display) return;
    glad_vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR) load(userptr, "vkCreateDisplayModeKHR");
    glad_vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR) load(userptr, "vkCreateDisplayPlaneSurfaceKHR");
    glad_vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR) load(userptr, "vkGetDisplayModePropertiesKHR");
    glad_vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR) load(userptr, "vkGetDisplayPlaneCapabilitiesKHR");
    glad_vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR) load(userptr, "vkGetDisplayPlaneSupportedDisplaysKHR");
    glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR) load(userptr, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    glad_vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) load(userptr, "vkGetPhysicalDeviceDisplayPropertiesKHR");
}
static void glad_vk_load_VK_KHR_display_swapchain( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_display_swapchain) return;
    glad_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR) load(userptr, "vkCreateSharedSwapchainsKHR");
}
static void glad_vk_load_VK_KHR_draw_indirect_count( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_draw_indirect_count) return;
    glad_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR) load(userptr, "vkCmdDrawIndexedIndirectCountKHR");
    glad_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR) load(userptr, "vkCmdDrawIndirectCountKHR");
}
static void glad_vk_load_VK_KHR_external_fence_capabilities( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_fence_capabilities) return;
    glad_vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR) load(userptr, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
}
static void glad_vk_load_VK_KHR_external_fence_fd( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_fence_fd) return;
    glad_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR) load(userptr, "vkGetFenceFdKHR");
    glad_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR) load(userptr, "vkImportFenceFdKHR");
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
static void glad_vk_load_VK_KHR_external_fence_win32( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_fence_win32) return;
    glad_vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR) load(userptr, "vkGetFenceWin32HandleKHR");
    glad_vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR) load(userptr, "vkImportFenceWin32HandleKHR");
}
#endif
static void glad_vk_load_VK_KHR_external_memory_capabilities( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_memory_capabilities) return;
    glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR) load(userptr, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
}
static void glad_vk_load_VK_KHR_external_memory_fd( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_memory_fd) return;
    glad_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR) load(userptr, "vkGetMemoryFdKHR");
    glad_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR) load(userptr, "vkGetMemoryFdPropertiesKHR");
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
static void glad_vk_load_VK_KHR_external_memory_win32( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_memory_win32) return;
    glad_vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR) load(userptr, "vkGetMemoryWin32HandleKHR");
    glad_vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR) load(userptr, "vkGetMemoryWin32HandlePropertiesKHR");
}
#endif
static void glad_vk_load_VK_KHR_external_semaphore_capabilities( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_semaphore_capabilities) return;
    glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR) load(userptr, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
}
static void glad_vk_load_VK_KHR_external_semaphore_fd( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_semaphore_fd) return;
    glad_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR) load(userptr, "vkGetSemaphoreFdKHR");
    glad_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR) load(userptr, "vkImportSemaphoreFdKHR");
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
static void glad_vk_load_VK_KHR_external_semaphore_win32( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_external_semaphore_win32) return;
    glad_vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR) load(userptr, "vkGetSemaphoreWin32HandleKHR");
    glad_vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR) load(userptr, "vkImportSemaphoreWin32HandleKHR");
}
#endif
static void glad_vk_load_VK_KHR_get_display_properties2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_display_properties2) return;
    glad_vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR) load(userptr, "vkGetDisplayModeProperties2KHR");
    glad_vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR) load(userptr, "vkGetDisplayPlaneCapabilities2KHR");
    glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR) load(userptr, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    glad_vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR) load(userptr, "vkGetPhysicalDeviceDisplayProperties2KHR");
}
static void glad_vk_load_VK_KHR_get_memory_requirements2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_memory_requirements2) return;
    glad_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR) load(userptr, "vkGetBufferMemoryRequirements2KHR");
    glad_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR) load(userptr, "vkGetImageMemoryRequirements2KHR");
    glad_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR) load(userptr, "vkGetImageSparseMemoryRequirements2KHR");
}
static void glad_vk_load_VK_KHR_get_physical_device_properties2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_physical_device_properties2) return;
    glad_vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR) load(userptr, "vkGetPhysicalDeviceFeatures2KHR");
    glad_vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR) load(userptr, "vkGetPhysicalDeviceFormatProperties2KHR");
    glad_vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR) load(userptr, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    glad_vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR) load(userptr, "vkGetPhysicalDeviceMemoryProperties2KHR");
    glad_vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR) load(userptr, "vkGetPhysicalDeviceProperties2KHR");
    glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR) load(userptr, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR) load(userptr, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
}
static void glad_vk_load_VK_KHR_get_surface_capabilities2( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_get_surface_capabilities2) return;
    glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR) load(userptr, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    glad_vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR) load(userptr, "vkGetPhysicalDeviceSurfaceFormats2KHR");
}
static void glad_vk_load_VK_KHR_maintenance1( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_maintenance1) return;
    glad_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR) load(userptr, "vkTrimCommandPoolKHR");
}
static void glad_vk_load_VK_KHR_maintenance3( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_maintenance3) return;
    glad_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR) load(userptr, "vkGetDescriptorSetLayoutSupportKHR");
}
static void glad_vk_load_VK_KHR_performance_query( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_performance_query) return;
    glad_vkAcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR) load(userptr, "vkAcquireProfilingLockKHR");
    glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR) load(userptr, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR) load(userptr, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    glad_vkReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR) load(userptr, "vkReleaseProfilingLockKHR");
}
static void glad_vk_load_VK_KHR_pipeline_executable_properties( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_pipeline_executable_properties) return;
    glad_vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR) load(userptr, "vkGetPipelineExecutableInternalRepresentationsKHR");
    glad_vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR) load(userptr, "vkGetPipelineExecutablePropertiesKHR");
    glad_vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR) load(userptr, "vkGetPipelineExecutableStatisticsKHR");
}
static void glad_vk_load_VK_KHR_push_descriptor( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_push_descriptor) return;
    glad_vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR) load(userptr, "vkCmdPushDescriptorSetKHR");
    glad_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR) load(userptr, "vkCmdPushDescriptorSetWithTemplateKHR");
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
static void glad_vk_load_VK_KHR_ray_tracing( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_ray_tracing) return;
    glad_vkBindAccelerationStructureMemoryKHR = (PFN_vkBindAccelerationStructureMemoryKHR) load(userptr, "vkBindAccelerationStructureMemoryKHR");
    glad_vkBuildAccelerationStructureKHR = (PFN_vkBuildAccelerationStructureKHR) load(userptr, "vkBuildAccelerationStructureKHR");
    glad_vkCmdBuildAccelerationStructureIndirectKHR = (PFN_vkCmdBuildAccelerationStructureIndirectKHR) load(userptr, "vkCmdBuildAccelerationStructureIndirectKHR");
    glad_vkCmdBuildAccelerationStructureKHR = (PFN_vkCmdBuildAccelerationStructureKHR) load(userptr, "vkCmdBuildAccelerationStructureKHR");
    glad_vkCmdCopyAccelerationStructureKHR = (PFN_vkCmdCopyAccelerationStructureKHR) load(userptr, "vkCmdCopyAccelerationStructureKHR");
    glad_vkCmdCopyAccelerationStructureToMemoryKHR = (PFN_vkCmdCopyAccelerationStructureToMemoryKHR) load(userptr, "vkCmdCopyAccelerationStructureToMemoryKHR");
    glad_vkCmdCopyMemoryToAccelerationStructureKHR = (PFN_vkCmdCopyMemoryToAccelerationStructureKHR) load(userptr, "vkCmdCopyMemoryToAccelerationStructureKHR");
    glad_vkCmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR) load(userptr, "vkCmdTraceRaysIndirectKHR");
    glad_vkCmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR) load(userptr, "vkCmdTraceRaysKHR");
    glad_vkCmdWriteAccelerationStructuresPropertiesKHR = (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR) load(userptr, "vkCmdWriteAccelerationStructuresPropertiesKHR");
    glad_vkCopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR) load(userptr, "vkCopyAccelerationStructureKHR");
    glad_vkCopyAccelerationStructureToMemoryKHR = (PFN_vkCopyAccelerationStructureToMemoryKHR) load(userptr, "vkCopyAccelerationStructureToMemoryKHR");
    glad_vkCopyMemoryToAccelerationStructureKHR = (PFN_vkCopyMemoryToAccelerationStructureKHR) load(userptr, "vkCopyMemoryToAccelerationStructureKHR");
    glad_vkCreateAccelerationStructureKHR = (PFN_vkCreateAccelerationStructureKHR) load(userptr, "vkCreateAccelerationStructureKHR");
    glad_vkCreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR) load(userptr, "vkCreateRayTracingPipelinesKHR");
    glad_vkDestroyAccelerationStructureKHR = (PFN_vkDestroyAccelerationStructureKHR) load(userptr, "vkDestroyAccelerationStructureKHR");
    glad_vkGetAccelerationStructureDeviceAddressKHR = (PFN_vkGetAccelerationStructureDeviceAddressKHR) load(userptr, "vkGetAccelerationStructureDeviceAddressKHR");
    glad_vkGetAccelerationStructureMemoryRequirementsKHR = (PFN_vkGetAccelerationStructureMemoryRequirementsKHR) load(userptr, "vkGetAccelerationStructureMemoryRequirementsKHR");
    glad_vkGetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR) load(userptr, "vkGetDeviceAccelerationStructureCompatibilityKHR");
    glad_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR) load(userptr, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    glad_vkGetRayTracingShaderGroupHandlesKHR = (PFN_vkGetRayTracingShaderGroupHandlesKHR) load(userptr, "vkGetRayTracingShaderGroupHandlesKHR");
    glad_vkWriteAccelerationStructuresPropertiesKHR = (PFN_vkWriteAccelerationStructuresPropertiesKHR) load(userptr, "vkWriteAccelerationStructuresPropertiesKHR");
}
#endif
static void glad_vk_load_VK_KHR_sampler_ycbcr_conversion( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_sampler_ycbcr_conversion) return;
    glad_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR) load(userptr, "vkCreateSamplerYcbcrConversionKHR");
    glad_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR) load(userptr, "vkDestroySamplerYcbcrConversionKHR");
}
static void glad_vk_load_VK_KHR_shared_presentable_image( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_shared_presentable_image) return;
    glad_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR) load(userptr, "vkGetSwapchainStatusKHR");
}
static void glad_vk_load_VK_KHR_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_surface) return;
    glad_vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR) load(userptr, "vkDestroySurfaceKHR");
    glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR) load(userptr, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    glad_vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR) load(userptr, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    glad_vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR) load(userptr, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    glad_vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR) load(userptr, "vkGetPhysicalDeviceSurfaceSupportKHR");
}
static void glad_vk_load_VK_KHR_swapchain( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_swapchain) return;
    glad_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR) load(userptr, "vkAcquireNextImage2KHR");
    glad_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR) load(userptr, "vkAcquireNextImageKHR");
    glad_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR) load(userptr, "vkCreateSwapchainKHR");
    glad_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR) load(userptr, "vkDestroySwapchainKHR");
    glad_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR) load(userptr, "vkGetDeviceGroupPresentCapabilitiesKHR");
    glad_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR) load(userptr, "vkGetDeviceGroupSurfacePresentModesKHR");
    glad_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR) load(userptr, "vkGetPhysicalDevicePresentRectanglesKHR");
    glad_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR) load(userptr, "vkGetSwapchainImagesKHR");
    glad_vkQueuePresentKHR = (PFN_vkQueuePresentKHR) load(userptr, "vkQueuePresentKHR");
}
static void glad_vk_load_VK_KHR_timeline_semaphore( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_timeline_semaphore) return;
    glad_vkGetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR) load(userptr, "vkGetSemaphoreCounterValueKHR");
    glad_vkSignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR) load(userptr, "vkSignalSemaphoreKHR");
    glad_vkWaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR) load(userptr, "vkWaitSemaphoresKHR");
}
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
static void glad_vk_load_VK_KHR_wayland_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_wayland_surface) return;
    glad_vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR) load(userptr, "vkCreateWaylandSurfaceKHR");
    glad_vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR) load(userptr, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
}
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
static void glad_vk_load_VK_KHR_win32_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_win32_surface) return;
    glad_vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR) load(userptr, "vkCreateWin32SurfaceKHR");
    glad_vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR) load(userptr, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
}
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
static void glad_vk_load_VK_KHR_xcb_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_xcb_surface) return;
    glad_vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR) load(userptr, "vkCreateXcbSurfaceKHR");
    glad_vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR) load(userptr, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
}
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
static void glad_vk_load_VK_KHR_xlib_surface( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_VK_KHR_xlib_surface) return;
    glad_vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR) load(userptr, "vkCreateXlibSurfaceKHR");
    glad_vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR) load(userptr, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
}
#endif



static int glad_vk_get_extensions( VkPhysicalDevice physical_device, uint32_t *out_extension_count, char ***out_extensions) {
    uint32_t i;
    uint32_t instance_extension_count = 0;
    uint32_t device_extension_count = 0;
    uint32_t max_extension_count = 0;
    uint32_t total_extension_count = 0;
    char **extensions = NULL;
    VkExtensionProperties *ext_properties = NULL;
    VkResult result;

    if (glad_vkEnumerateInstanceExtensionProperties == NULL || (physical_device != NULL && glad_vkEnumerateDeviceExtensionProperties == NULL)) {
        return 0;
    }

    result = glad_vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, NULL);
    if (result != VK_SUCCESS) {
        return 0;
    }

    if (physical_device != NULL) {
        result = glad_vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, NULL);
        if (result != VK_SUCCESS) {
            return 0;
        }
    }

    total_extension_count = instance_extension_count + device_extension_count;
    if (total_extension_count <= 0) {
        return 0;
    }

    max_extension_count = instance_extension_count > device_extension_count
        ? instance_extension_count : device_extension_count;

    ext_properties = (VkExtensionProperties*) malloc(max_extension_count * sizeof(VkExtensionProperties));
    if (ext_properties == NULL) {
        goto glad_vk_get_extensions_error;
    }

    result = glad_vkEnumerateInstanceExtensionProperties(NULL, &instance_extension_count, ext_properties);
    if (result != VK_SUCCESS) {
        goto glad_vk_get_extensions_error;
    }

    extensions = (char**) calloc(total_extension_count, sizeof(char*));
    if (extensions == NULL) {
        goto glad_vk_get_extensions_error;
    }

    for (i = 0; i < instance_extension_count; ++i) {
        VkExtensionProperties ext = ext_properties[i];

        size_t extension_name_length = strlen(ext.extensionName) + 1;
        extensions[i] = (char*) malloc(extension_name_length * sizeof(char));
        if (extensions[i] == NULL) {
            goto glad_vk_get_extensions_error;
        }
        memcpy(extensions[i], ext.extensionName, extension_name_length * sizeof(char));
    }

    if (physical_device != NULL) {
        result = glad_vkEnumerateDeviceExtensionProperties(physical_device, NULL, &device_extension_count, ext_properties);
        if (result != VK_SUCCESS) {
            goto glad_vk_get_extensions_error;
        }

        for (i = 0; i < device_extension_count; ++i) {
            VkExtensionProperties ext = ext_properties[i];

            size_t extension_name_length = strlen(ext.extensionName) + 1;
            extensions[instance_extension_count + i] = (char*) malloc(extension_name_length * sizeof(char));
            if (extensions[instance_extension_count + i] == NULL) {
                goto glad_vk_get_extensions_error;
            }
            memcpy(extensions[instance_extension_count + i], ext.extensionName, extension_name_length * sizeof(char));
        }
    }

    free((void*) ext_properties);

    *out_extension_count = total_extension_count;
    *out_extensions = extensions;

    return 1;

glad_vk_get_extensions_error:
    free((void*) ext_properties);
    if (extensions != NULL) {
        for (i = 0; i < total_extension_count; ++i) {
            free((void*) extensions[i]);
        }
        free(extensions);
    }
    return 0;
}

static void glad_vk_free_extensions(uint32_t extension_count, char **extensions) {
    uint32_t i;

    for(i = 0; i < extension_count ; ++i) {
        free((void*) (extensions[i]));
    }

    free((void*) extensions);
}

static int glad_vk_has_extension(const char *name, uint32_t extension_count, char **extensions) {
    uint32_t i;

    for (i = 0; i < extension_count; ++i) {
        if(extensions[i] != NULL && strcmp(name, extensions[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

static GLADapiproc glad_vk_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_vk_find_extensions_vulkan( VkPhysicalDevice physical_device) {
    uint32_t extension_count = 0;
    char **extensions = NULL;
    if (!glad_vk_get_extensions(physical_device, &extension_count, &extensions)) return 0;

    GLAD_VK_EXT_4444_formats = glad_vk_has_extension("VK_EXT_4444_formats", extension_count, extensions);
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    GLAD_VK_EXT_acquire_xlib_display = glad_vk_has_extension("VK_EXT_acquire_xlib_display", extension_count, extensions);
#endif
    GLAD_VK_EXT_astc_decode_mode = glad_vk_has_extension("VK_EXT_astc_decode_mode", extension_count, extensions);
    GLAD_VK_EXT_blend_operation_advanced = glad_vk_has_extension("VK_EXT_blend_operation_advanced", extension_count, extensions);
    GLAD_VK_EXT_buffer_device_address = glad_vk_has_extension("VK_EXT_buffer_device_address", extension_count, extensions);
    GLAD_VK_EXT_calibrated_timestamps = glad_vk_has_extension("VK_EXT_calibrated_timestamps", extension_count, extensions);
    GLAD_VK_EXT_conditional_rendering = glad_vk_has_extension("VK_EXT_conditional_rendering", extension_count, extensions);
    GLAD_VK_EXT_conservative_rasterization = glad_vk_has_extension("VK_EXT_conservative_rasterization", extension_count, extensions);
    GLAD_VK_EXT_custom_border_color = glad_vk_has_extension("VK_EXT_custom_border_color", extension_count, extensions);
    GLAD_VK_EXT_debug_marker = glad_vk_has_extension("VK_EXT_debug_marker", extension_count, extensions);
    GLAD_VK_EXT_debug_report = glad_vk_has_extension("VK_EXT_debug_report", extension_count, extensions);
    GLAD_VK_EXT_debug_utils = glad_vk_has_extension("VK_EXT_debug_utils", extension_count, extensions);
    GLAD_VK_EXT_depth_clip_enable = glad_vk_has_extension("VK_EXT_depth_clip_enable", extension_count, extensions);
    GLAD_VK_EXT_depth_range_unrestricted = glad_vk_has_extension("VK_EXT_depth_range_unrestricted", extension_count, extensions);
    GLAD_VK_EXT_descriptor_indexing = glad_vk_has_extension("VK_EXT_descriptor_indexing", extension_count, extensions);
    GLAD_VK_EXT_direct_mode_display = glad_vk_has_extension("VK_EXT_direct_mode_display", extension_count, extensions);
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    GLAD_VK_EXT_directfb_surface = glad_vk_has_extension("VK_EXT_directfb_surface", extension_count, extensions);
#endif
    GLAD_VK_EXT_discard_rectangles = glad_vk_has_extension("VK_EXT_discard_rectangles", extension_count, extensions);
    GLAD_VK_EXT_display_control = glad_vk_has_extension("VK_EXT_display_control", extension_count, extensions);
    GLAD_VK_EXT_display_surface_counter = glad_vk_has_extension("VK_EXT_display_surface_counter", extension_count, extensions);
    GLAD_VK_EXT_extended_dynamic_state = glad_vk_has_extension("VK_EXT_extended_dynamic_state", extension_count, extensions);
    GLAD_VK_EXT_external_memory_dma_buf = glad_vk_has_extension("VK_EXT_external_memory_dma_buf", extension_count, extensions);
    GLAD_VK_EXT_external_memory_host = glad_vk_has_extension("VK_EXT_external_memory_host", extension_count, extensions);
    GLAD_VK_EXT_filter_cubic = glad_vk_has_extension("VK_EXT_filter_cubic", extension_count, extensions);
    GLAD_VK_EXT_fragment_density_map = glad_vk_has_extension("VK_EXT_fragment_density_map", extension_count, extensions);
    GLAD_VK_EXT_fragment_density_map2 = glad_vk_has_extension("VK_EXT_fragment_density_map2", extension_count, extensions);
    GLAD_VK_EXT_fragment_shader_interlock = glad_vk_has_extension("VK_EXT_fragment_shader_interlock", extension_count, extensions);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_EXT_full_screen_exclusive = glad_vk_has_extension("VK_EXT_full_screen_exclusive", extension_count, extensions);
#endif
    GLAD_VK_EXT_global_priority = glad_vk_has_extension("VK_EXT_global_priority", extension_count, extensions);
    GLAD_VK_EXT_hdr_metadata = glad_vk_has_extension("VK_EXT_hdr_metadata", extension_count, extensions);
    GLAD_VK_EXT_headless_surface = glad_vk_has_extension("VK_EXT_headless_surface", extension_count, extensions);
    GLAD_VK_EXT_host_query_reset = glad_vk_has_extension("VK_EXT_host_query_reset", extension_count, extensions);
    GLAD_VK_EXT_image_drm_format_modifier = glad_vk_has_extension("VK_EXT_image_drm_format_modifier", extension_count, extensions);
    GLAD_VK_EXT_image_robustness = glad_vk_has_extension("VK_EXT_image_robustness", extension_count, extensions);
    GLAD_VK_EXT_index_type_uint8 = glad_vk_has_extension("VK_EXT_index_type_uint8", extension_count, extensions);
    GLAD_VK_EXT_inline_uniform_block = glad_vk_has_extension("VK_EXT_inline_uniform_block", extension_count, extensions);
    GLAD_VK_EXT_line_rasterization = glad_vk_has_extension("VK_EXT_line_rasterization", extension_count, extensions);
    GLAD_VK_EXT_memory_budget = glad_vk_has_extension("VK_EXT_memory_budget", extension_count, extensions);
    GLAD_VK_EXT_memory_priority = glad_vk_has_extension("VK_EXT_memory_priority", extension_count, extensions);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    GLAD_VK_EXT_metal_surface = glad_vk_has_extension("VK_EXT_metal_surface", extension_count, extensions);
#endif
    GLAD_VK_EXT_pci_bus_info = glad_vk_has_extension("VK_EXT_pci_bus_info", extension_count, extensions);
    GLAD_VK_EXT_pipeline_creation_cache_control = glad_vk_has_extension("VK_EXT_pipeline_creation_cache_control", extension_count, extensions);
    GLAD_VK_EXT_pipeline_creation_feedback = glad_vk_has_extension("VK_EXT_pipeline_creation_feedback", extension_count, extensions);
    GLAD_VK_EXT_post_depth_coverage = glad_vk_has_extension("VK_EXT_post_depth_coverage", extension_count, extensions);
    GLAD_VK_EXT_private_data = glad_vk_has_extension("VK_EXT_private_data", extension_count, extensions);
    GLAD_VK_EXT_queue_family_foreign = glad_vk_has_extension("VK_EXT_queue_family_foreign", extension_count, extensions);
    GLAD_VK_EXT_robustness2 = glad_vk_has_extension("VK_EXT_robustness2", extension_count, extensions);
    GLAD_VK_EXT_sample_locations = glad_vk_has_extension("VK_EXT_sample_locations", extension_count, extensions);
    GLAD_VK_EXT_sampler_filter_minmax = glad_vk_has_extension("VK_EXT_sampler_filter_minmax", extension_count, extensions);
    GLAD_VK_EXT_scalar_block_layout = glad_vk_has_extension("VK_EXT_scalar_block_layout", extension_count, extensions);
    GLAD_VK_EXT_separate_stencil_usage = glad_vk_has_extension("VK_EXT_separate_stencil_usage", extension_count, extensions);
    GLAD_VK_EXT_shader_atomic_float = glad_vk_has_extension("VK_EXT_shader_atomic_float", extension_count, extensions);
    GLAD_VK_EXT_shader_demote_to_helper_invocation = glad_vk_has_extension("VK_EXT_shader_demote_to_helper_invocation", extension_count, extensions);
    GLAD_VK_EXT_shader_stencil_export = glad_vk_has_extension("VK_EXT_shader_stencil_export", extension_count, extensions);
    GLAD_VK_EXT_shader_subgroup_ballot = glad_vk_has_extension("VK_EXT_shader_subgroup_ballot", extension_count, extensions);
    GLAD_VK_EXT_shader_subgroup_vote = glad_vk_has_extension("VK_EXT_shader_subgroup_vote", extension_count, extensions);
    GLAD_VK_EXT_shader_viewport_index_layer = glad_vk_has_extension("VK_EXT_shader_viewport_index_layer", extension_count, extensions);
    GLAD_VK_EXT_subgroup_size_control = glad_vk_has_extension("VK_EXT_subgroup_size_control", extension_count, extensions);
    GLAD_VK_EXT_swapchain_colorspace = glad_vk_has_extension("VK_EXT_swapchain_colorspace", extension_count, extensions);
    GLAD_VK_EXT_texel_buffer_alignment = glad_vk_has_extension("VK_EXT_texel_buffer_alignment", extension_count, extensions);
    GLAD_VK_EXT_texture_compression_astc_hdr = glad_vk_has_extension("VK_EXT_texture_compression_astc_hdr", extension_count, extensions);
    GLAD_VK_EXT_tooling_info = glad_vk_has_extension("VK_EXT_tooling_info", extension_count, extensions);
    GLAD_VK_EXT_transform_feedback = glad_vk_has_extension("VK_EXT_transform_feedback", extension_count, extensions);
    GLAD_VK_EXT_validation_cache = glad_vk_has_extension("VK_EXT_validation_cache", extension_count, extensions);
    GLAD_VK_EXT_validation_features = glad_vk_has_extension("VK_EXT_validation_features", extension_count, extensions);
    GLAD_VK_EXT_validation_flags = glad_vk_has_extension("VK_EXT_validation_flags", extension_count, extensions);
    GLAD_VK_EXT_vertex_attribute_divisor = glad_vk_has_extension("VK_EXT_vertex_attribute_divisor", extension_count, extensions);
    GLAD_VK_EXT_ycbcr_image_arrays = glad_vk_has_extension("VK_EXT_ycbcr_image_arrays", extension_count, extensions);
    GLAD_VK_KHR_16bit_storage = glad_vk_has_extension("VK_KHR_16bit_storage", extension_count, extensions);
    GLAD_VK_KHR_8bit_storage = glad_vk_has_extension("VK_KHR_8bit_storage", extension_count, extensions);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    GLAD_VK_KHR_android_surface = glad_vk_has_extension("VK_KHR_android_surface", extension_count, extensions);
#endif
    GLAD_VK_KHR_bind_memory2 = glad_vk_has_extension("VK_KHR_bind_memory2", extension_count, extensions);
    GLAD_VK_KHR_buffer_device_address = glad_vk_has_extension("VK_KHR_buffer_device_address", extension_count, extensions);
    GLAD_VK_KHR_create_renderpass2 = glad_vk_has_extension("VK_KHR_create_renderpass2", extension_count, extensions);
    GLAD_VK_KHR_dedicated_allocation = glad_vk_has_extension("VK_KHR_dedicated_allocation", extension_count, extensions);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    GLAD_VK_KHR_deferred_host_operations = glad_vk_has_extension("VK_KHR_deferred_host_operations", extension_count, extensions);
#endif
    GLAD_VK_KHR_depth_stencil_resolve = glad_vk_has_extension("VK_KHR_depth_stencil_resolve", extension_count, extensions);
    GLAD_VK_KHR_descriptor_update_template = glad_vk_has_extension("VK_KHR_descriptor_update_template", extension_count, extensions);
    GLAD_VK_KHR_device_group = glad_vk_has_extension("VK_KHR_device_group", extension_count, extensions);
    GLAD_VK_KHR_device_group_creation = glad_vk_has_extension("VK_KHR_device_group_creation", extension_count, extensions);
    GLAD_VK_KHR_display = glad_vk_has_extension("VK_KHR_display", extension_count, extensions);
    GLAD_VK_KHR_display_swapchain = glad_vk_has_extension("VK_KHR_display_swapchain", extension_count, extensions);
    GLAD_VK_KHR_draw_indirect_count = glad_vk_has_extension("VK_KHR_draw_indirect_count", extension_count, extensions);
    GLAD_VK_KHR_driver_properties = glad_vk_has_extension("VK_KHR_driver_properties", extension_count, extensions);
    GLAD_VK_KHR_external_fence = glad_vk_has_extension("VK_KHR_external_fence", extension_count, extensions);
    GLAD_VK_KHR_external_fence_capabilities = glad_vk_has_extension("VK_KHR_external_fence_capabilities", extension_count, extensions);
    GLAD_VK_KHR_external_fence_fd = glad_vk_has_extension("VK_KHR_external_fence_fd", extension_count, extensions);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_KHR_external_fence_win32 = glad_vk_has_extension("VK_KHR_external_fence_win32", extension_count, extensions);
#endif
    GLAD_VK_KHR_external_memory = glad_vk_has_extension("VK_KHR_external_memory", extension_count, extensions);
    GLAD_VK_KHR_external_memory_capabilities = glad_vk_has_extension("VK_KHR_external_memory_capabilities", extension_count, extensions);
    GLAD_VK_KHR_external_memory_fd = glad_vk_has_extension("VK_KHR_external_memory_fd", extension_count, extensions);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_KHR_external_memory_win32 = glad_vk_has_extension("VK_KHR_external_memory_win32", extension_count, extensions);
#endif
    GLAD_VK_KHR_external_semaphore = glad_vk_has_extension("VK_KHR_external_semaphore", extension_count, extensions);
    GLAD_VK_KHR_external_semaphore_capabilities = glad_vk_has_extension("VK_KHR_external_semaphore_capabilities", extension_count, extensions);
    GLAD_VK_KHR_external_semaphore_fd = glad_vk_has_extension("VK_KHR_external_semaphore_fd", extension_count, extensions);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_KHR_external_semaphore_win32 = glad_vk_has_extension("VK_KHR_external_semaphore_win32", extension_count, extensions);
#endif
    GLAD_VK_KHR_get_display_properties2 = glad_vk_has_extension("VK_KHR_get_display_properties2", extension_count, extensions);
    GLAD_VK_KHR_get_memory_requirements2 = glad_vk_has_extension("VK_KHR_get_memory_requirements2", extension_count, extensions);
    GLAD_VK_KHR_get_physical_device_properties2 = glad_vk_has_extension("VK_KHR_get_physical_device_properties2", extension_count, extensions);
    GLAD_VK_KHR_get_surface_capabilities2 = glad_vk_has_extension("VK_KHR_get_surface_capabilities2", extension_count, extensions);
    GLAD_VK_KHR_image_format_list = glad_vk_has_extension("VK_KHR_image_format_list", extension_count, extensions);
    GLAD_VK_KHR_imageless_framebuffer = glad_vk_has_extension("VK_KHR_imageless_framebuffer", extension_count, extensions);
    GLAD_VK_KHR_incremental_present = glad_vk_has_extension("VK_KHR_incremental_present", extension_count, extensions);
    GLAD_VK_KHR_maintenance1 = glad_vk_has_extension("VK_KHR_maintenance1", extension_count, extensions);
    GLAD_VK_KHR_maintenance2 = glad_vk_has_extension("VK_KHR_maintenance2", extension_count, extensions);
    GLAD_VK_KHR_maintenance3 = glad_vk_has_extension("VK_KHR_maintenance3", extension_count, extensions);
    GLAD_VK_KHR_multiview = glad_vk_has_extension("VK_KHR_multiview", extension_count, extensions);
    GLAD_VK_KHR_performance_query = glad_vk_has_extension("VK_KHR_performance_query", extension_count, extensions);
    GLAD_VK_KHR_pipeline_executable_properties = glad_vk_has_extension("VK_KHR_pipeline_executable_properties", extension_count, extensions);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    GLAD_VK_KHR_pipeline_library = glad_vk_has_extension("VK_KHR_pipeline_library", extension_count, extensions);
#endif
    GLAD_VK_KHR_push_descriptor = glad_vk_has_extension("VK_KHR_push_descriptor", extension_count, extensions);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    GLAD_VK_KHR_ray_tracing = glad_vk_has_extension("VK_KHR_ray_tracing", extension_count, extensions);
#endif
    GLAD_VK_KHR_relaxed_block_layout = glad_vk_has_extension("VK_KHR_relaxed_block_layout", extension_count, extensions);
    GLAD_VK_KHR_sampler_mirror_clamp_to_edge = glad_vk_has_extension("VK_KHR_sampler_mirror_clamp_to_edge", extension_count, extensions);
    GLAD_VK_KHR_sampler_ycbcr_conversion = glad_vk_has_extension("VK_KHR_sampler_ycbcr_conversion", extension_count, extensions);
    GLAD_VK_KHR_separate_depth_stencil_layouts = glad_vk_has_extension("VK_KHR_separate_depth_stencil_layouts", extension_count, extensions);
    GLAD_VK_KHR_shader_atomic_int64 = glad_vk_has_extension("VK_KHR_shader_atomic_int64", extension_count, extensions);
    GLAD_VK_KHR_shader_clock = glad_vk_has_extension("VK_KHR_shader_clock", extension_count, extensions);
    GLAD_VK_KHR_shader_draw_parameters = glad_vk_has_extension("VK_KHR_shader_draw_parameters", extension_count, extensions);
    GLAD_VK_KHR_shader_float16_int8 = glad_vk_has_extension("VK_KHR_shader_float16_int8", extension_count, extensions);
    GLAD_VK_KHR_shader_float_controls = glad_vk_has_extension("VK_KHR_shader_float_controls", extension_count, extensions);
    GLAD_VK_KHR_shader_non_semantic_info = glad_vk_has_extension("VK_KHR_shader_non_semantic_info", extension_count, extensions);
    GLAD_VK_KHR_shader_subgroup_extended_types = glad_vk_has_extension("VK_KHR_shader_subgroup_extended_types", extension_count, extensions);
    GLAD_VK_KHR_shared_presentable_image = glad_vk_has_extension("VK_KHR_shared_presentable_image", extension_count, extensions);
    GLAD_VK_KHR_spirv_1_4 = glad_vk_has_extension("VK_KHR_spirv_1_4", extension_count, extensions);
    GLAD_VK_KHR_storage_buffer_storage_class = glad_vk_has_extension("VK_KHR_storage_buffer_storage_class", extension_count, extensions);
    GLAD_VK_KHR_surface = glad_vk_has_extension("VK_KHR_surface", extension_count, extensions);
    GLAD_VK_KHR_surface_protected_capabilities = glad_vk_has_extension("VK_KHR_surface_protected_capabilities", extension_count, extensions);
    GLAD_VK_KHR_swapchain = glad_vk_has_extension("VK_KHR_swapchain", extension_count, extensions);
    GLAD_VK_KHR_swapchain_mutable_format = glad_vk_has_extension("VK_KHR_swapchain_mutable_format", extension_count, extensions);
    GLAD_VK_KHR_timeline_semaphore = glad_vk_has_extension("VK_KHR_timeline_semaphore", extension_count, extensions);
    GLAD_VK_KHR_uniform_buffer_standard_layout = glad_vk_has_extension("VK_KHR_uniform_buffer_standard_layout", extension_count, extensions);
    GLAD_VK_KHR_variable_pointers = glad_vk_has_extension("VK_KHR_variable_pointers", extension_count, extensions);
    GLAD_VK_KHR_vulkan_memory_model = glad_vk_has_extension("VK_KHR_vulkan_memory_model", extension_count, extensions);
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    GLAD_VK_KHR_wayland_surface = glad_vk_has_extension("VK_KHR_wayland_surface", extension_count, extensions);
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_KHR_win32_keyed_mutex = glad_vk_has_extension("VK_KHR_win32_keyed_mutex", extension_count, extensions);
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    GLAD_VK_KHR_win32_surface = glad_vk_has_extension("VK_KHR_win32_surface", extension_count, extensions);
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    GLAD_VK_KHR_xcb_surface = glad_vk_has_extension("VK_KHR_xcb_surface", extension_count, extensions);
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    GLAD_VK_KHR_xlib_surface = glad_vk_has_extension("VK_KHR_xlib_surface", extension_count, extensions);
#endif

    (void) glad_vk_has_extension;

    glad_vk_free_extensions(extension_count, extensions);

    return 1;
}

static int glad_vk_find_core_vulkan( VkPhysicalDevice physical_device) {
    int major = 1;
    int minor = 0;

#ifdef VK_VERSION_1_1
    if (glad_vkEnumerateInstanceVersion != NULL) {
        uint32_t version;
        VkResult result;

        result = glad_vkEnumerateInstanceVersion(&version);
        if (result == VK_SUCCESS) {
            major = (int) VK_VERSION_MAJOR(version);
            minor = (int) VK_VERSION_MINOR(version);
        }
    }
#endif

    if (physical_device != NULL && glad_vkGetPhysicalDeviceProperties != NULL) {
        VkPhysicalDeviceProperties properties;
        glad_vkGetPhysicalDeviceProperties(physical_device, &properties);

        major = (int) VK_VERSION_MAJOR(properties.apiVersion);
        minor = (int) VK_VERSION_MINOR(properties.apiVersion);
    }

    GLAD_VK_VERSION_1_0 = (major == 1 && minor >= 0) || major > 1;
    GLAD_VK_VERSION_1_1 = (major == 1 && minor >= 1) || major > 1;
    GLAD_VK_VERSION_1_2 = (major == 1 && minor >= 2) || major > 1;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladLoadVulkanUserPtr( VkPhysicalDevice physical_device, GLADuserptrloadfunc load, void *userptr) {
    int version;

#ifdef VK_VERSION_1_1
    glad_vkEnumerateInstanceVersion  = (PFN_vkEnumerateInstanceVersion) load(userptr, "vkEnumerateInstanceVersion");
#endif
    version = glad_vk_find_core_vulkan( physical_device);
    if (!version) {
        return 0;
    }

    glad_vk_load_VK_VERSION_1_0(load, userptr);
    glad_vk_load_VK_VERSION_1_1(load, userptr);
    glad_vk_load_VK_VERSION_1_2(load, userptr);

    if (!glad_vk_find_extensions_vulkan( physical_device)) return 0;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    glad_vk_load_VK_EXT_acquire_xlib_display(load, userptr);
#endif
    glad_vk_load_VK_EXT_buffer_device_address(load, userptr);
    glad_vk_load_VK_EXT_calibrated_timestamps(load, userptr);
    glad_vk_load_VK_EXT_conditional_rendering(load, userptr);
    glad_vk_load_VK_EXT_debug_marker(load, userptr);
    glad_vk_load_VK_EXT_debug_report(load, userptr);
    glad_vk_load_VK_EXT_debug_utils(load, userptr);
    glad_vk_load_VK_EXT_direct_mode_display(load, userptr);
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    glad_vk_load_VK_EXT_directfb_surface(load, userptr);
#endif
    glad_vk_load_VK_EXT_discard_rectangles(load, userptr);
    glad_vk_load_VK_EXT_display_control(load, userptr);
    glad_vk_load_VK_EXT_display_surface_counter(load, userptr);
    glad_vk_load_VK_EXT_extended_dynamic_state(load, userptr);
    glad_vk_load_VK_EXT_external_memory_host(load, userptr);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_vk_load_VK_EXT_full_screen_exclusive(load, userptr);
#endif
    glad_vk_load_VK_EXT_hdr_metadata(load, userptr);
    glad_vk_load_VK_EXT_headless_surface(load, userptr);
    glad_vk_load_VK_EXT_host_query_reset(load, userptr);
    glad_vk_load_VK_EXT_image_drm_format_modifier(load, userptr);
    glad_vk_load_VK_EXT_line_rasterization(load, userptr);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    glad_vk_load_VK_EXT_metal_surface(load, userptr);
#endif
    glad_vk_load_VK_EXT_private_data(load, userptr);
    glad_vk_load_VK_EXT_sample_locations(load, userptr);
    glad_vk_load_VK_EXT_tooling_info(load, userptr);
    glad_vk_load_VK_EXT_transform_feedback(load, userptr);
    glad_vk_load_VK_EXT_validation_cache(load, userptr);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    glad_vk_load_VK_KHR_android_surface(load, userptr);
#endif
    glad_vk_load_VK_KHR_bind_memory2(load, userptr);
    glad_vk_load_VK_KHR_buffer_device_address(load, userptr);
    glad_vk_load_VK_KHR_create_renderpass2(load, userptr);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_vk_load_VK_KHR_deferred_host_operations(load, userptr);
#endif
    glad_vk_load_VK_KHR_descriptor_update_template(load, userptr);
    glad_vk_load_VK_KHR_device_group(load, userptr);
    glad_vk_load_VK_KHR_device_group_creation(load, userptr);
    glad_vk_load_VK_KHR_display(load, userptr);
    glad_vk_load_VK_KHR_display_swapchain(load, userptr);
    glad_vk_load_VK_KHR_draw_indirect_count(load, userptr);
    glad_vk_load_VK_KHR_external_fence_capabilities(load, userptr);
    glad_vk_load_VK_KHR_external_fence_fd(load, userptr);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_vk_load_VK_KHR_external_fence_win32(load, userptr);
#endif
    glad_vk_load_VK_KHR_external_memory_capabilities(load, userptr);
    glad_vk_load_VK_KHR_external_memory_fd(load, userptr);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_vk_load_VK_KHR_external_memory_win32(load, userptr);
#endif
    glad_vk_load_VK_KHR_external_semaphore_capabilities(load, userptr);
    glad_vk_load_VK_KHR_external_semaphore_fd(load, userptr);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_vk_load_VK_KHR_external_semaphore_win32(load, userptr);
#endif
    glad_vk_load_VK_KHR_get_display_properties2(load, userptr);
    glad_vk_load_VK_KHR_get_memory_requirements2(load, userptr);
    glad_vk_load_VK_KHR_get_physical_device_properties2(load, userptr);
    glad_vk_load_VK_KHR_get_surface_capabilities2(load, userptr);
    glad_vk_load_VK_KHR_maintenance1(load, userptr);
    glad_vk_load_VK_KHR_maintenance3(load, userptr);
    glad_vk_load_VK_KHR_performance_query(load, userptr);
    glad_vk_load_VK_KHR_pipeline_executable_properties(load, userptr);
    glad_vk_load_VK_KHR_push_descriptor(load, userptr);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_vk_load_VK_KHR_ray_tracing(load, userptr);
#endif
    glad_vk_load_VK_KHR_sampler_ycbcr_conversion(load, userptr);
    glad_vk_load_VK_KHR_shared_presentable_image(load, userptr);
    glad_vk_load_VK_KHR_surface(load, userptr);
    glad_vk_load_VK_KHR_swapchain(load, userptr);
    glad_vk_load_VK_KHR_timeline_semaphore(load, userptr);
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    glad_vk_load_VK_KHR_wayland_surface(load, userptr);
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_vk_load_VK_KHR_win32_surface(load, userptr);
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    glad_vk_load_VK_KHR_xcb_surface(load, userptr);
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    glad_vk_load_VK_KHR_xlib_surface(load, userptr);
#endif


    return version;
}


int gladLoadVulkan( VkPhysicalDevice physical_device, GLADloadfunc load) {
    return gladLoadVulkanUserPtr( physical_device, glad_vk_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}



 
void gladInstallVulkanDebug() {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkAcquireFullScreenExclusiveModeEXT = glad_debug_impl_vkAcquireFullScreenExclusiveModeEXT;
#endif
    glad_debug_vkAcquireNextImage2KHR = glad_debug_impl_vkAcquireNextImage2KHR;
    glad_debug_vkAcquireNextImageKHR = glad_debug_impl_vkAcquireNextImageKHR;
    glad_debug_vkAcquireProfilingLockKHR = glad_debug_impl_vkAcquireProfilingLockKHR;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    glad_debug_vkAcquireXlibDisplayEXT = glad_debug_impl_vkAcquireXlibDisplayEXT;
#endif
    glad_debug_vkAllocateCommandBuffers = glad_debug_impl_vkAllocateCommandBuffers;
    glad_debug_vkAllocateDescriptorSets = glad_debug_impl_vkAllocateDescriptorSets;
    glad_debug_vkAllocateMemory = glad_debug_impl_vkAllocateMemory;
    glad_debug_vkBeginCommandBuffer = glad_debug_impl_vkBeginCommandBuffer;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkBindAccelerationStructureMemoryKHR = glad_debug_impl_vkBindAccelerationStructureMemoryKHR;
#endif
    glad_debug_vkBindBufferMemory = glad_debug_impl_vkBindBufferMemory;
    glad_debug_vkBindBufferMemory2 = glad_debug_impl_vkBindBufferMemory2;
    glad_debug_vkBindBufferMemory2KHR = glad_debug_impl_vkBindBufferMemory2KHR;
    glad_debug_vkBindImageMemory = glad_debug_impl_vkBindImageMemory;
    glad_debug_vkBindImageMemory2 = glad_debug_impl_vkBindImageMemory2;
    glad_debug_vkBindImageMemory2KHR = glad_debug_impl_vkBindImageMemory2KHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkBuildAccelerationStructureKHR = glad_debug_impl_vkBuildAccelerationStructureKHR;
#endif
    glad_debug_vkCmdBeginConditionalRenderingEXT = glad_debug_impl_vkCmdBeginConditionalRenderingEXT;
    glad_debug_vkCmdBeginDebugUtilsLabelEXT = glad_debug_impl_vkCmdBeginDebugUtilsLabelEXT;
    glad_debug_vkCmdBeginQuery = glad_debug_impl_vkCmdBeginQuery;
    glad_debug_vkCmdBeginQueryIndexedEXT = glad_debug_impl_vkCmdBeginQueryIndexedEXT;
    glad_debug_vkCmdBeginRenderPass = glad_debug_impl_vkCmdBeginRenderPass;
    glad_debug_vkCmdBeginRenderPass2 = glad_debug_impl_vkCmdBeginRenderPass2;
    glad_debug_vkCmdBeginRenderPass2KHR = glad_debug_impl_vkCmdBeginRenderPass2KHR;
    glad_debug_vkCmdBeginTransformFeedbackEXT = glad_debug_impl_vkCmdBeginTransformFeedbackEXT;
    glad_debug_vkCmdBindDescriptorSets = glad_debug_impl_vkCmdBindDescriptorSets;
    glad_debug_vkCmdBindIndexBuffer = glad_debug_impl_vkCmdBindIndexBuffer;
    glad_debug_vkCmdBindPipeline = glad_debug_impl_vkCmdBindPipeline;
    glad_debug_vkCmdBindTransformFeedbackBuffersEXT = glad_debug_impl_vkCmdBindTransformFeedbackBuffersEXT;
    glad_debug_vkCmdBindVertexBuffers = glad_debug_impl_vkCmdBindVertexBuffers;
    glad_debug_vkCmdBindVertexBuffers2EXT = glad_debug_impl_vkCmdBindVertexBuffers2EXT;
    glad_debug_vkCmdBlitImage = glad_debug_impl_vkCmdBlitImage;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdBuildAccelerationStructureIndirectKHR = glad_debug_impl_vkCmdBuildAccelerationStructureIndirectKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdBuildAccelerationStructureKHR = glad_debug_impl_vkCmdBuildAccelerationStructureKHR;
#endif
    glad_debug_vkCmdClearAttachments = glad_debug_impl_vkCmdClearAttachments;
    glad_debug_vkCmdClearColorImage = glad_debug_impl_vkCmdClearColorImage;
    glad_debug_vkCmdClearDepthStencilImage = glad_debug_impl_vkCmdClearDepthStencilImage;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdCopyAccelerationStructureKHR = glad_debug_impl_vkCmdCopyAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdCopyAccelerationStructureToMemoryKHR = glad_debug_impl_vkCmdCopyAccelerationStructureToMemoryKHR;
#endif
    glad_debug_vkCmdCopyBuffer = glad_debug_impl_vkCmdCopyBuffer;
    glad_debug_vkCmdCopyBufferToImage = glad_debug_impl_vkCmdCopyBufferToImage;
    glad_debug_vkCmdCopyImage = glad_debug_impl_vkCmdCopyImage;
    glad_debug_vkCmdCopyImageToBuffer = glad_debug_impl_vkCmdCopyImageToBuffer;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdCopyMemoryToAccelerationStructureKHR = glad_debug_impl_vkCmdCopyMemoryToAccelerationStructureKHR;
#endif
    glad_debug_vkCmdCopyQueryPoolResults = glad_debug_impl_vkCmdCopyQueryPoolResults;
    glad_debug_vkCmdDebugMarkerBeginEXT = glad_debug_impl_vkCmdDebugMarkerBeginEXT;
    glad_debug_vkCmdDebugMarkerEndEXT = glad_debug_impl_vkCmdDebugMarkerEndEXT;
    glad_debug_vkCmdDebugMarkerInsertEXT = glad_debug_impl_vkCmdDebugMarkerInsertEXT;
    glad_debug_vkCmdDispatch = glad_debug_impl_vkCmdDispatch;
    glad_debug_vkCmdDispatchBase = glad_debug_impl_vkCmdDispatchBase;
    glad_debug_vkCmdDispatchBaseKHR = glad_debug_impl_vkCmdDispatchBaseKHR;
    glad_debug_vkCmdDispatchIndirect = glad_debug_impl_vkCmdDispatchIndirect;
    glad_debug_vkCmdDraw = glad_debug_impl_vkCmdDraw;
    glad_debug_vkCmdDrawIndexed = glad_debug_impl_vkCmdDrawIndexed;
    glad_debug_vkCmdDrawIndexedIndirect = glad_debug_impl_vkCmdDrawIndexedIndirect;
    glad_debug_vkCmdDrawIndexedIndirectCount = glad_debug_impl_vkCmdDrawIndexedIndirectCount;
    glad_debug_vkCmdDrawIndexedIndirectCountKHR = glad_debug_impl_vkCmdDrawIndexedIndirectCountKHR;
    glad_debug_vkCmdDrawIndirect = glad_debug_impl_vkCmdDrawIndirect;
    glad_debug_vkCmdDrawIndirectByteCountEXT = glad_debug_impl_vkCmdDrawIndirectByteCountEXT;
    glad_debug_vkCmdDrawIndirectCount = glad_debug_impl_vkCmdDrawIndirectCount;
    glad_debug_vkCmdDrawIndirectCountKHR = glad_debug_impl_vkCmdDrawIndirectCountKHR;
    glad_debug_vkCmdEndConditionalRenderingEXT = glad_debug_impl_vkCmdEndConditionalRenderingEXT;
    glad_debug_vkCmdEndDebugUtilsLabelEXT = glad_debug_impl_vkCmdEndDebugUtilsLabelEXT;
    glad_debug_vkCmdEndQuery = glad_debug_impl_vkCmdEndQuery;
    glad_debug_vkCmdEndQueryIndexedEXT = glad_debug_impl_vkCmdEndQueryIndexedEXT;
    glad_debug_vkCmdEndRenderPass = glad_debug_impl_vkCmdEndRenderPass;
    glad_debug_vkCmdEndRenderPass2 = glad_debug_impl_vkCmdEndRenderPass2;
    glad_debug_vkCmdEndRenderPass2KHR = glad_debug_impl_vkCmdEndRenderPass2KHR;
    glad_debug_vkCmdEndTransformFeedbackEXT = glad_debug_impl_vkCmdEndTransformFeedbackEXT;
    glad_debug_vkCmdExecuteCommands = glad_debug_impl_vkCmdExecuteCommands;
    glad_debug_vkCmdFillBuffer = glad_debug_impl_vkCmdFillBuffer;
    glad_debug_vkCmdInsertDebugUtilsLabelEXT = glad_debug_impl_vkCmdInsertDebugUtilsLabelEXT;
    glad_debug_vkCmdNextSubpass = glad_debug_impl_vkCmdNextSubpass;
    glad_debug_vkCmdNextSubpass2 = glad_debug_impl_vkCmdNextSubpass2;
    glad_debug_vkCmdNextSubpass2KHR = glad_debug_impl_vkCmdNextSubpass2KHR;
    glad_debug_vkCmdPipelineBarrier = glad_debug_impl_vkCmdPipelineBarrier;
    glad_debug_vkCmdPushConstants = glad_debug_impl_vkCmdPushConstants;
    glad_debug_vkCmdPushDescriptorSetKHR = glad_debug_impl_vkCmdPushDescriptorSetKHR;
    glad_debug_vkCmdPushDescriptorSetWithTemplateKHR = glad_debug_impl_vkCmdPushDescriptorSetWithTemplateKHR;
    glad_debug_vkCmdResetEvent = glad_debug_impl_vkCmdResetEvent;
    glad_debug_vkCmdResetQueryPool = glad_debug_impl_vkCmdResetQueryPool;
    glad_debug_vkCmdResolveImage = glad_debug_impl_vkCmdResolveImage;
    glad_debug_vkCmdSetBlendConstants = glad_debug_impl_vkCmdSetBlendConstants;
    glad_debug_vkCmdSetCullModeEXT = glad_debug_impl_vkCmdSetCullModeEXT;
    glad_debug_vkCmdSetDepthBias = glad_debug_impl_vkCmdSetDepthBias;
    glad_debug_vkCmdSetDepthBounds = glad_debug_impl_vkCmdSetDepthBounds;
    glad_debug_vkCmdSetDepthBoundsTestEnableEXT = glad_debug_impl_vkCmdSetDepthBoundsTestEnableEXT;
    glad_debug_vkCmdSetDepthCompareOpEXT = glad_debug_impl_vkCmdSetDepthCompareOpEXT;
    glad_debug_vkCmdSetDepthTestEnableEXT = glad_debug_impl_vkCmdSetDepthTestEnableEXT;
    glad_debug_vkCmdSetDepthWriteEnableEXT = glad_debug_impl_vkCmdSetDepthWriteEnableEXT;
    glad_debug_vkCmdSetDeviceMask = glad_debug_impl_vkCmdSetDeviceMask;
    glad_debug_vkCmdSetDeviceMaskKHR = glad_debug_impl_vkCmdSetDeviceMaskKHR;
    glad_debug_vkCmdSetDiscardRectangleEXT = glad_debug_impl_vkCmdSetDiscardRectangleEXT;
    glad_debug_vkCmdSetEvent = glad_debug_impl_vkCmdSetEvent;
    glad_debug_vkCmdSetFrontFaceEXT = glad_debug_impl_vkCmdSetFrontFaceEXT;
    glad_debug_vkCmdSetLineStippleEXT = glad_debug_impl_vkCmdSetLineStippleEXT;
    glad_debug_vkCmdSetLineWidth = glad_debug_impl_vkCmdSetLineWidth;
    glad_debug_vkCmdSetPrimitiveTopologyEXT = glad_debug_impl_vkCmdSetPrimitiveTopologyEXT;
    glad_debug_vkCmdSetSampleLocationsEXT = glad_debug_impl_vkCmdSetSampleLocationsEXT;
    glad_debug_vkCmdSetScissor = glad_debug_impl_vkCmdSetScissor;
    glad_debug_vkCmdSetScissorWithCountEXT = glad_debug_impl_vkCmdSetScissorWithCountEXT;
    glad_debug_vkCmdSetStencilCompareMask = glad_debug_impl_vkCmdSetStencilCompareMask;
    glad_debug_vkCmdSetStencilOpEXT = glad_debug_impl_vkCmdSetStencilOpEXT;
    glad_debug_vkCmdSetStencilReference = glad_debug_impl_vkCmdSetStencilReference;
    glad_debug_vkCmdSetStencilTestEnableEXT = glad_debug_impl_vkCmdSetStencilTestEnableEXT;
    glad_debug_vkCmdSetStencilWriteMask = glad_debug_impl_vkCmdSetStencilWriteMask;
    glad_debug_vkCmdSetViewport = glad_debug_impl_vkCmdSetViewport;
    glad_debug_vkCmdSetViewportWithCountEXT = glad_debug_impl_vkCmdSetViewportWithCountEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdTraceRaysIndirectKHR = glad_debug_impl_vkCmdTraceRaysIndirectKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdTraceRaysKHR = glad_debug_impl_vkCmdTraceRaysKHR;
#endif
    glad_debug_vkCmdUpdateBuffer = glad_debug_impl_vkCmdUpdateBuffer;
    glad_debug_vkCmdWaitEvents = glad_debug_impl_vkCmdWaitEvents;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdWriteAccelerationStructuresPropertiesKHR = glad_debug_impl_vkCmdWriteAccelerationStructuresPropertiesKHR;
#endif
    glad_debug_vkCmdWriteTimestamp = glad_debug_impl_vkCmdWriteTimestamp;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCopyAccelerationStructureKHR = glad_debug_impl_vkCopyAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCopyAccelerationStructureToMemoryKHR = glad_debug_impl_vkCopyAccelerationStructureToMemoryKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCopyMemoryToAccelerationStructureKHR = glad_debug_impl_vkCopyMemoryToAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCreateAccelerationStructureKHR = glad_debug_impl_vkCreateAccelerationStructureKHR;
#endif
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    glad_debug_vkCreateAndroidSurfaceKHR = glad_debug_impl_vkCreateAndroidSurfaceKHR;
#endif
    glad_debug_vkCreateBuffer = glad_debug_impl_vkCreateBuffer;
    glad_debug_vkCreateBufferView = glad_debug_impl_vkCreateBufferView;
    glad_debug_vkCreateCommandPool = glad_debug_impl_vkCreateCommandPool;
    glad_debug_vkCreateComputePipelines = glad_debug_impl_vkCreateComputePipelines;
    glad_debug_vkCreateDebugReportCallbackEXT = glad_debug_impl_vkCreateDebugReportCallbackEXT;
    glad_debug_vkCreateDebugUtilsMessengerEXT = glad_debug_impl_vkCreateDebugUtilsMessengerEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCreateDeferredOperationKHR = glad_debug_impl_vkCreateDeferredOperationKHR;
#endif
    glad_debug_vkCreateDescriptorPool = glad_debug_impl_vkCreateDescriptorPool;
    glad_debug_vkCreateDescriptorSetLayout = glad_debug_impl_vkCreateDescriptorSetLayout;
    glad_debug_vkCreateDescriptorUpdateTemplate = glad_debug_impl_vkCreateDescriptorUpdateTemplate;
    glad_debug_vkCreateDescriptorUpdateTemplateKHR = glad_debug_impl_vkCreateDescriptorUpdateTemplateKHR;
    glad_debug_vkCreateDevice = glad_debug_impl_vkCreateDevice;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    glad_debug_vkCreateDirectFBSurfaceEXT = glad_debug_impl_vkCreateDirectFBSurfaceEXT;
#endif
    glad_debug_vkCreateDisplayModeKHR = glad_debug_impl_vkCreateDisplayModeKHR;
    glad_debug_vkCreateDisplayPlaneSurfaceKHR = glad_debug_impl_vkCreateDisplayPlaneSurfaceKHR;
    glad_debug_vkCreateEvent = glad_debug_impl_vkCreateEvent;
    glad_debug_vkCreateFence = glad_debug_impl_vkCreateFence;
    glad_debug_vkCreateFramebuffer = glad_debug_impl_vkCreateFramebuffer;
    glad_debug_vkCreateGraphicsPipelines = glad_debug_impl_vkCreateGraphicsPipelines;
    glad_debug_vkCreateHeadlessSurfaceEXT = glad_debug_impl_vkCreateHeadlessSurfaceEXT;
    glad_debug_vkCreateImage = glad_debug_impl_vkCreateImage;
    glad_debug_vkCreateImageView = glad_debug_impl_vkCreateImageView;
    glad_debug_vkCreateInstance = glad_debug_impl_vkCreateInstance;
#if defined(VK_USE_PLATFORM_METAL_EXT)
    glad_debug_vkCreateMetalSurfaceEXT = glad_debug_impl_vkCreateMetalSurfaceEXT;
#endif
    glad_debug_vkCreatePipelineCache = glad_debug_impl_vkCreatePipelineCache;
    glad_debug_vkCreatePipelineLayout = glad_debug_impl_vkCreatePipelineLayout;
    glad_debug_vkCreatePrivateDataSlotEXT = glad_debug_impl_vkCreatePrivateDataSlotEXT;
    glad_debug_vkCreateQueryPool = glad_debug_impl_vkCreateQueryPool;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCreateRayTracingPipelinesKHR = glad_debug_impl_vkCreateRayTracingPipelinesKHR;
#endif
    glad_debug_vkCreateRenderPass = glad_debug_impl_vkCreateRenderPass;
    glad_debug_vkCreateRenderPass2 = glad_debug_impl_vkCreateRenderPass2;
    glad_debug_vkCreateRenderPass2KHR = glad_debug_impl_vkCreateRenderPass2KHR;
    glad_debug_vkCreateSampler = glad_debug_impl_vkCreateSampler;
    glad_debug_vkCreateSamplerYcbcrConversion = glad_debug_impl_vkCreateSamplerYcbcrConversion;
    glad_debug_vkCreateSamplerYcbcrConversionKHR = glad_debug_impl_vkCreateSamplerYcbcrConversionKHR;
    glad_debug_vkCreateSemaphore = glad_debug_impl_vkCreateSemaphore;
    glad_debug_vkCreateShaderModule = glad_debug_impl_vkCreateShaderModule;
    glad_debug_vkCreateSharedSwapchainsKHR = glad_debug_impl_vkCreateSharedSwapchainsKHR;
    glad_debug_vkCreateSwapchainKHR = glad_debug_impl_vkCreateSwapchainKHR;
    glad_debug_vkCreateValidationCacheEXT = glad_debug_impl_vkCreateValidationCacheEXT;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    glad_debug_vkCreateWaylandSurfaceKHR = glad_debug_impl_vkCreateWaylandSurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkCreateWin32SurfaceKHR = glad_debug_impl_vkCreateWin32SurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    glad_debug_vkCreateXcbSurfaceKHR = glad_debug_impl_vkCreateXcbSurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    glad_debug_vkCreateXlibSurfaceKHR = glad_debug_impl_vkCreateXlibSurfaceKHR;
#endif
    glad_debug_vkDebugMarkerSetObjectNameEXT = glad_debug_impl_vkDebugMarkerSetObjectNameEXT;
    glad_debug_vkDebugMarkerSetObjectTagEXT = glad_debug_impl_vkDebugMarkerSetObjectTagEXT;
    glad_debug_vkDebugReportMessageEXT = glad_debug_impl_vkDebugReportMessageEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkDeferredOperationJoinKHR = glad_debug_impl_vkDeferredOperationJoinKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkDestroyAccelerationStructureKHR = glad_debug_impl_vkDestroyAccelerationStructureKHR;
#endif
    glad_debug_vkDestroyBuffer = glad_debug_impl_vkDestroyBuffer;
    glad_debug_vkDestroyBufferView = glad_debug_impl_vkDestroyBufferView;
    glad_debug_vkDestroyCommandPool = glad_debug_impl_vkDestroyCommandPool;
    glad_debug_vkDestroyDebugReportCallbackEXT = glad_debug_impl_vkDestroyDebugReportCallbackEXT;
    glad_debug_vkDestroyDebugUtilsMessengerEXT = glad_debug_impl_vkDestroyDebugUtilsMessengerEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkDestroyDeferredOperationKHR = glad_debug_impl_vkDestroyDeferredOperationKHR;
#endif
    glad_debug_vkDestroyDescriptorPool = glad_debug_impl_vkDestroyDescriptorPool;
    glad_debug_vkDestroyDescriptorSetLayout = glad_debug_impl_vkDestroyDescriptorSetLayout;
    glad_debug_vkDestroyDescriptorUpdateTemplate = glad_debug_impl_vkDestroyDescriptorUpdateTemplate;
    glad_debug_vkDestroyDescriptorUpdateTemplateKHR = glad_debug_impl_vkDestroyDescriptorUpdateTemplateKHR;
    glad_debug_vkDestroyDevice = glad_debug_impl_vkDestroyDevice;
    glad_debug_vkDestroyEvent = glad_debug_impl_vkDestroyEvent;
    glad_debug_vkDestroyFence = glad_debug_impl_vkDestroyFence;
    glad_debug_vkDestroyFramebuffer = glad_debug_impl_vkDestroyFramebuffer;
    glad_debug_vkDestroyImage = glad_debug_impl_vkDestroyImage;
    glad_debug_vkDestroyImageView = glad_debug_impl_vkDestroyImageView;
    glad_debug_vkDestroyInstance = glad_debug_impl_vkDestroyInstance;
    glad_debug_vkDestroyPipeline = glad_debug_impl_vkDestroyPipeline;
    glad_debug_vkDestroyPipelineCache = glad_debug_impl_vkDestroyPipelineCache;
    glad_debug_vkDestroyPipelineLayout = glad_debug_impl_vkDestroyPipelineLayout;
    glad_debug_vkDestroyPrivateDataSlotEXT = glad_debug_impl_vkDestroyPrivateDataSlotEXT;
    glad_debug_vkDestroyQueryPool = glad_debug_impl_vkDestroyQueryPool;
    glad_debug_vkDestroyRenderPass = glad_debug_impl_vkDestroyRenderPass;
    glad_debug_vkDestroySampler = glad_debug_impl_vkDestroySampler;
    glad_debug_vkDestroySamplerYcbcrConversion = glad_debug_impl_vkDestroySamplerYcbcrConversion;
    glad_debug_vkDestroySamplerYcbcrConversionKHR = glad_debug_impl_vkDestroySamplerYcbcrConversionKHR;
    glad_debug_vkDestroySemaphore = glad_debug_impl_vkDestroySemaphore;
    glad_debug_vkDestroyShaderModule = glad_debug_impl_vkDestroyShaderModule;
    glad_debug_vkDestroySurfaceKHR = glad_debug_impl_vkDestroySurfaceKHR;
    glad_debug_vkDestroySwapchainKHR = glad_debug_impl_vkDestroySwapchainKHR;
    glad_debug_vkDestroyValidationCacheEXT = glad_debug_impl_vkDestroyValidationCacheEXT;
    glad_debug_vkDeviceWaitIdle = glad_debug_impl_vkDeviceWaitIdle;
    glad_debug_vkDisplayPowerControlEXT = glad_debug_impl_vkDisplayPowerControlEXT;
    glad_debug_vkEndCommandBuffer = glad_debug_impl_vkEndCommandBuffer;
    glad_debug_vkEnumerateDeviceExtensionProperties = glad_debug_impl_vkEnumerateDeviceExtensionProperties;
    glad_debug_vkEnumerateDeviceLayerProperties = glad_debug_impl_vkEnumerateDeviceLayerProperties;
    glad_debug_vkEnumerateInstanceExtensionProperties = glad_debug_impl_vkEnumerateInstanceExtensionProperties;
    glad_debug_vkEnumerateInstanceLayerProperties = glad_debug_impl_vkEnumerateInstanceLayerProperties;
    glad_debug_vkEnumerateInstanceVersion = glad_debug_impl_vkEnumerateInstanceVersion;
    glad_debug_vkEnumeratePhysicalDeviceGroups = glad_debug_impl_vkEnumeratePhysicalDeviceGroups;
    glad_debug_vkEnumeratePhysicalDeviceGroupsKHR = glad_debug_impl_vkEnumeratePhysicalDeviceGroupsKHR;
    glad_debug_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = glad_debug_impl_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
    glad_debug_vkEnumeratePhysicalDevices = glad_debug_impl_vkEnumeratePhysicalDevices;
    glad_debug_vkFlushMappedMemoryRanges = glad_debug_impl_vkFlushMappedMemoryRanges;
    glad_debug_vkFreeCommandBuffers = glad_debug_impl_vkFreeCommandBuffers;
    glad_debug_vkFreeDescriptorSets = glad_debug_impl_vkFreeDescriptorSets;
    glad_debug_vkFreeMemory = glad_debug_impl_vkFreeMemory;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetAccelerationStructureDeviceAddressKHR = glad_debug_impl_vkGetAccelerationStructureDeviceAddressKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetAccelerationStructureMemoryRequirementsKHR = glad_debug_impl_vkGetAccelerationStructureMemoryRequirementsKHR;
#endif
    glad_debug_vkGetBufferDeviceAddress = glad_debug_impl_vkGetBufferDeviceAddress;
    glad_debug_vkGetBufferDeviceAddressEXT = glad_debug_impl_vkGetBufferDeviceAddressEXT;
    glad_debug_vkGetBufferDeviceAddressKHR = glad_debug_impl_vkGetBufferDeviceAddressKHR;
    glad_debug_vkGetBufferMemoryRequirements = glad_debug_impl_vkGetBufferMemoryRequirements;
    glad_debug_vkGetBufferMemoryRequirements2 = glad_debug_impl_vkGetBufferMemoryRequirements2;
    glad_debug_vkGetBufferMemoryRequirements2KHR = glad_debug_impl_vkGetBufferMemoryRequirements2KHR;
    glad_debug_vkGetBufferOpaqueCaptureAddress = glad_debug_impl_vkGetBufferOpaqueCaptureAddress;
    glad_debug_vkGetBufferOpaqueCaptureAddressKHR = glad_debug_impl_vkGetBufferOpaqueCaptureAddressKHR;
    glad_debug_vkGetCalibratedTimestampsEXT = glad_debug_impl_vkGetCalibratedTimestampsEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetDeferredOperationMaxConcurrencyKHR = glad_debug_impl_vkGetDeferredOperationMaxConcurrencyKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetDeferredOperationResultKHR = glad_debug_impl_vkGetDeferredOperationResultKHR;
#endif
    glad_debug_vkGetDescriptorSetLayoutSupport = glad_debug_impl_vkGetDescriptorSetLayoutSupport;
    glad_debug_vkGetDescriptorSetLayoutSupportKHR = glad_debug_impl_vkGetDescriptorSetLayoutSupportKHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetDeviceAccelerationStructureCompatibilityKHR = glad_debug_impl_vkGetDeviceAccelerationStructureCompatibilityKHR;
#endif
    glad_debug_vkGetDeviceGroupPeerMemoryFeatures = glad_debug_impl_vkGetDeviceGroupPeerMemoryFeatures;
    glad_debug_vkGetDeviceGroupPeerMemoryFeaturesKHR = glad_debug_impl_vkGetDeviceGroupPeerMemoryFeaturesKHR;
    glad_debug_vkGetDeviceGroupPresentCapabilitiesKHR = glad_debug_impl_vkGetDeviceGroupPresentCapabilitiesKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetDeviceGroupSurfacePresentModes2EXT = glad_debug_impl_vkGetDeviceGroupSurfacePresentModes2EXT;
#endif
    glad_debug_vkGetDeviceGroupSurfacePresentModesKHR = glad_debug_impl_vkGetDeviceGroupSurfacePresentModesKHR;
    glad_debug_vkGetDeviceMemoryCommitment = glad_debug_impl_vkGetDeviceMemoryCommitment;
    glad_debug_vkGetDeviceMemoryOpaqueCaptureAddress = glad_debug_impl_vkGetDeviceMemoryOpaqueCaptureAddress;
    glad_debug_vkGetDeviceMemoryOpaqueCaptureAddressKHR = glad_debug_impl_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
    glad_debug_vkGetDeviceProcAddr = glad_debug_impl_vkGetDeviceProcAddr;
    glad_debug_vkGetDeviceQueue = glad_debug_impl_vkGetDeviceQueue;
    glad_debug_vkGetDeviceQueue2 = glad_debug_impl_vkGetDeviceQueue2;
    glad_debug_vkGetDisplayModeProperties2KHR = glad_debug_impl_vkGetDisplayModeProperties2KHR;
    glad_debug_vkGetDisplayModePropertiesKHR = glad_debug_impl_vkGetDisplayModePropertiesKHR;
    glad_debug_vkGetDisplayPlaneCapabilities2KHR = glad_debug_impl_vkGetDisplayPlaneCapabilities2KHR;
    glad_debug_vkGetDisplayPlaneCapabilitiesKHR = glad_debug_impl_vkGetDisplayPlaneCapabilitiesKHR;
    glad_debug_vkGetDisplayPlaneSupportedDisplaysKHR = glad_debug_impl_vkGetDisplayPlaneSupportedDisplaysKHR;
    glad_debug_vkGetEventStatus = glad_debug_impl_vkGetEventStatus;
    glad_debug_vkGetFenceFdKHR = glad_debug_impl_vkGetFenceFdKHR;
    glad_debug_vkGetFenceStatus = glad_debug_impl_vkGetFenceStatus;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetFenceWin32HandleKHR = glad_debug_impl_vkGetFenceWin32HandleKHR;
#endif
    glad_debug_vkGetImageDrmFormatModifierPropertiesEXT = glad_debug_impl_vkGetImageDrmFormatModifierPropertiesEXT;
    glad_debug_vkGetImageMemoryRequirements = glad_debug_impl_vkGetImageMemoryRequirements;
    glad_debug_vkGetImageMemoryRequirements2 = glad_debug_impl_vkGetImageMemoryRequirements2;
    glad_debug_vkGetImageMemoryRequirements2KHR = glad_debug_impl_vkGetImageMemoryRequirements2KHR;
    glad_debug_vkGetImageSparseMemoryRequirements = glad_debug_impl_vkGetImageSparseMemoryRequirements;
    glad_debug_vkGetImageSparseMemoryRequirements2 = glad_debug_impl_vkGetImageSparseMemoryRequirements2;
    glad_debug_vkGetImageSparseMemoryRequirements2KHR = glad_debug_impl_vkGetImageSparseMemoryRequirements2KHR;
    glad_debug_vkGetImageSubresourceLayout = glad_debug_impl_vkGetImageSubresourceLayout;
    glad_debug_vkGetInstanceProcAddr = glad_debug_impl_vkGetInstanceProcAddr;
    glad_debug_vkGetMemoryFdKHR = glad_debug_impl_vkGetMemoryFdKHR;
    glad_debug_vkGetMemoryFdPropertiesKHR = glad_debug_impl_vkGetMemoryFdPropertiesKHR;
    glad_debug_vkGetMemoryHostPointerPropertiesEXT = glad_debug_impl_vkGetMemoryHostPointerPropertiesEXT;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetMemoryWin32HandleKHR = glad_debug_impl_vkGetMemoryWin32HandleKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetMemoryWin32HandlePropertiesKHR = glad_debug_impl_vkGetMemoryWin32HandlePropertiesKHR;
#endif
    glad_debug_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = glad_debug_impl_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    glad_debug_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = glad_debug_impl_vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif
    glad_debug_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
    glad_debug_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
    glad_debug_vkGetPhysicalDeviceDisplayProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceDisplayProperties2KHR;
    glad_debug_vkGetPhysicalDeviceDisplayPropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceDisplayPropertiesKHR;
    glad_debug_vkGetPhysicalDeviceExternalBufferProperties = glad_debug_impl_vkGetPhysicalDeviceExternalBufferProperties;
    glad_debug_vkGetPhysicalDeviceExternalBufferPropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
    glad_debug_vkGetPhysicalDeviceExternalFenceProperties = glad_debug_impl_vkGetPhysicalDeviceExternalFenceProperties;
    glad_debug_vkGetPhysicalDeviceExternalFencePropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceExternalFencePropertiesKHR;
    glad_debug_vkGetPhysicalDeviceExternalSemaphoreProperties = glad_debug_impl_vkGetPhysicalDeviceExternalSemaphoreProperties;
    glad_debug_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = glad_debug_impl_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
    glad_debug_vkGetPhysicalDeviceFeatures = glad_debug_impl_vkGetPhysicalDeviceFeatures;
    glad_debug_vkGetPhysicalDeviceFeatures2 = glad_debug_impl_vkGetPhysicalDeviceFeatures2;
    glad_debug_vkGetPhysicalDeviceFeatures2KHR = glad_debug_impl_vkGetPhysicalDeviceFeatures2KHR;
    glad_debug_vkGetPhysicalDeviceFormatProperties = glad_debug_impl_vkGetPhysicalDeviceFormatProperties;
    glad_debug_vkGetPhysicalDeviceFormatProperties2 = glad_debug_impl_vkGetPhysicalDeviceFormatProperties2;
    glad_debug_vkGetPhysicalDeviceFormatProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceFormatProperties2KHR;
    glad_debug_vkGetPhysicalDeviceImageFormatProperties = glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties;
    glad_debug_vkGetPhysicalDeviceImageFormatProperties2 = glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties2;
    glad_debug_vkGetPhysicalDeviceImageFormatProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceImageFormatProperties2KHR;
    glad_debug_vkGetPhysicalDeviceMemoryProperties = glad_debug_impl_vkGetPhysicalDeviceMemoryProperties;
    glad_debug_vkGetPhysicalDeviceMemoryProperties2 = glad_debug_impl_vkGetPhysicalDeviceMemoryProperties2;
    glad_debug_vkGetPhysicalDeviceMemoryProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceMemoryProperties2KHR;
    glad_debug_vkGetPhysicalDeviceMultisamplePropertiesEXT = glad_debug_impl_vkGetPhysicalDeviceMultisamplePropertiesEXT;
    glad_debug_vkGetPhysicalDevicePresentRectanglesKHR = glad_debug_impl_vkGetPhysicalDevicePresentRectanglesKHR;
    glad_debug_vkGetPhysicalDeviceProperties = glad_debug_impl_vkGetPhysicalDeviceProperties;
    glad_debug_vkGetPhysicalDeviceProperties2 = glad_debug_impl_vkGetPhysicalDeviceProperties2;
    glad_debug_vkGetPhysicalDeviceProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceProperties2KHR;
    glad_debug_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
    glad_debug_vkGetPhysicalDeviceQueueFamilyProperties = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties;
    glad_debug_vkGetPhysicalDeviceQueueFamilyProperties2 = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties2;
    glad_debug_vkGetPhysicalDeviceQueueFamilyProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
    glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties = glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties;
    glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties2 = glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties2;
    glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = glad_debug_impl_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
    glad_debug_vkGetPhysicalDeviceSurfaceCapabilities2EXT = glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilities2EXT;
    glad_debug_vkGetPhysicalDeviceSurfaceCapabilities2KHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilities2KHR;
    glad_debug_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
    glad_debug_vkGetPhysicalDeviceSurfaceFormats2KHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceFormats2KHR;
    glad_debug_vkGetPhysicalDeviceSurfaceFormatsKHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceFormatsKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetPhysicalDeviceSurfacePresentModes2EXT = glad_debug_impl_vkGetPhysicalDeviceSurfacePresentModes2EXT;
#endif
    glad_debug_vkGetPhysicalDeviceSurfacePresentModesKHR = glad_debug_impl_vkGetPhysicalDeviceSurfacePresentModesKHR;
    glad_debug_vkGetPhysicalDeviceSurfaceSupportKHR = glad_debug_impl_vkGetPhysicalDeviceSurfaceSupportKHR;
    glad_debug_vkGetPhysicalDeviceToolPropertiesEXT = glad_debug_impl_vkGetPhysicalDeviceToolPropertiesEXT;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    glad_debug_vkGetPhysicalDeviceWaylandPresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetPhysicalDeviceWin32PresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    glad_debug_vkGetPhysicalDeviceXcbPresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    glad_debug_vkGetPhysicalDeviceXlibPresentationSupportKHR = glad_debug_impl_vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif
    glad_debug_vkGetPipelineCacheData = glad_debug_impl_vkGetPipelineCacheData;
    glad_debug_vkGetPipelineExecutableInternalRepresentationsKHR = glad_debug_impl_vkGetPipelineExecutableInternalRepresentationsKHR;
    glad_debug_vkGetPipelineExecutablePropertiesKHR = glad_debug_impl_vkGetPipelineExecutablePropertiesKHR;
    glad_debug_vkGetPipelineExecutableStatisticsKHR = glad_debug_impl_vkGetPipelineExecutableStatisticsKHR;
    glad_debug_vkGetPrivateDataEXT = glad_debug_impl_vkGetPrivateDataEXT;
    glad_debug_vkGetQueryPoolResults = glad_debug_impl_vkGetQueryPoolResults;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    glad_debug_vkGetRandROutputDisplayEXT = glad_debug_impl_vkGetRandROutputDisplayEXT;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = glad_debug_impl_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetRayTracingShaderGroupHandlesKHR = glad_debug_impl_vkGetRayTracingShaderGroupHandlesKHR;
#endif
    glad_debug_vkGetRenderAreaGranularity = glad_debug_impl_vkGetRenderAreaGranularity;
    glad_debug_vkGetSemaphoreCounterValue = glad_debug_impl_vkGetSemaphoreCounterValue;
    glad_debug_vkGetSemaphoreCounterValueKHR = glad_debug_impl_vkGetSemaphoreCounterValueKHR;
    glad_debug_vkGetSemaphoreFdKHR = glad_debug_impl_vkGetSemaphoreFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetSemaphoreWin32HandleKHR = glad_debug_impl_vkGetSemaphoreWin32HandleKHR;
#endif
    glad_debug_vkGetSwapchainCounterEXT = glad_debug_impl_vkGetSwapchainCounterEXT;
    glad_debug_vkGetSwapchainImagesKHR = glad_debug_impl_vkGetSwapchainImagesKHR;
    glad_debug_vkGetSwapchainStatusKHR = glad_debug_impl_vkGetSwapchainStatusKHR;
    glad_debug_vkGetValidationCacheDataEXT = glad_debug_impl_vkGetValidationCacheDataEXT;
    glad_debug_vkImportFenceFdKHR = glad_debug_impl_vkImportFenceFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkImportFenceWin32HandleKHR = glad_debug_impl_vkImportFenceWin32HandleKHR;
#endif
    glad_debug_vkImportSemaphoreFdKHR = glad_debug_impl_vkImportSemaphoreFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkImportSemaphoreWin32HandleKHR = glad_debug_impl_vkImportSemaphoreWin32HandleKHR;
#endif
    glad_debug_vkInvalidateMappedMemoryRanges = glad_debug_impl_vkInvalidateMappedMemoryRanges;
    glad_debug_vkMapMemory = glad_debug_impl_vkMapMemory;
    glad_debug_vkMergePipelineCaches = glad_debug_impl_vkMergePipelineCaches;
    glad_debug_vkMergeValidationCachesEXT = glad_debug_impl_vkMergeValidationCachesEXT;
    glad_debug_vkQueueBeginDebugUtilsLabelEXT = glad_debug_impl_vkQueueBeginDebugUtilsLabelEXT;
    glad_debug_vkQueueBindSparse = glad_debug_impl_vkQueueBindSparse;
    glad_debug_vkQueueEndDebugUtilsLabelEXT = glad_debug_impl_vkQueueEndDebugUtilsLabelEXT;
    glad_debug_vkQueueInsertDebugUtilsLabelEXT = glad_debug_impl_vkQueueInsertDebugUtilsLabelEXT;
    glad_debug_vkQueuePresentKHR = glad_debug_impl_vkQueuePresentKHR;
    glad_debug_vkQueueSubmit = glad_debug_impl_vkQueueSubmit;
    glad_debug_vkQueueWaitIdle = glad_debug_impl_vkQueueWaitIdle;
    glad_debug_vkRegisterDeviceEventEXT = glad_debug_impl_vkRegisterDeviceEventEXT;
    glad_debug_vkRegisterDisplayEventEXT = glad_debug_impl_vkRegisterDisplayEventEXT;
    glad_debug_vkReleaseDisplayEXT = glad_debug_impl_vkReleaseDisplayEXT;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkReleaseFullScreenExclusiveModeEXT = glad_debug_impl_vkReleaseFullScreenExclusiveModeEXT;
#endif
    glad_debug_vkReleaseProfilingLockKHR = glad_debug_impl_vkReleaseProfilingLockKHR;
    glad_debug_vkResetCommandBuffer = glad_debug_impl_vkResetCommandBuffer;
    glad_debug_vkResetCommandPool = glad_debug_impl_vkResetCommandPool;
    glad_debug_vkResetDescriptorPool = glad_debug_impl_vkResetDescriptorPool;
    glad_debug_vkResetEvent = glad_debug_impl_vkResetEvent;
    glad_debug_vkResetFences = glad_debug_impl_vkResetFences;
    glad_debug_vkResetQueryPool = glad_debug_impl_vkResetQueryPool;
    glad_debug_vkResetQueryPoolEXT = glad_debug_impl_vkResetQueryPoolEXT;
    glad_debug_vkSetDebugUtilsObjectNameEXT = glad_debug_impl_vkSetDebugUtilsObjectNameEXT;
    glad_debug_vkSetDebugUtilsObjectTagEXT = glad_debug_impl_vkSetDebugUtilsObjectTagEXT;
    glad_debug_vkSetEvent = glad_debug_impl_vkSetEvent;
    glad_debug_vkSetHdrMetadataEXT = glad_debug_impl_vkSetHdrMetadataEXT;
    glad_debug_vkSetPrivateDataEXT = glad_debug_impl_vkSetPrivateDataEXT;
    glad_debug_vkSignalSemaphore = glad_debug_impl_vkSignalSemaphore;
    glad_debug_vkSignalSemaphoreKHR = glad_debug_impl_vkSignalSemaphoreKHR;
    glad_debug_vkSubmitDebugUtilsMessageEXT = glad_debug_impl_vkSubmitDebugUtilsMessageEXT;
    glad_debug_vkTrimCommandPool = glad_debug_impl_vkTrimCommandPool;
    glad_debug_vkTrimCommandPoolKHR = glad_debug_impl_vkTrimCommandPoolKHR;
    glad_debug_vkUnmapMemory = glad_debug_impl_vkUnmapMemory;
    glad_debug_vkUpdateDescriptorSetWithTemplate = glad_debug_impl_vkUpdateDescriptorSetWithTemplate;
    glad_debug_vkUpdateDescriptorSetWithTemplateKHR = glad_debug_impl_vkUpdateDescriptorSetWithTemplateKHR;
    glad_debug_vkUpdateDescriptorSets = glad_debug_impl_vkUpdateDescriptorSets;
    glad_debug_vkWaitForFences = glad_debug_impl_vkWaitForFences;
    glad_debug_vkWaitSemaphores = glad_debug_impl_vkWaitSemaphores;
    glad_debug_vkWaitSemaphoresKHR = glad_debug_impl_vkWaitSemaphoresKHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkWriteAccelerationStructuresPropertiesKHR = glad_debug_impl_vkWriteAccelerationStructuresPropertiesKHR;
#endif
}

void gladUninstallVulkanDebug() {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkAcquireFullScreenExclusiveModeEXT = glad_vkAcquireFullScreenExclusiveModeEXT;
#endif
    glad_debug_vkAcquireNextImage2KHR = glad_vkAcquireNextImage2KHR;
    glad_debug_vkAcquireNextImageKHR = glad_vkAcquireNextImageKHR;
    glad_debug_vkAcquireProfilingLockKHR = glad_vkAcquireProfilingLockKHR;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    glad_debug_vkAcquireXlibDisplayEXT = glad_vkAcquireXlibDisplayEXT;
#endif
    glad_debug_vkAllocateCommandBuffers = glad_vkAllocateCommandBuffers;
    glad_debug_vkAllocateDescriptorSets = glad_vkAllocateDescriptorSets;
    glad_debug_vkAllocateMemory = glad_vkAllocateMemory;
    glad_debug_vkBeginCommandBuffer = glad_vkBeginCommandBuffer;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkBindAccelerationStructureMemoryKHR = glad_vkBindAccelerationStructureMemoryKHR;
#endif
    glad_debug_vkBindBufferMemory = glad_vkBindBufferMemory;
    glad_debug_vkBindBufferMemory2 = glad_vkBindBufferMemory2;
    glad_debug_vkBindBufferMemory2KHR = glad_vkBindBufferMemory2KHR;
    glad_debug_vkBindImageMemory = glad_vkBindImageMemory;
    glad_debug_vkBindImageMemory2 = glad_vkBindImageMemory2;
    glad_debug_vkBindImageMemory2KHR = glad_vkBindImageMemory2KHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkBuildAccelerationStructureKHR = glad_vkBuildAccelerationStructureKHR;
#endif
    glad_debug_vkCmdBeginConditionalRenderingEXT = glad_vkCmdBeginConditionalRenderingEXT;
    glad_debug_vkCmdBeginDebugUtilsLabelEXT = glad_vkCmdBeginDebugUtilsLabelEXT;
    glad_debug_vkCmdBeginQuery = glad_vkCmdBeginQuery;
    glad_debug_vkCmdBeginQueryIndexedEXT = glad_vkCmdBeginQueryIndexedEXT;
    glad_debug_vkCmdBeginRenderPass = glad_vkCmdBeginRenderPass;
    glad_debug_vkCmdBeginRenderPass2 = glad_vkCmdBeginRenderPass2;
    glad_debug_vkCmdBeginRenderPass2KHR = glad_vkCmdBeginRenderPass2KHR;
    glad_debug_vkCmdBeginTransformFeedbackEXT = glad_vkCmdBeginTransformFeedbackEXT;
    glad_debug_vkCmdBindDescriptorSets = glad_vkCmdBindDescriptorSets;
    glad_debug_vkCmdBindIndexBuffer = glad_vkCmdBindIndexBuffer;
    glad_debug_vkCmdBindPipeline = glad_vkCmdBindPipeline;
    glad_debug_vkCmdBindTransformFeedbackBuffersEXT = glad_vkCmdBindTransformFeedbackBuffersEXT;
    glad_debug_vkCmdBindVertexBuffers = glad_vkCmdBindVertexBuffers;
    glad_debug_vkCmdBindVertexBuffers2EXT = glad_vkCmdBindVertexBuffers2EXT;
    glad_debug_vkCmdBlitImage = glad_vkCmdBlitImage;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdBuildAccelerationStructureIndirectKHR = glad_vkCmdBuildAccelerationStructureIndirectKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdBuildAccelerationStructureKHR = glad_vkCmdBuildAccelerationStructureKHR;
#endif
    glad_debug_vkCmdClearAttachments = glad_vkCmdClearAttachments;
    glad_debug_vkCmdClearColorImage = glad_vkCmdClearColorImage;
    glad_debug_vkCmdClearDepthStencilImage = glad_vkCmdClearDepthStencilImage;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdCopyAccelerationStructureKHR = glad_vkCmdCopyAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdCopyAccelerationStructureToMemoryKHR = glad_vkCmdCopyAccelerationStructureToMemoryKHR;
#endif
    glad_debug_vkCmdCopyBuffer = glad_vkCmdCopyBuffer;
    glad_debug_vkCmdCopyBufferToImage = glad_vkCmdCopyBufferToImage;
    glad_debug_vkCmdCopyImage = glad_vkCmdCopyImage;
    glad_debug_vkCmdCopyImageToBuffer = glad_vkCmdCopyImageToBuffer;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdCopyMemoryToAccelerationStructureKHR = glad_vkCmdCopyMemoryToAccelerationStructureKHR;
#endif
    glad_debug_vkCmdCopyQueryPoolResults = glad_vkCmdCopyQueryPoolResults;
    glad_debug_vkCmdDebugMarkerBeginEXT = glad_vkCmdDebugMarkerBeginEXT;
    glad_debug_vkCmdDebugMarkerEndEXT = glad_vkCmdDebugMarkerEndEXT;
    glad_debug_vkCmdDebugMarkerInsertEXT = glad_vkCmdDebugMarkerInsertEXT;
    glad_debug_vkCmdDispatch = glad_vkCmdDispatch;
    glad_debug_vkCmdDispatchBase = glad_vkCmdDispatchBase;
    glad_debug_vkCmdDispatchBaseKHR = glad_vkCmdDispatchBaseKHR;
    glad_debug_vkCmdDispatchIndirect = glad_vkCmdDispatchIndirect;
    glad_debug_vkCmdDraw = glad_vkCmdDraw;
    glad_debug_vkCmdDrawIndexed = glad_vkCmdDrawIndexed;
    glad_debug_vkCmdDrawIndexedIndirect = glad_vkCmdDrawIndexedIndirect;
    glad_debug_vkCmdDrawIndexedIndirectCount = glad_vkCmdDrawIndexedIndirectCount;
    glad_debug_vkCmdDrawIndexedIndirectCountKHR = glad_vkCmdDrawIndexedIndirectCountKHR;
    glad_debug_vkCmdDrawIndirect = glad_vkCmdDrawIndirect;
    glad_debug_vkCmdDrawIndirectByteCountEXT = glad_vkCmdDrawIndirectByteCountEXT;
    glad_debug_vkCmdDrawIndirectCount = glad_vkCmdDrawIndirectCount;
    glad_debug_vkCmdDrawIndirectCountKHR = glad_vkCmdDrawIndirectCountKHR;
    glad_debug_vkCmdEndConditionalRenderingEXT = glad_vkCmdEndConditionalRenderingEXT;
    glad_debug_vkCmdEndDebugUtilsLabelEXT = glad_vkCmdEndDebugUtilsLabelEXT;
    glad_debug_vkCmdEndQuery = glad_vkCmdEndQuery;
    glad_debug_vkCmdEndQueryIndexedEXT = glad_vkCmdEndQueryIndexedEXT;
    glad_debug_vkCmdEndRenderPass = glad_vkCmdEndRenderPass;
    glad_debug_vkCmdEndRenderPass2 = glad_vkCmdEndRenderPass2;
    glad_debug_vkCmdEndRenderPass2KHR = glad_vkCmdEndRenderPass2KHR;
    glad_debug_vkCmdEndTransformFeedbackEXT = glad_vkCmdEndTransformFeedbackEXT;
    glad_debug_vkCmdExecuteCommands = glad_vkCmdExecuteCommands;
    glad_debug_vkCmdFillBuffer = glad_vkCmdFillBuffer;
    glad_debug_vkCmdInsertDebugUtilsLabelEXT = glad_vkCmdInsertDebugUtilsLabelEXT;
    glad_debug_vkCmdNextSubpass = glad_vkCmdNextSubpass;
    glad_debug_vkCmdNextSubpass2 = glad_vkCmdNextSubpass2;
    glad_debug_vkCmdNextSubpass2KHR = glad_vkCmdNextSubpass2KHR;
    glad_debug_vkCmdPipelineBarrier = glad_vkCmdPipelineBarrier;
    glad_debug_vkCmdPushConstants = glad_vkCmdPushConstants;
    glad_debug_vkCmdPushDescriptorSetKHR = glad_vkCmdPushDescriptorSetKHR;
    glad_debug_vkCmdPushDescriptorSetWithTemplateKHR = glad_vkCmdPushDescriptorSetWithTemplateKHR;
    glad_debug_vkCmdResetEvent = glad_vkCmdResetEvent;
    glad_debug_vkCmdResetQueryPool = glad_vkCmdResetQueryPool;
    glad_debug_vkCmdResolveImage = glad_vkCmdResolveImage;
    glad_debug_vkCmdSetBlendConstants = glad_vkCmdSetBlendConstants;
    glad_debug_vkCmdSetCullModeEXT = glad_vkCmdSetCullModeEXT;
    glad_debug_vkCmdSetDepthBias = glad_vkCmdSetDepthBias;
    glad_debug_vkCmdSetDepthBounds = glad_vkCmdSetDepthBounds;
    glad_debug_vkCmdSetDepthBoundsTestEnableEXT = glad_vkCmdSetDepthBoundsTestEnableEXT;
    glad_debug_vkCmdSetDepthCompareOpEXT = glad_vkCmdSetDepthCompareOpEXT;
    glad_debug_vkCmdSetDepthTestEnableEXT = glad_vkCmdSetDepthTestEnableEXT;
    glad_debug_vkCmdSetDepthWriteEnableEXT = glad_vkCmdSetDepthWriteEnableEXT;
    glad_debug_vkCmdSetDeviceMask = glad_vkCmdSetDeviceMask;
    glad_debug_vkCmdSetDeviceMaskKHR = glad_vkCmdSetDeviceMaskKHR;
    glad_debug_vkCmdSetDiscardRectangleEXT = glad_vkCmdSetDiscardRectangleEXT;
    glad_debug_vkCmdSetEvent = glad_vkCmdSetEvent;
    glad_debug_vkCmdSetFrontFaceEXT = glad_vkCmdSetFrontFaceEXT;
    glad_debug_vkCmdSetLineStippleEXT = glad_vkCmdSetLineStippleEXT;
    glad_debug_vkCmdSetLineWidth = glad_vkCmdSetLineWidth;
    glad_debug_vkCmdSetPrimitiveTopologyEXT = glad_vkCmdSetPrimitiveTopologyEXT;
    glad_debug_vkCmdSetSampleLocationsEXT = glad_vkCmdSetSampleLocationsEXT;
    glad_debug_vkCmdSetScissor = glad_vkCmdSetScissor;
    glad_debug_vkCmdSetScissorWithCountEXT = glad_vkCmdSetScissorWithCountEXT;
    glad_debug_vkCmdSetStencilCompareMask = glad_vkCmdSetStencilCompareMask;
    glad_debug_vkCmdSetStencilOpEXT = glad_vkCmdSetStencilOpEXT;
    glad_debug_vkCmdSetStencilReference = glad_vkCmdSetStencilReference;
    glad_debug_vkCmdSetStencilTestEnableEXT = glad_vkCmdSetStencilTestEnableEXT;
    glad_debug_vkCmdSetStencilWriteMask = glad_vkCmdSetStencilWriteMask;
    glad_debug_vkCmdSetViewport = glad_vkCmdSetViewport;
    glad_debug_vkCmdSetViewportWithCountEXT = glad_vkCmdSetViewportWithCountEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdTraceRaysIndirectKHR = glad_vkCmdTraceRaysIndirectKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdTraceRaysKHR = glad_vkCmdTraceRaysKHR;
#endif
    glad_debug_vkCmdUpdateBuffer = glad_vkCmdUpdateBuffer;
    glad_debug_vkCmdWaitEvents = glad_vkCmdWaitEvents;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCmdWriteAccelerationStructuresPropertiesKHR = glad_vkCmdWriteAccelerationStructuresPropertiesKHR;
#endif
    glad_debug_vkCmdWriteTimestamp = glad_vkCmdWriteTimestamp;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCopyAccelerationStructureKHR = glad_vkCopyAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCopyAccelerationStructureToMemoryKHR = glad_vkCopyAccelerationStructureToMemoryKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCopyMemoryToAccelerationStructureKHR = glad_vkCopyMemoryToAccelerationStructureKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCreateAccelerationStructureKHR = glad_vkCreateAccelerationStructureKHR;
#endif
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    glad_debug_vkCreateAndroidSurfaceKHR = glad_vkCreateAndroidSurfaceKHR;
#endif
    glad_debug_vkCreateBuffer = glad_vkCreateBuffer;
    glad_debug_vkCreateBufferView = glad_vkCreateBufferView;
    glad_debug_vkCreateCommandPool = glad_vkCreateCommandPool;
    glad_debug_vkCreateComputePipelines = glad_vkCreateComputePipelines;
    glad_debug_vkCreateDebugReportCallbackEXT = glad_vkCreateDebugReportCallbackEXT;
    glad_debug_vkCreateDebugUtilsMessengerEXT = glad_vkCreateDebugUtilsMessengerEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCreateDeferredOperationKHR = glad_vkCreateDeferredOperationKHR;
#endif
    glad_debug_vkCreateDescriptorPool = glad_vkCreateDescriptorPool;
    glad_debug_vkCreateDescriptorSetLayout = glad_vkCreateDescriptorSetLayout;
    glad_debug_vkCreateDescriptorUpdateTemplate = glad_vkCreateDescriptorUpdateTemplate;
    glad_debug_vkCreateDescriptorUpdateTemplateKHR = glad_vkCreateDescriptorUpdateTemplateKHR;
    glad_debug_vkCreateDevice = glad_vkCreateDevice;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    glad_debug_vkCreateDirectFBSurfaceEXT = glad_vkCreateDirectFBSurfaceEXT;
#endif
    glad_debug_vkCreateDisplayModeKHR = glad_vkCreateDisplayModeKHR;
    glad_debug_vkCreateDisplayPlaneSurfaceKHR = glad_vkCreateDisplayPlaneSurfaceKHR;
    glad_debug_vkCreateEvent = glad_vkCreateEvent;
    glad_debug_vkCreateFence = glad_vkCreateFence;
    glad_debug_vkCreateFramebuffer = glad_vkCreateFramebuffer;
    glad_debug_vkCreateGraphicsPipelines = glad_vkCreateGraphicsPipelines;
    glad_debug_vkCreateHeadlessSurfaceEXT = glad_vkCreateHeadlessSurfaceEXT;
    glad_debug_vkCreateImage = glad_vkCreateImage;
    glad_debug_vkCreateImageView = glad_vkCreateImageView;
    glad_debug_vkCreateInstance = glad_vkCreateInstance;
#if defined(VK_USE_PLATFORM_METAL_EXT)
    glad_debug_vkCreateMetalSurfaceEXT = glad_vkCreateMetalSurfaceEXT;
#endif
    glad_debug_vkCreatePipelineCache = glad_vkCreatePipelineCache;
    glad_debug_vkCreatePipelineLayout = glad_vkCreatePipelineLayout;
    glad_debug_vkCreatePrivateDataSlotEXT = glad_vkCreatePrivateDataSlotEXT;
    glad_debug_vkCreateQueryPool = glad_vkCreateQueryPool;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkCreateRayTracingPipelinesKHR = glad_vkCreateRayTracingPipelinesKHR;
#endif
    glad_debug_vkCreateRenderPass = glad_vkCreateRenderPass;
    glad_debug_vkCreateRenderPass2 = glad_vkCreateRenderPass2;
    glad_debug_vkCreateRenderPass2KHR = glad_vkCreateRenderPass2KHR;
    glad_debug_vkCreateSampler = glad_vkCreateSampler;
    glad_debug_vkCreateSamplerYcbcrConversion = glad_vkCreateSamplerYcbcrConversion;
    glad_debug_vkCreateSamplerYcbcrConversionKHR = glad_vkCreateSamplerYcbcrConversionKHR;
    glad_debug_vkCreateSemaphore = glad_vkCreateSemaphore;
    glad_debug_vkCreateShaderModule = glad_vkCreateShaderModule;
    glad_debug_vkCreateSharedSwapchainsKHR = glad_vkCreateSharedSwapchainsKHR;
    glad_debug_vkCreateSwapchainKHR = glad_vkCreateSwapchainKHR;
    glad_debug_vkCreateValidationCacheEXT = glad_vkCreateValidationCacheEXT;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    glad_debug_vkCreateWaylandSurfaceKHR = glad_vkCreateWaylandSurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkCreateWin32SurfaceKHR = glad_vkCreateWin32SurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    glad_debug_vkCreateXcbSurfaceKHR = glad_vkCreateXcbSurfaceKHR;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    glad_debug_vkCreateXlibSurfaceKHR = glad_vkCreateXlibSurfaceKHR;
#endif
    glad_debug_vkDebugMarkerSetObjectNameEXT = glad_vkDebugMarkerSetObjectNameEXT;
    glad_debug_vkDebugMarkerSetObjectTagEXT = glad_vkDebugMarkerSetObjectTagEXT;
    glad_debug_vkDebugReportMessageEXT = glad_vkDebugReportMessageEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkDeferredOperationJoinKHR = glad_vkDeferredOperationJoinKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkDestroyAccelerationStructureKHR = glad_vkDestroyAccelerationStructureKHR;
#endif
    glad_debug_vkDestroyBuffer = glad_vkDestroyBuffer;
    glad_debug_vkDestroyBufferView = glad_vkDestroyBufferView;
    glad_debug_vkDestroyCommandPool = glad_vkDestroyCommandPool;
    glad_debug_vkDestroyDebugReportCallbackEXT = glad_vkDestroyDebugReportCallbackEXT;
    glad_debug_vkDestroyDebugUtilsMessengerEXT = glad_vkDestroyDebugUtilsMessengerEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkDestroyDeferredOperationKHR = glad_vkDestroyDeferredOperationKHR;
#endif
    glad_debug_vkDestroyDescriptorPool = glad_vkDestroyDescriptorPool;
    glad_debug_vkDestroyDescriptorSetLayout = glad_vkDestroyDescriptorSetLayout;
    glad_debug_vkDestroyDescriptorUpdateTemplate = glad_vkDestroyDescriptorUpdateTemplate;
    glad_debug_vkDestroyDescriptorUpdateTemplateKHR = glad_vkDestroyDescriptorUpdateTemplateKHR;
    glad_debug_vkDestroyDevice = glad_vkDestroyDevice;
    glad_debug_vkDestroyEvent = glad_vkDestroyEvent;
    glad_debug_vkDestroyFence = glad_vkDestroyFence;
    glad_debug_vkDestroyFramebuffer = glad_vkDestroyFramebuffer;
    glad_debug_vkDestroyImage = glad_vkDestroyImage;
    glad_debug_vkDestroyImageView = glad_vkDestroyImageView;
    glad_debug_vkDestroyInstance = glad_vkDestroyInstance;
    glad_debug_vkDestroyPipeline = glad_vkDestroyPipeline;
    glad_debug_vkDestroyPipelineCache = glad_vkDestroyPipelineCache;
    glad_debug_vkDestroyPipelineLayout = glad_vkDestroyPipelineLayout;
    glad_debug_vkDestroyPrivateDataSlotEXT = glad_vkDestroyPrivateDataSlotEXT;
    glad_debug_vkDestroyQueryPool = glad_vkDestroyQueryPool;
    glad_debug_vkDestroyRenderPass = glad_vkDestroyRenderPass;
    glad_debug_vkDestroySampler = glad_vkDestroySampler;
    glad_debug_vkDestroySamplerYcbcrConversion = glad_vkDestroySamplerYcbcrConversion;
    glad_debug_vkDestroySamplerYcbcrConversionKHR = glad_vkDestroySamplerYcbcrConversionKHR;
    glad_debug_vkDestroySemaphore = glad_vkDestroySemaphore;
    glad_debug_vkDestroyShaderModule = glad_vkDestroyShaderModule;
    glad_debug_vkDestroySurfaceKHR = glad_vkDestroySurfaceKHR;
    glad_debug_vkDestroySwapchainKHR = glad_vkDestroySwapchainKHR;
    glad_debug_vkDestroyValidationCacheEXT = glad_vkDestroyValidationCacheEXT;
    glad_debug_vkDeviceWaitIdle = glad_vkDeviceWaitIdle;
    glad_debug_vkDisplayPowerControlEXT = glad_vkDisplayPowerControlEXT;
    glad_debug_vkEndCommandBuffer = glad_vkEndCommandBuffer;
    glad_debug_vkEnumerateDeviceExtensionProperties = glad_vkEnumerateDeviceExtensionProperties;
    glad_debug_vkEnumerateDeviceLayerProperties = glad_vkEnumerateDeviceLayerProperties;
    glad_debug_vkEnumerateInstanceExtensionProperties = glad_vkEnumerateInstanceExtensionProperties;
    glad_debug_vkEnumerateInstanceLayerProperties = glad_vkEnumerateInstanceLayerProperties;
    glad_debug_vkEnumerateInstanceVersion = glad_vkEnumerateInstanceVersion;
    glad_debug_vkEnumeratePhysicalDeviceGroups = glad_vkEnumeratePhysicalDeviceGroups;
    glad_debug_vkEnumeratePhysicalDeviceGroupsKHR = glad_vkEnumeratePhysicalDeviceGroupsKHR;
    glad_debug_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = glad_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
    glad_debug_vkEnumeratePhysicalDevices = glad_vkEnumeratePhysicalDevices;
    glad_debug_vkFlushMappedMemoryRanges = glad_vkFlushMappedMemoryRanges;
    glad_debug_vkFreeCommandBuffers = glad_vkFreeCommandBuffers;
    glad_debug_vkFreeDescriptorSets = glad_vkFreeDescriptorSets;
    glad_debug_vkFreeMemory = glad_vkFreeMemory;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetAccelerationStructureDeviceAddressKHR = glad_vkGetAccelerationStructureDeviceAddressKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetAccelerationStructureMemoryRequirementsKHR = glad_vkGetAccelerationStructureMemoryRequirementsKHR;
#endif
    glad_debug_vkGetBufferDeviceAddress = glad_vkGetBufferDeviceAddress;
    glad_debug_vkGetBufferDeviceAddressEXT = glad_vkGetBufferDeviceAddressEXT;
    glad_debug_vkGetBufferDeviceAddressKHR = glad_vkGetBufferDeviceAddressKHR;
    glad_debug_vkGetBufferMemoryRequirements = glad_vkGetBufferMemoryRequirements;
    glad_debug_vkGetBufferMemoryRequirements2 = glad_vkGetBufferMemoryRequirements2;
    glad_debug_vkGetBufferMemoryRequirements2KHR = glad_vkGetBufferMemoryRequirements2KHR;
    glad_debug_vkGetBufferOpaqueCaptureAddress = glad_vkGetBufferOpaqueCaptureAddress;
    glad_debug_vkGetBufferOpaqueCaptureAddressKHR = glad_vkGetBufferOpaqueCaptureAddressKHR;
    glad_debug_vkGetCalibratedTimestampsEXT = glad_vkGetCalibratedTimestampsEXT;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetDeferredOperationMaxConcurrencyKHR = glad_vkGetDeferredOperationMaxConcurrencyKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetDeferredOperationResultKHR = glad_vkGetDeferredOperationResultKHR;
#endif
    glad_debug_vkGetDescriptorSetLayoutSupport = glad_vkGetDescriptorSetLayoutSupport;
    glad_debug_vkGetDescriptorSetLayoutSupportKHR = glad_vkGetDescriptorSetLayoutSupportKHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetDeviceAccelerationStructureCompatibilityKHR = glad_vkGetDeviceAccelerationStructureCompatibilityKHR;
#endif
    glad_debug_vkGetDeviceGroupPeerMemoryFeatures = glad_vkGetDeviceGroupPeerMemoryFeatures;
    glad_debug_vkGetDeviceGroupPeerMemoryFeaturesKHR = glad_vkGetDeviceGroupPeerMemoryFeaturesKHR;
    glad_debug_vkGetDeviceGroupPresentCapabilitiesKHR = glad_vkGetDeviceGroupPresentCapabilitiesKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetDeviceGroupSurfacePresentModes2EXT = glad_vkGetDeviceGroupSurfacePresentModes2EXT;
#endif
    glad_debug_vkGetDeviceGroupSurfacePresentModesKHR = glad_vkGetDeviceGroupSurfacePresentModesKHR;
    glad_debug_vkGetDeviceMemoryCommitment = glad_vkGetDeviceMemoryCommitment;
    glad_debug_vkGetDeviceMemoryOpaqueCaptureAddress = glad_vkGetDeviceMemoryOpaqueCaptureAddress;
    glad_debug_vkGetDeviceMemoryOpaqueCaptureAddressKHR = glad_vkGetDeviceMemoryOpaqueCaptureAddressKHR;
    glad_debug_vkGetDeviceProcAddr = glad_vkGetDeviceProcAddr;
    glad_debug_vkGetDeviceQueue = glad_vkGetDeviceQueue;
    glad_debug_vkGetDeviceQueue2 = glad_vkGetDeviceQueue2;
    glad_debug_vkGetDisplayModeProperties2KHR = glad_vkGetDisplayModeProperties2KHR;
    glad_debug_vkGetDisplayModePropertiesKHR = glad_vkGetDisplayModePropertiesKHR;
    glad_debug_vkGetDisplayPlaneCapabilities2KHR = glad_vkGetDisplayPlaneCapabilities2KHR;
    glad_debug_vkGetDisplayPlaneCapabilitiesKHR = glad_vkGetDisplayPlaneCapabilitiesKHR;
    glad_debug_vkGetDisplayPlaneSupportedDisplaysKHR = glad_vkGetDisplayPlaneSupportedDisplaysKHR;
    glad_debug_vkGetEventStatus = glad_vkGetEventStatus;
    glad_debug_vkGetFenceFdKHR = glad_vkGetFenceFdKHR;
    glad_debug_vkGetFenceStatus = glad_vkGetFenceStatus;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetFenceWin32HandleKHR = glad_vkGetFenceWin32HandleKHR;
#endif
    glad_debug_vkGetImageDrmFormatModifierPropertiesEXT = glad_vkGetImageDrmFormatModifierPropertiesEXT;
    glad_debug_vkGetImageMemoryRequirements = glad_vkGetImageMemoryRequirements;
    glad_debug_vkGetImageMemoryRequirements2 = glad_vkGetImageMemoryRequirements2;
    glad_debug_vkGetImageMemoryRequirements2KHR = glad_vkGetImageMemoryRequirements2KHR;
    glad_debug_vkGetImageSparseMemoryRequirements = glad_vkGetImageSparseMemoryRequirements;
    glad_debug_vkGetImageSparseMemoryRequirements2 = glad_vkGetImageSparseMemoryRequirements2;
    glad_debug_vkGetImageSparseMemoryRequirements2KHR = glad_vkGetImageSparseMemoryRequirements2KHR;
    glad_debug_vkGetImageSubresourceLayout = glad_vkGetImageSubresourceLayout;
    glad_debug_vkGetInstanceProcAddr = glad_vkGetInstanceProcAddr;
    glad_debug_vkGetMemoryFdKHR = glad_vkGetMemoryFdKHR;
    glad_debug_vkGetMemoryFdPropertiesKHR = glad_vkGetMemoryFdPropertiesKHR;
    glad_debug_vkGetMemoryHostPointerPropertiesEXT = glad_vkGetMemoryHostPointerPropertiesEXT;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetMemoryWin32HandleKHR = glad_vkGetMemoryWin32HandleKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetMemoryWin32HandlePropertiesKHR = glad_vkGetMemoryWin32HandlePropertiesKHR;
#endif
    glad_debug_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = glad_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    glad_debug_vkGetPhysicalDeviceDirectFBPresentationSupportEXT = glad_vkGetPhysicalDeviceDirectFBPresentationSupportEXT;
#endif
    glad_debug_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = glad_vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
    glad_debug_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = glad_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
    glad_debug_vkGetPhysicalDeviceDisplayProperties2KHR = glad_vkGetPhysicalDeviceDisplayProperties2KHR;
    glad_debug_vkGetPhysicalDeviceDisplayPropertiesKHR = glad_vkGetPhysicalDeviceDisplayPropertiesKHR;
    glad_debug_vkGetPhysicalDeviceExternalBufferProperties = glad_vkGetPhysicalDeviceExternalBufferProperties;
    glad_debug_vkGetPhysicalDeviceExternalBufferPropertiesKHR = glad_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
    glad_debug_vkGetPhysicalDeviceExternalFenceProperties = glad_vkGetPhysicalDeviceExternalFenceProperties;
    glad_debug_vkGetPhysicalDeviceExternalFencePropertiesKHR = glad_vkGetPhysicalDeviceExternalFencePropertiesKHR;
    glad_debug_vkGetPhysicalDeviceExternalSemaphoreProperties = glad_vkGetPhysicalDeviceExternalSemaphoreProperties;
    glad_debug_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = glad_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
    glad_debug_vkGetPhysicalDeviceFeatures = glad_vkGetPhysicalDeviceFeatures;
    glad_debug_vkGetPhysicalDeviceFeatures2 = glad_vkGetPhysicalDeviceFeatures2;
    glad_debug_vkGetPhysicalDeviceFeatures2KHR = glad_vkGetPhysicalDeviceFeatures2KHR;
    glad_debug_vkGetPhysicalDeviceFormatProperties = glad_vkGetPhysicalDeviceFormatProperties;
    glad_debug_vkGetPhysicalDeviceFormatProperties2 = glad_vkGetPhysicalDeviceFormatProperties2;
    glad_debug_vkGetPhysicalDeviceFormatProperties2KHR = glad_vkGetPhysicalDeviceFormatProperties2KHR;
    glad_debug_vkGetPhysicalDeviceImageFormatProperties = glad_vkGetPhysicalDeviceImageFormatProperties;
    glad_debug_vkGetPhysicalDeviceImageFormatProperties2 = glad_vkGetPhysicalDeviceImageFormatProperties2;
    glad_debug_vkGetPhysicalDeviceImageFormatProperties2KHR = glad_vkGetPhysicalDeviceImageFormatProperties2KHR;
    glad_debug_vkGetPhysicalDeviceMemoryProperties = glad_vkGetPhysicalDeviceMemoryProperties;
    glad_debug_vkGetPhysicalDeviceMemoryProperties2 = glad_vkGetPhysicalDeviceMemoryProperties2;
    glad_debug_vkGetPhysicalDeviceMemoryProperties2KHR = glad_vkGetPhysicalDeviceMemoryProperties2KHR;
    glad_debug_vkGetPhysicalDeviceMultisamplePropertiesEXT = glad_vkGetPhysicalDeviceMultisamplePropertiesEXT;
    glad_debug_vkGetPhysicalDevicePresentRectanglesKHR = glad_vkGetPhysicalDevicePresentRectanglesKHR;
    glad_debug_vkGetPhysicalDeviceProperties = glad_vkGetPhysicalDeviceProperties;
    glad_debug_vkGetPhysicalDeviceProperties2 = glad_vkGetPhysicalDeviceProperties2;
    glad_debug_vkGetPhysicalDeviceProperties2KHR = glad_vkGetPhysicalDeviceProperties2KHR;
    glad_debug_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = glad_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
    glad_debug_vkGetPhysicalDeviceQueueFamilyProperties = glad_vkGetPhysicalDeviceQueueFamilyProperties;
    glad_debug_vkGetPhysicalDeviceQueueFamilyProperties2 = glad_vkGetPhysicalDeviceQueueFamilyProperties2;
    glad_debug_vkGetPhysicalDeviceQueueFamilyProperties2KHR = glad_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
    glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties = glad_vkGetPhysicalDeviceSparseImageFormatProperties;
    glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties2 = glad_vkGetPhysicalDeviceSparseImageFormatProperties2;
    glad_debug_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = glad_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
    glad_debug_vkGetPhysicalDeviceSurfaceCapabilities2EXT = glad_vkGetPhysicalDeviceSurfaceCapabilities2EXT;
    glad_debug_vkGetPhysicalDeviceSurfaceCapabilities2KHR = glad_vkGetPhysicalDeviceSurfaceCapabilities2KHR;
    glad_debug_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = glad_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
    glad_debug_vkGetPhysicalDeviceSurfaceFormats2KHR = glad_vkGetPhysicalDeviceSurfaceFormats2KHR;
    glad_debug_vkGetPhysicalDeviceSurfaceFormatsKHR = glad_vkGetPhysicalDeviceSurfaceFormatsKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetPhysicalDeviceSurfacePresentModes2EXT = glad_vkGetPhysicalDeviceSurfacePresentModes2EXT;
#endif
    glad_debug_vkGetPhysicalDeviceSurfacePresentModesKHR = glad_vkGetPhysicalDeviceSurfacePresentModesKHR;
    glad_debug_vkGetPhysicalDeviceSurfaceSupportKHR = glad_vkGetPhysicalDeviceSurfaceSupportKHR;
    glad_debug_vkGetPhysicalDeviceToolPropertiesEXT = glad_vkGetPhysicalDeviceToolPropertiesEXT;
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    glad_debug_vkGetPhysicalDeviceWaylandPresentationSupportKHR = glad_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetPhysicalDeviceWin32PresentationSupportKHR = glad_vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    glad_debug_vkGetPhysicalDeviceXcbPresentationSupportKHR = glad_vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    glad_debug_vkGetPhysicalDeviceXlibPresentationSupportKHR = glad_vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif
    glad_debug_vkGetPipelineCacheData = glad_vkGetPipelineCacheData;
    glad_debug_vkGetPipelineExecutableInternalRepresentationsKHR = glad_vkGetPipelineExecutableInternalRepresentationsKHR;
    glad_debug_vkGetPipelineExecutablePropertiesKHR = glad_vkGetPipelineExecutablePropertiesKHR;
    glad_debug_vkGetPipelineExecutableStatisticsKHR = glad_vkGetPipelineExecutableStatisticsKHR;
    glad_debug_vkGetPrivateDataEXT = glad_vkGetPrivateDataEXT;
    glad_debug_vkGetQueryPoolResults = glad_vkGetQueryPoolResults;
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    glad_debug_vkGetRandROutputDisplayEXT = glad_vkGetRandROutputDisplayEXT;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR = glad_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
#endif
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkGetRayTracingShaderGroupHandlesKHR = glad_vkGetRayTracingShaderGroupHandlesKHR;
#endif
    glad_debug_vkGetRenderAreaGranularity = glad_vkGetRenderAreaGranularity;
    glad_debug_vkGetSemaphoreCounterValue = glad_vkGetSemaphoreCounterValue;
    glad_debug_vkGetSemaphoreCounterValueKHR = glad_vkGetSemaphoreCounterValueKHR;
    glad_debug_vkGetSemaphoreFdKHR = glad_vkGetSemaphoreFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkGetSemaphoreWin32HandleKHR = glad_vkGetSemaphoreWin32HandleKHR;
#endif
    glad_debug_vkGetSwapchainCounterEXT = glad_vkGetSwapchainCounterEXT;
    glad_debug_vkGetSwapchainImagesKHR = glad_vkGetSwapchainImagesKHR;
    glad_debug_vkGetSwapchainStatusKHR = glad_vkGetSwapchainStatusKHR;
    glad_debug_vkGetValidationCacheDataEXT = glad_vkGetValidationCacheDataEXT;
    glad_debug_vkImportFenceFdKHR = glad_vkImportFenceFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkImportFenceWin32HandleKHR = glad_vkImportFenceWin32HandleKHR;
#endif
    glad_debug_vkImportSemaphoreFdKHR = glad_vkImportSemaphoreFdKHR;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkImportSemaphoreWin32HandleKHR = glad_vkImportSemaphoreWin32HandleKHR;
#endif
    glad_debug_vkInvalidateMappedMemoryRanges = glad_vkInvalidateMappedMemoryRanges;
    glad_debug_vkMapMemory = glad_vkMapMemory;
    glad_debug_vkMergePipelineCaches = glad_vkMergePipelineCaches;
    glad_debug_vkMergeValidationCachesEXT = glad_vkMergeValidationCachesEXT;
    glad_debug_vkQueueBeginDebugUtilsLabelEXT = glad_vkQueueBeginDebugUtilsLabelEXT;
    glad_debug_vkQueueBindSparse = glad_vkQueueBindSparse;
    glad_debug_vkQueueEndDebugUtilsLabelEXT = glad_vkQueueEndDebugUtilsLabelEXT;
    glad_debug_vkQueueInsertDebugUtilsLabelEXT = glad_vkQueueInsertDebugUtilsLabelEXT;
    glad_debug_vkQueuePresentKHR = glad_vkQueuePresentKHR;
    glad_debug_vkQueueSubmit = glad_vkQueueSubmit;
    glad_debug_vkQueueWaitIdle = glad_vkQueueWaitIdle;
    glad_debug_vkRegisterDeviceEventEXT = glad_vkRegisterDeviceEventEXT;
    glad_debug_vkRegisterDisplayEventEXT = glad_vkRegisterDisplayEventEXT;
    glad_debug_vkReleaseDisplayEXT = glad_vkReleaseDisplayEXT;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    glad_debug_vkReleaseFullScreenExclusiveModeEXT = glad_vkReleaseFullScreenExclusiveModeEXT;
#endif
    glad_debug_vkReleaseProfilingLockKHR = glad_vkReleaseProfilingLockKHR;
    glad_debug_vkResetCommandBuffer = glad_vkResetCommandBuffer;
    glad_debug_vkResetCommandPool = glad_vkResetCommandPool;
    glad_debug_vkResetDescriptorPool = glad_vkResetDescriptorPool;
    glad_debug_vkResetEvent = glad_vkResetEvent;
    glad_debug_vkResetFences = glad_vkResetFences;
    glad_debug_vkResetQueryPool = glad_vkResetQueryPool;
    glad_debug_vkResetQueryPoolEXT = glad_vkResetQueryPoolEXT;
    glad_debug_vkSetDebugUtilsObjectNameEXT = glad_vkSetDebugUtilsObjectNameEXT;
    glad_debug_vkSetDebugUtilsObjectTagEXT = glad_vkSetDebugUtilsObjectTagEXT;
    glad_debug_vkSetEvent = glad_vkSetEvent;
    glad_debug_vkSetHdrMetadataEXT = glad_vkSetHdrMetadataEXT;
    glad_debug_vkSetPrivateDataEXT = glad_vkSetPrivateDataEXT;
    glad_debug_vkSignalSemaphore = glad_vkSignalSemaphore;
    glad_debug_vkSignalSemaphoreKHR = glad_vkSignalSemaphoreKHR;
    glad_debug_vkSubmitDebugUtilsMessageEXT = glad_vkSubmitDebugUtilsMessageEXT;
    glad_debug_vkTrimCommandPool = glad_vkTrimCommandPool;
    glad_debug_vkTrimCommandPoolKHR = glad_vkTrimCommandPoolKHR;
    glad_debug_vkUnmapMemory = glad_vkUnmapMemory;
    glad_debug_vkUpdateDescriptorSetWithTemplate = glad_vkUpdateDescriptorSetWithTemplate;
    glad_debug_vkUpdateDescriptorSetWithTemplateKHR = glad_vkUpdateDescriptorSetWithTemplateKHR;
    glad_debug_vkUpdateDescriptorSets = glad_vkUpdateDescriptorSets;
    glad_debug_vkWaitForFences = glad_vkWaitForFences;
    glad_debug_vkWaitSemaphores = glad_vkWaitSemaphores;
    glad_debug_vkWaitSemaphoresKHR = glad_vkWaitSemaphoresKHR;
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    glad_debug_vkWriteAccelerationStructuresPropertiesKHR = glad_vkWriteAccelerationStructuresPropertiesKHR;
#endif
}


#ifdef __cplusplus
}
#endif
