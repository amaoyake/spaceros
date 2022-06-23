#include <array>
#include <string>
#include <cassert>
#include <memory_resource>


const unsigned int SMALL_MEM  = 128;
const unsigned int MEDIUM_MEM = 4096;
const unsigned int LARGE_MEM  = 32768;

template <size_t N>
using MEMORY_BUFFER = std::array<std::uint8_t, N>;

template <size_t N>
using PREALLOCATE = std::array<std::uint8_t, N>;


class ROSAllocator : public std::pmr::memory_resource
{
 public:
    ROSAllocator(std::string name, unsigned char* buffer, size_t buffer_size) : m_name(std::move(name)),
    monotonic(buffer, buffer_size, std::pmr::null_memory_resource()),
    memory_pool(&monotonic)
    {

    }

    private:
    std::string m_name;
    std::pmr::memory_resource* m_upstream;

    // Declare memory in the class stack
    std::pmr::monotonic_buffer_resource monotonic;
    std::pmr::unsynchronized_pool_resource memory_pool;

    void* do_allocate(std::size_t bytes, std::size_t alignment) 
    {
        auto result = memory_pool.allocate(bytes, alignment);
        return result;
    }
  
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment)
    {
        memory_pool.deallocate(p, bytes, alignment);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override 
    {
        return this == &other;
    }
};


