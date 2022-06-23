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
#include <cpuinfo/cpuinfo.h>


// Returns a string "[]" if the condition is false
// otherwise it will retrurn "[+]"
char* check(uint8_t condition)
{
    if (condition)
    {
        return "[+]";
    }
    else 
    {
        return "[]";
    }
}



void list_features(void)
{
    printf("\n<==== Listing CPU Features ====>\n[+] => Supported, [] => Unsupported\n\n");
    printf("On-Chip Floating Point Unit %s\n", check(cpu_has_feature(CPU_FPU)));
    printf("Virtual Mode Extension %s\n", check(cpu_has_feature(CPU_VME)));
    printf("Debugging Extension %s\n", check(cpu_has_feature(CPU_DE)));
    printf("Page Size Extension %s\n", check(cpu_has_feature(CPU_PSE)));
    printf("Time Stamp Counter %s\n", check(cpu_has_feature(CPU_TSC)));
    printf("Model Specific Registers %s\n", check(cpu_has_feature(CPU_MSR)));
    printf("Physical Address Extension %s\n", check(cpu_has_feature(CPU_PAE)));
    printf("Model Check Exception %s\n", check(cpu_has_feature(CPU_MSE)));
    printf("CMPXCHG8 Instruction %s\n", check(cpu_has_feature(CPU_CX8)));
    printf("Fast System Call %s\n", check(cpu_has_feature(CPU_SEP)));
    printf("Memory Type Range %s\n", check(cpu_has_feature(CPU_MTRR)));
    printf("Page Global Enable %s\n", check(cpu_has_feature(CPU_PGE)));
    printf("Machine Check Architecture %s\n", check(cpu_has_feature(CPU_MCA)));
    printf("Conditional Move Instruction %s\n", check(cpu_has_feature(CPU_CMOV)));
    printf("Page Attribute Table %s\n", check(cpu_has_feature(CPU_PAT)));
    printf("36-Bit Page Size %s\n", check(cpu_has_feature(CPU_PSE36)));
    printf("ACPI %s\n", check(cpu_has_feature(CPU_ACPI)));
    printf("MMX %s\n", check(cpu_has_feature(CPU_MMX)));
    printf("FXSAVE And FXSTOR Instructions %s\n", check(cpu_has_feature(CPU_FXSR)));
    printf("Streaming SIMD Extensions %s\n", check(cpu_has_feature(CPU_SSE)));
    printf("Streaming SIMD Extensions 2 %s\n", check(cpu_has_feature(CPU_SSE2)));
    printf("Self Snoop %s\n", check(cpu_has_feature(CPU_SS)));
    printf("Multi-Threading %s\n", check(cpu_has_feature(CPU_HTT)));
    printf("Thermal Monitor %s\n", check(cpu_has_feature(CPU_TM)));
    printf("Pending Break Enable %s\n", check(cpu_has_feature(CPU_PBE)));

    // CPUID:1[ECX] feature flags.
    printf("Streaming SIMD Extensions 3 %s\n", check(cpu_has_feature_ecx(CPU_SSE3)));
    printf("PCMULDQ Instruction %s\n", check(cpu_has_feature_ecx(CPU_PCLMULDQ)));
    printf("64-Bit Debug Store %s\n", check(cpu_has_feature_ecx(CPU_DTES64)));
    printf("MONITOR/WAIT Instructions %s\n", check(cpu_has_feature_ecx(CPU_MONITOR)));
    printf("CPL Qualified Debug Store %s\n", check(cpu_has_feature_ecx(CPU_DSCPL)));
    printf("Virtual Machine Extensions %s\n", check(cpu_has_feature_ecx(CPU_VMX)));
    printf("Safer Mode Extensions %s\n", check(cpu_has_feature_ecx(CPU_SMX)));
    printf("Enhanced Intel SpeedStep(R) Technology %s\n", check(cpu_has_feature_ecx(CPU_EST)));
    printf("Thermal Monitor 2 %s\n", check(cpu_has_feature_ecx(CPU_TM2)));
}



int main(void)
{
    printf("CPU VENDOR - %s\n", cpu_get_vendor());
    printf("CPU MODEL NUMBER - 0x%X\n", cpu_get_model_number());
    printf("CPU FAMILY - 0x%X\n", cpu_get_family_value());
    list_features();
    return 0;
}
