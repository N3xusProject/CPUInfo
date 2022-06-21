#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CPUID_VENDOR_AMD           "AuthenticAMD"
#define CPUID_VENDOR_INTEL         "GenuineIntel"
#define CPUID_VENDOR_VIA           "VIA VIA VIA "
#define CPUID_VENDOR_TRANSMETA     "GenuineTMx86"
#define CPUID_VENDOR_CYRIX         "CyrixInstead"
#define CPUID_VENDOR_CENTAUR       "CentaurHauls"
#define CPUID_VENDOR_NEXGEN        "NexGenDriven"
#define CPUID_VENDOR_UMC           "UMC UMC UMC "
#define CPUID_VENDOR_SIS           "SiS SiS SiS "
#define CPUID_VENDOR_NSC           "Geode by NSC"
#define CPUID_VENDOR_RISE          "RiseRiseRise"
#define CPUID_VENDOR_VORTEX        "Vortex86 SoC"
#define CPUID_VENDOR_AO486         "MiSTer AO486"
#define CPUID_VENDOR_ZHAOXIN       "  Shanghai  "
#define CPUID_VENDOR_HYGON         "HygonGenuine"
#define CPUID_VENDOR_ELBRUS        "E2K MACHINE "


static inline void cpuid(uint32_t leaf, uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx)
{
  __asm__ __volatile__("cpuid"
               : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx)
               : "a"(leaf), "c"(0x0)
               : "memory");
}

char* get_vendor_string(void)
{
    uint32_t unused, ebx, edx, ecx;
    cpuid(0, &unused, &ebx, &ecx, &edx);

    static char vendor_str[13];
    uint8_t vendor_str_idx = 0;


    // Fetch vendor string stored in EBX, EDX and ECX.
    for (uint64_t i = 0; i < sizeof(ebx); ++i, ebx >>= 8)
    {
        vendor_str[vendor_str_idx++] = ebx;
    }

    for (uint64_t i = 0; i < sizeof(edx); ++i, edx >>= 8)
    {
        vendor_str[vendor_str_idx++] = edx;
    }

    for (uint64_t i = 0; i < sizeof(ecx); ++i, ecx >>= 8)
    {
        vendor_str[vendor_str_idx++] = ecx;
    }

    // Null terminate vendor string.
    vendor_str[vendor_str_idx] = '\0';

    // Return it.
    return vendor_str;
}

void get_vendor(const char* vendor_str)
{
    if (strcmp(vendor_str, CPUID_VENDOR_AMD) == 0)
    {
        printf("CPU VENDOR - AMD\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_INTEL) == 0)
    {
        printf("CPU VENDOR - INTEL\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_VIA) == 0)
    {
        printf("CPU VENDOR - VIA\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_TRANSMETA) == 0)
    {
        printf("CPU VENDOR - TRANSMETA\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_CYRIX) == 0)
    {
        printf("CPU VENDOR - CYRIX\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_CENTAUR) == 0)
    {
        printf("CPU VENDOR - CENTUAR\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_NEXGEN) == 0)
    {
        printf("CPU VENDOR - NEXTGEN\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_UMC) == 0)
    {
        printf("CPU VENDOR - UMC\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_SIS) == 0)
    {
        printf("CPU VENDOR - SIS\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_RISE) == 0)
    {
        printf("CPU VENDOR - RISE\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_VORTEX) == 0)
    {
        printf("CPU VENDOR - VORTEX\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_AO486) == 0)
    {
        printf("CPU VENDOR - AO486\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_ZHAOXIN) == 0)
    {
        printf("CPU VENDOR - ZHAOXIN\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_HYGON) == 0)
    {
        printf("CPU VENDOR - HYGON\n");
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_ELBRUS) == 0)
    {
        printf("CPU VENDOR - ELBRUS\n");
    }
}


int main(void)
{
    get_vendor(get_vendor_string());
    return 0;
}
