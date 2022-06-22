/*
 *  MIT License
 *
 *  Copyright (c) 2022 Nexus-C, Ian Marco Moffett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

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

// CPU feature flags.

typedef enum
{
	FF_FPU 		= 		(1 << 0),			// Floating point unit.
	FF_VME 		= 		(1 << 1),			// Virtual mode extension.
	FF_DE 		= 		(1 << 2),			// Debugging extension.
	FF_PSE 		= 		(1 << 3),			// Page size extension.
	FF_TSC 		= 		(1 << 4),			// Time stamp counter.
	FF_MSR 		= 		(1 << 5),			// Model specific registers..
	FF_PAE 		= 		(1 << 6),			// Physical address extension.
	FF_MCE 		= 		(1 << 7),			// Machien check exception.
	FF_CX8 		= 		(1 << 8),			// Support for CMPXCHG8 instruction.
	FF_APIC 	= 		(1 << 9),			// On-Chip Advanced Programmable Interrupt Controller (APIC).
	FF_SEP 		= 		(1 << 11),			// Fast system call support.
	FF_MTRR 	= 		(1 << 12),			// Memory type range registers.
	FF_PGE		=		(1 << 13),			// Page global enable.
	FF_MCA 		= 		(1 << 14), 			// Machine check architecture.
	FF_CMOV		= 		(1 << 15),			// Conditional move instruction.
	FF_PAT 		= 		(1 << 16)			// Page attribute table.
} FEATURE_FLAG;

uint32_t eax, ebx, ecx, edx;

// Sets a variable called checkmark of type const char* to either a checkmark
// that is set or not set based on a condition.

const char* set_checkmark(uint8_t condition)
{
	static char checkmark[4];

	if (condition)
	{
		strcpy(checkmark, "[+]");
	}
	else
	{
		strcpy(checkmark, "[]");
	}

	return checkmark;
}

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

	// Vendor string stored here.
    static char vendor_str[13];

	// Index into vendor string.
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
    else
    {
        printf("CPU VENDOR - UNKNOWN\n");
    }
}


// See https://en.wikipedia.org/wiki/Stepping_level
void get_stepping_level(void)
{
    cpuid(1, &eax, &ebx, &ecx, &edx);
    printf("CPU STEPPING LEVEL - 0x%X\n", eax & 0x7);
}


uint32_t get_model_number(void)
{
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return (eax >> 4) & 0x7;
}


uint32_t get_extended_model(void)
{
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return (eax >> 16) & 0x7;
}


uint8_t get_processor_type(void)
{
    cpuid(1, &eax, &ebx, &ecx, &edx);
    return (eax & (1 << 13)) << 1 | eax & (1 << 12);
}


void feature_dump(void)
{
	// Feature flags will be in EDX.
    cpuid(1, &eax, &ebx, &ecx, &edx);

	printf("\nListing CPU features..\n[x] => supported, [] => not supported\n\n");

	const char* check = "[]";

	printf("On-Chip Floating Point Unit (FPU) %s\n", set_checkmark(edx & FF_FPU));
	printf("Virtual Mode Extension (VME) %s\n", set_checkmark(edx & FF_VME));
	printf("Debugging Extension (DE) %s\n", set_checkmark(edx & FF_DE));
	printf("Page Size Extension (PSE) %s\n", set_checkmark(edx & FF_PSE));
	printf("Time Stamp Counter (TSC) %s\n", set_checkmark(edx & FF_TSC));
	printf("Model Specific Registers (MSR) %s\n", set_checkmark(edx & FF_MSR));
	printf("Physical Address Extension (PAE) %s\n", set_checkmark(edx & FF_PAE));
	printf("Machine-Check Exception (MCE) %s\n", set_checkmark(edx & FF_MCE));
	printf("CMPXCHG8 Instruction (CX8) %s\n", set_checkmark(edx & FF_CX8));
	printf("On-Chip APIC Hardware (APIC) %s\n", set_checkmark(edx & FF_APIC));
	printf("Fast System Call (SEP) %s\n", set_checkmark(edx & FF_SEP));
	printf("Page Global Enable (PGE) %s\n", set_checkmark(edx & FF_PGE));
	printf("Machine-Check Architecture (MCA) %s\n", set_checkmark(edx & FF_MCA));
	printf("Page Attribute Table (PAT) %s\n", set_checkmark(edx & FF_PAT));
}


int main(void)
{
    get_vendor(get_vendor_string());
    get_stepping_level();

    printf("CPU MODEL NUMBER - 0x%X\n", get_model_number());
    printf("CPU EXTENDED MODEL - 0x%X\n", get_extended_model());

	switch (get_processor_type())
	{
		case 0b00:
			printf("CPU TYPE - Original OEM Processor\n");
			break;
		case 0b01:
			printf("CPU TYPE - Overdrive(R) Processor\n");
			break;
		case 0b10:
			printf("CPU TYPE - Dual Processor\n");
			break;
		default:
			printf("CPU TYPE - Unknown\n");
			break;
	}

	// Dump features.
	feature_dump();
    return 0;
}
