#include "stdio.h"
#include "stdint.h"
#include "atomic"

class RegisterBit
{
    volatile uint32_t *base;
    uint8_t bitPos;

public:
    RegisterBit(uint32_t base, uint8_t bit)
        : base(reinterpret_cast<volatile uint32_t *>(base)), bitPos(bit)
    {
    }

    void set()
    {
        *base |= (1 << bitPos);
    }

    void clear()
    {
        *base &= ~(1 << bitPos);
    }
    bool read() const
    {
        return (*base & ~(1 << bitPos)) >> bitPos;
    }

    void operator=(bool val)
    {
        if (val)
            set();
        else
            clear();
    }

    operator bool() const
    {
        return read();
    }
};

class TS_Counter
{
    std::atomic<uint32_t> count;

public:
    TS_Counter() : count(0)
    {
    }
    void increment()
    {
        count.fetch_add(1);
    }

    void decrement()
    {
        count.fetch_sub(1);
    }

    uint32_t get()
    {
        return count;
    }
};

int main()
{
    constexpr uint32_t BASE = 0x454545;
    RegisterBit Status(BASE, 5);
    Status.set();
    Status.read();
    Status.clear();

    auto IsSet = [Status]() mutable -> bool
    {
        bool res = Status.read();
        return res;
    };

    if (IsSet())
    {
        /* code */
        printf("warn:Status Bit is Set");
    }
}