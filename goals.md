# Sachin Kumar — Goals & Action Plan
**Date:** April 2026 | **Experience:** 9 YOE Embedded/BSP | **Gap:** 1 Year

---

## 🎯 Primary Objective
Get back to earning — join a job (remote preferred) within **3–6 months**.

**Target Companies:** Qualcomm / NXP India  
**Target Salary:** ₹35–55 LPA  
**Long-term:** Abroad transfer (Singapore / Germany)

---

## 1. JOB GOAL

### Interview Prep Status
| Topic | Status |
|-------|--------|
| C++ fundamentals | ✅ Done |
| Design patterns | ✅ Done |
| Move semantics, lambdas | ✅ Done |
| Operator overloading | ✅ Done |
| ISR-safe C++ | ✅ Done |
| Exception handling | ✅ Done |
| Diamond problem | ✅ Done |
| Linux kernel internals | 🔄 In progress — read LDD3 |
| System design | ⬜ Pending |
| Behavioural questions | ⬜ Pending |
| Mock interview | ⬜ Pending |

### Next Steps
- [ ] Read LDD3 Ch 1–3 → build scull on STM32MP157
- [ ] Read LDD3 Ch 10, 14, 15 (IRQ, device model, DMA)
- [ ] System design: BSP architecture, OTA, CAN stack, secure boot
- [ ] Mock interview: 60 min technical + 30 min behavioural
- [ ] Apply to Qualcomm / NXP — don't wait for everything to be perfect

---

## 2. ZEPHYR PR GOAL

**PR:** https://github.com/zephyrproject-rtos/zephyr/pull/106870  
**Branch:** `boards-s32k3x4evb_T172`  
**Board:** NXP S32K3X4EVB-T172 (S32K344, 172-pin LQFP)

### PR Status
| Check | Status |
|-------|--------|
| Compliance | ✅ Passing |
| Documentation HTML | ✅ Passing |
| Twister builds | 🔄 CI running |
| Reviewer approval | ⬜ Waiting |

### Commits (5 total)
1. `boards: nxp: s32k3x4evb_t172: add initial board support`
2. `samples: net: echo: add support for s32k3x4evb_t172`
3. `tests: drivers: gpio: add support for s32k3x4evb_t172`
4. `tests: drivers: uart: add support for s32k3x4evb_t172`
5. `samples: drivers: can: add support for s32k3x4evb_t172`

### Reviewers
- @Dat-NguyenDuy
- @manuargue
- @nordicjm (latest)

### Remaining
- [ ] Wait for CI to pass after rebase on upstream/main
- [ ] Wait for maintainer review approval

---

## 3. MINI SDV PROJECT GOAL

**Repo:** `~/Workspace/zephyrproject/mini-sdv/`  
**Purpose:** Portfolio demo for job applications

### Architecture
```
ESP32 (BLE) → STM32MP157 (Kuksa VSS) ↔ S32K344 (CAN+ETH) → RPi (SOME/IP + MQTT)
```

### Hardware
| Board | Role | Status |
|-------|------|--------|
| S32K344 172Q | Zone ECU | ✅ Working |
| STM32MP157 | Central compute | ✅ Booted |
| ESP32 | BLE sensor | ✅ Working |
| Raspberry Pi 3 | HMI gateway | ⬜ Pending |

### Milestones
| Week | Goal | Status |
|------|------|--------|
| 1–2 | S32K344 CAN→UDP→PC | ✅ Done |
| 2–3 | ESP32 BLE GATT sensor | ✅ Done |
| 3–4 | STM32MP157 reads BLE data | ✅ Done |
| 4–5 | Kuksa databroker + BLE feeder | ⬜ Pending |
| 5–6 | CAN feeder → Kuksa VSS | ⬜ Pending |
| 6–7 | SOME/IP STM32MP157 → RPi | ⬜ Pending |
| 7–8 | RPi dashboard + MQTT cloud | ⬜ Pending |
| 8 | Demo video + GitHub README | ⬜ Pending |

### Next Immediate Step
Add Kuksa databroker to STM32MP157 Yocto image:
```bash
# Add to sdv-image.bb
IMAGE_INSTALL:append = " kuksa-databroker python3-kuksa-client"
```

---

## 4. LEARNING GOALS

### C++ ✅ Complete
- Classes, RAII, constructors, destructors
- Virtual functions, polymorphism, CRTP
- Smart pointers, move semantics, lambdas
- Design patterns: Singleton, Factory, Observer, Strategy
- ISR-safe: atomic, mutex, lock_guard
- Operator overloading, const correctness
- STL: array, vector, map — embedded usage

### Linux Kernel 🔄 In Progress
- [ ] LDD3 Ch 1–2: modules, insmod/rmmod, printk
- [ ] LDD3 Ch 3: char drivers, file_ops, scull
- [ ] LDD3 Ch 10: IRQ, request_irq, threaded IRQ
- [ ] LDD3 Ch 14: device model, platform driver, probe
- [ ] LDD3 Ch 15: DMA, memory mapping
- [ ] Build scull on STM32MP157
- [ ] Write custom platform driver

### Zephyr ✅ Strong
- Board bring-up, DTS, pinctrl
- CAN-FD, Ethernet (100BASE-T1), BLE
- Networking stack (UDP, TCP)
- Open source contribution (PR merged pending)

### Yocto ✅ Strong
- Custom layer, image recipe
- STM32MP157 BSP
- BlueZ, Python3, can-utils, mosquitto

---

## 5. PRIORITY ORDER

1. **Apply now** — C++, Zephyr, Yocto skills are already strong enough for screening
2. **Finish LDD3** — Linux kernel is the most common interview gap
3. **Get PR merged** — one merged Zephyr PR > 10 side projects
4. **Complete SDV demo** — use as talking point even if partially done

---

## 6. QUICK REFERENCE

### Key Commands
```bash
# Zephyr PR
cd ~/Workspace/zephyrproject/zephyr
git push origin boards-s32k3x4evb_T172 --force
./scripts/ci/check_compliance.py -c upstream/main..

# Mini SDV S32K344
cd ~/Workspace/zephyrproject/mini-sdv
west build -p -b mini-sdv-s32k3 .
west flash -r pyocd

# Mini SDV ESP32
cd ~/Workspace/zephyrproject/mini-sdv/esp32_ble
west build -p -b esp32_devkitc/esp32/procpu .
west flash --esp-device /dev/ttyUSB1

# STM32MP157 Yocto
cd ~/Workspace/Git/poky/build-mp1
bitbake sdv-image

# Flash STM32MP157
cd tmp/deploy/images/stm32mp15-disco
sudo DEVICE=sdb ./scripts/create_sdcard_from_flashlayout.sh \
  flashlayout_sdv-image/opteemin/FlashLayout_sdcard_stm32mp157f-dk2-opteemin.tsv
```

### Serial Ports
| Port | Device |
|------|--------|
| /dev/ttyUSB0 | TOSUN CAN adapter / S32K344 console |
| /dev/ttyUSB1 | ESP32 |
| /dev/ttyACM0 | STM32MP157 OpenSDA |
| /dev/ttyACM1 | S32K344 console (JLink) |

### Network
| Device | IP |
|--------|----|
| S32K344 | 192.168.10.10 |
| Linux PC (eth) | 192.168.10.1 (enp7s0) |
| ESP32 Wi-Fi | 192.168.1.15 (DHCP) |
| MQTT broker | 192.168.1.10:1883 |
