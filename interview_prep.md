# Interview Preparation — Sachin Kumar
**Phase 1 Target (Now → 6 months):** Qualcomm, NXP, TI, Renesas, KPIT, Continental | ₹35–55 LPA
**Phase 2 Target (6–18 months):** NVIDIA DRIVE, Aptiv ADAS, Bosch AI | ₹60–120 LPA
**Updated:** April 2026

---

## Target Companies — Phase 1

| Company | Focus Area | Why You Fit |
|---|---|---|
| **Qualcomm India** | Snapdragon BSP, modem firmware, automotive (Ride platform) | C depth, RTOS, ARM, ISO 26262 |
| **NXP India** | S32 automotive, i.MX Linux BSP, AUTOSAR | RH850/S32K experience, CAN, MCAL |
| **Texas Instruments India** | Jacinto/DRA automotive, Sitara Linux BSP | TI MCU background, RTOS |
| **Renesas India** | R-Car, RH850 AUTOSAR | Direct RH850 experience at HMCMM |
| **KPIT Technologies** | AUTOSAR, SDV stack, Zephyr | Automotive domain, CAN, SDV project |
| **Continental India** | AUTOSAR Adaptive, Linux BSP, Zephyr | BSW architecture, ASPICE |
| **Harman India** | Infotainment, embedded Linux, IVI | Linux hobby project, BLE, MQTT |
| **Bosch India** | AUTOSAR, EV/thermal, Linux | Already worked here — re-apply at higher band |

## Qualcomm Interview Pattern (what they actually ask)
1. **C fundamentals** — very deep, expect trick questions on pointers/memory
2. **OS concepts** — process vs thread, virtual memory, scheduling, IPC (Qualcomm tests this hard)
3. **Computer architecture** — cache hierarchy, pipeline, branch prediction, ARM specifics
4. **RTOS** — scheduling, priority inversion, synchronization primitives
5. **Embedded specifics** — ISR, DMA, bootloader, protocols
6. **DSA round** — yes, Qualcomm asks linked list, sorting, trees (1 dedicated round)
7. **Linux drivers** — for BSP roles, kernel module and driver questions
8. **System design** — BSP architecture, OTA, multi-core bring-up

---

## Legend
- ✅ Strong (can answer confidently from real work)
- 🔄 Needs revision (know the concept, need to articulate clearly)
- ⬜ Gap (must study from scratch)
- ❌ Skip for now (low ROI for target roles)

---

## PRIORITY 1 — Asked in almost every BSW interview

### A. Embedded C Deep Dive ✅→🔄
Topics to prepare:
- [ ] `volatile` keyword — when to use, why compiler optimization breaks ISRs without it
- [ ] `const` correctness — `const int*` vs `int* const` vs `const int* const`
- [ ] `static` in all contexts (local, global, function)
- [ ] `restrict` keyword — what it means for compiler
- [ ] Bit manipulation — set, clear, toggle, check a bit without using bit-fields
- [ ] Bit-fields — layout, endianness issues, why not for protocol parsing
- [ ] Memory segments — text, data, BSS, heap, stack — what goes where
- [ ] `volatile` + `const` together — hardware register pattern
- [ ] Function pointers — syntax, use in driver dispatch tables
- [ ] Void pointers — casting rules, alignment issues
- [ ] `extern`, `inline`, `register` — when and why
- [ ] Endianness — big vs little, how to detect, how to swap
- [ ] Struct padding and alignment — how to control with `__attribute__((packed))`
- [ ] Stack vs heap — when to use each in embedded, why heap is dangerous
- [ ] Memory-mapped I/O — why `volatile` is mandatory
- [ ] Linker script basics — SECTIONS, VMA vs LMA, `.text`, `.data` copy at startup
- [ ] `memcpy` vs `memmove` — when each is safe

### B. ISR (Interrupt Service Routine) Design ✅
- [ ] ISR rules — no blocking, no malloc, no printf
- [ ] Sharing data between ISR and main — volatile + atomic or critical section
- [ ] Nested interrupts — how to enable/disable, risks
- [ ] Interrupt latency vs jitter — how to minimize
- [ ] Debouncing in ISR
- [ ] DMA vs interrupt-driven transfers — trade-offs
- [ ] ISR in RTOS context — ISR-safe API calls (FreeRTOS: `FromISR` variants)

### C. RTOS / FreeRTOS ✅
- [ ] Preemptive vs cooperative scheduling
- [ ] Priority inversion — what it is, real example (Mars Pathfinder bug)
- [ ] Priority inheritance — how FreeRTOS mutex solves inversion
- [ ] Deadlock — conditions (CHON), detection, prevention
- [ ] Semaphore vs Mutex — key differences (ownership, recursion, ISR use)
- [ ] Binary semaphore vs counting semaphore
- [ ] Message queue vs mailbox vs event flags
- [ ] Stack overflow detection in FreeRTOS (watermark, `uxTaskGetStackHighWaterMark`)
- [ ] Tick rate — impact on latency, power, timer resolution
- [ ] Context switch — what registers are saved, how long it takes
- [ ] Critical section — `taskENTER_CRITICAL` vs `taskDISABLE_INTERRUPTS`
- [ ] `vTaskDelay` vs `vTaskDelayUntil` — periodic task pattern
- [ ] Idle task and hooks — power saving
- [ ] Task notification vs semaphore — when to use which

### D. Automotive Protocols ✅
**CAN (strong — deep dive)**
- [ ] Frame format — SOF, arbitration ID, RTR, IDE, DLC, data, CRC, ACK, EOF
- [ ] Bit stuffing — rule, why needed
- [ ] Arbitration — how multi-master works, dominant vs recessive
- [ ] Error frames — 6 types of errors (bit, stuff, form, ACK, CRC, overload)
- [ ] Error counters (TEC, REC) and bus-off state
- [ ] CAN-FD — BRS (bit rate switch), ESI, max 64 bytes, ISO vs non-ISO
- [ ] Extended vs standard ID — 11-bit vs 29-bit

**LIN ✅**
- [ ] Master/slave architecture — only master initiates
- [ ] Frame structure — break, sync, PID, data, checksum
- [ ] Schedule table — unconditional, event-triggered, sporadic frames
- [ ] LIN 2.x vs 1.x checksum difference

**UDS — ISO 14229 ✅**
- [ ] Service ID table (must memorize key ones):
  - 0x10 — DiagnosticSessionControl (default, programming, extended)
  - 0x11 — ECUReset
  - 0x14 — ClearDiagnosticInformation
  - 0x19 — ReadDTCInformation
  - 0x22 — ReadDataByIdentifier
  - 0x27 — SecurityAccess (seed/key)
  - 0x28 — CommunicationControl
  - 0x2E — WriteDataByIdentifier
  - 0x31 — RoutineControl (start, stop, requestResult)
  - 0x34 — RequestDownload
  - 0x36 — TransferData
  - 0x37 — RequestTransferExit
  - 0x3E — TesterPresent
- [ ] Negative response codes (0x7F + SID + NRC)
- [ ] Addressing modes — physical, functional, broadcast

**XCP ✅**
- [ ] DAQ (data acquisition) vs STIM (stimulation)
- [ ] XCP on CAN frame structure
- [ ] Measurement and calibration workflow with CANape

---

## PRIORITY 2 — Asked at senior/lead level

### E. Bootloader Design ✅
- [ ] Boot sequence — ROM bootloader → app bootloader → application
- [ ] Memory map for dual-bank / A/B update scheme
- [ ] UDS bootloader flow — session change → security access → erase → download → verify → reset
- [ ] Flash programming — page erase, word write, verify
- [ ] CRC validation of application image
- [ ] Fallback / golden image strategy
- [ ] Secure boot concepts — code signing, hash verification, key storage
- [ ] Watchdog during flash — why dangerous, how to handle (e.g., kick before each page)
- [ ] XCP bootloader vs UDS bootloader — when to use each

### F. AUTOSAR Classic 🔄
- [ ] Layered architecture — MCAL / ECU Abstraction / Services / RTE / SWC
- [ ] MCAL modules: ADC, PWM, GPT, ICU, PORT, DIO, SPI, CAN, LIN, WDG
- [ ] SWC types — application, sensor/actuator, complex driver
- [ ] Port interfaces — sender/receiver vs client/server
- [ ] RTE — what it generates, runnable → task mapping
- [ ] OS (OSEK): tasks (basic vs extended), alarms, events, resources (priority ceiling)
- [ ] DEM — event reporting, DTC management
- [ ] DCM — diagnostic request handling, DSP, DSD, DCM-DEM interface
- [ ] NVM, FEE — NV block management
- [ ] PDU Router, COM, CanIf, CanSM — ComStack flow
- [ ] DaVinci Configurator — what you configured (MCAL modules, OS, ComStack)

### G. C++ for Embedded 🔄
- [ ] RAII — resource acquisition is initialization, destructor guarantee
- [ ] Smart pointers — `unique_ptr` (no copy), `shared_ptr` (ref count), `weak_ptr` (break cycles)
- [ ] Move semantics — `std::move`, rvalue reference, why it avoids copies
- [ ] `const` methods and `mutable`
- [ ] Virtual functions — vtable, vptr, cost in embedded (heap, indirect call)
- [ ] Pure virtual and abstract class
- [ ] Diamond problem — virtual inheritance
- [ ] CRTP — compile-time polymorphism, zero overhead
- [ ] Templates — function template, class template, template specialization
- [ ] `constexpr` and `consteval` — compile-time computation
- [ ] Lambda — capture by value vs reference, in ISR (never capture by reference to stack)
- [ ] `std::atomic` — why needed, `memory_order`
- [ ] `std::mutex`, `std::lock_guard`, `std::unique_lock`
- [ ] Design patterns:
  - Singleton — thread-safe implementation (Meyers singleton)
  - Observer — event/callback pattern
  - Factory — object creation abstraction
  - Strategy — swappable algorithm
  - State machine — enum-based vs table-based
- [ ] Why exceptions are disabled in embedded (`-fno-exceptions`)
- [ ] Why RTTI is disabled (`-fno-rtti`)
- [ ] `static_assert` — compile-time checks
- [ ] `override` and `final` keywords
- [ ] Operator overloading — assignment, comparison, stream (when useful in embedded)

---

## PRIORITY 3 — For Linux/SDV roles (study in parallel)

### H. Linux Kernel Basics ⬜
- [ ] Linux boot: BIOS/UEFI → U-Boot → kernel → init/systemd
- [ ] Kernel module: `module_init`, `module_exit`, `MODULE_LICENSE`
- [ ] `insmod`, `rmmod`, `modprobe`, `lsmod`
- [ ] `printk` and log levels (KERN_ERR, KERN_INFO, etc.)
- [ ] Character driver: `cdev_init`, `cdev_add`, `file_operations` (open, read, write, ioctl, release)
- [ ] Major and minor numbers — `alloc_chrdev_region`
- [ ] `copy_to_user`, `copy_from_user` — why needed
- [ ] Platform driver: `platform_driver_register`, `probe`, `remove`, `platform_device`
- [ ] Device tree: node, compatible string, `of_match_table`
- [ ] IRQ in kernel: `request_irq`, `free_irq`, `IRQ_HANDLED`
- [ ] Threaded IRQ: `request_threaded_irq` — top half vs bottom half
- [ ] Work queues: deferred work from interrupt context
- [ ] Tasklets — softirq context, no sleep
- [ ] Memory allocation: `kmalloc` (physically contiguous) vs `vmalloc` (virtually contiguous)
- [ ] `ioremap` — map hardware registers to virtual address
- [ ] Kernel synchronization: spinlock (interrupt context), mutex (process context), semaphore
- [ ] Sysfs — `sysfs_create_file`, show/store callbacks
- [ ] procfs — `/proc` entries
- [ ] DMA in Linux: `dma_alloc_coherent`, `dma_map_single`

### I. Yocto / Embedded Linux Build ⬜
- [ ] Yocto layers: `meta-*`, `BBLAYERS`
- [ ] Recipe structure: `.bb` file, `SRC_URI`, `do_compile`, `do_install`
- [ ] `bitbake <recipe>`, `bitbake -c devshell`
- [ ] `IMAGE_INSTALL`, `MACHINE`, `DISTRO`
- [ ] Layer priority and overrides
- [ ] `.bbappend` — how to extend an existing recipe
- [ ] SDK generation: `bitbake -c populate_sdk`
- [ ] Common packages: `busybox`, `dropbear`, `bluez5`, `can-utils`, `mosquitto`
- [ ] U-Boot recipe and kernel recipe customization

### J. Zephyr RTOS ⬜
- [ ] West workspace — `west init`, `west update`, `west build`, `west flash`
- [ ] Kconfig — `CONFIG_*`, `prj.conf`
- [ ] Device tree in Zephyr — `.dts`, `.overlay`, `chosen`, `aliases`
- [ ] Zephyr thread API — `k_thread_create`, `K_THREAD_DEFINE`, priority, stack
- [ ] Zephyr synchronization — `k_sem`, `k_mutex`, `k_msgq`, `k_fifo`
- [ ] Zephyr work queue — `k_work`, `k_work_submit`
- [ ] Zephyr driver model — `DEVICE_DT_DEFINE`, device API structs
- [ ] CAN in Zephyr — `can_send`, `can_add_rx_filter`, `zcan_frame`
- [ ] Logging — `LOG_MODULE_REGISTER`, `LOG_INF`, `LOG_ERR`
- [ ] Shell subsystem
- [ ] Contribution workflow — west manifest, PR, CI compliance check

---

## PRIORITY 4 — System Design (senior/staff level)

### K. System Design for BSW Roles 🔄
- [ ] Design a UDS bootloader from scratch — memory map, state machine, security
- [ ] Design a CAN communication stack — buffering, error handling, bus-off recovery
- [ ] Design an OTA update system — dual bank, integrity check, rollback
- [ ] Design a BSP for a new MCU — bring-up sequence, clock, memory, peripherals
- [ ] Heterogeneous system (MCU + MPU) — IPC mechanisms (SPI, shared memory, RPMsg)
- [ ] Secure boot architecture — root of trust, chain of trust, key revocation
- [ ] ASIL decomposition — splitting ASIL-D into two ASIL-B components
- [ ] Watchdog architecture — independent, windowed, question-answer

---

## PRIORITY 5 — Behavioral (prepare before first mock)

- [ ] Why did you leave EMOTORAD? (was it voluntary/company closed/restructured?)
- [ ] What did you do during the 1-year gap? (frame: intentional upskilling — Linux IoT project, SDV project, C++ modernization)
- [ ] Tell me your most challenging technical problem and how you solved it
- [ ] How do you handle disagreement with a hardware engineer?
- [ ] How did you manage a team of 5 engineers at EMOTORAD?
- [ ] Tell me about a time you delivered under a tight deadline
- [ ] Why Qualcomm/NXP/this company specifically?

---

## Study Order (Qualcomm / Phase 1 Target)

```
Week 1:     Embedded C deep dive (volatile, pointers, memory layout, ISR)
Week 2:     RTOS concepts (priority inversion, deadlock, sync primitives)
Week 3:     Automotive protocols (CAN frames, UDS services, LIN)
Week 4:     C++ for embedded (RAII, smart pointers, virtual, templates)
Week 5:     Bootloader + AUTOSAR revision
Week 6:     OS concepts (process/thread, virtual memory, scheduler, IPC)
Week 7:     Linux kernel basics (modules, char driver, platform driver)
Week 8:     DSA for Qualcomm (linked list, trees, sorting — 1 problem/day)
Ongoing:    System design — 1 question per day
Before apply: Behavioral narrative (gap year story, leadership at EMOTORAD)
```

## DSA Topics for Qualcomm (dedicated round)
- [ ] Linked list — reverse, detect cycle, merge sorted lists
- [ ] Arrays — two pointer, sliding window, rotate
- [ ] Stack / Queue — using arrays, min-stack
- [ ] Binary search — on sorted array, rotated array
- [ ] Trees — BFS, DFS, height, LCA
- [ ] Sorting — quicksort, mergesort (implement from scratch)
- [ ] String manipulation — reverse words, anagram check
- [ ] Hash map — frequency count, two-sum
- [ ] Recursion — factorial, fibonacci, power, subset
- NOTE: Qualcomm level is LeetCode Easy–Medium. Not hard algorithmic puzzles.

---

## Mock Interview Checklist
- [ ] 60 min technical (Embedded C + RTOS + protocols)
- [ ] 30 min system design (bootloader or OTA)
- [ ] 15 min behavioral
- [ ] Record yourself — review pacing and clarity
